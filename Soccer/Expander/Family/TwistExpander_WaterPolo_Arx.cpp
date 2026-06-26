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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE5B5912210EA625BULL + 0xFCB87AE75147C46FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9AFE33CFEF27D1DDULL + 0x91C935C820EAC330ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBAA063D75EB9F1A1ULL + 0xF5F485CD5AB313A2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9FA61F86021611C3ULL + 0xE739C3A4A31102A4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9DE01BCED941587BULL + 0x9482CCA446193CF0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCB59156749D46E79ULL + 0xA1A937FA903C9398ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA0D3C43ABEA1503ULL + 0xC7B165D4B5026F66ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDBB2AE6E2956B3E1ULL + 0xB1BF437B44C6536CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEC7731F73C886EA5ULL + 0xC2F220E87D543F48ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCB27E9D88D5E2091ULL + 0x8A3B8D4BAE086F8DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD0E0E736469E4FADULL + 0xAA5C3E240B2A7A0EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC3F85E03A5CB0543ULL + 0xC85C62F1F5839802ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA33F4818B72550D3ULL + 0xCC6E86C418A21F04ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x80F8C4351AA9BB5DULL + 0xB1965B74E74271FAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBEE1329F61165AEFULL + 0xF81AF3B39CEBC87FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC4723A6FBD381B6FULL + 0x9D153B4233475890ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5177U)) & S_BLOCK1], 46U) ^ RotL64(pSnow[((aIndex + 3862U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3232U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4831U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 52U)) + 7948891781097675369U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 29U)) + 13928362874228230226U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 19U)) + 10776180542602258926U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 5735115172149470447U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 56U)) + 5353591822981766987U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 27U)) + 562301708107268570U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 10467810247578364868U) + aNonceWordN;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 14541630141152308564U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 35U)) + 2350076897065139429U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 39U)) + 17519109078651162228U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 6061035173339902910U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15654836633731000065U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13723521735153718904U;
            aOrbiterJ = RotL64((aOrbiterJ * 14459516479283070563U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2849680038315532197U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7671010488872356142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11485114338165600777U;
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8759060657343458985U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11009137869375286581U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8741417343929809115U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15792999392743144135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6180808423175992479U;
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 361487389591183005U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15292753806514404853U;
            aOrbiterI = RotL64((aOrbiterI * 17478232597253311153U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14929153438443362045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7904556383593914086U;
            aOrbiterG = RotL64((aOrbiterG * 2484130486635511403U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3793180909904286848U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10391957637467171320U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 505484041943467117U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11648765065563798353U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17601185776537566611U;
            aOrbiterK = RotL64((aOrbiterK * 4753179291885740011U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2907499704986356444U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17048858067202291241U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 2607549567999666889U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4340465159886930775U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7948891781097675369U;
            aOrbiterA = RotL64((aOrbiterA * 12913104720552907335U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterF, 26U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 13U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 24U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10889U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6937U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8235U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7113U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 1898718075389870739U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + 5631794889237247403U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 6U)) + 18219714659484524607U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 35U)) + 15419581386225732921U) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aCross, 47U)) + 9125575431710198210U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 12205871520544965505U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 7617534300497343422U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 18017579105368135814U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 58U)) + 10693882161946020042U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 11669615701700895306U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 21U)) + 11045110212889232165U) + aNonceWordJ;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18019107802806469913U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12315940560472528716U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4899009736070044310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17412253404253730364U;
            aOrbiterE = RotL64((aOrbiterE * 10791901166391946485U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4826286251927854181U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4523455921321845084U;
            aOrbiterA = RotL64((aOrbiterA * 14534103906736598099U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4132514462154182215U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7164745605985109269U;
            aOrbiterI = RotL64((aOrbiterI * 14107325508977225261U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6297434295807635654U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8813887638672996646U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 17495632530773158201U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11086381278955626084U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5660733992573928887U;
            aOrbiterF = RotL64((aOrbiterF * 11248164458720777889U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14851044686208609882U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12707776386060264479U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4470919091467313071U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11508023384209716657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11752973809740920034U;
            aOrbiterJ = RotL64((aOrbiterJ * 10212754472298834769U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16746821150860017820U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9659421716296641396U;
            aOrbiterD = RotL64((aOrbiterD * 7530071874978553673U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3192309064305104593U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11409078048681398061U;
            aOrbiterH = RotL64((aOrbiterH * 14991409124701807765U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 315359495275427324U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1898718075389870739U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13126661894614781343U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 38U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE + ((((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 54U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 50U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14373U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 14563U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14982U)) & S_BLOCK1], 22U) ^ RotL64(pSnow[((aIndex + 13761U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 14U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aIngress, 37U)) + 16189787374324972735U;
            aOrbiterB = ((((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 17563763730956242224U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererH + RotL64(aCross, 58U)) + 10572803498593789385U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 53U)) + 7713105232072974166U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 29U)) + 10760839534772718139U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 3U)) + 13397069448391230253U) + aNonceWordM;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 4569255679998375682U) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 9888769350817876949U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 5U)) + 11351796060878856300U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 56U)) + 18153775071965707204U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 35U)) + 1282846411145853435U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16457743979262460660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3927345926316409630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5158769729850853623U;
            aOrbiterD = RotL64((aOrbiterD * 2446452358663812945U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 12331351600010165154U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3940794200348684050U;
            aOrbiterB = RotL64((aOrbiterB * 13248997263062075043U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11248514843822945425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1391497323278226522U;
            aOrbiterJ = RotL64((aOrbiterJ * 8376841806072565005U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13265623528678787307U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2802033745265647317U;
            aOrbiterG = RotL64((aOrbiterG * 3437626962562016147U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6938444301018051844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1086544666755559028U;
            aOrbiterC = RotL64((aOrbiterC * 16039728388882079889U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16156443117365816536U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3619942859562697142U;
            aOrbiterF = RotL64((aOrbiterF * 7589346043159112151U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17681848914912743292U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8848238631758130416U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 810402256099500607U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6019192027793541890U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16917288363166352778U;
            aOrbiterH = RotL64((aOrbiterH * 17673667086593738207U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5598218150530046752U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17285995539011279010U;
            aOrbiterA = RotL64((aOrbiterA * 15621233176885995065U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12380627610747299268U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16189787374324972735U;
            aOrbiterK = RotL64((aOrbiterK * 2144714828503219209U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 50U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 52U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20258U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 19146U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16444U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16546U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 36U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 51U)) + 6024062041314952357U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 57U)) + 18340757093658015585U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 11911120493880346751U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 3U)) + 17428074353884654439U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 12790849760814795936U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + 12633397052172117800U) + aNonceWordA;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 13U)) + 11946150433665237945U) + aNonceWordM;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 16842157900909419285U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 14186235783224155962U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 48U)) + 13284904542579767591U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 43U)) + 11609181965078844357U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9628562297095374984U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7850281529011259759U;
            aOrbiterJ = RotL64((aOrbiterJ * 17611485102925470357U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 257458718073794527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10693404545773519306U;
            aOrbiterC = RotL64((aOrbiterC * 14821443722828498323U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3430519236533871460U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6183054506953198055U;
            aOrbiterF = RotL64((aOrbiterF * 6121082743789970911U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2905610989884221654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16870142883133769663U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1403692060594816451U;
            aOrbiterE = RotL64((aOrbiterE * 9740854430251597879U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16904169913507057108U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4773518591580333357U;
            aOrbiterD = RotL64((aOrbiterD * 5306070307776061267U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6528141733853494275U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11254806909313951442U;
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6857506858448143407U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2855763534355983644U;
            aOrbiterI = RotL64((aOrbiterI * 16881334940165182415U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12328391751024624740U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16475072086109949522U;
            aOrbiterH = RotL64((aOrbiterH * 15218626930666825883U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15505670341076785424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6972128419331939330U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12206069109180246067U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7151546362283646210U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6024062041314952357U;
            aOrbiterG = RotL64((aOrbiterG * 10243806128059850493U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterG, 50U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 4U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22120U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25764U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25923U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 23988U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 52U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 27U)) + 12262991801139086177U) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aCross, 30U)) + 7963038771924890197U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 15540520327933568896U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 8745565892055020722U) + aNonceWordE;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 39U)) + 16619329199683755286U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 19U)) + 10865705026433867260U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 2743368697984518059U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 13U)) + 5556006271515473135U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aPrevious, 5U)) + 5355833281353498588U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 58U)) + 8313616108963479829U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 16657121016801866434U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16532226425013000833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5800465874932467232U;
            aOrbiterB = RotL64((aOrbiterB * 5966395771690704577U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17882948163883121328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15029375310296563175U;
            aOrbiterJ = RotL64((aOrbiterJ * 17021415832288477713U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10170682648007918739U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11829089574189398773U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15755874363488568849U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1746524867389196322U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10217423427886742775U;
            aOrbiterK = RotL64((aOrbiterK * 9166162099575333519U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1338457710729082656U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1319981417675542556U;
            aOrbiterD = RotL64((aOrbiterD * 9518448254565489715U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3985281993069194761U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7281264481139915593U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 13498446162967276739U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17394503335338855566U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1430703546991948227U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1623206122475721175U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 472559435062214929U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8065899137826178995U;
            aOrbiterE = RotL64((aOrbiterE * 13287499768933229539U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3377996409668333322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10456089146891981998U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12037044781049717633U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 5246784368779537905U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8518987022368391332U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4046763804695058779U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7791883487780325967U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12262991801139086177U;
            aOrbiterF = RotL64((aOrbiterF * 3409890579914160747U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 12U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 14U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32058U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31856U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28272U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31544U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 12311607308490066301U) + aNonceWordB;
            aOrbiterE = (aWandererJ + RotL64(aCross, 54U)) + 13100864684740679846U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 29U)) + 13697304189274329704U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererK + RotL64(aIngress, 37U)) + 9047976902871216732U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 13U)) + 2147897579538537888U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 3U)) + 2072444829390996142U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 2129307836981020908U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 10663145333751112064U) + aNonceWordH;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 5U)) + 15019844390503785459U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 27U)) + 5460865577557928142U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 43U)) + 15806522559993224197U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6361113778657833389U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8306013884615042570U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 8234258702656728667U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4038420580499706912U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11908091484457158973U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3964111175645156719U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11133912466611921250U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2469227904206936928U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2704438771198001599U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13234017916788297295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9061117693840451988U;
            aOrbiterF = RotL64((aOrbiterF * 3637440416741459419U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12013423690843812324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14371779015144617412U;
            aOrbiterG = RotL64((aOrbiterG * 3359568073302062667U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10044883414565441442U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14334898081890462218U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4878939077928220019U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13788962593988366125U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8377887372059713516U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 1925913354197206851U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4584439257847749371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13335592911357756498U;
            aOrbiterC = RotL64((aOrbiterC * 6515028218115896375U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11166747459333977215U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2368465601636093120U;
            aOrbiterI = RotL64((aOrbiterI * 1929974840976648333U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4538402006569031063U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3397601475441212067U;
            aOrbiterE = RotL64((aOrbiterE * 12043369327112500565U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4804403185062062524U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12311607308490066301U;
            aOrbiterA = RotL64((aOrbiterA * 10281231071618984185U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 50U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 39U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x99218F591F47CD27ULL + 0xBC5E2867DF452E9CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x855265BAF0876EE5ULL + 0x911283F13E708372ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD8880B4C20344B59ULL + 0xD60819A341593C05ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB5BC625B0FE8E193ULL + 0xA9F64E61DC6A81BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBE3BF29E60DFEEC3ULL + 0x95602EF72BF899C2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB2AC44AAC8836251ULL + 0xCFE4E7A48E9882CFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x95C18BB061A2480DULL + 0xF6C1E87FE3645407ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAC8F116FFC78C8B3ULL + 0x802531A746107D7AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB4CBE45C37858981ULL + 0xA376BAA4CA4FE65BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xABA708CF6A47333FULL + 0xBE1E4CE705783C8EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE49067CF1BA64853ULL + 0x85EE8F3E030878FEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8B2FE3B67DCBB9F3ULL + 0xB893F98066DE9475ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xABB64ED56B0965B1ULL + 0xF5999DBCB620CB5BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE50512CC1B768B93ULL + 0xB6D015D207970DB5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB5D68385F58419CBULL + 0xA2F22055B982FCF8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9B34E9E00D366E91ULL + 0x9D1DAA1755918F00ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4537U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7666U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2597U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6825U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 34U)) + RotL64(aCarry, 13U)) + 9435962834163239322U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 51U)) + 10524704356081318973U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 27U)) + 7403401305665208680U;
            aOrbiterG = (aWandererB + RotL64(aCross, 13U)) + 7525414805023556493U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 19U)) + 1116686470029070951U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + 13257612299137802420U) + aNonceWordB;
            aOrbiterC = ((aWandererI + RotL64(aCross, 42U)) + RotL64(aCarry, 39U)) + 9181543003986598283U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 9739384852307501107U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 3U)) + 11308402900229016057U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14935167593705272337U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7171824007631943535U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4839974427616194289U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8068411284829563567U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12350207458513447578U;
            aOrbiterD = RotL64((aOrbiterD * 813973258659041895U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17039236343991574134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18291683592714999632U;
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6239616841884430968U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10604527977569876774U;
            aOrbiterA = RotL64((aOrbiterA * 6972820410084939637U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1707724300671717658U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3802268808625297647U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 11296811630387191563U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9423064323799920219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 242153923313096551U;
            aOrbiterG = RotL64((aOrbiterG * 12117679073775630197U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 945801070951928277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13094814302414492064U;
            aOrbiterC = RotL64((aOrbiterC * 14638176479878969775U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7572219725951040117U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16494986983782503428U;
            aOrbiterB = RotL64((aOrbiterB * 2739189408707408171U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10949497978229234856U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11219643352002119905U;
            aOrbiterF = RotL64((aOrbiterF * 16900635614259262873U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 24U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 36U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 48U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15106U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 14258U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12799U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 15373U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 43U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 41U)) + 17019646486641172469U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 12276141179299971572U) + aNonceWordL;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 58U)) + 3617241694029841555U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 6967963401259371737U) + aNonceWordG;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 51U)) + 6340709284279891017U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 27U)) + 456065368903896482U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 35U)) + 17686765719908116203U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 46U)) + 1322045955429785736U) + aNonceWordC;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 5163772703302372887U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13268431135020363252U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6538789950366849332U;
            aOrbiterI = RotL64((aOrbiterI * 5352960308459065837U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10390344544314544893U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5087084271300584267U;
            aOrbiterA = RotL64((aOrbiterA * 15149302947570776165U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13423071121590981727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18324443012024134729U;
            aOrbiterB = RotL64((aOrbiterB * 15814349432207734533U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4129091815978464507U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17024797553831962245U;
            aOrbiterF = RotL64((aOrbiterF * 3137753479364378175U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6501545108779991661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11930037791867597447U;
            aOrbiterH = RotL64((aOrbiterH * 4904739567549702851U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4667298703308315851U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6315980380900062127U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12080555704907924637U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12732382340390769888U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7792095326183864547U;
            aOrbiterE = RotL64((aOrbiterE * 12645556660611824631U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17428384983571405782U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3193205313177048443U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14488006565106259731U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2813743367131107264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2742138679703780981U;
            aOrbiterC = RotL64((aOrbiterC * 18356569025783532225U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 60U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterE, 6U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22456U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20489U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24232U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 23811U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 57U)) + 4259993311776766595U;
            aOrbiterG = ((((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 2857813330021126753U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 1345396841329442896U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 3U)) + 320992148982301024U) + aNonceWordL;
            aOrbiterB = (aWandererG + RotL64(aCross, 22U)) + 5619109532065293074U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 47U)) + 10380157329426706345U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 35U)) + 12449831150625409695U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 7847096607042268396U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 18U)) + 11707184096803214678U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9893643746186827088U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 333687403830908774U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 17911256836121454271U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13837360705077441580U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4367119682175710689U;
            aOrbiterH = RotL64((aOrbiterH * 10295744669174603401U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1193493435041306784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15062951612027370606U;
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16000173839235429105U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15294482444605409961U;
            aOrbiterG = RotL64((aOrbiterG * 1031800997944302665U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5720749055549773527U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17248674962996093668U;
            aOrbiterB = RotL64((aOrbiterB * 15730637462755795591U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 16956840483882091059U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9637715107943515594U;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7147495779349862274U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7508890985889484275U;
            aOrbiterC = RotL64((aOrbiterC * 17728368447504622035U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4407738164617959366U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17027017782352660454U;
            aOrbiterA = RotL64((aOrbiterA * 417183060881259295U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3174658601748235285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9779053567370714831U;
            aOrbiterF = RotL64((aOrbiterF * 6383245776181968033U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterD, 26U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 58U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28413U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24814U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32140U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 31182U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 6U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 53U)) + 3970829908171131502U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + 7040283759419531991U) + aNonceWordC;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 51U)) + 11856292169397052901U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 819598588791819022U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 2176451710970866848U) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 6454704928613390494U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 11U)) + 11792122387218053841U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 43U)) + 9254780213489752211U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 18U)) + 16591812589999846482U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1471246223935074832U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1424843083106386453U;
            aOrbiterK = RotL64((aOrbiterK * 15020536982657410783U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1856469958050891629U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6331743690452052712U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 15327924647897459645U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10351075711345476487U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9518585245330480185U;
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17787514620244712033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14182328067398162557U;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12798088948801072444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9563215159275202323U;
            aOrbiterA = RotL64((aOrbiterA * 7058145016617349141U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9904919772580498232U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16579777394992143043U;
            aOrbiterD = RotL64((aOrbiterD * 10516761340320196661U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6344049286854588503U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3531503618941046788U;
            aOrbiterC = RotL64((aOrbiterC * 10855385899703024105U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11334308840132700377U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11093833870078787770U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16105889714648555755U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3831491136025364271U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12505259454860591372U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6135450888433504093U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 26U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 18U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 34U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordP;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8B5874E740471651ULL + 0x88B3AEE2B9325A20ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC5D2877C89B864FBULL + 0xFC475E6879B52BB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x94C8F4983A953F49ULL + 0xB4333DEC23AFF20EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD8D86EB4DE89CEDBULL + 0x82CC9C7FD8056039ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA2347CF8C2CF2D8DULL + 0xA30AE0D4B4C47A22ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC85E6E0AE2E0DED1ULL + 0xA482573DEA8894E9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x929367B286552269ULL + 0xE41E7791706D0867ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE1651B3FD8BD3D23ULL + 0xE2EF4E85553B73BBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA70374238841250DULL + 0xA1116D7C2424CD34ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC8471A7F8E3AA537ULL + 0xA3BF752B9ACB19D9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x921872F38BA4C92DULL + 0x9163629CD49040BFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEBB93EA2CCD4616FULL + 0xA6CD95C3A4908CEAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF7BCD3BD3A239EFFULL + 0xEB40F71D1598F993ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xED55245B06783567ULL + 0xC1C1ECA02860611AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAD1CDFE6B608D059ULL + 0xB6FE81B116CD6772ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9A2D513581748D6FULL + 0x92F91E13C16E7AD1ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5667U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2025U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6872U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 7614U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 4751694786009671052U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 16362725160370844224U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 20U)) + 6360885380915941057U) + aNonceWordF;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 5154536007972297036U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 5U)) + 9362540581874808253U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13902493871525612934U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10208452885367546542U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 12067703239567933105U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3117030377279160998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17286247690414027870U;
            aOrbiterJ = RotL64((aOrbiterJ * 4896931759653832095U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3930314320040949141U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 7289525252391668404U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15452162299105112187U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3434167955466809185U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17852573095128575663U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6137259687928853253U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13992510605237574698U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 46U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9132U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 10963U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12201U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 13493U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 13960289014350612206U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aWandererE + RotL64(aScatter, 29U)) + 3483331015269589730U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 6873299241002444518U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 3562094007125534229U) + aNonceWordB;
            aOrbiterH = (aWandererA + RotL64(aScatter, 13U)) + 11422367439932782705U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 532453428514259816U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17810941465810193088U;
            aOrbiterC = RotL64((aOrbiterC * 2830829128884590275U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11869759058631106331U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8837581071876177566U;
            aOrbiterH = RotL64((aOrbiterH * 15329827515970522213U), 51U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 17185378327053837778U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7578253375676981500U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17112646434432814442U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14949096407295697881U;
            aOrbiterB = RotL64((aOrbiterB * 14770977858283051753U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4259590620758467836U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6534899413644542303U;
            aOrbiterE = RotL64((aOrbiterE * 7987609419215568661U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 42U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 38U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16621U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18074U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18675U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((aIndex + 19432U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 44U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 2225397913940961213U) + aNonceWordO;
            aOrbiterD = (aWandererG + RotL64(aIngress, 37U)) + 8342544893601343643U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + 162922186381417187U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 11660218373710972210U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 5U)) + 14909034764605802354U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16776955237009701511U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5834487809188925253U;
            aOrbiterF = RotL64((aOrbiterF * 4458820879204327709U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1498492772767040320U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15535994410289065281U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10511923076962447765U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8575954471692620021U;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6536325446331340573U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1790628986900286346U;
            aOrbiterB = RotL64((aOrbiterB * 5262997114200816715U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2623814807619278590U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11676970995834706612U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10057461115132434901U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterI, 4U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32602U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25208U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29262U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 24690U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 785861751704720606U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 3U)) + 15968088718435606299U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 1393976526590347151U) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 17240750947292745884U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 42U)) + 4921576136163183137U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3334047873553153032U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15086509978458408698U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2162818176367899893U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 892391205397581998U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2965686403183767521U;
            aOrbiterE = RotL64((aOrbiterE * 709160942482770225U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14632215393655706170U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15740589515342377322U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15677716942904794913U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11131164813943086445U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6988080581278900960U;
            aOrbiterI = RotL64((aOrbiterI * 6412189142344044255U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16021254613117657178U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6183615599897921154U;
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 44U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordN);
            aWandererE = aWandererE + (((((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 57U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE26B92C8EA7D2DF5ULL + 0x8843652A8C868DF9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEBA1420069A84A2DULL + 0xD2B48954648D9408ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA271C446465E9DC9ULL + 0x81BD249E993D1D97ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEFA6FCF37ADFF04FULL + 0xB5A751691A33A937ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBD4BF88C26A45E07ULL + 0xAB47CB39A58F2ED9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD2879014BFDB6287ULL + 0xEB73B49AEAC74877ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE9AD84746E37D3ABULL + 0x8CB385AE5050AABEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBA6C2324E6037F91ULL + 0xD2455723B14F0E9CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF9C43CD841055CEFULL + 0x8DF1A93DC7C08C0DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAC8C2815DC9A64EDULL + 0xDDE5DA1C892AB9F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8588F88503F335F9ULL + 0xA685581BF16C04E4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8A1A4E621DFD087BULL + 0xDD6FCFD21B5D86C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF3FF986F191C0219ULL + 0x831178809E9A41EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x86E16658AE2292CBULL + 0x9EA495121B765BC1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9B49E8B0954FDC73ULL + 0x8AF7372013C7827AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBDEB9921E817F9C9ULL + 0x8CC5DC9DF1222AC5ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3181U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7866U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1773U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 1490U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 11U)) + 10915618884692072446U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 12634922308499254909U) + aNonceWordC;
            aOrbiterA = ((((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 6533934734564499389U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 3U)) + 6744203303756105181U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 46U)) + 13086782386652045658U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + 5693840533331397822U) + aNonceWordF;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 1803663542535024611U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3597219300593287708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1429753448204448904U;
            aOrbiterA = RotL64((aOrbiterA * 10927459251773273143U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17229017825587322715U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1137574712801062932U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3645832160939819415U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2401991077004083378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterG = RotL64((aOrbiterG * 15029831858261506447U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11730946340796899885U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15319163439700390962U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4744141870145159917U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6067132201862688684U;
            aOrbiterK = RotL64((aOrbiterK * 6046100687757836027U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 14991509179286371800U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4342608825699398682U;
            aOrbiterF = RotL64((aOrbiterF * 10240526103933275875U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3727521409410742075U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3302027219498304367U;
            aOrbiterB = RotL64((aOrbiterB * 12153634588200479559U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8651U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 9787U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15829U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11955U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 16519040829220310189U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 6888002778416941825U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 29U)) + 1310832187746534025U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 35U)) + 5890888009051281674U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 60U)) + 5143864838362464857U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 15591534069452660003U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + 1466867671765325096U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13931443680107902488U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15400747367673245552U;
            aOrbiterF = RotL64((aOrbiterF * 7011651369456453127U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2836975369734495759U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2370720358274970117U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4615571902817575375U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3470677184188006133U) + aNonceWordL;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 7175584278499266723U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 10067096593682482345U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6095078817776863055U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2176637999243513070U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12215701810843975501U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5580391239754903129U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15196125567953871184U;
            aOrbiterC = RotL64((aOrbiterC * 12686361960729564519U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12787014151503209931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1523153207064063495U;
            aOrbiterE = RotL64((aOrbiterE * 3113907543551927561U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12973289026485937829U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9087439766232078173U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 5817029335999350327U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 34U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23222U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 17011U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22774U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22973U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 5906639480605353429U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 5293518570213287605U) + aNonceWordI;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 22U)) + 15383185501428521377U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 15364072512743978902U) + aNonceWordK;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 51U)) + 4525473357144014271U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 3U)) + 10400911938125603074U) + aNonceWordM;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 41U)) + 16417506293824627550U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2419329331753341815U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14929222427923332069U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 11596261802662514979U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16771573504983922586U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1863466450051787622U;
            aOrbiterE = RotL64((aOrbiterE * 2585626547126027053U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12895350137096692415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3700979086526298327U;
            aOrbiterI = RotL64((aOrbiterI * 10279730254867618193U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1977099106211282426U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6144698304096915742U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5039822990560519609U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3858895556659724975U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1283646340363435327U;
            aOrbiterA = RotL64((aOrbiterA * 11622421841377018069U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6240532051889108891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 757364889381634634U;
            aOrbiterK = RotL64((aOrbiterK * 943852137901972945U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5272945693977418174U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6850528198786172283U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 1966383079897679953U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 54U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32699U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30843U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27234U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27576U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 6068543441070417854U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 2995980468193441856U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 19U)) + 18020277482171594003U) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aCross, 39U)) + 4293807434721230702U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 3U)) + 7980599111583893156U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 28U)) + 8593141111851052016U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 5903487523900084325U) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15112035513447930209U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9854037263057006439U;
            aOrbiterE = RotL64((aOrbiterE * 396276470208637283U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16759760289688823193U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12622628933030601390U;
            aOrbiterH = RotL64((aOrbiterH * 2151912984825538321U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1264668857268123425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16302812053619101593U;
            aOrbiterA = RotL64((aOrbiterA * 18291400055836111547U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16087995784896123610U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7970269262800468363U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14924752223305807461U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5331477046030959632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16534913204255550893U;
            aOrbiterF = RotL64((aOrbiterF * 1013433634373673565U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11042821902537871209U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 8069677512345031660U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 13622218526054132397U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5737130058129936372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1076627182956662997U;
            aOrbiterD = RotL64((aOrbiterD * 14342191224014199929U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 48U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB941B615C97B47F7ULL + 0xF9F3B413D6882999ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAC6FBCE9BEBAAF19ULL + 0x8675BE2089F51CC9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x88A019900B9D814FULL + 0xF28DBDD18844BB56ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAA1967BDF3F4FA5FULL + 0xF3A4974CCE2E7C2FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFCC129F193CB2DFBULL + 0xDEFC760C9D884581ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC90492C29E13DB95ULL + 0xF62353FEFB7B0D44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEDDEDFCD71F2D58BULL + 0x99E7B9F1B3249899ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEEE4901ECEF59829ULL + 0x9B8E40509F4018EFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE74C47EECB6A4737ULL + 0x8561552344CF72D1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF97755AD2D9026B9ULL + 0xF4902016B1FA600EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8AD8E6287CF3AB55ULL + 0x90C0733D140A21B4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB453BB4F6A6BB7DDULL + 0xC888875B8552A647ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x87C5E7F18564D553ULL + 0x98CE6CAF4F4B5501ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8D022781DD956E53ULL + 0xC598CF3D88407BD1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x804609F5F5A9C7BFULL + 0xDF0C193C1D430520ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD3F4ADCFCBE34D7DULL + 0x9DF7E4B5B6DC1BC4ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3912U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 4885U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5423U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 744U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 36U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 43U)) + 7632760812370906911U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 19U)) + 6007174525479723089U) + aNonceWordK;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 3362829642521821048U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 18009548556107978286U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + 17880909432272697327U) + aNonceWordB;
            aOrbiterG = (aWandererH + RotL64(aIngress, 29U)) + 15961567935420752568U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 10136559064656837921U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17622019364405410277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6927494824421416306U;
            aOrbiterK = RotL64((aOrbiterK * 2686290883767829973U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7125170407794874847U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12342273503071032250U;
            aOrbiterD = RotL64((aOrbiterD * 867417849555857179U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 14997696377476124836U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14874498694181230698U;
            aOrbiterG = RotL64((aOrbiterG * 4026127545746010937U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2549397729130885686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4217995818662767955U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4706089044415442525U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17983900172670031015U;
            aOrbiterA = RotL64((aOrbiterA * 541552737180932879U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1904937798143929988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10620877287033139483U;
            aOrbiterF = RotL64((aOrbiterF * 16711012562024287213U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15681091173163181525U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2655543246639000084U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16686375598149755947U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 36U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12312U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneD[((aIndex + 8226U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14437U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14268U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 48U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 1042610313571524121U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 3505725321008825582U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 35U)) + 12584654563843782991U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 11U)) + 6645399144515770935U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + 3608978423753715584U) + aNonceWordL;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 37U)) + 8089198857670370983U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 15207251813516399879U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9579268660105824516U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2269649280637188723U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 583811872609805949U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7027491967970873942U;
            aOrbiterG = RotL64((aOrbiterG * 12686754713465826139U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18256061823189677508U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12708429127816136937U;
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12169216645156306078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12694325407567795065U;
            aOrbiterB = RotL64((aOrbiterB * 3711789483877261899U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16109994660203297503U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4234704064165718913U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 730085881474787681U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14119541943554602878U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8777769004811352951U;
            aOrbiterF = RotL64((aOrbiterF * 2556957257736134223U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15642663488392549609U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11594468530833278624U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6639306656361601143U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 12U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 10U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17400U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 18811U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21544U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 19585U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 50U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 51U)) + 11450949896247900941U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 3905542253538116335U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 9529740545977785305U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 1856876631533143492U) + aNonceWordN;
            aOrbiterG = (aWandererD + RotL64(aScatter, 11U)) + 84253466320181686U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 60U)) + 12577480918745432444U) + aNonceWordC;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 5625703170397704029U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 694608607323629282U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3993981243536262204U;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4119215953484892051U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8785040118556157146U;
            aOrbiterD = RotL64((aOrbiterD * 17113521266125471625U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16234403619456882890U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10398727475672860610U;
            aOrbiterE = RotL64((aOrbiterE * 5086871400049644715U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18327987141759096769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2645964788056875452U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2859452497983106129U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7196557924940881076U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14415389907490256711U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 930127943984174668U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15673596916054795749U;
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16673140529110941163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2258448294877833760U;
            aOrbiterC = RotL64((aOrbiterC * 1821550319748977445U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 14U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 20U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30433U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 29823U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28175U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31364U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aIngress, 29U)) + 13650869943246163567U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + 3435284932011770999U) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 11U)) + 12388155658186776579U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 2374345913955712039U) + aNonceWordI;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 6095094526980292156U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 4965147025852444174U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 23U)) + 3261881216269075298U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4939780217097329222U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3019862009792676287U;
            aOrbiterC = RotL64((aOrbiterC * 2452316208025448747U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 901910626217143974U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 3647055146712366383U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 1792602402476450009U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7731765438957392967U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13409819457393479741U;
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5415832109107794258U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8876738832313114471U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1304277600444504135U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17135570542519390359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2373193062766802082U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 4213691513185791519U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16318403285501718552U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8456043288604687045U;
            aOrbiterE = RotL64((aOrbiterE * 10556964529144571683U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10572534930284516528U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14616251186735204677U;
            aOrbiterD = RotL64((aOrbiterD * 2048651204265459805U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterF, 21U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 56U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCD89EBA59741E983ULL + 0xB63288AE9E640FEAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFD54C4DEC3E60A07ULL + 0xE6591159E5636E10ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB62286EB43E0C449ULL + 0x8BD094DECA8F06FBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x84B71796B1CAC227ULL + 0xAB5C30716F618702ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF28F84616A275FDULL + 0xC16A349537F386A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF6718E42A33C4849ULL + 0xC61F79B3480C88A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x93410CDD39997A63ULL + 0xAB8BC1ACF72D4A5FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB7AEAF59D2440CA9ULL + 0x9B1809766211F598ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x892B17BFC4EB198BULL + 0xE55E5AF9A11AD3C8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF331821D21BE708DULL + 0xCEF392349A9445B5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAFEF3225CBDF9481ULL + 0xAA97FC1E4819C233ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEA71B2449C322145ULL + 0xB85515DA6C621F8CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x915DEA0B3634FAFDULL + 0xE35E04B33EF45BA7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF10759494EF01CF3ULL + 0x8671F04D96A91B4EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE16E8EF65684C027ULL + 0xD21C27EDB1ED3CDDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB4DC1FA7DCF82515ULL + 0xC33DE3F530BFCC68ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 205U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7578U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5415U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6178U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 48U)) + 8367680518550579791U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 51U)) + 11491674725611181241U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 5U)) + 16673861720782164214U) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 9786610124108350855U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 35U)) + 5745080601557577637U) + aNonceWordL;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 43U)) + 1959402215131684684U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 6121650036079196522U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 12016309761037342392U) + aNonceWordM;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 13U)) + 5986936646177049603U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 3U)) + 1000367700904043468U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 23U)) + 17425288243569101032U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4856917474950325209U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16312111093223166419U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 456110002032422270U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11393724374787795662U;
            aOrbiterD = RotL64((aOrbiterD * 1176984359123668389U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8378176867715697176U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8086186452345234815U;
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8470349167474173245U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2528229938740192694U;
            aOrbiterH = RotL64((aOrbiterH * 8717790851266520943U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13247168811545753141U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8745293957516815264U;
            aOrbiterE = RotL64((aOrbiterE * 14270617180621072619U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6165915500564961987U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12015407798844173213U;
            aOrbiterF = RotL64((aOrbiterF * 3913451986559154153U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 545006684939922156U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16366753936267185001U;
            aOrbiterG = RotL64((aOrbiterG * 6495185976430013201U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3097605623436091728U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15950167830259022926U;
            aOrbiterA = RotL64((aOrbiterA * 4415538963984293323U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8356327899232213426U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10183421678251169945U;
            aOrbiterJ = RotL64((aOrbiterJ * 9474380650337109299U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16327340177970834683U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7086901180933495535U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1276521829484494857U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13421211370092080006U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8367680518550579791U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 12256662446176946163U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 34U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 26U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16000U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12555U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16186U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11453U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 54U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + 17225673071833726819U) + aNonceWordA;
            aOrbiterK = (aWandererA + RotL64(aScatter, 53U)) + 10301458382103627331U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 18U)) + 3960233050857362414U;
            aOrbiterA = (aWandererI + RotL64(aCross, 23U)) + 17768665685046605837U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 14471018461213959767U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 37U)) + 10730597892721340453U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 14863394003122760542U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 9948587274816688296U;
            aOrbiterB = (aWandererF + RotL64(aCross, 41U)) + 3573569431435100993U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 39U)) + 8153670675740450590U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 46U)) + 16438856577722561424U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15765587867581925041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1082039522061775213U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4202521649260798876U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15877659681260461141U;
            aOrbiterK = RotL64((aOrbiterK * 11369910758551088173U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2551560426129646123U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3005102326163906320U;
            aOrbiterC = RotL64((aOrbiterC * 4241583192662435107U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1675501058857208089U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12774812270956702043U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5488437008504905105U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1044886020922563597U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4857445127457225171U;
            aOrbiterB = RotL64((aOrbiterB * 13223560654459705259U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11548725551787560962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2434677823189765161U;
            aOrbiterH = RotL64((aOrbiterH * 4283026044563670969U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9606875320524736294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13732615866277657704U;
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13921743663803299567U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13350829301153929899U;
            aOrbiterE = RotL64((aOrbiterE * 11858642286713079795U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9473349030551400156U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7446792050826434742U;
            aOrbiterI = RotL64((aOrbiterI * 6619682184124713031U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17970527747978977453U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2326714817603921480U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14581676978186226887U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 7875511075130474136U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17225673071833726819U;
            aOrbiterF = RotL64((aOrbiterF * 1196024136909896027U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 20U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterI, 24U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK + (((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 44U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17909U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24361U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19570U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 20961U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 43U)) + 1888427424966603593U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 21U)) + 5436761445660415091U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 19U)) + 17322876217962143270U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 41U)) + 9728299982740564979U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 21U)) + 301720335271716921U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 8069685428854814396U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 30U)) + 1973715500949100991U;
            aOrbiterC = (aWandererI + RotL64(aCross, 51U)) + 87666408799854155U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 12195436904339035245U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 4578742069143400295U) + aNonceWordL;
            aOrbiterJ = (aWandererG + RotL64(aCross, 11U)) + 7828776048774876484U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17203146364542781833U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16913369550858890466U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13534417587921978507U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9632761514552265402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9106637671877341286U;
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15423680889126750876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6087310684583331882U;
            aOrbiterH = RotL64((aOrbiterH * 8964465129744898619U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5420955876411796789U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14166807419730848032U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 442659738632823751U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8118312450347026824U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4253043584558403086U;
            aOrbiterC = RotL64((aOrbiterC * 5651748455190536467U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8810774678371762700U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12218479555589447835U;
            aOrbiterI = RotL64((aOrbiterI * 11026364205248516355U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11389930523582876358U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16334420553471379915U;
            aOrbiterB = RotL64((aOrbiterB * 13830132212033904777U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18201289372553710279U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7196540389657785361U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13058135202554889791U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2601046573550065116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2243003381737071984U;
            aOrbiterE = RotL64((aOrbiterE * 10518763530499878945U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6058992247656841580U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10083863011670540073U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 17908394295613117155U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8505005026063156940U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1888427424966603593U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 18298382581929885653U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 6U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27699U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 29329U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30550U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27579U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 48U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 6318740973868639425U;
            aOrbiterK = (aWandererI + RotL64(aCross, 26U)) + 5487840061430920881U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 10258706763248072672U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + 18356875269730338208U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 23U)) + 12883160282903147010U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 13U)) + 1010140474942697730U) + aNonceWordD;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 19U)) + 17733939421700898293U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 21U)) + 13693055887924981201U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 41U)) + 14574732452793385269U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 37U)) + 10832873941223609012U) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 8212600587135328040U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5312744319781971178U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3693249147883790810U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18365859989736602556U;
            aOrbiterJ = RotL64((aOrbiterJ * 3348463719324104997U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10645056678337549771U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13556844570541823717U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4790355739411849736U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14905575502272644116U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17047244574558476634U;
            aOrbiterC = RotL64((aOrbiterC * 2356386971503880047U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10161614295718414869U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13413914082651612468U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 16224039093981079491U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6072693130156927774U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4333656233793103787U;
            aOrbiterB = RotL64((aOrbiterB * 9374745547133955709U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17209776289202130250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11752001118070361543U;
            aOrbiterF = RotL64((aOrbiterF * 4416523594812872339U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15367365111105608277U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8650687767097460704U;
            aOrbiterA = RotL64((aOrbiterA * 11430451559660578667U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18074648514448405693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10857586858462237581U;
            aOrbiterK = RotL64((aOrbiterK * 3722891011080095849U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17219932344278345591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6318740973868639425U;
            aOrbiterH = RotL64((aOrbiterH * 8846295038878812229U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 4U)) + aOrbiterC) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC7CEFC4106FF3061ULL + 0x97B53FFE22939E35ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8B1B9CECFB8F54F1ULL + 0x8FEB312359EFC8C6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDC5C5D7AF0FDE1ADULL + 0xF91A8A7DF398462BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9B4725C70BF9A265ULL + 0x966C3842A63FCCD5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF22345085AB4DC71ULL + 0xEAB19F54DBEA52A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE1C5B9C8D82B5CE9ULL + 0xC7EF55B59EF355E5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA9DB4C5CB4E42A13ULL + 0x89C92EBA11AF8145ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC100E962499520C3ULL + 0xD5B4CAD2E7DD3686ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCEBB965293D595E7ULL + 0x8E52361F0C252606ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEC5CA4A94114C56FULL + 0xDC621967A8376C0BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC5A975924DBD0EF5ULL + 0xD594B88DE4DF7EDAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD71FBB9A7470685DULL + 0xE24DD779A9F2669AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD9A29D3CF5887231ULL + 0xBD2292C54D7F4F0CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8E86A75D0ABA82B9ULL + 0xB70CACB69082370DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBB210A9BFA50E42FULL + 0xA6ABAF8C6B9C3497ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE2A5E60234515CB7ULL + 0x833067C09404DF23ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4693U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4504U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5436U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 3197U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 46U)) + 4980738603982643969U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 19U)) + 17660278413018470020U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 17598114429859543466U) + aNonceWordO;
            aOrbiterA = (aWandererI + RotL64(aCross, 29U)) + 10993929335279994739U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 6U)) + 17967203122976322481U) + aNonceWordL;
            aOrbiterF = ((aWandererA + RotL64(aCross, 23U)) + 1872290205549034384U) + aNonceWordM;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 16607778671782810797U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 41U)) + 4895226930754394376U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 14960359005982301383U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9921642352377700630U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 893281964367208693U;
            aOrbiterD = RotL64((aOrbiterD * 2345509157333444217U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8232519988397858732U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4433022122758913407U;
            aOrbiterF = RotL64((aOrbiterF * 834240393225479419U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12689609831247168353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 404535388957472176U;
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3349108201964013155U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4386449511297371730U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9596273264321140229U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14314587717949070586U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10923886625271054985U;
            aOrbiterG = RotL64((aOrbiterG * 7838969002623486809U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17634909585329833520U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2021301459918350372U;
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5219599112498224367U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10641339455385046206U;
            aOrbiterJ = RotL64((aOrbiterJ * 1022283727595400719U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5003342156562330058U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10951027475628404336U;
            aOrbiterE = RotL64((aOrbiterE * 17836928292555158461U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13040991872592235460U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11149099984302782267U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 4248667283139686251U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 54U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 38U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 26U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 52U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 30U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5526U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7752U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9137U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 6410U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 44U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 52U)) + 12775735908960052604U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 57U)) + 11791373812080296887U) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aScatter, 39U)) + 5537362877706057303U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 2023912048504189380U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 17668828109963766893U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 19U)) + 558908629933941224U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 5U)) + 1479633119685446888U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 29U)) + 15460320397843364063U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 10059749397555469054U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 9987633811929693924U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4446204415503364254U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10611580584157624739U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5462682413239873181U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9327201928815412810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7890659377013147073U;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10675114832750356941U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12871947817782057116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11015991745792051390U;
            aOrbiterH = RotL64((aOrbiterH * 17152451500505815031U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6320437975845673731U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 702457937087191287U;
            aOrbiterJ = RotL64((aOrbiterJ * 17491257114676739589U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16629064896250312921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6054107387816339103U;
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterI, 18U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 6U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10990U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13107U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15396U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15622U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCross, 18U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 39U)) + 13442819395490639310U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 8187292523194120936U) + aNonceWordP;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 30U)) + RotL64(aCarry, 13U)) + 11469697159823131388U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 13414083692375929653U;
            aOrbiterH = (aWandererF + RotL64(aCross, 53U)) + 11404010733687907517U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 47U)) + 6783212827186218247U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 43U)) + 8561131439340372614U) + aNonceWordH;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 34U)) + 6252609642004429113U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 12804867444200448952U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2739648749603690781U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14808861217017399752U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 373911885694012101U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17588866502571268888U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5882260142735642980U;
            aOrbiterK = RotL64((aOrbiterK * 7688252946143263869U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15493099088132862949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5175647411532429582U;
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14279707376173642767U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6826363572161275158U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13267185753040999992U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9980987858092888720U;
            aOrbiterH = RotL64((aOrbiterH * 13210290848800728635U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3582972937645514549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10140409019562890804U;
            aOrbiterA = RotL64((aOrbiterA * 6944490201647678479U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6160444117287330557U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16344602960561293113U;
            aOrbiterG = RotL64((aOrbiterG * 2319964919335633293U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 3497141036108337171U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12739932748793144857U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12820180915064791197U;
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 4U)) + aOrbiterJ) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16947U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21372U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21750U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 20606U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 60U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 12122689833405846292U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 13U)) + 9640400270962766788U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 9141937998266739071U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 41U)) + 12899395770434090537U) + aNonceWordM;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 13457918115408031842U;
            aOrbiterA = (aWandererI + RotL64(aCross, 53U)) + 15134784483576000943U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 47U)) + 12540961268790055438U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 24U)) + 6306886773092764230U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 37U)) + 13573343491337243121U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8545588657348974413U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10891410570357275120U;
            aOrbiterG = RotL64((aOrbiterG * 5399310978367842841U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2877137119767060151U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9178097682386595144U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15528007881855616978U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11368419529245281435U;
            aOrbiterK = RotL64((aOrbiterK * 12433207037378339309U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5932738914934356645U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5551842263864055419U;
            aOrbiterB = RotL64((aOrbiterB * 16093776759971522681U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3824433359595690603U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17184628855571662441U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 691208053136187317U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8724462245014132623U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7481349499528092352U;
            aOrbiterA = RotL64((aOrbiterA * 8212182934509617583U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6908362960248294718U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5354057969992655314U;
            aOrbiterE = RotL64((aOrbiterE * 16586084885820679343U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11138301629323903147U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14164180536320940750U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9099767681053390287U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 709942920176922902U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17128241237359414945U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 14063385518459963529U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterB, 10U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 48U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24473U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23113U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26325U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 26438U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 39U)) + 898812731947995389U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 8677347622525527167U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 770321564027567654U) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 14U)) + 11020474858081526395U) + aNonceWordH;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 17289793580414993470U;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 10111912559295118444U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 27U)) + 8083622125544542011U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 23U)) + 7149858558922988240U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 5919683821379905699U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6860902846079238714U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15083517836867542075U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14852868368708376381U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9860233289028878323U;
            aOrbiterG = RotL64((aOrbiterG * 13418143547952204667U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 772406119079116272U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 10168120622976358617U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8478568022896691911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4027604850785607101U;
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17199331557841535430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7515957656979776361U;
            aOrbiterJ = RotL64((aOrbiterJ * 5468950152869656599U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17138249294921502391U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16236812863923234668U;
            aOrbiterH = RotL64((aOrbiterH * 2925542836624164807U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16941524155859123682U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11240343728857342866U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7281012444214294659U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15163914964139858328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6673576554415729652U;
            aOrbiterB = RotL64((aOrbiterB * 1558880328574736975U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5399050402101642989U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11806006719060024615U;
            aOrbiterE = RotL64((aOrbiterE * 15782156615926092159U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 28U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 6U)) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30321U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31938U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28607U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29320U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 51U)) + 3236820517816085022U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 30U)) + 741288875914097926U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 47U)) + 8417246926007729580U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 9715717805774537170U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 14360243844821619482U;
            aOrbiterG = (aWandererG + RotL64(aCross, 56U)) + 10760908100206775334U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 3434641779946167811U;
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 7885568822756234567U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 23U)) + 3041563437672051294U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15761355327564963516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1158633562785937421U;
            aOrbiterA = RotL64((aOrbiterA * 15511324886867188235U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9338581575871970653U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9172038894262857354U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14653924713599790081U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3854497592598563309U;
            aOrbiterE = RotL64((aOrbiterE * 11737111068815795303U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16286980180327600557U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5092583772591249756U;
            aOrbiterB = RotL64((aOrbiterB * 13955105624639442903U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4288397994175567333U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15584236478994873104U;
            aOrbiterF = RotL64((aOrbiterF * 1860480595862755379U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5557463939827483792U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2659814275753280856U;
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6941807963525063449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2040598555191211307U;
            aOrbiterK = RotL64((aOrbiterK * 14750544987531722765U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 347572666231116258U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 779304821185302523U;
            aOrbiterG = RotL64((aOrbiterG * 14180254150318109855U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10632524582873079742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9761308771280517212U;
            aOrbiterI = RotL64((aOrbiterI * 13926235411726048921U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 60U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 18U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCC0D2B97646F3E1DULL + 0x951D8F1BCEF7C52CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x888F5B6095524629ULL + 0x8CF591C5DB332335ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x84C9C568370A588DULL + 0xFCCF49B7AB22173BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA65AE8B7196B99D3ULL + 0xD705AC9AC2A7745EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB6ED5F92D7AE9D69ULL + 0xCB921DCA8F689854ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFF9663B01A4CB683ULL + 0x8DAF4C51327999CCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x82188FECC71DE5B5ULL + 0xE1B6E81EC3D67A1FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE56F9D2A2C6B75A5ULL + 0x95B7D759F0882A20ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDD2F749D9738A02FULL + 0xC316814BFFC0B00CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF84A1E201EBE86C3ULL + 0xD41D218D55EC375BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD973E5D39B39D1B9ULL + 0xE75900686830B0FCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9DB5F7E5419E455BULL + 0xDD416D5F9FC98880ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDAD2DA67FDF25605ULL + 0xF2DEDEF35A5E8AF1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEE62CB5636254E13ULL + 0x9B0051AE3BB66EAAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD523CDBD9CA2D4FDULL + 0xC2233071024E8331ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE559A4D04207585DULL + 0x8D5FA3114C23CA23ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1135U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2536U)) & W_KEY1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 589U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 656U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 23U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 29U)) + 14624277139785904404U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 51U)) + 6966977309498165611U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 38U)) + 205536824352530761U) + aNonceWordP;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 16629575265808255692U) + aPhaseAOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 596881340147972746U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 11U)) + 11944412799107412650U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 4615021315668210206U) + aPhaseAOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8497630055977606216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11131601107309336885U;
            aOrbiterA = RotL64((aOrbiterA * 18028349768453554935U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5935883479805510099U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15629346719765798174U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8535523790685945275U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5279128339113651273U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16778365912440331821U;
            aOrbiterG = RotL64((aOrbiterG * 705421028266789241U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16003052937645491524U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6723226158737614764U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 16690657664909260573U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9785784358981219543U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10055457337292292710U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17919129940751761111U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11779163108592974175U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 1177999477942202687U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 13475069421684114643U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9190694445141492214U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15605342360346353457U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14547769706392595647U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 36U)) + aNonceWordM) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10615U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8132U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7861U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10434U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 1708250618750199233U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 12009147777553691142U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 27U)) + 8393982703399156592U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + 3247327098356831221U) + aNonceWordP;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 3403590155376353737U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 53U)) + 18197244558104735044U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererE + RotL64(aScatter, 47U)) + 3096253642040701606U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8012692688785412179U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17531946907545680745U;
            aOrbiterG = RotL64((aOrbiterG * 16510602981731506381U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17687695944270225817U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 16147773866007628769U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18244641303026196497U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8839160526348897457U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10599266240854068246U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2056723540756216155U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4629354220460621284U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9505955649473204942U;
            aOrbiterK = RotL64((aOrbiterK * 17775391885312236187U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17078153810088721310U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9470436761716263000U;
            aOrbiterB = RotL64((aOrbiterB * 5431855497250357229U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3305863413630104742U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14377172434239576161U;
            aOrbiterD = RotL64((aOrbiterD * 6880176890091033423U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 27U)) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 28U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aNonceWordA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13541U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 12453U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11879U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[((aIndex + 11679U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 54U)) + 701291026547470433U) + aNonceWordI;
            aOrbiterC = ((aWandererG + RotL64(aCross, 11U)) + 17283292650462111643U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 27U)) + 9969124091931303406U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 889176772718046988U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 6054541844643748084U) + aNonceWordP;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 14703226235143028132U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 35U)) + 7977975878522921062U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16894322614172266274U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12160451749345900570U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18055355572903901749U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10870847008043897470U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8159920947172520247U;
            aOrbiterC = RotL64((aOrbiterC * 4833194641611011805U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 2440099120969517932U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2428396147731468007U;
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2213226274394673479U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7079731443427765333U;
            aOrbiterK = RotL64((aOrbiterK * 16918930776877030559U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 958896789550478970U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10788682955708075458U;
            aOrbiterA = RotL64((aOrbiterA * 913321215613559729U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2003386579317564870U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8419686358774204999U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6547052526438697621U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6989167615157578904U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17636634003643824148U;
            aOrbiterI = RotL64((aOrbiterI * 11038576417283732937U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 12U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19598U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19524U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19684U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16665U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 21U)) + 3550722402315312207U;
            aOrbiterF = (aWandererI + RotL64(aCross, 35U)) + 16724184551669522754U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 981751330116773021U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 7891159229704944868U) + aNonceWordG;
            aOrbiterB = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 13618396711464799841U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 5969291018449003648U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 28U)) + RotL64(aCarry, 41U)) + 14595540413313640042U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 3287990436916111762U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12534369400200483704U;
            aOrbiterA = RotL64((aOrbiterA * 2345945228434740707U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2277312067930392274U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10026320559261334353U;
            aOrbiterE = RotL64((aOrbiterE * 11020464940995912637U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11258082063135659551U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1445958517675746990U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10062265337488757971U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1011298251290970844U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6487834862470043744U;
            aOrbiterB = RotL64((aOrbiterB * 15477913837027179675U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9966279022928268335U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10285993486057704393U;
            aOrbiterJ = RotL64((aOrbiterJ * 15965714363201157535U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16005362468813966136U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 223843444699390781U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18178876294968532775U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12490136112181806806U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16380841616662993709U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aNonceWordK) + aPhaseAWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 60U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23231U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24606U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25234U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 22195U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 43U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 12206125048349568300U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 35U)) + 5843520589343188818U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 12195046124287121687U;
            aOrbiterJ = ((((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 16769779119214020640U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 29U)) + 5257603646260695833U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 21U)) + 8523523946234886745U) + aNonceWordK;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + 7316024684200084096U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11996978575084115207U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15491711479085513628U;
            aOrbiterD = RotL64((aOrbiterD * 15136690392026011819U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6036648530996821484U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 926323222234121863U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6639661141258803779U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 2700323841295743492U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5852273765810284935U;
            aOrbiterJ = RotL64((aOrbiterJ * 16665696735016345215U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11697397483133538067U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17777142964957007194U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6338967222543284999U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10892176201151170298U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11759700374509499684U;
            aOrbiterE = RotL64((aOrbiterE * 14247697264744736081U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11343756773329590643U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15785048929757652350U;
            aOrbiterG = RotL64((aOrbiterG * 17208103574389502597U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7508839228498497238U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13088508510402094665U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 15730279447009669103U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 30U)) + aOrbiterG) + aNonceWordM) + aPhaseAWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27984U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 29478U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29910U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31475U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + 4384716820085860551U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 9715780315942116888U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 21U)) + 15963520052789178632U) + aNonceWordL;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 43U)) + 14346700690686392938U) + aNonceWordC;
            aOrbiterE = (aWandererA + RotL64(aCross, 29U)) + 6005518012489966643U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + 2506732930310252119U) + aNonceWordO;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 16782163084851775826U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 823673076571076303U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1634084509064077736U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1128407326773234517U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1288134975466877686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2998220403162908444U;
            aOrbiterE = RotL64((aOrbiterE * 4321412662318298283U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 220430672180734911U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10223923547068528867U;
            aOrbiterB = RotL64((aOrbiterB * 12577370238343872139U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11696469696177647608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 79691451831797107U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8971444023498649419U;
            aOrbiterA = RotL64((aOrbiterA * 7148919880477390009U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 5624403902454498793U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9468064161002030997U;
            aOrbiterI = RotL64((aOrbiterI * 8243560528100864595U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4619361544913629805U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12682446273369750704U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 48U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEAB6344E27590D15ULL + 0xBF4DAD23F3B9018DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x914E1EFA9EFBA253ULL + 0xB15B691E9576D7BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEA1B568BA27DF465ULL + 0xA2EC5472EB73131CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8CF946ABF87F7171ULL + 0x99249AED23EAC743ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCABD4138113B6E11ULL + 0xC95B93FF6A3337C2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBA5BEC7B9E1D1D9DULL + 0xA58AB984B76E7048ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB0D95F771C9CF2C3ULL + 0x988B6DDD6B4F5287ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF5316170E6064175ULL + 0xF28352943D85B5D5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA4623431368CC70BULL + 0xC2BF0F725C8F1472ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC74C518BD0AD809DULL + 0xC933309C8C1B31D8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9209F351A841C1AFULL + 0xC4773F9AB81FD100ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD22C5C0DB37E9285ULL + 0xA6CCB6B6429F7F0EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB40ACA9B2AA9C43DULL + 0x9CB399699619C43CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA980C6C073838731ULL + 0xC09F38F0DC8F92D7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD5C171BFFFD790BBULL + 0xC621CE6F8F231495ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD5CD419E4458A9CFULL + 0xD3164C24F2B70E52ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 217U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 222U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4471U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 3649U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 50U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 39U)) + 10336802574069791273U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 3U)) + 169025388197058936U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 16223920526599306104U) + aNonceWordJ;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 11U)) + 12756613707692514808U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5082475548176484035U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4907435526952698526U;
            aOrbiterK = RotL64((aOrbiterK * 1379692095754989215U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14236627073831834337U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11502511046130497584U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3460330807286625917U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3679044835550219497U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11254838916686736746U;
            aOrbiterC = RotL64((aOrbiterC * 8631695922983532915U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10582608424233200966U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 10449735026385340313U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 52U)) + aNonceWordH);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 35U)) + aNonceWordE) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + aPhaseBWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6633U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9709U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8969U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9077U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 54U)) + 18319689184146942855U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 39U)) + 8041304130090501019U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 11347064191990897738U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 15242243470024447468U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 10619749107163611105U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14795614276221947128U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1578095288886372393U;
            aOrbiterH = RotL64((aOrbiterH * 9953192041564147241U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13593906305770501684U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8919815528334599172U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2033810402808238127U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17425548324720065145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11125018338392347335U;
            aOrbiterI = RotL64((aOrbiterI * 4377887040461528587U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3779189180734244399U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 10958224663276134041U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4317305352561612995U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 4891139433808505355U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11507024985663120317U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 50U)) + aOrbiterG) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16311U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15005U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13129U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 11008U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 14U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 3561491146322798260U) + aPhaseBOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 7075025056181885339U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 9230910887904171613U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 11U)) + 4119781172609908917U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 34U)) + 17155609083870983149U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2423018561430181695U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12957280305617615744U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17696410107705645631U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 2461704174772065813U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7907123257849391997U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9416171962847312179U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7257868138318960007U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16425903703085702285U;
            aOrbiterI = RotL64((aOrbiterI * 7996935869077231999U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2990822664594079467U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5654819006718953817U;
            aOrbiterK = RotL64((aOrbiterK * 4465096036756887801U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12183676471235678779U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15026286960542123922U;
            aOrbiterH = RotL64((aOrbiterH * 17199049329995315279U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 24U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aNonceWordN) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 56U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterF) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 42U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18704U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21191U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17010U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19649U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 24U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 15920462086654025436U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 60U)) + 487844076858004017U) + aPhaseBOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 14502883786442630566U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 3787107318658233674U) + aNonceWordA;
            aOrbiterH = (aWandererK + RotL64(aIngress, 13U)) + 12548777544693755491U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4907309444075181683U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18342396700266492072U;
            aOrbiterG = RotL64((aOrbiterG * 14842961036061482089U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13503051997624242670U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17845742460521374571U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8640887211877858169U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 5273913123709097537U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 1661149444148461791U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17756844173695563883U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6713055830729302951U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2832836748513174311U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5106468334224035972U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10228769728713526172U;
            aOrbiterH = RotL64((aOrbiterH * 9760310686414358435U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordN) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 20U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26246U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 22945U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22759U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 26038U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 13350544654542863236U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 12364346790125404372U) + aNonceWordP;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 9738750172849512764U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 5U)) + 3781373837635491421U) + aPhaseBOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 58U)) + 16635020317512702337U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5383653921676231276U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10181959815492056493U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14784636206508715141U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10005510924273927017U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9524687662265740565U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13687380438646756931U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4259138552009771014U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8973051213213726023U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12625091476068190979U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17602611840127337490U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8218984546932905269U;
            aOrbiterC = RotL64((aOrbiterC * 17504305273683304231U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18102186122213487888U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2629927500298092976U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 6983280164448292723U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aPhaseBWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordC) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27616U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28482U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32100U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28248U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 34U) + RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 7651355040951791298U) + aPhaseBOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 13988210277931659312U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 29U)) + 9846849412579537783U;
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 41U)) + 12746719939495876158U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 41U)) + 11498066185182895284U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11101058955193080232U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15513734459555672046U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 6974281215677538561U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15711108675349394643U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4771231759949468556U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9806191054594333615U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11449258010811305256U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17036938391509986723U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 7411466953205347639U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6999245666776654250U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2106819066263369528U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13005885810757743129U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12716183358903477216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16752724547046059889U;
            aOrbiterG = RotL64((aOrbiterG * 11475905692393034141U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 52U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordD) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aNonceWordH) + aPhaseBWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF2D7E3BC85C63DBBULL + 0xC3A7B2FA9EA4D4ECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF613B37929C9CD6FULL + 0xFDEC5AD9579CDFCCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD132CE6783A0A4A1ULL + 0x92C872088412D054ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEF477472D593CA39ULL + 0x8A48196462E9C283ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8E3566963768A4B9ULL + 0x9E9CC8682697C8AEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE92CB88A31F1FCD9ULL + 0xFBEC90C8165BA7DDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDBED2B6A8E31B1F3ULL + 0xE8CCD73A929E652DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9EA86BDC292C54E3ULL + 0x9A6C2D3E574D82E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8ADC4A58A393ED19ULL + 0xEF3349787BC5637DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBCEB3E388C152F95ULL + 0xAC9AC4726AC6810EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD42EFF0149863CCFULL + 0xAEA9AC392B1AEE71ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xECD14AAA023E28DBULL + 0xC2295F3830521BF4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC443AEE1D1D54999ULL + 0xD784CC18E8838FF8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE595A43CA6AD28E1ULL + 0x820D42DBAC1A9A87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB9F58D99AC3140ADULL + 0xF4FB7BC977D4C72BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB1A78EEA5361214BULL + 0x9A46767B60FC6797ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4761U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3439U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6142U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 89U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 38U)) + 13924571355038625040U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 16328300979357156658U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 3947771961206012461U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 23U)) + 15428284250569311285U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 19U)) + 5777369485254032486U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 19U)) + 16813320300717644673U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 27U)) + 16689933050200758251U) + aNonceWordB;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 1856422419049390708U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 11U)) + 18214498743831925517U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18278550878494094923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 797712062039591797U;
            aOrbiterD = RotL64((aOrbiterD * 7212998747080137625U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15854849439012341347U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 996882939768167773U;
            aOrbiterH = RotL64((aOrbiterH * 14936703950807908575U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3005829974130671692U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8793495343509953906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7710453029930631112U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9511995836117707047U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 7250766204781428201U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 670902975693341744U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9045820304668279777U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 18373074917532639027U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12417212387607119470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12816983560669985622U;
            aOrbiterI = RotL64((aOrbiterI * 8406003970221889847U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17245432086377688540U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6806521945548502014U;
            aOrbiterC = RotL64((aOrbiterC * 11335859481858640857U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8947500746292365294U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4468060468522895852U;
            aOrbiterB = RotL64((aOrbiterB * 7022481284816599797U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9892975931958803992U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3042599331526937836U;
            aOrbiterK = RotL64((aOrbiterK * 3308512896171443645U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 48U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 30U) + RotL64(aOrbiterD, 30U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11248U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12258U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11393U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 9379U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aIngress, 13U)) + 15383045568644941552U) + aPhaseCOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 51U)) + 17452811657750910067U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 15660117718455155603U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 47U)) + 10396441207743665753U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + 3708971058200841442U) + aNonceWordD;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 7000673057768598750U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 21U)) + 9886354469011131596U) + aNonceWordC;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 16018065329058043467U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 41U)) + 5024756166109352320U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6587818720728886652U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3652672354944162319U;
            aOrbiterB = RotL64((aOrbiterB * 10807121230791716109U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6307315649915348048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16405347331742979258U;
            aOrbiterG = RotL64((aOrbiterG * 7183142442906743699U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5427299664054601957U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4983381733483185898U;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10182995521328377487U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8694282877540593550U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14614602561910403893U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 4085927978153269932U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6176195962815240877U;
            aOrbiterH = RotL64((aOrbiterH * 16792916528959579875U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6966742100601433005U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9920952446921247521U;
            aOrbiterA = RotL64((aOrbiterA * 1879821050131820933U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11958734477518336014U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2058335903640404380U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 6986170159285417789U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 77366119537297816U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12072894199692855000U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9083781120514635987U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11874297832446385377U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13715562531763053196U;
            aOrbiterJ = RotL64((aOrbiterJ * 12822488258322963187U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 52U) + aOrbiterH) + RotL64(aOrbiterK, 20U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + aNonceWordB) + aPhaseCWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19962U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21070U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22735U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 23146U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 18U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 35U)) + 2225397913940961213U) + aPhaseCOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 57U)) + 8342544893601343643U;
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 162922186381417187U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 12U)) + 11660218373710972210U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 47U)) + 14909034764605802354U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 16776955237009701511U) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 5U)) + 5834487809188925253U) + aPhaseCOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 40U)) + RotL64(aCarry, 57U)) + 1498492772767040320U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 4161765458781579617U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10511923076962447765U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8575954471692620021U;
            aOrbiterC = RotL64((aOrbiterC * 12526744988828982731U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6536325446331340573U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1790628986900286346U;
            aOrbiterJ = RotL64((aOrbiterJ * 5262997114200816715U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2623814807619278590U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11676970995834706612U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 10057461115132434901U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13836786354224256591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6293096163612129260U;
            aOrbiterI = RotL64((aOrbiterI * 8977954126326217153U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4271144764978661248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15938494256992560202U;
            aOrbiterH = RotL64((aOrbiterH * 10004841288382726739U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11038155227307702976U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12408749795071243930U;
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1673665849053496882U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12866353361497103629U;
            aOrbiterB = RotL64((aOrbiterB * 6041125499398924871U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 10673935802381580966U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8946776538955520352U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12293084177712710021U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 16294935203370452805U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4697759331563852212U;
            aOrbiterA = RotL64((aOrbiterA * 14407806317275373043U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 52U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 41U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 18U)) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordF) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterB, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26028U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 32312U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30808U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24908U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 20U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 11177787645248006236U) + aNonceWordN;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 3808340254579817169U;
            aOrbiterA = ((((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 29U)) + 828030667598518279U) + aPhaseCOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererC + RotL64(aCross, 39U)) + 16177835921238398371U) + aNonceWordH;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 35U)) + 5518747735458708741U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 19U)) + 17346319082399995165U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 58U)) + 6397156921893030937U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 47U)) + 15559381654710713582U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 13U)) + 940404446491415088U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8047166032048732645U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4688468645859470491U;
            aOrbiterA = RotL64((aOrbiterA * 14383536431614496369U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3710878044770337260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 116343189456629220U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5637725064169289339U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 883908030159391659U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 18058691521694880482U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3132200449123497619U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17521015077103586117U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3668332225435714918U;
            aOrbiterF = RotL64((aOrbiterF * 12658899101297839881U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12229480388278883300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16206524049491531816U;
            aOrbiterK = RotL64((aOrbiterK * 11122340196620859805U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5743265849441077466U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2812293020719282236U;
            aOrbiterB = RotL64((aOrbiterB * 8903956475200417109U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13718364781538837074U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 861529717259766236U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 17019744777211266685U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4862687502126693872U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7722024283321020761U;
            aOrbiterE = RotL64((aOrbiterE * 18086944039541060829U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8205803118233399853U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15130160926615050422U;
            aOrbiterC = RotL64((aOrbiterC * 1454552751453996765U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordB);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 48U)) + aOrbiterA) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterF) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 60U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAD1EA64F22D04DB9ULL + 0xC5DF355094367B9DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEC340E3A040ED677ULL + 0xDC7C0459401AE392ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x861147F83DC3B99FULL + 0xF04F449E691D488AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C7BF076F8BCCFBFULL + 0xBB1898FCE706328DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBA21FC9848B40595ULL + 0x8A8E4FB3DA41488DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB09D942BDAEA1997ULL + 0xC54CDDEA13D4ADBEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x95176B0C4605B047ULL + 0xE38CB6874E1D16F9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA85F0EB83F6C7C5DULL + 0xA5DED5C4A1706812ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDD8396125E5C1E0BULL + 0xFD6724F52E4F54A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA0C3B1023BE015B9ULL + 0xB803AA4742A3BE8DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDE00A65561C5D761ULL + 0xE3B2335D8529336AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBB9111F2B3C14A77ULL + 0xF9887CF84AAC9947ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8228CBAB927238B9ULL + 0xF1B1E722292CF263ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCEB286E05D874461ULL + 0xB96FF335778192CDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD37A7D6686436D49ULL + 0x86FA6D6A5C53C63BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDE679F0C65DF46D1ULL + 0xC972BC403114D913ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 989U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 2870U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2719U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 578U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 18U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 4739486756133131180U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 3U)) + 16089707555501328184U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 10U)) + 15310047330238536453U) + aNonceWordI;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 7901411596386834955U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 23U)) + 4357555491060982163U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 47U)) + 15667085602825720102U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 8520635334382269253U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 1772509779231068315U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 15336170957886025677U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 30U)) + 8628770833489469980U;
            aOrbiterC = (aWandererH + RotL64(aCross, 39U)) + 15469234024247246228U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10796430900884288328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10660110397012853289U;
            aOrbiterD = RotL64((aOrbiterD * 9140007610912037461U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11202284258711214794U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17509491802893182994U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9329107599972703671U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16212572740740103554U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2190030203761579226U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3101886685668871045U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12014337082293041909U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7100994963061975529U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17837541162838600258U;
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3311518938023146951U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7709505172646831553U;
            aOrbiterF = RotL64((aOrbiterF * 7121143171245765213U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4979968094554018443U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16822214821463034107U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8376124175020587079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11084586282092424876U;
            aOrbiterB = RotL64((aOrbiterB * 5835632742522563537U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7816368455027681621U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10893292019060642422U;
            aOrbiterG = RotL64((aOrbiterG * 3995821210667317677U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13602875505184178486U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5425735673005681983U;
            aOrbiterI = RotL64((aOrbiterI * 12667085597129312079U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5995385043278810987U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4739486756133131180U;
            aOrbiterH = RotL64((aOrbiterH * 15709273328685013399U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterI, 48U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 20U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8464U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 10326U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5486U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 8713U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 22U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 44U)) + 18180797995100240808U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 41U)) + 6585906608223552885U;
            aOrbiterA = (aWandererK + RotL64(aCross, 11U)) + 14088708930575939855U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 13U)) + 468974153311516044U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 39U)) + 12481951025619894110U) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 35U)) + 17227987923860711763U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 51U)) + 4373962756657477139U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 2077576476565420951U) + aNonceWordC;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 19U)) + 17435011300234663764U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 4118039398293246896U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 13724716599855216683U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12391461204689596339U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9900605191533799627U;
            aOrbiterA = RotL64((aOrbiterA * 13553565332531046301U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 972946858824366125U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17247681919694541215U;
            aOrbiterK = RotL64((aOrbiterK * 2974639094630445643U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15442851427306771601U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12650358753454105119U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1483710933373510492U;
            aOrbiterB = RotL64((aOrbiterB * 6531763256577221891U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18065810162229740788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11311677121338794007U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15116367961682119467U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2355285311890287611U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1287783821903407734U;
            aOrbiterE = RotL64((aOrbiterE * 8054011680932255985U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9282654686791135654U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15488608017745542551U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7858866274035085123U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13296835576073421802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7127700236018338741U;
            aOrbiterI = RotL64((aOrbiterI * 11246173563106014149U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1365928843264598789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7777790578813003657U;
            aOrbiterF = RotL64((aOrbiterF * 10121688100505628161U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2104270617375082523U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13363764449819651164U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2685452132715528975U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2008038686059197988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18180797995100240808U;
            aOrbiterD = RotL64((aOrbiterD * 8978998151475372047U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterF, 20U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererG = aWandererG + ((RotL64(aIngress, 6U) + aOrbiterE) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14367U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 12275U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12045U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14424U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 9630214189402543339U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 23U)) + 4072576573737526819U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 48U)) + 15994787452709618869U) + aNonceWordD;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 6403240137132259482U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 39U)) + 10229266900170507720U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 5U)) + 5025294577989748989U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 3U)) + 16696461238217956883U) + aNonceWordE;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 21U)) + 9878318855341719119U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 11U)) + 16086635438116177346U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 28U)) + 12295437783084203730U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 7681150419912842402U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2639104034287637448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12298170009332243573U;
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3485932317267669626U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16569551670038752475U;
            aOrbiterC = RotL64((aOrbiterC * 8139802826402217631U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4448490103784103954U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14510534073046885941U;
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4286195398675733451U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15790355933840266463U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6362891510370156055U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15121822034579983174U;
            aOrbiterK = RotL64((aOrbiterK * 7268045994574844937U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13817341015719915628U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14113474087906143783U;
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9988301252236121106U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11287477288382171758U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4979297247881426383U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9491727010910328644U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7961202721830514030U;
            aOrbiterH = RotL64((aOrbiterH * 16300364540313620767U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10058066852293995222U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 541563830282750968U;
            aOrbiterE = RotL64((aOrbiterE * 1516823517052019845U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7791201128863372861U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8334318157449352359U;
            aOrbiterG = RotL64((aOrbiterG * 2924838607279239375U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6861081455774799715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9630214189402543339U;
            aOrbiterF = RotL64((aOrbiterF * 10837610668580336781U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 24U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterF, 26U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 40U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20681U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21845U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16435U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 21507U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 7948891781097675369U;
            aOrbiterB = (aWandererF + RotL64(aCross, 39U)) + 13928362874228230226U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 27U)) + 10776180542602258926U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 37U)) + 5735115172149470447U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 5353591822981766987U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 562301708107268570U;
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 10467810247578364868U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 53U)) + 14541630141152308564U) + aNonceWordJ;
            aOrbiterG = ((((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 2350076897065139429U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 17519109078651162228U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 34U)) + 6061035173339902910U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15654836633731000065U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13723521735153718904U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14459516479283070563U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2849680038315532197U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17336102435576647923U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7671010488872356142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11485114338165600777U;
            aOrbiterD = RotL64((aOrbiterD * 4162584865462407791U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8759060657343458985U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11009137869375286581U;
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15792999392743144135U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6180808423175992479U;
            aOrbiterA = RotL64((aOrbiterA * 13681230339693676907U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 361487389591183005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15292753806514404853U;
            aOrbiterG = RotL64((aOrbiterG * 17478232597253311153U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14929153438443362045U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterE = RotL64((aOrbiterE * 2484130486635511403U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3793180909904286848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10391957637467171320U;
            aOrbiterJ = RotL64((aOrbiterJ * 505484041943467117U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11648765065563798353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17601185776537566611U;
            aOrbiterH = RotL64((aOrbiterH * 4753179291885740011U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2907499704986356444U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17048858067202291241U;
            aOrbiterB = RotL64((aOrbiterB * 2607549567999666889U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4340465159886930775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7948891781097675369U;
            aOrbiterK = RotL64((aOrbiterK * 12913104720552907335U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 58U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 10U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 46U)) + aOrbiterG) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25069U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24726U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26108U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26148U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 15316464782468770057U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 6642872057476351588U) + aNonceWordN;
            aOrbiterE = (aWandererI + RotL64(aScatter, 18U)) + 660732654689529192U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 57U)) + 7235418086884000655U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 21U)) + 14784518476694580493U) + aNonceWordH;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 3U)) + 12222433977933449375U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 47U)) + 8573001207708329927U;
            aOrbiterG = (aWandererK + RotL64(aCross, 44U)) + 16035256260815013172U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 5U)) + 15767726974121910203U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 35U)) + 17712217935322939971U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 13488963456923357159U) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10222949131965611079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1495561412321657209U;
            aOrbiterE = RotL64((aOrbiterE * 9706305581868526265U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16156530750584361434U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7773792489045606309U;
            aOrbiterB = RotL64((aOrbiterB * 10730624207715601393U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11544578291333360613U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3665587867634242865U;
            aOrbiterG = RotL64((aOrbiterG * 4840528190844842595U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15248434984650998090U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15487979645426567581U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10868107809356766183U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6972347795052712690U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterD = RotL64((aOrbiterD * 1262655238856775853U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16851139687900415292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14630026837021552812U;
            aOrbiterC = RotL64((aOrbiterC * 9577900853521254603U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14236330619137368169U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17778707026111136216U;
            aOrbiterI = RotL64((aOrbiterI * 16239561893843454747U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9390961969105999083U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1174881758316573228U;
            aOrbiterK = RotL64((aOrbiterK * 6602061268277529311U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3025148570039849574U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2813499258480831171U;
            aOrbiterH = RotL64((aOrbiterH * 12272555492688861861U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15397952138592662354U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10394648143430175275U;
            aOrbiterJ = RotL64((aOrbiterJ * 18195627209519212303U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3043205345760158739U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15316464782468770057U;
            aOrbiterF = RotL64((aOrbiterF * 8162506622688910545U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 20U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 50U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 54U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 26U)) + aOrbiterB) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29417U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30875U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32458U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 27516U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 4U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 3621877681473089725U) + aNonceWordO;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 4451752751536414717U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 44U)) + 11371625415377772117U) + aNonceWordK;
            aOrbiterA = (aWandererG + RotL64(aCross, 51U)) + 6046792758881150619U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 21U)) + 8213166120394461682U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + 4343156661140422645U) + aNonceWordP;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + 11105271483234947905U) + aPhaseDOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aCross, 14U)) + RotL64(aCarry, 41U)) + 348904609985341372U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 23U)) + 12924652822526858767U;
            aOrbiterC = (aWandererC + RotL64(aCross, 5U)) + 7461211697358520287U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 16551553555297890558U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11908056404140782995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9147367258259948715U;
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8876461054692728610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10546855952702525404U;
            aOrbiterD = RotL64((aOrbiterD * 10071104785895309677U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4748636139110443794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 783046909529525098U;
            aOrbiterG = RotL64((aOrbiterG * 8969157702460927215U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16683965945838696665U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12385412690177109575U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10795062772707143187U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8210546822184469023U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13146493623236979963U;
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13857628148804187115U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7241297989337473475U;
            aOrbiterI = RotL64((aOrbiterI * 16223448508809614229U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 773904571213804946U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7660676598236419707U;
            aOrbiterC = RotL64((aOrbiterC * 14467390638468925567U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16822672435156055469U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6514707119190640433U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 7097496727567460535U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17784153215885060832U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16027189961519690419U;
            aOrbiterB = RotL64((aOrbiterB * 3248782394761733169U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 821916530432611671U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8764650990196504963U;
            aOrbiterH = RotL64((aOrbiterH * 6269514974278082251U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5987370764866753332U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3621877681473089725U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14763908964222787377U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 24U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 10U)) + aOrbiterK) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + aNonceWordC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 21U));
            aWandererE = aWandererE + ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordI;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x86CEA856344F7845ULL + 0x96DB6336E16F84D6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB24F1091A1C3482FULL + 0xFDDDAF4AFF9BF6D4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9ECB76AD15B03DB1ULL + 0xB631E38FAF90B995ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB2FBAE1C6C0A9CBULL + 0xBF1248ECD11D24DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA317D5E009F594C3ULL + 0xBB873FC5E96D7984ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDBBB2D05E70572B3ULL + 0xC6A8B9B759ECAFABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF8B04D9119EE9CC7ULL + 0xE44BA35074C5CBF3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9F78C719A8FF4905ULL + 0x936C18A6D0FB9C39ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA3046C3273248123ULL + 0x94F021AC28A0766CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF6D29DCCA1990E61ULL + 0x829AF686A2E59740ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB70620229D53C361ULL + 0xBD6630E5C9FF9FA0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB0900BA13218771DULL + 0x940B154C0A71F475ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDB323734DBF10D83ULL + 0x8B00D76981F3D980ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF12CDFB5F955BE0FULL + 0xF9D66E9B1C5C4072ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDACED0CB12978B1BULL + 0xDBFB0DC120771074ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x93E4EE938B37CDE1ULL + 0xD364384DC095C8E8ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4154U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5254U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4935U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 1464U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 19U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 6U)) + 7790166497945719700U) + aNonceWordG;
            aOrbiterF = (aWandererF + RotL64(aIngress, 47U)) + 7136208896846119188U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 41U)) + 12123156943355100886U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 27U)) + 5095546037880875199U) + aNonceWordC;
            aOrbiterD = (aWandererI + RotL64(aCross, 21U)) + 17642705393916765992U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 9918479837334416990U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 4890009823843176466U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 43U)) + 17652590786213674124U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 870002527644696135U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 52U)) + 12545429703552643682U) + aNonceWordN;
            aOrbiterA = (aWandererA + RotL64(aScatter, 23U)) + 5310272867406182581U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3264719049050179440U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 1967241238180278937U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 13004319774269457957U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 773883832927040736U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12766817190261232485U;
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 260069382395598265U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15462103891287350123U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4072032867513289827U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17153061419083897076U;
            aOrbiterH = RotL64((aOrbiterH * 11934532169271718913U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6207264270332656966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18048064697837314947U;
            aOrbiterG = RotL64((aOrbiterG * 13632594619404208489U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14484617445340272026U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16160443600497652026U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1988599349457831597U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5873314228291583482U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16418290052752166515U;
            aOrbiterA = RotL64((aOrbiterA * 18270363452003213317U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9158414409987627714U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8205937960146492168U;
            aOrbiterF = RotL64((aOrbiterF * 14008398661393344261U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16386126219854809263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12418021156683187869U;
            aOrbiterD = RotL64((aOrbiterD * 13897930566207284517U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5427232681451476584U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18237670074497382745U;
            aOrbiterB = RotL64((aOrbiterB * 15528665160297906195U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8330262458028468513U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7790166497945719700U;
            aOrbiterI = RotL64((aOrbiterI * 6001280767763971107U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 52U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + aNonceWordB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 54U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 48U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 26U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10714U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8587U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6674U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10685U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 54U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 16124889768301047791U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 48U)) + 11912338587186717280U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 53U)) + 8594012868813114354U) + aNonceWordJ;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 41U)) + 18281043566156682815U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 21U)) + 16853106130200942302U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 27U)) + 2611212958619673086U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 39U)) + 18039472325066855180U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 14495785571345122046U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 4556063793412832418U;
            aOrbiterA = (aWandererC + RotL64(aCross, 60U)) + 14896419970271244358U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 13U)) + 880028529183500036U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2379557167489415783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11854373946064529806U;
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1487252775956449964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12777924204511625545U;
            aOrbiterJ = RotL64((aOrbiterJ * 1366019527386994789U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15998631485222477969U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8864212892296191613U;
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17069347835763226743U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7443008171694679791U;
            aOrbiterC = RotL64((aOrbiterC * 748894368884566607U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17334256152350782002U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8986626119086556393U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2258172145924120235U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8528180968228358674U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12702290928064582589U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15673603224146737631U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7742438100860023610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3729687240959702198U;
            aOrbiterD = RotL64((aOrbiterD * 3756794766163746783U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 426129097367382096U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16782175452274911213U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1041477289638333659U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5942016166948841079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5260815086125551703U;
            aOrbiterH = RotL64((aOrbiterH * 1603799103692438147U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11732742583346900772U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17182924380693084401U;
            aOrbiterA = RotL64((aOrbiterA * 14858685629471497071U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8539335803784852017U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16124889768301047791U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 6607245691919237755U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 50U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aNonceWordL) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterE, 48U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13859U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 11386U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15110U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11156U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 18U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (((aWandererC + RotL64(aCross, 41U)) + 10038936806177516123U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererE + RotL64(aScatter, 52U)) + 1773168435195292638U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 19U)) + 10655711161526628072U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 39U)) + 14422295664639740437U) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + 4125228715513159576U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 3670449653158650845U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 17553727567180813057U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 5111401772713882743U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 3U)) + 7688573124662314413U) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aCross, 47U)) + 9438375825507814395U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 50U)) + 14177477039902118886U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16329942595859623928U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3990536794006836672U;
            aOrbiterF = RotL64((aOrbiterF * 579024714339065373U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5072881436583180756U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16789727877867289997U;
            aOrbiterA = RotL64((aOrbiterA * 8766246302636197905U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17313956922306689438U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11530878396329822041U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11356860047841383129U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3612616532321160196U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4172189825359187763U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12938945495299393177U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8677279703778052804U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1912172980909479362U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10053289257955474143U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1460085850227494500U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12116763868122868147U;
            aOrbiterK = RotL64((aOrbiterK * 6076945628020280957U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17571840610366424432U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15581362592611080868U;
            aOrbiterJ = RotL64((aOrbiterJ * 1129054058044872003U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14434700039977611666U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4534294602623329152U;
            aOrbiterH = RotL64((aOrbiterH * 5860911553425182045U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 865998255725903702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16407778704555344108U;
            aOrbiterI = RotL64((aOrbiterI * 15571344643129797977U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1948990288894429805U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18218556219056835250U;
            aOrbiterE = RotL64((aOrbiterE * 16574160087642377293U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1309229265173143398U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10038936806177516123U;
            aOrbiterD = RotL64((aOrbiterD * 12954594462760207923U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 21U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + aNonceWordP);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 6U)) + aOrbiterE) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19819U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 21579U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18282U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 18194U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + 9888431329297626900U) + aNonceWordB;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 11U)) + 2937735167534624403U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 51U)) + 17626022970343789617U;
            aOrbiterF = ((((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 5665660859333693743U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererE + RotL64(aIngress, 23U)) + 1060537034632076669U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 13U)) + 743777763907175800U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 4U)) + RotL64(aCarry, 41U)) + 5744905970181808845U;
            aOrbiterB = (aWandererK + RotL64(aCross, 19U)) + 3545351394494002180U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 29U)) + 4877547088414106007U) + aNonceWordI;
            aOrbiterH = ((aWandererF + RotL64(aCross, 27U)) + 11669378338379598445U) + aPhaseEOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 41U)) + 2961072441706158212U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13984945589234919765U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1433097875470903205U;
            aOrbiterC = RotL64((aOrbiterC * 451996840039906781U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 716415411025451152U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8542286150858297810U;
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12932391786479661299U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14005503313299177013U;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9382792812676318046U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5138554251079724724U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6386016499265056247U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8522380066269546172U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11825536408101906458U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 17042837108792016849U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15504062350899452495U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1219010998820336744U;
            aOrbiterD = RotL64((aOrbiterD * 10650635772711590803U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6442717843380349632U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1047843426279085117U;
            aOrbiterH = RotL64((aOrbiterH * 4074561571072878005U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10611039527108679173U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5092816736177358221U;
            aOrbiterJ = RotL64((aOrbiterJ * 14342779343820140833U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12327496881352988530U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6405703847824845457U;
            aOrbiterE = RotL64((aOrbiterE * 12094143526751620113U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8906613392335197542U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5962698890029858689U;
            aOrbiterA = RotL64((aOrbiterA * 9136193803330500489U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2610083915800734277U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9888431329297626900U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3794133356691218671U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 36U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 38U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22534U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24241U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23484U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 22536U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 16922357079016918108U) + aNonceWordL;
            aOrbiterH = (aWandererE + RotL64(aScatter, 13U)) + 11771749797137599131U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 4635668433708036077U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 20U)) + 15827952719230577008U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 51U)) + 1495675306110023086U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 35U)) + 7294835466949728365U) + aNonceWordB;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 47U)) + 179122461212041978U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 545981421632236251U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 56U)) + 15338259639814630535U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 29U)) + 12924313840290895215U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + 17846785921286020610U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5721472794107057875U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16359630793856870319U;
            aOrbiterK = RotL64((aOrbiterK * 14186771515526698907U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10614102110239037308U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16421992251278236531U;
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8668149834861244963U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12699331834360948734U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2249360824172616357U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4470693178142950471U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 526000656022724741U;
            aOrbiterD = RotL64((aOrbiterD * 16688501462334673493U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6880246132270094141U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7126466778855297013U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 5692237926830293205U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6436404501390442054U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1213633065612242699U;
            aOrbiterC = RotL64((aOrbiterC * 17604454985534439259U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8186529105901185854U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10607460957358250935U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17172191011625677861U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9743278964993305169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14007577681873418075U;
            aOrbiterJ = RotL64((aOrbiterJ * 4231122580398039133U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11636165671710638530U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9334375905020670988U;
            aOrbiterI = RotL64((aOrbiterI * 8801600439900803907U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4261340110915336428U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12336921031446129288U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2306768964600968743U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2029125959974424325U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16922357079016918108U;
            aOrbiterE = RotL64((aOrbiterE * 8718484611517064455U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterE, 36U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 14U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27669U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29048U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30922U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 31793U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 19U)) + 6163290588946759209U) + aNonceWordH;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 7342672468560105447U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 57U)) + 11574563167017282321U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 2254820206194758964U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 14U)) + 1469783447473099498U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 11U)) + 14174828900676165088U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 16277954291890598132U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 23U)) + 14845750668693136766U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 38U)) + 150099699692047766U) + aNonceWordN;
            aOrbiterG = (aWandererG + RotL64(aScatter, 53U)) + 1200784917165131703U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 5U)) + 9469982764806754302U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10956702761701710182U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7915506894975487807U;
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17335794183733623213U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 557028996286989506U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 3993359298602424281U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1597385667771002414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4376417959915162639U;
            aOrbiterE = RotL64((aOrbiterE * 4626236858205178149U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 549770198518993876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 756554555648070919U;
            aOrbiterJ = RotL64((aOrbiterJ * 16272320259614325355U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7298557532533152193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3336802611342112013U;
            aOrbiterK = RotL64((aOrbiterK * 14679103452120080499U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2314938232094714365U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12215066333571149153U;
            aOrbiterB = RotL64((aOrbiterB * 10747052773052630601U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7762752719356805046U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6519429915769040078U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15548676502167938513U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7556691736109752918U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13731245903412646404U;
            aOrbiterC = RotL64((aOrbiterC * 15581965016668635409U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5910925625723735162U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16037704866415841869U;
            aOrbiterH = RotL64((aOrbiterH * 11628217027073824759U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12605882248192797360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9579778913978981884U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 5372577227818787957U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6063171520266734946U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6163290588946759209U;
            aOrbiterD = RotL64((aOrbiterD * 291843698316138251U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 60U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 14U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE391F9AA81974EF9ULL + 0xB4F8D481CDC3CDBEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x800F80E4BC0C66ABULL + 0xA89DDA136C3516B3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD122A2755AC08CC1ULL + 0xBEB617FB225FDCB0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8F0967EE189B613BULL + 0xCBB823426720AB1DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE0B2C9F8750947D5ULL + 0xC8CA7F8696E703FDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCB725D6EB83A3CAFULL + 0xE6762CDA86B2D00FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD7427BA62FC63D81ULL + 0xA1D053F9EE3612A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCDD74D7E4A91CA35ULL + 0xC997B7EF8D29ECB5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9345A12B66D17529ULL + 0xFB39D342D33B4BB1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9B6CEF3BC22C9085ULL + 0x9441A099693E7038ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE9D46312C59207F7ULL + 0x950C42F0748370D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD91FB871273260DDULL + 0x82215EBAE8595040ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF298CCD660F6DBA9ULL + 0xEBED4DE02AEDF367ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB0BCE63CB51DDBC7ULL + 0x8E07CA3FF909D11BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF350ABC1C232E0D7ULL + 0xE09970EEC88A9E9AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBC1053A291640103ULL + 0xFE4DBDD317BC8322ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2760U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 4728U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2778U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 4693U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 8375305456876489425U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 23U)) + 16193562952772453047U) + aNonceWordL;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 18088652458594816223U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 767344788620249944U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 60U)) + 7705194930396368752U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 5U)) + 3829736891311272834U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 41U)) + 9881681671347640061U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 19U)) + 1721196560190164264U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 11U)) + 3002652618388454213U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 54U)) + 9811621464004005202U) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 51U)) + 5652598941069986530U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6250499348327316328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16025054277615264530U;
            aOrbiterE = RotL64((aOrbiterE * 16446892258704281903U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13800298546867243172U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12256104592865905782U;
            aOrbiterF = RotL64((aOrbiterF * 16983140179497142713U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17817225416918329229U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17738671327352776217U;
            aOrbiterB = RotL64((aOrbiterB * 393488251327705063U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6816031224188400541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16989563985059237014U;
            aOrbiterG = RotL64((aOrbiterG * 8677884225771717797U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16891524847268207549U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1833508573940405571U;
            aOrbiterH = RotL64((aOrbiterH * 9709196587703979539U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12729999421507068973U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6839758643521968957U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 16350557395881283975U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8524167125469267428U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14741523560290472617U;
            aOrbiterA = RotL64((aOrbiterA * 4367850822282205897U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10983798459868424892U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5649250846622078964U;
            aOrbiterJ = RotL64((aOrbiterJ * 7149612714806023987U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8587302028325090061U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17457129226030333666U;
            aOrbiterC = RotL64((aOrbiterC * 18107356450566915215U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15600113588474915690U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6595247491374683783U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1432432381540098765U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13246325856585534283U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8375305456876489425U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8331406038795786099U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6739U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7776U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7868U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 8586U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aScatter, 27U)) + 1898718075389870739U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 27U)) + 5631794889237247403U) + aNonceWordO;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 13U)) + 18219714659484524607U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 15419581386225732921U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 51U)) + 9125575431710198210U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 12205871520544965505U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 57U)) + 7617534300497343422U;
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 18017579105368135814U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 6U)) + 10693882161946020042U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 37U)) + 11669615701700895306U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 41U)) + 11045110212889232165U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18019107802806469913U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12315940560472528716U;
            aOrbiterJ = RotL64((aOrbiterJ * 4505122470351404065U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4899009736070044310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17412253404253730364U;
            aOrbiterE = RotL64((aOrbiterE * 10791901166391946485U), 41U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 4826286251927854181U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4523455921321845084U;
            aOrbiterB = RotL64((aOrbiterB * 14534103906736598099U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4132514462154182215U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7164745605985109269U;
            aOrbiterH = RotL64((aOrbiterH * 14107325508977225261U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6297434295807635654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8813887638672996646U;
            aOrbiterG = RotL64((aOrbiterG * 17495632530773158201U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11086381278955626084U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5660733992573928887U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11248164458720777889U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14851044686208609882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12707776386060264479U;
            aOrbiterK = RotL64((aOrbiterK * 4470919091467313071U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11508023384209716657U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11752973809740920034U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10212754472298834769U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16746821150860017820U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9659421716296641396U;
            aOrbiterF = RotL64((aOrbiterF * 7530071874978553673U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3192309064305104593U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11409078048681398061U;
            aOrbiterC = RotL64((aOrbiterC * 14991409124701807765U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 315359495275427324U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1898718075389870739U;
            aOrbiterI = RotL64((aOrbiterI * 13126661894614781343U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 14U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterK, 52U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11080U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14398U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13371U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 15363U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 6U)) + 12669015908335980355U;
            aOrbiterH = (aWandererB + RotL64(aCross, 23U)) + 5438715179868613192U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 13172104448184536460U;
            aOrbiterA = ((((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 13421421503244744803U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererD + RotL64(aCross, 3U)) + 13327113302994856582U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 48U)) + 4671768205922454413U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 35U)) + 5355759962838579929U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 6691720614265406851U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 37U)) + 7063906424700911378U) + aNonceWordD;
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 17328616394166672263U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 57U)) + 1542940602574207068U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7203866278803132454U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 993485696233139264U;
            aOrbiterJ = RotL64((aOrbiterJ * 11609009908810366447U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15659679028507488331U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18321361454094675842U;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9633319822696783352U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3496559332232402963U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1918349708324205526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7701088402761359134U;
            aOrbiterD = RotL64((aOrbiterD * 9649485438465644795U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6006824348814439686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18088375375347012557U;
            aOrbiterK = RotL64((aOrbiterK * 12801082943086128385U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12816533373478543584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17951880253818836433U;
            aOrbiterC = RotL64((aOrbiterC * 8935839101517220201U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11311632024372748238U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9891349164779752351U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 11405973752233193209U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 711130292000437038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17818800917771709681U;
            aOrbiterA = RotL64((aOrbiterA * 10567029732245868263U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10188714200240109442U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9745615081760948652U;
            aOrbiterI = RotL64((aOrbiterI * 9321909462220134035U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6508703788527163965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7536038073603467381U;
            aOrbiterG = RotL64((aOrbiterG * 12015514242701199813U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2793951597846756844U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12669015908335980355U;
            aOrbiterB = RotL64((aOrbiterB * 7355285540199760689U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 42U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 22U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 44U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21154U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 20194U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17370U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 18732U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 57U)) + 14249093584376402677U) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 14U)) + 8756965951816492264U) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 27U)) + 11221139480258176330U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 11U)) + 17218894445564194851U;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 8064642692524949490U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 5822093203710704646U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 21U)) + 3217799620158102238U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 29U)) + 2613757677892120843U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 50U)) + 13647481499551657237U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 3545714196663685016U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 9735422670576621521U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3911046580637583767U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9315984027042049203U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12568550776487242469U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8926367674641729058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10748158733051120339U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2467801787989056455U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 12621934274702358977U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9244415080474351390U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8517784887959492079U;
            aOrbiterA = RotL64((aOrbiterA * 17022899813765884147U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8409307332803038455U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11043806021873232950U;
            aOrbiterH = RotL64((aOrbiterH * 8294888329708842989U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17512395828450251457U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16849067939795823992U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 9361991804481514337U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17541946638063238056U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11430501673960586718U;
            aOrbiterJ = RotL64((aOrbiterJ * 15074409630605450091U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 78307505705383302U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4834528975263832983U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17245673681686752861U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9647985402149698269U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6610247710757518931U;
            aOrbiterF = RotL64((aOrbiterF * 8672486173272686859U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2706696306041774372U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9519896513600816252U;
            aOrbiterD = RotL64((aOrbiterD * 7468605169665549731U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14647351223431646222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14249093584376402677U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8296105266618697281U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 38U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aNonceWordG);
            aWandererD = aWandererD + ((RotL64(aIngress, 20U) + aOrbiterF) + RotL64(aOrbiterB, 46U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21898U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23174U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23472U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26701U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 14U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 27U)) + 8866844335448071821U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 13U)) + 15159698739856430085U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 20U)) + RotL64(aCarry, 37U)) + 9582805772989594633U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 11U)) + 1438538239931588373U) + aNonceWordD;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 39U)) + 10862044156620436139U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 3U)) + 13682173320058164615U) + aNonceWordH;
            aOrbiterD = (aWandererG + RotL64(aCross, 44U)) + 8351013291045977592U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 15777857431516633916U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 37U)) + 16178966745333885377U) + aNonceWordN;
            aOrbiterI = (aWandererK + RotL64(aCross, 5U)) + 9031889187993001617U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 6308472367425865347U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 642109145903321046U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9186268569255318035U;
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6091345356803675860U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13218507921880873749U;
            aOrbiterF = RotL64((aOrbiterF * 15415157927185637717U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4266652275234474616U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4391422098164506195U;
            aOrbiterE = RotL64((aOrbiterE * 17634679403195085867U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5160682323243635577U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10351728852161347404U;
            aOrbiterI = RotL64((aOrbiterI * 11105410036471745951U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3950932176454814023U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9536466386833427441U;
            aOrbiterJ = RotL64((aOrbiterJ * 18064984243491293435U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9927425919978776529U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6819384090527481081U;
            aOrbiterG = RotL64((aOrbiterG * 18032965969184368561U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1646274931424218507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16166524473976135097U;
            aOrbiterD = RotL64((aOrbiterD * 11672192658072663849U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11252501968059485262U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16847854447987609067U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 6326299154627028295U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16723218285355036446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13870211254243048975U;
            aOrbiterA = RotL64((aOrbiterA * 10203222183774624097U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11401147367366049493U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4266628469244269926U;
            aOrbiterC = RotL64((aOrbiterC * 2409934496621365221U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11578385782347296942U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8866844335448071821U;
            aOrbiterH = RotL64((aOrbiterH * 6456956795450036515U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 18U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 20U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29712U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 31349U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29971U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31867U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 28U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 35U)) + 2974056819475622600U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 51U)) + 7345051759236356098U;
            aOrbiterA = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 12738468816846628882U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererF + RotL64(aScatter, 13U)) + 7694520596043297922U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 5530753590015084774U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 19U)) + 3776309161718383105U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 41U)) + 784780304358106404U) + aNonceWordN;
            aOrbiterE = (aWandererK + RotL64(aIngress, 53U)) + 8999942326995036509U;
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 5194986506064092779U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 27U)) + 7920040007459652762U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 20U)) + 11311997270710107937U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5365231114813547251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8630110234623825263U;
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2358235238039571072U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18059414891616491807U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14526050556461782864U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6937282036603272474U;
            aOrbiterH = RotL64((aOrbiterH * 14954512365270028029U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10105832250694931310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3884223553012098137U;
            aOrbiterF = RotL64((aOrbiterF * 16340956813003906195U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10385284339549648087U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1257633893341505930U;
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5528890519572824318U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15664241747527713256U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 16670884497088220497U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14264122979415331887U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17985061405540198036U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2729487440173395133U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1663986734997903415U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3706166884286400587U;
            aOrbiterB = RotL64((aOrbiterB * 10549736618301955745U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12736963182099961466U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 95411267612114381U;
            aOrbiterI = RotL64((aOrbiterI * 8011937916302325057U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4966620136499917388U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8478316876240452401U;
            aOrbiterJ = RotL64((aOrbiterJ * 13297718919105366563U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11123814701411614557U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2974056819475622600U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5913569942407618997U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 56U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterE, 58U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 29U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 18U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordC);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC107E141332A9537ULL + 0x9C565E722C8305C0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD67B977DEECF6C15ULL + 0xD0EDD87D395E9FE0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8A968EF56144BF89ULL + 0xAFF7983D174F6AFBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF4ABB091255C0CF1ULL + 0x86E60C69C1167D3BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9C9D476D5704B9DFULL + 0x91045755E093F4A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8141CAA4E5031E21ULL + 0x837D79E3B85CB087ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF6900476BFFC7FBBULL + 0x969F22D53EA072F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC3E74DDA96A30191ULL + 0xF49B649120250476ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAEA08B7015CCCB99ULL + 0xB686CA22CC0C0BDBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD8CB73C497B5AEE3ULL + 0xF292A6D5ADE8F9A5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB0CF40C855CD8CF5ULL + 0xFD803DC6A88887C1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD4E5414CB4510EEBULL + 0x837C23F53FCBAA5BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEAC7A16ADE48CA7BULL + 0xB026E85319EA7780ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE9675022378450F1ULL + 0xEAE0AC05A8F546F1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBFDE86019AACFE8FULL + 0xBFCE4822049B59AAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFC960EBCE0F7CB37ULL + 0xD981BEA57350D808ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1720U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 5045U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 297U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1648U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 16802219662864902427U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 41U)) + 14332033461409490629U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 57U)) + 8781794298640286845U) + aNonceWordO;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 44U)) + RotL64(aCarry, 27U)) + 8459933908074937264U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 39U)) + 1883580287986004426U;
            aOrbiterG = (aWandererB + RotL64(aCross, 53U)) + 17500258188004626118U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 3U)) + 7934811305150872870U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 6380363892361098905U;
            aOrbiterA = (aWandererK + RotL64(aCross, 35U)) + 12623079132626676910U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 6U)) + 10455208121949202703U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 8805532707916767629U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9161544391400377699U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3501434325829663268U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7933545151293799637U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 651783304096081996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 441505031509930622U;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1771159983581326424U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15227946417377695989U;
            aOrbiterB = RotL64((aOrbiterB * 1563141188972797601U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4153717524193279095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4404521756523902829U;
            aOrbiterH = RotL64((aOrbiterH * 1410342912973206203U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6231945075461813285U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3864780227164426690U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 18031353247480673617U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1509699687948576558U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17316114302489411191U;
            aOrbiterA = RotL64((aOrbiterA * 15490661284980281585U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2250572827340157410U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6403966113144372915U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 726441947009132383U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2329903609147403156U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2486330017319455238U;
            aOrbiterE = RotL64((aOrbiterE * 17427461345935191757U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9333421733051210144U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14779925626161889533U;
            aOrbiterJ = RotL64((aOrbiterJ * 9120486933147706541U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4343688173541745311U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12686722305368397686U;
            aOrbiterC = RotL64((aOrbiterC * 17484250022537912537U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3745163111502795473U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16802219662864902427U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 4343730534036919417U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 40U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 39U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 20U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterH, 4U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9541U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 9905U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10376U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10258U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 8975885703279267062U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 60U)) + 8664844915562660637U) + aNonceWordI;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 39U)) + 12281774799736296726U) + aNonceWordC;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 47U)) + 15347461352311329726U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 35U)) + 12967500561828907834U;
            aOrbiterG = (aWandererH + RotL64(aCross, 13U)) + 5002833859280402726U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 11908257536954668983U) + aNonceWordO;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 19U)) + 17017174811949227162U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 53U)) + 16851323125613931180U;
            aOrbiterB = (aWandererB + RotL64(aCross, 41U)) + 13469326957728686706U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 5228638551056105241U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11945166198089308564U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14781204627695095701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5365325354838101092U;
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 563147416025715953U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14660867395395625851U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 4769458126865307103U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3168989056355712105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16179131669773665579U;
            aOrbiterD = RotL64((aOrbiterD * 5641461617066671723U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4160220074225527179U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8597134686962559111U;
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16811551552456811661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5827323970423386301U;
            aOrbiterE = RotL64((aOrbiterE * 9328247349730652021U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15583234353262170227U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2950816254621717748U;
            aOrbiterF = RotL64((aOrbiterF * 1102417597476170143U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4426165025104306337U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11871220132164971152U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2366168050042802207U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3832424136113939717U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17673885217916768611U;
            aOrbiterI = RotL64((aOrbiterI * 10887063696370811871U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3479289844909914390U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9498461576098567546U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8734492074299676555U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10645314291190544864U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8975885703279267062U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16584086014947250551U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 52U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 30U)) + aOrbiterH) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 44U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15787U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 13189U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13672U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 16019U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 54U)) + 10336802574069791273U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 13U)) + 169025388197058936U;
            aOrbiterK = (aWandererC + RotL64(aCross, 5U)) + 6541354188379168846U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 3U)) + 16223920526599306104U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 12756613707692514808U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 5082475548176484035U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 4907435526952698526U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 14236627073831834337U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 26U)) + 11502511046130497584U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 21U)) + 3679044835550219497U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 41U)) + 11254838916686736746U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10582608424233200966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10449735026385340313U;
            aOrbiterK = RotL64((aOrbiterK * 7363770199734997411U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4628253464169957835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterA = RotL64((aOrbiterA * 4234720298731378527U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3798386391743884889U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1379331161819246587U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9816600392407327227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16781971616348376878U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7909676419643119585U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 256053568910383007U;
            aOrbiterI = RotL64((aOrbiterI * 11965085163352053161U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16179914439220412472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3968867762761955845U;
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7474832923901283742U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 596484364660389193U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13822222274464306169U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1723502278319885511U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16307920280681985443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3505106171801702915U;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4987142580981135150U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10336802574069791273U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 2670706512498539705U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 22U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 30U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 54U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19843U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 17841U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16774U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 20293U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 37U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 22U)) + 16462052553719977502U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + 12337064059566619581U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 15801005007094515447U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 8228706742665081656U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 41U)) + 11006723027845190869U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 18173765337829177450U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 11U)) + 530215083653542558U) + aNonceWordI;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 27U)) + 6608611827035564511U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 2246051826221626809U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 29U)) + 5228575308895381421U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 38U)) + 10999213210689606857U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11150566414723818350U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8336366151003049546U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9033771197242493699U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13233968794237090787U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8172558473508478819U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 17837070423649268435U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 133564480283347997U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15104810248883567064U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 706802420642303533U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9138629520201127075U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13993086066341664080U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 4875046427147105077U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6547273508580516932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9838727018769865759U;
            aOrbiterI = RotL64((aOrbiterI * 11395273371936839815U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11685694999526122626U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8945983172566303116U;
            aOrbiterG = RotL64((aOrbiterG * 17791527981004597623U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17606249889617356327U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9296903152000480008U;
            aOrbiterK = RotL64((aOrbiterK * 18066622289408024413U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14248192861977167583U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5467843420970464193U;
            aOrbiterF = RotL64((aOrbiterF * 10121398470914323221U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17072313558131700643U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7932446176598954438U;
            aOrbiterD = RotL64((aOrbiterD * 11684711939539349335U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15377107166135929052U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16462052553719977502U;
            aOrbiterA = RotL64((aOrbiterA * 9057188521274832217U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterK, 42U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterE, 22U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22912U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26881U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24496U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 24975U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 28U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + 12131317914288566437U) + aNonceWordL;
            aOrbiterF = (aWandererF + RotL64(aIngress, 3U)) + 5672805657999385496U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 3581710244233124197U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 15251296040538489436U;
            aOrbiterI = ((((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 37U)) + 11295008604679904153U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 27U)) + 2230897493419504490U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 43U)) + 7109600123297458999U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 13U)) + 13119156643107683803U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 29U)) + 14755160867807355250U) + aNonceWordI;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 16829363373287496832U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 20U)) + 16981122946707720883U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8806000776958603317U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16810923047720876014U;
            aOrbiterH = RotL64((aOrbiterH * 17872735050219539145U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8129657889554436328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8653100378491974463U;
            aOrbiterG = RotL64((aOrbiterG * 11395283153912468661U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17048985838727432415U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10892675550889823573U;
            aOrbiterB = RotL64((aOrbiterB * 976298937314081913U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15960158965421254346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12290011578634850001U;
            aOrbiterA = RotL64((aOrbiterA * 9280475585104357745U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16265047040311479093U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10312956912303656248U;
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 16706890352221352779U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10630955894218491929U;
            aOrbiterK = RotL64((aOrbiterK * 12675937483456206355U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4009352551041162434U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3043810773683888556U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4328135390387997315U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1398071019814944785U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16689766557488135301U;
            aOrbiterC = RotL64((aOrbiterC * 8403881916549404871U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15934647144489136524U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13521276033614992223U;
            aOrbiterD = RotL64((aOrbiterD * 18003640895553609933U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4281211055727414100U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11848150507497406421U;
            aOrbiterF = RotL64((aOrbiterF * 1107789990317433481U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12022829841608199449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12131317914288566437U;
            aOrbiterI = RotL64((aOrbiterI * 13275753083882829973U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 14U)) + aOrbiterK) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 46U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30425U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 29621U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29903U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31318U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 9774364261626083532U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 37U)) + 18059001521926116420U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 18U)) + 10615626210406381148U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 53U)) + 10536484278007898620U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 47U)) + 13320663045139972700U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 29U)) + 17127001787268166583U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 16742574590844166551U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + 8347719720758228053U) + aNonceWordC;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 13502468705946051986U;
            aOrbiterI = (aWandererB + RotL64(aCross, 13U)) + 3512687886188904904U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 26U)) + 495660316165795934U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5092722552034477356U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15641128019608284015U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 3621036395703527059U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15421873776811085458U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17978775513204574125U;
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16617179197537669849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1931805387534012528U;
            aOrbiterD = RotL64((aOrbiterD * 3400139345857733775U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9544923119559308431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12930999400470173353U;
            aOrbiterA = RotL64((aOrbiterA * 16791006919271490005U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13673733276226249890U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2032263473309124738U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3088728329261360607U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14868502349358414206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10116495537187552321U;
            aOrbiterK = RotL64((aOrbiterK * 1380512121796709469U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5341113995358179244U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8415417980279705731U;
            aOrbiterI = RotL64((aOrbiterI * 8521501372683793821U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2462819265072352463U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7657062767608441931U;
            aOrbiterG = RotL64((aOrbiterG * 15554638801273540163U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8153420530633265789U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10990681417675210534U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1928509513380702895U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17035995983178569271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2806563871848226777U;
            aOrbiterH = RotL64((aOrbiterH * 4137935663733587867U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6570698907081812011U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9774364261626083532U;
            aOrbiterJ = RotL64((aOrbiterJ * 1766375419340392741U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterF, 26U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aNonceWordL) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 48U));
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7289U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 45U)) & W_KEY1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4859U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 951U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCross, 10U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 51U)) + 13296600294247799698U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 37U)) + 5818503518080877515U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 6735784238734173597U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 56U)) + 7368398209488856201U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 29U)) + 961734029066455638U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 797011946660892011U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + 12841876018396622350U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 16213253970483895623U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 60U)) + 15186950557113470375U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5117930310827477341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12265429373166094162U;
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13920531346698601568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14695405206998211456U;
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7851960904825938443U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9501511171732550190U;
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5663365182245722077U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9607860124321315555U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3461820361914280601U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18171052650586819280U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3442698321538580861U;
            aOrbiterG = RotL64((aOrbiterG * 6317525514963824829U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1491052813469258970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3956599824067616133U;
            aOrbiterB = RotL64((aOrbiterB * 2928600779267623085U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10963841237346073453U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2303020125591252534U;
            aOrbiterF = RotL64((aOrbiterF * 9969099842343321981U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14503856057958162356U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11147548150090597694U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11856382308792700441U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 36U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 52U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 48U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8914U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 15488U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15087U)) & W_KEY1], 50U) ^ RotL64(aKeyRowReadB[((aIndex + 14034U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 38U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 22U)) + 15316464782468770057U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 6642872057476351588U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 51U)) + 660732654689529192U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 7235418086884000655U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + 14784518476694580493U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 12222433977933449375U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 8573001207708329927U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 10U)) + 16035256260815013172U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 15767726974121910203U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17712217935322939971U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13488963456923357159U;
            aOrbiterI = RotL64((aOrbiterI * 16785285630840310405U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10222949131965611079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1495561412321657209U;
            aOrbiterG = RotL64((aOrbiterG * 9706305581868526265U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16156530750584361434U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7773792489045606309U;
            aOrbiterD = RotL64((aOrbiterD * 10730624207715601393U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11544578291333360613U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3665587867634242865U;
            aOrbiterK = RotL64((aOrbiterK * 4840528190844842595U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15248434984650998090U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15487979645426567581U;
            aOrbiterA = RotL64((aOrbiterA * 10868107809356766183U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6972347795052712690U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16074994810010431338U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1262655238856775853U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16851139687900415292U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14630026837021552812U;
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14236330619137368169U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17778707026111136216U;
            aOrbiterF = RotL64((aOrbiterF * 16239561893843454747U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9390961969105999083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1174881758316573228U;
            aOrbiterB = RotL64((aOrbiterB * 6602061268277529311U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 28U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterE, 19U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterE, 34U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23172U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20145U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20227U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19341U)) & W_KEY1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 13333509828310369865U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 14U)) + 7645352517103840797U) + aPhaseCOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 5310766306660062655U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 5165635069832352932U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 15684141764734281849U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 10U)) + 3327963374225061738U;
            aOrbiterK = (aWandererF + RotL64(aCross, 47U)) + 8625811794878848871U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 37U)) + 7598657468430485291U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 53U)) + 2881171216276746485U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10237691227222918101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6419254255884834497U;
            aOrbiterG = RotL64((aOrbiterG * 3816625473642865305U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4238455444646479956U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14936613353493061492U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3544216916806292273U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15324699725208372627U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3709149613660215641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1724290199312754307U;
            aOrbiterI = RotL64((aOrbiterI * 12597580418257897965U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13191172833570139194U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3686087945377837886U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10418330386245397022U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5383531313632347245U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2987755379396160073U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7414716553072652212U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11301761123966206201U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1546727321088592187U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8570229732236388847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8773754460060264773U;
            aOrbiterB = RotL64((aOrbiterB * 3251360788932563495U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13636929800504199371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5486599841558573720U;
            aOrbiterE = RotL64((aOrbiterE * 2867914211589815153U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterK, 6U)) + aPhaseCWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterA, 14U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 54U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28766U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30509U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27522U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27773U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aCross, 13U)) + 15910560457440369082U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 17953072986407436888U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 41U)) + 15446940721193538669U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 35U)) + 3020785262774422009U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 7001288645424994404U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 13385250665458462689U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 4841895644623005949U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 28U)) + 13053476783239482065U) + aPhaseCOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + 641996979335975244U) + aPhaseCOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16211238020928688299U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12715448751323279480U;
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9035070625716345139U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6085848172494001945U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1177103851507561053U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2281901691017816407U;
            aOrbiterH = RotL64((aOrbiterH * 3142197009403602497U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9040984343694325070U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13334258224023902365U;
            aOrbiterG = RotL64((aOrbiterG * 4782523727707164869U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1079824790138592518U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14024082692012948652U;
            aOrbiterB = RotL64((aOrbiterB * 3219489374333737903U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2966776524421278970U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5510281854029308547U;
            aOrbiterJ = RotL64((aOrbiterJ * 9275402927591867297U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7126632329316720048U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1476827035602733472U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6470212302133184965U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4172257438373147415U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4449314239630366533U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 30U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterD, 24U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3202U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1800U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2179U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 3845U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aScatter, 21U)) + 6654158889644956636U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 40U)) + 9045779659363991870U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 3888897662136993491U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 6882016842864459345U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 15601891715956172291U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5176811598629335350U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12519945150889074325U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8721098129033306427U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4552583214397603278U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14225482701804864688U;
            aOrbiterJ = RotL64((aOrbiterJ * 8526052833180466359U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5485298070606280363U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11237713257388094289U;
            aOrbiterE = RotL64((aOrbiterE * 11032429223099413011U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14340345895626142788U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16275167270553643347U;
            aOrbiterB = RotL64((aOrbiterB * 7308578867128951199U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14041860597556520250U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1436068974197066343U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3938460345031496843U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterB, 52U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14725U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15680U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11040U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 8202U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 26U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 37U)) + 8402620908307642697U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 11347672014525086047U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 20U)) + 2816462912503401876U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 6940159795470696093U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 9134692490095883851U) + aPhaseDOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4999455497008026526U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5992451460350651332U;
            aOrbiterH = RotL64((aOrbiterH * 12796550245322491401U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3417087346651371924U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3612773820086198270U;
            aOrbiterI = RotL64((aOrbiterI * 5519856345435871169U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 463398077083428570U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11249391303705089012U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7106735772303292983U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17027535139825739501U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 568131384979596481U;
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4793712537158004047U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10415170179135963622U;
            aOrbiterK = RotL64((aOrbiterK * 13729564030210361415U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterB, 60U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21807U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19595U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19119U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 22928U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 4634399531433127141U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 16961792729406903200U) + aPhaseDOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 4105280732301137738U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 15692013501147331191U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 54U)) + 1252216715968780587U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7958289043012473752U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6611577301818896615U;
            aOrbiterA = RotL64((aOrbiterA * 2757493607265637973U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8506226754305949140U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3648813120449403353U;
            aOrbiterI = RotL64((aOrbiterI * 9521367946879238849U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5195245426245535735U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 542948051600803051U;
            aOrbiterB = RotL64((aOrbiterB * 4631106308856448475U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11974253551208964789U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10596463592332655367U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10941161258815714641U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12015129484061440159U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8254944355710109060U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3233697992479357615U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 50U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 14U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26901U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31368U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25147U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26460U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 3238389262925516513U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 12381787182611386995U;
            aOrbiterB = (aWandererD + RotL64(aCross, 38U)) + 7883885539305181549U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 1185413044597727092U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 15219353497204773135U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7533774715626734082U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2599930450937763464U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13207380361960949159U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16074720663961214284U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15483613196360051221U;
            aOrbiterE = RotL64((aOrbiterE * 11717479088020532861U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9396557867081376268U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9668459976852660245U;
            aOrbiterD = RotL64((aOrbiterD * 11748505665890567063U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9037269914643207212U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16936742640861088240U;
            aOrbiterC = RotL64((aOrbiterC * 1040172193161012227U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16481274825758546398U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 60U));
            aWandererK = aWandererK + ((((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3424U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 253U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 663U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5050U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 35U)) + 13924571355038625040U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 21U)) + 16328300979357156658U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 3947771961206012461U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 15428284250569311285U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 5777369485254032486U;
            aOrbiterB = (aWandererE + RotL64(aCross, 41U)) + 16813320300717644673U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 16689933050200758251U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1856422419049390708U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18214498743831925517U;
            aOrbiterF = RotL64((aOrbiterF * 10744120577560529379U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18278550878494094923U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 797712062039591797U;
            aOrbiterI = RotL64((aOrbiterI * 7212998747080137625U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15854849439012341347U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3005829974130671692U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8793495343509953906U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7710453029930631112U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9511995836117707047U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7250766204781428201U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 670902975693341744U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9045820304668279777U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18373074917532639027U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12417212387607119470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12816983560669985622U;
            aOrbiterE = RotL64((aOrbiterE * 8406003970221889847U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterC, 48U));
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14503U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14007U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11301U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((aIndex + 11921U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 3U)) + 6973892330986118220U;
            aOrbiterH = (aWandererD + RotL64(aCross, 41U)) + 9886813896272094864U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 10996306582517553173U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 8490648283899856223U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 13U)) + 105141713530704655U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 3114337422810562588U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 19U)) + 980857684690886131U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6562042345807072665U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15665371138706353619U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8086237578564620623U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18113013571374375028U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17405346422601997299U;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5130876096426182506U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1813821672299154629U;
            aOrbiterG = RotL64((aOrbiterG * 15478100342425611875U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15793814882743306728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9924458846049579438U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7810034662781768090U;
            aOrbiterK = RotL64((aOrbiterK * 10310594595026622513U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12812586478656872854U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5709576448057435237U;
            aOrbiterD = RotL64((aOrbiterD * 9101555233909853025U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7839807649914541516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4717944526755429647U;
            aOrbiterA = RotL64((aOrbiterA * 8515229146471335721U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterK, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 4U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17391U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22355U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23327U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((aIndex + 22045U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 38U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 11U)) + 8101351470141807662U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 6965474099521076705U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 6803828268885684784U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 13454235922950972488U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 11678091885751244777U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 3U)) + 5307134544628507141U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 20U)) + 4873703518950429353U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8542156221858586039U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3993726182905296513U;
            aOrbiterH = RotL64((aOrbiterH * 11331376012938127609U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12113047622035464386U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1944244448665721151U;
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12914188029425467576U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2486762763475327024U;
            aOrbiterG = RotL64((aOrbiterG * 12319769994433811617U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14580191602982245481U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12093414832400135066U;
            aOrbiterE = RotL64((aOrbiterE * 12720286833215690663U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13623906997320021065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9977356009806428696U;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3694954095397810851U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11453812627797091638U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13730420725113907161U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 542311345544726351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3024285045990499484U;
            aOrbiterC = RotL64((aOrbiterC * 5153745952148205645U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 22U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26034U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28710U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29363U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26368U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 2225397913940961213U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 8342544893601343643U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 162922186381417187U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 51U)) + 11660218373710972210U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 60U)) + 14909034764605802354U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 43U)) + 16776955237009701511U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 5834487809188925253U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1498492772767040320U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4161765458781579617U;
            aOrbiterE = RotL64((aOrbiterE * 15535994410289065281U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10511923076962447765U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8575954471692620021U;
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6536325446331340573U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1790628986900286346U;
            aOrbiterG = RotL64((aOrbiterG * 5262997114200816715U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2623814807619278590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11676970995834706612U;
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13836786354224256591U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6293096163612129260U;
            aOrbiterK = RotL64((aOrbiterK * 8977954126326217153U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4271144764978661248U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15938494256992560202U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10004841288382726739U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11038155227307702976U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12408749795071243930U;
            aOrbiterC = RotL64((aOrbiterC * 5527720475032868855U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 22U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 60U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 27U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 39U);
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

void TwistExpander_WaterPolo_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2626U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4066U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7417U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 7917U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 1087148170018530502U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 15530846874509311414U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 16987358651515511212U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 47U)) + 12504143181007924259U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 39U)) + 393322117322732418U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14325937299241887166U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9395262907017475742U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3442643798173589117U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13658510441418344769U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6410754322737005336U;
            aOrbiterB = RotL64((aOrbiterB * 6932217611373076391U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9257290738538818434U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7489828960857692286U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16519674788777989043U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4118778591214588387U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16619215231168796563U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14876884956536265157U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11326283811003573430U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1865401866017614604U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8378326058282460073U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 20U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 52U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12113U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13124U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10752U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14849U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 12222235191147985484U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 16367317014523328414U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 3511378091284703789U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 48U)) + 15247492830966725949U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 7745995913390407897U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6463593307540108810U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1101669311005268630U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10550146460887359369U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12988052764067518580U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17717179747434679772U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10820310705487638793U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11662190906682400416U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6563014073547628748U;
            aOrbiterA = RotL64((aOrbiterA * 16967910471722117761U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13099094932059419219U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16342730862261868847U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10988124108686164829U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16855346813127524624U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6570063128502306944U;
            aOrbiterI = RotL64((aOrbiterI * 4571570049463124831U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 56U)) + aOrbiterH) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20112U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23719U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21621U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18690U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 30U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 2571116506511057880U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 47U)) + 13112435411509707292U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 8461951095541400405U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 28U)) + 9890793478557463815U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3030229465991783707U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7273848154043719247U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17562254601517935669U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10681774862516028276U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7105082755586853104U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12217705329504230357U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6588579345319551129U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterH = RotL64((aOrbiterH * 2934574715879306337U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15439666290229654921U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14438730801970761889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14515616787452085729U;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterK, 37U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterB, 58U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererH, 38U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26831U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 31258U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27286U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29832U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 13174219512651137892U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 47U)) + 2715455762789269341U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 1338018183235594313U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 16566866551729552930U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 21U)) + 6901845297307236726U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2476078302049201718U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15531109473927052260U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1078804000420970559U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4087849380858572351U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5167830630098599644U;
            aOrbiterB = RotL64((aOrbiterB * 1982835131228146099U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7275995452428627217U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14794340370010024117U;
            aOrbiterC = RotL64((aOrbiterC * 8779497557416568379U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8509217403041662849U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2321522025240806996U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 113568101672878697U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5676672952755594051U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2304681269233504384U;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterB, 52U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterE, 41U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 38U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 3214U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 1962U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7226U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((aIndex + 8031U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 23U)) + 10336802574069791273U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 169025388197058936U) + aPhaseGOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 6541354188379168846U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 16223920526599306104U;
            aOrbiterI = (aWandererF + RotL64(aCross, 39U)) + 12756613707692514808U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5082475548176484035U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4907435526952698526U;
            aOrbiterD = RotL64((aOrbiterD * 1379692095754989215U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14236627073831834337U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11502511046130497584U;
            aOrbiterA = RotL64((aOrbiterA * 3460330807286625917U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3679044835550219497U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11254838916686736746U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8631695922983532915U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10582608424233200966U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 52U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 44U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12426U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16099U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12167U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 13132U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 14624277139785904404U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 13U)) + 6966977309498165611U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 36U)) + RotL64(aCarry, 27U)) + 205536824352530761U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 16629575265808255692U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 3U)) + 596881340147972746U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11944412799107412650U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4615021315668210206U;
            aOrbiterE = RotL64((aOrbiterE * 6459084105396631625U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8497630055977606216U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11131601107309336885U;
            aOrbiterC = RotL64((aOrbiterC * 18028349768453554935U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5935883479805510099U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15629346719765798174U;
            aOrbiterA = RotL64((aOrbiterA * 8535523790685945275U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5279128339113651273U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16778365912440331821U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 705421028266789241U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16003052937645491524U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6723226158737614764U;
            aOrbiterI = RotL64((aOrbiterI * 16690657664909260573U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20820U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((aIndex + 23532U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18716U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 21974U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 57U)) + 18180797995100240808U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 6585906608223552885U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 47U)) + 14088708930575939855U) + aPhaseGOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 34U)) + RotL64(aCarry, 11U)) + 468974153311516044U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 12481951025619894110U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17227987923860711763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4373962756657477139U;
            aOrbiterI = RotL64((aOrbiterI * 6069068316234356267U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2077576476565420951U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17435011300234663764U;
            aOrbiterH = RotL64((aOrbiterH * 8910133867294004711U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4118039398293246896U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13724716599855216683U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17556333902751079677U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12391461204689596339U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9900605191533799627U;
            aOrbiterF = RotL64((aOrbiterF * 13553565332531046301U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 972946858824366125U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17247681919694541215U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 48U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 31178U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25079U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25325U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 26284U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 22U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 13880995121909552664U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 3U)) + 14534942818069300546U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 17745973100886007133U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 2249805580771946872U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 21U)) + 4460116116396439410U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3378683994078106878U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3992996501048809123U;
            aOrbiterF = RotL64((aOrbiterF * 13273544260537223797U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12057768808864451929U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4115362079047921130U;
            aOrbiterE = RotL64((aOrbiterE * 12263015903331031345U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15297384955502206698U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17623548383481905636U;
            aOrbiterI = RotL64((aOrbiterI * 7487278217901483685U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3559213898000162417U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12311605719074507335U;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14807313864347885885U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11222085523291581822U;
            aOrbiterG = RotL64((aOrbiterG * 12580941911587215653U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 28U)) + aPhaseGWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5902U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5270U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7791U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6314U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 34U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 9080426856729228705U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 7851218321653539276U) + aPhaseHOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 27U)) + 7023344692919298036U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 43U)) + 9772846154227440734U;
            aOrbiterE = (aWandererH + RotL64(aCross, 11U)) + 12008298632429608431U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12201090455849562875U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9498721803411445471U;
            aOrbiterI = RotL64((aOrbiterI * 6511810500788451775U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 351203764023093632U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4966360430644539250U;
            aOrbiterJ = RotL64((aOrbiterJ * 10138518378274592739U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9194167899071345693U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4922477697284269116U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8444814161720407881U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15742625291642356429U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7528703106518431730U;
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15279053574704935317U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2425839793660355555U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11486964816849830667U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 22U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11644U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9601U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14285U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 10110U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 14U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 6163290588946759209U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 7342672468560105447U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 11U)) + 11574563167017282321U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 2254820206194758964U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 54U)) + 1469783447473099498U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14174828900676165088U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16277954291890598132U;
            aOrbiterA = RotL64((aOrbiterA * 4608888834164373691U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14845750668693136766U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 150099699692047766U;
            aOrbiterG = RotL64((aOrbiterG * 7644895634421086357U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1200784917165131703U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9469982764806754302U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17851969334511301943U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10956702761701710182U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7915506894975487807U;
            aOrbiterB = RotL64((aOrbiterB * 8874108311712727983U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17335794183733623213U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 557028996286989506U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3993359298602424281U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 38U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21739U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 18970U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22522U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 18241U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 50U)) + 15045917390223766480U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 10763054007033668758U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 21U)) + 13190170142593666607U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 9657025731441167065U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 11433367178975954211U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17904920143996810366U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3244383020512113283U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 552521443123433353U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6538815775171139091U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7195368312757976343U;
            aOrbiterC = RotL64((aOrbiterC * 10515679176134176565U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18134430713910279374U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6571776588427107976U;
            aOrbiterK = RotL64((aOrbiterK * 11916502085252589161U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11830778129647517758U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2287235876793192036U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8951959188326141794U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9968356718110753845U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 48U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 24916U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 31465U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30374U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 24872U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 15549114274303128055U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 16466750056388063241U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 12209449840836787142U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 42U)) + 14551496099734294336U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 6266576428679808622U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16892841575635668152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7375966221423362125U;
            aOrbiterH = RotL64((aOrbiterH * 15338878556107177587U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11926105302821753530U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16219253791550461124U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2117550758226173419U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7299056065319248160U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15234001484933728439U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8182244796017018911U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6615802589932632120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5481176858895819247U;
            aOrbiterC = RotL64((aOrbiterC * 3604590158551984877U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17220507586542139380U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14137921473739415340U;
            aOrbiterD = RotL64((aOrbiterD * 10634645686035907603U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 38U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
