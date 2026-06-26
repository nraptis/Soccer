#include "TwistExpander_Boxing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Boxing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA006DBCE0AEA4C57ULL + 0x86EA40B6EB1DB431ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBD906270D9CB0BE3ULL + 0xF32D8BEDFCD782EDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB0A7A3A1FD412853ULL + 0xD1368F751A50E8AEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBFDF858E03D2ED05ULL + 0xA3B81F6D820203D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x84F4A1DB45F745A1ULL + 0xD0B8F4F644A7E5DEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD34AB0B4284EBB65ULL + 0xA3542D13EA6B37D5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x877B450243319FD3ULL + 0xAA437C685C9D66FCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDCEC161ACC719213ULL + 0xF75D83FC2BF6C844ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD13CC4B1791C668DULL + 0x8409D0E4DE2AAB10ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x947282D0719239A3ULL + 0x94AE6FABB7D24462ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x86C7C1CB5F0BA681ULL + 0xA65831794E9BF665ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDDB4A68556883DD7ULL + 0xF2503FF99EC0A527ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x93515A938CDED12FULL + 0xF045EFD369B1AFB8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBA8688C34099EFE5ULL + 0xBD75C32C8F3034FEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB1B19D85EF64BF4BULL + 0xECC2FD6CA507B065ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAFDE9FA301087599ULL + 0xBBC35B0A9F1A541EULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 372U)) & S_BLOCK1], 42U) ^ RotL64(pSnow[((aIndex + 2360U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2678U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1710U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 7948891781097675369U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 29U)) + 13928362874228230226U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 5U)) + 10776180542602258926U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 56U)) + 5735115172149470447U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 51U)) + 5353591822981766987U) + aNonceWordJ;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 562301708107268570U;
            aOrbiterG = (aWandererK + RotL64(aCross, 23U)) + 10467810247578364868U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 60U)) + 14541630141152308564U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 2350076897065139429U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 53U)) + 17519109078651162228U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 11U)) + 6061035173339902910U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15654836633731000065U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2849680038315532197U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17336102435576647923U;
            aOrbiterC = RotL64((aOrbiterC * 10984689101753586739U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7671010488872356142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11485114338165600777U;
            aOrbiterH = RotL64((aOrbiterH * 4162584865462407791U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8759060657343458985U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11009137869375286581U;
            aOrbiterI = RotL64((aOrbiterI * 8741417343929809115U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15792999392743144135U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterG = RotL64((aOrbiterG * 13681230339693676907U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 361487389591183005U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15292753806514404853U;
            aOrbiterF = RotL64((aOrbiterF * 17478232597253311153U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14929153438443362045U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7904556383593914086U;
            aOrbiterB = RotL64((aOrbiterB * 2484130486635511403U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3793180909904286848U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10391957637467171320U;
            aOrbiterE = RotL64((aOrbiterE * 505484041943467117U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11648765065563798353U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17601185776537566611U;
            aOrbiterD = RotL64((aOrbiterD * 4753179291885740011U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2907499704986356444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17048858067202291241U;
            aOrbiterA = RotL64((aOrbiterA * 2607549567999666889U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4340465159886930775U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7948891781097675369U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12913104720552907335U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 4U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 46U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10186U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 8961U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 10864U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7770U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 14157904117287696136U) + aNonceWordP;
            aOrbiterH = (aWandererG + RotL64(aCross, 51U)) + 7369512677371640676U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 57U)) + 8411250745902073798U) + aNonceWordE;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 41U)) + 5002041814539710275U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 60U)) + 9538041410816283124U) + aNonceWordB;
            aOrbiterC = (aWandererB + RotL64(aIngress, 5U)) + 5210700103927513061U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 7600709399101287982U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 2366369466696580499U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 28U)) + 5544575244203019109U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 8710073749110329779U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + 15998211310115361630U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15354357553877376422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10657523549259276169U;
            aOrbiterI = RotL64((aOrbiterI * 13695239532898311073U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10405750198355464768U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3465819693133515142U;
            aOrbiterH = RotL64((aOrbiterH * 14678343718277562799U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16724189641701408630U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3484340153620198872U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17247547677520703125U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7420442404884871126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11138445997256757636U;
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1428191560884663125U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16950093140800653985U;
            aOrbiterD = RotL64((aOrbiterD * 4423012306984814805U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17288299075036481960U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13793597915359681028U;
            aOrbiterE = RotL64((aOrbiterE * 9639204979982125757U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5017972942710079726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12409957957614320964U;
            aOrbiterJ = RotL64((aOrbiterJ * 10273295741911545745U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12487994181992095174U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1573393166996612118U;
            aOrbiterC = RotL64((aOrbiterC * 13364311829104520751U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13227642825780350128U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7961292096150889569U;
            aOrbiterB = RotL64((aOrbiterB * 16627209081334341289U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10312485102088913337U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3177620041478410950U;
            aOrbiterF = RotL64((aOrbiterF * 15918551366833593853U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2599092792737616563U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14157904117287696136U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 14883446269291639813U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 44U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterC, 26U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15002U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14660U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 12779U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 10947U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + 17225673071833726819U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 51U)) + 10301458382103627331U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 3960233050857362414U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 53U)) + 17768665685046605837U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererA + RotL64(aCross, 39U)) + 14471018461213959767U) + aNonceWordL;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 11U)) + 10730597892721340453U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 14863394003122760542U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 9948587274816688296U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 44U)) + 3573569431435100993U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 29U)) + 8153670675740450590U;
            aOrbiterK = (aWandererD + RotL64(aCross, 27U)) + 16438856577722561424U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15765587867581925041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1082039522061775213U;
            aOrbiterI = RotL64((aOrbiterI * 17023740047246402641U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4202521649260798876U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2551560426129646123U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3005102326163906320U;
            aOrbiterA = RotL64((aOrbiterA * 4241583192662435107U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1675501058857208089U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12774812270956702043U;
            aOrbiterD = RotL64((aOrbiterD * 5488437008504905105U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1044886020922563597U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4857445127457225171U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13223560654459705259U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11548725551787560962U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2434677823189765161U;
            aOrbiterB = RotL64((aOrbiterB * 4283026044563670969U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9606875320524736294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterJ = RotL64((aOrbiterJ * 3905528919281629775U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13921743663803299567U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13350829301153929899U;
            aOrbiterC = RotL64((aOrbiterC * 11858642286713079795U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9473349030551400156U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7446792050826434742U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 6619682184124713031U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17970527747978977453U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2326714817603921480U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14581676978186226887U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7875511075130474136U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17225673071833726819U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 1196024136909896027U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 30U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterK, 24U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aNonceWordP);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17081U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 18465U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19590U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 18208U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 38U)) + 13924571355038625040U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 51U)) + 16328300979357156658U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 21U)) + 3947771961206012461U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 15428284250569311285U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 26U)) + 5777369485254032486U) + aNonceWordI;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 16813320300717644673U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 16689933050200758251U;
            aOrbiterH = (aWandererG + RotL64(aCross, 3U)) + 1856422419049390708U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 57U)) + 18214498743831925517U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 23U)) + 18278550878494094923U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 797712062039591797U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15854849439012341347U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 996882939768167773U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14936703950807908575U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3005829974130671692U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8793495343509953906U;
            aOrbiterF = RotL64((aOrbiterF * 14065479348374612031U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7710453029930631112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9511995836117707047U;
            aOrbiterE = RotL64((aOrbiterE * 7250766204781428201U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 670902975693341744U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9045820304668279777U;
            aOrbiterI = RotL64((aOrbiterI * 18373074917532639027U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12417212387607119470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12816983560669985622U;
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17245432086377688540U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6806521945548502014U;
            aOrbiterA = RotL64((aOrbiterA * 11335859481858640857U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8947500746292365294U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4468060468522895852U;
            aOrbiterK = RotL64((aOrbiterK * 7022481284816599797U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9892975931958803992U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3042599331526937836U;
            aOrbiterB = RotL64((aOrbiterB * 3308512896171443645U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12991568221485810891U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8551331172836260315U;
            aOrbiterD = RotL64((aOrbiterD * 4509997595920847057U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 183547209633334407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17275712817092769452U;
            aOrbiterJ = RotL64((aOrbiterJ * 15677355290000929085U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12743863879392372723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13924571355038625040U;
            aOrbiterC = RotL64((aOrbiterC * 11966689345179279407U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 30U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterB, 48U)) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23265U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24937U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24761U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 24552U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 5U)) + 16189787374324972735U) + aNonceWordD;
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 17563763730956242224U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 53U)) + 10572803498593789385U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 39U)) + 7713105232072974166U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 19U)) + 10760839534772718139U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 13397069448391230253U;
            aOrbiterE = (aWandererC + RotL64(aCross, 10U)) + 4569255679998375682U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 9888769350817876949U) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aCross, 51U)) + 11351796060878856300U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 37U)) + 18153775071965707204U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 29U)) + 1282846411145853435U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16457743979262460660U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3927345926316409630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5158769729850853623U;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12331351600010165154U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3940794200348684050U;
            aOrbiterJ = RotL64((aOrbiterJ * 13248997263062075043U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11248514843822945425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1391497323278226522U;
            aOrbiterA = RotL64((aOrbiterA * 8376841806072565005U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13265623528678787307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2802033745265647317U;
            aOrbiterF = RotL64((aOrbiterF * 3437626962562016147U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6938444301018051844U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1086544666755559028U;
            aOrbiterG = RotL64((aOrbiterG * 16039728388882079889U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16156443117365816536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3619942859562697142U;
            aOrbiterE = RotL64((aOrbiterE * 7589346043159112151U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17681848914912743292U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8848238631758130416U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 810402256099500607U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6019192027793541890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16917288363166352778U;
            aOrbiterD = RotL64((aOrbiterD * 17673667086593738207U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5598218150530046752U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17285995539011279010U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15621233176885995065U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12380627610747299268U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16189787374324972735U;
            aOrbiterH = RotL64((aOrbiterH * 2144714828503219209U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 42U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 28U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 52U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28918U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29018U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30461U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 28683U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 20U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 13499155707765393469U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 35U)) + 3740324981823726185U) + aNonceWordC;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 5470765363949735652U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 3446436171274452326U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 47U)) + 1778929412631211933U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 52U)) + 14666308799855220954U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + 4548410236791175055U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 41U)) + 5829739767694190372U) + aNonceWordG;
            aOrbiterC = (aWandererG + RotL64(aCross, 23U)) + 14319231414903675748U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 1513851750246111405U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 60U)) + 1685620217748986019U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16284162182006054402U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12669312437565969473U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11894755313393001665U;
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6315983824634946566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17106616474222892782U;
            aOrbiterB = RotL64((aOrbiterB * 167205520766791073U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13350266700180455548U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4608846311203767162U;
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14195866746143604365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7917977448256795054U;
            aOrbiterE = RotL64((aOrbiterE * 5927771378657284557U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10707336923305131629U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17122696159336995392U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13953518568670659191U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5182322763573586116U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6503754948502556246U;
            aOrbiterJ = RotL64((aOrbiterJ * 14749002194140663519U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14907832047832987341U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6258064448676621346U;
            aOrbiterG = RotL64((aOrbiterG * 4407960312705621487U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1180234574888070795U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 801686887651085881U;
            aOrbiterD = RotL64((aOrbiterD * 433981853631548041U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11810494591997709554U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9343740505955858127U;
            aOrbiterI = RotL64((aOrbiterI * 8733378485648720323U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12816829575386720695U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13499155707765393469U;
            aOrbiterA = RotL64((aOrbiterA * 9937924703928730369U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 26U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 6U));
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordF);
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

void TwistExpander_Boxing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBA18AA2CD9D1B3C1ULL + 0xDD6C21D530F30A1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBBFD338D26E76FEDULL + 0xC10956B16B27A60FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAC53EDAB919701C5ULL + 0xB5C74E12AC288117ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A4DA216F2C42A65ULL + 0xD7F01357D7828B55ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8C322E19827E271BULL + 0xFE94F71EF2CE9C81ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAEE2928B06EB01B9ULL + 0xE23A579BA553BB58ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEB9FDEE237C03F41ULL + 0xC87A1A70BB7BE218ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x89A6EF5EC3A775E5ULL + 0xDDEF262A9491E1DFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBBBAD8CF6ECF011FULL + 0xB7B947C6B8D4FD78ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9031FBD36F0680CDULL + 0xABFF76FEFAC3F804ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xACEF9E45D5BA5F7FULL + 0xCFAF22A2C81E2583ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA60E9D9A6E8B6A35ULL + 0x9D37BDC0F1270AEFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x94743C7A63873907ULL + 0x8C0C0432794858B6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA9565CE37D753081ULL + 0xCD880FE9E5C7E502ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8F2DDE5D6571E2A5ULL + 0xD74602D12F1968E5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB0789B3EC2B23217ULL + 0xC26C3CE35024DFB7ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3901U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 7776U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 799U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4051U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 14U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 17936518874386450467U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 40U)) + RotL64(aCarry, 39U)) + 13722737841589910344U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 51U)) + 11774969167948715796U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 3640101505680493777U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 23U)) + 1369495382725650822U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 46U)) + 11827310354654653345U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 13U)) + 186037671377175394U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 57U)) + 11428829344234627340U) + aNonceWordG;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 19U)) + 2275016369870029068U) + aNonceWordE;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15471646673734798328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12172082573115640145U;
            aOrbiterC = RotL64((aOrbiterC * 9629417882787847753U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6626736341348283154U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12220614992483863623U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 8137086205714097487U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13157102324253760215U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4143587482368093601U;
            aOrbiterG = RotL64((aOrbiterG * 5060677690991506895U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11007575246013796426U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11721585930088637162U;
            aOrbiterB = RotL64((aOrbiterB * 15009627907125738519U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5720789204450196217U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3094696226821431648U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4412033981712165541U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14675830108100986773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9444071495289719645U;
            aOrbiterD = RotL64((aOrbiterD * 10983136361953366557U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 5106753847015199956U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7585421898593510010U;
            aOrbiterF = RotL64((aOrbiterF * 140996914192351011U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11746948407655524690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16336323220286344483U;
            aOrbiterI = RotL64((aOrbiterI * 6590417628835864497U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8030445186765781136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 276034088015165891U;
            aOrbiterJ = RotL64((aOrbiterJ * 7626025612710225099U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterD) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterE, 48U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11536U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9817U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15197U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12541U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 35U)) + 11210042748013785976U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 5U)) + 4584747303233477454U;
            aOrbiterD = (aWandererK + RotL64(aCross, 23U)) + 8878765929792969517U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 2172232330280041122U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 12U)) + 8378937026022264016U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 8683007464695824208U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 57U)) + 9564352997357118134U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 51U)) + 11713878436769887528U) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 41U)) + 8052917623074021077U) + aNonceWordG;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7720597162792145185U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2602847785328475621U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14065077077207224525U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17813669222300509724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8724263063156573013U;
            aOrbiterA = RotL64((aOrbiterA * 3632927017737834359U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6882429835961613492U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13213313479525717359U;
            aOrbiterJ = RotL64((aOrbiterJ * 2411431247725974895U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2401526093648669573U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3616448566579979749U;
            aOrbiterC = RotL64((aOrbiterC * 13323155103752121393U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18268262471839710401U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5116424918948694752U;
            aOrbiterI = RotL64((aOrbiterI * 7641143782996332069U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11405305689555640431U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12427591396711015574U;
            aOrbiterK = RotL64((aOrbiterK * 8112834135715541223U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16960781161508084626U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12382604781005282628U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17196168631120103115U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 10054839091354729292U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4167641616532985407U;
            aOrbiterB = RotL64((aOrbiterB * 919291747187787625U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14383737233143309039U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16258779988369405932U;
            aOrbiterG = RotL64((aOrbiterG * 8348773195366160215U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + aNonceWordL);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 56U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20715U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 20959U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20665U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18608U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 10U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 12980104182836602177U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + 3172622203188863995U) + aNonceWordE;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 10U)) + 1170974132219980203U;
            aOrbiterK = (aWandererI + RotL64(aCross, 21U)) + 6035201940965047490U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 47U)) + 18033907118424996722U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 14604813424800580304U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 13720232492851066035U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 43U)) + 3902659710585257448U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 34U)) + 8331560652661619868U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4485014147538689794U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 168202636924512424U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 13711020666131492091U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16227825670092707848U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4792781933944671365U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12636865372722601282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18198291399585556632U;
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3650053185419807206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5897288963905408776U;
            aOrbiterG = RotL64((aOrbiterG * 3706949366974086151U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9922308113622901726U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4025213180483632557U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14969461950939646117U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10231661776135056651U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11284575051455238501U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10621934544068320859U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 6029116920305246887U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 6087523725059376905U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12887482425168671195U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8351351557123783853U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3839381627914762245U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5405938210926464973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 385145802287899406U;
            aOrbiterC = RotL64((aOrbiterC * 8330751480464271445U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 18U)) + aOrbiterK) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aCross, 34U) + RotL64(aOrbiterG, 47U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 34U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31393U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 26812U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29787U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 28160U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 11U)) + 12122689833405846292U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 9640400270962766788U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 57U)) + 9141937998266739071U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 12899395770434090537U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 13457918115408031842U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 35U)) + 15134784483576000943U;
            aOrbiterC = (aWandererE + RotL64(aCross, 23U)) + 12540961268790055438U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 6306886773092764230U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 46U)) + 13573343491337243121U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8545588657348974413U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10891410570357275120U;
            aOrbiterJ = RotL64((aOrbiterJ * 5399310978367842841U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2877137119767060151U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9178097682386595144U;
            aOrbiterG = RotL64((aOrbiterG * 3524486002084427513U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15528007881855616978U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11368419529245281435U;
            aOrbiterC = RotL64((aOrbiterC * 12433207037378339309U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5932738914934356645U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5551842263864055419U;
            aOrbiterE = RotL64((aOrbiterE * 16093776759971522681U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3824433359595690603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17184628855571662441U;
            aOrbiterH = RotL64((aOrbiterH * 691208053136187317U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8724462245014132623U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7481349499528092352U;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6908362960248294718U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5354057969992655314U;
            aOrbiterA = RotL64((aOrbiterA * 16586084885820679343U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11138301629323903147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14164180536320940750U;
            aOrbiterD = RotL64((aOrbiterD * 9099767681053390287U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 709942920176922902U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17128241237359414945U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14063385518459963529U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 34U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 39U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9CBE4BBA4A0830BBULL + 0xA3456FE0D6B92301ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC29F8441753DB59DULL + 0x852BB3E7B2F9C9A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x91D72E66436ADA21ULL + 0x91E00DD2A9214B24ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC46BAA836A3D05E9ULL + 0xAD76CE73BAF65A73ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x916CB742088A3203ULL + 0xB9A07D6CAC3480A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF20C5138EFFEA9B3ULL + 0xC2DA7E6BBED6F159ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x927360543670C68DULL + 0x9F6B4A81213C8EBFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8DD47CACC09FB9D5ULL + 0xE3BF7BE4CC4A1EC6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x82252FF3228CE029ULL + 0xB256ACB988B5C001ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDE1AB34995F94875ULL + 0xE7094D0481B9E7FAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA8C53CE47C353939ULL + 0x96C50A95D8FA487AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB4646947157561A1ULL + 0xE1A397F5A1A718C8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF7CB9E02B91D9999ULL + 0xA2F6358787028E29ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE6AC7D7DC9348CD7ULL + 0xF2B1A5513433FD67ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAD95434A9CEC9819ULL + 0x9DC1CC16D8554333ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF5CBD28512799537ULL + 0xDF3C3C44D1623DD6ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5156U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 1885U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 6589U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 2786079456995203065U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 18U)) + 7237256119153857253U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 9310834010563647604U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 17361734905706517877U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 27U)) + 15837111231884647451U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18065431964418026445U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3029123922999952652U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16309219658285890145U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5166926595573507837U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1918425684273807598U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16616641579714896719U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4724551751012661440U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1818014487579644390U;
            aOrbiterD = RotL64((aOrbiterD * 14904092108647864911U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6670090372241084216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterF = RotL64((aOrbiterF * 11876760095108618363U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4928130251509514742U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 26U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10961U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11136U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12418U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13433U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 4848316479321533394U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 43U)) + 6919360256662636195U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aCross, 35U)) + 9897013582181108544U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 7319353809896158678U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 26U)) + RotL64(aCarry, 27U)) + 2848175435514849859U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 6967780718720437934U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10143884766603388136U;
            aOrbiterF = RotL64((aOrbiterF * 17346772745745835895U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8675965006150972051U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16350117755560994281U;
            aOrbiterB = RotL64((aOrbiterB * 15072308930382994425U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17976597517118423760U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1399631141355370237U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16537788276543236833U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3590613762034716792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5134624314245932157U;
            aOrbiterA = RotL64((aOrbiterA * 13077589037975283371U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10082236952942943654U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4015535035905433450U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4961808568701908559U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 52U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22889U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18151U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22610U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20963U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 4179952823252098240U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 3745613452332101749U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 19U)) + 2955689793395307176U) + aNonceWordG;
            aOrbiterA = (aWandererB + RotL64(aCross, 35U)) + 5639060180251322019U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 3U)) + 7901969163853586463U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 2242166787816318119U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5239936443960750064U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 2752853245379816327U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13939136954732185558U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17058884136712717463U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7222348891215482977U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18148618660054585941U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7022023484530327814U;
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7722084537340095637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11764151879690934182U;
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16412785901758144708U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9666718667728274824U;
            aOrbiterD = RotL64((aOrbiterD * 10865799822751771795U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24896U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 30837U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27441U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25840U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 1708250618750199233U) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 12009147777553691142U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 12U)) + 8393982703399156592U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 3247327098356831221U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 3403590155376353737U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18197244558104735044U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 3096253642040701606U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 6656168712438620783U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8012692688785412179U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17531946907545680745U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16510602981731506381U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17687695944270225817U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16147773866007628769U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16926442582711557877U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18244641303026196497U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8839160526348897457U;
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10599266240854068246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2056723540756216155U;
            aOrbiterI = RotL64((aOrbiterI * 13311591601230386375U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 56U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordG);
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

void TwistExpander_Boxing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFDC1E9AC2CB1CEB9ULL + 0xBF44F5403B10D229ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAD82509A61D43EA7ULL + 0xEF7C7214E0AF3875ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD46B05DC741B0417ULL + 0xDC2568E6743B0884ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x94A38134CE09B72BULL + 0xFF7AFAEDC7827E68ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE93CEF5234AB64B3ULL + 0xDB111D682A1FD564ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA09EA71C2264EF53ULL + 0x88DB07EFDF72A6EEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8023174995AFF243ULL + 0xBAF45C0EBB17BA63ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFB6CC6F9C8AAD51FULL + 0xDE8E6CE94D28289FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9F33F617B0491131ULL + 0xEA3223C58420328FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDCE295C85167CAA7ULL + 0x83F0740754D69039ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB9AF44ADBA4F11E3ULL + 0xA141039461627366ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEFECEE7FA19F1C09ULL + 0xEB3291322DD25C94ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF3406ED945679F83ULL + 0xBBE5A911694361A0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8E64194D5579ACEFULL + 0xFE08DF1B3EC52861ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB39D1D6B625F114FULL + 0xDFCFC4F393EDE595ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x87CAC55B517046C7ULL + 0xE31585FAC29CD7ABULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7086U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3914U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2319U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 7313U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 24U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 16424657151168221875U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 17150123681886380361U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 16041993588694572757U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 9871185846434828537U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 11227236398354430757U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 41U)) + 5399325217402192631U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 48U)) + 9248828789282890454U) + aNonceWordG;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9041370494203701062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14944424084524970764U;
            aOrbiterG = RotL64((aOrbiterG * 10283363059424655079U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5481938174456671041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14783648629543752715U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 7260164783191886395U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12355573914530445723U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 9863991559011968318U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 8495251211794343179U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16149688605937250965U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 106041828692026825U;
            aOrbiterF = RotL64((aOrbiterF * 12199934305374582599U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 8076098639554567792U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11155119311895580013U;
            aOrbiterC = RotL64((aOrbiterC * 1495180896564818647U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6847612160595917702U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16094377920388017367U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4875801863643206333U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13584719866672696684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13446209321646234607U;
            aOrbiterI = RotL64((aOrbiterI * 9945349065094781529U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterA, 44U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16064U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 13749U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13398U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 10857U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererG + RotL64(aScatter, 42U)) + RotL64(aCarry, 19U)) + 9471546960258473684U) + aNonceWordF;
            aOrbiterD = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 18050235435948942244U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 19U)) + 3005107102671544641U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 53U)) + 17898396434573801850U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 11U)) + 15071602525497771648U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 5780119462702672108U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 35U)) + 13301326224151025687U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18129323022260575961U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1199228670638790709U;
            aOrbiterK = RotL64((aOrbiterK * 1780426336211781025U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1839199978088021020U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4999517042246790165U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4585813675677234577U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8788607633376516299U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15143903839930468749U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12735914889325422675U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16674732686428431869U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15908873150953195581U;
            aOrbiterD = RotL64((aOrbiterD * 18049755517524334107U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11204775359756474667U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2525984309543939465U;
            aOrbiterH = RotL64((aOrbiterH * 3988529812023791571U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4566345170476825512U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14876612901557406267U;
            aOrbiterI = RotL64((aOrbiterI * 9047956948845135339U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 14926290877038883931U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12710203178186614846U;
            aOrbiterA = RotL64((aOrbiterA * 14841163494801662515U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 54U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17712U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 22277U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23224U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21986U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 28U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 77518479758428414U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 4832061802166300011U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 11695291171006574112U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + 7467412817843260094U) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 13U)) + 17801484124471154757U) + aNonceWordP;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 19U)) + 5555455638503958639U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + 5669470540733721606U) + aNonceWordG;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3042388456327784163U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2236734925228156691U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 10076582424701705531U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14459720401528685450U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4814967631216658856U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18288097536171386643U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16950679344449075945U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6262238639302011050U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 9942659897425088183U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3522256359074996724U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12524717897707074242U;
            aOrbiterG = RotL64((aOrbiterG * 6787771338063891989U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13891759914865623828U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11910250571469028666U;
            aOrbiterK = RotL64((aOrbiterK * 12311343917878428995U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2240189915640314069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5365912986308810837U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 15133972552032469957U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9323732721344489753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13087326560957916553U;
            aOrbiterH = RotL64((aOrbiterH * 14659491687401151733U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 26U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 58U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25049U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 30125U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24739U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29383U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 22U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 16462052553719977502U) + aNonceWordI;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 5U)) + 12337064059566619581U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 53U)) + 15801005007094515447U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 8228706742665081656U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 11U)) + 11006723027845190869U) + aNonceWordN;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 18173765337829177450U) + aNonceWordP;
            aOrbiterE = ((aWandererI + RotL64(aCross, 60U)) + 530215083653542558U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6608611827035564511U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2246051826221626809U;
            aOrbiterB = RotL64((aOrbiterB * 6333352641495253539U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5228575308895381421U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10999213210689606857U;
            aOrbiterD = RotL64((aOrbiterD * 5467601259546342925U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3773371037240485696U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8887985779436152504U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 698713082830739677U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11150566414723818350U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8336366151003049546U;
            aOrbiterC = RotL64((aOrbiterC * 9033771197242493699U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13233968794237090787U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8172558473508478819U;
            aOrbiterA = RotL64((aOrbiterA * 17837070423649268435U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 133564480283347997U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15104810248883567064U;
            aOrbiterJ = RotL64((aOrbiterJ * 706802420642303533U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9138629520201127075U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 13993086066341664080U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 4875046427147105077U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 34U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Boxing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD97B1F41F91BC98BULL + 0xB2D7BDEB5037A31CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8362B83F4DE3831FULL + 0xB57D568EB4754415ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFBCD69E092AAB561ULL + 0xCF01B31D9EBDF5BDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDBB487FA3FCE51F3ULL + 0xFB8417AB4218C0CDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD2989DB607232CF9ULL + 0xB3815AE0418FA1D7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xED5D190C0E3D4497ULL + 0xBBA3853C68A21285ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD09DA9CD53944F7FULL + 0x8B28F39057705214ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE0507F7C7A72741DULL + 0xD9A7D2498D25FAD9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB199E6DA63070B47ULL + 0xAD0D1A46B05642D4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCD91871E2D7989F9ULL + 0xF5D19AA38B43A3E1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB07D0B710AE4F6A9ULL + 0xE2BFF8A60F24B290ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAA808DEC78926C63ULL + 0xD7A47FAE13904ECFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBF5FD871CB511699ULL + 0xA6D4C5647AF5632BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC8433DD74F417167ULL + 0xF80A777A7D5C4DD6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE176B2A68C40A1A7ULL + 0xFEBEBA1DB5B40306ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA94DF55ECE870E3DULL + 0xF64F77EF71358AD3ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1367U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 5923U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6309U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 5685U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 11410829607777684449U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 14U)) + 7502698839700975347U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 53U)) + 13267685058252106173U) + aNonceWordN;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 35U)) + 238242706996630625U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 23U)) + 8184695499511454281U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 12767823220461985403U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 12293198423143850330U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 11149495229952495939U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7556992689338382800U;
            aOrbiterJ = RotL64((aOrbiterJ * 18232398462716803063U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3431338808774134649U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16863099140844995099U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 752376661101787919U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17872458049880677604U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16760153457252546974U;
            aOrbiterF = RotL64((aOrbiterF * 11225037229069712805U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3115544493537438408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4359882942759752958U;
            aOrbiterG = RotL64((aOrbiterG * 561477566995575801U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13387113067202396536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12955690074544490161U;
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15614054443728226807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1939441328066616114U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4484917074808974359U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4599016263007782537U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9962305629016158048U;
            aOrbiterA = RotL64((aOrbiterA * 1496184427500037279U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8737U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8834U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16294U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 9508U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 11U)) + 6654158889644956636U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 9045779659363991870U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 3888897662136993491U) + aNonceWordK;
            aOrbiterA = (aWandererA + RotL64(aCross, 57U)) + 6882016842864459345U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 4U)) + 15601891715956172291U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 5176811598629335350U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererH + RotL64(aCross, 51U)) + 12519945150889074325U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 4552583214397603278U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14225482701804864688U;
            aOrbiterK = RotL64((aOrbiterK * 8526052833180466359U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5485298070606280363U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11237713257388094289U;
            aOrbiterJ = RotL64((aOrbiterJ * 11032429223099413011U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14340345895626142788U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7308578867128951199U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14041860597556520250U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1436068974197066343U;
            aOrbiterB = RotL64((aOrbiterB * 3938460345031496843U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11483155566419547004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4608508534724289325U;
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2389196334288832895U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4062682330273866602U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8787682133271101901U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5655656046585592034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7977947821249746880U;
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 4U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24282U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 16937U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18222U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 17452U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 16451272412693907816U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 10099485419723255462U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 47U)) + 17668900099534923192U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 5497093724143181753U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 34U)) + 10354044773550071706U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + 12728258851198019099U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 4144050505314242618U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14133805325480076530U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 308863673210602899U;
            aOrbiterH = RotL64((aOrbiterH * 2672613556981540433U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11741180130160569753U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12926863156769180448U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9726030996091054939U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 211920854786494259U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13234608842479411078U;
            aOrbiterJ = RotL64((aOrbiterJ * 2556747209733759467U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9164711974854618892U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6667377062281954219U;
            aOrbiterC = RotL64((aOrbiterC * 2603737166987437649U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4559040002406721850U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1749875480850675109U;
            aOrbiterI = RotL64((aOrbiterI * 15822640067349481089U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 9555365165561936366U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18289733999504213574U;
            aOrbiterK = RotL64((aOrbiterK * 14156217554673229429U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8727162691639622461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 291406782452963706U;
            aOrbiterA = RotL64((aOrbiterA * 8413500075082350243U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterH, 56U));
            aWandererF = aWandererF + (((((RotL64(aCross, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28132U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 30932U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29350U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 25175U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 11521331427196538632U;
            aOrbiterH = ((((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 16653824187682957632U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 3U)) + 11654676587350088289U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 37U)) + 8010313317412193584U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 11U)) + 1108775560502907471U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 21U)) + 243952321439823521U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 57U)) + 2324945800401240403U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9257554497543369657U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16701314607244592540U;
            aOrbiterB = RotL64((aOrbiterB * 8790054741039817107U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3900445848034341782U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7652316487347103658U;
            aOrbiterJ = RotL64((aOrbiterJ * 11480123491361589799U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14980368605272070578U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2001165460948764796U;
            aOrbiterH = RotL64((aOrbiterH * 8110980921827107649U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1911044015666991050U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11366207111147818339U;
            aOrbiterG = RotL64((aOrbiterG * 17234439040652553865U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16469329744002456607U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8062793687044950815U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5856142259851144369U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 15364721421972807872U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8979915611483540231U;
            aOrbiterA = RotL64((aOrbiterA * 10899377466171153383U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7654234623563110457U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1526832460342135008U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12766083052650723051U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordN);
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

void TwistExpander_Boxing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC63A9545331BE76FULL + 0xE122CF705D84196EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x802F8AA76406A5E3ULL + 0x83C2D882A08C3677ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDDFD8F934EA45A6BULL + 0xE1A1CB5E15C6198DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC32EE8CCA1322B69ULL + 0xE9D6733F8B140FC6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB93A38F3D6635B89ULL + 0x8BCEA9F19F16794EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB08C7990C908931DULL + 0xFF1C0552B667CDF6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDD1657063CDB4DF9ULL + 0x977F7BA92BB853DFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96354365CD602877ULL + 0xC3BD3FFD3F21DF3EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD97FE84901235C97ULL + 0x8A51240D7DB48004ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBA132081FDFB30B1ULL + 0xD00B3F5D00405EB7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x81B8286308983207ULL + 0x992BAF320F2EBB22ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFD98666B8614D903ULL + 0xA989C764D622BB0EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9AA9095073848677ULL + 0xFED81D0558725840ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x85EDC2492B9ABEC7ULL + 0xB19B0BD5650BC75DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x981768493A395E65ULL + 0x89B4FBE658E91B75ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD82A665AA17B6761ULL + 0xE964FD2EB1BDB193ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3579U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5727U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6865U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4913U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 34U)) + 12632404972795375757U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 51U)) + 5351879979055988456U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 39U)) + 3597737727467443413U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 2830846754917852318U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 29U)) + 17311925960294518018U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 3U)) + 2083584640523695383U;
            aOrbiterH = (aWandererH + RotL64(aCross, 53U)) + 15049343611387010158U;
            aOrbiterB = ((((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 6443050378205811147U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + 6021965178697344070U) + aNonceWordO;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 5080289878758029976U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 42U)) + 576927745306972983U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4728489691382690859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6184355840165758855U;
            aOrbiterA = RotL64((aOrbiterA * 1515043910404156423U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11220539885798595450U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11091438724966718214U;
            aOrbiterG = RotL64((aOrbiterG * 8225347114759391961U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17184210490020062419U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2150997767099116408U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 8058553821648892499U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7021953562676903717U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17159676348343312834U;
            aOrbiterF = RotL64((aOrbiterF * 13877284519668483549U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10367891770525239784U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11922478487264201233U;
            aOrbiterH = RotL64((aOrbiterH * 9195137452661956029U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17815162358981720634U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9582631251085100284U;
            aOrbiterE = RotL64((aOrbiterE * 11838992994130850483U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 872593750259572264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17832330100262167302U;
            aOrbiterC = RotL64((aOrbiterC * 1114416841510028467U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16601139856969287418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14931287111691324985U;
            aOrbiterJ = RotL64((aOrbiterJ * 16757174577841001179U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11413072442039115924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15253605470589905889U;
            aOrbiterD = RotL64((aOrbiterD * 10832817442285245673U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3653487723581514107U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14891378240114471865U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 1386594204573386051U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15659724464711852035U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12632404972795375757U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2407347385127296647U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterE, 58U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 56U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13058U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14713U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9932U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 14011U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 36U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 6U)) + 3561491146322798260U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 19U)) + 7075025056181885339U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 9230910887904171613U) + aNonceWordG;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 23U)) + 4119781172609908917U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 21U)) + 17155609083870983149U) + aNonceWordD;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 3U)) + 2423018561430181695U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 12957280305617615744U;
            aOrbiterI = (aWandererF + RotL64(aCross, 43U)) + 2461704174772065813U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 5U)) + 7907123257849391997U;
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 7257868138318960007U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 47U)) + 16425903703085702285U) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2990822664594079467U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5654819006718953817U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4465096036756887801U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12183676471235678779U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15026286960542123922U;
            aOrbiterE = RotL64((aOrbiterE * 17199049329995315279U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12169080607071830522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2906296852254787499U;
            aOrbiterD = RotL64((aOrbiterD * 6754514406846040163U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3029858695410344584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14406410317495954566U;
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11048818178401163861U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13622063920319445043U;
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2642646089141233277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12761571777929273548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5518252696078700127U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7753802695131502382U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8510425459525030222U;
            aOrbiterB = RotL64((aOrbiterB * 12412361423636026483U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13522645164493316722U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1437430302489702713U;
            aOrbiterK = RotL64((aOrbiterK * 14019316635365783545U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14745189473423751499U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16968328257002103715U;
            aOrbiterI = RotL64((aOrbiterI * 17915588590593471981U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5001838243344386314U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13506188720092630563U;
            aOrbiterC = RotL64((aOrbiterC * 7010027510838271877U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16902624500530747723U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3561491146322798260U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 95761172090277669U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 37U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 42U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 51U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 10U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21705U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 16541U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18523U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18184U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 18U)) + 18302975933754610273U) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 16736972646771456082U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + 17389406266488137442U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + 5252511566486165539U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 23U)) + 5730715427422747640U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 54U)) + 6412695646456045825U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 9539701605708994494U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 18355107116412945722U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 41U)) + 11735742491750132942U;
            aOrbiterF = (aWandererE + RotL64(aCross, 51U)) + 12363819388562658842U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 5861430292304371543U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15027487084595017708U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7012850020745791926U;
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11904871669287886120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11199760114477343208U;
            aOrbiterB = RotL64((aOrbiterB * 7156374911847525867U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3856004502263742700U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3705931243173921893U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 10334871178498711485U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12305785390539209389U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18057980996551978823U;
            aOrbiterA = RotL64((aOrbiterA * 4850564181113470859U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3229431819292153014U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2994716629242460094U;
            aOrbiterD = RotL64((aOrbiterD * 1029427328395257917U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9796307843453735512U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2957260393651252432U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 7261055869794739609U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4060469664218866340U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17462081697889685330U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7712009170974461225U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13638660073917821172U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15202349592659062565U;
            aOrbiterK = RotL64((aOrbiterK * 4514326257446024301U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12071949111168967041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11930843273199806728U;
            aOrbiterG = RotL64((aOrbiterG * 16229663295689525137U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11294220104731500296U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 440743185210586759U;
            aOrbiterH = RotL64((aOrbiterH * 14810195235168807229U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8514240764798061804U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18302975933754610273U;
            aOrbiterC = RotL64((aOrbiterC * 1972439346780950873U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 48U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterK, 14U));
            aWandererI = aWandererI + ((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26508U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 31602U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26287U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31314U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 6U)) + 14686411261024919129U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 19U)) + 7514582233957632005U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 6520710480103365552U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 35U)) + 1983621978676188036U) + aNonceWordK;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 37U)) + 9003524602590749672U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aCross, 13U)) + 6428568234045228995U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 8656552687136446989U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + 16916248288415922490U) + aNonceWordO;
            aOrbiterK = (aWandererH + RotL64(aIngress, 30U)) + 9740237548002535784U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 907561000814618339U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 57U)) + 4751108900841197631U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 167774899400732287U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11907484918310854962U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7213139491146402985U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14910318613649863924U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16175942562693781908U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11022373758481651102U;
            aOrbiterJ = RotL64((aOrbiterJ * 6836331461393816027U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12548405399045031548U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10850926364556828443U;
            aOrbiterF = RotL64((aOrbiterF * 16231561687709867431U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13391684887911141790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14648937281264822988U;
            aOrbiterB = RotL64((aOrbiterB * 6533299316940026059U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8298658887198526821U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13822977698661348891U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 17769262972278410937U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7505646847564645719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3238749538197209166U;
            aOrbiterH = RotL64((aOrbiterH * 15394286542600778567U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15853506915123709257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8426329899401071248U;
            aOrbiterI = RotL64((aOrbiterI * 1330397096577715113U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14848635392815613098U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3549927798350175044U;
            aOrbiterC = RotL64((aOrbiterC * 1899044682313056949U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1798973117197750802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13056711228618953977U;
            aOrbiterE = RotL64((aOrbiterE * 9102877396419306689U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1395893547965799281U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14686411261024919129U;
            aOrbiterA = RotL64((aOrbiterA * 17075377081365066067U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 10U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 4U)) + aOrbiterF) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 40U) + RotL64(aOrbiterH, 48U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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

void TwistExpander_Boxing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9B14EC8B7E7BEEC5ULL + 0xC76C33ABA5832A1FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB789F0DA1DBD85DULL + 0xC74B743269374680ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9EF8AA8A5B89A6FBULL + 0xC98E1F1FB54FDBA3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC26301CA230072F5ULL + 0xCC151F79E6759F55ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE9BC985E05D3922DULL + 0xD7EE41F50454C21EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC3C4B4F5FB4EC7F9ULL + 0x9B2874757E805295ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA62D6F51701DA83DULL + 0xA272AD8A796ADD64ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFE31198800A7009FULL + 0xBDE6845595546449ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8EC9149F7A9C91B3ULL + 0xD61D3E45EA6668D9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD3F8F38426676DA1ULL + 0xBC14F5216C65C7F7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8788AB7261EB11DBULL + 0x9D70A9C30869521DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB977BB3B5F2874DDULL + 0x948BED68DA63EF98ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB50DA4AA040A68BDULL + 0xE30FCC4A5A59D5B6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94657C0E75B90A4BULL + 0xFD35D6CE690690F6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC16277B0456BBD39ULL + 0xEA61F334AB9BED44ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBAA857195FF5B561ULL + 0xC6386F5656E0789FULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2672U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneC[((aIndex + 3318U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 728U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1042U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 27U)) + 6521330037475130256U) + aNonceWordM;
            aOrbiterK = (aWandererG + RotL64(aIngress, 19U)) + 12611880456055428940U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 6U)) + 12061611078130934708U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 1558112410801116984U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 10509115227850160786U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 4045915960688792066U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 1196541286513243082U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + 15564991032722373702U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 54U)) + 4897765238703641798U) + aNonceWordG;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12327429514907752733U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6189189797708711636U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 9017615866338877651U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6374267075282018852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1888758503831341439U;
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14956857689299491800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14879361107223331957U;
            aOrbiterH = RotL64((aOrbiterH * 9166712966729591953U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16086885494838105042U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterC = RotL64((aOrbiterC * 8878470736758734353U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10854345917959911439U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7078313614360332089U;
            aOrbiterF = RotL64((aOrbiterF * 9864025732292844871U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15083669236062255011U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 594879695916679116U;
            aOrbiterJ = RotL64((aOrbiterJ * 9852515479152735283U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6721466068234534523U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 475816724162626782U;
            aOrbiterG = RotL64((aOrbiterG * 4799725182757588407U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4341655358154605899U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15477254302340298586U;
            aOrbiterK = RotL64((aOrbiterK * 13961520225881974201U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 10179091913200895775U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6310490897546909571U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15080621088825477613U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 18U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 30U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7010U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8840U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7160U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 6720U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 22U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 13960289014350612206U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 12U)) + 3483331015269589730U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 19U)) + 6873299241002444518U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 3562094007125534229U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 37U)) + 11422367439932782705U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 532453428514259816U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + 17810941465810193088U) + aNonceWordE;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 60U)) + 11869759058631106331U) + aNonceWordD;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 51U)) + 8837581071876177566U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17185378327053837778U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7578253375676981500U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 13371647568758721729U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17112646434432814442U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14949096407295697881U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14770977858283051753U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4259590620758467836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6534899413644542303U;
            aOrbiterF = RotL64((aOrbiterF * 7987609419215568661U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2637407498893694243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15819295597921425711U;
            aOrbiterC = RotL64((aOrbiterC * 5202015597375051399U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6373559542002699718U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3308736483775453062U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12749929710650475901U;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1569528215675579656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1044077933631689572U;
            aOrbiterI = RotL64((aOrbiterI * 6443796233912755143U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8393422728124537471U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2002732612516530754U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13702146823622364279U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13469191942843147943U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 7633171368709520560U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 9713514012478203047U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 42U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 36U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterE, 36U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterI, 14U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14852U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12447U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15735U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 15461U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 11998579547770778580U) + aNonceWordJ;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 28U)) + 8409465187298704610U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 51U)) + 3470222286110333500U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 5704486785203069994U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 57U)) + 10334944660253279633U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 39U)) + 7626852700722567477U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 12U)) + 14631310754943209743U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 807160297237854120U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 47U)) + 5624154783624196107U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4971444394698940423U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6340057638461027062U;
            aOrbiterC = RotL64((aOrbiterC * 12027586111086798629U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9003019862787819481U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13632057463595873033U;
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12766104026871797746U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4062118445824915939U;
            aOrbiterH = RotL64((aOrbiterH * 13130770039048080701U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5258212525426469978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9956946981015983939U;
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10837606223056473999U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13292864885504191134U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 166087925900318658U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4411147600413147773U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16888086378070246404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5240855484445974002U;
            aOrbiterK = RotL64((aOrbiterK * 402652898573422271U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6874866669211571608U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 732890824978127460U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3776365957702257453U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5541380495707308058U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17947326584411475765U;
            aOrbiterF = RotL64((aOrbiterF * 10920952349981652899U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 58U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 30U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17552U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 17048U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17499U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 17719U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 15036852811491820366U) + aNonceWordP;
            aOrbiterE = (aWandererB + RotL64(aScatter, 52U)) + 305637140752898475U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 37U)) + 11948631574496129610U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 47U)) + 5321623592482991426U) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 4075270159062690728U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 22U)) + 15111580500356908928U) + aNonceWordC;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 7244150695504160363U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 57U)) + 5131563519577488862U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + 5881954992088651371U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12780935808751507998U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12599159643925470226U;
            aOrbiterH = RotL64((aOrbiterH * 17690046932587062701U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9466589929741834066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6093158735705189789U;
            aOrbiterC = RotL64((aOrbiterC * 7453778295800853653U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17461243886150519249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15456408913739900718U;
            aOrbiterF = RotL64((aOrbiterF * 16093292401746174671U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11260643903290392780U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7870342756041882616U;
            aOrbiterD = RotL64((aOrbiterD * 2431528656086173419U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 134484990005888936U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10626896209992890407U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 12034131076645285597U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14031164129515132292U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1771835705730244212U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 186981668443596623U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16395472745067254664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1455944290845294254U;
            aOrbiterA = RotL64((aOrbiterA * 6757824754363319079U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17866422769075350837U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10226884082632410805U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 206035536985843815U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14474587247775371703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8501763445324525303U;
            aOrbiterE = RotL64((aOrbiterE * 5298694643596784007U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 24U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 41U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 18U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 22U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 24U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25099U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24747U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26866U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23916U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 58U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 23U)) + 12632404972795375757U) + aNonceWordF;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 4U)) + RotL64(aCarry, 37U)) + 5351879979055988456U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 3597737727467443413U) + aNonceWordN;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 43U)) + 2830846754917852318U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 19U)) + 17311925960294518018U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 13U)) + 2083584640523695383U) + aNonceWordC;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 15049343611387010158U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 60U)) + 6443050378205811147U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 51U)) + 6021965178697344070U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5080289878758029976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 576927745306972983U;
            aOrbiterB = RotL64((aOrbiterB * 16008958833683246115U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4728489691382690859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6184355840165758855U;
            aOrbiterG = RotL64((aOrbiterG * 1515043910404156423U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11220539885798595450U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11091438724966718214U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8225347114759391961U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17184210490020062419U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2150997767099116408U;
            aOrbiterA = RotL64((aOrbiterA * 8058553821648892499U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7021953562676903717U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17159676348343312834U;
            aOrbiterI = RotL64((aOrbiterI * 13877284519668483549U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10367891770525239784U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11922478487264201233U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 9195137452661956029U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17815162358981720634U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9582631251085100284U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 11838992994130850483U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 872593750259572264U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17832330100262167302U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1114416841510028467U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16601139856969287418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14931287111691324985U;
            aOrbiterJ = RotL64((aOrbiterJ * 16757174577841001179U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterB, 48U)) + aNonceWordI);
            aWandererH = aWandererH + ((((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterE, 18U)) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32712U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30076U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28587U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 29754U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + 6069475454765660321U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 39U)) + 11483704742497268068U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 11055697447388986418U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 34U)) + 10897095046039997004U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 4731637118230457840U;
            aOrbiterE = (aWandererG + RotL64(aCross, 27U)) + 13855839187084986751U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 5328208115460188239U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 60U)) + 12479538544291412985U) + aNonceWordD;
            aOrbiterD = (aWandererE + RotL64(aCross, 11U)) + 10740165998792608231U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 6492798157284955373U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13056825957483891921U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14882112110627751751U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2068184064919194657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5656302738780746294U;
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11193756120230763294U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17306750816837208999U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7949360041241439741U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12952818800389361804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15380412293642628312U;
            aOrbiterK = RotL64((aOrbiterK * 2914662289178925547U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7706090204767242996U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14598802276412649570U;
            aOrbiterD = RotL64((aOrbiterD * 4821408736292041399U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17819762117328075515U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6481384240915075101U;
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 754936290510338717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15510875946573720154U;
            aOrbiterB = RotL64((aOrbiterB * 2994718968852184303U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9245381722813944586U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2629847912019726214U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6718795794951106961U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3909987749797113773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9277056074757335265U;
            aOrbiterI = RotL64((aOrbiterI * 11580847505996697115U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 46U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterI, 18U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 46U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordA);
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

void TwistExpander_Boxing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEDB9C372FE3B2AFDULL + 0xC3FD30D411EB7916ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x99884DE56B93B9D3ULL + 0xFF13AF7C20E03656ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF28E061D907A40DDULL + 0xDE698B9B15E09C05ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8CA9D00A9F4764A1ULL + 0xE5BDE3CA48FB89C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC0E1BA0C4AF7A699ULL + 0x834E7EF5A0E6F78EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE17CCFADA1EE7D9FULL + 0x86584EF7AF254230ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x930201A0A29FE985ULL + 0x8BA6E481EF3E9009ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF3A24622C9C39383ULL + 0xE07177A71D657929ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x935BDB839A4B1CF3ULL + 0xE0301E55F604624FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x91922EAF72400025ULL + 0x920E00A2DBDCB740ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF20BB5F4B4A8A38FULL + 0x9447159D177E363FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9C4B31BEE7380335ULL + 0xF5A6A86F894E4C72ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDF3A0F87D35A81C3ULL + 0xDBAFE6E4DA673252ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE3965D3DC9559215ULL + 0xD382BE5581B75268ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8AC5D888E394E30DULL + 0xEFF8158BBB3F40D1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF2E2769D193991AFULL + 0xA689B5F14346D083ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3805U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 3495U)) & W_KEY1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3195U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4984U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 3970829908171131502U) + aNonceWordO;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 37U)) + 7040283759419531991U) + aNonceWordD;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 11856292169397052901U;
            aOrbiterD = (aWandererD + RotL64(aCross, 43U)) + 819598588791819022U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 2176451710970866848U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 21U)) + 6454704928613390494U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 6U)) + 11792122387218053841U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9254780213489752211U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16591812589999846482U;
            aOrbiterJ = RotL64((aOrbiterJ * 5425771603523423167U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1471246223935074832U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1424843083106386453U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15020536982657410783U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1856469958050891629U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6331743690452052712U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 15327924647897459645U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10351075711345476487U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9518585245330480185U;
            aOrbiterA = RotL64((aOrbiterA * 3792179827396760391U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17787514620244712033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14182328067398162557U;
            aOrbiterC = RotL64((aOrbiterC * 18107337388659070197U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12798088948801072444U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 9563215159275202323U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 7058145016617349141U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9904919772580498232U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16579777394992143043U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10516761340320196661U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 28U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10039U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 6333U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5967U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7936U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 2783898056762489197U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 7177192902873343053U) + aNonceWordO;
            aOrbiterF = (aWandererG + RotL64(aScatter, 13U)) + 12254703232691980774U;
            aOrbiterA = ((((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 15446547245691219559U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 21U)) + 888475203006174856U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererA + RotL64(aCross, 3U)) + 3649183529366307877U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 27U)) + 4642631047518805167U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6108329730724782250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8334054653023816636U;
            aOrbiterF = RotL64((aOrbiterF * 9352516059501924393U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 5891895375031474350U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3176720746238477862U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1869961473768307911U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6111038696865301675U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11914998302228682704U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17005063057791320948U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18333780598768130670U;
            aOrbiterI = RotL64((aOrbiterI * 5416759844884107303U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2056115016443263153U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10245512728872962677U;
            aOrbiterE = RotL64((aOrbiterE * 707106795383284903U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4810366069422162351U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterK = RotL64((aOrbiterK * 13558537578054436423U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9285068547223654308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 58U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordF) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aNonceWordL);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 41U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15191U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15384U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13774U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 14411U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 30U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + 9446153639709651566U) + aNonceWordH;
            aOrbiterE = (aWandererE + RotL64(aCross, 41U)) + 10550762260670758167U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 14U)) + 7062634922142578383U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 9178499097812764515U;
            aOrbiterB = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 6887103379773525538U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererH + RotL64(aCross, 29U)) + 6239750312052010257U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 17645022614523287959U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3639618183259408272U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3131737117548745095U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6585057380704940395U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7253994382396406554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15217993711938379561U;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12594152227603630033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11250170200489647869U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 546800378327864723U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12936942656624279424U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10990736056052106149U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7123916809953459187U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12787293075893090465U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17154990205620778151U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10031369940028159521U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1270827262969060301U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17337623431665013136U;
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 830330490987911853U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6828309232554560547U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 9742464176986145819U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 60U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21127U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 20070U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21729U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((aIndex + 20901U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 14179205183062705133U) + aNonceWordD;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 210032324058740920U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + 7387115089142500152U) + aNonceWordF;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 10U)) + 17583362781238061430U) + aPhaseAOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 4991442849150005943U;
            aOrbiterC = (aWandererC + RotL64(aCross, 3U)) + 2891376254689854555U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 10523274382407446239U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3861893764676218667U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3366674459852093746U;
            aOrbiterA = RotL64((aOrbiterA * 14005994095369483813U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5898492634386601145U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7047353571244768721U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2257518291062508467U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14374108805453186316U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8763667021501226510U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7694695426430267863U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18261523829316379575U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 650477532238860965U;
            aOrbiterF = RotL64((aOrbiterF * 8291758490821819851U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2162326554604894042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5776546692501825278U;
            aOrbiterD = RotL64((aOrbiterD * 14911545784585246537U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3501863793638415049U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14853789267425352958U;
            aOrbiterE = RotL64((aOrbiterE * 10590325397179928739U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 15399673014671329743U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12253428583438990426U;
            aOrbiterI = RotL64((aOrbiterI * 12052855472196447849U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 4U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22616U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 23719U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24671U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27073U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCross, 29U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 5U)) + 10805654776556844351U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 582794182442795335U) + aNonceWordC;
            aOrbiterI = (((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 2858343650974681068U) + aNonceWordL;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 8189584049022064284U;
            aOrbiterH = (aWandererH + RotL64(aCross, 13U)) + 1565100751996962893U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 53U)) + 8062028016947611891U) + aPhaseAOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererG + RotL64(aScatter, 29U)) + 8280504280578451745U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11326869194491655350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1671695656567777163U;
            aOrbiterI = RotL64((aOrbiterI * 7511554500524257921U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2349843105293943452U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13015545152052004254U;
            aOrbiterF = RotL64((aOrbiterF * 1316662811685429983U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16703354404749291869U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 8713231044374305801U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11118401674497783533U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14857556493734710364U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12953419670951660965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12666121730825089017U;
            aOrbiterH = RotL64((aOrbiterH * 14049925256934142519U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11075249639473053423U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9374217688244187867U;
            aOrbiterE = RotL64((aOrbiterE * 5261156325627117877U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17608340953291367867U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13159437499327086340U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4882100944453534805U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 12U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aScatter, 42U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aNonceWordM) + aPhaseAWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27800U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29658U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32691U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 29933U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 9107326720193244489U) + aNonceWordK;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 19U)) + 10868585484401664145U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 51U)) + 13637736741437846622U) + aNonceWordO;
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 6130725216183918844U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 30U)) + 2063834478521338187U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 8564870627911949158U) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 57U)) + 6524015751064086390U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9874937766875388236U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14723718409522680894U;
            aOrbiterG = RotL64((aOrbiterG * 17379140128833323431U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 13767059954741528279U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6387608251033722169U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6601902195707980693U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5391425980008431000U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11524218415655093779U;
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 155510463350385905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10554591788433641311U;
            aOrbiterA = RotL64((aOrbiterA * 5412084824127934293U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8662160162966241542U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5092555636369853727U;
            aOrbiterF = RotL64((aOrbiterF * 433807340167635499U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7163345798448796101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 695089002178413267U;
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5409173939213468972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15349690077393827541U;
            aOrbiterC = RotL64((aOrbiterC * 10984681254001609841U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordG;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDFAB61D0D604A275ULL + 0xEF595F14F4C7B7B6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x994007559CFB616DULL + 0x92BF5BA560CA3864ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x833987131D01F521ULL + 0xBCB7C85CA61F7C15ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBA253C106430BF9DULL + 0x9735378FEB32794FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA4AA4D806A9667EBULL + 0xA3EA6E6C1FDD0415ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF43ABC7436FA5B17ULL + 0xC3D2D26C5471E4BFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBC34359B8D229389ULL + 0xD0C737E2AE05C8DBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA23105469F601C39ULL + 0xE65DDD95C20554A1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEFC1412961A35109ULL + 0xB429162DD0C6F0F1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF250060B136F25CDULL + 0xA122D63D581D77E3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF47A983A806524A1ULL + 0xBD4CDC7010380116ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8C0DCE049CEEFEFDULL + 0x9713E6F8F7E8CBEBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBB857E8BD825B80DULL + 0xB8F5DDDDEE5221ADULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE1BFEA6C579CC503ULL + 0x9B7373733C715FDEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA052E03AE54F15DBULL + 0xDE1E7F43FAE322F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDD021891ED87B3D7ULL + 0x8B273FE740887F2EULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3726U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 187U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1458U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4803U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 44U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 13924571355038625040U) + aPhaseBOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 16328300979357156658U) + aNonceWordG;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 3947771961206012461U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 3U)) + 15428284250569311285U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 46U)) + 5777369485254032486U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16813320300717644673U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16689933050200758251U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 4832495563863469353U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1856422419049390708U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 18214498743831925517U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10744120577560529379U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18278550878494094923U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 797712062039591797U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7212998747080137625U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15854849439012341347U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 996882939768167773U;
            aOrbiterK = RotL64((aOrbiterK * 14936703950807908575U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3005829974130671692U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8793495343509953906U;
            aOrbiterH = RotL64((aOrbiterH * 14065479348374612031U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 35U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aNonceWordI) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 4U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8167U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9752U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8152U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7338U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 12849591986267890852U) + aNonceWordK;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 8232614804696815750U) + aPhaseBOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + 12141567259210877281U) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 23U)) + 2928641981037885644U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + 980733350554783938U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2683985177993350746U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14532148403815527355U;
            aOrbiterJ = RotL64((aOrbiterJ * 15985362037094864225U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7736296629433884203U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10428437770166310549U;
            aOrbiterD = RotL64((aOrbiterD * 326634742742373401U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18327174144859461029U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6810436935194432002U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2715987179577753597U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12606153309690753435U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17123256945895150555U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13469111258504672565U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9057777759026189541U) + aNonceWordF;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 16478485918911194442U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 52U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + aNonceWordP) + aPhaseBWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 42U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + aNonceWordM) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13055U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14241U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16021U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15292U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 22U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 21U)) + 16922357079016918108U) + aNonceWordC;
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 11771749797137599131U) + aPhaseBOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 4635668433708036077U) + aPhaseBOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 44U)) + 15827952719230577008U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 1495675306110023086U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 7294835466949728365U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 179122461212041978U;
            aOrbiterK = RotL64((aOrbiterK * 14467072888722097971U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 545981421632236251U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15338259639814630535U;
            aOrbiterF = RotL64((aOrbiterF * 14895421566334357871U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12924313840290895215U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17846785921286020610U;
            aOrbiterD = RotL64((aOrbiterD * 18309347016029917133U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5721472794107057875U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16359630793856870319U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14186771515526698907U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10614102110239037308U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16421992251278236531U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2561232904676068089U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 48U) + RotL64(aOrbiterK, 40U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aNonceWordF) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16690U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21207U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21821U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 16625U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 2177539223979303669U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + 3962004686551521471U) + aNonceWordP;
            aOrbiterD = ((aWandererA + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 8457602312617147662U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 18011802451816510632U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 21U)) + 9046101759168876832U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11135620637431969597U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15913029940697999701U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 646524659942693491U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16304193109948135982U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13208892298820080981U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15093751072618884859U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4182377898949419225U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13970137023071326151U;
            aOrbiterK = RotL64((aOrbiterK * 9075061559681739865U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 8402396284835248583U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 8859190834060657829U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 13552418608113716117U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9760005337757990392U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14108277760135744897U;
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 36U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22678U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 26874U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23321U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26160U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 826930775230515406U) + aPhaseBOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aWandererG + RotL64(aCross, 11U)) + 5137814617363250861U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 14761561947426681616U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 12773023438753662590U) + aNonceWordF;
            aOrbiterI = ((aWandererA + RotL64(aCross, 58U)) + 7331345852207096322U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3899381212671247460U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10072004147620068599U;
            aOrbiterC = RotL64((aOrbiterC * 5663583566047763435U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3424585039401897560U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8246760141625966321U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11478879365443736383U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3655992860610853290U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11154618022505863898U;
            aOrbiterG = RotL64((aOrbiterG * 4791494171286145231U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15629361991059709973U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10842068502278489664U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17223002513104960799U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 5571312349016336686U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 589313823745748879U;
            aOrbiterJ = RotL64((aOrbiterJ * 1356685926549786027U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 58U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27542U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30313U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32143U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31732U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 12U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 43U)) + 6163290588946759209U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 24U)) + RotL64(aCarry, 19U)) + 7342672468560105447U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 57U)) + 11574563167017282321U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 2254820206194758964U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 1469783447473099498U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14174828900676165088U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16277954291890598132U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4608888834164373691U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14845750668693136766U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 150099699692047766U;
            aOrbiterC = RotL64((aOrbiterC * 7644895634421086357U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1200784917165131703U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9469982764806754302U;
            aOrbiterK = RotL64((aOrbiterK * 17851969334511301943U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10956702761701710182U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7915506894975487807U;
            aOrbiterB = RotL64((aOrbiterB * 8874108311712727983U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 17335794183733623213U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 557028996286989506U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3993359298602424281U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 12U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Boxing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD474FECFB128319BULL + 0xF9CAA8FE37AF4765ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE717CEF0C43EC04BULL + 0xE862C6D449FF7323ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCC0CBDF8D11DC829ULL + 0x99DFA87C05568961ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBDB64FBFD821A5F3ULL + 0xE3D954199146860CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x966416F06757FEF1ULL + 0x89D8660CF498B122ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8672CE2109ED4DC1ULL + 0xBF2451049115F38CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAA3DF69776FA5EBFULL + 0xFB2DA40BA1FC893AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x825811BF5C0A4689ULL + 0xA45A2113D664541DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD1C3A3C26F2E9707ULL + 0x99E012056B556492ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xACBB5F8B66FD914BULL + 0xAB79F6DE64F7C4CFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x89245C2F904BDEDDULL + 0xA43AF0DCBCFFDD86ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFC795B8502DB0EEDULL + 0xE640A5D91E5D38B1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB99F31063B37B449ULL + 0x81050A0A02F131C5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB8E23F40F565DF07ULL + 0x88B8CD3724DDA832ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF9CDA07FE4141299ULL + 0xB94A7F1D92AEF5FEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA7A8971ECA7835EDULL + 0xF87A16C888802368ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7377U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2544U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4649U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2363U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 47U)) + 16124889768301047791U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 11912338587186717280U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 3U)) + 8594012868813114354U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 18281043566156682815U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 54U)) + 16853106130200942302U) + aPhaseCOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 39U)) + 2611212958619673086U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 43U)) + 18039472325066855180U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 14495785571345122046U) + aNonceWordF;
            aOrbiterJ = (aWandererK + RotL64(aCross, 12U)) + 4556063793412832418U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14896419970271244358U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 880028529183500036U;
            aOrbiterH = RotL64((aOrbiterH * 14228281807461251361U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2379557167489415783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11854373946064529806U;
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1487252775956449964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12777924204511625545U;
            aOrbiterC = RotL64((aOrbiterC * 1366019527386994789U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15998631485222477969U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8864212892296191613U;
            aOrbiterJ = RotL64((aOrbiterJ * 579242788050369815U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17069347835763226743U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7443008171694679791U;
            aOrbiterE = RotL64((aOrbiterE * 748894368884566607U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17334256152350782002U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8986626119086556393U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2258172145924120235U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8528180968228358674U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12702290928064582589U;
            aOrbiterK = RotL64((aOrbiterK * 15673603224146737631U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7742438100860023610U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 3729687240959702198U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3756794766163746783U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 426129097367382096U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16782175452274911213U;
            aOrbiterA = RotL64((aOrbiterA * 1041477289638333659U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 30U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 26U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aNonceWordP) + aPhaseCWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10671U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9453U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14319U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15490U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 5171470532667965920U) + aNonceWordB;
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 750549462358682403U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 35U)) + 3325689257577120525U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 18031575461559790826U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 11U)) + 13874739537012288677U) + aNonceWordK;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 39U)) + 4250029868785016865U) + aPhaseCOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererC + RotL64(aScatter, 57U)) + 8211158803112611161U;
            aOrbiterD = (aWandererI + RotL64(aCross, 23U)) + 1083939790236786027U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 28U)) + 3446525462376962464U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6973817815000417325U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15230876489676945543U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9359727659738755880U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8775170107816327654U;
            aOrbiterB = RotL64((aOrbiterB * 6910680458261008653U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11958941755525038545U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16966819714283167348U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14556087985619763243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17915047508377045221U;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8578745677485367222U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7002181668717618866U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12329703532414955235U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3569939503066735457U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2956247934282522184U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9946650822131152531U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4285180013402474041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5976239869535619811U;
            aOrbiterJ = RotL64((aOrbiterJ * 3458095419039067465U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2424524955161695463U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6849595426583763537U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12727902040238318101U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11414890686374886716U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5668287266836153445U;
            aOrbiterG = RotL64((aOrbiterG * 8011885266143066285U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + aNonceWordH) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 30U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 44U));
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23677U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 20760U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20464U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20960U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 2915859148137000694U) + aNonceWordC;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 210680583721444425U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 19U)) + 6668118118775650387U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 15794200818099010989U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 6565076707062828369U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 6U)) + 16323164497808856719U) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aIngress, 35U)) + 7965435318816716560U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 41U)) + 7390281030573369017U) + aNonceWordM;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 2269738866911824875U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9664014216039993873U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18284857398028357633U;
            aOrbiterI = RotL64((aOrbiterI * 8402008251343393737U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 367667619795303009U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7935945060956274197U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5481786693511955209U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16683666162337789540U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10655658270998102390U;
            aOrbiterA = RotL64((aOrbiterA * 15231596813382239841U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8307037916581540297U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052136713218656641U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10446792483683818139U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16374602929344972364U;
            aOrbiterE = RotL64((aOrbiterE * 12599903932725787599U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2411334498322777183U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1093701164116833765U;
            aOrbiterK = RotL64((aOrbiterK * 13129220206835381729U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17018480952982840635U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17348395690080029814U;
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16111252311283623152U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12776492920397785951U;
            aOrbiterF = RotL64((aOrbiterF * 6136009241593081821U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12214538600808144816U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10043377462096783363U;
            aOrbiterD = RotL64((aOrbiterD * 14639467375095185877U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 18U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 6U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32730U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29123U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29031U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29014U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 9133751643283278896U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 18U)) + 8971581804375380408U) + aNonceWordE;
            aOrbiterJ = (aWandererC + RotL64(aCross, 37U)) + 12559650383714566592U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 3U)) + 15753206088872859163U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 7640756270450762350U) + aNonceWordB;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 7340073357551376125U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 47U)) + 5270256573644196046U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 54U)) + 3567367996479995928U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 23U)) + 11939634537492733738U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7051817732424527120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1730487669951837941U;
            aOrbiterJ = RotL64((aOrbiterJ * 15191634337956285841U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18009252467909454817U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2361024272031696442U;
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15902755877642960397U) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12243517544704116184U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16846181962302186187U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 636121425116506681U;
            aOrbiterE = RotL64((aOrbiterE * 17075030673338779993U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6887385655828217318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3705834550934775862U;
            aOrbiterC = RotL64((aOrbiterC * 11275428284929594435U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11165142437077969438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6426659930331618269U;
            aOrbiterF = RotL64((aOrbiterF * 17170640810530893705U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12629082390899315789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4277510580069574724U;
            aOrbiterK = RotL64((aOrbiterK * 9829125163412708305U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 13814834144170469978U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3698381854100295826U;
            aOrbiterG = RotL64((aOrbiterG * 5126359230872258015U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 11623170635983579937U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7247413650388803796U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3403219499465560059U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 30U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aIngress, 26U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordD) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 52U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterE, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordI;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB7AA7373B99AF5B3ULL + 0xB758BAB9F012D51BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF3F69A2D70D4693BULL + 0xFFC93036C1E5CE91ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF635CC7CB0385D8BULL + 0xC62A0182B21D362CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9F63BC51545DDB93ULL + 0xB2A5EB3158E735F4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBC01B18B8E8EAB95ULL + 0xAE4268BC0054F614ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB7CFBE1F3E899503ULL + 0x8BAF70969773DF6DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEDC57F74D1FC3907ULL + 0xD0C6AAC0F53127BDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE7FCA8A5100489EBULL + 0xEFF2B7281A6DBA65ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x85F619AB767ECE37ULL + 0xEB7A59BE25DC82FFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAD5A9038E18D37D9ULL + 0xE9C074749D0182F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA7F67CAC975730A7ULL + 0x8F423A6223FBA9D6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCD5541B3A790288FULL + 0xC4C0450869B8A59EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9278A0895509F69BULL + 0x880DF1EF047FAA58ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAE6205EBCEDD9D8DULL + 0xE604F5B04F222DAAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x92ADBB38A0BD71B1ULL + 0xB2F16BA9B14E1DF6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x886232313BC7793FULL + 0x901CE21DE3036CFFULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5397U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 773U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 858U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 272U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 41U)) + 16160838483846078448U) + aNonceWordG;
            aOrbiterC = (aWandererF + RotL64(aCross, 29U)) + 15404960896190227946U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 14U)) + 16904160594024977199U) + aNonceWordH;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 17790460246821031802U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + 16395168254086971959U) + aPhaseDOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 7484373204039901786U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 11U)) + 18026814691322913510U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 24U)) + 15244817793136966450U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 5795491730356335666U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 3163873518027801504U) + aNonceWordP;
            aOrbiterA = (aWandererC + RotL64(aCross, 5U)) + 2690791759507349172U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17898067251167087906U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8028010015006604239U;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7304739457289910555U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6476837815096530043U;
            aOrbiterG = RotL64((aOrbiterG * 16380545138701113267U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14242499233467960602U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17305645693017634630U;
            aOrbiterH = RotL64((aOrbiterH * 14442976693206929569U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9772864059444171908U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7897200728282156408U;
            aOrbiterJ = RotL64((aOrbiterJ * 816306719390807411U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4890999319172950996U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8165132649356094963U;
            aOrbiterE = RotL64((aOrbiterE * 17297706071263690189U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9342923520083533265U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7213639583505088067U;
            aOrbiterF = RotL64((aOrbiterF * 1349251979649428909U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4079475132684197272U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3350998022472827283U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 948841791460066265U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2479140576609216238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7703147534931674972U;
            aOrbiterC = RotL64((aOrbiterC * 11419116495223970801U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9050277787914448469U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13295888852307317371U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 3027097172772140975U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15380254190549884741U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17653690414528791774U;
            aOrbiterI = RotL64((aOrbiterI * 15923958179714368315U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6825072759468337036U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16160838483846078448U;
            aOrbiterK = RotL64((aOrbiterK * 11690325563580492415U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterF, 48U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 26U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererE, 28U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6890U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10252U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6369U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 10838U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 27U)) + 4634399531433127141U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 16961792729406903200U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 29U)) + 4105280732301137738U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 47U)) + 15692013501147331191U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 13U)) + 1252216715968780587U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 37U)) + 7958289043012473752U;
            aOrbiterH = (aWandererE + RotL64(aCross, 35U)) + 6611577301818896615U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 8506226754305949140U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 21U)) + 3648813120449403353U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 54U)) + 5195245426245535735U) + aNonceWordO;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 542948051600803051U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11974253551208964789U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10596463592332655367U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12015129484061440159U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8254944355710109060U;
            aOrbiterF = RotL64((aOrbiterF * 3233697992479357615U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2754858806943915419U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5007802002906662779U;
            aOrbiterE = RotL64((aOrbiterE * 15613733948331639723U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6262190752136523216U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 10528977986487821428U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 1184258264034585525U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8511097226098211854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12091864735686692582U;
            aOrbiterB = RotL64((aOrbiterB * 6128140528141411237U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4970966265236842566U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10728884018459718341U;
            aOrbiterD = RotL64((aOrbiterD * 18205183219769602827U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13760057185629905360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6590269178744829056U;
            aOrbiterI = RotL64((aOrbiterI * 14482684769712170123U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 765826377665103262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9364759196106579706U;
            aOrbiterA = RotL64((aOrbiterA * 10315111163659289329U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4629303338428087146U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15107221579712215172U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14410837138199304663U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9407987092859067074U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13589362515507116096U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4544198075069052713U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2236921538387014026U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4634399531433127141U;
            aOrbiterG = RotL64((aOrbiterG * 13132011613143486575U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 46U) + aOrbiterD) + RotL64(aOrbiterI, 22U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aNonceWordK) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 40U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererC = aWandererC + ((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15208U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 12181U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13123U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13351U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 42U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 11480359716598965890U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 35U)) + 15431182525482873419U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 18U)) + 11360504974812776707U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 41U)) + 9292576416573382769U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 1549257414531028975U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 21U)) + 5347769463033129317U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 60U)) + 17019199177478377234U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 16558106007323125094U) + aNonceWordB;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 57U)) + 3976182233825939422U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 23U)) + 2889047161195954395U) + aNonceWordC;
            aOrbiterG = (aWandererC + RotL64(aScatter, 11U)) + 2241831345026962605U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12850802412140579294U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13541744735436450160U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 906089290000537439U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2085863085516538212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2969034221711544086U;
            aOrbiterA = RotL64((aOrbiterA * 7768528124408400403U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6482666944512391472U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16969153556875844613U;
            aOrbiterB = RotL64((aOrbiterB * 9483462388353216219U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5161314086757363678U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5465304381272305847U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 2344610773390354017U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 17010258514288089191U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8335906578006588582U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13668796013474193793U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8228000547141147777U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9663362594301419686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3683773739120343413U;
            aOrbiterD = RotL64((aOrbiterD * 8319320803406104749U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2538583190438044942U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4454069062219406996U;
            aOrbiterI = RotL64((aOrbiterI * 16329554225309389599U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17177136683616247897U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3680497519697457252U;
            aOrbiterE = RotL64((aOrbiterE * 6479357366957384599U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16812938441063719463U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4545693142067578891U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 17479957806084346527U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9232311730019478327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11480359716598965890U;
            aOrbiterG = RotL64((aOrbiterG * 6678546065399772697U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 24U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 44U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19941U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17389U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20973U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 19721U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 38U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 57U)) + 14499676118633326000U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 41U)) + 17191273593018552288U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 29U)) + 4085176294948097737U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 23U)) + 11112671474158908186U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + 8745787969012266485U) + aNonceWordG;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 18074049663777707948U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + 2543758649719164688U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 4659584749412700523U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 3U)) + 974639159259871273U;
            aOrbiterE = (aWandererB + RotL64(aCross, 19U)) + 9211220687971081987U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 10U)) + 8567024626862182714U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5803002132294840900U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11968489432878148467U;
            aOrbiterF = RotL64((aOrbiterF * 4501441062617123165U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9470807228394903442U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1692347973120388469U;
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16510815732690193145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 755159406833096510U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 14091736464659561165U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1518824876475937620U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 701225390867330446U;
            aOrbiterD = RotL64((aOrbiterD * 12264618860580199927U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8425976693733003889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7182176375442410367U;
            aOrbiterH = RotL64((aOrbiterH * 8860605703761731859U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4546566785167467924U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2593340999038753749U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10152461487764567563U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9756331608356622299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5511625814747641978U;
            aOrbiterE = RotL64((aOrbiterE * 4806076157539829529U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8694400787420160733U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12648969491371382682U;
            aOrbiterC = RotL64((aOrbiterC * 5346585704222643759U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15261238546696118531U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14236129054778329471U;
            aOrbiterI = RotL64((aOrbiterI * 11789581469516267749U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16251500056378064213U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 790320176607605195U;
            aOrbiterB = RotL64((aOrbiterB * 15706130623435648555U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17114773669444878655U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14499676118633326000U;
            aOrbiterJ = RotL64((aOrbiterJ * 8095707555083587081U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 18U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 56U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23239U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24088U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24897U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25359U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 47U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 57U)) + 8793908991006073956U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 2932916283348441943U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 22U)) + 11069042087940968262U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 14369628676782894441U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 8602903272780978282U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 3827036107178568820U) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + 8905245209036772489U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 13331387530760017893U;
            aOrbiterK = (aWandererE + RotL64(aCross, 5U)) + 9880107580289737823U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 13U)) + 10199619040626900278U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 10U)) + 2466307560891374281U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13973403407981259448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2851460278409385243U;
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10365453393815690776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5058198848163792422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10500434740387593487U;
            aOrbiterJ = RotL64((aOrbiterJ * 5946747708776079787U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11289798395177667084U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14327152153231286666U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18155778059595245561U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8065137263811956313U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3865153574847924816U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18102279969722473375U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6306428427188742325U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17826782872351406167U), 23U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 16953348204663693724U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11950791817032898613U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1498946055469611133U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11980823193543752994U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17845490308799454871U;
            aOrbiterK = RotL64((aOrbiterK * 16385153013485463791U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5566398755702887071U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10308378271388889968U;
            aOrbiterD = RotL64((aOrbiterD * 142732084484961281U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6717846700455219260U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8297225372883997017U;
            aOrbiterE = RotL64((aOrbiterE * 14102812043481327907U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12249337046267666603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8793908991006073956U;
            aOrbiterG = RotL64((aOrbiterG * 5851229209188473467U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 52U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterG, 53U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 30U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aNonceWordI) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 26U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 60U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30311U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 29326U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31070U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31298U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 23U)) + 4751694786009671052U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 16362725160370844224U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 27U)) + 6360885380915941057U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 5154536007972297036U) + aNonceWordG;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + 9362540581874808253U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 11U)) + 13902493871525612934U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 10208452885367546542U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 27U)) + 3117030377279160998U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 19U)) + 17286247690414027870U) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aScatter, 13U)) + 3930314320040949141U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 7289525252391668404U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3434167955466809185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterG = RotL64((aOrbiterG * 1485660158767033425U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6137259687928853253U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13992510605237574698U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6470556523400123474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4333255670390099293U;
            aOrbiterC = RotL64((aOrbiterC * 11089933812030082647U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7700424876430257995U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16920736951239453071U;
            aOrbiterK = RotL64((aOrbiterK * 8920407493132380497U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1635071690430295730U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9966700845966398620U;
            aOrbiterA = RotL64((aOrbiterA * 17210048121896546867U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9833458070123027075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1990346556486746432U;
            aOrbiterE = RotL64((aOrbiterE * 8704943923474148699U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13339523466436517327U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5018264760406215603U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2769197961801783627U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 123427497520755346U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4535841104215792886U;
            aOrbiterF = RotL64((aOrbiterF * 1417676310539177131U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3525925567359163763U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3273741481392187986U;
            aOrbiterB = RotL64((aOrbiterB * 16116160744647235811U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6230742908784102407U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7578784912496239362U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2614448818452560369U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14669810330213234082U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4751694786009671052U;
            aOrbiterJ = RotL64((aOrbiterJ * 9583151676882991817U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 4U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 4U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 40U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 44U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
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

void TwistExpander_Boxing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDC05D349638DE07DULL + 0xE95CF35CA5C49B8CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8BF949CFFD584C47ULL + 0xBD4FBD2FDCADAE7DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDE3336EFE5837025ULL + 0x8305B1A918472E47ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBF55259F04AEBFEDULL + 0xAFBD326AAC6A536AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDD615C64B0791CFBULL + 0xFBFDCFF992A0B664ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFC6BB90586027275ULL + 0xC202301F5D7C65F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF855DAAB9A2016A1ULL + 0x9304BA5E94B9D220ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9437F2B95A3934DBULL + 0xFFEBD7E488379E9CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x85A117C9F2C3B059ULL + 0x952A44B224EADD23ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFFF2D72D2A46C21FULL + 0xA9D70C99C2876827ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC0241497506CBCCFULL + 0x87D390C4761F42C1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF2F5532C447498C9ULL + 0xD4ADDFDCB46FB311ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD732BE1D83F7216BULL + 0xE5228243D5E8067BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF1DE95FC03A28645ULL + 0x953410D9922664ADULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFBBB9E48D1982221ULL + 0xBB7CFC92D1B5A4F7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC5069C7125683991ULL + 0xA4E6B0EFFC275545ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3217U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 4136U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2859U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 3905U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 20U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 12U)) + 11700815697312060726U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 11808423452327465441U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 21U)) + 8670503858631730886U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 2400061067991988544U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 44U)) + 16163118178366229686U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 51U)) + 3280178595904941068U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 37U)) + 3298683600817047727U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 16321624053445183574U) + aNonceWordP;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 23U)) + 6730229877611375225U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 10162830636713641322U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 47U)) + 15646771327759599256U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14841751262270544102U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9545541117228834895U;
            aOrbiterF = RotL64((aOrbiterF * 11529769874752969377U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14676615635857599982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1231768638470558855U;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1945905595345404833U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1406171421638586846U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4577864352425476233U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1970292335806697198U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12309719390375013297U;
            aOrbiterC = RotL64((aOrbiterC * 16540660957923687327U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5352135521358954576U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15465675376193501658U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385761112921041387U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2842123638916600369U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3544764287036748668U;
            aOrbiterE = RotL64((aOrbiterE * 3360772950777850115U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6038297172906492282U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10249342332287140970U;
            aOrbiterD = RotL64((aOrbiterD * 16701083081566042277U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1662076777040529446U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1949705569959740274U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 11340691546658994529U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13934194245417822360U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5720408806425535958U;
            aOrbiterK = RotL64((aOrbiterK * 15237561081637415383U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2209251362417210658U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4917447930929521699U;
            aOrbiterH = RotL64((aOrbiterH * 17489570156694692569U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14817115766683623486U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11700815697312060726U;
            aOrbiterG = RotL64((aOrbiterG * 16982411053956669181U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 24U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 58U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9420U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8677U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6289U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 10338U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 40U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 43U)) + 4752759164691497960U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 12088872623537639782U;
            aOrbiterD = (aWandererG + RotL64(aCross, 39U)) + 3734943577379734227U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 4U)) + 8854778183012444234U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 11U)) + 16948373492893967275U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 7962415690046184385U) + aNonceWordG;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 1872682375669714454U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 28U)) + 7776801806943853566U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 57U)) + 16665439117257230732U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 53U)) + 11088186766134265676U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 35U)) + 10850237991780969350U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6464817712131305812U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13261563971157415841U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2323811103717827362U;
            aOrbiterJ = RotL64((aOrbiterJ * 11483723582415081925U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12338803568475493422U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2811342930111104982U;
            aOrbiterF = RotL64((aOrbiterF * 5020981755203607757U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5554497011738996057U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12712169745460598698U;
            aOrbiterK = RotL64((aOrbiterK * 1985586486150377769U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17415058661427002973U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9430421222715343818U;
            aOrbiterC = RotL64((aOrbiterC * 10321140659099470811U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3926618548181233180U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6172453297026957838U;
            aOrbiterH = RotL64((aOrbiterH * 1161551082037835233U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8633288765997226004U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17270881130844274342U;
            aOrbiterA = RotL64((aOrbiterA * 8888559940161770791U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12232950994807835262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15352600312956742750U;
            aOrbiterB = RotL64((aOrbiterB * 6140396356904933003U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5614120002595447983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1920822446545182835U;
            aOrbiterE = RotL64((aOrbiterE * 17049182594382482085U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 625576652179261739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2362773059031414585U;
            aOrbiterG = RotL64((aOrbiterG * 17049048587829564949U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16749690978107177915U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4752759164691497960U;
            aOrbiterI = RotL64((aOrbiterI * 8442185754037031199U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 40U));
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 46U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14906U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11829U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15435U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 15152U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 51U)) + 12262991801139086177U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 3U)) + 7963038771924890197U) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 15540520327933568896U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 47U)) + 8745565892055020722U;
            aOrbiterD = ((((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 16619329199683755286U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 58U)) + 10865705026433867260U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aScatter, 29U)) + 2743368697984518059U;
            aOrbiterC = (aWandererA + RotL64(aCross, 51U)) + 5556006271515473135U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 5355833281353498588U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 8313616108963479829U;
            aOrbiterE = (aWandererF + RotL64(aCross, 21U)) + 16657121016801866434U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16532226425013000833U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5800465874932467232U;
            aOrbiterH = RotL64((aOrbiterH * 5966395771690704577U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17882948163883121328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15029375310296563175U;
            aOrbiterB = RotL64((aOrbiterB * 17021415832288477713U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10170682648007918739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11829089574189398773U;
            aOrbiterK = RotL64((aOrbiterK * 15755874363488568849U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1746524867389196322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10217423427886742775U;
            aOrbiterD = RotL64((aOrbiterD * 9166162099575333519U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1338457710729082656U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1319981417675542556U;
            aOrbiterC = RotL64((aOrbiterC * 9518448254565489715U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3985281993069194761U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7281264481139915593U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13498446162967276739U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17394503335338855566U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1430703546991948227U;
            aOrbiterG = RotL64((aOrbiterG * 1623206122475721175U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 472559435062214929U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8065899137826178995U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 13287499768933229539U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3377996409668333322U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 10456089146891981998U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 12037044781049717633U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5246784368779537905U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8518987022368391332U;
            aOrbiterF = RotL64((aOrbiterF * 4046763804695058779U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7791883487780325967U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12262991801139086177U;
            aOrbiterE = RotL64((aOrbiterE * 3409890579914160747U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 6U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + aNonceWordL) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 14U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18395U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19156U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21660U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((aIndex + 19131U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 29U)) + 11410829607777684449U;
            aOrbiterF = (aWandererK + RotL64(aCross, 26U)) + 7502698839700975347U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 13267685058252106173U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 238242706996630625U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 21U)) + 8184695499511454281U) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aScatter, 53U)) + 12767823220461985403U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 41U)) + 12293198423143850330U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 11149495229952495939U) + aNonceWordH;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 7556992689338382800U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 3431338808774134649U) + aNonceWordK;
            aOrbiterH = (aWandererD + RotL64(aScatter, 56U)) + 16863099140844995099U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17872458049880677604U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16760153457252546974U;
            aOrbiterJ = RotL64((aOrbiterJ * 11225037229069712805U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3115544493537438408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4359882942759752958U;
            aOrbiterK = RotL64((aOrbiterK * 561477566995575801U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13387113067202396536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12955690074544490161U;
            aOrbiterI = RotL64((aOrbiterI * 12449941770827974511U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15614054443728226807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1939441328066616114U;
            aOrbiterE = RotL64((aOrbiterE * 4484917074808974359U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4599016263007782537U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9962305629016158048U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1496184427500037279U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8428467674122750557U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3938884087806393439U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12810531094050481761U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6018636830758044658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1510372000641305416U;
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17592782466215337843U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8119921507606870360U;
            aOrbiterH = RotL64((aOrbiterH * 1299795061644535485U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8753237702359236964U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12389957327067768090U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4586786761936601607U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17791633199762408683U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11606494383812053915U;
            aOrbiterF = RotL64((aOrbiterF * 13041480602055778521U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4418614662439151979U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11410829607777684449U;
            aOrbiterA = RotL64((aOrbiterA * 3342270212301058781U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 50U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 10U));
            aWandererC = aWandererC + ((RotL64(aCross, 38U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25662U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24105U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26767U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 22339U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 47U)) + 13278949403988203974U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 9213599924054673756U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 1255746482932381798U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 43U)) + 11575321997144516122U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 13U)) + 15881587525529432437U;
            aOrbiterK = (aWandererD + RotL64(aCross, 11U)) + 9846195809864862707U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 6U)) + 12319815691858217670U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 16322617427294439587U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 23U)) + 16332130810525887437U) + aNonceWordM;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 3U)) + 4920951156015336794U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 18U)) + 16767126455124552329U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12553595911087945223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1437522202135436142U;
            aOrbiterE = RotL64((aOrbiterE * 2001992794165550905U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12313100454852227143U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2761983020631055729U;
            aOrbiterK = RotL64((aOrbiterK * 3874839760378039509U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17635303588421554367U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 788212489507463763U;
            aOrbiterD = RotL64((aOrbiterD * 17896475584538528059U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5192552894670654434U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6784748488807738811U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 8077237651953896479U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16113417046719114943U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1096874945215225916U;
            aOrbiterG = RotL64((aOrbiterG * 17308604412622879833U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7610274704570171595U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10466070212284342550U;
            aOrbiterJ = RotL64((aOrbiterJ * 6449728258497920613U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6777845928873855221U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5251515022021984126U;
            aOrbiterH = RotL64((aOrbiterH * 9018277343404261611U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13849343158824111498U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7977711210181714021U;
            aOrbiterC = RotL64((aOrbiterC * 4182053966171053577U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 6494539818728106982U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11314590450226080781U;
            aOrbiterI = RotL64((aOrbiterI * 12455979257225599157U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 552687702594328012U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14961304171192292246U;
            aOrbiterF = RotL64((aOrbiterF * 846375892915484717U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 9771874402848476494U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13278949403988203974U;
            aOrbiterA = RotL64((aOrbiterA * 2119203863777871233U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 40U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 26U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 50U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28327U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 29375U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32061U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 31871U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 40U)) + RotL64(aCarry, 19U)) + 17711946802293254150U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 11U)) + 16652362590489569378U) + aNonceWordL;
            aOrbiterF = ((aWandererB + RotL64(aCross, 5U)) + 6972810344198183097U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 13117100889782940546U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 35U)) + 13199305696782626591U;
            aOrbiterG = (aWandererA + RotL64(aCross, 58U)) + 992156184392760945U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 47U)) + 13791265442074543880U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aIngress, 13U)) + 17057087245252294859U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 27U)) + 13444195995883541046U) + aNonceWordA;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 6723678233676059420U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 7913379431208430475U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4481887195529300665U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11892724101424384078U;
            aOrbiterF = RotL64((aOrbiterF * 3468639499716604111U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7700902083270424194U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1888001433557140271U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8975562955027025349U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14996753906788986929U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 939004845422123765U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2507090308972292313U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11922230289291941807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15681187459741147199U;
            aOrbiterJ = RotL64((aOrbiterJ * 10124947739653819101U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9119043713532718155U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8327697433992362166U;
            aOrbiterH = RotL64((aOrbiterH * 11157657162184304567U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13630755116592440359U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 771252613886022889U;
            aOrbiterB = RotL64((aOrbiterB * 2958918915223536519U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8524239721467527770U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17732617735422435572U;
            aOrbiterA = RotL64((aOrbiterA * 13992947983987668631U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5265753270696005619U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14456128349522985053U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5406509991740849617U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12909993509014176457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10113568710432654194U;
            aOrbiterI = RotL64((aOrbiterI * 6857806395910432831U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14818978163348513071U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17843349910031998923U;
            aOrbiterC = RotL64((aOrbiterC * 13608449524810499593U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12589077818524017161U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17711946802293254150U;
            aOrbiterD = RotL64((aOrbiterD * 9454569713107675231U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 36U) + aOrbiterF) + RotL64(aOrbiterD, 30U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 38U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA6254BA3975AC3DULL + 0xB16409DDCAC8D687ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFAE844DC621DB927ULL + 0xE9340353E3689C6EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA751B85B6CF2F397ULL + 0xEAA8D887504FD5ADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFF0F75A6DB512AD5ULL + 0xE572C012D8F0713DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE6AB71567BD26B69ULL + 0xBE3C8608A80812EFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBC51F8AFB5B59407ULL + 0xB2ABB063078751ECULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x94FECA9F9CA56493ULL + 0x9DDD1D6AD06A09BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA3DDAA568B4BF319ULL + 0xAB9249273F601FA7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD6D131E08D790A71ULL + 0xC7A3FB58A759F1CBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFCEEE6045A1E3D6BULL + 0x8CAF2246641ABE49ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE75048E9ECE4FA25ULL + 0xF2675034BA0358D2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDFB51531A87578DFULL + 0xDA8E9DB17C299F65ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE9CA6A2C250F0B27ULL + 0xF758CA27401155D1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9602A8507AE3718DULL + 0xB52B82FA96E2F059ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x86FC186BAA11B163ULL + 0xF09C7FF46C99081BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9CECF3E656CE8341ULL + 0xB311AB399CABAF1AULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4867U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3174U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3515U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 1186U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 23U)) + 3199575576585871314U) + aNonceWordF;
            aOrbiterF = (aWandererA + RotL64(aCross, 56U)) + 2533378188975571824U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 6819782112558312658U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 11U)) + 12690060987724798497U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 3U)) + 7088375139715629606U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 13U)) + 17785618677423695666U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 38U)) + RotL64(aCarry, 11U)) + 1714999280296491277U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 17611338506932491624U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 21U)) + 6475727359297421201U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 43U)) + 2347744591204119530U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 19U)) + 2739317903351401068U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8663535261373274338U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8205245127823536479U;
            aOrbiterG = RotL64((aOrbiterG * 13857005110466856439U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8916510616749754516U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3944805940148512932U;
            aOrbiterD = RotL64((aOrbiterD * 18082271583211389701U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14094751253118853302U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14094299829196076311U;
            aOrbiterC = RotL64((aOrbiterC * 6370012560657108493U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3940673811518673802U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3015106523254484839U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9655401190755573379U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15404103131982599922U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1828655763233900875U;
            aOrbiterE = RotL64((aOrbiterE * 13024358077740310049U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1236981890899916502U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 18208975564570342697U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4577109989465876801U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17882273895471449661U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16196010765612713713U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 15624856645134182005U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14639250100311162559U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9139027997336903273U;
            aOrbiterF = RotL64((aOrbiterF * 1853126389565574293U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16848571995585465845U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 15901000078517800358U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 11617866400577762383U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9405166641274108606U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6776079798531281127U;
            aOrbiterA = RotL64((aOrbiterA * 6914644957401512339U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15056085197286596847U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3199575576585871314U;
            aOrbiterK = RotL64((aOrbiterK * 15940936753708416817U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 48U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 41U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8167U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10377U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10407U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 9376U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 34U)) + 8793908991006073956U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 2932916283348441943U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 11069042087940968262U;
            aOrbiterH = (aWandererG + RotL64(aCross, 23U)) + 14369628676782894441U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 56U)) + 8602903272780978282U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 3827036107178568820U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 39U)) + 8905245209036772489U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 27U)) + 13331387530760017893U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererI + RotL64(aCross, 11U)) + 9880107580289737823U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 10199619040626900278U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 2466307560891374281U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13973403407981259448U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2851460278409385243U;
            aOrbiterJ = RotL64((aOrbiterJ * 11226902976321781743U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10365453393815690776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5058198848163792422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10500434740387593487U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5946747708776079787U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11289798395177667084U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14327152153231286666U;
            aOrbiterC = RotL64((aOrbiterC * 18155778059595245561U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8065137263811956313U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3865153574847924816U;
            aOrbiterE = RotL64((aOrbiterE * 9495741102667755161U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18102279969722473375U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6306428427188742325U;
            aOrbiterD = RotL64((aOrbiterD * 17826782872351406167U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16953348204663693724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11950791817032898613U;
            aOrbiterH = RotL64((aOrbiterH * 1498946055469611133U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11980823193543752994U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17845490308799454871U;
            aOrbiterA = RotL64((aOrbiterA * 16385153013485463791U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5566398755702887071U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10308378271388889968U;
            aOrbiterK = RotL64((aOrbiterK * 142732084484961281U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6717846700455219260U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8297225372883997017U;
            aOrbiterG = RotL64((aOrbiterG * 14102812043481327907U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12249337046267666603U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 8793908991006073956U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 5851229209188473467U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 6U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 24U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 46U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15621U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 12338U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13313U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 14931U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 35U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aIngress, 11U)) + 17912271996338180948U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 53U)) + 13259276608841847058U;
            aOrbiterC = (aWandererH + RotL64(aCross, 37U)) + 16225936008657276089U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 13U)) + 2243058962151834071U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 29U)) + 10637439274127347861U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 15312219216405992627U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 13U)) + 2393933972129878613U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 43U)) + 4327069337247976513U) + aNonceWordN;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 8307656353434167837U;
            aOrbiterE = (aWandererF + RotL64(aCross, 40U)) + 17299145556933889336U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 19U)) + 14458100581172798164U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6410095654927998067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6168964796264687686U;
            aOrbiterC = RotL64((aOrbiterC * 16218071040190475953U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3667999465041020730U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16021552859323602007U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6427266472526362663U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12941668202330045095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4222032891850449934U;
            aOrbiterG = RotL64((aOrbiterG * 17292856787431308097U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1346342592002730785U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 16860611785008118820U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 384963420804756607U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3193572711804730241U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5866881282680588589U;
            aOrbiterK = RotL64((aOrbiterK * 9226331800853634597U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17180332731328479126U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10222097519535882241U;
            aOrbiterE = RotL64((aOrbiterE * 9422887302872778795U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8863502179821584859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14872318155712512999U;
            aOrbiterB = RotL64((aOrbiterB * 11830641277356873233U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16478790641892781150U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8414944141232294781U;
            aOrbiterF = RotL64((aOrbiterF * 17443775794621154023U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13204056527590476037U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15084952142545813228U;
            aOrbiterI = RotL64((aOrbiterI * 17183888602469193015U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13051035678904490854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17565188004293304987U;
            aOrbiterJ = RotL64((aOrbiterJ * 12785271107667631897U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 814245676602237400U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17912271996338180948U;
            aOrbiterD = RotL64((aOrbiterD * 14557769257469623169U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 20U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 24U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererG, 48U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16905U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19650U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17446U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21096U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 29U)) + 3236820517816085022U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 37U)) + 741288875914097926U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 51U)) + 8417246926007729580U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + 9715717805774537170U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 41U)) + 14360243844821619482U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 47U)) + 10760908100206775334U) + aNonceWordP;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 3434641779946167811U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 7885568822756234567U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 43U)) + 3041563437672051294U) + aNonceWordM;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 15761355327564963516U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 6U)) + 1158633562785937421U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9338581575871970653U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterK = RotL64((aOrbiterK * 3110871165285625807U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14653924713599790081U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3854497592598563309U;
            aOrbiterJ = RotL64((aOrbiterJ * 11737111068815795303U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16286980180327600557U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5092583772591249756U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13955105624639442903U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4288397994175567333U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15584236478994873104U;
            aOrbiterI = RotL64((aOrbiterI * 1860480595862755379U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5557463939827483792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2659814275753280856U;
            aOrbiterH = RotL64((aOrbiterH * 17702430405693184643U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6941807963525063449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2040598555191211307U;
            aOrbiterD = RotL64((aOrbiterD * 14750544987531722765U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 347572666231116258U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 779304821185302523U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14180254150318109855U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10632524582873079742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9761308771280517212U;
            aOrbiterA = RotL64((aOrbiterA * 13926235411726048921U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2097439707055737964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2813977930321463948U;
            aOrbiterB = RotL64((aOrbiterB * 14983538728730662603U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6080592019313796689U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5396623654821376409U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15478858835919398677U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8460497459575045342U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3236820517816085022U;
            aOrbiterF = RotL64((aOrbiterF * 5530411244458067093U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB + (((RotL64(aCross, 36U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 50U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 53U)) + aOrbiterI) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererD, 4U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25318U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27218U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25681U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 25268U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 37U)) + 13880995121909552664U) + aNonceWordE;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 14534942818069300546U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 17745973100886007133U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 5U)) + 2249805580771946872U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 41U)) + 4460116116396439410U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 47U)) + 3378683994078106878U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 27U)) + 3992996501048809123U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 39U)) + 12057768808864451929U) + aNonceWordC;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 4115362079047921130U) + aNonceWordK;
            aOrbiterF = ((aWandererE + RotL64(aCross, 30U)) + 15297384955502206698U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 19U)) + 17623548383481905636U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3559213898000162417U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12311605719074507335U;
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14807313864347885885U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11222085523291581822U;
            aOrbiterG = RotL64((aOrbiterG * 12580941911587215653U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 916681229436292462U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2441350114032314686U;
            aOrbiterA = RotL64((aOrbiterA * 7336079498999018067U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7361470539894653271U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12153585147213579808U;
            aOrbiterF = RotL64((aOrbiterF * 3040327545467672961U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13566300726101613579U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14875254144748509128U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13699179902908972403U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9268158535644002904U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14144295981814993491U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 12739937231684038161U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13861225650900541642U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12620513474052058164U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18141974182442267181U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14163773386433257965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5725700029399455855U;
            aOrbiterB = RotL64((aOrbiterB * 10446930901088908809U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16644838246877860102U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6611825438224873117U;
            aOrbiterI = RotL64((aOrbiterI * 5336239588054125897U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9408958265247071226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16980073477599191801U;
            aOrbiterE = RotL64((aOrbiterE * 7985839560318985205U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6513029242607881518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13880995121909552664U;
            aOrbiterH = RotL64((aOrbiterH * 17463079726765044639U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 40U)) + aOrbiterK) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + aNonceWordD) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterF, 52U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 44U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31844U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31287U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28841U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 28310U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 1364174714924216027U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 24U)) + 13561796874229506613U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 11845572344206238305U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 37U)) + 15762708240326773763U;
            aOrbiterA = (aWandererE + RotL64(aCross, 5U)) + 1157119665207900473U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 53U)) + 6823546624372055260U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 14465564210523945121U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 28U)) + 10667464548080807531U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 21U)) + 13445737493224316575U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 3U)) + 3009837893785957665U;
            aOrbiterE = ((((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 2886920524111083752U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10886177449328249656U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15067759884678100433U;
            aOrbiterK = RotL64((aOrbiterK * 5724566815989860041U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 18307930462682331536U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterA = RotL64((aOrbiterA * 9265158882471421767U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 805797468642992351U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5743305867058244964U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 16263000753351131717U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17102025528234481273U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1841579177327486899U;
            aOrbiterI = RotL64((aOrbiterI * 3841603385577825265U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2189493507896508972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18209567010094914374U;
            aOrbiterF = RotL64((aOrbiterF * 3737080408976852351U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6697069234216868330U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 927471474577415372U;
            aOrbiterB = RotL64((aOrbiterB * 10680760991009199309U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13155854301197725408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1014625081915435892U;
            aOrbiterC = RotL64((aOrbiterC * 11592754232949990435U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12697209921410914931U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11555096613655648647U;
            aOrbiterE = RotL64((aOrbiterE * 4598821388864997089U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9335308231651271690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3160859883353473444U;
            aOrbiterH = RotL64((aOrbiterH * 4753600703924906409U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15681189182414315768U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3147692210581710663U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6271949093080510861U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5373388632562432117U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1364174714924216027U;
            aOrbiterG = RotL64((aOrbiterG * 4694926665965807945U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 30U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aPhaseFWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 38U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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

void TwistExpander_Boxing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8515DBFC16F89301ULL + 0xFF6B25A3A44398D6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD659795977E144E3ULL + 0xFDCA7096A0DF5864ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE36D960BCC47939DULL + 0x9EE2DF247D5BD4C3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC419FE4EA1C35DCFULL + 0xA78ED3FD30A05A0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xECB57112601CC3BFULL + 0xC81953B48699528CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCB10008C33D77631ULL + 0x9F83BEF908A40B43ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCD61D33909B4100DULL + 0x9DA01C9B70A84745ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF93C60F75EFD8859ULL + 0xCE8E5ECB09604ABFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA3E027F0B153E61FULL + 0xABB3D52C651250E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCA9BD545F6AB1F59ULL + 0xBE757B60755F36E6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x96BF5EE83987C9D1ULL + 0x8AA5FE6DE59C7139ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF8AB6C0B999C1313ULL + 0xBFF6684EAF635BBCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDB07FBDB7A453A19ULL + 0xE38DCEF282FE11BBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC6352681647848B9ULL + 0xA89B0BB73BF1E757ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCF459C059BB96F9BULL + 0xC256B3E40D9CA0CDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDF23A93E7220BA2DULL + 0xEEABCDEDDFEAF0DDULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5410U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2296U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 307U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1773U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 56U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 27U)) + 14686411261024919129U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 23U)) + 7514582233957632005U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 53U)) + 6520710480103365552U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 40U)) + 1983621978676188036U) + aNonceWordO;
            aOrbiterI = (aWandererC + RotL64(aCross, 29U)) + 9003524602590749672U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 11U)) + 6428568234045228995U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 8656552687136446989U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 13U)) + 16916248288415922490U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 43U)) + 9740237548002535784U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 907561000814618339U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 4751108900841197631U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 167774899400732287U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11907484918310854962U;
            aOrbiterA = RotL64((aOrbiterA * 7213139491146402985U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14910318613649863924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14882888155751455276U;
            aOrbiterC = RotL64((aOrbiterC * 11394136445442060201U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16175942562693781908U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11022373758481651102U;
            aOrbiterD = RotL64((aOrbiterD * 6836331461393816027U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12548405399045031548U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10850926364556828443U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16231561687709867431U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13391684887911141790U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14648937281264822988U;
            aOrbiterK = RotL64((aOrbiterK * 6533299316940026059U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8298658887198526821U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13822977698661348891U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 17769262972278410937U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7505646847564645719U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3238749538197209166U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15394286542600778567U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15853506915123709257U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 8426329899401071248U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 1330397096577715113U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14848635392815613098U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3549927798350175044U;
            aOrbiterI = RotL64((aOrbiterI * 1899044682313056949U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1798973117197750802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13056711228618953977U;
            aOrbiterE = RotL64((aOrbiterE * 9102877396419306689U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1395893547965799281U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14686411261024919129U;
            aOrbiterB = RotL64((aOrbiterB * 17075377081365066067U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 28U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10305U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5984U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7213U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7244U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aScatter, 27U)) + 15910560457440369082U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 5U)) + 17953072986407436888U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 19U)) + 15446940721193538669U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aCross, 35U)) + 3020785262774422009U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 10U)) + 7001288645424994404U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 21U)) + 13385250665458462689U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 37U)) + 4841895644623005949U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 41U)) + 13053476783239482065U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 50U)) + RotL64(aCarry, 57U)) + 641996979335975244U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 16211238020928688299U) + aNonceWordM;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 12715448751323279480U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9035070625716345139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1177103851507561053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9040984343694325070U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13334258224023902365U;
            aOrbiterH = RotL64((aOrbiterH * 4782523727707164869U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1079824790138592518U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14024082692012948652U;
            aOrbiterK = RotL64((aOrbiterK * 3219489374333737903U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2966776524421278970U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5510281854029308547U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 9275402927591867297U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7126632329316720048U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterD = RotL64((aOrbiterD * 2217671289726794033U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6470212302133184965U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4172257438373147415U;
            aOrbiterJ = RotL64((aOrbiterJ * 4449314239630366533U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11445212164224402184U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1779825157413363285U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15393425495668107155U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7561888690947559866U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14440989817038856852U;
            aOrbiterE = RotL64((aOrbiterE * 5799807036762859679U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10618807050937260814U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15910560457440369082U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10902491688248464465U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 34U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 36U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13531U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15568U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13804U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15635U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 50U)) + RotL64(aCarry, 13U)) + 14008824488073394623U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 13U)) + 13317978415866411468U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 11U)) + 13209180141897453900U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 11870521586865233578U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + 8052156380448047385U) + aNonceWordI;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 12158131176743680605U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 3U)) + 14674467487607719347U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 27U)) + 18055496790566231147U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 30U)) + 3838105585041578784U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 23U)) + 2839568255183054418U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 11933612922864258179U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6289849094151630580U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2640344350528492271U;
            aOrbiterA = RotL64((aOrbiterA * 16197726750829369365U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16306175266267657791U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3339898380394883600U;
            aOrbiterK = RotL64((aOrbiterK * 7105436590182982373U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15017076663742800002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8973064296077602496U;
            aOrbiterH = RotL64((aOrbiterH * 9309462227233615761U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17580319233338139859U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14063208878807603874U;
            aOrbiterB = RotL64((aOrbiterB * 16601475239075164585U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13326130855721009942U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12843186026737544416U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4975848122837321619U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14102887715772847499U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14495942314329085733U;
            aOrbiterJ = RotL64((aOrbiterJ * 4236795312917583565U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11564857125101669667U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17435970784822000464U;
            aOrbiterE = RotL64((aOrbiterE * 1472691848852381173U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16561390130356833062U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9952805588514363872U;
            aOrbiterC = RotL64((aOrbiterC * 3720874990001086597U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8246822023509690545U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 305480212301772662U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 4295787267516476485U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11729872285756639125U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9669174142543613799U;
            aOrbiterG = RotL64((aOrbiterG * 9443240779947114779U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7653344907616923293U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14008824488073394623U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 8362849599309360823U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 56U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 20U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG + (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 6U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20030U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 17263U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19017U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 21437U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 48U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 13U)) + 4259993311776766595U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 2857813330021126753U) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aCross, 51U)) + 1345396841329442896U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 320992148982301024U) + aNonceWordH;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 57U)) + 5619109532065293074U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 43U)) + 10380157329426706345U) + aNonceWordL;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 18U)) + 12449831150625409695U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 35U)) + 7847096607042268396U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 3U)) + 11707184096803214678U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 29U)) + 9893643746186827088U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 46U)) + RotL64(aCarry, 27U)) + 333687403830908774U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13837360705077441580U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4367119682175710689U;
            aOrbiterF = RotL64((aOrbiterF * 10295744669174603401U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1193493435041306784U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15062951612027370606U;
            aOrbiterJ = RotL64((aOrbiterJ * 2509383510565136549U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16000173839235429105U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15294482444605409961U;
            aOrbiterE = RotL64((aOrbiterE * 1031800997944302665U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5720749055549773527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17248674962996093668U;
            aOrbiterI = RotL64((aOrbiterI * 15730637462755795591U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16956840483882091059U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9637715107943515594U;
            aOrbiterH = RotL64((aOrbiterH * 8878362378343603463U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7147495779349862274U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7508890985889484275U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17728368447504622035U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4407738164617959366U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17027017782352660454U;
            aOrbiterB = RotL64((aOrbiterB * 417183060881259295U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3174658601748235285U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9779053567370714831U;
            aOrbiterA = RotL64((aOrbiterA * 6383245776181968033U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16256981360027888091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12778335633397105924U;
            aOrbiterG = RotL64((aOrbiterG * 10821225965811763659U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13985909343937844583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14307218309393008729U;
            aOrbiterD = RotL64((aOrbiterD * 12053366452617039877U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15549857305890093491U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4259993311776766595U;
            aOrbiterK = RotL64((aOrbiterK * 13703695714360435719U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 53U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23912U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 24703U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22052U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 23158U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 11U)) + 3199575576585871314U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 2533378188975571824U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 6819782112558312658U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 20U)) + 12690060987724798497U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 47U)) + 7088375139715629606U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 17785618677423695666U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 53U)) + 1714999280296491277U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 17611338506932491624U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 43U)) + 6475727359297421201U) + aNonceWordL;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 51U)) + 2347744591204119530U) + aNonceWordM;
            aOrbiterD = (aWandererC + RotL64(aCross, 60U)) + 2739317903351401068U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8663535261373274338U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8205245127823536479U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13857005110466856439U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8916510616749754516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3944805940148512932U;
            aOrbiterH = RotL64((aOrbiterH * 18082271583211389701U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14094751253118853302U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14094299829196076311U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 6370012560657108493U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3940673811518673802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3015106523254484839U;
            aOrbiterE = RotL64((aOrbiterE * 9655401190755573379U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15404103131982599922U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1828655763233900875U;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1236981890899916502U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18208975564570342697U;
            aOrbiterI = RotL64((aOrbiterI * 4577109989465876801U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17882273895471449661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16196010765612713713U;
            aOrbiterG = RotL64((aOrbiterG * 15624856645134182005U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14639250100311162559U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9139027997336903273U;
            aOrbiterA = RotL64((aOrbiterA * 1853126389565574293U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16848571995585465845U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15901000078517800358U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 11617866400577762383U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9405166641274108606U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6776079798531281127U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6914644957401512339U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15056085197286596847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3199575576585871314U;
            aOrbiterC = RotL64((aOrbiterC * 15940936753708416817U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterA, 52U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 39U)) + aOrbiterI) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 57U)) + aNonceWordE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 14U));
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28712U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30671U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29990U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30180U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 18180797995100240808U) + aNonceWordE;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 51U)) + 6585906608223552885U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 3U)) + 14088708930575939855U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 11U)) + 468974153311516044U) + aNonceWordB;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 53U)) + 12481951025619894110U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 35U)) + 17227987923860711763U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 19U)) + 4373962756657477139U;
            aOrbiterG = (aWandererA + RotL64(aCross, 37U)) + 2077576476565420951U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 58U)) + 17435011300234663764U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 21U)) + 4118039398293246896U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 13724716599855216683U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12391461204689596339U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9900605191533799627U;
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 972946858824366125U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17247681919694541215U;
            aOrbiterD = RotL64((aOrbiterD * 2974639094630445643U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15442851427306771601U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7303586227288294037U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 15406402525021428799U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12650358753454105119U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1483710933373510492U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6531763256577221891U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18065810162229740788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11311677121338794007U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15116367961682119467U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2355285311890287611U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1287783821903407734U;
            aOrbiterK = RotL64((aOrbiterK * 8054011680932255985U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9282654686791135654U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15488608017745542551U;
            aOrbiterA = RotL64((aOrbiterA * 7858866274035085123U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13296835576073421802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7127700236018338741U;
            aOrbiterI = RotL64((aOrbiterI * 11246173563106014149U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1365928843264598789U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7777790578813003657U;
            aOrbiterH = RotL64((aOrbiterH * 10121688100505628161U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2104270617375082523U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13363764449819651164U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 2685452132715528975U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2008038686059197988U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18180797995100240808U;
            aOrbiterJ = RotL64((aOrbiterJ * 8978998151475372047U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 56U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterC, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3422U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 1785U)) & W_KEY1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1964U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6230U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 27U)) + 11410829607777684449U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 7502698839700975347U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 19U)) + 13267685058252106173U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 238242706996630625U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 8184695499511454281U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 53U)) + 12767823220461985403U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 5U)) + 12293198423143850330U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 57U)) + 11149495229952495939U;
            aOrbiterH = (aWandererA + RotL64(aCross, 48U)) + 7556992689338382800U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3431338808774134649U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16863099140844995099U;
            aOrbiterA = RotL64((aOrbiterA * 752376661101787919U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17872458049880677604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16760153457252546974U;
            aOrbiterI = RotL64((aOrbiterI * 11225037229069712805U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3115544493537438408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4359882942759752958U;
            aOrbiterD = RotL64((aOrbiterD * 561477566995575801U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13387113067202396536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12955690074544490161U;
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15614054443728226807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1939441328066616114U;
            aOrbiterJ = RotL64((aOrbiterJ * 4484917074808974359U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4599016263007782537U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9962305629016158048U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1496184427500037279U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8428467674122750557U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3938884087806393439U;
            aOrbiterF = RotL64((aOrbiterF * 12810531094050481761U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6018636830758044658U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1510372000641305416U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17592782466215337843U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8119921507606870360U;
            aOrbiterK = RotL64((aOrbiterK * 1299795061644535485U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 38U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 28U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aPhaseCWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11345U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 8599U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8471U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 16069U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 9080426856729228705U;
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 7851218321653539276U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 3U)) + 7023344692919298036U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 60U)) + 9772846154227440734U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 39U)) + 12008298632429608431U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 12201090455849562875U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 9498721803411445471U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 14U)) + 351203764023093632U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 53U)) + 4966360430644539250U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9194167899071345693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4922477697284269116U;
            aOrbiterK = RotL64((aOrbiterK * 8444814161720407881U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15742625291642356429U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7528703106518431730U;
            aOrbiterJ = RotL64((aOrbiterJ * 11530049278751507567U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15279053574704935317U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2425839793660355555U;
            aOrbiterC = RotL64((aOrbiterC * 11486964816849830667U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13209849392400008898U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9041500097716231309U;
            aOrbiterG = RotL64((aOrbiterG * 340661035700748739U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7885423750878814599U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1992993999902904603U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1478629826632201617U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6120758615019314102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8529621625846992066U;
            aOrbiterD = RotL64((aOrbiterD * 8485991471612862467U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9125182130757385320U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15691232622970220043U;
            aOrbiterA = RotL64((aOrbiterA * 16517916951054758147U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11413090085435424697U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11563151001080914939U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16828196274450408201U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1778975369262558069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3232132443557192010U;
            aOrbiterB = RotL64((aOrbiterB * 17132823737792200981U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 44U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 56U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16751U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 17182U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 23534U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 17450U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 23U)) + 15652862298542575895U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 16925323928418184554U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 10U)) + 4413861484961668394U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 35U)) + 2215946422098155969U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 29U)) + 14975185533513111110U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 5U)) + 9711613814905834552U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 13154957291850149471U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 5058313016418534840U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 23U)) + 15011423472941211620U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2030053257469580168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 150530795186791193U;
            aOrbiterH = RotL64((aOrbiterH * 11106050063717096073U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10878237472104183427U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11724672539469573109U;
            aOrbiterD = RotL64((aOrbiterD * 16158741837357985395U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9589700906445846956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1367381624958248949U;
            aOrbiterE = RotL64((aOrbiterE * 8459515089081211977U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12003215666757518106U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11232479330848006729U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10993290955464593033U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13013910456628561621U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6092509838924105265U;
            aOrbiterF = RotL64((aOrbiterF * 805601154718006061U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11999225836250312801U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14421271973875748413U;
            aOrbiterG = RotL64((aOrbiterG * 9529010940887430157U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15536288285741825272U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2071793889925436679U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1526376970151714589U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5622386476463436967U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16147972771639168516U;
            aOrbiterI = RotL64((aOrbiterI * 11826916832825159095U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4519892856053952290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12059500374938843538U;
            aOrbiterB = RotL64((aOrbiterB * 14987533625537956299U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 56U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29817U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29459U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29002U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27504U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 14179205183062705133U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 54U)) + RotL64(aCarry, 53U)) + 210032324058740920U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 13U)) + 7387115089142500152U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 43U)) + 17583362781238061430U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 27U)) + 4991442849150005943U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 19U)) + 2891376254689854555U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 10523274382407446239U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 34U)) + 3861893764676218667U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 5U)) + 3366674459852093746U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5898492634386601145U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7047353571244768721U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2257518291062508467U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14374108805453186316U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8763667021501226510U;
            aOrbiterH = RotL64((aOrbiterH * 7694695426430267863U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18261523829316379575U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 650477532238860965U;
            aOrbiterF = RotL64((aOrbiterF * 8291758490821819851U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2162326554604894042U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5776546692501825278U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14911545784585246537U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3501863793638415049U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14853789267425352958U;
            aOrbiterE = RotL64((aOrbiterE * 10590325397179928739U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15399673014671329743U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12253428583438990426U;
            aOrbiterB = RotL64((aOrbiterB * 12052855472196447849U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13202953937621953839U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7547616636832698398U;
            aOrbiterJ = RotL64((aOrbiterJ * 9533399972562428073U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15709801946594868318U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12458677982746610971U;
            aOrbiterD = RotL64((aOrbiterD * 6662570874316418993U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6957370791367530127U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10511379961344950861U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15551333099264031337U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 54U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aPhaseCWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2988U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2660U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6536U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 4254U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 8402620908307642697U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 11347672014525086047U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 2816462912503401876U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 20U)) + 6940159795470696093U;
            aOrbiterK = (aWandererF + RotL64(aCross, 39U)) + 9134692490095883851U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4999455497008026526U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5992451460350651332U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12796550245322491401U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3417087346651371924U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3612773820086198270U;
            aOrbiterD = RotL64((aOrbiterD * 5519856345435871169U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 463398077083428570U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11249391303705089012U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7106735772303292983U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17027535139825739501U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 568131384979596481U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5683451044852895957U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4793712537158004047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10415170179135963622U;
            aOrbiterK = RotL64((aOrbiterK * 13729564030210361415U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterF, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13110U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10768U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12198U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16265U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 35U)) + 479672811032092393U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 18061121631394564425U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 14237400452740566065U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 6723123812257706134U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 52U)) + 4247997188026499248U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1939107415066134869U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3912640123546395979U;
            aOrbiterA = RotL64((aOrbiterA * 9779626695085572877U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8295478436553964298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3218960600711526885U;
            aOrbiterI = RotL64((aOrbiterI * 15443507655470278069U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5874096203353388890U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10294536533673023358U;
            aOrbiterK = RotL64((aOrbiterK * 15561710414949058923U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11268561953904130747U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16693201256788898423U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16291987237693567209U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7550969634681894654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9501647424602245869U;
            aOrbiterD = RotL64((aOrbiterD * 11265865222096866605U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 58U));
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19213U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20960U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19392U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22244U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 17936518874386450467U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 57U)) + 13722737841589910344U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 30U)) + 11774969167948715796U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 3640101505680493777U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 1369495382725650822U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11827310354654653345U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 186037671377175394U;
            aOrbiterI = RotL64((aOrbiterI * 829791264853993897U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11428829344234627340U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2275016369870029068U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14936799202145280833U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15471646673734798328U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12172082573115640145U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9629417882787847753U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6626736341348283154U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12220614992483863623U;
            aOrbiterF = RotL64((aOrbiterF * 8137086205714097487U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13157102324253760215U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4143587482368093601U;
            aOrbiterC = RotL64((aOrbiterC * 5060677690991506895U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((((RotL64(aCross, 56U) + RotL64(aOrbiterF, 12U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30618U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 27437U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25640U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30403U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 43U)) + 2672739400294801233U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 27U)) + 8475624545015101850U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 1252755112289831257U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 37U)) + 7938039507649183387U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 8167413146948861022U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17712313989694374353U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7637042279892596975U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13056020836704050293U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15770412950033467341U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3951812021898608685U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6623127125223204737U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8656983621098246507U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17943342344730687317U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16495519451034883813U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3087677463651608668U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16493240011924342788U;
            aOrbiterK = RotL64((aOrbiterK * 16898479041530771871U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7750923317452683057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2185924841611106546U;
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 54U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2185U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 6573U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 952U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 6247U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 28U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 39U)) + 12122689833405846292U;
            aOrbiterA = (aWandererA + RotL64(aCross, 53U)) + 9640400270962766788U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 57U)) + 9141937998266739071U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 21U)) + 12899395770434090537U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 13457918115408031842U) + aPhaseEOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 15134784483576000943U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 5U)) + 12540961268790055438U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6306886773092764230U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13573343491337243121U;
            aOrbiterK = RotL64((aOrbiterK * 15893457012357368707U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8545588657348974413U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10891410570357275120U;
            aOrbiterF = RotL64((aOrbiterF * 5399310978367842841U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2877137119767060151U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9178097682386595144U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3524486002084427513U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15528007881855616978U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11368419529245281435U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12433207037378339309U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5932738914934356645U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5551842263864055419U;
            aOrbiterD = RotL64((aOrbiterD * 16093776759971522681U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3824433359595690603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17184628855571662441U;
            aOrbiterJ = RotL64((aOrbiterJ * 691208053136187317U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8724462245014132623U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7481349499528092352U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8212182934509617583U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 22U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aPhaseEWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15909U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 10477U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11530U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 8756U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 3448371607470865612U;
            aOrbiterG = (aWandererF + RotL64(aCross, 3U)) + 3743742913651580573U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 13069491287948807280U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 44U)) + 16872779275586545632U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 17945792656755062795U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 23U)) + 18199747196793731853U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 37U)) + 15953311878379809513U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 941268763494588338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10090221530365796809U;
            aOrbiterA = RotL64((aOrbiterA * 14035236086292997613U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8335698093307607001U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6147498804734306100U;
            aOrbiterF = RotL64((aOrbiterF * 6904444049941211327U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5980246079567570090U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4152167624425912978U;
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14990418790239735916U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3418668387496597219U;
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4206650904177199425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3905470780938996069U;
            aOrbiterE = RotL64((aOrbiterE * 16030122739273137005U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9968672788233080924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterK = RotL64((aOrbiterK * 2615726693066300065U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17751667243048041383U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2414054413585296027U;
            aOrbiterH = RotL64((aOrbiterH * 1049512574773201893U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 30U));
            aWandererK = aWandererK + (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17104U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 21946U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24007U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22671U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 1952750591494698524U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 11U)) + 4488270851303332830U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 19U)) + 2738763375328927635U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 57U)) + 6728843649480454340U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 3U)) + 10490717875258865358U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + 1429288737812910205U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 2761375016998907636U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1088988605204499835U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6829840407300289709U;
            aOrbiterE = RotL64((aOrbiterE * 13101432880030791787U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9267240337867690471U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8120113021183975703U;
            aOrbiterH = RotL64((aOrbiterH * 14296504593187173107U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1340980511302566784U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11874452169979878835U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8638486178860092537U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1872314794140971426U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6013952618696225751U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7994863587373565715U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3644011378086236002U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8501867691997891731U;
            aOrbiterG = RotL64((aOrbiterG * 7115282675461711509U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2493546555198066143U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5179240189571799179U;
            aOrbiterA = RotL64((aOrbiterA * 1267579130962756135U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11273348247858394197U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4577476419423118925U;
            aOrbiterK = RotL64((aOrbiterK * 8427261005061162673U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 6U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26680U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 25931U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27086U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 27560U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 60U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 19U)) + 13687218104610230596U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 27U)) + 6841550124960692709U;
            aOrbiterG = (aWandererC + RotL64(aCross, 3U)) + 17418968668458764131U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 8303537912696948204U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 38U)) + 12376614417285936537U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 14215749063579232654U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 4111736931433665347U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11250375934571631522U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5367367837773331275U;
            aOrbiterG = RotL64((aOrbiterG * 7262723007545807179U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15514089192382674434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1475991716685034960U;
            aOrbiterA = RotL64((aOrbiterA * 17720681295551650891U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5531622777788629748U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8363822215908303335U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3741256932685720414U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11634667238062155772U;
            aOrbiterJ = RotL64((aOrbiterJ * 15925089729784547403U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18180546911210417155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5123234656838556335U;
            aOrbiterH = RotL64((aOrbiterH * 15362857462853398025U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11215734271189250284U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16863747802158398092U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1828035970246160023U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9859050606636646323U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9331300036643654675U;
            aOrbiterI = RotL64((aOrbiterI * 2502263410556166281U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 56U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[aIndex], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 476U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 922U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 2264U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 30U)) + RotL64(aCarry, 29U)) + 4622023259121087483U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 10253505250223501352U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 47U)) + 17133877904420462669U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 6162827793741796700U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 13U)) + 9610986424765907615U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11210747154264753754U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16554205219580654546U;
            aOrbiterG = RotL64((aOrbiterG * 12754735039924859911U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10352576357413766388U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3651845783283479752U;
            aOrbiterE = RotL64((aOrbiterE * 1011289824180799641U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18145542190463500476U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5415609566767162857U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6474184559323816389U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2033734872464201570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3507213117125813345U;
            aOrbiterK = RotL64((aOrbiterK * 5453058336688881113U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8716253393049851856U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 695984869565941856U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8377921610764044735U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 14U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15668U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 15397U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8983U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13291U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 3917730204724097072U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 43U)) + 1874642340716212824U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 6900165757434854160U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 12750946097023807161U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 22U)) + 6563216048479513594U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14960240191349450795U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16306180275951788289U;
            aOrbiterD = RotL64((aOrbiterD * 12077366095522790283U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6502066618271045547U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6219852857850888738U;
            aOrbiterH = RotL64((aOrbiterH * 10892297250334325283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2272931312452845850U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3028929882263199463U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11005324285856805069U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6067393030073568112U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10094809900437037258U;
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5962414178157074575U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15755563045799129417U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 50U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17493U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23807U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18298U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 19742U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aIngress, 20U)) + RotL64(aCarry, 35U)) + 2571116506511057880U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 13112435411509707292U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 8461951095541400405U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 39U)) + 9890793478557463815U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3030229465991783707U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7273848154043719247U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17562254601517935669U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10681774862516028276U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7105082755586853104U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12217705329504230357U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6588579345319551129U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14616333550242386092U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2934574715879306337U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15439666290229654921U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3360304356760164799U;
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14438730801970761889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14515616787452085729U;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 4U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29998U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32357U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26821U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26822U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 7075016829833562104U) + aPhaseFOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 11U)) + 8783765886115517036U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 2996723892384565829U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 9494134707342189476U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 3U)) + 5052642981395679904U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8766787055127962238U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4467211954388738079U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8599295330343804047U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8030255604633658608U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16962408063455702251U;
            aOrbiterJ = RotL64((aOrbiterJ * 11171737929747471631U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3768222186567699076U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14930990410207899871U;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14179761938395502502U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1879084742719898108U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5535012408925981515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterH = RotL64((aOrbiterH * 8577530993755159329U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 11U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7991U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 7582U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2001U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2993U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 13499155707765393469U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 22U)) + 3740324981823726185U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 5470765363949735652U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 3446436171274452326U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 47U)) + 1778929412631211933U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14666308799855220954U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4548410236791175055U;
            aOrbiterJ = RotL64((aOrbiterJ * 6822908616815218501U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5829739767694190372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14319231414903675748U;
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1513851750246111405U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1685620217748986019U;
            aOrbiterA = RotL64((aOrbiterA * 9286548037413609445U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16284162182006054402U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6271539598462003309U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12669312437565969473U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11894755313393001665U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12556759675372354075U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 22U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12863U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((aIndex + 11439U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16242U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 16325U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 12980104182836602177U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 3172622203188863995U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 1170974132219980203U) + aPhaseGOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 60U)) + 6035201940965047490U) + aPhaseGOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 13U)) + 18033907118424996722U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14604813424800580304U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13720232492851066035U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8927246214721284759U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3902659710585257448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8331560652661619868U;
            aOrbiterD = RotL64((aOrbiterD * 11418103770615560205U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4485014147538689794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 168202636924512424U;
            aOrbiterJ = RotL64((aOrbiterJ * 13711020666131492091U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16227825670092707848U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4792781933944671365U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12636865372722601282U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18198291399585556632U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 58U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 23107U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19604U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16753U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((aIndex + 24037U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 47U)) + 5576732410244514238U) + aPhaseGOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 2833808925935929629U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 3670188682914544792U) + aPhaseGOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 15759072378887814995U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 22U)) + 13934007231137439994U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11022225696007690512U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16989177104453635790U;
            aOrbiterI = RotL64((aOrbiterI * 14156758251105809453U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9256930045263527091U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17788596104417068290U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 675554110563253305U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17044369456673337625U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1310908395523250343U;
            aOrbiterH = RotL64((aOrbiterH * 16305084373037705921U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12067065689034065422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15130844248737512262U;
            aOrbiterA = RotL64((aOrbiterA * 9409499577465934107U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14532689204495587494U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8198147292120244178U;
            aOrbiterC = RotL64((aOrbiterC * 1418356389507740991U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 24U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + aPhaseGWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 25181U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30901U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28262U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31486U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 2101601659597850213U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 3U)) + 2759794072560720121U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 9443562552411269339U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 10801360546699857975U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 57U)) + 8020716394829332019U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1021894212367773801U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13346855534622490176U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12668950387932320985U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16359309548462953836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12642446944680783519U;
            aOrbiterF = RotL64((aOrbiterF * 12197935153255283321U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8197424982767553380U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14346334610901859094U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16982899923227935679U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14171304260534233539U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 334531601308283605U;
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10707856298471572695U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 18364775750091914766U;
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 34U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aPhaseGWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4883U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 6294U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 417U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 3509U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 13960289014350612206U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 3483331015269589730U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 6873299241002444518U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 3562094007125534229U) + aPhaseHOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 50U)) + 11422367439932782705U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 532453428514259816U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17810941465810193088U;
            aOrbiterC = RotL64((aOrbiterC * 2830829128884590275U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11869759058631106331U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8837581071876177566U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15329827515970522213U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17185378327053837778U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7578253375676981500U;
            aOrbiterK = RotL64((aOrbiterK * 13371647568758721729U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17112646434432814442U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14949096407295697881U;
            aOrbiterA = RotL64((aOrbiterA * 14770977858283051753U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4259590620758467836U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6534899413644542303U;
            aOrbiterE = RotL64((aOrbiterE * 7987609419215568661U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 30U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8718U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12936U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14740U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13296U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 17081642665820489793U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 14468854040067229623U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 47U)) + 2249450222593057429U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 13U)) + 14964389079511378664U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 23U)) + 17003491054252360650U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12710882240582032588U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9887078182156755359U;
            aOrbiterH = RotL64((aOrbiterH * 8205865025853482573U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7665284531810584704U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7304284015511876717U;
            aOrbiterA = RotL64((aOrbiterA * 6193179739025093929U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5517927023543751734U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17704756310857362759U;
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11347400363019508578U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11696395232760991243U;
            aOrbiterE = RotL64((aOrbiterE * 9725231749679442003U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10875780291242873583U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7808740614343437672U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8889516201913716283U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 20U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 48U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 36U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21887U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17741U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18136U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 17612U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 15036852811491820366U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 27U)) + 305637140752898475U) + aPhaseHOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 11948631574496129610U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 5321623592482991426U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 19U)) + 4075270159062690728U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15111580500356908928U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7244150695504160363U;
            aOrbiterI = RotL64((aOrbiterI * 2445733898697939969U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5131563519577488862U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5881954992088651371U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12780935808751507998U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12599159643925470226U;
            aOrbiterH = RotL64((aOrbiterH * 17690046932587062701U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9466589929741834066U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6093158735705189789U;
            aOrbiterB = RotL64((aOrbiterB * 7453778295800853653U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17461243886150519249U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15456408913739900718U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16093292401746174671U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26846U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30048U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30583U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29566U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 21U)) + 3105313968748067810U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 9977249451119627064U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 17941392803495349366U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 4279533326705471133U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 30U)) + 13983828966811580039U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3983490984234810378U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 308786542215259956U;
            aOrbiterC = RotL64((aOrbiterC * 4366245356597769425U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8443607695364427037U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14939626441464340668U;
            aOrbiterA = RotL64((aOrbiterA * 16793255020331774983U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9350693577306121110U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1717071159396961752U;
            aOrbiterH = RotL64((aOrbiterH * 11062480662625054525U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15911765265202100610U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14898546272333182767U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2674900543810733067U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3560903518513465868U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5367062725726860234U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
