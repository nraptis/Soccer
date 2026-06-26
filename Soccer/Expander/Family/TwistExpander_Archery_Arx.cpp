#include "TwistExpander_Archery_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Archery_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAC5567B398DB5A17ULL + 0xE9A8E49727905554ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD35F4DA6142B588DULL + 0xDF23D1B6E2AAAE6DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDCED7FCB183BC8A3ULL + 0x937626AEF263B575ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8863FF9180587345ULL + 0xF2C3126294AB71F1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9A56FCD4194FE1ABULL + 0xDB225909D33207E3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE84EAA472AD81F85ULL + 0x9A5A2210B81255A1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x95C9713370CCE01BULL + 0xC2EC90E0C6E46595ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAAAD28D87E977E57ULL + 0xAAAAC97AC2E0D7E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8F737DA27F28A2E1ULL + 0xDF9B88E7A4788607ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9EE65C8C4454A7CBULL + 0xBC7E52021D93C73DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA3B6D726E69C23A5ULL + 0x9B2EB16071E74F72ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA94A72A05713D87FULL + 0xF37691C033919964ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA4380721CCAE3D29ULL + 0xB1788AA2DF16F5A2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD4052D300CE54EE9ULL + 0xF245A4791A2B53D4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8FBD8F10614EE679ULL + 0xA7952D384753D28FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEE38504DABD9CDA9ULL + 0x8D481C5EC8481B89ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4080U)) & S_BLOCK1], 42U) ^ RotL64(pSnow[((aIndex + 4787U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2647U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1673U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aScatter, 30U)) + 17912271996338180948U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 3U)) + 13259276608841847058U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 57U)) + 16225936008657276089U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 37U)) + 2243058962151834071U) + aNonceWordA;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 10637439274127347861U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 54U)) + 15312219216405992627U;
            aOrbiterC = (aWandererK + RotL64(aCross, 39U)) + 2393933972129878613U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 4327069337247976513U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 8307656353434167837U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 35U)) + 17299145556933889336U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 51U)) + 14458100581172798164U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6410095654927998067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 6168964796264687686U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16218071040190475953U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3667999465041020730U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16021552859323602007U;
            aOrbiterJ = RotL64((aOrbiterJ * 6427266472526362663U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12941668202330045095U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4222032891850449934U;
            aOrbiterD = RotL64((aOrbiterD * 17292856787431308097U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1346342592002730785U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16860611785008118820U;
            aOrbiterF = RotL64((aOrbiterF * 384963420804756607U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3193572711804730241U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5866881282680588589U;
            aOrbiterC = RotL64((aOrbiterC * 9226331800853634597U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17180332731328479126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10222097519535882241U;
            aOrbiterK = RotL64((aOrbiterK * 9422887302872778795U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8863502179821584859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14872318155712512999U;
            aOrbiterI = RotL64((aOrbiterI * 11830641277356873233U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16478790641892781150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8414944141232294781U;
            aOrbiterE = RotL64((aOrbiterE * 17443775794621154023U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13204056527590476037U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15084952142545813228U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17183888602469193015U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13051035678904490854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17565188004293304987U;
            aOrbiterB = RotL64((aOrbiterB * 12785271107667631897U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 814245676602237400U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17912271996338180948U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 14557769257469623169U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterE, 44U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 44U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 36U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 60U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8134U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7872U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6036U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8026U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 1708250618750199233U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 57U)) + 12009147777553691142U;
            aOrbiterI = (aWandererB + RotL64(aCross, 53U)) + 8393982703399156592U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 3247327098356831221U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 3403590155376353737U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 18U)) + 18197244558104735044U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 35U)) + 3096253642040701606U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 8012692688785412179U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 5U)) + 17531946907545680745U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 60U)) + 17687695944270225817U) + aNonceWordN;
            aOrbiterE = (aWandererF + RotL64(aCross, 39U)) + 16147773866007628769U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 18244641303026196497U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8839160526348897457U;
            aOrbiterI = RotL64((aOrbiterI * 14268021129087663397U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10599266240854068246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2056723540756216155U;
            aOrbiterA = RotL64((aOrbiterA * 13311591601230386375U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4629354220460621284U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17775391885312236187U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17078153810088721310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9470436761716263000U;
            aOrbiterC = RotL64((aOrbiterC * 5431855497250357229U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3305863413630104742U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14377172434239576161U;
            aOrbiterB = RotL64((aOrbiterB * 6880176890091033423U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 415687827894226513U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16975319836893760993U;
            aOrbiterK = RotL64((aOrbiterK * 6597144958013976445U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12707054129431596074U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8974182792497231239U;
            aOrbiterF = RotL64((aOrbiterF * 7874658957269462717U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10826131924322955095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4168545139712703154U;
            aOrbiterH = RotL64((aOrbiterH * 10305904857550051705U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4539070253658625193U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3737870219498561326U;
            aOrbiterG = RotL64((aOrbiterG * 13130847633918921393U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11563084648810555040U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7410695535361901473U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7540855656023807389U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6687453696858775037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1708250618750199233U;
            aOrbiterE = RotL64((aOrbiterE * 13104250803527718135U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 30U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterI, 48U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12104U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15486U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14460U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 15023U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 54U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aIngress, 29U)) + 17454559218352016650U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 37U)) + 8005709669325164803U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 43U)) + 13393741948412816357U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 3665865624348875553U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 8334142570031883436U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 5U)) + 17226066128706139657U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 48U)) + 3319093033121522613U) + aNonceWordD;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 6657535603401588798U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 41U)) + 5469746182326331147U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 27U)) + 17846791786050221418U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererC + RotL64(aScatter, 56U)) + 15939541003714896288U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12076763190461077406U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3594038213596405284U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8301291631324464622U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8460406137668390582U;
            aOrbiterK = RotL64((aOrbiterK * 9117147929757711595U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7612394867020871200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8525076134853103975U;
            aOrbiterI = RotL64((aOrbiterI * 5790440201072204659U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11929899088215090379U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7119509166360685726U;
            aOrbiterD = RotL64((aOrbiterD * 1662341427992528823U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5081078459225240607U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17149991983909906705U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 950223374568067343U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8817303295675241994U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7962039282652745113U;
            aOrbiterF = RotL64((aOrbiterF * 12773588587795522121U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13596273086338032370U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8186297702278180956U;
            aOrbiterB = RotL64((aOrbiterB * 6226504769888753861U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1696277861691580263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17360461831507082959U;
            aOrbiterJ = RotL64((aOrbiterJ * 1651378456022210983U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1384868996572650981U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2039624849777183290U;
            aOrbiterE = RotL64((aOrbiterE * 13148024378138271937U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14530407348595669913U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18023931565754525034U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18025122652259338105U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11245556671533878373U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17454559218352016650U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15665798947106818229U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterC, 24U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterB, 58U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20284U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16612U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19508U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 18493U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 27U)) + 5295352595333316211U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 50U)) + RotL64(aCarry, 35U)) + 2341795367042042605U;
            aOrbiterF = (aWandererG + RotL64(aCross, 23U)) + 10122175780504033663U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 41U)) + 10084612804696198554U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 16470424309851045971U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 656016130975227994U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 15313268829659834317U) + aNonceWordN;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 3795220914993923394U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 3U)) + 14044442220988813825U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 54U)) + 3804224626734584802U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 37U)) + 7980006306010255693U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13746830564584711549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11852212099729274845U;
            aOrbiterF = RotL64((aOrbiterF * 2164880979318247855U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9083223471018084847U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11361854103656219887U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1713819986642275223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1382000168233902914U;
            aOrbiterI = RotL64((aOrbiterI * 3894160765130198157U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4540474625764565485U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1756168174375757220U;
            aOrbiterA = RotL64((aOrbiterA * 12739160208010092017U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1409297070183609309U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6082750101445444357U;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1113239890859479202U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10932192439503964363U;
            aOrbiterC = RotL64((aOrbiterC * 5915660289913324281U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3732595033748508428U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 5117760372351117286U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 2671510075176315761U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7399968659654088641U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14835608167871904147U;
            aOrbiterG = RotL64((aOrbiterG * 8312521710415756159U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7851355416751467648U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 262169565276199916U;
            aOrbiterD = RotL64((aOrbiterD * 11801419425408657509U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1771847554312299305U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15588805765521695222U;
            aOrbiterB = RotL64((aOrbiterB * 8541206691371972017U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6162696602553964144U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5295352595333316211U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8368226841948931873U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 6U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 41U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25061U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 25744U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26452U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26458U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 14214886793361825363U;
            aOrbiterI = (aWandererH + RotL64(aCross, 37U)) + 17267959031078766320U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 60U)) + 16436067429484887644U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 3U)) + 9885951769332633820U;
            aOrbiterB = (aWandererD + RotL64(aCross, 43U)) + 12971711341813893304U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 27U)) + 199970353398450154U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 1237341696444162094U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 39U)) + 7991128854417613360U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 14809029847149045833U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 2559509556915775947U) + aNonceWordH;
            aOrbiterA = (((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 53U)) + 14336829730147834160U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8853631886733610440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13346159398673246914U;
            aOrbiterD = RotL64((aOrbiterD * 13660497151446983393U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12121095718571872976U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16239781125815589804U;
            aOrbiterH = RotL64((aOrbiterH * 5157009090454962231U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9051377033794324106U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13805815136723461780U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 571129481747181357U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14849157800322754413U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18116651528452542634U;
            aOrbiterK = RotL64((aOrbiterK * 3638480428016835537U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4105057226952948599U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5911714320560994391U;
            aOrbiterC = RotL64((aOrbiterC * 1796514171654961389U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4439149331729987587U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10278532228230163632U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17428224919864716517U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2342456582668741750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2360578572554664800U;
            aOrbiterF = RotL64((aOrbiterF * 1108428466956691925U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12132934875391401246U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17213278726790245812U;
            aOrbiterG = RotL64((aOrbiterG * 11904899990681410419U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7994340481560109811U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13735851271080138255U;
            aOrbiterA = RotL64((aOrbiterA * 12387076892129731557U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6682417543888875268U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15642799286975840550U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 7861250716882028053U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9839299346094784067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14214886793361825363U;
            aOrbiterB = RotL64((aOrbiterB * 2103132743364916037U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 4U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27517U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 30720U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27870U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 31436U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 51U)) + 6469584119078165548U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 24U)) + 14329756366517987910U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 12890831797059772123U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + 3164503807500018990U) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aCross, 35U)) + 177531431387646836U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 27U)) + 3167421392893561015U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 2813174781844753460U) + aNonceWordP;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 22U)) + 10953270419153249857U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 29U)) + 16911518309710356951U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 53U)) + 6616750447844893150U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 10276741398025985982U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6206043608461213208U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12021552904553405793U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 10023362889960174909U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15283586234744144846U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5923238786775948571U;
            aOrbiterK = RotL64((aOrbiterK * 8200882393521882651U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11044014510971660078U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9351141024085076044U;
            aOrbiterH = RotL64((aOrbiterH * 13316079344614432317U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17703395981862992420U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10154548848376027087U;
            aOrbiterI = RotL64((aOrbiterI * 12324478347590509035U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8836420852291617425U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10193385413543886344U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 824935982418585449U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8248580084535685190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3910083671888152974U;
            aOrbiterF = RotL64((aOrbiterF * 17825311776715895927U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12350341628569930642U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2565977481575002842U;
            aOrbiterC = RotL64((aOrbiterC * 18233446879833776677U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9271041067874027417U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14289254596554201861U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7985522692852251413U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5981802134118235214U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14047813418129636856U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15961435325216504877U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11808443842149398212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11380858372643695792U;
            aOrbiterA = RotL64((aOrbiterA * 100198424024622179U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10385375464069162356U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6469584119078165548U;
            aOrbiterD = RotL64((aOrbiterD * 5263876933019848989U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 40U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 10U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Archery_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8F08AC25D8294D85ULL + 0xBFA95A51FE85C3C9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDE2755CB87E90F01ULL + 0xB4CB09951DD50B29ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE0B11F7F755AF4E1ULL + 0xEB7734CD31809AF3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC56F3E3C72DD8A29ULL + 0xEEF0EF142C18BEA4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCCA1A781BCCDE029ULL + 0x8B5DF11B7206F048ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81F4D85E6F521DABULL + 0xB0725F1EDA3F165AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8742F4076C478731ULL + 0xB196F3915BCE617BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x803C4B705F678DEDULL + 0xFD604411EC9B04D9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF77F1E6F31CC3CFBULL + 0xCD52322623EA2979ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC8AED8E8205E66E9ULL + 0xE00B6358327B461FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCB6F41E72D6D4655ULL + 0xBE1D5D7A402138D8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x80254A09D2B692DBULL + 0xCFB548D64D1707E9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFF96B93BF1C470BDULL + 0xC3A41EFED57CFF08ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB35500AEA2092E31ULL + 0xDD5C18A0DE6722A3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBF4FE63A86622973ULL + 0xCFBF0187250FECCCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB4BE9F65DC1E58EBULL + 0xCA4D627875C0665DULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 455U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 4496U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7545U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 3562U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + 18302975933754610273U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 16736972646771456082U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 19U)) + 17389406266488137442U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 58U)) + RotL64(aCarry, 47U)) + 5252511566486165539U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 5730715427422747640U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 47U)) + 6412695646456045825U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 5U)) + 9539701605708994494U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 54U)) + 18355107116412945722U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + 11735742491750132942U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12363819388562658842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5861430292304371543U;
            aOrbiterK = RotL64((aOrbiterK * 12989055611235382695U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15027487084595017708U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7012850020745791926U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 15952928839355613939U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11904871669287886120U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11199760114477343208U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7156374911847525867U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3856004502263742700U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3705931243173921893U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12305785390539209389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18057980996551978823U;
            aOrbiterI = RotL64((aOrbiterI * 4850564181113470859U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3229431819292153014U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2994716629242460094U;
            aOrbiterH = RotL64((aOrbiterH * 1029427328395257917U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9796307843453735512U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2957260393651252432U;
            aOrbiterE = RotL64((aOrbiterE * 7261055869794739609U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4060469664218866340U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17462081697889685330U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 7712009170974461225U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13638660073917821172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15202349592659062565U;
            aOrbiterA = RotL64((aOrbiterA * 4514326257446024301U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 50U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 34U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 12U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10120U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 13749U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8273U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9885U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 13278949403988203974U;
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 9213599924054673756U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 39U)) + 1255746482932381798U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 35U)) + 11575321997144516122U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 46U)) + 15881587525529432437U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 51U)) + 9846195809864862707U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 13U)) + 12319815691858217670U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 16322617427294439587U) + aNonceWordB;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 47U)) + 16332130810525887437U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4920951156015336794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16767126455124552329U;
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12553595911087945223U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1437522202135436142U;
            aOrbiterK = RotL64((aOrbiterK * 2001992794165550905U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12313100454852227143U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2761983020631055729U;
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17635303588421554367U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 788212489507463763U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17896475584538528059U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5192552894670654434U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6784748488807738811U;
            aOrbiterE = RotL64((aOrbiterE * 8077237651953896479U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16113417046719114943U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1096874945215225916U;
            aOrbiterD = RotL64((aOrbiterD * 17308604412622879833U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7610274704570171595U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10466070212284342550U;
            aOrbiterJ = RotL64((aOrbiterJ * 6449728258497920613U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6777845928873855221U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5251515022021984126U;
            aOrbiterG = RotL64((aOrbiterG * 9018277343404261611U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13849343158824111498U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7977711210181714021U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4182053966171053577U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 48U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 34U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19051U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 20554U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22860U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22166U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 10U)) + RotL64(aCarry, 53U)) + 12046647397183218524U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 2760779375026461991U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 23U)) + 13735454443176855650U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 4370377000586647724U) + aNonceWordD;
            aOrbiterG = (aWandererE + RotL64(aScatter, 27U)) + 14566322384189969094U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 14U)) + 5056565959818422786U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 5U)) + 8795403810686579209U) + aNonceWordG;
            aOrbiterC = ((aWandererA + RotL64(aCross, 57U)) + 9625947666256011567U) + aNonceWordL;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 35U)) + 1703669290934254701U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6664070663184147951U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2104148316797553431U;
            aOrbiterH = RotL64((aOrbiterH * 12887842067180975983U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1197910004222596145U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9922977170060903197U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 13047828062605568603U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2048376210852567829U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12568990647075931409U;
            aOrbiterA = RotL64((aOrbiterA * 9860242601194210927U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15026894775772902751U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3439447160137900629U;
            aOrbiterF = RotL64((aOrbiterF * 1813754963043785165U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6532671388552829796U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17261098369835997661U;
            aOrbiterG = RotL64((aOrbiterG * 568292591215203521U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3171300991007459947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5935563269327662024U;
            aOrbiterE = RotL64((aOrbiterE * 11271790283157765003U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14290941734320455612U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12371794745736518824U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 12208762336145168647U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8782840145467637373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4067525421190366741U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6671002797916227485U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11854812920571789853U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17564890418553131451U;
            aOrbiterI = RotL64((aOrbiterI * 16657184504366731805U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterB, 14U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterC, 34U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24921U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30788U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26518U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30253U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 10U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 56U)) + 11177787645248006236U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 11U)) + 3808340254579817169U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + 828030667598518279U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + 16177835921238398371U) + aNonceWordG;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 5518747735458708741U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 17346319082399995165U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 6397156921893030937U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 15559381654710713582U) + aNonceWordP;
            aOrbiterJ = (aWandererC + RotL64(aCross, 51U)) + 940404446491415088U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8047166032048732645U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4688468645859470491U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14383536431614496369U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3710878044770337260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 883908030159391659U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18058691521694880482U;
            aOrbiterG = RotL64((aOrbiterG * 3132200449123497619U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17521015077103586117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3668332225435714918U;
            aOrbiterA = RotL64((aOrbiterA * 12658899101297839881U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12229480388278883300U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16206524049491531816U;
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5743265849441077466U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2812293020719282236U;
            aOrbiterC = RotL64((aOrbiterC * 8903956475200417109U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13718364781538837074U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 861529717259766236U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 17019744777211266685U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4862687502126693872U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7722024283321020761U;
            aOrbiterJ = RotL64((aOrbiterJ * 18086944039541060829U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8205803118233399853U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15130160926615050422U;
            aOrbiterE = RotL64((aOrbiterE * 1454552751453996765U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 4U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterB, 24U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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

void TwistExpander_Archery_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDD3627271D9BE22DULL + 0xF9F2D89E281C62C1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDF289325CB3D5D57ULL + 0xA109E54CF474AAF4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB9F00C4C9D08C865ULL + 0x8751E9322458075EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFEE15FE0C9081971ULL + 0xE0ED8BFD208B4DBAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xABAD4BD3E8C57F65ULL + 0xA4A92CA3CD8EC2E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9C346D815063ECA5ULL + 0xC5FE3BC6DCF9E9AAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB2324195295320F1ULL + 0xA6459512DC2C7808ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFA66DFB65A7895D1ULL + 0xA8BDC50E8A193CA6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF51BD8D193B12343ULL + 0xF6A9A7A495DF20E4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD53D404B58F39799ULL + 0xEA79593026B3264FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC902D1E75A0B3475ULL + 0xFF14DFB74AB0AE3AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE8EA59FA9DD98D3DULL + 0xBC46A8E2D86696ADULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD6ED47D985DFDDE7ULL + 0x9750C8903E8114E2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9F29C9A67B4B94ADULL + 0xA658471417CF478DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCC8D3D8BE799A7FBULL + 0xC819E903387ED178ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBE376BF2C182393DULL + 0xF2A65DA41765BD97ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 872U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 1275U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7723U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7570U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 3U)) + 3917730204724097072U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 54U)) + RotL64(aCarry, 53U)) + 1874642340716212824U;
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 6900165757434854160U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 12750946097023807161U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 21U)) + 6563216048479513594U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14960240191349450795U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16306180275951788289U;
            aOrbiterK = RotL64((aOrbiterK * 12077366095522790283U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6502066618271045547U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6219852857850888738U;
            aOrbiterC = RotL64((aOrbiterC * 10892297250334325283U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2272931312452845850U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3028929882263199463U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11005324285856805069U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 6067393030073568112U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10094809900437037258U;
            aOrbiterD = RotL64((aOrbiterD * 18095564940730322769U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5962414178157074575U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15755563045799129417U;
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 28U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11412U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15169U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12760U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10503U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + 14249093584376402677U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 8756965951816492264U) + aNonceWordC;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 37U)) + 11221139480258176330U;
            aOrbiterH = ((((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 17218894445564194851U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 50U)) + RotL64(aCarry, 57U)) + 8064642692524949490U) + aNonceWordA;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 5822093203710704646U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3217799620158102238U;
            aOrbiterG = RotL64((aOrbiterG * 2806328682494910635U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 2613757677892120843U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13647481499551657237U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5517563514031899891U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3545714196663685016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9735422670576621521U;
            aOrbiterI = RotL64((aOrbiterI * 7276207208162697249U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3911046580637583767U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9315984027042049203U;
            aOrbiterJ = RotL64((aOrbiterJ * 12568550776487242469U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8926367674641729058U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11035347490524961446U;
            aOrbiterH = RotL64((aOrbiterH * 10948288997163592463U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 12U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20581U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 16813U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17710U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 19851U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 52U)) + 15813325389431304548U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 2223874171125403602U) + aNonceWordG;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 5510483568496824130U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 15474152493495661876U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 19U)) + 16846339705130829195U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1289670576865739669U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18017354919647006944U;
            aOrbiterB = RotL64((aOrbiterB * 13103155460891498469U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8539685539928984921U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3333721400836704048U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3745286323481400085U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2261560416623815491U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4377786131746816567U;
            aOrbiterF = RotL64((aOrbiterF * 9164777834392621157U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 18047393176583722719U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8184724021940434631U;
            aOrbiterH = RotL64((aOrbiterH * 9800116157750921119U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10469895939183324807U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14543391765109879223U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 56U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 58U);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26897U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 32301U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29580U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31153U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 2177539223979303669U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 22U)) + RotL64(aCarry, 3U)) + 3962004686551521471U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 39U)) + 8457602312617147662U) + aNonceWordI;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 18011802451816510632U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 11U)) + 9046101759168876832U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11135620637431969597U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15913029940697999701U;
            aOrbiterI = RotL64((aOrbiterI * 646524659942693491U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16304193109948135982U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13208892298820080981U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 15093751072618884859U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 4182377898949419225U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13970137023071326151U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9075061559681739865U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8402396284835248583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9760005337757990392U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14108277760135744897U;
            aOrbiterA = RotL64((aOrbiterA * 4474681104256093885U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 56U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aNonceWordG);
            aWandererD = aWandererD + (((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 35U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_Archery_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8BEEDF13562ADBBDULL + 0xEA7E48129BF5D85EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEA3D91878C192EE3ULL + 0xF25F99EDC4FC5023ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x985C8BC446C4CDC1ULL + 0x8054E628B50A817DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAB8881BC15598A7FULL + 0xA5EDFDA7AAF53149ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDEF52CE29C0E58FDULL + 0xC099211E561BCE67ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x85AA15B9C612DEBFULL + 0x8AAA42EDF0EBCE9AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF9167A3D1540EB27ULL + 0xE8E9AEC480AFC657ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFCAE2841495DC88DULL + 0xB4C457EEF2CDF2F5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x825AAA112339243DULL + 0x9AFF55C3305A08CCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA8DC275C68FC1765ULL + 0x912ED09B68D6F9E6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA11A6E96EF67D9EBULL + 0xCB4640014ECD1496ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF772262D4F8FCA77ULL + 0xC88EC8FC9874F969ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF67D12179F77A2FDULL + 0xCCCDDDCABD7E9FF9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x825F4E741592EF01ULL + 0xDFC539DD2AE5776AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF4396E1C22AD0441ULL + 0xF63CCA4B189B625AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD600F29310849D39ULL + 0xC25F8ACA30C2D2FFULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7345U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 854U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6841U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 3136U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 22U)) + 12535417189990029950U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 35U)) + 6204401443676390273U) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + 869613505613154672U) + aNonceWordA;
            aOrbiterF = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 15053590879563855802U) + aNonceWordL;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 13338989605204591428U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 18306470022403825392U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 3U)) + 1150696349434090218U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13549541786420596437U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14302878430259588461U;
            aOrbiterE = RotL64((aOrbiterE * 16813606782134305513U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4660437084477165225U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1653628537860912069U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5594199757006711631U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11008472193138708891U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 13645764762027798301U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6378674346113979108U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11438762460659123362U;
            aOrbiterA = RotL64((aOrbiterA * 2733309638158283953U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10624263004446482910U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12546839706919241411U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 11468326687628079347U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8466639576503293921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7835487310289634515U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 50U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterJ, 50U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13260U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 16056U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9509U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10192U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 56U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 14U)) + 11700815697312060726U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 11808423452327465441U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 8670503858631730886U) + aNonceWordO;
            aOrbiterB = (aWandererJ + RotL64(aCross, 27U)) + 2400061067991988544U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 3U)) + 16163118178366229686U) + aNonceWordJ;
            aOrbiterC = ((((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 3280178595904941068U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aCross, 43U)) + 3298683600817047727U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16321624053445183574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6730229877611375225U;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10162830636713641322U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15646771327759599256U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15333053762177144775U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14841751262270544102U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 9545541117228834895U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 11529769874752969377U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14676615635857599982U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 1945905595345404833U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1406171421638586846U;
            aOrbiterK = RotL64((aOrbiterK * 4577864352425476233U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1970292335806697198U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12309719390375013297U;
            aOrbiterC = RotL64((aOrbiterC * 16540660957923687327U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5352135521358954576U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385761112921041387U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterK, 41U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 6U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19192U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17643U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22181U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19432U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 3199575576585871314U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 2533378188975571824U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 23U)) + 6819782112558312658U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 41U)) + 12690060987724798497U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 7088375139715629606U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 17785618677423695666U;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 1714999280296491277U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17611338506932491624U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6475727359297421201U;
            aOrbiterH = RotL64((aOrbiterH * 15133348244242438069U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2347744591204119530U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2739317903351401068U;
            aOrbiterG = RotL64((aOrbiterG * 15435029315209475631U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8663535261373274338U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8205245127823536479U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8916510616749754516U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3944805940148512932U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 18082271583211389701U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14094751253118853302U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14094299829196076311U;
            aOrbiterJ = RotL64((aOrbiterJ * 6370012560657108493U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3940673811518673802U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3015106523254484839U;
            aOrbiterI = RotL64((aOrbiterI * 9655401190755573379U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15404103131982599922U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1828655763233900875U;
            aOrbiterE = RotL64((aOrbiterE * 13024358077740310049U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25183U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30020U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25111U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 27839U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 20U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 51U)) + 7825479804710770560U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 5298124167101358123U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 17774541024369233726U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 7679371833537454082U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 5385914900748772224U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 13U)) + 3879781930908486531U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 43U)) + 659110346638873236U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 10749021728538539749U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3631252455767429457U;
            aOrbiterF = RotL64((aOrbiterF * 8552825360915119613U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2271978810960685021U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5963558780692551176U;
            aOrbiterH = RotL64((aOrbiterH * 4772055335210781149U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 974909966119198104U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9296998242911152296U;
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2245318466901521959U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13391076374843288568U;
            aOrbiterJ = RotL64((aOrbiterJ * 18094558036982107419U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6184487746594236737U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1563385912137291418U;
            aOrbiterI = RotL64((aOrbiterI * 4805455299959232321U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1744840092006498629U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2100927276837188416U;
            aOrbiterD = RotL64((aOrbiterD * 3541788262067077997U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9998911862807246338U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12239948725635220096U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7098620484129489129U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 44U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterD, 5U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Archery_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9DF51BC38B87854BULL + 0xA672353FDF9ECA55ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB18C23298C4D58ADULL + 0x944BAE8F0D853645ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8F90F03D2301EBF7ULL + 0xE830AB051CC428B2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xED3E4E521DBAA03DULL + 0x89567547ECFD058FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCD6C31518AEF43E3ULL + 0xF5B866A5CDC87A20ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEDE3AAC7F58B7297ULL + 0x8C8C8C6C940C0247ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9B7F030CB2FCE6DBULL + 0xE6B1D000D5CDF242ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCA038876CD52322DULL + 0x9A63EC911CAB9584ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB96ADF3411F52421ULL + 0x8CC5A9EF4C3B626BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9B08A2852371FFAFULL + 0xDCD0073F82471007ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD05DF139A05AFEF9ULL + 0xC868F52147BE2B5AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC6A35795A1679981ULL + 0xC3E18F34E033DC61ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB15ECA4FC670CD7DULL + 0xA0EC73697D9FA743ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xECE2C17FCD58E147ULL + 0xB67F3126295459EFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE7720E3E08081BB5ULL + 0xA9DF013A5ED4729DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA1E65E4D133CE17FULL + 0xF3F6E82F5F968585ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5968U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 2143U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1168U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 8103U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 35U)) + 12775735908960052604U) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 11791373812080296887U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 5537362877706057303U;
            aOrbiterC = ((((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 2023912048504189380U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 17668828109963766893U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 51U)) + 558908629933941224U) + aNonceWordL;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 13U)) + 1479633119685446888U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15460320397843364063U) + aNonceWordK;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 10059749397555469054U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 8671817118586065469U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9987633811929693924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4446204415503364254U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9430197906134676162U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10611580584157624739U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9327201928815412810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterC = RotL64((aOrbiterC * 13827717178378062047U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10675114832750356941U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterI) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 12U)) + aOrbiterE) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11680U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11903U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11498U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 13837U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 60U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 57U)) + 15549114274303128055U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 16466750056388063241U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 12209449840836787142U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + 14551496099734294336U) + aNonceWordN;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 27U)) + 6266576428679808622U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 50U)) + 16892841575635668152U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 7375966221423362125U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11926105302821753530U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16219253791550461124U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 2117550758226173419U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7299056065319248160U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 15234001484933728439U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 8182244796017018911U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6615802589932632120U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5481176858895819247U;
            aOrbiterJ = RotL64((aOrbiterJ * 3604590158551984877U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17220507586542139380U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14137921473739415340U;
            aOrbiterE = RotL64((aOrbiterE * 10634645686035907603U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16981960446540932787U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10897565927079518588U;
            aOrbiterH = RotL64((aOrbiterH * 418843936329303571U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2746889569299593263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4894117146736361379U;
            aOrbiterB = RotL64((aOrbiterB * 2656750612042673191U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18294823016957137777U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 86828501068883383U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 48U)) + aOrbiterG) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 36U) + aOrbiterK) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20055U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 24144U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19194U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 23092U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 5U)) + 4179952823252098240U) + aNonceWordI;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 42U)) + RotL64(aCarry, 57U)) + 3745613452332101749U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 2955689793395307176U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + 5639060180251322019U) + aNonceWordC;
            aOrbiterB = (aWandererA + RotL64(aCross, 51U)) + 7901969163853586463U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 2242166787816318119U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 5239936443960750064U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13939136954732185558U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17058884136712717463U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7222348891215482977U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 18148618660054585941U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7022023484530327814U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 650100011311048589U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7722084537340095637U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11764151879690934182U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12264384877711365655U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16412785901758144708U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9666718667728274824U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 10865799822751771795U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4307127540152109364U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2457646804702647606U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6340030928007058595U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3179394870088602208U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 504977947273774249U;
            aOrbiterG = RotL64((aOrbiterG * 16190282058883481551U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16182729401018310837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7110817020445860609U;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordG) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 48U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25863U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27168U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30848U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24825U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 12U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 3612110001869385068U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererI + RotL64(aCross, 43U)) + 16340824141280225936U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererA + RotL64(aScatter, 50U)) + 15222338965130765231U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 13U)) + 6649270508107155041U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 768217258655426384U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 4481855259658861851U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 3U)) + 18318041934562434016U) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4212457153804401807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16143621095636987628U;
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2095664232866642086U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4339527736737366572U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17503569508822244125U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13679353177869884790U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11582168502846418236U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10451330452898542191U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12951448817640617841U;
            aOrbiterI = RotL64((aOrbiterI * 4141870904192742091U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15389161934419370747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4754886272708253014U;
            aOrbiterA = RotL64((aOrbiterA * 16638243718191281597U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11746389873929280688U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 12042680172517298768U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 3814780289755857543U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2648103752465009244U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 451594673632597973U;
            aOrbiterK = RotL64((aOrbiterK * 8496763663271072425U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 19U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordI;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFFE22E22D4BE24CBULL + 0x8C6A760EAE92C817ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFA37880DCD6397D5ULL + 0x9F18BF80FFFEADEEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA31D7C3B1EA2D71DULL + 0x8706A1DC6975CA59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8B37A76B3DACEC4DULL + 0xB12BE73D2B4D1414ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB7B5AA51DDB55389ULL + 0x8279C224B6C2515EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF407AF646D00D7DBULL + 0xC267BC317DDE2382ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB7D7F24E994477A1ULL + 0x865E4F8B8CD0DA4DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC3B707CD40E4DAC7ULL + 0xBDFE2DD58E11756BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDC272C39752979B9ULL + 0xA6D8B6555FECB7ABULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAB41B2E006BEA187ULL + 0xB3D695BB442A92E0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAF089E4263B9B49FULL + 0xBEEBD5E30CD9E4CFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB15604849499832BULL + 0xAD65FB25CF2BBC92ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC5FF09AD2DC89795ULL + 0x89C65817F85E4A28ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA8B9C59D04501B9BULL + 0xED9B12B1993A6DD1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBF66E80920C69737ULL + 0xA673F6DDBE34909BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFCD91196EA2431D3ULL + 0xCDB540D7F7734353ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3031U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5940U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3326U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 3668U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 12029393034357490020U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 4526754731580694987U) + aNonceWordI;
            aOrbiterA = (aWandererD + RotL64(aIngress, 14U)) + 17060419646421271853U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 57U)) + 4128488893837059683U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 12706894827547160110U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 47U)) + 12506324593645825056U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 21U)) + 12581344490649250025U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 44U)) + RotL64(aCarry, 23U)) + 14357032418199130132U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 15341977701796331249U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 37U)) + 7086602307544733241U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 53U)) + 12398300065276832486U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2499745046076601988U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7249361592814001829U;
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3254456186337366437U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3472973415969046680U;
            aOrbiterH = RotL64((aOrbiterH * 14583566953969168353U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7905718972111691591U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15941413652144021522U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3473779492962783565U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10583964125960308762U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13659925272340853715U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16708294803316630743U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9487054537489454887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13287757570441887517U;
            aOrbiterF = RotL64((aOrbiterF * 17351439045329892107U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15279245465808571942U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12424999114621745879U;
            aOrbiterJ = RotL64((aOrbiterJ * 2274918760256527137U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13915392738892970475U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13797668053788805126U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13752161103680525317U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14344766585550401077U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13727554194373146727U;
            aOrbiterE = RotL64((aOrbiterE * 17164450431362670223U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1332966642432651232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 938583742533681467U;
            aOrbiterB = RotL64((aOrbiterB * 13323340043936037549U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5659239372701978244U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8501778564909302938U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15629932660749672503U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1698500835332753591U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12029393034357490020U;
            aOrbiterK = RotL64((aOrbiterK * 18176507271635640153U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 40U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 56U));
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK + ((((RotL64(aCross, 22U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterD, 14U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13433U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13405U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13591U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16211U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 60U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aScatter, 23U)) + 785861751704720606U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 54U)) + RotL64(aCarry, 23U)) + 15968088718435606299U) + aNonceWordP;
            aOrbiterI = (aWandererE + RotL64(aIngress, 51U)) + 1393976526590347151U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 41U)) + 17240750947292745884U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 29U)) + 4921576136163183137U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 37U)) + 3334047873553153032U;
            aOrbiterG = (aWandererH + RotL64(aCross, 57U)) + 15086509978458408698U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 35U)) + 892391205397581998U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aCross, 26U)) + 2965686403183767521U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 14632215393655706170U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 15740589515342377322U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11131164813943086445U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6988080581278900960U;
            aOrbiterI = RotL64((aOrbiterI * 6412189142344044255U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16021254613117657178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6183615599897921154U;
            aOrbiterJ = RotL64((aOrbiterJ * 9976411093264211033U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12533992547026652747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3104325358982904219U;
            aOrbiterE = RotL64((aOrbiterE * 14977348108778147265U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3878525937957474644U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2120435259884368445U;
            aOrbiterG = RotL64((aOrbiterG * 15964718652193073177U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14928658302694194856U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9121310461310309348U;
            aOrbiterB = RotL64((aOrbiterB * 17304439784647477491U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3715693239100476493U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7336577492932262490U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11074754160002665253U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2312452827448455675U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4322756069651934618U;
            aOrbiterC = RotL64((aOrbiterC * 6908893297397073539U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4962079617577705818U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5072727464750706525U;
            aOrbiterK = RotL64((aOrbiterK * 4947670001221089155U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4553791875259778686U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15823770920225774233U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 409663191536830375U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9468608484284459072U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8658861660659699947U;
            aOrbiterF = RotL64((aOrbiterF * 2933359123761406353U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14453429515273506170U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 785861751704720606U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 3544627380583668815U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 54U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 50U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 22U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16863U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 21869U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17274U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 18246U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aCross, 46U)) + 7893287783892523139U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 21U)) + 10257331997383491153U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 14562226733652231753U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 14320342577110737851U;
            aOrbiterB = (aWandererD + RotL64(aCross, 23U)) + 9816717579822880756U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 9558926960095881953U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 53U)) + 9230371862654338324U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 35U)) + 6414274291252913420U;
            aOrbiterF = (aWandererE + RotL64(aCross, 50U)) + 13868546184398350849U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 29U)) + 16940736952569949038U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + 2866957764814864371U) + aNonceWordO;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7916721976073979724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1602444214978842275U;
            aOrbiterH = RotL64((aOrbiterH * 11072503711308122385U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9529061385251008037U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8402775110887376588U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 13980225144628227381U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15003592180290390713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14195681406520825751U;
            aOrbiterG = RotL64((aOrbiterG * 11455000833788877217U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3263577002367714202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12019422062655581928U;
            aOrbiterB = RotL64((aOrbiterB * 5002313835338447799U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8508638054582582917U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6536618106353552880U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6233964121117511885U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9654542989321430868U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7019594782797863244U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1234877854354279981U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8256061220727519919U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9232754129467036130U;
            aOrbiterA = RotL64((aOrbiterA * 17556001874302369781U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5608829951337740378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12632120498473345701U;
            aOrbiterI = RotL64((aOrbiterI * 6994794653605831925U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17313364434369677697U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10147405701828074385U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11544579984323623009U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16853703086012867980U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3591438641820423822U;
            aOrbiterF = RotL64((aOrbiterF * 3570430739475340845U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13974806289212867511U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7893287783892523139U;
            aOrbiterD = RotL64((aOrbiterD * 6648351608953339723U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 44U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 24U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 22U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25316U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 28715U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28505U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27962U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 44U)) + RotL64(aCarry, 19U)) + 10881271196314989997U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 6406461249988567558U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 3U)) + 17255067918280095959U) + aNonceWordC;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 35U)) + 16690850682497718411U) + aNonceWordB;
            aOrbiterH = (aWandererC + RotL64(aScatter, 27U)) + 5576201059361086866U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 30U)) + 11991259685693687554U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 14652535244217836909U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + 1701789037170782122U) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 51U)) + 953429054903473833U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 23U)) + 12064513610469714211U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 7993881398822002424U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14421313768013320050U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11112386845630998889U;
            aOrbiterK = RotL64((aOrbiterK * 11771526352030371669U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17069630896535699015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3308240081138623373U;
            aOrbiterH = RotL64((aOrbiterH * 10449509484417835159U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17615529807112933619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11782807146851563541U;
            aOrbiterD = RotL64((aOrbiterD * 12992075832343669221U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14401645829607611983U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6736397344219993532U;
            aOrbiterA = RotL64((aOrbiterA * 1667287547938175641U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6446974060524700550U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7840991992443308254U;
            aOrbiterG = RotL64((aOrbiterG * 6891023544882740107U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10362169906019794305U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4503700997923168911U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15066164494038852559U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13492041134973259041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14337899277551397976U;
            aOrbiterI = RotL64((aOrbiterI * 5966740718899290915U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13693100781608180748U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16177545026405910052U;
            aOrbiterB = RotL64((aOrbiterB * 6019231448444020563U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9641191118119415680U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 735491776764667034U;
            aOrbiterC = RotL64((aOrbiterC * 11305930862759869997U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2225714710491247284U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16906789796765378455U;
            aOrbiterF = RotL64((aOrbiterF * 4341667316266234469U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9451961177946601088U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 10881271196314989997U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 10929686721061541543U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterK, 54U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterC, 18U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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

void TwistExpander_Archery_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC4BBC17D1913374BULL + 0xE8C68B0BE6D7BB35ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB706542FFAE51F57ULL + 0xB718C72DF3741E22ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB66CCFD3650E1E45ULL + 0xC4208E07FB79C26FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x83823C2A3F7F58B3ULL + 0xA90EBDBF1F65545FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCE4AF59458B5FC37ULL + 0xC0F9B488F60ABF8EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8322A10EF90CDAD7ULL + 0xD1695E8ED8EFB4D7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB265D23692F46FBFULL + 0xAB4F48BD214D6FC0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBA79D8F2CCC8FD81ULL + 0xB76CA181A0AADF6DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE4FDBF136D951137ULL + 0xE67F5611D4DFA67BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA06E924EC4279ACBULL + 0x8607E4004A907802ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC8DE5DF75738BF11ULL + 0xFE277E957F3A7300ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x892B6F72C06CAE2FULL + 0xF8E4D9FA560D3BC8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x92173728F1DCD729ULL + 0x92E4B189168E09CEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE580448631D3A893ULL + 0xED773E6898B2A5DDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC9815BA7798E9B1FULL + 0xDE6AD71508A59725ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFC3AB7A7A6199BBFULL + 0xB417E5B86D86CEBBULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1827U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1533U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1700U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 459U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 4980738603982643969U) + aNonceWordP;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 17660278413018470020U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 17598114429859543466U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 52U)) + 10993929335279994739U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 29U)) + 17967203122976322481U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 1872290205549034384U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 37U)) + 16607778671782810797U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 4895226930754394376U;
            aOrbiterD = (aWandererB + RotL64(aCross, 56U)) + 14960359005982301383U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9921642352377700630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 893281964367208693U;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8232519988397858732U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 4433022122758913407U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 834240393225479419U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12689609831247168353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 404535388957472176U;
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3349108201964013155U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4386449511297371730U;
            aOrbiterD = RotL64((aOrbiterD * 9596273264321140229U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14314587717949070586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10923886625271054985U;
            aOrbiterE = RotL64((aOrbiterE * 7838969002623486809U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17634909585329833520U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2021301459918350372U;
            aOrbiterJ = RotL64((aOrbiterJ * 1388242915918642741U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5219599112498224367U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10641339455385046206U;
            aOrbiterK = RotL64((aOrbiterK * 1022283727595400719U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5003342156562330058U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10951027475628404336U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17836928292555158461U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13040991872592235460U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11149099984302782267U;
            aOrbiterH = RotL64((aOrbiterH * 4248667283139686251U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 28U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 29U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 47U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 58U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6300U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 9362U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7541U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6443U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 9914837590440975587U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 27U)) + 6706125076401958051U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 16570817772679258409U) + aNonceWordO;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 6843705658115186948U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 20U)) + 16099930446791572351U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 57U)) + 5420550009556030459U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 39U)) + 5729549069420177477U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 51U)) + 15590601126188675834U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 34U)) + 13044027390998620029U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11068338135659636772U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6584988841809544332U;
            aOrbiterA = RotL64((aOrbiterA * 1683336180438945439U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8516813219883915404U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10647314042912492785U;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 3883760518944464145U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13861805129175491145U;
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12019138626550801486U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11724200983306280107U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2643807255422544248U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4127143302485631794U;
            aOrbiterB = RotL64((aOrbiterB * 5441038881111578487U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14602951930809633069U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4555737199162278494U;
            aOrbiterI = RotL64((aOrbiterI * 12415825635220991865U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6343143902997169834U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10404783711336491985U;
            aOrbiterF = RotL64((aOrbiterF * 6235474458879439079U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7406959231434835393U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6684368109277850196U;
            aOrbiterG = RotL64((aOrbiterG * 8760360417572331159U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterG, 6U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 53U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12639U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11697U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14112U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 12360U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererB + RotL64(aScatter, 21U)) + 18144572925667544139U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 53U)) + 5659758077574059728U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 46U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 17754639838410839447U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 57U)) + 9451843819849581729U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 5U)) + 7957854457197462212U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + 1461994799722205010U) + aNonceWordP;
            aOrbiterK = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 18002214276252170177U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 36U)) + RotL64(aCarry, 35U)) + 14689869073147027164U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3978104368003440293U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8512135845221335386U;
            aOrbiterJ = RotL64((aOrbiterJ * 10506667163729414667U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1477533446382953439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8082437060686606995U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4363687722464700362U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15782763348014924206U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8572509150015960728U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3340528604891897779U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12248271773316742521U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterD = RotL64((aOrbiterD * 1860631869877427405U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17244849374768558859U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1030743048280579012U;
            aOrbiterB = RotL64((aOrbiterB * 10858949914285817051U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17722342363541914280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15667504059789880034U;
            aOrbiterH = RotL64((aOrbiterH * 15872269872168533709U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12645332941998550794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9938135244509986497U;
            aOrbiterK = RotL64((aOrbiterK * 16548185968987392957U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4024609904162105979U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6732064218696157303U;
            aOrbiterE = RotL64((aOrbiterE * 3815409766145891393U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 46U));
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 18U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19615U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17677U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20669U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 16543U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 58U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 47U)) + 4634399531433127141U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 16961792729406903200U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 4105280732301137738U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 27U)) + 15692013501147331191U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 1252216715968780587U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 19U)) + 7958289043012473752U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 6611577301818896615U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 36U)) + 8506226754305949140U) + aNonceWordA;
            aOrbiterH = (aWandererE + RotL64(aScatter, 13U)) + 3648813120449403353U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5195245426245535735U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 542948051600803051U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4631106308856448475U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11974253551208964789U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10596463592332655367U;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12015129484061440159U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8254944355710109060U;
            aOrbiterG = RotL64((aOrbiterG * 3233697992479357615U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2754858806943915419U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5007802002906662779U;
            aOrbiterJ = RotL64((aOrbiterJ * 15613733948331639723U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6262190752136523216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10528977986487821428U;
            aOrbiterA = RotL64((aOrbiterA * 1184258264034585525U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8511097226098211854U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12091864735686692582U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6128140528141411237U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4970966265236842566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10728884018459718341U;
            aOrbiterF = RotL64((aOrbiterF * 18205183219769602827U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13760057185629905360U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6590269178744829056U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 14482684769712170123U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 765826377665103262U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9364759196106579706U;
            aOrbiterD = RotL64((aOrbiterD * 10315111163659289329U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 26U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 30U)) + aOrbiterD) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23165U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 26103U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23780U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25876U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 8101351470141807662U) + aNonceWordM;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 6965474099521076705U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 19U)) + 6803828268885684784U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 53U)) + 13454235922950972488U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 47U)) + 11678091885751244777U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 5307134544628507141U) + aNonceWordJ;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 37U)) + 4873703518950429353U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererG + RotL64(aScatter, 14U)) + 8542156221858586039U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 23U)) + 3993726182905296513U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12113047622035464386U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1944244448665721151U;
            aOrbiterH = RotL64((aOrbiterH * 7010050836758762003U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12914188029425467576U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2486762763475327024U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14580191602982245481U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12093414832400135066U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13623906997320021065U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9977356009806428696U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2005536391712733499U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3694954095397810851U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11453812627797091638U;
            aOrbiterK = RotL64((aOrbiterK * 13730420725113907161U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 542311345544726351U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3024285045990499484U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15397664082460849530U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10716856680110815056U;
            aOrbiterC = RotL64((aOrbiterC * 13947203772929252823U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 833342121331428547U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1111339940097269219U;
            aOrbiterE = RotL64((aOrbiterE * 17991642769781175473U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9312963978841402871U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8225496710723213204U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 894499195498817065U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 52U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 14U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31839U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 27375U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31530U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 28948U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 24U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 26U)) + 15652862298542575895U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 39U)) + 16925323928418184554U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aWandererH + RotL64(aCross, 35U)) + 4413861484961668394U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererI + RotL64(aIngress, 11U)) + 2215946422098155969U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 14975185533513111110U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 9711613814905834552U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 13154957291850149471U;
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 5058313016418534840U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 4U)) + 15011423472941211620U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2030053257469580168U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 150530795186791193U;
            aOrbiterC = RotL64((aOrbiterC * 11106050063717096073U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10878237472104183427U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16158741837357985395U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9589700906445846956U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1367381624958248949U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 8459515089081211977U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12003215666757518106U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11232479330848006729U;
            aOrbiterK = RotL64((aOrbiterK * 10993290955464593033U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13013910456628561621U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6092509838924105265U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 805601154718006061U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11999225836250312801U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14421271973875748413U;
            aOrbiterA = RotL64((aOrbiterA * 9529010940887430157U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15536288285741825272U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2071793889925436679U;
            aOrbiterH = RotL64((aOrbiterH * 1526376970151714589U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5622386476463436967U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16147972771639168516U;
            aOrbiterD = RotL64((aOrbiterD * 11826916832825159095U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4519892856053952290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12059500374938843538U;
            aOrbiterG = RotL64((aOrbiterG * 14987533625537956299U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 52U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterI, 36U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA7805EC0F088A763ULL + 0xBCF5FA41FD1A92DCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA99D4F2D0997A153ULL + 0xDEF09DCA841B8DDAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBA709B5C0E9CD297ULL + 0xBF1B4220B5BE2DADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBEA2AA256E3DCDEFULL + 0xC51B1109055DA5BFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9F77D5A986B9EB13ULL + 0xE360A2D6392F787BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF54F0AC49F4B6F03ULL + 0xC3E9B76773330967ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA47D39FE396A321BULL + 0xBC82FF570ABAE015ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x81AA272BB684182FULL + 0xF22BB980A2100046ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCC0F19647776B793ULL + 0xF1D8E09A9579D2B9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD725BD8553AF5A1BULL + 0xED9739AA40AF9A69ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFEABA7221C7011E5ULL + 0xDD13BC6D416504EAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDE9169AD5B232523ULL + 0xB4EB6E4F48D5D8E6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFFDBCDE800248A8FULL + 0xE2419347B2F27C16ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE1208C56FD7CBEBFULL + 0xB23F893B24495481ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x95347DF9861B99DDULL + 0xE52E72D8366AB3ABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCB6A9A814D56E147ULL + 0xB967A82FE3B8B93AULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3926U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[((aIndex + 61U)) & W_KEY1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5058U)) & W_KEY1], 23U) ^ RotL64(mSource[((aIndex + 2866U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 16462052553719977502U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 13U)) + 12337064059566619581U) + aNonceWordM;
            aOrbiterI = ((aWandererD + RotL64(aCross, 19U)) + 15801005007094515447U) + aPhaseAOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 8228706742665081656U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 11006723027845190869U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 35U)) + 18173765337829177450U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 43U)) + 530215083653542558U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6608611827035564511U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2246051826221626809U;
            aOrbiterI = RotL64((aOrbiterI * 6333352641495253539U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5228575308895381421U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10999213210689606857U;
            aOrbiterJ = RotL64((aOrbiterJ * 5467601259546342925U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3773371037240485696U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11150566414723818350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8336366151003049546U;
            aOrbiterD = RotL64((aOrbiterD * 9033771197242493699U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13233968794237090787U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8172558473508478819U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17837070423649268435U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 133564480283347997U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15104810248883567064U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 706802420642303533U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9138629520201127075U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13993086066341664080U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4875046427147105077U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterB, 44U));
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8675U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 6851U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8599U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 8002U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 13U)) + 10812151398716051703U) + aPhaseAOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 18202551453336003710U) + aNonceWordB;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 27U)) + 9434410809101973752U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 12955829998028534045U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 12271740641929640181U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 20U)) + 14009351527014534752U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 53U)) + 4316296955679133450U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16473324966997442872U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15735123324965019802U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5624078184997601019U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17656375090484080236U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16066325053456055298U;
            aOrbiterG = RotL64((aOrbiterG * 17912970706985130327U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12908968778503516903U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12761433987676836197U;
            aOrbiterK = RotL64((aOrbiterK * 1023329467480907925U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12737513138040664509U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14535795767570998392U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15560519667062222269U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14370908061811284364U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7001358781208669795U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11641248025734015835U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7298578161120090849U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10498302152357484629U;
            aOrbiterB = RotL64((aOrbiterB * 13144110412179037175U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11447343228638006767U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 18284143620422655675U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aNonceWordK) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12690U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14562U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13305U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 13282U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 11U)) + 6068543441070417854U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 2995980468193441856U) + aNonceWordH;
            aOrbiterI = ((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 57U)) + 18020277482171594003U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 4293807434721230702U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 19U)) + 7980599111583893156U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 8593141111851052016U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 57U)) + 5903487523900084325U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15112035513447930209U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9854037263057006439U;
            aOrbiterI = RotL64((aOrbiterI * 396276470208637283U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16759760289688823193U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12622628933030601390U;
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1264668857268123425U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16302812053619101593U;
            aOrbiterG = RotL64((aOrbiterG * 18291400055836111547U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16087995784896123610U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7970269262800468363U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 14924752223305807461U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5331477046030959632U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16534913204255550893U;
            aOrbiterH = RotL64((aOrbiterH * 1013433634373673565U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11042821902537871209U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8069677512345031660U;
            aOrbiterF = RotL64((aOrbiterF * 13622218526054132397U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5737130058129936372U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1076627182956662997U;
            aOrbiterJ = RotL64((aOrbiterJ * 14342191224014199929U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 34U)) + aOrbiterI) + aPhaseAWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18092U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 20797U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16994U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 20375U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 7893287783892523139U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererF + RotL64(aIngress, 43U)) + 10257331997383491153U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 22U)) + 14562226733652231753U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 14320342577110737851U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 37U)) + 9816717579822880756U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 9558926960095881953U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 9230371862654338324U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6414274291252913420U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 13868546184398350849U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 1547986864837497409U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16940736952569949038U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2866957764814864371U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3554702178644797003U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7916721976073979724U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1602444214978842275U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11072503711308122385U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9529061385251008037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8402775110887376588U;
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15003592180290390713U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14195681406520825751U;
            aOrbiterJ = RotL64((aOrbiterJ * 11455000833788877217U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3263577002367714202U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12019422062655581928U;
            aOrbiterF = RotL64((aOrbiterF * 5002313835338447799U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8508638054582582917U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6536618106353552880U;
            aOrbiterA = RotL64((aOrbiterA * 6233964121117511885U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordH);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24851U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22181U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26260U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 23179U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 42U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 16183871922837164759U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + 7002058258090219055U) + aPhaseAOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 19U)) + 5650868611888303705U;
            aOrbiterB = ((((aWandererB + RotL64(aPrevious, 34U)) + RotL64(aCarry, 19U)) + 11899839660943876690U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 15349649504488111111U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 3U)) + 14060149569086744970U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 12920917574225030112U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2831994965175330135U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18312543585028439192U;
            aOrbiterI = RotL64((aOrbiterI * 11618182708195744321U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11657562205118394239U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10850792819281246052U;
            aOrbiterD = RotL64((aOrbiterD * 10663100544207879337U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17810371216216125323U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7963413941144223128U;
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5498715358793875584U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9256727548911651373U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 10498848323914000989U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17246360111302191699U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3100998994319502921U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8129301860291235970U;
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1889641029473279114U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16538494307002917945U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aPhaseAWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + RotL64(aOrbiterB, 12U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32421U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 31055U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29891U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30974U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 12U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 29U)) + 8367680518550579791U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 12U)) + 11491674725611181241U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 16673861720782164214U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 9786610124108350855U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 5745080601557577637U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + 1959402215131684684U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 57U)) + 6121650036079196522U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12016309761037342392U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5986936646177049603U;
            aOrbiterA = RotL64((aOrbiterA * 3585650475703294895U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1000367700904043468U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17425288243569101032U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 2174614006719048535U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4856917474950325209U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16312111093223166419U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11046477664487805241U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 456110002032422270U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11393724374787795662U;
            aOrbiterC = RotL64((aOrbiterC * 1176984359123668389U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8378176867715697176U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 8086186452345234815U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 8450438271765985235U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8470349167474173245U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2528229938740192694U;
            aOrbiterF = RotL64((aOrbiterF * 8717790851266520943U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13247168811545753141U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8745293957516815264U;
            aOrbiterE = RotL64((aOrbiterE * 14270617180621072619U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 36U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererA = aWandererA + (((((RotL64(aCross, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordP;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC38FD663DF27A02BULL + 0xC1FE58B21ABA2AE6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD5307E65D67CD6D3ULL + 0xBC5DE69725625ED0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x90C4B22BF37F432BULL + 0x93964568AE6185B8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x832F49A4A713CF85ULL + 0xD86923A30A67D938ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBC8C556B3BCE93F1ULL + 0xABF7229FBD7738BEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFBA066F1F8F7A2CFULL + 0xAF8E9C2DB27C6D2DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB97A14B5A2FCB7C7ULL + 0xFB148FC0DF16C549ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFE9B60C5B35492CBULL + 0xAA9219D6E8A5B0B3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBAB3B1709F1A7DEDULL + 0xF225C49A84ADB9D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAE2E73FF47663C29ULL + 0xCF406E82F4778B4FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF426C02E67E5683FULL + 0xC470DE8AD1A3B7ADULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB1AFBDCDDA20AD7DULL + 0xBE62568D59413F4AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAB97547FB77BD81FULL + 0xD9E6A5F086A66C71ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC0A94833BAE5537FULL + 0xED59A4994A862D29ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x971D84D9CF7D6267ULL + 0xA3E9E4BE1BDE80BDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFEE9CDCFC86D63D1ULL + 0xB8C082E895598350ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5382U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2717U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1793U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5189U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 1142447269198373880U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 47U)) + 10581460640040336191U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + 14703062773878202900U) + aNonceWordM;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 15737525756286914746U) + aNonceWordI;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 16178774478273186999U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2514897053906809160U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13702496607592508464U;
            aOrbiterB = RotL64((aOrbiterB * 16540143680974064057U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18030885275418337965U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5241783876161655984U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10970981186787227937U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2807052676283587925U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8022804576763271327U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15597099852232205860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1538435607932096400U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11147868774413615365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 18U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aNonceWordD) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8319U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 7266U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9709U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9258U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 2974056819475622600U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 7345051759236356098U) + aNonceWordM;
            aOrbiterE = (aWandererB + RotL64(aIngress, 38U)) + 12738468816846628882U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 7694520596043297922U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 47U)) + 5530753590015084774U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3776309161718383105U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 784780304358106404U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1503119308251871519U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 8999942326995036509U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5194986506064092779U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15070787038006135963U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7920040007459652762U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11311997270710107937U;
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5365231114813547251U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 8630110234623825263U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 2735881715888325759U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2358235238039571072U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18059414891616491807U;
            aOrbiterJ = RotL64((aOrbiterJ * 17150786106857185467U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 30U)) + aPhaseBWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11188U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 12491U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13533U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13946U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 4U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 51U)) + 13350544654542863236U) + aPhaseBOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 12364346790125404372U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + 9738750172849512764U) + aNonceWordP;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 3781373837635491421U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 43U)) + 16635020317512702337U) + aNonceWordG;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5383653921676231276U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10181959815492056493U;
            aOrbiterE = RotL64((aOrbiterE * 14784636206508715141U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10005510924273927017U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9524687662265740565U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13687380438646756931U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4259138552009771014U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8973051213213726023U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 12625091476068190979U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17602611840127337490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18102186122213487888U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2629927500298092976U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + aNonceWordM) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordH) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererI, 4U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21144U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 21318U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16505U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19824U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 5U)) + 1457104756581596530U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 6127240317844622874U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 16492290056044189421U) + aPhaseBOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererK + RotL64(aIngress, 30U)) + 10963676850938416468U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 4872917367399752405U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15218882377875616148U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5934166612122118251U;
            aOrbiterD = RotL64((aOrbiterD * 10365045124180379919U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14215280930872003003U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11428034799044600979U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12162528943733976177U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5453003654321728726U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14273775120265649389U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5139018128323795309U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 328723770018440271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13032190719588211088U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13363368478932798315U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2386881543033598494U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1649501123340887116U;
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 57U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + RotL64(aOrbiterA, 48U)) + aOrbiterC) + aNonceWordP) + aPhaseBWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23783U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22448U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23014U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 23388U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 58U)) + 12980104182836602177U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 35U)) + 3172622203188863995U) + aNonceWordB;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 1170974132219980203U) + aNonceWordL;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 6035201940965047490U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 18033907118424996722U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14604813424800580304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13720232492851066035U;
            aOrbiterI = RotL64((aOrbiterI * 8927246214721284759U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3902659710585257448U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8331560652661619868U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11418103770615560205U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4485014147538689794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 168202636924512424U;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16227825670092707848U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4792781933944671365U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12636865372722601282U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18198291399585556632U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aNonceWordI);
            aWandererG = aWandererG + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordG) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterI, 46U)) + aNonceWordC) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27903U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28815U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29363U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 29349U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 48U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 21U)) + 11210042748013785976U) + aNonceWordE;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 4584747303233477454U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 39U)) + 8878765929792969517U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 2172232330280041122U;
            aOrbiterB = ((((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 8378937026022264016U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8683007464695824208U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9564352997357118134U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 17869948990449143305U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11713878436769887528U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8052917623074021077U;
            aOrbiterH = RotL64((aOrbiterH * 7450115139081623477U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7720597162792145185U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2602847785328475621U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 14065077077207224525U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17813669222300509724U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8724263063156573013U;
            aOrbiterI = RotL64((aOrbiterI * 3632927017737834359U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6882429835961613492U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13213313479525717359U;
            aOrbiterB = RotL64((aOrbiterB * 2411431247725974895U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 46U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Archery_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x95CE0C2971616131ULL + 0xC400227F51A9F800ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAD200FC1E4CB0DB1ULL + 0xF066195A18D2D970ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBB616069061288C9ULL + 0xD662A3C21CE93C54ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF216E4A4113D6179ULL + 0xE53F7032C5A2F77AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAB5A0B715495AE47ULL + 0x98E296C3D911D00AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA94229945DC11651ULL + 0xDB305E47FA508E8AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x92D465A06716B84DULL + 0xA24B9A34B0B75C18ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBD3F185E7FBFA689ULL + 0xF6D95EE5352582EEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA2ED57CB056ED9B3ULL + 0xDACFFEA79BFEAAC9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAFCCEBEBF59C7759ULL + 0xBE0F7E6F2005DC4DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF1A24E6B26421965ULL + 0xADD27FD3F63DFC6DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE7A9DE1313A5434BULL + 0xDEB6E991B29C62C4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD9FAFEED1F6C1955ULL + 0xA3B6BA133BCB7A35ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x833C1BD2FF2958FBULL + 0xF67BE449F4204F15ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE3BFF2CD933DEB15ULL + 0xA761B7B0A338278BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC6947AEFCC941ED7ULL + 0x9623F3A7C1DED304ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5432U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 173U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7543U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4630U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 36U)) + RotL64(aCarry, 5U)) + 15910560457440369082U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 13U)) + 17953072986407436888U) + aPhaseCOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 15446940721193538669U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3020785262774422009U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 18U)) + 7001288645424994404U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + 13385250665458462689U) + aNonceWordM;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 27U)) + 4841895644623005949U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 13053476783239482065U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 641996979335975244U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16211238020928688299U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12715448751323279480U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 2116880429675303291U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17784406727699995290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16626339815786580778U;
            aOrbiterF = RotL64((aOrbiterF * 13940754474750138041U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9035070625716345139U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6085848172494001945U;
            aOrbiterJ = RotL64((aOrbiterJ * 10405728912339646693U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1177103851507561053U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2281901691017816407U;
            aOrbiterH = RotL64((aOrbiterH * 3142197009403602497U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9040984343694325070U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13334258224023902365U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4782523727707164869U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1079824790138592518U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14024082692012948652U;
            aOrbiterA = RotL64((aOrbiterA * 3219489374333737903U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2966776524421278970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5510281854029308547U;
            aOrbiterE = RotL64((aOrbiterE * 9275402927591867297U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7126632329316720048U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1476827035602733472U;
            aOrbiterI = RotL64((aOrbiterI * 2217671289726794033U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6470212302133184965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4172257438373147415U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4449314239630366533U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 10U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 36U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 4U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11906U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 16111U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10400U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14811U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 24U)) + 2915859148137000694U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 47U)) + 210680583721444425U) + aNonceWordO;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 6668118118775650387U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 19U)) + 15794200818099010989U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + 6565076707062828369U) + aNonceWordA;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 16323164497808856719U) + aPhaseCOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 6U)) + 7965435318816716560U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 35U)) + 7390281030573369017U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 2269738866911824875U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9664014216039993873U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18284857398028357633U;
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 367667619795303009U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7935945060956274197U;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16683666162337789540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10655658270998102390U;
            aOrbiterK = RotL64((aOrbiterK * 15231596813382239841U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8307037916581540297U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3247742749860703524U;
            aOrbiterG = RotL64((aOrbiterG * 15052136713218656641U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10446792483683818139U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16374602929344972364U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 12599903932725787599U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2411334498322777183U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1093701164116833765U;
            aOrbiterF = RotL64((aOrbiterF * 13129220206835381729U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17018480952982840635U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17348395690080029814U;
            aOrbiterH = RotL64((aOrbiterH * 6212591395713433257U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16111252311283623152U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12776492920397785951U;
            aOrbiterJ = RotL64((aOrbiterJ * 6136009241593081821U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12214538600808144816U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10043377462096783363U;
            aOrbiterD = RotL64((aOrbiterD * 14639467375095185877U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterE, 14U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16959U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22083U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22755U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((aIndex + 18951U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 12535417189990029950U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 37U)) + 6204401443676390273U) + aPhaseCOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 27U)) + 869613505613154672U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + 15053590879563855802U) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aCross, 51U)) + 13338989605204591428U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 18U)) + 18306470022403825392U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 1150696349434090218U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 13549541786420596437U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 13U)) + 14302878430259588461U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4660437084477165225U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1653628537860912069U;
            aOrbiterK = RotL64((aOrbiterK * 2624835201155303123U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5594199757006711631U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11008472193138708891U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13645764762027798301U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3668516817279364310U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 128159531749679984U;
            aOrbiterE = RotL64((aOrbiterE * 4523246859249826987U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6378674346113979108U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11438762460659123362U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2733309638158283953U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10624263004446482910U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12546839706919241411U;
            aOrbiterH = RotL64((aOrbiterH * 11468326687628079347U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8466639576503293921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5828694979857951504U;
            aOrbiterF = RotL64((aOrbiterF * 7835487310289634515U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16496305151014092976U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 589464613876410567U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 13190816610718051897U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4168532743415647825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15944887793736489375U;
            aOrbiterD = RotL64((aOrbiterD * 17273403561158196717U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11642456814106259483U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1609897693632334867U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12912773555616819941U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 30U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterI, 39U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 20U)) + aOrbiterD) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25272U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27848U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28286U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27876U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 18U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 13481227414590594621U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 17425964381118918026U;
            aOrbiterC = (aWandererI + RotL64(aCross, 23U)) + 4792004356135956581U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 60U)) + 11926849936000639098U) + aPhaseCOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 43U)) + 990697329347742142U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 27U)) + 9307721505373076588U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 19U)) + 17605732738841908719U) + aNonceWordK;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 13110764518634187439U) + aNonceWordH;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 38U)) + 17970109897810645911U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10273133817644703654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11239046688920468137U;
            aOrbiterC = RotL64((aOrbiterC * 5197802934333553327U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8355821483275763145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15522151127786049345U;
            aOrbiterA = RotL64((aOrbiterA * 4844278537850520413U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 5381663179722418112U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9551368011768104906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14202470972121732997U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16264476585232221270U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7721417776432288282U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10267770327791051869U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 339418090653475277U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3390560045236418590U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3894024951542543635U;
            aOrbiterD = RotL64((aOrbiterD * 10599637790900418767U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3878539166189668154U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5617705593218220843U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 82771190372750823U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12320861089148474544U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14943790251625519550U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13758322022902008313U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18119213517612562775U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1413193144229486646U;
            aOrbiterF = RotL64((aOrbiterF * 14562375280658115687U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 57U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 38U)) + aOrbiterC) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 6U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordA) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordJ;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB50C3BE6F0533629ULL + 0xC7ABE9556BA88932ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8DBA7F4BB3361FE5ULL + 0xAB92C1B000ACC930ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB12186261AABD6E7ULL + 0x8A57126B9EBD77DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB3CEBFE5AF2E5915ULL + 0xC0E2CFAF15100B27ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB37CA15F26D94435ULL + 0xD78DB37506986C1AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD95ACBEFB30D585BULL + 0xA126F1D939BA0087ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x93DD90AF7DAE50BFULL + 0xD86CA210F8ED6F27ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8590468E74A12FEDULL + 0x97BE1C3ADE9D63E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFD4C0DEB0403FEA1ULL + 0x934974C0EB8CBF68ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC489FA2632528AC7ULL + 0xF445ABB171F41698ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAD76B50A7D22AE9BULL + 0xBBB5DAB78E924068ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEE14EE67C0855CD3ULL + 0xF021BB9F5B9CBFC1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB9E6861FE1CC0F83ULL + 0x8C5CE7DE3B064321ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA6C47C32EEB83DDFULL + 0x888325DA8084A42BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCF7EC8148C383025ULL + 0xB8138B7FC009E88CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDC446F795368EE51ULL + 0xD97CCB60507469DFULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1963U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 2790U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3549U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 3644U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 53U)) + 3448371607470865612U) + aNonceWordM;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 10U)) + 3743742913651580573U;
            aOrbiterB = (aWandererA + RotL64(aCross, 57U)) + 13069491287948807280U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 16872779275586545632U;
            aOrbiterG = (aWandererH + RotL64(aCross, 13U)) + 17945792656755062795U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 18199747196793731853U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 51U)) + 15953311878379809513U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 21U)) + 941268763494588338U) + aPhaseDOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 10090221530365796809U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 43U)) + 8335698093307607001U) + aNonceWordL;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 11U)) + 6147498804734306100U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5980246079567570090U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4152167624425912978U;
            aOrbiterB = RotL64((aOrbiterB * 10019421651535123573U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14990418790239735916U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3418668387496597219U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 12814077238529863119U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4206650904177199425U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3905470780938996069U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16030122739273137005U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9968672788233080924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterI = RotL64((aOrbiterI * 2615726693066300065U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17751667243048041383U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2414054413585296027U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 1049512574773201893U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6523322402744047752U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6729901917767398779U;
            aOrbiterC = RotL64((aOrbiterC * 8039939871405367139U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11460169185076814539U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7559640379553110573U;
            aOrbiterJ = RotL64((aOrbiterJ * 9864654321914036135U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17271150091827475028U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 3541809324556914646U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 12655168871428868639U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10332471447306597185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12580133010006951091U;
            aOrbiterG = RotL64((aOrbiterG * 1159183486084705865U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17333553613777910945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14179392055698682109U;
            aOrbiterA = RotL64((aOrbiterA * 17675559451285279251U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3996830751779338356U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3448371607470865612U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5375529914102609947U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterH, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterH, 44U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterD, 14U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6674U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 9890U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9727U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 7809U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 18191288703716505885U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 9824014524910417136U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 11953012029254917548U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 6297568011027199089U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 40U)) + RotL64(aCarry, 21U)) + 2576999400457367975U) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 5U)) + 13176139160575558254U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aIngress, 37U)) + 9978408174563621810U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererG + RotL64(aCross, 47U)) + 16765834875061607142U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 16534507305459121344U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 53U)) + 3114710944346151807U;
            aOrbiterG = (aWandererD + RotL64(aCross, 18U)) + 10240517868726718592U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10721450637990777883U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2427422768928450209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13495584061816457831U;
            aOrbiterH = RotL64((aOrbiterH * 6670984773768885119U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7058636403765106682U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9897341853944713767U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17749559755733386064U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12515645083926326659U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 6582878478865838245U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2625692458813609962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10596240255026143019U;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12374290338067865540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1507386663796330249U;
            aOrbiterD = RotL64((aOrbiterD * 1210241080424446087U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9288099549484146726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15159312464747000702U;
            aOrbiterA = RotL64((aOrbiterA * 500055502081347757U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 14998608679505446229U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17625038109437732009U;
            aOrbiterK = RotL64((aOrbiterK * 14785862243019841689U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10543192232885637211U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10330547522729618042U;
            aOrbiterC = RotL64((aOrbiterC * 7635903835474874057U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5753298214283941201U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15943436872588208065U;
            aOrbiterJ = RotL64((aOrbiterJ * 17704547766822075741U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5757218926946874970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18191288703716505885U;
            aOrbiterG = RotL64((aOrbiterG * 2644970408001409575U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 14U));
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 60U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererI, 28U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12401U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15720U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15111U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 12870U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 26U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 8402620908307642697U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 35U)) + 11347672014525086047U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 54U)) + 2816462912503401876U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + 6940159795470696093U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + 9134692490095883851U) + aNonceWordM;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 29U)) + 4999455497008026526U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 5U)) + 5992451460350651332U) + aNonceWordO;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 3417087346651371924U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 37U)) + 3612773820086198270U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 20U)) + RotL64(aCarry, 47U)) + 463398077083428570U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + 11249391303705089012U) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17027535139825739501U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 568131384979596481U;
            aOrbiterH = RotL64((aOrbiterH * 5683451044852895957U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4793712537158004047U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10415170179135963622U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13729564030210361415U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2391473979460065630U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4240058362680064261U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12375884373396400889U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9963957011090031698U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3325305624067445525U;
            aOrbiterG = RotL64((aOrbiterG * 3128542681461806309U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2094945647665114693U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10703615640774042674U;
            aOrbiterA = RotL64((aOrbiterA * 12641986098450423751U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3768738815518590289U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15021301790376706827U;
            aOrbiterD = RotL64((aOrbiterD * 14445850924223550339U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10571246886181608316U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5130325144599151793U;
            aOrbiterI = RotL64((aOrbiterI * 3185251943547657467U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8617523421720966373U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16574597770835250074U;
            aOrbiterK = RotL64((aOrbiterK * 1759209403428937799U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17474733286551120355U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17914672092861237776U;
            aOrbiterE = RotL64((aOrbiterE * 13657291990878792267U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12856557371623447773U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1636296609747335898U;
            aOrbiterF = RotL64((aOrbiterF * 9286345529656087313U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12588848560509679821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8402620908307642697U;
            aOrbiterJ = RotL64((aOrbiterJ * 2269772223506258147U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + aNonceWordI);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + RotL64(aOrbiterC, 58U)) + aOrbiterI) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20164U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 17972U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19974U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18365U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 24U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 15316464782468770057U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 5U)) + 6642872057476351588U) + aNonceWordI;
            aOrbiterK = (aWandererC + RotL64(aIngress, 43U)) + 660732654689529192U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 7235418086884000655U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 51U)) + 14784518476694580493U) + aNonceWordM;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 19U)) + 12222433977933449375U) + aNonceWordG;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 8573001207708329927U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 16035256260815013172U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 15767726974121910203U;
            aOrbiterC = (aWandererA + RotL64(aCross, 47U)) + 17712217935322939971U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 24U)) + 13488963456923357159U) + aPhaseDOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10222949131965611079U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterK = RotL64((aOrbiterK * 9706305581868526265U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16156530750584361434U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7773792489045606309U;
            aOrbiterA = RotL64((aOrbiterA * 10730624207715601393U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11544578291333360613U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3665587867634242865U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4840528190844842595U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15248434984650998090U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15487979645426567581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6972347795052712690U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16074994810010431338U;
            aOrbiterD = RotL64((aOrbiterD * 1262655238856775853U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16851139687900415292U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14630026837021552812U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9577900853521254603U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14236330619137368169U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17778707026111136216U;
            aOrbiterC = RotL64((aOrbiterC * 16239561893843454747U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9390961969105999083U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1174881758316573228U;
            aOrbiterE = RotL64((aOrbiterE * 6602061268277529311U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3025148570039849574U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2813499258480831171U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12272555492688861861U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15397952138592662354U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10394648143430175275U;
            aOrbiterF = RotL64((aOrbiterF * 18195627209519212303U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3043205345760158739U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15316464782468770057U;
            aOrbiterI = RotL64((aOrbiterI * 8162506622688910545U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + aNonceWordO) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23064U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26828U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26064U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 23070U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 9446153639709651566U) + aNonceWordH;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 10550762260670758167U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 7062634922142578383U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 39U)) + 9178499097812764515U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 41U)) + 6887103379773525538U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 26U)) + 6239750312052010257U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 17645022614523287959U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 57U)) + 3639618183259408272U) + aNonceWordL;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 13U)) + 3131737117548745095U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 7253994382396406554U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 15217993711938379561U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12594152227603630033U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11250170200489647869U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 546800378327864723U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12936942656624279424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10990736056052106149U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12787293075893090465U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17154990205620778151U;
            aOrbiterK = RotL64((aOrbiterK * 10031369940028159521U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1270827262969060301U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17337623431665013136U;
            aOrbiterE = RotL64((aOrbiterE * 1517262088236356107U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 830330490987911853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6828309232554560547U;
            aOrbiterF = RotL64((aOrbiterF * 9742464176986145819U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11470087853413986203U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10470148870747884420U;
            aOrbiterD = RotL64((aOrbiterD * 6766079738799967443U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18315536891901859637U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12264670822285914271U;
            aOrbiterB = RotL64((aOrbiterB * 5841574505408674119U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10931842095884524879U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11134871340959676257U;
            aOrbiterA = RotL64((aOrbiterA * 11714837622285605745U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11484168476761306078U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5964766416973454097U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 14721123403032510803U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10646362765367117994U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8994267196877016381U;
            aOrbiterC = RotL64((aOrbiterC * 17386417559346134797U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16797547458402042464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9446153639709651566U;
            aOrbiterH = RotL64((aOrbiterH * 567585472220695323U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 42U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 52U)) + aOrbiterB) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 22U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29989U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32406U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31811U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 30057U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 13583136155674166402U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 35U)) + 12830472187484919497U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 21U)) + 18081197909484522509U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 8680634051297891550U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 5U)) + 13939998767458656823U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + 1795730579103692594U) + aPhaseDOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 41U)) + 17369751719734069999U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 18U)) + 224769585901248068U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + 4133547085925268180U) + aNonceWordM;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 7022512056309567391U) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 10319484359046945495U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10483878349412282069U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6481381149199985736U;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13721077228796934509U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9704818014314175007U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 760445624027740287U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6253040047758584339U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16890211690273641226U;
            aOrbiterK = RotL64((aOrbiterK * 5622534399866057841U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6216227831265032436U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2023609047004658739U;
            aOrbiterJ = RotL64((aOrbiterJ * 3252332895698310147U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9201669637050388263U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5106927540934338576U;
            aOrbiterH = RotL64((aOrbiterH * 6368134569042291431U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10080368957861445998U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10784789383436485808U;
            aOrbiterF = RotL64((aOrbiterF * 3794918350254445939U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15426339824951793026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17637144549368340331U;
            aOrbiterB = RotL64((aOrbiterB * 10971293914614704441U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 9941300382181962134U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8118046374121322097U;
            aOrbiterA = RotL64((aOrbiterA * 8481945819050983127U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5138086185042567633U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7279942739248982986U;
            aOrbiterE = RotL64((aOrbiterE * 12911998308338410917U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12135610639038562853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12945353426409788798U;
            aOrbiterG = RotL64((aOrbiterG * 7434977715954413699U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7534876598022096222U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13583136155674166402U;
            aOrbiterD = RotL64((aOrbiterD * 8194058098043157015U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 52U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 30U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 12U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 48U) + RotL64(aOrbiterF, 43U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 14U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordH;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC25B64C4152EFD1BULL + 0x9539999DCD56F1FCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCC9213BAAFD991D3ULL + 0xC6175DA9EA2DBD60ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD614FADE5BF2E92BULL + 0xC08976618B55749FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF9EFA2DE6F8D20C5ULL + 0xB7168E2D2BC7934BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF695B1B4DDDE1E03ULL + 0x8A5E24FF70FFBC79ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBA5DD669721BE1E1ULL + 0xEF0D07E4B1BC67BFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD5CB5430BC30E03FULL + 0x8F64FA8CAC712D2BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF839E3B14CBA9B0FULL + 0xEBC2ECD1DDB065E0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEABB816647791BDDULL + 0x82431D7343B89B24ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9F033A0C2B7789E3ULL + 0xFC704A788D2FCBB9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE483476F4C2D5ED7ULL + 0xCF5E412F0BBE1E65ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF68A0A93201EC069ULL + 0xF9F66546B77BC358ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x834001FB75BE058FULL + 0xA13FCCA317A1601CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDA42EF4F47A76A57ULL + 0xDD945E857F823210ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEB2DA3D4E28CD3E1ULL + 0xC94ACDC971E756C5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD3ED16822C6FB6A5ULL + 0xB21088EECBC1D2D6ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3253U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2868U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2917U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 222U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 43U)) + 7825479804710770560U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 5298124167101358123U) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 30U)) + RotL64(aCarry, 39U)) + 17774541024369233726U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 3U)) + 7679371833537454082U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 53U)) + 5385914900748772224U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 19U)) + 3879781930908486531U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 659110346638873236U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + 10749021728538539749U) + aNonceWordJ;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 47U)) + 3631252455767429457U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 51U)) + 2271978810960685021U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 5963558780692551176U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 974909966119198104U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9296998242911152296U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2613629915877957661U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2245318466901521959U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13391076374843288568U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6184487746594236737U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1563385912137291418U;
            aOrbiterB = RotL64((aOrbiterB * 4805455299959232321U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1744840092006498629U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2100927276837188416U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3541788262067077997U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9998911862807246338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12239948725635220096U;
            aOrbiterA = RotL64((aOrbiterA * 7098620484129489129U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3307447094994950246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12746613971448298932U;
            aOrbiterJ = RotL64((aOrbiterJ * 9463975886346934681U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11577488293733790649U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 191108997585598809U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 9574978681405356871U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18096145693841273722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10026281133603934071U;
            aOrbiterE = RotL64((aOrbiterE * 17261343107314203471U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2346682418062064668U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2996178204018644206U;
            aOrbiterD = RotL64((aOrbiterD * 2552965800703390909U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15085425896818988223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1589593231782852588U;
            aOrbiterK = RotL64((aOrbiterK * 1535556765195388675U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17170695588248383518U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7825479804710770560U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7434218282170150533U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterH, 4U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterH, 11U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 36U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6430U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 10694U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6422U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 7045U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 20U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aCross, 29U)) + 4384716820085860551U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + 9715780315942116888U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 47U)) + 15963520052789178632U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 3U)) + 14346700690686392938U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 34U)) + 6005518012489966643U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 2506732930310252119U) + aNonceWordB;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 16782163084851775826U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 823673076571076303U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 53U)) + 1634084509064077736U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 1288134975466877686U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 36U)) + 2998220403162908444U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 220430672180734911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10223923547068528867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12577370238343872139U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11696469696177647608U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6545430420379636963U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8387163146257553773U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5624403902454498793U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9468064161002030997U;
            aOrbiterE = RotL64((aOrbiterE * 8243560528100864595U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4619361544913629805U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterK = RotL64((aOrbiterK * 10879074713156075641U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8728730962617599223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9099675924074253030U;
            aOrbiterI = RotL64((aOrbiterI * 5525644236954497523U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3298303921318288541U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5953276499411658358U;
            aOrbiterH = RotL64((aOrbiterH * 10565471305001292693U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6725769507592688539U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1057277456510215817U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 8269412198279297075U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11317925732206917722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17814749417006079067U;
            aOrbiterA = RotL64((aOrbiterA * 4369209051015735925U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9258362135343403308U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4873837345446960113U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14223381466269503273U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7863380865835889675U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4384716820085860551U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2003891033298374621U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 60U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + aNonceWordD) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 35U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 24U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15253U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15520U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15434U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 13412U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 20U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 17668251151213543491U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 35U)) + 16101602509895104517U) + aNonceWordA;
            aOrbiterA = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 9083915270773304935U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 12810720730318214811U;
            aOrbiterE = (aWandererH + RotL64(aCross, 30U)) + 18113428002071925621U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + 1582208899354109878U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 23U)) + 4180688104819188154U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 47U)) + 8954598189262820611U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 13U)) + 15360094153175355879U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 27U)) + 8383954114668216260U;
            aOrbiterH = (aWandererC + RotL64(aCross, 52U)) + 15626783326234049197U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10609978564404958066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17656516608997517984U;
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 760077259110786536U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3597338735888033063U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4431777844935985157U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10710423172154671296U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 16267496318491473315U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10240882795242085185U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7826053487019825891U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 15053729937684375907U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9418883403715727353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterC = RotL64((aOrbiterC * 16189463984557044693U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11545217316421066655U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 617921402135485341U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 8182920764965471653U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14456933220749921009U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7990243583564535387U;
            aOrbiterD = RotL64((aOrbiterD * 5994900368027985469U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14023633125757654751U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11319146808574958827U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13676159969338309307U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14161653180846538446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17993503892528842342U;
            aOrbiterG = RotL64((aOrbiterG * 12184170842617942651U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10449311783872638478U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17210495321003036773U;
            aOrbiterK = RotL64((aOrbiterK * 17591257107603354151U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14586515403314763393U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17668251151213543491U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9367185933291003363U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterE, 38U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 14U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 48U));
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21089U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19589U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18341U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((aIndex + 19115U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 13278949403988203974U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 24U)) + 9213599924054673756U) + aNonceWordB;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 5U)) + 1255746482932381798U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 37U)) + 11575321997144516122U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 13U)) + 15881587525529432437U) + aNonceWordI;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 9846195809864862707U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererJ + RotL64(aCross, 21U)) + 12319815691858217670U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 53U)) + 16322617427294439587U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 16332130810525887437U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 4920951156015336794U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 60U)) + 16767126455124552329U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12553595911087945223U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1437522202135436142U;
            aOrbiterJ = RotL64((aOrbiterJ * 2001992794165550905U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12313100454852227143U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2761983020631055729U;
            aOrbiterC = RotL64((aOrbiterC * 3874839760378039509U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17635303588421554367U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 788212489507463763U;
            aOrbiterI = RotL64((aOrbiterI * 17896475584538528059U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5192552894670654434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6784748488807738811U;
            aOrbiterB = RotL64((aOrbiterB * 8077237651953896479U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16113417046719114943U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1096874945215225916U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 17308604412622879833U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7610274704570171595U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10466070212284342550U;
            aOrbiterE = RotL64((aOrbiterE * 6449728258497920613U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6777845928873855221U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5251515022021984126U;
            aOrbiterH = RotL64((aOrbiterH * 9018277343404261611U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13849343158824111498U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7977711210181714021U;
            aOrbiterD = RotL64((aOrbiterD * 4182053966171053577U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6494539818728106982U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11314590450226080781U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12455979257225599157U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 552687702594328012U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14961304171192292246U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 846375892915484717U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9771874402848476494U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13278949403988203974U;
            aOrbiterF = RotL64((aOrbiterF * 2119203863777871233U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterI, 22U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 26U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22810U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 25413U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22132U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23871U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 41U)) + 9041099828460168106U;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 12883711604096848454U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererB + RotL64(aCross, 57U)) + 17420968786226443079U) + aNonceWordB;
            aOrbiterI = (aWandererC + RotL64(aIngress, 5U)) + 3448213891716125104U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 50U)) + 11866455977445336560U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 43U)) + 4119356835384495905U;
            aOrbiterE = (aWandererE + RotL64(aCross, 29U)) + 2186212599698637068U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 35U)) + 6506144898969301620U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 12556800923644051626U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 4075551535185182945U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 54U)) + 17877694808492008749U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5553428900598223316U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14362304852277160675U;
            aOrbiterD = RotL64((aOrbiterD * 11415103199856419303U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9174200302876075831U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16110739511917638547U;
            aOrbiterK = RotL64((aOrbiterK * 7004356839428657949U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10189881974519849402U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2128076632642616677U;
            aOrbiterC = RotL64((aOrbiterC * 8860453653433114929U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18133523799074400083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9916472958834153766U;
            aOrbiterA = RotL64((aOrbiterA * 3454601168808001733U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10274457562795569227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14134814273275356425U;
            aOrbiterB = RotL64((aOrbiterB * 15912501063665343159U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6394306369514735480U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4825761192736485643U;
            aOrbiterI = RotL64((aOrbiterI * 12534544147331805643U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5672807934779206275U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3881953574159390421U;
            aOrbiterE = RotL64((aOrbiterE * 7448770570912161095U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12012232712634303203U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14176392925893052596U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11288668529893084583U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 307148402076391033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15380446373458263079U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 15228462337097647933U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4654312690816676129U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10818029316701301859U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16245734506125913215U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7340370713289840635U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9041099828460168106U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 1807356802142268373U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterB, 37U));
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterG, 26U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 44U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27589U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28382U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30954U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30658U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 18U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 4751694786009671052U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 35U)) + 16362725160370844224U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 21U)) + 6360885380915941057U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 56U)) + 5154536007972297036U;
            aOrbiterK = (aWandererC + RotL64(aCross, 5U)) + 9362540581874808253U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + 13902493871525612934U) + aNonceWordI;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 37U)) + 10208452885367546542U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 3U)) + 3117030377279160998U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 17286247690414027870U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 57U)) + 3930314320040949141U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 7289525252391668404U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3434167955466809185U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6137259687928853253U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13992510605237574698U;
            aOrbiterK = RotL64((aOrbiterK * 15346263295995333395U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6470556523400123474U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4333255670390099293U;
            aOrbiterD = RotL64((aOrbiterD * 11089933812030082647U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7700424876430257995U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16920736951239453071U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8920407493132380497U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1635071690430295730U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9966700845966398620U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17210048121896546867U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9833458070123027075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1990346556486746432U;
            aOrbiterE = RotL64((aOrbiterE * 8704943923474148699U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13339523466436517327U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5018264760406215603U;
            aOrbiterB = RotL64((aOrbiterB * 2769197961801783627U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 123427497520755346U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4535841104215792886U;
            aOrbiterG = RotL64((aOrbiterG * 1417676310539177131U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3525925567359163763U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3273741481392187986U;
            aOrbiterC = RotL64((aOrbiterC * 16116160744647235811U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6230742908784102407U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7578784912496239362U;
            aOrbiterF = RotL64((aOrbiterF * 2614448818452560369U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14669810330213234082U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4751694786009671052U;
            aOrbiterA = RotL64((aOrbiterA * 9583151676882991817U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 26U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK + ((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterB, 48U)) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordO);
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

void TwistExpander_Archery_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB809FCF1E9FCE18FULL + 0xFD8DD26A58B92976ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF3E978B24EB1D21BULL + 0x91D98CA62588036DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x879E0CAA3C73DCF3ULL + 0xD015D7CEA75F6790ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8FF17BBB39D76493ULL + 0xAA6A4C776BD59F50ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE0DEF514BBD43E51ULL + 0xE16D067DCB10E36AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9D0D26CFFFFFB963ULL + 0xD58CE79098C329FDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA954190219BF39C1ULL + 0xD5C418A08DA8C063ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF0ADDEF8013344DDULL + 0xD246B140A15E7A15ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDA3C0561202ED2EDULL + 0xB05A64F9BDDE808AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBD3D0556C8F9E697ULL + 0xF901E6101B388B27ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x833427A152DDBFEDULL + 0xFA5E66DF41C0FD91ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8C9BD9C08AC486ADULL + 0xEB44485529F54A8DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF55B16C6312D5511ULL + 0xC241B64C8AC25ABFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8B54F1EBAB0AC21DULL + 0x8BC1CDC8850B3FF1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDCB246739D11D8B9ULL + 0xBB2C05012C0736E1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD983EAD1667A9553ULL + 0xCFC628477D05B917ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1099U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 3801U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4315U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5426U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 53U)) + 7825479804710770560U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 13U)) + 5298124167101358123U) + aNonceWordM;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 17774541024369233726U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 37U)) + 7679371833537454082U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 5385914900748772224U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 43U)) + 3879781930908486531U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 26U)) + RotL64(aCarry, 35U)) + 659110346638873236U;
            aOrbiterF = (aWandererK + RotL64(aCross, 35U)) + 10749021728538539749U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 21U)) + 3631252455767429457U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 57U)) + 2271978810960685021U) + aNonceWordH;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 18U)) + 5963558780692551176U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 974909966119198104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9296998242911152296U;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2245318466901521959U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13391076374843288568U;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6184487746594236737U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1563385912137291418U;
            aOrbiterD = RotL64((aOrbiterD * 4805455299959232321U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1744840092006498629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2100927276837188416U;
            aOrbiterB = RotL64((aOrbiterB * 3541788262067077997U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9998911862807246338U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12239948725635220096U;
            aOrbiterC = RotL64((aOrbiterC * 7098620484129489129U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3307447094994950246U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterK = RotL64((aOrbiterK * 9463975886346934681U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11577488293733790649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 191108997585598809U;
            aOrbiterG = RotL64((aOrbiterG * 9574978681405356871U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18096145693841273722U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10026281133603934071U;
            aOrbiterA = RotL64((aOrbiterA * 17261343107314203471U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2346682418062064668U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2996178204018644206U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2552965800703390909U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15085425896818988223U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1589593231782852588U;
            aOrbiterF = RotL64((aOrbiterF * 1535556765195388675U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17170695588248383518U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7825479804710770560U;
            aOrbiterE = RotL64((aOrbiterE * 7434218282170150533U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterI, 40U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterA, 58U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7263U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6611U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7290U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((aIndex + 8779U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aPrevious, 19U)) + 8988572360732005217U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 17889613225105985335U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 42U)) + RotL64(aCarry, 27U)) + 15563478320513948626U) + aNonceWordI;
            aOrbiterG = (aWandererE + RotL64(aCross, 27U)) + 3441351228410524816U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + 4425592689451435346U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 12733160231627305928U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 48U)) + 3574152157304607854U) + aNonceWordD;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 11U)) + 15167631896729808783U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 15822667973915417055U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 23U)) + 17181685481076577637U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 9979204751408873468U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1334240485667164762U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9190066751460137016U;
            aOrbiterH = RotL64((aOrbiterH * 14585141844653660363U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15465215829109246336U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2305208282453624419U;
            aOrbiterJ = RotL64((aOrbiterJ * 10257861974108363283U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16951510027310993926U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11117938943423526901U;
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12461379120662979432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11719697049048823897U;
            aOrbiterI = RotL64((aOrbiterI * 14880996802304818757U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6843357278142933570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12727898578324702374U;
            aOrbiterB = RotL64((aOrbiterB * 9786435451654365097U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18127999660067652233U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11754709060558683082U;
            aOrbiterC = RotL64((aOrbiterC * 12798744012150745847U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16940151146420516184U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12924950783056761895U;
            aOrbiterG = RotL64((aOrbiterG * 8898170377271926745U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14829713915929878471U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 840466047621042565U;
            aOrbiterF = RotL64((aOrbiterF * 10748511630509529489U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11469637840333471085U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5561780312837795893U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 11935079844970978957U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1059834104159730610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10122108814456766430U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2184693583782179921U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14857099570072635006U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8988572360732005217U;
            aOrbiterE = RotL64((aOrbiterE * 14409836741925393077U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 52U) + aOrbiterD) + RotL64(aOrbiterJ, 48U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 54U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordM) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 44U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11619U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 16254U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14820U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((aIndex + 13061U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 29U)) + 12535417189990029950U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 6204401443676390273U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 24U)) + RotL64(aCarry, 29U)) + 869613505613154672U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 41U)) + 15053590879563855802U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 19U)) + 13338989605204591428U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + 18306470022403825392U) + aNonceWordC;
            aOrbiterK = ((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 1150696349434090218U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 57U)) + 13549541786420596437U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererD + RotL64(aCross, 37U)) + 14302878430259588461U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 3U)) + 4660437084477165225U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 43U)) + 1653628537860912069U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5594199757006711631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11008472193138708891U;
            aOrbiterF = RotL64((aOrbiterF * 13645764762027798301U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3668516817279364310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 128159531749679984U;
            aOrbiterH = RotL64((aOrbiterH * 4523246859249826987U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6378674346113979108U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11438762460659123362U;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10624263004446482910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8466639576503293921U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5828694979857951504U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7835487310289634515U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16496305151014092976U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 589464613876410567U;
            aOrbiterG = RotL64((aOrbiterG * 13190816610718051897U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 4168532743415647825U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15944887793736489375U;
            aOrbiterC = RotL64((aOrbiterC * 17273403561158196717U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11642456814106259483U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1609897693632334867U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12912773555616819941U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14950238412766325479U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11862438528287402255U;
            aOrbiterK = RotL64((aOrbiterK * 7635864312080265695U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5900629306795222263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3221591991392500536U;
            aOrbiterJ = RotL64((aOrbiterJ * 7188525011266868855U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16938699391746264010U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12535417189990029950U;
            aOrbiterA = RotL64((aOrbiterA * 18212319484142613215U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterK, 30U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 26U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17653U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21028U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21698U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18596U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 9220392006207660113U;
            aOrbiterH = (aWandererF + RotL64(aCross, 14U)) + 11305018553489132882U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + 5860373868073513684U) + aPhaseFOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 53U)) + 12319586170883987589U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 43U)) + 14072333614354649021U) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 57U)) + 9332158529453194608U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 21U)) + 3860569321145958686U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 8119005668901240093U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 13918259792880333239U;
            aOrbiterE = (aWandererB + RotL64(aCross, 60U)) + 6938856216758228704U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 3960905839118710604U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6043879193734253929U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15691425268831319195U;
            aOrbiterF = RotL64((aOrbiterF * 7189195135654636271U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14912209933584715274U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16180183395910618923U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3942858974766467849U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4966642362507707776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6962226782462822861U;
            aOrbiterJ = RotL64((aOrbiterJ * 3647802407741095419U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12409120845092026295U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2302946450253872465U;
            aOrbiterG = RotL64((aOrbiterG * 7099576330777297911U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16118304388937163838U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15968419034359049422U;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17098982091525008231U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10298979200690822062U;
            aOrbiterI = RotL64((aOrbiterI * 12620028874653521945U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 552826643694256437U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11786560990790695378U;
            aOrbiterE = RotL64((aOrbiterE * 11190309640069208311U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13730399230389329793U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17614226859252305432U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2640019643570222977U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1062738267846296283U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13959480457644980835U;
            aOrbiterD = RotL64((aOrbiterD * 1194145909157002977U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4635071137794189167U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13374502212707796180U;
            aOrbiterH = RotL64((aOrbiterH * 129680788767298945U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11479902881487238033U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9220392006207660113U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 1437457810224888809U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 24U)) + aOrbiterI) + aNonceWordF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 60U)) + aOrbiterD) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26512U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23712U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26020U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27013U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 12669015908335980355U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 5438715179868613192U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 23U)) + 13172104448184536460U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 41U)) + 13421421503244744803U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 13327113302994856582U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + 4671768205922454413U) + aNonceWordB;
            aOrbiterB = (aWandererG + RotL64(aCross, 21U)) + 5355759962838579929U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + 6691720614265406851U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 37U)) + 7063906424700911378U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 17328616394166672263U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 37U)) + 1542940602574207068U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7203866278803132454U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 993485696233139264U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 11609009908810366447U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15659679028507488331U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18321361454094675842U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3966860765622641843U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9633319822696783352U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3496559332232402963U;
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1918349708324205526U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7701088402761359134U;
            aOrbiterK = RotL64((aOrbiterK * 9649485438465644795U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6006824348814439686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18088375375347012557U;
            aOrbiterF = RotL64((aOrbiterF * 12801082943086128385U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12816533373478543584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterD = RotL64((aOrbiterD * 8935839101517220201U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11311632024372748238U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9891349164779752351U;
            aOrbiterB = RotL64((aOrbiterB * 11405973752233193209U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 711130292000437038U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17818800917771709681U;
            aOrbiterE = RotL64((aOrbiterE * 10567029732245868263U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10188714200240109442U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9745615081760948652U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9321909462220134035U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 6508703788527163965U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7536038073603467381U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 12015514242701199813U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2793951597846756844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12669015908335980355U;
            aOrbiterJ = RotL64((aOrbiterJ * 7355285540199760689U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 39U)) + aNonceWordG) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH + (((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 60U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aNonceWordI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 12U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30368U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31441U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30814U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 30281U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 48U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 13296600294247799698U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 35U)) + 5818503518080877515U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererK + RotL64(aCross, 53U)) + 6735784238734173597U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 7368398209488856201U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 39U)) + 961734029066455638U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 37U)) + 797011946660892011U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 11U)) + 12841876018396622350U) + aNonceWordI;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 30U)) + 16213253970483895623U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 15186950557113470375U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 47U)) + 5117930310827477341U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 51U)) + 12265429373166094162U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13920531346698601568U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14695405206998211456U;
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7851960904825938443U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9501511171732550190U;
            aOrbiterB = RotL64((aOrbiterB * 5614164120361489613U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5663365182245722077U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9607860124321315555U;
            aOrbiterA = RotL64((aOrbiterA * 3461820361914280601U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18171052650586819280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3442698321538580861U;
            aOrbiterH = RotL64((aOrbiterH * 6317525514963824829U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1491052813469258970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3956599824067616133U;
            aOrbiterE = RotL64((aOrbiterE * 2928600779267623085U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 10963841237346073453U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2303020125591252534U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9969099842343321981U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14503856057958162356U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11147548150090597694U;
            aOrbiterG = RotL64((aOrbiterG * 11856382308792700441U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10103207278550444685U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10415809965217261104U;
            aOrbiterJ = RotL64((aOrbiterJ * 16562732599511350217U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17435033201864058457U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5540494424887364682U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 18230910315317249045U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18020151683897013854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13296600294247799698U;
            aOrbiterI = RotL64((aOrbiterI * 10000194329456668845U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 6U)) + aOrbiterA) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aCross, 18U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 34U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Archery_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE96526AE1FB0BC6FULL + 0xD42F075DBDAE1741ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBDA567D45555C831ULL + 0xBD06847A1D67346EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBDFD68B66BA38747ULL + 0x8FEEDFCEA2459AC5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDFDA3FE9566D2435ULL + 0x924F2FF0AF023949ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x91AC726B21B122BBULL + 0xF81396B04793C7C1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFB6606C721CC50FFULL + 0xBF0F01B763661E34ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC495ABD8826FA9FFULL + 0xECE151A0AA602C10ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC8E1D3A1E0D14905ULL + 0xF7C9D40F9F686475ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC6149039AB8DCB27ULL + 0xD88105C9E6F669F2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF0B17020B0A2D223ULL + 0xC1328184B2636EDEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA119DEC98949BCFULL + 0x98A9FCC5C5AC8623ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEA2FBD15A5585ED5ULL + 0x838AB9BA152E57C4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xECEF92C1AEB5AA47ULL + 0xFEE2C18A46C9B4B0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD3472E6CFC0BCCD7ULL + 0xC181E7ABD28D3640ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x839CCDA9A2D42CCDULL + 0x94B1D4367AA136A2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBBE79E42921BA783ULL + 0x849EACF18C66D8B4ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3899U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4349U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3558U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 3923U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 34U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 3238389262925516513U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 23U)) + 12381787182611386995U;
            aOrbiterA = (aWandererA + RotL64(aCross, 27U)) + 7883885539305181549U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 29U)) + 1185413044597727092U) + aNonceWordD;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 14U)) + 15219353497204773135U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 7533774715626734082U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 57U)) + 2599930450937763464U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 35U)) + 16074720663961214284U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 53U)) + 15483613196360051221U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 9396557867081376268U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 9668459976852660245U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9037269914643207212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16936742640861088240U;
            aOrbiterA = RotL64((aOrbiterA * 1040172193161012227U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16481274825758546398U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 481851372837611166U;
            aOrbiterK = RotL64((aOrbiterK * 2225030139210599207U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13608921517203544108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16930740723286214636U;
            aOrbiterE = RotL64((aOrbiterE * 2605108503821980865U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 902242902582149908U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1510861213079342977U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3309753895727400707U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7116243600304980310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6631412278359709602U;
            aOrbiterI = RotL64((aOrbiterI * 11452627691392637463U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9246698682265275165U) + aNonceWordI;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 8594373032014031450U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 2550138341089957033U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15912837963877821048U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11404583513022627609U;
            aOrbiterF = RotL64((aOrbiterF * 17715204726760125357U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17295214920690244319U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18315664494984189344U;
            aOrbiterG = RotL64((aOrbiterG * 17398893532076312945U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2474825506593695564U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4400473621592150441U;
            aOrbiterB = RotL64((aOrbiterB * 7098832854166953839U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15270166373215060119U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4331232225067306139U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2299883590703870703U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2176207815544347316U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3238389262925516513U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13104597690682251231U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 50U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + (((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 44U)) + aOrbiterJ);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 51U)) + aNonceWordP) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9335U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 10148U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10771U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 6226U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 39U)) + 15045917390223766480U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 10763054007033668758U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 19U)) + 13190170142593666607U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + 9657025731441167065U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 26U)) + 11433367178975954211U) + aNonceWordC;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 17904920143996810366U) + aNonceWordO;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 3244383020512113283U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 6538815775171139091U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 5U)) + 7195368312757976343U) + aNonceWordL;
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 18134430713910279374U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 22U)) + 6571776588427107976U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11830778129647517758U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9793702760907767365U;
            aOrbiterI = RotL64((aOrbiterI * 4096246227968677179U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2287235876793192036U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8951959188326141794U;
            aOrbiterC = RotL64((aOrbiterC * 9968356718110753845U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7583061790273240157U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3571364625022806085U;
            aOrbiterG = RotL64((aOrbiterG * 6238360922735480669U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13869345563551689212U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 277480328952975002U;
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4983735092494677578U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9490022869381030928U;
            aOrbiterJ = RotL64((aOrbiterJ * 12926352917961703123U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7928039573014765566U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6504190875809407084U;
            aOrbiterD = RotL64((aOrbiterD * 14648214826494826711U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2787985600176307413U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16308785053443116826U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 17867565986311256691U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12788128335006767824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1187040019537798339U;
            aOrbiterA = RotL64((aOrbiterA * 10834905007658184183U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10771230162770496645U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6542421559654716320U;
            aOrbiterK = RotL64((aOrbiterK * 16829492790597069373U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 702458690970201679U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2806140783487813070U;
            aOrbiterF = RotL64((aOrbiterF * 7415398198842270381U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 950611302199732036U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15045917390223766480U;
            aOrbiterH = RotL64((aOrbiterH * 9358017420417979347U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 38U)) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13868U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13649U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14363U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14645U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 37U)) + 15652862298542575895U;
            aOrbiterE = (aWandererK + RotL64(aCross, 54U)) + 16925323928418184554U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + 4413861484961668394U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 51U)) + 2215946422098155969U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 14975185533513111110U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 13U)) + 9711613814905834552U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 13154957291850149471U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 5058313016418534840U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 27U)) + 15011423472941211620U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 30U)) + 2030053257469580168U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 150530795186791193U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10878237472104183427U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11724672539469573109U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16158741837357985395U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9589700906445846956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1367381624958248949U;
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12003215666757518106U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11232479330848006729U;
            aOrbiterE = RotL64((aOrbiterE * 10993290955464593033U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13013910456628561621U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6092509838924105265U;
            aOrbiterF = RotL64((aOrbiterF * 805601154718006061U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11999225836250312801U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14421271973875748413U;
            aOrbiterJ = RotL64((aOrbiterJ * 9529010940887430157U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15536288285741825272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2071793889925436679U;
            aOrbiterB = RotL64((aOrbiterB * 1526376970151714589U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5622386476463436967U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16147972771639168516U;
            aOrbiterG = RotL64((aOrbiterG * 11826916832825159095U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4519892856053952290U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12059500374938843538U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14987533625537956299U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4547335128847992282U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15378473334472216418U;
            aOrbiterA = RotL64((aOrbiterA * 13907560285280544037U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14644123269581735633U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 6434315615480805381U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 4335857173941645355U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14241680137158382296U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15652862298542575895U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 4190840063924551519U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 6U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterC, 52U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20575U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19158U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17426U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17547U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 27U)) + 3248574644570178787U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 4506961512959200024U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 29U)) + 8423739774540738590U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 6593975869641735337U) + aNonceWordA;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + 16441716090557369103U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 10U)) + 7936601450453207914U) + aNonceWordD;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 13333752583560167065U;
            aOrbiterB = (aWandererA + RotL64(aCross, 21U)) + 8013703284795432973U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 2349852779887439236U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 5318539364763284138U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 35U)) + 11450957608502944376U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9058992558327552687U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 632095686920230926U;
            aOrbiterI = RotL64((aOrbiterI * 12460364388358520799U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14734218428913777098U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16344357661370784442U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 15049472842002138369U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2981145363531184308U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11198457590069700889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4311591763498985972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16194341833989936369U;
            aOrbiterB = RotL64((aOrbiterB * 9997934560195932575U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7560794022401107431U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10683789740265711603U;
            aOrbiterA = RotL64((aOrbiterA * 15637823045351977883U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11614366395125937178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10750771385100564416U;
            aOrbiterD = RotL64((aOrbiterD * 4987921274272444283U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2934697034132204529U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4646873794658020363U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10555456865641580175U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7913681837683568905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17603563535330106340U;
            aOrbiterG = RotL64((aOrbiterG * 17882943067522319671U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15375641415139193079U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17059712718085411887U;
            aOrbiterE = RotL64((aOrbiterE * 13722089235751208215U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14022558453716067200U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3248574644570178787U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15249135451439374621U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + ((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterK, 48U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22674U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 25046U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22501U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 26288U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 28U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + 701291026547470433U) + aNonceWordA;
            aOrbiterH = ((((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 17283292650462111643U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 13U)) + 9969124091931303406U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 40U)) + RotL64(aCarry, 57U)) + 889176772718046988U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 21U)) + 6054541844643748084U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 57U)) + 14703226235143028132U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 7977975878522921062U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 16894322614172266274U) + aNonceWordO;
            aOrbiterB = (aWandererB + RotL64(aCross, 43U)) + 12160451749345900570U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 54U)) + 10870847008043897470U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 8159920947172520247U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2440099120969517932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2428396147731468007U;
            aOrbiterE = RotL64((aOrbiterE * 9363073341539598441U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2213226274394673479U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7079731443427765333U;
            aOrbiterG = RotL64((aOrbiterG * 16918930776877030559U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 958896789550478970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10788682955708075458U;
            aOrbiterD = RotL64((aOrbiterD * 913321215613559729U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2003386579317564870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8419686358774204999U;
            aOrbiterK = RotL64((aOrbiterK * 6547052526438697621U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6989167615157578904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17636634003643824148U;
            aOrbiterI = RotL64((aOrbiterI * 11038576417283732937U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13824962118933907859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9543912892587859646U;
            aOrbiterC = RotL64((aOrbiterC * 14736710162285997415U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15729878041027706114U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9542137475454825463U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11420547128115090491U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5327302277575009955U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2707383132257428583U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9008601903853562620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11050463189491777908U;
            aOrbiterF = RotL64((aOrbiterF * 9178386878636430553U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14683684132116778056U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5390271065690907120U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 17903005409098232619U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5183407290520277451U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 701291026547470433U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16329261100139524239U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 30U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28931U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31270U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32335U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 29335U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 19U)) + 11410829607777684449U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 7502698839700975347U;
            aOrbiterD = (aWandererG + RotL64(aCross, 41U)) + 13267685058252106173U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 38U)) + RotL64(aCarry, 11U)) + 238242706996630625U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 23U)) + 8184695499511454281U) + aNonceWordL;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 12767823220461985403U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 13U)) + 12293198423143850330U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 27U)) + 11149495229952495939U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 60U)) + 7556992689338382800U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 5U)) + 3431338808774134649U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 53U)) + 16863099140844995099U) + aPhaseFOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17872458049880677604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16760153457252546974U;
            aOrbiterD = RotL64((aOrbiterD * 11225037229069712805U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3115544493537438408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4359882942759752958U;
            aOrbiterK = RotL64((aOrbiterK * 561477566995575801U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13387113067202396536U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12955690074544490161U;
            aOrbiterI = RotL64((aOrbiterI * 12449941770827974511U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15614054443728226807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1939441328066616114U;
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4599016263007782537U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9962305629016158048U;
            aOrbiterJ = RotL64((aOrbiterJ * 1496184427500037279U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8428467674122750557U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3938884087806393439U;
            aOrbiterH = RotL64((aOrbiterH * 12810531094050481761U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6018636830758044658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1510372000641305416U;
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17592782466215337843U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8119921507606870360U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1299795061644535485U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8753237702359236964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12389957327067768090U;
            aOrbiterC = RotL64((aOrbiterC * 4586786761936601607U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17791633199762408683U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11606494383812053915U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13041480602055778521U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4418614662439151979U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11410829607777684449U;
            aOrbiterE = RotL64((aOrbiterE * 3342270212301058781U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 26U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 40U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3256U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5191U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5875U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 1133U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aCross, 57U)) + 1708250618750199233U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 4U)) + 12009147777553691142U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 8393982703399156592U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 3247327098356831221U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 13U)) + 3403590155376353737U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 51U)) + 18197244558104735044U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 18U)) + 3096253642040701606U;
            aOrbiterD = (aWandererC + RotL64(aCross, 37U)) + 8012692688785412179U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 17531946907545680745U) + aPhaseCOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17687695944270225817U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16147773866007628769U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18244641303026196497U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8839160526348897457U;
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10599266240854068246U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2056723540756216155U;
            aOrbiterD = RotL64((aOrbiterD * 13311591601230386375U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4629354220460621284U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9505955649473204942U;
            aOrbiterE = RotL64((aOrbiterE * 17775391885312236187U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17078153810088721310U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9470436761716263000U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5431855497250357229U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3305863413630104742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14377172434239576161U;
            aOrbiterI = RotL64((aOrbiterI * 6880176890091033423U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 415687827894226513U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16975319836893760993U;
            aOrbiterK = RotL64((aOrbiterK * 6597144958013976445U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12707054129431596074U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8974182792497231239U;
            aOrbiterJ = RotL64((aOrbiterJ * 7874658957269462717U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10826131924322955095U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4168545139712703154U;
            aOrbiterF = RotL64((aOrbiterF * 10305904857550051705U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 52U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 56U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aPhaseCWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aIngress, 22U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 52U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9302U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 15297U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13764U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 14262U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 34U)) + 3550722402315312207U;
            aOrbiterK = (aWandererE + RotL64(aCross, 23U)) + 16724184551669522754U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 981751330116773021U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 47U)) + 7891159229704944868U;
            aOrbiterB = (aWandererH + RotL64(aCross, 42U)) + 13618396711464799841U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 53U)) + 5969291018449003648U) + aPhaseCOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 14595540413313640042U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 3287990436916111762U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 12534369400200483704U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2277312067930392274U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10026320559261334353U;
            aOrbiterG = RotL64((aOrbiterG * 11020464940995912637U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11258082063135659551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1445958517675746990U;
            aOrbiterB = RotL64((aOrbiterB * 10062265337488757971U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1011298251290970844U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6487834862470043744U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15477913837027179675U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9966279022928268335U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10285993486057704393U;
            aOrbiterH = RotL64((aOrbiterH * 15965714363201157535U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16005362468813966136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 223843444699390781U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 665392038954573081U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18178876294968532775U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12490136112181806806U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16380841616662993709U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8775696166557913635U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16464340319444310842U;
            aOrbiterI = RotL64((aOrbiterI * 18111632334728200721U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6296039992673546227U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7152939277656436037U;
            aOrbiterF = RotL64((aOrbiterF * 15183918431501487319U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14066791413416223271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5026743227399908016U;
            aOrbiterK = RotL64((aOrbiterK * 5891343232759075675U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 30U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 52U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 14U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19377U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16741U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 23704U)) & W_KEY1], 30U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21077U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 14686411261024919129U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 41U)) + 7514582233957632005U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 37U)) + 6520710480103365552U;
            aOrbiterG = (aWandererD + RotL64(aCross, 29U)) + 1983621978676188036U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 5U)) + 9003524602590749672U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 53U)) + 6428568234045228995U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 19U)) + 8656552687136446989U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 16916248288415922490U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 11U)) + 9740237548002535784U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 907561000814618339U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4751108900841197631U;
            aOrbiterK = RotL64((aOrbiterK * 4545395964730641957U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 167774899400732287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11907484918310854962U;
            aOrbiterH = RotL64((aOrbiterH * 7213139491146402985U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14910318613649863924U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14882888155751455276U;
            aOrbiterG = RotL64((aOrbiterG * 11394136445442060201U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16175942562693781908U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11022373758481651102U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6836331461393816027U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12548405399045031548U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10850926364556828443U;
            aOrbiterC = RotL64((aOrbiterC * 16231561687709867431U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13391684887911141790U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14648937281264822988U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6533299316940026059U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8298658887198526821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13822977698661348891U;
            aOrbiterE = RotL64((aOrbiterE * 17769262972278410937U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7505646847564645719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3238749538197209166U;
            aOrbiterJ = RotL64((aOrbiterJ * 15394286542600778567U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15853506915123709257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8426329899401071248U;
            aOrbiterF = RotL64((aOrbiterF * 1330397096577715113U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 38U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterJ, 56U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 12U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28662U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32193U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32289U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 25628U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCarry, 43U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 53U)) + 12980104182836602177U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 57U)) + 3172622203188863995U) + aPhaseCOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 53U)) + 1170974132219980203U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 6035201940965047490U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 18033907118424996722U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 37U)) + 14604813424800580304U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 5U)) + 13720232492851066035U;
            aOrbiterE = (aWandererG + RotL64(aCross, 20U)) + 3902659710585257448U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 43U)) + 8331560652661619868U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4485014147538689794U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 168202636924512424U;
            aOrbiterK = RotL64((aOrbiterK * 13711020666131492091U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16227825670092707848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12636865372722601282U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18198291399585556632U;
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3650053185419807206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5897288963905408776U;
            aOrbiterB = RotL64((aOrbiterB * 3706949366974086151U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9922308113622901726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13352279749091561510U;
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14969461950939646117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10231661776135056651U;
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10621934544068320859U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6029116920305246887U;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12887482425168671195U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8351351557123783853U;
            aOrbiterD = RotL64((aOrbiterD * 3839381627914762245U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5405938210926464973U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 385145802287899406U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8330751480464271445U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 34U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4962U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1718U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2419U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 1639U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 29U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 20U)) + 14157904117287696136U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 7369512677371640676U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 5002041814539710275U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 9538041410816283124U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5210700103927513061U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7600709399101287982U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6777896926889560889U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2366369466696580499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5544575244203019109U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8710073749110329779U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15998211310115361630U;
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15354357553877376422U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10405750198355464768U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3465819693133515142U;
            aOrbiterA = RotL64((aOrbiterA * 14678343718277562799U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 54U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 40U) + RotL64(aOrbiterB, 26U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13905U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14573U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14420U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13413U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 12426357877879529292U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 28U)) + RotL64(aCarry, 53U)) + 12604900366173639176U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 13511119007338929401U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 39U)) + 9878720081166788060U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 15463195409806395076U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6407922778852833423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7690427254160734016U;
            aOrbiterI = RotL64((aOrbiterI * 11841396512731990295U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18030974031722143619U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17983938038322737041U;
            aOrbiterH = RotL64((aOrbiterH * 12479365337221685413U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16605512170117753884U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 681802273302348322U;
            aOrbiterC = RotL64((aOrbiterC * 14608920184802647123U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15550312921312083819U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17824154101711884508U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1939207786756735430U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3132864634777826569U;
            aOrbiterJ = RotL64((aOrbiterJ * 13606281919426730325U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 14U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16653U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 17248U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23802U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19561U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 17711946802293254150U;
            aOrbiterK = (aWandererI + RotL64(aCross, 30U)) + 16652362590489569378U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 6972810344198183097U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 3U)) + 13117100889782940546U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 13199305696782626591U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 992156184392760945U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13791265442074543880U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1263919538622722673U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17057087245252294859U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13444195995883541046U;
            aOrbiterK = RotL64((aOrbiterK * 13067044288608808777U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6723678233676059420U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7913379431208430475U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2295062944289127123U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4481887195529300665U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11892724101424384078U;
            aOrbiterA = RotL64((aOrbiterA * 3468639499716604111U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7700902083270424194U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1888001433557140271U;
            aOrbiterF = RotL64((aOrbiterF * 8975562955027025349U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 50U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25638U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 30887U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25220U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26666U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 2177539223979303669U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 3962004686551521471U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 8457602312617147662U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 6U)) + RotL64(aCarry, 57U)) + 18011802451816510632U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 39U)) + 9046101759168876832U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11135620637431969597U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15913029940697999701U;
            aOrbiterB = RotL64((aOrbiterB * 646524659942693491U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16304193109948135982U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13208892298820080981U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15093751072618884859U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4182377898949419225U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13970137023071326151U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9075061559681739865U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8402396284835248583U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8859190834060657829U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13552418608113716117U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9760005337757990392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14108277760135744897U;
            aOrbiterE = RotL64((aOrbiterE * 4474681104256093885U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 38U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aPhaseDWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3305U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 7396U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6832U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 5523U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 40U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 29U)) + 17912271996338180948U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 41U)) + 13259276608841847058U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 16225936008657276089U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 2243058962151834071U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 19U)) + 10637439274127347861U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 15312219216405992627U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 5U)) + 2393933972129878613U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4327069337247976513U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8307656353434167837U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11386588389133096705U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17299145556933889336U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14458100581172798164U;
            aOrbiterE = RotL64((aOrbiterE * 16543734663677070509U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6410095654927998067U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6168964796264687686U;
            aOrbiterC = RotL64((aOrbiterC * 16218071040190475953U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3667999465041020730U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterG = RotL64((aOrbiterG * 6427266472526362663U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12941668202330045095U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4222032891850449934U;
            aOrbiterK = RotL64((aOrbiterK * 17292856787431308097U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1346342592002730785U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16860611785008118820U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 384963420804756607U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3193572711804730241U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5866881282680588589U;
            aOrbiterJ = RotL64((aOrbiterJ * 9226331800853634597U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12512U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15911U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9091U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 12654U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 12775735908960052604U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 11791373812080296887U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 5537362877706057303U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 48U)) + 2023912048504189380U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 57U)) + 17668828109963766893U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 19U)) + 558908629933941224U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 11U)) + 1479633119685446888U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15460320397843364063U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10059749397555469054U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9987633811929693924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10087337844580228269U;
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4446204415503364254U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15106063243302192717U;
            aOrbiterE = RotL64((aOrbiterE * 13273756657334709803U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9430197906134676162U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10611580584157624739U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3137391249289641509U;
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9327201928815412810U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7890659377013147073U;
            aOrbiterG = RotL64((aOrbiterG * 13827717178378062047U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10675114832750356941U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8804440385852327267U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 20U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 14U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24546U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20526U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16921U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 16936U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 28U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 29U)) + 5721224134332887360U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 13U)) + 6892749729775049095U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 3884839462099556836U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 37U)) + 4365431706830216193U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 15501528746571578773U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 4505911326320650606U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 53U)) + 1865129050927879580U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2011737665969640369U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 611672935827062688U;
            aOrbiterK = RotL64((aOrbiterK * 12873671551304596619U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 663547038310431047U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5468932264754299556U;
            aOrbiterE = RotL64((aOrbiterE * 11968657455484578525U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17920294117231191705U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 486058453837528110U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8851102552244026737U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2789178451938129313U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 420772587981211184U;
            aOrbiterH = RotL64((aOrbiterH * 17402987842294006667U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16196774774442181825U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16264169656793713547U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6900221986041638783U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10207659833859860796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8593749091183323678U;
            aOrbiterJ = RotL64((aOrbiterJ * 10696776033512404927U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7224922076047787384U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15366267474865172373U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10134187073321814217U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterE, 26U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27065U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 25599U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32569U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32710U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 41U)) + 15045917390223766480U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 10763054007033668758U;
            aOrbiterD = (aWandererH + RotL64(aCross, 27U)) + 13190170142593666607U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 60U)) + 9657025731441167065U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 53U)) + 11433367178975954211U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 17904920143996810366U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 3244383020512113283U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6538815775171139091U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7195368312757976343U;
            aOrbiterD = RotL64((aOrbiterD * 10515679176134176565U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18134430713910279374U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6571776588427107976U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11916502085252589161U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11830778129647517758U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9793702760907767365U;
            aOrbiterB = RotL64((aOrbiterB * 4096246227968677179U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2287235876793192036U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8951959188326141794U;
            aOrbiterC = RotL64((aOrbiterC * 9968356718110753845U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7583061790273240157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3571364625022806085U;
            aOrbiterJ = RotL64((aOrbiterJ * 6238360922735480669U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13869345563551689212U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 277480328952975002U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4983735092494677578U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9490022869381030928U;
            aOrbiterH = RotL64((aOrbiterH * 12926352917961703123U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2926U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7808U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2780U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 1118U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 12U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 21U)) + 3650233661228036955U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 11607036400067735729U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 3899614406903883035U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 8159156925629965143U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 40U)) + 7148903913967261270U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9161665622287517848U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2981535013474059469U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4434815231517266013U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15812469008200319549U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14687469489893270300U;
            aOrbiterB = RotL64((aOrbiterB * 14142363399696670451U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6025209349511417063U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12964750392311112676U;
            aOrbiterF = RotL64((aOrbiterF * 12955480283032701843U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6572355895765394340U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3542300121890027981U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11201491178181273935U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6477175684045398359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1081388388827929314U;
            aOrbiterK = RotL64((aOrbiterK * 8752188637514143529U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 27U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15700U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 15072U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13655U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11391U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 34U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 8101351470141807662U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 6965474099521076705U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 24U)) + 6803828268885684784U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 13454235922950972488U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 43U)) + 11678091885751244777U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5307134544628507141U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4873703518950429353U;
            aOrbiterD = RotL64((aOrbiterD * 2680442582958424915U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8542156221858586039U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3993726182905296513U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11331376012938127609U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12113047622035464386U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1944244448665721151U;
            aOrbiterH = RotL64((aOrbiterH * 7010050836758762003U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12914188029425467576U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2486762763475327024U;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14580191602982245481U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12093414832400135066U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12720286833215690663U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 34U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19802U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 22332U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16478U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 23399U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 60U)) + 5088525177670191619U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 9966456257813932112U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 7707646574027146307U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 75480203757681173U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 19U)) + 384659134071835163U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3158769775373307778U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17360830943513941272U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9986023786908098621U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5317278822721604586U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1371427105215954781U;
            aOrbiterJ = RotL64((aOrbiterJ * 10956603063464438611U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3162710551223553423U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5332921933853550756U;
            aOrbiterD = RotL64((aOrbiterD * 11709546145149357887U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10572462410297815854U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10234389605554817892U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2130374833440291193U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13421365517991380605U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10186643614984034083U;
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterA, 46U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29785U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 30660U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24930U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 29763U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 8375305456876489425U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 40U)) + 16193562952772453047U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 3U)) + 18088652458594816223U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 767344788620249944U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 7705194930396368752U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3829736891311272834U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9881681671347640061U;
            aOrbiterJ = RotL64((aOrbiterJ * 14380245087931793021U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1721196560190164264U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3002652618388454213U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15289749311593032657U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9811621464004005202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5652598941069986530U;
            aOrbiterB = RotL64((aOrbiterB * 4797973356708091621U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6250499348327316328U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16025054277615264530U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16446892258704281903U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13800298546867243172U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12256104592865905782U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16983140179497142713U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 3027U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1559U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7782U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 4905U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 5480870806135400132U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 57U)) + 8034874599430768743U) + aPhaseGOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 4006919843736863767U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 2988069748674633718U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 14U)) + 12347295651973135786U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14152683894431568192U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15765143815254196598U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8948877544291035189U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10473067082331244233U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1089466925383677249U;
            aOrbiterA = RotL64((aOrbiterA * 17334888609179149753U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13215039929873682230U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3957997712247961479U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7631186240013784703U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10023907397941685546U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterJ = RotL64((aOrbiterJ * 17111300092082154687U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13353797968154036726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9259966668512102858U;
            aOrbiterH = RotL64((aOrbiterH * 8326732574268308221U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterJ, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 24U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10902U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13567U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10139U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 8315U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 12222235191147985484U) + aPhaseGOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 16367317014523328414U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 3511378091284703789U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 60U)) + 15247492830966725949U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 29U)) + 7745995913390407897U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6463593307540108810U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1101669311005268630U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10550146460887359369U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12988052764067518580U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17717179747434679772U;
            aOrbiterG = RotL64((aOrbiterG * 10820310705487638793U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11662190906682400416U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6563014073547628748U;
            aOrbiterF = RotL64((aOrbiterF * 16967910471722117761U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13099094932059419219U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16855346813127524624U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6570063128502306944U;
            aOrbiterA = RotL64((aOrbiterA * 4571570049463124831U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 4U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + aPhaseGWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 28U)) + aOrbiterE) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22270U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 21200U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17101U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16976U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 34U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 8975885703279267062U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 57U)) + 8664844915562660637U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 4U)) + 12281774799736296726U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 15347461352311329726U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12967500561828907834U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5002833859280402726U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11908257536954668983U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4384790916151202785U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17017174811949227162U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16851323125613931180U;
            aOrbiterD = RotL64((aOrbiterD * 12446990992858763577U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13469326957728686706U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5228638551056105241U;
            aOrbiterB = RotL64((aOrbiterB * 13369947664646167255U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11945166198089308564U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16268645041872996022U;
            aOrbiterC = RotL64((aOrbiterC * 5391448793718370911U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14781204627695095701U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5365325354838101092U;
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 28U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26476U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 24977U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24744U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30984U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + 7896237440058555694U) + aPhaseGOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 11870529476037558635U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 9158983227801569448U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 4710172270996950329U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 52U)) + 14634482800356647630U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8822207952170610891U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13755891414028982553U;
            aOrbiterH = RotL64((aOrbiterH * 5173750624716006485U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4555293067488040719U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2816805148093762081U;
            aOrbiterB = RotL64((aOrbiterB * 16838149138341713943U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2122631477965135190U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4592922416380416071U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11644507904538573165U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7102471666524164715U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17274623547879474204U;
            aOrbiterE = RotL64((aOrbiterE * 5443572270546181789U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 938587316977094680U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18258015823797023523U;
            aOrbiterJ = RotL64((aOrbiterJ * 6068819567674605919U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 4U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + aPhaseGWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + aPhaseGWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6531U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4692U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1781U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4420U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 43U)) + (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 36U)) + 3248574644570178787U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 4506961512959200024U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 8423739774540738590U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 11U)) + 6593975869641735337U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 16441716090557369103U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7936601450453207914U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13333752583560167065U;
            aOrbiterK = RotL64((aOrbiterK * 5389149472324384311U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8013703284795432973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2349852779887439236U;
            aOrbiterC = RotL64((aOrbiterC * 2422888500648100783U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5318539364763284138U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11450957608502944376U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1957880366707810635U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9058992558327552687U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 632095686920230926U;
            aOrbiterG = RotL64((aOrbiterG * 12460364388358520799U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14734218428913777098U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16344357661370784442U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA + ((((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterK, 10U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 52U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10843U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15803U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15831U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 12221U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 58U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 9751314027302668907U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 12175450995523107056U;
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 17519694958730119552U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 9093525527925682263U) + aPhaseHOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 3U)) + 3713831321786810138U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10108355209191835040U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12956307447311314768U;
            aOrbiterB = RotL64((aOrbiterB * 9198936928658626667U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1904298513945877359U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4658049993308574460U;
            aOrbiterI = RotL64((aOrbiterI * 10482422152074338611U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9826333658248851902U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12058666914724365134U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 964233873188373939U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2516574707110528099U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13335308331049750235U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8230749255538495304U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16536559486797811486U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7097036838156464969U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 36U) + aOrbiterF) + RotL64(aOrbiterD, 10U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21418U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 18925U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21512U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 16547U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 12046647397183218524U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 21U)) + 2760779375026461991U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 42U)) + 13735454443176855650U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 4370377000586647724U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 14566322384189969094U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5056565959818422786U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8795403810686579209U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11205867337479457471U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9625947666256011567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1703669290934254701U;
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6664070663184147951U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2104148316797553431U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1197910004222596145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9922977170060903197U;
            aOrbiterG = RotL64((aOrbiterG * 13047828062605568603U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2048376210852567829U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12568990647075931409U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9860242601194210927U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aPhaseHWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26908U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 32759U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24657U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((aIndex + 26834U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 53U)) + 1042610313571524121U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 3505725321008825582U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 12584654563843782991U) + aPhaseHOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 34U)) + 6645399144515770935U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 3608978423753715584U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8089198857670370983U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15207251813516399879U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7596841660069752069U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9579268660105824516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16055044469473802812U;
            aOrbiterH = RotL64((aOrbiterH * 2269649280637188723U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 583811872609805949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7027491967970873942U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12686754713465826139U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18256061823189677508U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12708429127816136937U;
            aOrbiterB = RotL64((aOrbiterB * 12593886633108075321U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12169216645156306078U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12694325407567795065U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3711789483877261899U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
