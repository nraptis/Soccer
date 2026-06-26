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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE91E9BB6948DB4C7ULL + 0xA6E72ECA4E70C031ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB074E9C6B5430C25ULL + 0xCE57D28C5C85D35FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9B21AC066B5F787BULL + 0xC49CB27AF774FE92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x99072EEBBF48F2B3ULL + 0xF6F85C392C04FCBCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDBB4AC955FC1A58DULL + 0x826D6828FA4ADCF1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8D275DF4B82105ABULL + 0xE4E67BA88A12A062ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBD5E1D22887AF69DULL + 0xD313B0B71D563373ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA52B5532E12F247BULL + 0xF80481CD98AE2DB9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB51211CD7BAFA805ULL + 0xC5BBAD4CF3F3FC27ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x835D15FE5FDBFE31ULL + 0xB89A32905A8BD58AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB66D6C8FEA0E9F7BULL + 0xE91F37D341A22724ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x94BDB102DA49D42DULL + 0x860C08061E79945BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x87D8206D9298153BULL + 0xA584DF2FE1CDED80ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF79A48287D55ABB1ULL + 0xC944681F0C88F79EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF8F5AABE03B79A37ULL + 0x8FDB454852CD2225ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE9F8964D07FC9065ULL + 0xE460C5BC8457ED72ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5170U)) & S_BLOCK1], 18U) ^ RotL64(pSnow[((aIndex + 14U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3195U)) & S_BLOCK1], 20U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2755U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 29U)) + 14249093584376402677U;
            aOrbiterB = (aWandererG + RotL64(aCross, 56U)) + 8756965951816492264U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 39U)) + 11221139480258176330U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 17218894445564194851U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 8064642692524949490U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 5822093203710704646U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 3217799620158102238U) + aNonceWordP;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 2613757677892120843U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 35U)) + 13647481499551657237U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 37U)) + 3545714196663685016U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 24U)) + 9735422670576621521U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3911046580637583767U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9315984027042049203U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12568550776487242469U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8926367674641729058U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11035347490524961446U;
            aOrbiterH = RotL64((aOrbiterH * 10948288997163592463U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10748158733051120339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9244415080474351390U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8517784887959492079U;
            aOrbiterE = RotL64((aOrbiterE * 17022899813765884147U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8409307332803038455U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11043806021873232950U;
            aOrbiterC = RotL64((aOrbiterC * 8294888329708842989U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17512395828450251457U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16849067939795823992U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 9361991804481514337U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17541946638063238056U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11430501673960586718U;
            aOrbiterK = RotL64((aOrbiterK * 15074409630605450091U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 78307505705383302U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 4834528975263832983U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 17245673681686752861U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9647985402149698269U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6610247710757518931U;
            aOrbiterJ = RotL64((aOrbiterJ * 8672486173272686859U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2706696306041774372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9519896513600816252U;
            aOrbiterF = RotL64((aOrbiterF * 7468605169665549731U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14647351223431646222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14249093584376402677U;
            aOrbiterA = RotL64((aOrbiterA * 8296105266618697281U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterE, 22U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 12U)) + aOrbiterC) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7905U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9796U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 7645U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9110U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 27U)) + 13053031069776604052U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 1331396630251085122U) + aNonceWordM;
            aOrbiterD = (aWandererB + RotL64(aCross, 14U)) + 15879286043343942393U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 41U)) + 13590365633321406830U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 23U)) + 14569235423040242618U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 11397370636618371560U) + aNonceWordG;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 29U)) + 3455933494593971847U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 1307153376443784593U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 43U)) + 10688618762584786871U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + 17746248451153600096U) + aNonceWordK;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 11U)) + 8512568600755410158U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8950230550112591092U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17790968369472845496U;
            aOrbiterD = RotL64((aOrbiterD * 5104988920132008913U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12583323865381967534U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11243927099685293887U;
            aOrbiterJ = RotL64((aOrbiterJ * 12867003042486433971U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9690268715525781389U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7466066217365074653U;
            aOrbiterC = RotL64((aOrbiterC * 17565696765505320889U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3673528673209875118U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14079103852360952255U;
            aOrbiterF = RotL64((aOrbiterF * 17449228863409999629U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6747836856132250630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5027692924422297153U;
            aOrbiterK = RotL64((aOrbiterK * 2492421273167124437U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11370341866003395776U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14013204893442579282U;
            aOrbiterB = RotL64((aOrbiterB * 6602239957997240785U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3436953430697936790U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6399073534839993637U;
            aOrbiterE = RotL64((aOrbiterE * 14186050072610021241U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7054057507823631422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5752085719673338095U;
            aOrbiterI = RotL64((aOrbiterI * 13252660162476029593U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10628323020010327594U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5029617362660411790U;
            aOrbiterA = RotL64((aOrbiterA * 7230663968894173433U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6816547880074551571U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6683840259024813282U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13145224557159574541U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5952768353050729617U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13053031069776604052U;
            aOrbiterG = RotL64((aOrbiterG * 13710064584055068065U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 22U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 52U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12608U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13987U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 15396U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12446U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 60U)) + 15652862298542575895U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 16925323928418184554U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 13U)) + 4413861484961668394U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 51U)) + 2215946422098155969U) + aNonceWordO;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 14975185533513111110U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 9711613814905834552U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 13154957291850149471U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 27U)) + 5058313016418534840U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 53U)) + 15011423472941211620U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 58U)) + 2030053257469580168U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + 150530795186791193U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10878237472104183427U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16158741837357985395U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9589700906445846956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1367381624958248949U;
            aOrbiterH = RotL64((aOrbiterH * 8459515089081211977U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12003215666757518106U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11232479330848006729U;
            aOrbiterC = RotL64((aOrbiterC * 10993290955464593033U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13013910456628561621U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6092509838924105265U;
            aOrbiterB = RotL64((aOrbiterB * 805601154718006061U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11999225836250312801U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14421271973875748413U;
            aOrbiterG = RotL64((aOrbiterG * 9529010940887430157U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15536288285741825272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2071793889925436679U;
            aOrbiterD = RotL64((aOrbiterD * 1526376970151714589U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5622386476463436967U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16147972771639168516U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11826916832825159095U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4519892856053952290U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12059500374938843538U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 14987533625537956299U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4547335128847992282U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15378473334472216418U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13907560285280544037U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14644123269581735633U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6434315615480805381U;
            aOrbiterK = RotL64((aOrbiterK * 4335857173941645355U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14241680137158382296U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15652862298542575895U;
            aOrbiterJ = RotL64((aOrbiterJ * 4190840063924551519U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 24U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 54U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 34U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21841U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 18634U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18685U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16927U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 39U)) + 12206125048349568300U) + aNonceWordO;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 52U)) + 5843520589343188818U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 37U)) + 12195046124287121687U) + aNonceWordD;
            aOrbiterC = (aWandererF + RotL64(aIngress, 19U)) + 16769779119214020640U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 5257603646260695833U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 35U)) + 8523523946234886745U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 7316024684200084096U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 11996978575084115207U;
            aOrbiterG = (aWandererB + RotL64(aCross, 13U)) + 15491711479085513628U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 54U)) + 6036648530996821484U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + 926323222234121863U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2700323841295743492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5852273765810284935U;
            aOrbiterE = RotL64((aOrbiterE * 16665696735016345215U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11697397483133538067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17777142964957007194U;
            aOrbiterK = RotL64((aOrbiterK * 6338967222543284999U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10892176201151170298U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11759700374509499684U;
            aOrbiterH = RotL64((aOrbiterH * 14247697264744736081U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11343756773329590643U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15785048929757652350U;
            aOrbiterF = RotL64((aOrbiterF * 17208103574389502597U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7508839228498497238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13088508510402094665U;
            aOrbiterA = RotL64((aOrbiterA * 15730279447009669103U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16259236641717377699U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11228995722951003980U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4870092259515181323U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13775851561528617086U) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 3023564646900497080U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 9936548213275464131U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 154952467284609583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14239675888632174461U;
            aOrbiterI = RotL64((aOrbiterI * 1370550680736926425U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 168749514558708557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5070416708211422927U;
            aOrbiterJ = RotL64((aOrbiterJ * 13631900152346927703U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1961290602001581341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12235345489656113478U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14403534235273302211U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2295581049708176078U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12206125048349568300U;
            aOrbiterC = RotL64((aOrbiterC * 6008868846674396181U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterE) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 40U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 24U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26787U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26649U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25278U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24592U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + 380024772508948442U) + aNonceWordI;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 7649029098162567210U;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 5329304598870421851U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererB + RotL64(aCross, 14U)) + 12306118665045151326U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 960751560457324256U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 35U)) + 3244070254386191876U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 43U)) + 15733408571609521746U;
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 17623448932647018544U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 8787759896149035829U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 18U)) + 14741681792348288162U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 37U)) + 8801731213568307302U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9872248187499779222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15407371518644528235U;
            aOrbiterB = RotL64((aOrbiterB * 1245102406469471673U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4242060317152943062U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 888649755587764533U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7296348796484458631U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15061417216070157797U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10349554676953256231U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3233185810644297433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9241229457641024287U;
            aOrbiterG = RotL64((aOrbiterG * 2728237515724597517U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8464051359381554575U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3307872165699029375U;
            aOrbiterE = RotL64((aOrbiterE * 4859663401033023433U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5482617843966711997U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4442149210462943872U;
            aOrbiterA = RotL64((aOrbiterA * 8979352218576515647U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10591636597580147381U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14925122230279312217U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15038171961638724013U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9772367878232735350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15800661165607190092U;
            aOrbiterH = RotL64((aOrbiterH * 10493976952980533589U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1571665862499272194U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3162847040693387901U;
            aOrbiterI = RotL64((aOrbiterI * 2747235335326991399U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4868791925868749848U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13134549226315884613U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3551955270718495869U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7830447320021657240U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 380024772508948442U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 5143324968958616357U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 4U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + ((RotL64(aCross, 28U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 60U));
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 37U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32160U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30216U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28267U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 27698U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 51U)) + 77518479758428414U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 4832061802166300011U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + 11695291171006574112U) + aNonceWordD;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 23U)) + 7467412817843260094U) + aNonceWordC;
            aOrbiterF = (aWandererD + RotL64(aScatter, 19U)) + 17801484124471154757U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 5555455638503958639U;
            aOrbiterD = (aWandererI + RotL64(aCross, 37U)) + 5669470540733721606U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 3042388456327784163U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 58U)) + 2236734925228156691U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 43U)) + 14459720401528685450U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aCross, 29U)) + 4814967631216658856U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16950679344449075945U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3522256359074996724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13891759914865623828U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12311343917878428995U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2240189915640314069U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5365912986308810837U;
            aOrbiterD = RotL64((aOrbiterD * 15133972552032469957U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9323732721344489753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterB = RotL64((aOrbiterB * 14659491687401151733U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16398238057564892809U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11517870519285159224U;
            aOrbiterA = RotL64((aOrbiterA * 1501848878469712681U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7758285512254776734U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17475149091906684720U;
            aOrbiterG = RotL64((aOrbiterG * 6015816725428299273U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2051631493975035243U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11684740065349595315U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 10918975496337269197U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10575473798991451167U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8267005776169272822U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 13166868678285963961U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6249698995716039231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13808085811784323978U;
            aOrbiterK = RotL64((aOrbiterK * 3897731011582061983U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2739364646624876985U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 77518479758428414U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 6977724811175035551U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 60U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 40U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 56U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordJ);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD0ADF40C63839CA1ULL + 0xEC7272B0E8CF087FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB05D04696D8503B3ULL + 0x9DEAA6671AC2090AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE472E322E23177EDULL + 0xAF440E9DCA450167ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB73A3E04906203D7ULL + 0xBC27477D36D57D91ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC2F529C8AEC7F6CBULL + 0x95D1F45A20E882BEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA97FEDACE25A14B5ULL + 0xD36459D320831669ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA747E3D5F2D536C3ULL + 0xB710D855FFCE352EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9A70F2EC6D72116BULL + 0x975E7F53526EA9F6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x81E6FA385EE66117ULL + 0xBF691E9177D7701FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFA7716B57C6176CFULL + 0xF7355888811B20BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6BBBD2C9FC2A283ULL + 0x9BF90DBD57817327ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB68F6849C2EBD85BULL + 0xAB5409EA24738A71ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9B1DF2D4031F6927ULL + 0xDCFA120A8A13009CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC6364C3CA2AC19F1ULL + 0xB9941EB4CEDEC997ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC1636A32E2F670D1ULL + 0x9FE2F0FA7CD27065ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCA6DF1A6CE0ADAC1ULL + 0xBDE8E31B84504CD3ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1969U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 3124U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4069U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7069U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 29U)) + 7948891781097675369U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + 13928362874228230226U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 10776180542602258926U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 5735115172149470447U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 58U)) + 5353591822981766987U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 39U)) + 562301708107268570U) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 10467810247578364868U;
            aOrbiterC = (aWandererG + RotL64(aCross, 11U)) + 14541630141152308564U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 22U)) + RotL64(aCarry, 19U)) + 2350076897065139429U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17519109078651162228U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10021905773432907835U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15654836633731000065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2849680038315532197U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17336102435576647923U;
            aOrbiterC = RotL64((aOrbiterC * 10984689101753586739U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7671010488872356142U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11485114338165600777U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 4162584865462407791U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8759060657343458985U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11009137869375286581U;
            aOrbiterK = RotL64((aOrbiterK * 8741417343929809115U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15792999392743144135U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6180808423175992479U;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 361487389591183005U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15292753806514404853U;
            aOrbiterJ = RotL64((aOrbiterJ * 17478232597253311153U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14929153438443362045U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterA = RotL64((aOrbiterA * 2484130486635511403U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3793180909904286848U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10391957637467171320U;
            aOrbiterG = RotL64((aOrbiterG * 505484041943467117U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 14U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 30U)) + aOrbiterK) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 56U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterI, 39U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14288U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9560U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11762U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9990U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 43U)) + 13174219512651137892U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 39U)) + 2715455762789269341U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 29U)) + 1338018183235594313U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 16566866551729552930U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 53U)) + 6901845297307236726U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 2476078302049201718U;
            aOrbiterK = (aWandererI + RotL64(aCross, 21U)) + 15531109473927052260U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 34U)) + 4087849380858572351U) + aNonceWordG;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 13U)) + 5167830630098599644U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7275995452428627217U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14794340370010024117U;
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8509217403041662849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2321522025240806996U;
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5676672952755594051U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2304681269233504384U;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8383399721062437300U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13181984036942227666U;
            aOrbiterF = RotL64((aOrbiterF * 1648761328771932069U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13602604532551684210U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12725687663616352843U;
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5831790822416009806U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4535048543735457407U;
            aOrbiterG = RotL64((aOrbiterG * 12076777878870257053U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10617608605149381858U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5244225377862618630U;
            aOrbiterB = RotL64((aOrbiterB * 15307177251167023999U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18229989093139888456U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9728120630096192811U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16052574428163231023U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1312233443099767304U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8043115602160128619U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9365756845731616963U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterE, 10U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 58U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20077U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23952U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24448U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 20481U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 10U)) + 4476099022490972343U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 39U)) + 16836423700375760429U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 51U)) + 8850577488928703557U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 7091631824560042743U) + aNonceWordG;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 12560498899956759494U;
            aOrbiterI = (aWandererG + RotL64(aCross, 35U)) + 7797973377112012161U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 51U)) + 6173820673874805794U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 5U)) + 10805025132310245348U) + aNonceWordJ;
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 7139216143268029968U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8241544862261635722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4735527016563596150U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6621354217673598381U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5166171126690294033U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11117641762075368393U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 4980156869201219393U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6312932356458415421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1304139291184508668U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10085025354842771067U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16745854428789531080U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1945983905747274355U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2497187958708890337U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16069701876646548995U;
            aOrbiterG = RotL64((aOrbiterG * 16606039730973709495U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17242004368025978091U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12334315722243232121U;
            aOrbiterI = RotL64((aOrbiterI * 16528598396696346719U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8007042082518126895U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5665686359038811484U;
            aOrbiterA = RotL64((aOrbiterA * 11289316305875751813U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3913477186958600592U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16918984318564170343U;
            aOrbiterD = RotL64((aOrbiterD * 5128293326494417281U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10227611546502931418U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7187623463085447228U;
            aOrbiterE = RotL64((aOrbiterE * 8479839369622163181U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 21U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 10U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 36U) + aOrbiterI) + RotL64(aOrbiterD, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26190U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28401U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26966U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24671U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 48U)) + 9080426856729228705U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + 7851218321653539276U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 7023344692919298036U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 9772846154227440734U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 14U)) + RotL64(aCarry, 19U)) + 12008298632429608431U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 43U)) + 12201090455849562875U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 53U)) + 9498721803411445471U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 21U)) + 351203764023093632U) + aNonceWordI;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 39U)) + 4966360430644539250U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9194167899071345693U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 4922477697284269116U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 8444814161720407881U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15742625291642356429U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7528703106518431730U;
            aOrbiterE = RotL64((aOrbiterE * 11530049278751507567U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15279053574704935317U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 13209849392400008898U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9041500097716231309U;
            aOrbiterH = RotL64((aOrbiterH * 340661035700748739U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7885423750878814599U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1992993999902904603U;
            aOrbiterG = RotL64((aOrbiterG * 1478629826632201617U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6120758615019314102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8529621625846992066U;
            aOrbiterA = RotL64((aOrbiterA * 8485991471612862467U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9125182130757385320U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15691232622970220043U;
            aOrbiterJ = RotL64((aOrbiterJ * 16517916951054758147U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11413090085435424697U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11563151001080914939U;
            aOrbiterF = RotL64((aOrbiterF * 16828196274450408201U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1778975369262558069U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3232132443557192010U;
            aOrbiterD = RotL64((aOrbiterD * 17132823737792200981U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 60U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 10U) + aOrbiterA) + RotL64(aOrbiterJ, 52U)) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBE9302FE58C22909ULL + 0xD130A12502237B05ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAFCF3BA7228C0C63ULL + 0x860198E25DBA0080ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF00C4C8391312733ULL + 0xA68103413DFC09A7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA3A8C4E6A797CED7ULL + 0xD89C369C3948250EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA512D19AD823E0FFULL + 0x8534EFFE4614639EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCD71A1BCE1BF1D2DULL + 0xEB1A417A4497BCE4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDEA919B18B0F95EBULL + 0xD79BF98D9466AE07ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x83B2177DAF4302E9ULL + 0xDA43C239A77C756DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC63EA35997F91475ULL + 0x9705CEA8B45A42F0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x98EC157A4DE0A7F9ULL + 0xD1351F2AB367EBBAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x89109ED81C9B1415ULL + 0xF1E878E18752FBE7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE4FE302CC275BA31ULL + 0x85CE97A21C739B42ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBD4D9963E4F26DEDULL + 0x8C3133839C6EDAC5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDCDD81E98DE7C407ULL + 0xC72DA9F4BDD32235ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC807F065EFD14321ULL + 0x8368674101CFD5D2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9B2C51D0E8E7AD23ULL + 0xF1D07E7F9F0C46C5ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1239U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6458U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 516U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1115U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 42U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 12U)) + 1708250618750199233U) + aNonceWordJ;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 12009147777553691142U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 8393982703399156592U;
            aOrbiterD = ((((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 3247327098356831221U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aWandererJ + RotL64(aCross, 35U)) + 3403590155376353737U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18197244558104735044U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3096253642040701606U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 6656168712438620783U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 8012692688785412179U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17531946907545680745U;
            aOrbiterC = RotL64((aOrbiterC * 16510602981731506381U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17687695944270225817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16147773866007628769U;
            aOrbiterD = RotL64((aOrbiterD * 16926442582711557877U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 18244641303026196497U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8839160526348897457U;
            aOrbiterJ = RotL64((aOrbiterJ * 14268021129087663397U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10599266240854068246U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13311591601230386375U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 30U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12460U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11501U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15765U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 11409U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 51U)) + 9435962834163239322U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 10524704356081318973U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 7403401305665208680U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 27U)) + 7525414805023556493U) + aNonceWordG;
            aOrbiterE = (aWandererK + RotL64(aIngress, 35U)) + 1116686470029070951U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13257612299137802420U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9181543003986598283U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 18162011316880411235U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9739384852307501107U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11308402900229016057U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12690186771773188967U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14935167593705272337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7171824007631943535U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4839974427616194289U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8068411284829563567U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12350207458513447578U;
            aOrbiterG = RotL64((aOrbiterG * 813973258659041895U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17039236343991574134U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18291683592714999632U;
            aOrbiterH = RotL64((aOrbiterH * 7771718817924840713U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 38U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 52U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23191U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17831U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17172U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 20916U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 42U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 5U)) + 12669015908335980355U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 38U)) + RotL64(aCarry, 39U)) + 5438715179868613192U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 13172104448184536460U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 13421421503244744803U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 13327113302994856582U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4671768205922454413U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5355759962838579929U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15080379163499722187U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6691720614265406851U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7063906424700911378U;
            aOrbiterE = RotL64((aOrbiterE * 17091734375516280675U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17328616394166672263U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 1542940602574207068U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 8981679306319627975U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7203866278803132454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 993485696233139264U;
            aOrbiterB = RotL64((aOrbiterB * 11609009908810366447U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15659679028507488331U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18321361454094675842U;
            aOrbiterC = RotL64((aOrbiterC * 3966860765622641843U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 10U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30721U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30833U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24958U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 31217U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 15383045568644941552U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 17452811657750910067U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 15660117718455155603U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 12U)) + 10396441207743665753U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + 3708971058200841442U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7000673057768598750U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9886354469011131596U;
            aOrbiterK = RotL64((aOrbiterK * 296615166652808759U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16018065329058043467U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5024756166109352320U;
            aOrbiterA = RotL64((aOrbiterA * 11660932185479046483U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6587818720728886652U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3652672354944162319U;
            aOrbiterF = RotL64((aOrbiterF * 10807121230791716109U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6307315649915348048U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16405347331742979258U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7183142442906743699U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5427299664054601957U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14646556236306407673U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 60U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordE;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB0F9CD5E59FF59B7ULL + 0x9B323B54FDAF0840ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA686CDC1C2BDFCF1ULL + 0xDECEFFB26C7BC038ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA8C2042E57527D59ULL + 0xE21BA89A60E25559ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA99516D00FF86781ULL + 0xFE393655454225D4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEC7E1737966C4B1DULL + 0xD08B6213F36E1FB3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x94DACCBB83DA52F1ULL + 0xD8207FE39DF8989BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB82EC5C08D6A7D8BULL + 0x81EA59F7795E0D31ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD558ADD679EE6CCFULL + 0x87FDEAAC611FB602ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD3539750098382F5ULL + 0xFF4BBF024C335A9BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE3AB194405FC8DD5ULL + 0xEA7F21794EC956B2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB7F52E3D8DC1B569ULL + 0xC1CF8206DF6106E9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCBFCD39F2CEAFBCDULL + 0x80DD386C251D5D7CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC13432CD167A7ECDULL + 0xB25ED01174D25754ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA3289E6BDB176C5DULL + 0x9AAF1FAE9317208EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEC8FFC5E54DA020BULL + 0xE52303137C6C6D3EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE8ECFAFE0C90D205ULL + 0xF99C6FDC77841D12ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2528U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6512U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2488U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3613U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 5960680319644404115U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 16050752633567034185U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 8447503223226854741U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 14176813813397917591U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + 10534915376130006644U) + aNonceWordN;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 13U)) + 6866224454375302514U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 23U)) + 16506374165041008396U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7167814023968794098U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13870852197416596664U;
            aOrbiterG = RotL64((aOrbiterG * 17015971222069856463U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18064038854848993105U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9869630811507771691U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13723164383800461387U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 863613100452759380U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16597969741225436529U;
            aOrbiterA = RotL64((aOrbiterA * 2680793528887208903U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6575347108051310653U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17062262265485019063U;
            aOrbiterJ = RotL64((aOrbiterJ * 7601045488473620019U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7193399224636409133U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14146747818810433849U;
            aOrbiterD = RotL64((aOrbiterD * 5273185769989530041U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9441449106442431427U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4303295336545399503U;
            aOrbiterB = RotL64((aOrbiterB * 8829695296836242587U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12604760768543193458U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15779327512379787715U;
            aOrbiterE = RotL64((aOrbiterE * 14000905201441272597U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 56U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11775U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 15892U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11378U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 16275U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 13U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 29U)) + 16016931609704150191U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 14511433515861302636U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 11691237442613269593U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 16383220587320484649U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 14293015313458219868U;
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 4407695248205526670U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aCross, 58U)) + 1158323195324398372U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6577683409653864555U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 171080079472863843U;
            aOrbiterG = RotL64((aOrbiterG * 3063978974927752653U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 5766333425872228205U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16173508656917582960U;
            aOrbiterD = RotL64((aOrbiterD * 12187968015372936695U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11781450063402219202U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterJ = RotL64((aOrbiterJ * 4331137994135472025U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4006310759400926020U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13156817947481574467U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 563189239835001483U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12791290558893516411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 989729955679243234U;
            aOrbiterI = RotL64((aOrbiterI * 8757228712495095017U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 838379839663022790U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2830743864262313606U;
            aOrbiterH = RotL64((aOrbiterH * 10173947177104802797U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2146646527331684652U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4629168181742174906U;
            aOrbiterF = RotL64((aOrbiterF * 9046124907945045131U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 22U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererB = aWandererB + (((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 41U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21690U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 21737U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20095U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22094U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 22U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 3U)) + 14008824488073394623U) + aNonceWordB;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 13317978415866411468U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 13209180141897453900U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 12U)) + 11870521586865233578U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 8052156380448047385U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 12158131176743680605U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 21U)) + 14674467487607719347U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18055496790566231147U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3838105585041578784U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1075709247574580091U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2839568255183054418U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11933612922864258179U;
            aOrbiterJ = RotL64((aOrbiterJ * 7571964469321160347U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6289849094151630580U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2640344350528492271U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16197726750829369365U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16306175266267657791U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3339898380394883600U;
            aOrbiterF = RotL64((aOrbiterF * 7105436590182982373U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15017076663742800002U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8973064296077602496U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9309462227233615761U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17580319233338139859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14063208878807603874U;
            aOrbiterC = RotL64((aOrbiterC * 16601475239075164585U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13326130855721009942U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12843186026737544416U;
            aOrbiterB = RotL64((aOrbiterB * 4975848122837321619U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 6U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31772U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 32527U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25596U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 32007U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 13960289014350612206U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 3483331015269589730U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 6873299241002444518U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 19U)) + 3562094007125534229U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 37U)) + 11422367439932782705U) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + 532453428514259816U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 10U)) + 17810941465810193088U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11869759058631106331U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8837581071876177566U;
            aOrbiterD = RotL64((aOrbiterD * 15329827515970522213U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17185378327053837778U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7578253375676981500U;
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17112646434432814442U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14949096407295697881U;
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4259590620758467836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6534899413644542303U;
            aOrbiterF = RotL64((aOrbiterF * 7987609419215568661U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2637407498893694243U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15819295597921425711U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6373559542002699718U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11694562937392022505U;
            aOrbiterI = RotL64((aOrbiterI * 9311557972331218597U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3308736483775453062U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12749929710650475901U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 248428400724560945U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 12U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterC, 40U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAEA3ABBCA3E6BB1BULL + 0xE179316ED67BB38CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFE491A00110E7FC9ULL + 0x879388579C8429C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9D938BAC6704849BULL + 0xB09975D95DEF7B1BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEF86E37C75A41ED5ULL + 0xEE05E451043C4290ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8B368157E8493105ULL + 0x8E59FBE7F3438F6BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBE610D7D665F723FULL + 0xFD7DB68F5BF90938ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE01A34025ED2A68DULL + 0xAF5D60363B0319B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9BA15738076E36FBULL + 0xD7E73CA91A8B54E4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFC3AC198D967F065ULL + 0x8B99C18DACB34B11ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDF8AC033E94079E9ULL + 0xB064F0CAB702098AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCB2D7E948900CB47ULL + 0x8F669006DEC0A824ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8907BB0DA164CF91ULL + 0x8F0CE11954073EE9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCCC44D32CE157ACFULL + 0xD51180867CB2373CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x89A10C3DF6021BC1ULL + 0xC9343330F3F47BBCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8E092C803F479045ULL + 0xD217734D0A53706FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFCD0BD8784EC009FULL + 0xFA3CAF0C9E2DFC7FULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5100U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7804U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6763U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2774U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 28U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 35U)) + 10915618884692072446U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 12634922308499254909U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 6533934734564499389U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 6744203303756105181U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 13U)) + 13086782386652045658U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 5693840533331397822U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 6U)) + 1803663542535024611U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3597219300593287708U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1429753448204448904U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10927459251773273143U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17229017825587322715U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1137574712801062932U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3645832160939819415U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2401991077004083378U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1332473247826139292U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 15029831858261506447U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11730946340796899885U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15319163439700390962U;
            aOrbiterG = RotL64((aOrbiterG * 1349242001887975499U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4744141870145159917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6067132201862688684U;
            aOrbiterD = RotL64((aOrbiterD * 6046100687757836027U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14991509179286371800U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4342608825699398682U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10240526103933275875U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3727521409410742075U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3302027219498304367U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12153634588200479559U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + ((((RotL64(aCross, 18U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 10U)) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16195U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 8836U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14440U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 8496U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 29U)) + 12632404972795375757U) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 5351879979055988456U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 51U)) + 3597737727467443413U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 35U)) + 2830846754917852318U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 17311925960294518018U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 44U)) + 2083584640523695383U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 15049343611387010158U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6443050378205811147U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6021965178697344070U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6054064448935006741U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5080289878758029976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 576927745306972983U;
            aOrbiterA = RotL64((aOrbiterA * 16008958833683246115U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4728489691382690859U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6184355840165758855U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 1515043910404156423U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 11220539885798595450U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11091438724966718214U;
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17184210490020062419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2150997767099116408U;
            aOrbiterI = RotL64((aOrbiterI * 8058553821648892499U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7021953562676903717U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17159676348343312834U;
            aOrbiterE = RotL64((aOrbiterE * 13877284519668483549U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10367891770525239784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11922478487264201233U;
            aOrbiterH = RotL64((aOrbiterH * 9195137452661956029U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + aNonceWordO);
            aWandererH = aWandererH + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 36U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21990U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22945U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22139U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18657U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 50U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 57U)) + 2672739400294801233U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 29U)) + 8475624545015101850U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 1252755112289831257U) + aNonceWordJ;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 7938039507649183387U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 20U)) + RotL64(aCarry, 11U)) + 8167413146948861022U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 37U)) + 17712313989694374353U) + aNonceWordA;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 3U)) + 7637042279892596975U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15770412950033467341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3951812021898608685U;
            aOrbiterE = RotL64((aOrbiterE * 6623127125223204737U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8656983621098246507U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17943342344730687317U;
            aOrbiterK = RotL64((aOrbiterK * 16495519451034883813U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3087677463651608668U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16493240011924342788U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 16898479041530771871U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7750923317452683057U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2185924841611106546U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 708072658250726381U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14676868738946722416U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6849098251696302393U;
            aOrbiterB = RotL64((aOrbiterB * 2599806275837778069U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17817755047153606419U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9900465270314068757U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9267925873983176685U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11380000891112113701U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15930503831156546113U;
            aOrbiterD = RotL64((aOrbiterD * 14450535035065393845U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 10U)) + aOrbiterI) + aNonceWordN);
            aWandererB = aWandererB + (((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31325U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27158U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24823U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32152U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 15549114274303128055U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 60U)) + 16466750056388063241U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 12209449840836787142U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + 14551496099734294336U) + aNonceWordN;
            aOrbiterK = (aWandererC + RotL64(aScatter, 35U)) + 6266576428679808622U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 19U)) + 16892841575635668152U) + aNonceWordG;
            aOrbiterH = ((((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 7375966221423362125U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11926105302821753530U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16219253791550461124U;
            aOrbiterJ = RotL64((aOrbiterJ * 2117550758226173419U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7299056065319248160U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15234001484933728439U;
            aOrbiterA = RotL64((aOrbiterA * 8182244796017018911U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6615802589932632120U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5481176858895819247U;
            aOrbiterG = RotL64((aOrbiterG * 3604590158551984877U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17220507586542139380U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14137921473739415340U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 10634645686035907603U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16981960446540932787U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10897565927079518588U;
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2746889569299593263U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4894117146736361379U;
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18294823016957137777U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 86828501068883383U;
            aOrbiterH = RotL64((aOrbiterH * 11432686669235402365U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 10U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordC;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD4948DADE54C03E9ULL + 0x91CFD1B01379184BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCE4151E51FB64DD5ULL + 0xB821233E941324B7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA84E2817CA9E79E5ULL + 0x93D843169E4581B0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBFA456005A1785FDULL + 0xD672A1D64074B42FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x965A5FAAEA5DC153ULL + 0xDC91776204B4F41DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA376CDB542445F1FULL + 0xE2B931607A37D066ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEB61C96ECD6B83CFULL + 0xF346193721D7499CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEB828B6B1D516BE3ULL + 0xB71E5A15F623F5A5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD427F60DCB0E2DB5ULL + 0x83A912F026B74C8DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA881E3BE1786752DULL + 0x8488615D46585D7AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF372C9A585DB79D1ULL + 0xE5D149947FD746D5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD3DA787E4C733DA5ULL + 0xE53E0894CB1C3F67ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBC8F3CE2F11EC9FDULL + 0xA98FAA5ADF9423E6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDBB964D1D41C26F7ULL + 0xAA85CD0A04A9290AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x95D9DA3D4F8EC407ULL + 0x9D60103B36A84404ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA471EAED869CB7EDULL + 0x977CB9F698BBDA4EULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5473U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5350U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2513U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 6366U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 28U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 13481227414590594621U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 13U)) + 17425964381118918026U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 27U)) + 4792004356135956581U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 54U)) + 11926849936000639098U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 41U)) + 990697329347742142U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + 9307721505373076588U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 17605732738841908719U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 21U)) + 13110764518634187439U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 17970109897810645911U;
            aOrbiterF = (aWandererD + RotL64(aCross, 43U)) + 10273133817644703654U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 11239046688920468137U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8355821483275763145U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4844278537850520413U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5381663179722418112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9551368011768104906U;
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16264476585232221270U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7721417776432288282U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 339418090653475277U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3247926250495935511U;
            aOrbiterB = RotL64((aOrbiterB * 16824669543765729097U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3390560045236418590U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3894024951542543635U;
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3878539166189668154U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5617705593218220843U;
            aOrbiterA = RotL64((aOrbiterA * 82771190372750823U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12320861089148474544U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterH = RotL64((aOrbiterH * 13758322022902008313U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18119213517612562775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1413193144229486646U;
            aOrbiterJ = RotL64((aOrbiterJ * 14562375280658115687U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14810150213456844196U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8468712395797520201U;
            aOrbiterD = RotL64((aOrbiterD * 8167911669632436949U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13501570100536254566U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15409772061478100850U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 955182899606655851U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8621805947309982779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13481227414590594621U;
            aOrbiterF = RotL64((aOrbiterF * 9591362493722704105U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 24U) + aOrbiterI) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 42U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 38U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 42U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10111U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 12989U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12106U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8762U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 24U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 9654059367478508868U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 27U)) + 6473006635864677427U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 43U)) + 6944184481315853243U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 4061496421939102306U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 56U)) + 15791809275719085463U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 11U)) + 14050798802646323055U) + aNonceWordN;
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 12072905924741758266U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 17639076509231343896U;
            aOrbiterD = (aWandererI + RotL64(aCross, 35U)) + 12195388285571234715U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 41U)) + 4325404419499496529U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 46U)) + 5910567888204238382U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13092940059929942699U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6345904465930943295U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15622862439323440527U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14027151901132249793U;
            aOrbiterB = RotL64((aOrbiterB * 2273573821630510087U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4584410023907605157U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15763755180625487157U;
            aOrbiterF = RotL64((aOrbiterF * 6755736130607297639U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17023059745666559199U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5298529579288492971U;
            aOrbiterE = RotL64((aOrbiterE * 2483562793328357721U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2870152867331654736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12017191100173748848U;
            aOrbiterD = RotL64((aOrbiterD * 9958191466506480519U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15899529176182436062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16482713846343388735U;
            aOrbiterG = RotL64((aOrbiterG * 719465695044265601U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12943393531812774449U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9881108254540483225U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8011108108007885059U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3532054586199716750U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7142230313294797435U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14154176174768868421U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 733958394016131587U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2060800099014517137U;
            aOrbiterH = RotL64((aOrbiterH * 12988885554457108631U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2278498033811574812U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15342071118593803929U;
            aOrbiterC = RotL64((aOrbiterC * 7842196613533603835U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12987212219357101955U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9654059367478508868U;
            aOrbiterJ = RotL64((aOrbiterJ * 11796100167917742307U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 44U)) + aOrbiterI) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 36U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23393U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 17142U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19977U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 19748U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 57U)) + 12615321415808640429U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 53U)) + 15712784676459931207U) + aNonceWordJ;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 5U)) + 11013335427004930046U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 10U)) + RotL64(aCarry, 39U)) + 8298733856304768806U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 6207732959150824216U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 35U)) + 9769864876127544038U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + 10782181918651152563U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 37U)) + 5790454015845620939U;
            aOrbiterE = (aWandererI + RotL64(aCross, 26U)) + 15606578025386733803U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 19U)) + 5522352539991175304U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 5993355818572869649U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10864534396947622047U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12090053126235913528U;
            aOrbiterC = RotL64((aOrbiterC * 7250801471645972261U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14191181677234981396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2258570108233924592U;
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8448114811381534603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterA = RotL64((aOrbiterA * 6710443836432274393U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17202184076718780200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 150549910056015002U;
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4910512055808124967U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4783477997418403079U;
            aOrbiterD = RotL64((aOrbiterD * 861977492146512865U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13842899106208709771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7930112618036681468U;
            aOrbiterK = RotL64((aOrbiterK * 8609551859830858419U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8790107242863198659U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6882768826643279144U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 13745521454063360763U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12136498871759890015U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8120456314755584336U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1830725195528043575U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14425711740351183016U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15907406009196323049U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8599371693260686839U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4878521420367891861U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1184672056055028939U;
            aOrbiterE = RotL64((aOrbiterE * 5963961755367831967U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10126736568567000180U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12615321415808640429U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 11663715449073755137U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + aOrbiterC) + RotL64(aOrbiterD, 14U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 58U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26065U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26755U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29269U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25114U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 43U)) + 12136097566601676613U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 27U)) + 7969431322248040056U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 37U)) + 10530676021510553889U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 23U)) + 8740777303075445264U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 46U)) + 13249434169895564739U) + aNonceWordF;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 29U)) + 15529577005925628472U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 344627093687331562U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 8824277416519988893U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 19U)) + 5636276438449709875U) + aNonceWordJ;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 57U)) + 2079413361031851552U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 35U)) + 7807998179168655561U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13589392896232029112U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10733011474804473996U;
            aOrbiterA = RotL64((aOrbiterA * 361749145931578805U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15934162328347805968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7573511217796245232U;
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 4828475187337891975U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13284974329890393113U;
            aOrbiterH = RotL64((aOrbiterH * 10831075817642374287U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13173869918669643112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15841507674783398167U;
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14168272451055700516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11134471485501999898U;
            aOrbiterK = RotL64((aOrbiterK * 8019507184494591705U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2611858916687822610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17863271539727513641U;
            aOrbiterG = RotL64((aOrbiterG * 4987884722174985677U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8874401993454249066U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5131480593493950665U;
            aOrbiterJ = RotL64((aOrbiterJ * 8585874663602346121U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9366563022381918996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7890729519928340296U;
            aOrbiterB = RotL64((aOrbiterB * 11428572374057899517U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 131774386529223292U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4108356674478240148U;
            aOrbiterD = RotL64((aOrbiterD * 2492753294539081613U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7651738365157869789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2745458108574051004U;
            aOrbiterI = RotL64((aOrbiterI * 2175955806036373729U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10492013124307434604U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12136097566601676613U;
            aOrbiterC = RotL64((aOrbiterC * 13128652803485742119U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 10U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 22U)) + aOrbiterC) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterJ, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordG;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC9B547413D700F29ULL + 0x9541725ACE3A41B0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE75A59873B1EB919ULL + 0xABAA3E5A9CED8C57ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFD5235C2C6E4D5D3ULL + 0xE1F5642E88C47080ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x954E260F0213E907ULL + 0x9492484F8E336373ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC90DD3BF2A8F6279ULL + 0xE322288C0521E491ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCCFFF95F4DA7ABA7ULL + 0xDE48E2D26423A8A7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDA9803F647CE6E83ULL + 0xB9808BF78C945C5FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8CE8F85EB8932CE5ULL + 0xCA8EDD87BF21F74BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAA3068585144F85FULL + 0xF310039B94C97B39ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x87B022273A2566D9ULL + 0xAA44C5348AD7926EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF82BFCC85C480DBDULL + 0x931D9932DA83E747ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x91FFE2CDDA570F1FULL + 0xE85FB85D16C843C3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x82F0A23FD698AD65ULL + 0xE63B30ABA04D3D29ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA808E5BA221A954BULL + 0xEB9C8D59621ADD48ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x99360B1A77FB58D5ULL + 0x973BED71C467A480ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE37E0F3B91D3B25FULL + 0xAC951D1365817C61ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4494U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((aIndex + 1093U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3722U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1214U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 43U)) + 2101601659597850213U) + aNonceWordA;
            aOrbiterC = (aWandererE + RotL64(aIngress, 53U)) + 2759794072560720121U;
            aOrbiterD = ((((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 9443562552411269339U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 10U)) + 10801360546699857975U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + 8020716394829332019U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 23U)) + 1021894212367773801U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 13346855534622490176U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 16359309548462953836U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 43U)) + 12642446944680783519U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8197424982767553380U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14346334610901859094U;
            aOrbiterD = RotL64((aOrbiterD * 16982899923227935679U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14171304260534233539U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 334531601308283605U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10707856298471572695U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18364775750091914766U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8531394793118363836U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15352876929406908882U;
            aOrbiterG = RotL64((aOrbiterG * 475199047053777179U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 567682016232278157U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2068146551757663119U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1557877740957797555U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7776122587613256525U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16430938890724272256U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 4540270493783593257U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11912000645055436094U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 16800749242578741498U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 17804584625034241737U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5909199180260499150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5751089915336865588U;
            aOrbiterC = RotL64((aOrbiterC * 15376689503142397927U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3478216857728853008U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18007567146937338241U;
            aOrbiterA = RotL64((aOrbiterA * 6620498877303917855U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 24U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7226U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9410U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5989U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5621U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 7790166497945719700U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 12U)) + 7136208896846119188U;
            aOrbiterH = ((((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 12123156943355100886U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 5095546037880875199U;
            aOrbiterA = (aWandererH + RotL64(aCross, 47U)) + 17642705393916765992U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 57U)) + 9918479837334416990U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 40U)) + 4890009823843176466U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 3U)) + 17652590786213674124U) + aNonceWordP;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 35U)) + 870002527644696135U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12545429703552643682U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5310272867406182581U;
            aOrbiterH = RotL64((aOrbiterH * 10420003334833925011U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3264719049050179440U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1967241238180278937U;
            aOrbiterA = RotL64((aOrbiterA * 13004319774269457957U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 773883832927040736U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12766817190261232485U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7448864556802318431U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 260069382395598265U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15462103891287350123U;
            aOrbiterJ = RotL64((aOrbiterJ * 5029268763635635753U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4072032867513289827U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17153061419083897076U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11934532169271718913U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6207264270332656966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18048064697837314947U;
            aOrbiterK = RotL64((aOrbiterK * 13632594619404208489U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14484617445340272026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16160443600497652026U;
            aOrbiterD = RotL64((aOrbiterD * 1988599349457831597U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5873314228291583482U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16418290052752166515U;
            aOrbiterG = RotL64((aOrbiterG * 18270363452003213317U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9158414409987627714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8205937960146492168U;
            aOrbiterE = RotL64((aOrbiterE * 14008398661393344261U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 46U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 6U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11217U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12265U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13919U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13013U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 51U)) + 6771552164800695068U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 12131763371571322040U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + 3326182381395522013U) + aNonceWordC;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 35U)) + 12288775097697156383U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 5195948373449796741U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 57U)) + 14404044002250137144U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 20U)) + 11142382920035825426U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 2967149520256475485U) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 47U)) + 1470907369577818097U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9231668148004163910U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13078929163913892386U;
            aOrbiterI = RotL64((aOrbiterI * 7509829068700523627U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9485274692075657877U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12216951187543631673U;
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6933334652581744234U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17260276102423580920U;
            aOrbiterH = RotL64((aOrbiterH * 7796879893790990605U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 387767848169714392U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8597538259308082638U;
            aOrbiterF = RotL64((aOrbiterF * 4888054690557707241U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7996708724489146033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15357384191688149939U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9827691726832491373U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17739222908739454637U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1614322333281471170U;
            aOrbiterJ = RotL64((aOrbiterJ * 7063116837752240891U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4531604274893197209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3453280714992341288U;
            aOrbiterA = RotL64((aOrbiterA * 8390029711127907805U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 116623650872661533U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6565636510115095988U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 9691897067492501177U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10303258439817808058U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10917642773040237611U;
            aOrbiterB = RotL64((aOrbiterB * 10232856828372963363U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 36U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterF, 28U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterK, 4U));
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20550U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 17526U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18622U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 17408U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 2786079456995203065U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 36U)) + 7237256119153857253U) + aNonceWordN;
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 9310834010563647604U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 13U)) + 17361734905706517877U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererE + RotL64(aIngress, 19U)) + 15837111231884647451U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 60U)) + 18065431964418026445U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 3029123922999952652U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 5166926595573507837U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 47U)) + 1918425684273807598U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4724551751012661440U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1818014487579644390U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14904092108647864911U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6670090372241084216U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8485757110007268693U;
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4928130251509514742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2528788422725346792U;
            aOrbiterC = RotL64((aOrbiterC * 1855982047967756661U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2860387120895147503U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12927802338151379368U;
            aOrbiterB = RotL64((aOrbiterB * 8876144125458603029U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18029699867733207083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13361836994951253312U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5349767426256597073U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11957294454794128079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3755417922063414648U;
            aOrbiterE = RotL64((aOrbiterE * 13896364063651241401U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18001157153447913032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16214145724690286854U;
            aOrbiterI = RotL64((aOrbiterI * 5874139687703360515U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3860958772090975562U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12395621524459640173U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 722817135977510161U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3402035664910754484U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2139099117325745602U;
            aOrbiterJ = RotL64((aOrbiterJ * 14008983756425796029U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 12U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 58U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 38U) + aOrbiterC) + RotL64(aOrbiterE, 22U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26153U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24503U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26564U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25548U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 53U)) + 15036852811491820366U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 36U)) + 305637140752898475U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 11948631574496129610U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 5321623592482991426U) + aNonceWordG;
            aOrbiterB = (aWandererF + RotL64(aIngress, 3U)) + 4075270159062690728U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 13U)) + 15111580500356908928U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 29U)) + 7244150695504160363U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 5131563519577488862U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 19U)) + 5881954992088651371U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12780935808751507998U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12599159643925470226U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17690046932587062701U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9466589929741834066U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6093158735705189789U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7453778295800853653U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17461243886150519249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15456408913739900718U;
            aOrbiterF = RotL64((aOrbiterF * 16093292401746174671U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11260643903290392780U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7870342756041882616U;
            aOrbiterC = RotL64((aOrbiterC * 2431528656086173419U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 134484990005888936U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10626896209992890407U;
            aOrbiterI = RotL64((aOrbiterI * 12034131076645285597U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14031164129515132292U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1771835705730244212U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 186981668443596623U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16395472745067254664U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1455944290845294254U;
            aOrbiterH = RotL64((aOrbiterH * 6757824754363319079U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17866422769075350837U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10226884082632410805U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 206035536985843815U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14474587247775371703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8501763445324525303U;
            aOrbiterB = RotL64((aOrbiterB * 5298694643596784007U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 4U) + RotL64(aOrbiterD, 48U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 18U)) + aOrbiterC) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aScatter, 22U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30514U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 31053U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31401U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 30619U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 13U) + RotL64(aCross, 30U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 8402620908307642697U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 5U)) + 11347672014525086047U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 2816462912503401876U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 41U)) + 6940159795470696093U) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 13U)) + 9134692490095883851U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 4999455497008026526U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 54U)) + 5992451460350651332U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 3417087346651371924U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 27U)) + 3612773820086198270U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 463398077083428570U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11249391303705089012U;
            aOrbiterF = RotL64((aOrbiterF * 7106735772303292983U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17027535139825739501U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 568131384979596481U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 5683451044852895957U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4793712537158004047U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10415170179135963622U;
            aOrbiterI = RotL64((aOrbiterI * 13729564030210361415U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2391473979460065630U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4240058362680064261U;
            aOrbiterA = RotL64((aOrbiterA * 12375884373396400889U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9963957011090031698U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3325305624067445525U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3128542681461806309U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2094945647665114693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10703615640774042674U;
            aOrbiterK = RotL64((aOrbiterK * 12641986098450423751U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3768738815518590289U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15021301790376706827U;
            aOrbiterE = RotL64((aOrbiterE * 14445850924223550339U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10571246886181608316U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5130325144599151793U;
            aOrbiterG = RotL64((aOrbiterG * 3185251943547657467U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8617523421720966373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16574597770835250074U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1759209403428937799U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 42U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordB);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE39C6D94C768EBB3ULL + 0xE503DE647FEB3A91ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD76C7CF0F6887385ULL + 0xA827FB57FEB1B87DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB70C37BB22DDCB81ULL + 0xF1B28162293018A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x97E12E1D877EF981ULL + 0xC85F281DA047D2F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9501B80D8D242425ULL + 0x80B6D35556282174ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF8EFDF2383EA6C25ULL + 0xE9E6FF3473B66449ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF8CA810D4EF0E34DULL + 0xA167AE84AAB9D08FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDA3BFA1A32F4567BULL + 0xE03135AAE4BA458BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC0850CDED2E1C47DULL + 0x86DA6E3ECBDDD52FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x849480BDCA135797ULL + 0xFC29D4C6F6652D9DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD2E3BE7D32B96E7FULL + 0x82CD492CD99108F7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD8E981F3E167B795ULL + 0xA552A6469E29E43AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF16C927388A36713ULL + 0xFAC49ACB90AFFBB7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA0E9CDB44EBE2D25ULL + 0xE0D2B610094966EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8973BFF6BC1613AFULL + 0x885694DEF16F53A5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8BE3D45099A45949ULL + 0xC2FAC82E4A4C29DEULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2363U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 5446U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3876U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4177U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 11U)) + 12775735908960052604U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 11791373812080296887U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 5537362877706057303U) + aNonceWordL;
            aOrbiterH = (aWandererG + RotL64(aCross, 5U)) + 2023912048504189380U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 17668828109963766893U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 58U)) + 558908629933941224U) + aNonceWordO;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 51U)) + 1479633119685446888U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15460320397843364063U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10059749397555469054U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9987633811929693924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10087337844580228269U;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4446204415503364254U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15106063243302192717U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9430197906134676162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1226048679997253363U;
            aOrbiterG = RotL64((aOrbiterG * 14247538885252664127U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10611580584157624739U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3137391249289641509U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9327201928815412810U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7890659377013147073U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10675114832750356941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8804440385852327267U;
            aOrbiterB = RotL64((aOrbiterB * 8520671775587260601U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 22U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterD, 36U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8141U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9849U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10600U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8793U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 41U)) + 8101351470141807662U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6965474099521076705U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 11U)) + 6803828268885684784U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 34U)) + 13454235922950972488U) + aPhaseAOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 11678091885751244777U) + aNonceWordE;
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 5307134544628507141U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 27U)) + 4873703518950429353U) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8542156221858586039U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3993726182905296513U;
            aOrbiterD = RotL64((aOrbiterD * 11331376012938127609U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12113047622035464386U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1944244448665721151U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 7010050836758762003U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12914188029425467576U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2486762763475327024U;
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14580191602982245481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12093414832400135066U;
            aOrbiterH = RotL64((aOrbiterH * 12720286833215690663U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13623906997320021065U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9977356009806428696U;
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 3694954095397810851U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11453812627797091638U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 542311345544726351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3024285045990499484U;
            aOrbiterE = RotL64((aOrbiterE * 5153745952148205645U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 38U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15372U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 15470U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16375U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 12433U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 3U)) + 2225397913940961213U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 8342544893601343643U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 43U)) + 162922186381417187U;
            aOrbiterA = (aWandererB + RotL64(aCross, 57U)) + 11660218373710972210U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 50U)) + RotL64(aCarry, 51U)) + 14909034764605802354U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 16776955237009701511U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 5834487809188925253U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1498492772767040320U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4161765458781579617U;
            aOrbiterH = RotL64((aOrbiterH * 15535994410289065281U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10511923076962447765U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8575954471692620021U;
            aOrbiterF = RotL64((aOrbiterF * 12526744988828982731U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6536325446331340573U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1790628986900286346U;
            aOrbiterE = RotL64((aOrbiterE * 5262997114200816715U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2623814807619278590U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11676970995834706612U;
            aOrbiterA = RotL64((aOrbiterA * 10057461115132434901U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13836786354224256591U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6293096163612129260U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8977954126326217153U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4271144764978661248U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15938494256992560202U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10004841288382726739U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11038155227307702976U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12408749795071243930U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterC, 60U)) + aPhaseAWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18286U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17165U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19874U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 17503U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 29U)) + 16802219662864902427U) + aNonceWordE;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 21U)) + 14332033461409490629U;
            aOrbiterG = (aWandererE + RotL64(aCross, 47U)) + 8781794298640286845U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 8459933908074937264U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 1883580287986004426U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 37U)) + 17500258188004626118U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aIngress, 11U)) + 7934811305150872870U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6380363892361098905U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12623079132626676910U;
            aOrbiterG = RotL64((aOrbiterG * 12406671746344127399U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10455208121949202703U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8805532707916767629U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 666082374369701881U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9161544391400377699U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3501434325829663268U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7933545151293799637U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 651783304096081996U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 441505031509930622U;
            aOrbiterH = RotL64((aOrbiterH * 8045355432310956143U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1771159983581326424U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15227946417377695989U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1563141188972797601U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4153717524193279095U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4404521756523902829U;
            aOrbiterC = RotL64((aOrbiterC * 1410342912973206203U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6231945075461813285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3864780227164426690U;
            aOrbiterF = RotL64((aOrbiterF * 18031353247480673617U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererD = aWandererD + (((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U)) + aNonceWordN) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 44U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25070U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25495U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25537U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24112U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 29U)) + 7893287783892523139U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 10257331997383491153U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 4U)) + RotL64(aCarry, 23U)) + 14562226733652231753U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 51U)) + 14320342577110737851U) + aNonceWordL;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 19U)) + 9816717579822880756U) + aNonceWordF;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 9558926960095881953U) + aNonceWordC;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + 9230371862654338324U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6414274291252913420U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13868546184398350849U;
            aOrbiterF = RotL64((aOrbiterF * 1547986864837497409U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16940736952569949038U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2866957764814864371U;
            aOrbiterD = RotL64((aOrbiterD * 3554702178644797003U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7916721976073979724U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1602444214978842275U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 11072503711308122385U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9529061385251008037U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8402775110887376588U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15003592180290390713U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14195681406520825751U;
            aOrbiterA = RotL64((aOrbiterA * 11455000833788877217U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3263577002367714202U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12019422062655581928U;
            aOrbiterK = RotL64((aOrbiterK * 5002313835338447799U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8508638054582582917U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6536618106353552880U;
            aOrbiterH = RotL64((aOrbiterH * 6233964121117511885U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 48U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordE) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + (((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 57U)) + aNonceWordA) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28053U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 30279U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31389U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29488U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 57U)) + 13583136155674166402U) + aPhaseAOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 12830472187484919497U) + aNonceWordN;
            aOrbiterD = ((aWandererB + RotL64(aCross, 47U)) + 18081197909484522509U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 8680634051297891550U) + aNonceWordG;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 13939998767458656823U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 40U)) + 1795730579103692594U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 17369751719734069999U) + aNonceWordO;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 224769585901248068U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4133547085925268180U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2611561365156544735U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7022512056309567391U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10319484359046945495U;
            aOrbiterG = RotL64((aOrbiterG * 3400140531307001933U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10483878349412282069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6481381149199985736U;
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13721077228796934509U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9704818014314175007U;
            aOrbiterK = RotL64((aOrbiterK * 760445624027740287U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6253040047758584339U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16890211690273641226U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5622534399866057841U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6216227831265032436U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2023609047004658739U;
            aOrbiterA = RotL64((aOrbiterA * 3252332895698310147U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9201669637050388263U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5106927540934338576U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6368134569042291431U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterC, 4U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8FABE5A2D9B559F3ULL + 0xF88D15F2DEA76D1EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x830AAB5AB596DFC9ULL + 0xF6C3A77DAD1C405FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAD1F42F42AB73185ULL + 0xEDE69DA6825C1FC0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFBDCA7B8A010BCEFULL + 0x8A335FBC36EB7264ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB32A0FC17E0E09E3ULL + 0xB36A9540A33894DFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFFA16836ABA5EED3ULL + 0x8A8F4FBA568863BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x969F76D7F967F313ULL + 0xB4186FAAE46E5B81ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE4E7EC426133E6EBULL + 0xA51AA63EC417DBF6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD68E784F667AC171ULL + 0x8C71803EE01880AAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFCEE9E81EAA1A46FULL + 0xC962F1E034222688ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD4C31B33426BE363ULL + 0x832CDB171EA4BC74ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x86441032A69C36D1ULL + 0xCEE2850D574162ECULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF9A7DF11BE9A1D71ULL + 0xDEA942D69203ABEFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC87284498B7949DBULL + 0xCC5632105E114B8AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBCD1FC30A2B6D8A7ULL + 0x8ECABB461F742C63ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCE23D7A42F172FD5ULL + 0xA65DCB37C1DC9219ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4495U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 1570U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3143U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 4071U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 38U)) + RotL64(aCarry, 13U)) + 12775735908960052604U;
            aOrbiterJ = ((((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 11791373812080296887U) + aPhaseBOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 5537362877706057303U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererD + RotL64(aCross, 27U)) + 2023912048504189380U) + aNonceWordC;
            aOrbiterE = (aWandererB + RotL64(aIngress, 5U)) + 17668828109963766893U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 558908629933941224U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1479633119685446888U;
            aOrbiterG = RotL64((aOrbiterG * 4447153373540811385U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15460320397843364063U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 10059749397555469054U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 8671817118586065469U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9987633811929693924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10087337844580228269U;
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4446204415503364254U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15106063243302192717U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13273756657334709803U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9430197906134676162U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1226048679997253363U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + aNonceWordE) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10841U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 10125U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5463U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 7374U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 28U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 11274974230580265396U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 11U)) + 16658438747342741547U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 53U)) + 16612986966106053844U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 3U)) + 9329502236843231290U;
            aOrbiterF = ((((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 14088261356708344656U) + aPhaseBOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13692608802007789581U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6824473946645682398U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13619437545775237601U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2072915876348570040U) + aNonceWordN;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 7420507753044460759U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 13239288539564571257U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4677557318688502593U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterC = RotL64((aOrbiterC * 16659305295251177155U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7026792817486507482U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14871665922943969918U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6807734532159292872U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17882797335141303280U;
            aOrbiterH = RotL64((aOrbiterH * 15439872930381050291U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterE, 18U));
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordM) + aPhaseBWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13086U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14987U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14918U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15483U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 21U)) + 3917730204724097072U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 1874642340716212824U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + 6900165757434854160U) + aNonceWordA;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 12750946097023807161U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 6563216048479513594U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14960240191349450795U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16306180275951788289U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 12077366095522790283U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6502066618271045547U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6219852857850888738U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 10892297250334325283U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2272931312452845850U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3028929882263199463U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11005324285856805069U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6067393030073568112U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10094809900437037258U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18095564940730322769U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5962414178157074575U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 15755563045799129417U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 3692603590609922031U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 35U)) + aNonceWordG) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + aNonceWordB);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterA, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18858U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 17179U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16682U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18775U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 36U)) + RotL64(aCarry, 35U)) + 964165145848253292U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 53U)) + 10645976767204934746U) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 8241612229349212650U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 4159196033256913347U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 3U)) + 7194795864620233507U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7638928444536778384U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11819105916503968109U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9052440449038441625U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18052213302858186237U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8663575313970041570U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14131073322476609161U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16644136720439299786U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16930316530442679864U;
            aOrbiterB = RotL64((aOrbiterB * 2650922074098320859U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16251107616988250593U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7171986193609401665U;
            aOrbiterC = RotL64((aOrbiterC * 3543709971414550087U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17885046834432626644U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7757069274715713557U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15766885299397923879U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 56U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + (((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 3U)) + aNonceWordF) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + aNonceWordC) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22759U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 22490U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23141U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 22770U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 15920462086654025436U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 35U)) + 487844076858004017U) + aNonceWordD;
            aOrbiterD = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 14502883786442630566U;
            aOrbiterB = ((((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 23U)) + 3787107318658233674U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 57U)) + 12548777544693755491U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4907309444075181683U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 18342396700266492072U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14842961036061482089U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13503051997624242670U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17845742460521374571U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 1366356786138085155U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8640887211877858169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5273913123709097537U;
            aOrbiterK = RotL64((aOrbiterK * 1661149444148461791U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17756844173695563883U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6713055830729302951U;
            aOrbiterE = RotL64((aOrbiterE * 2832836748513174311U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5106468334224035972U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10228769728713526172U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9760310686414358435U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 42U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29238U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 32441U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29645U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 28679U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 4179952823252098240U) + aNonceWordA;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 46U)) + 3745613452332101749U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 2955689793395307176U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 5639060180251322019U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + 7901969163853586463U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2242166787816318119U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5239936443960750064U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 2752853245379816327U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13939136954732185558U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17058884136712717463U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 7222348891215482977U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 18148618660054585941U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7022023484530327814U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7722084537340095637U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11764151879690934182U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16412785901758144708U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9666718667728274824U;
            aOrbiterA = RotL64((aOrbiterA * 10865799822751771795U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 3U)) + aNonceWordH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aNonceWordN) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordD);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFCEBDC9A898DF27FULL + 0xC58A1D6A2DC89990ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD71B48241B49081FULL + 0xDCC06A4FE9135366ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFD3BEDDB26EF080DULL + 0x9AB27F63ECB1CE92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xADE622E595DE7AAFULL + 0xF4958599BF950329ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDF32948E59CBFF63ULL + 0x88047B4DFD1FDDD2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF8D664C9447DF7E3ULL + 0x87CA83E07D5DEFCFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x840F7BCBB25111D9ULL + 0xC301084BA8175744ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC326707443602597ULL + 0x8B1DEB31E1730E2FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF4204CB7948129A1ULL + 0xC9B012431645EC0CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE52949DAAC79709BULL + 0xB7AFB95F56A59B39ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCD7EAC19E424B90BULL + 0xA6EF5A5631708100ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xADE5F734E43D41D9ULL + 0xB9B724FB90ABAA31ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCD0B7E577282416FULL + 0xF3779F3F3B4DADA5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD005B8D11C022447ULL + 0x85F4AF34BA93F347ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8EAF70ED85DCBA5FULL + 0x950D992574B69E7BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE21C1532C54325AFULL + 0x8CBD6E5ACC2D5628ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7847U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 7624U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1286U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 67U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 12U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 21U)) + 5960680319644404115U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 58U)) + 16050752633567034185U) + aNonceWordJ;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 8447503223226854741U) + aNonceWordG;
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 14176813813397917591U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 3U)) + 10534915376130006644U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 30U)) + 6866224454375302514U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aWandererJ + RotL64(aCross, 39U)) + 16506374165041008396U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 7167814023968794098U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + 13870852197416596664U) + aPhaseCOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 18064038854848993105U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9869630811507771691U;
            aOrbiterJ = RotL64((aOrbiterJ * 13723164383800461387U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 863613100452759380U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16597969741225436529U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2680793528887208903U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6575347108051310653U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17062262265485019063U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7601045488473620019U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7193399224636409133U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14146747818810433849U;
            aOrbiterA = RotL64((aOrbiterA * 5273185769989530041U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9441449106442431427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4303295336545399503U;
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12604760768543193458U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15779327512379787715U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14000905201441272597U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15553000781122708728U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17162740616060079717U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 9458662233556750239U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1032374679817715156U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16413393156165548232U;
            aOrbiterG = RotL64((aOrbiterG * 549659738811935015U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14056855000013992045U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7399202019042538829U;
            aOrbiterC = RotL64((aOrbiterC * 6103508549612077695U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterK, 4U)) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 24U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 14U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14189U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15970U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8254U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 14114U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 58U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + 16519040829220310189U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 23U)) + 6888002778416941825U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 13U)) + 1310832187746534025U) + aNonceWordO;
            aOrbiterE = (aWandererK + RotL64(aIngress, 19U)) + 5890888009051281674U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 41U)) + 5143864838362464857U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 15591534069452660003U) + aNonceWordG;
            aOrbiterC = (aWandererF + RotL64(aIngress, 27U)) + 1466867671765325096U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 39U)) + 13931443680107902488U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 53U)) + 15400747367673245552U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2836975369734495759U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2370720358274970117U;
            aOrbiterF = RotL64((aOrbiterF * 4615571902817575375U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3470677184188006133U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7175584278499266723U;
            aOrbiterG = RotL64((aOrbiterG * 10067096593682482345U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6095078817776863055U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2176637999243513070U;
            aOrbiterC = RotL64((aOrbiterC * 12215701810843975501U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5580391239754903129U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15196125567953871184U;
            aOrbiterJ = RotL64((aOrbiterJ * 12686361960729564519U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12787014151503209931U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1523153207064063495U;
            aOrbiterH = RotL64((aOrbiterH * 3113907543551927561U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12973289026485937829U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9087439766232078173U;
            aOrbiterB = RotL64((aOrbiterB * 5817029335999350327U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16318022893068674015U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11089160685103562409U;
            aOrbiterE = RotL64((aOrbiterE * 17087834321385147603U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8680037953925067235U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3112588943274158119U;
            aOrbiterK = RotL64((aOrbiterK * 9214011370307670371U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16749015684369649821U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9419550535891334966U;
            aOrbiterI = RotL64((aOrbiterI * 5421312787569114811U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 6U)) + aOrbiterH) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterJ, 42U));
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16436U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17014U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16431U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20174U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 52U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 12426357877879529292U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 4U)) + 12604900366173639176U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + 13511119007338929401U) + aPhaseCOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 9878720081166788060U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 15463195409806395076U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + 6407922778852833423U) + aNonceWordG;
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 7690427254160734016U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 23U)) + 18030974031722143619U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 52U)) + RotL64(aCarry, 43U)) + 17983938038322737041U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16605512170117753884U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 681802273302348322U;
            aOrbiterC = RotL64((aOrbiterC * 14608920184802647123U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15550312921312083819U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1939207786756735430U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3132864634777826569U;
            aOrbiterI = RotL64((aOrbiterI * 13606281919426730325U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12822929773923954849U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 16576106045887115660U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 16370914370769903051U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2398825881649235260U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13700821892926092479U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2439833784883391606U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterJ = RotL64((aOrbiterJ * 3797380922767479287U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9165457123134229670U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8736642509192659417U;
            aOrbiterK = RotL64((aOrbiterK * 16219277537523484065U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9232719746484835693U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7826680628853322541U;
            aOrbiterB = RotL64((aOrbiterB * 12578050118133526187U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14323652326982518782U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2254524512851399313U;
            aOrbiterA = RotL64((aOrbiterA * 4119339547645451149U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 18U);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 34U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aPhaseCWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 28U)) + aOrbiterI) + aNonceWordF);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aNonceWordA) + aPhaseCWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 5U);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31056U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 28879U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25497U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27883U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 39U)) + 17264605017518259932U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 15209184354580778643U) + aNonceWordL;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 3299527965014731384U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 29U)) + 16293096431816127821U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 11031983436878828337U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 46U)) + 9188018632448236358U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 19U)) + 13420816400363406556U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 35U)) + 2485063384097917101U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 11U)) + 3089135816938128264U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10730544971770435788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14883796491656899074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13465877783538483706U;
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4950101626975919939U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17961706029559914243U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10321902557977495175U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 18146616411403012772U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8414050129421955787U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11739172334166341121U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7936637782633487291U;
            aOrbiterE = RotL64((aOrbiterE * 14940929920543800413U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3160044627483874242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16816384076887379704U;
            aOrbiterF = RotL64((aOrbiterF * 5052772186568301951U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8101560104988710226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8851416379738817624U;
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterE, 34U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + aNonceWordA) + aPhaseCWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterK, 12U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aNonceWordF) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB3F1FF3EFF0D8561ULL + 0xF34859E9AF6A85E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAB2965EA053EA071ULL + 0xB95CE3CA03C2E8EBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8BC9200089F629D3ULL + 0xAD4ED25BBB6033DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBA44982EE2829F85ULL + 0xD7AB6A33DF666A0BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD9DAC7A9876546D3ULL + 0xE122194EA7A15C91ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8573EAA432F8CB6DULL + 0xB87D1C9972E020A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF55E9AD76A3E5DAFULL + 0xCAD86720E00EF619ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEF160080DD862FFFULL + 0xF000DD0B50746D7CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF27320E1391B64FFULL + 0xC3BC9CAF8AE88940ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDFBE379429E14A11ULL + 0xB6A2D4CA163F886DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDE8A280EE5A458BFULL + 0xF31297B6FA5DF0F7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9417E84838C1EBA7ULL + 0xBE4575FB6642CE96ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE09D8A355129F9D1ULL + 0xDE7571EDBD819988ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8937674FCCA98865ULL + 0xA169D3E7629340EFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC970CB00173F039FULL + 0xFA0123150E13A8F1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFCC63C00A06AD0FFULL + 0xE3D8B9F86D0C4152ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2496U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5229U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3128U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 5312U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 34U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 37U)) + 14179205183062705133U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 56U)) + 210032324058740920U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 7387115089142500152U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 21U)) + 17583362781238061430U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 4991442849150005943U) + aNonceWordF;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 35U)) + 2891376254689854555U) + aPhaseDOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 51U)) + 10523274382407446239U) + aNonceWordC;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 39U)) + 3861893764676218667U;
            aOrbiterF = (aWandererH + RotL64(aCross, 27U)) + 3366674459852093746U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 42U)) + 5898492634386601145U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 7047353571244768721U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14374108805453186316U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8763667021501226510U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 7694695426430267863U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18261523829316379575U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 650477532238860965U;
            aOrbiterK = RotL64((aOrbiterK * 8291758490821819851U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2162326554604894042U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5776546692501825278U;
            aOrbiterC = RotL64((aOrbiterC * 14911545784585246537U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3501863793638415049U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14853789267425352958U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 10590325397179928739U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15399673014671329743U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12253428583438990426U;
            aOrbiterI = RotL64((aOrbiterI * 12052855472196447849U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13202953937621953839U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7547616636832698398U;
            aOrbiterF = RotL64((aOrbiterF * 9533399972562428073U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15709801946594868318U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12458677982746610971U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6662570874316418993U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6957370791367530127U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10511379961344950861U;
            aOrbiterH = RotL64((aOrbiterH * 15551333099264031337U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16489828646914719181U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6827290294344770680U;
            aOrbiterB = RotL64((aOrbiterB * 6408864925398536651U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3308531598034561099U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10336568208337990458U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5606941634846696657U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14116471880098183908U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14179205183062705133U;
            aOrbiterA = RotL64((aOrbiterA * 8824119255416045191U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 56U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 22U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 22U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aPhaseDWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterC, 50U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6793U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 10909U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6815U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10225U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 56U)) + 12311607308490066301U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 13100864684740679846U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 13697304189274329704U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 41U)) + 9047976902871216732U) + aNonceWordG;
            aOrbiterH = (aWandererH + RotL64(aIngress, 23U)) + 2147897579538537888U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 58U)) + 2072444829390996142U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + 2129307836981020908U) + aNonceWordL;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 10663145333751112064U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 21U)) + 15019844390503785459U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 43U)) + 5460865577557928142U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 19U)) + 15806522559993224197U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6361113778657833389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8306013884615042570U;
            aOrbiterK = RotL64((aOrbiterK * 8234258702656728667U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4038420580499706912U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11908091484457158973U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3964111175645156719U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11133912466611921250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2469227904206936928U;
            aOrbiterH = RotL64((aOrbiterH * 2704438771198001599U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13234017916788297295U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9061117693840451988U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3637440416741459419U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12013423690843812324U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14371779015144617412U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 3359568073302062667U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10044883414565441442U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14334898081890462218U;
            aOrbiterG = RotL64((aOrbiterG * 4878939077928220019U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13788962593988366125U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8377887372059713516U;
            aOrbiterC = RotL64((aOrbiterC * 1925913354197206851U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4584439257847749371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13335592911357756498U;
            aOrbiterE = RotL64((aOrbiterE * 6515028218115896375U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11166747459333977215U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2368465601636093120U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 1929974840976648333U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4538402006569031063U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3397601475441212067U;
            aOrbiterI = RotL64((aOrbiterI * 12043369327112500565U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4804403185062062524U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12311607308490066301U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10281231071618984185U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 40U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterK, 14U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 46U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14852U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11715U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11476U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14083U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 50U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 14U)) + 12849591986267890852U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 8232614804696815750U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 21U)) + 12141567259210877281U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 2928641981037885644U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 980733350554783938U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 2683985177993350746U;
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 14532148403815527355U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 52U)) + 7736296629433884203U) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aCross, 19U)) + 10428437770166310549U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 35U)) + 18327174144859461029U) + aNonceWordI;
            aOrbiterG = (aWandererH + RotL64(aScatter, 27U)) + 6810436935194432002U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12606153309690753435U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17123256945895150555U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9057777759026189541U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 16478485918911194442U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18064460487552100483U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11477276762421684083U;
            aOrbiterD = RotL64((aOrbiterD * 3886501230380184395U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18318375441973295081U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13849305985380030986U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 12962140243967824959U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10240409420338313641U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18360586077779529086U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18196875422391501927U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16801797158622424257U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4950305991208513887U;
            aOrbiterK = RotL64((aOrbiterK * 4437082499761416951U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15790878572843321918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9808781805065559728U;
            aOrbiterB = RotL64((aOrbiterB * 9394280083159162953U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11974996650410830731U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4955004489435232515U;
            aOrbiterH = RotL64((aOrbiterH * 13301966529515483085U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1187569634223338864U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5351017164244226367U;
            aOrbiterC = RotL64((aOrbiterC * 14735674576470803699U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9587142385246940125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16253850371962732943U;
            aOrbiterI = RotL64((aOrbiterI * 3408021872390904463U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14990060157351237661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12849591986267890852U;
            aOrbiterG = RotL64((aOrbiterG * 2158106726261981983U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 26U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aNonceWordF) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 36U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18845U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19493U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18518U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19861U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 43U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 3U)) + 12690502671561165478U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 22U)) + 17519943923428102801U;
            aOrbiterH = (aWandererG + RotL64(aCross, 27U)) + 10705515807975331385U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 16586447272278538179U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 19U)) + 8006560996840971798U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 12928600185788857701U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 34U)) + 14240723153798267172U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + 8636219177994872072U) + aNonceWordD;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 7586790235186467512U) + aNonceWordE;
            aOrbiterB = (aWandererD + RotL64(aScatter, 43U)) + 1103807034179512424U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 41U)) + 7547526530239498693U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8380239679344786397U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5690809173787433519U;
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8390902801141804609U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3507306189192059486U;
            aOrbiterA = RotL64((aOrbiterA * 18336280496510253103U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6190745292098482871U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 8065418693975056902U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 6414621418430102589U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12111755051718111803U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7605877769709909297U;
            aOrbiterD = RotL64((aOrbiterD * 17525248694315944599U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5969794501112646237U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5127559299360591476U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4521563633438853069U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10593847754747739786U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4401750688524310121U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14265829318976633707U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6927893132508779499U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4874009978647014479U;
            aOrbiterB = RotL64((aOrbiterB * 13340466017023540755U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13146693487138744677U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3298472134223595298U;
            aOrbiterC = RotL64((aOrbiterC * 2145005258008477281U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8729305340729268734U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 18347161842033439538U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7952715248988302017U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 166831495912855225U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4943633045563697271U;
            aOrbiterF = RotL64((aOrbiterF * 1809857625425000137U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2460623715340753589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12690502671561165478U;
            aOrbiterE = RotL64((aOrbiterE * 16421139715633515623U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterE, 14U)) + RotL64(aCarry, 27U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 10U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23648U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25014U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26805U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 22441U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 23U)) + 14249093584376402677U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 47U)) + 8756965951816492264U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 19U)) + 11221139480258176330U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 27U)) + 17218894445564194851U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 6U)) + 8064642692524949490U) + aNonceWordJ;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 5822093203710704646U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 39U)) + 3217799620158102238U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 2613757677892120843U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 21U)) + 13647481499551657237U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 44U)) + 3545714196663685016U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 9735422670576621521U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3911046580637583767U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9315984027042049203U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8926367674641729058U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11035347490524961446U;
            aOrbiterF = RotL64((aOrbiterF * 10948288997163592463U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10748158733051120339U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2467801787989056455U;
            aOrbiterJ = RotL64((aOrbiterJ * 12621934274702358977U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9244415080474351390U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8517784887959492079U;
            aOrbiterC = RotL64((aOrbiterC * 17022899813765884147U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8409307332803038455U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11043806021873232950U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8294888329708842989U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17512395828450251457U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16849067939795823992U;
            aOrbiterH = RotL64((aOrbiterH * 9361991804481514337U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17541946638063238056U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11430501673960586718U;
            aOrbiterA = RotL64((aOrbiterA * 15074409630605450091U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 78307505705383302U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4834528975263832983U;
            aOrbiterE = RotL64((aOrbiterE * 17245673681686752861U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9647985402149698269U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6610247710757518931U;
            aOrbiterK = RotL64((aOrbiterK * 8672486173272686859U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 2706696306041774372U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9519896513600816252U;
            aOrbiterI = RotL64((aOrbiterI * 7468605169665549731U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14647351223431646222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14249093584376402677U;
            aOrbiterB = RotL64((aOrbiterB * 8296105266618697281U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterB, 4U));
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 30U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 20U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28629U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30378U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32577U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31010U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 3970829908171131502U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 28U)) + 7040283759419531991U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 21U)) + 11856292169397052901U) + aPhaseDOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 11U)) + 819598588791819022U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 37U)) + 2176451710970866848U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 6454704928613390494U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 11792122387218053841U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 3U)) + 9254780213489752211U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 16591812589999846482U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 53U)) + 1471246223935074832U) + aNonceWordI;
            aOrbiterH = ((aWandererE + RotL64(aCross, 40U)) + 1424843083106386453U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1856469958050891629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6331743690452052712U;
            aOrbiterD = RotL64((aOrbiterD * 15327924647897459645U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10351075711345476487U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9518585245330480185U;
            aOrbiterB = RotL64((aOrbiterB * 3792179827396760391U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17787514620244712033U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14182328067398162557U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 18107337388659070197U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12798088948801072444U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9563215159275202323U;
            aOrbiterK = RotL64((aOrbiterK * 7058145016617349141U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9904919772580498232U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16579777394992143043U;
            aOrbiterG = RotL64((aOrbiterG * 10516761340320196661U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6344049286854588503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3531503618941046788U;
            aOrbiterA = RotL64((aOrbiterA * 10855385899703024105U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11334308840132700377U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11093833870078787770U;
            aOrbiterI = RotL64((aOrbiterI * 16105889714648555755U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3831491136025364271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12505259454860591372U;
            aOrbiterH = RotL64((aOrbiterH * 6135450888433504093U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2210290810330253363U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10786160915224323113U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 799075068398619501U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7791474921127653867U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1046454625851499863U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18040454167287729591U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14636813124839719351U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3970829908171131502U;
            aOrbiterF = RotL64((aOrbiterF * 2737568880005765517U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 36U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 58U)) + aOrbiterA) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordN;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCFE855D6FFA28629ULL + 0xD1FE0BF48F2B2791ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x83FB032A82CADF77ULL + 0xBD6F46C7DABB860FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA5294B2C6B6780E1ULL + 0xD3023CAAD9030DB5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8523FAC1E878B925ULL + 0x8DBB43C1DD6537F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDC054E251230D385ULL + 0xF57A712E058C4B74ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9E375D745AE5BEE9ULL + 0xD815DCAB46527E11ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDD8EA1C6843DC985ULL + 0xA36353F2D5F229BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE97DFB22CE7A1D5DULL + 0xB2F698FEE95E7A03ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB864A90D3482081FULL + 0x9786DDF3BFFD93E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD61F78D117C46B43ULL + 0xF51A69A021FEB61AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD3064CCF92AC3935ULL + 0xA73236D1401B1B61ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCFF89B4DFA35D167ULL + 0xCDCB94F5B19D158EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF91D55F1E1067EDULL + 0x89DBA139F1EEA4E9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCD312C30456D3C25ULL + 0x9A574136388E0801ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDF95461410CCE093ULL + 0xB8C5A506DEAAEED1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA971E5A0342787CFULL + 0x95D3552DA5BEBAEEULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1106U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4770U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1954U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4131U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aScatter, 24U)) + 12615321415808640429U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 41U)) + 15712784676459931207U) + aNonceWordD;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 11013335427004930046U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 8298733856304768806U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 35U)) + 6207732959150824216U;
            aOrbiterF = (aWandererD + RotL64(aCross, 53U)) + 9769864876127544038U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 21U)) + 10782181918651152563U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 5790454015845620939U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 15606578025386733803U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 10U)) + 5522352539991175304U;
            aOrbiterG = ((((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 5993355818572869649U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10864534396947622047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14191181677234981396U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2258570108233924592U;
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8448114811381534603U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2702389315763499817U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6710443836432274393U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17202184076718780200U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 150549910056015002U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 195034681254956335U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4910512055808124967U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4783477997418403079U;
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13842899106208709771U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7930112618036681468U;
            aOrbiterC = RotL64((aOrbiterC * 8609551859830858419U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8790107242863198659U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6882768826643279144U;
            aOrbiterG = RotL64((aOrbiterG * 13745521454063360763U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12136498871759890015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8120456314755584336U;
            aOrbiterH = RotL64((aOrbiterH * 1830725195528043575U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14425711740351183016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15907406009196323049U;
            aOrbiterI = RotL64((aOrbiterI * 8599371693260686839U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4878521420367891861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1184672056055028939U;
            aOrbiterB = RotL64((aOrbiterB * 5963961755367831967U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10126736568567000180U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12615321415808640429U;
            aOrbiterJ = RotL64((aOrbiterJ * 11663715449073755137U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 30U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterD, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 24U)) + aOrbiterG) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8424U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 7449U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7879U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 7123U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 18087125778766689269U;
            aOrbiterI = (aWandererD + RotL64(aCross, 3U)) + 13710545066503235196U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 47U)) + 1701939704736254645U;
            aOrbiterE = ((((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 13U)) + 8064093611384019909U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererG + RotL64(aCross, 27U)) + 16623332751533885431U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 19U)) + 15590129153794910109U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 7413312683079107383U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 14U)) + 4186064478651458810U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 41U)) + 5501191643940735954U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 21U)) + 11064645242200570835U) + aNonceWordL;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + 13825922087298055833U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5944980709887369970U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8181136916070569646U;
            aOrbiterK = RotL64((aOrbiterK * 395183021205661827U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15442336949157292482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11580554435240641337U;
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11240018128174598322U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2027565596050777471U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 18048186560314431815U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16425887196883725233U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16828683527588834095U;
            aOrbiterJ = RotL64((aOrbiterJ * 17746289103235902485U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9923829146479008804U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6669171007279929454U;
            aOrbiterF = RotL64((aOrbiterF * 681823450939955099U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3902430046523165149U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6739998149289590041U;
            aOrbiterC = RotL64((aOrbiterC * 2675037435528416821U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16014401255534234075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14741857638680634564U;
            aOrbiterE = RotL64((aOrbiterE * 8723611021403369393U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5064807861673260054U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 968747317273200299U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 14122304002722582329U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5282686212362051427U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6902253563196129760U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7682808024658992049U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4995580401402368332U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 14949762584793646470U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 3539183342072953803U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2378815735788107402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18087125778766689269U;
            aOrbiterA = RotL64((aOrbiterA * 16799380528404446281U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 36U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 34U)) + aPhaseEWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 26U)) + aOrbiterA) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15355U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14657U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11779U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13749U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 18U)) + 14624277139785904404U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 6966977309498165611U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 41U)) + 205536824352530761U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 16629575265808255692U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 28U)) + 596881340147972746U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 13U)) + 11944412799107412650U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 4615021315668210206U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 8497630055977606216U) + aNonceWordE;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 5U)) + 11131601107309336885U;
            aOrbiterC = (aWandererC + RotL64(aCross, 51U)) + 5935883479805510099U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 57U)) + 15629346719765798174U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5279128339113651273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16778365912440331821U;
            aOrbiterE = RotL64((aOrbiterE * 705421028266789241U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16003052937645491524U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6723226158737614764U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 16690657664909260573U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9785784358981219543U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10055457337292292710U;
            aOrbiterD = RotL64((aOrbiterD * 17919129940751761111U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11779163108592974175U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1177999477942202687U;
            aOrbiterI = RotL64((aOrbiterI * 13475069421684114643U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9190694445141492214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15605342360346353457U;
            aOrbiterG = RotL64((aOrbiterG * 14547769706392595647U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14877565450677523492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1074095623308025684U;
            aOrbiterC = RotL64((aOrbiterC * 7884068939436891093U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12803174154216941583U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8813356463693637033U;
            aOrbiterF = RotL64((aOrbiterF * 4898237214617563167U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6063909634038581414U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15112191502834052566U;
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13926459034757240311U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4324555954703597591U;
            aOrbiterH = RotL64((aOrbiterH * 18068922072149745351U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7183063131331255506U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 18072787091203847052U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12530396154012878153U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10143386327707219710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14624277139785904404U;
            aOrbiterB = RotL64((aOrbiterB * 12100828883424264587U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 39U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 58U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 18U)) + aOrbiterA) + aNonceWordO) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererG, 4U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21674U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((aIndex + 19266U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18853U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 19004U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 19U)) + 15726877954695761686U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 3U)) + 14187652171881943587U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 8420423151313882782U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 30U)) + 14942322692433259283U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 13U)) + 7272331475919796255U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 35U)) + 154504365041805840U) + aPhaseEOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aWandererF + RotL64(aScatter, 21U)) + 17475491222554948786U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 5759181483165339605U) + aNonceWordI;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 5993060214499322845U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 60U)) + 10901786237875941844U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 41U)) + 17135786595614068473U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5208202073886811165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6821452921018900631U;
            aOrbiterG = RotL64((aOrbiterG * 13119330055184115669U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13348064837402206969U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8130283784171430891U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6351113882502502876U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15960622823993072903U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6894708729226455769U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12065058511247133944U;
            aOrbiterB = RotL64((aOrbiterB * 5432601727436935831U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17138279326229372741U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12987698199066890628U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12665716655177320977U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13688833537574196675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4211971980434000618U;
            aOrbiterH = RotL64((aOrbiterH * 1374411763361518851U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10376917117582537592U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 4807742522197923516U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 15257251453302090961U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18038296468177121243U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6879666349379745258U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15819475269715810555U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5193656664432659624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 680899397323387963U;
            aOrbiterE = RotL64((aOrbiterE * 9857476056194621321U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1851929589073547860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13093101559415170218U;
            aOrbiterA = RotL64((aOrbiterA * 13950928576652143737U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13695333301427028607U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15726877954695761686U;
            aOrbiterC = RotL64((aOrbiterC * 960063676226172027U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 20U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aCross, 18U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterC, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26751U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23377U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26727U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23911U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 24U)) + 1364174714924216027U) + aNonceWordO;
            aOrbiterC = (aWandererD + RotL64(aScatter, 41U)) + 13561796874229506613U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 21U)) + 11845572344206238305U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 29U)) + 15762708240326773763U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 35U)) + 1157119665207900473U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 35U)) + 6823546624372055260U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 14465564210523945121U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 10667464548080807531U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 11U)) + 13445737493224316575U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 5U)) + 3009837893785957665U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 37U)) + 2886920524111083752U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10886177449328249656U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15067759884678100433U;
            aOrbiterA = RotL64((aOrbiterA * 5724566815989860041U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18307930462682331536U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8791864377579255801U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 805797468642992351U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5743305867058244964U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16263000753351131717U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17102025528234481273U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1841579177327486899U;
            aOrbiterH = RotL64((aOrbiterH * 3841603385577825265U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2189493507896508972U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18209567010094914374U;
            aOrbiterK = RotL64((aOrbiterK * 3737080408976852351U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6697069234216868330U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 927471474577415372U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10680760991009199309U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13155854301197725408U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1014625081915435892U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 11592754232949990435U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12697209921410914931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11555096613655648647U;
            aOrbiterD = RotL64((aOrbiterD * 4598821388864997089U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9335308231651271690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3160859883353473444U;
            aOrbiterG = RotL64((aOrbiterG * 4753600703924906409U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15681189182414315768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3147692210581710663U;
            aOrbiterC = RotL64((aOrbiterC * 6271949093080510861U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5373388632562432117U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1364174714924216027U;
            aOrbiterJ = RotL64((aOrbiterJ * 4694926665965807945U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterA, 44U)) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 4U)) + aOrbiterF) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererG, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29536U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32089U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31114U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 32637U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 19U)) + 1087148170018530502U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 57U)) + 15530846874509311414U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 16987358651515511212U;
            aOrbiterF = (aWandererG + RotL64(aCross, 34U)) + 12504143181007924259U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 43U)) + 393322117322732418U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 13U)) + 14325937299241887166U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + 9395262907017475742U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 29U)) + 13658510441418344769U;
            aOrbiterG = (aWandererE + RotL64(aCross, 39U)) + 6410754322737005336U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 9257290738538818434U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 7489828960857692286U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4118778591214588387U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16619215231168796563U;
            aOrbiterB = RotL64((aOrbiterB * 14876884956536265157U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11326283811003573430U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1865401866017614604U;
            aOrbiterE = RotL64((aOrbiterE * 8378326058282460073U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 670150121105733604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1499331510641068749U;
            aOrbiterI = RotL64((aOrbiterI * 16623742535540383107U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1116410848560838532U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2696841341036281779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9598953298074904869U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5487352391229549881U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12008243050943342979U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 9087261224804582459U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 552859665927882960U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8426942688524814473U;
            aOrbiterG = RotL64((aOrbiterG * 10916963622695549105U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1613287981244830815U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15592897923468694288U;
            aOrbiterH = RotL64((aOrbiterH * 6600750586743893303U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7629853970631002676U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13778028957247561272U;
            aOrbiterC = RotL64((aOrbiterC * 4063798788229605659U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2932956928094332652U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14855524972646900872U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9546042275547649745U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11071597794692793784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6327727700942234552U;
            aOrbiterA = RotL64((aOrbiterA * 15301120263944789797U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5147576281502110428U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1087148170018530502U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18045084130531645749U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 40U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + aNonceWordB) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + ((RotL64(aIngress, 28U) + RotL64(aOrbiterF, 60U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 20U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordJ;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x82E4B8EE4B94C20DULL + 0xA3B1D8AA27860C8CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x95C50E4CFEBF408FULL + 0xC20E1F341328E75FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE8EA2D4D812BE649ULL + 0xB2EEE890B24D1F04ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE0D3B152E68C2145ULL + 0x9CB5557CDC6A0934ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC21A112A989A22CBULL + 0xDA06785F1010CF06ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBDC5FB97927AF1D1ULL + 0xE00533FA393707F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE7BA0FD9B33324FBULL + 0xB0990098A7496C1AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9E6982234E711BD5ULL + 0xF59228848F65A411ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDBE695B9A3251FD9ULL + 0xB28AFFA007D48805ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD21E32829794FA35ULL + 0xB9611C7FAE430025ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD8D326274F68F22FULL + 0xBD509A283C7962CAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8A2D0EAD22AE0775ULL + 0xC959D7AAA19C91D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA0FAADF7893B6E1BULL + 0xBAA4E546ACFBA53BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDF8A9D44BCE3880DULL + 0x8F9A49E36BA0D07FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x892446DD6F0BF099ULL + 0xD953B5D61C115D53ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCD7BF1AE9269F46FULL + 0xC594785E290750BBULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 908U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 373U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1143U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 4582U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 24U)) + 3236820517816085022U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 35U)) + 741288875914097926U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 27U)) + 8417246926007729580U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 47U)) + 9715717805774537170U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 14360243844821619482U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 10760908100206775334U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 60U)) + 3434641779946167811U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 29U)) + 7885568822756234567U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 3U)) + 3041563437672051294U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 13U)) + 15761355327564963516U) + aNonceWordE;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 1158633562785937421U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9338581575871970653U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14653924713599790081U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3854497592598563309U;
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16286980180327600557U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5092583772591249756U;
            aOrbiterG = RotL64((aOrbiterG * 13955105624639442903U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4288397994175567333U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15584236478994873104U;
            aOrbiterK = RotL64((aOrbiterK * 1860480595862755379U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5557463939827483792U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2659814275753280856U;
            aOrbiterA = RotL64((aOrbiterA * 17702430405693184643U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6941807963525063449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2040598555191211307U;
            aOrbiterB = RotL64((aOrbiterB * 14750544987531722765U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 347572666231116258U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 779304821185302523U;
            aOrbiterJ = RotL64((aOrbiterJ * 14180254150318109855U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10632524582873079742U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9761308771280517212U;
            aOrbiterH = RotL64((aOrbiterH * 13926235411726048921U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2097439707055737964U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2813977930321463948U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14983538728730662603U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6080592019313796689U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5396623654821376409U;
            aOrbiterE = RotL64((aOrbiterE * 15478858835919398677U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8460497459575045342U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3236820517816085022U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5530411244458067093U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 48U));
            aWandererK = aWandererK + (((RotL64(aScatter, 48U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 44U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5622U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 8000U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7129U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 6942U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 8020711767807230555U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 15368693777246341570U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 5117523734225562401U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 6U)) + 13155269151097507808U;
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 9879303753623578272U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererB + RotL64(aCross, 35U)) + 1165799257173794826U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 930641942062732091U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 20U)) + RotL64(aCarry, 35U)) + 11330571332221123153U;
            aOrbiterA = (aWandererK + RotL64(aCross, 39U)) + 2862963158282518899U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 53U)) + 6019186399361476659U) + aNonceWordD;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 37U)) + 1924419843785161958U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12618629043591380461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9334176504266512405U;
            aOrbiterF = RotL64((aOrbiterF * 18239109235362925739U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16829692481030013551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5604784396927022709U;
            aOrbiterH = RotL64((aOrbiterH * 2833893610883508353U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16124030106598549644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16571659812830230677U;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15171089673591843703U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2826755560293849328U;
            aOrbiterK = RotL64((aOrbiterK * 9397017963457655287U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9976785768283589291U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11845100564714691809U;
            aOrbiterA = RotL64((aOrbiterA * 4935139932585319251U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7318560453127859950U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3039196878830506712U;
            aOrbiterE = RotL64((aOrbiterE * 3140508261330698717U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 8850992055588337843U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4219373528176869146U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1310964742529956743U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1341474458715938799U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15937557372891732898U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11437307017920192915U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7512741986101399499U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4304636545688233645U;
            aOrbiterG = RotL64((aOrbiterG * 1948671766238131953U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11460886069492094055U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2019818350627642126U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9802784763505584769U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3190374588085859096U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8020711767807230555U;
            aOrbiterJ = RotL64((aOrbiterJ * 12055760672321414929U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 52U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 22U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 26U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11905U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 16301U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14867U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15590U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 28U)) + 13583136155674166402U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 12830472187484919497U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 18081197909484522509U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 13U)) + 8680634051297891550U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + 13939998767458656823U) + aNonceWordJ;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 57U)) + 1795730579103692594U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + 17369751719734069999U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 39U)) + 224769585901248068U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 21U)) + 4133547085925268180U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 26U)) + RotL64(aCarry, 35U)) + 7022512056309567391U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 10319484359046945495U) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10483878349412282069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6481381149199985736U;
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13721077228796934509U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9704818014314175007U;
            aOrbiterK = RotL64((aOrbiterK * 760445624027740287U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6253040047758584339U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16890211690273641226U;
            aOrbiterE = RotL64((aOrbiterE * 5622534399866057841U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6216227831265032436U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2023609047004658739U;
            aOrbiterH = RotL64((aOrbiterH * 3252332895698310147U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9201669637050388263U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5106927540934338576U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6368134569042291431U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10080368957861445998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10784789383436485808U;
            aOrbiterB = RotL64((aOrbiterB * 3794918350254445939U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15426339824951793026U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17637144549368340331U;
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9941300382181962134U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8118046374121322097U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8481945819050983127U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5138086185042567633U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7279942739248982986U;
            aOrbiterJ = RotL64((aOrbiterJ * 12911998308338410917U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12135610639038562853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12945353426409788798U;
            aOrbiterA = RotL64((aOrbiterA * 7434977715954413699U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7534876598022096222U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13583136155674166402U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8194058098043157015U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 34U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterD, 26U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18436U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21330U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21675U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 16716U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 47U)) + 5160910997561396461U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 26U)) + 14920764751058512062U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 43U)) + 6080952401749660022U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 17667234330526298627U) + aNonceWordB;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 760630072638686756U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 39U)) + 3504157162816997476U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 9489022223422585882U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 37U)) + 1149898536879968964U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 23U)) + 10492284328940025310U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 30U)) + 13213275606286399312U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 21U)) + 10557118912847180413U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15618980209023994776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5268600749854045564U;
            aOrbiterA = RotL64((aOrbiterA * 3849660559223919613U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8011552687609649990U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3148133096349525066U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5245156554959620007U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12032847944237867285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14999005703490824673U;
            aOrbiterE = RotL64((aOrbiterE * 6631584955208646049U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5426735969392906710U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3593177531650386729U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12997284886192717043U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1701444719333347373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15928731228196894960U;
            aOrbiterF = RotL64((aOrbiterF * 1919318226904213433U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5960179456039157036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5716434224061596483U;
            aOrbiterH = RotL64((aOrbiterH * 3731976564761202801U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2136841536293340279U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12969550408652728526U;
            aOrbiterC = RotL64((aOrbiterC * 7612191387451455137U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3641997570461447114U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4677572491523684525U;
            aOrbiterJ = RotL64((aOrbiterJ * 2730358077882211651U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2741372094325164504U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4998631511811832690U;
            aOrbiterK = RotL64((aOrbiterK * 10619395395977372695U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 6260464862798783617U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16489087874167346533U;
            aOrbiterD = RotL64((aOrbiterD * 11278053967185244867U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7043760915859224327U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5160910997561396461U;
            aOrbiterB = RotL64((aOrbiterB * 15260149870590431675U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 40U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 30U)) + aOrbiterJ) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterA, 50U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23590U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27180U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23789U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 24717U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 28U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 8604208734152026945U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 56U)) + 1374329953253889829U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 5779278910548228339U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 23U)) + 17670451230882805140U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 43U)) + 8193848740764866860U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 19U)) + 15801168428145650104U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 14U)) + 2584718176087499066U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 47U)) + 14950366247822737997U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 11U)) + 9779293225265670135U) + aNonceWordK;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 8688968319288372383U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 13665723186950342601U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9395428688359973510U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2152719218018108418U;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1350324137411377992U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8729317951386057921U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6008790836417785083U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6317310451893678411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10175620379041384281U;
            aOrbiterB = RotL64((aOrbiterB * 14079679617394330781U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1203082119358827708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 523869107818193101U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 4629501113595689157U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4028324959540432983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15447631947468213912U;
            aOrbiterK = RotL64((aOrbiterK * 6037306615787729185U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14225888694733041031U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11925000696281947629U;
            aOrbiterC = RotL64((aOrbiterC * 4337022940520411253U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15015531024930608745U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16752579225076943550U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15551083683579981439U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2432733494869267901U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10103430321388601485U;
            aOrbiterH = RotL64((aOrbiterH * 18372919379972432569U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15943360147468638325U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9782703760233558733U;
            aOrbiterI = RotL64((aOrbiterI * 685056980418243879U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18345087852012669037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8897505040792027675U;
            aOrbiterE = RotL64((aOrbiterE * 14333687539092412967U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7402581293947129667U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8604208734152026945U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 9965525485538037673U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterD, 46U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 12U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30212U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 32281U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29957U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27520U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 20U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 10812151398716051703U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 18202551453336003710U;
            aOrbiterD = (aWandererE + RotL64(aCross, 58U)) + 9434410809101973752U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 37U)) + 12955829998028534045U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 47U)) + 12271740641929640181U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 14009351527014534752U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 18U)) + 4316296955679133450U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 16473324966997442872U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 29U)) + 15735123324965019802U) + aNonceWordH;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 17656375090484080236U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 35U)) + 16066325053456055298U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12908968778503516903U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12761433987676836197U;
            aOrbiterD = RotL64((aOrbiterD * 1023329467480907925U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12737513138040664509U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14535795767570998392U;
            aOrbiterJ = RotL64((aOrbiterJ * 15560519667062222269U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14370908061811284364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7001358781208669795U;
            aOrbiterB = RotL64((aOrbiterB * 11641248025734015835U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7298578161120090849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10498302152357484629U;
            aOrbiterE = RotL64((aOrbiterE * 13144110412179037175U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11447343228638006767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18284143620422655675U;
            aOrbiterK = RotL64((aOrbiterK * 572862190073605651U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 5918253208127360199U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3910541329178205943U;
            aOrbiterI = RotL64((aOrbiterI * 4550654545328228103U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10357053096941367910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5610891501128498748U;
            aOrbiterA = RotL64((aOrbiterA * 8676370811772047449U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9049881176058575811U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6307599924966452216U;
            aOrbiterC = RotL64((aOrbiterC * 5551444450572055895U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17109966783467892046U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11563095828344462249U;
            aOrbiterF = RotL64((aOrbiterF * 15463753739272001875U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3739147427725509014U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5324449517615050698U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5926079615575226853U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5706251076252597592U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10812151398716051703U;
            aOrbiterG = RotL64((aOrbiterG * 5666491216813197045U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 40U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 10U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aNonceWordL) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 60U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFA118EF4AB63C40FULL + 0xE658461E3AA0BEDCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAA16B2113A4A4463ULL + 0xBB678B55660B1EA7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF0244D9F1BA57313ULL + 0xF54D88664B8D04DBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB86F9141EB198B73ULL + 0xB02230709BC93FB1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEDE3D2B90750F0FDULL + 0xC3D3D878E54296EEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFEEA09E87DC3AEADULL + 0x8E567391D0A049EBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE445E573ACB75D49ULL + 0x8F7FB1BBF259A4C3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x88181F5F6FAE6425ULL + 0xCE5D506AEF458CAAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEDD10E9AF7BF7423ULL + 0xA724446F20149DC8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB2554F9FB21348A7ULL + 0xBA907AB0628B562BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF167CA7A8152022FULL + 0xFDB361987377BA46ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEBA4086D65BD758DULL + 0x8AD1DB7FC0072961ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x87852DFEB2C469F9ULL + 0xCFDD5D42DB037FCCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE08A64CAE7D9C06DULL + 0xF2D7710EB16F77B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9656617AD6A68453ULL + 0xB73441A67C914EF2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBB044A77A75B8E03ULL + 0xC8CAB6D4F88412A3ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2660U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 5415U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3648U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1167U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 24U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 37U)) + 13915875634607599122U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 1695770381382411673U) + aNonceWordN;
            aOrbiterB = (aWandererF + RotL64(aScatter, 53U)) + 3709105579778295511U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 27U)) + 7673376335333251804U;
            aOrbiterK = (aWandererG + RotL64(aCross, 3U)) + 8814147709738503518U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 34U)) + 13451412605350381172U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 6447870234069609538U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 13419487997946496825U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 23U)) + 5478309847615220345U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aIngress, 19U)) + 3635184969215610049U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 56U)) + 12527903812035294828U) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1684685110885338814U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12860354576326835090U;
            aOrbiterB = RotL64((aOrbiterB * 12743745087733307255U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9081823570147481835U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14369321778210049109U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17865953349448767035U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11518132079084873250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11893535026126957389U;
            aOrbiterI = RotL64((aOrbiterI * 15751374986135615095U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7084079180579206226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2999676609847603277U;
            aOrbiterE = RotL64((aOrbiterE * 14602698397511266403U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17683445810614029153U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11576460512964896969U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5243651036457051155U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13429800604736567949U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14661785761747367546U;
            aOrbiterD = RotL64((aOrbiterD * 4765843989277333421U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12837164345582888950U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6222666313184669392U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 17402483466567712319U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5358647039491079457U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12459911673401497180U;
            aOrbiterF = RotL64((aOrbiterF * 13605465035256188065U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3333017644772803587U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15501587702102554928U;
            aOrbiterK = RotL64((aOrbiterK * 4921693371641768339U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8492287653837766613U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3432736785678875404U;
            aOrbiterC = RotL64((aOrbiterC * 7326419883291516513U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2841486107704281869U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13915875634607599122U;
            aOrbiterG = RotL64((aOrbiterG * 707861617246345083U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterI, 6U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 60U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10342U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((aIndex + 5590U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5590U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 10078U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 41U)) + 12029393034357490020U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 28U)) + 4526754731580694987U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 5U)) + 17060419646421271853U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 4128488893837059683U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 12706894827547160110U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 12506324593645825056U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 19U)) + 12581344490649250025U) + aNonceWordK;
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 14357032418199130132U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 58U)) + 15341977701796331249U;
            aOrbiterD = (aWandererD + RotL64(aCross, 39U)) + 7086602307544733241U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 21U)) + 12398300065276832486U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2499745046076601988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7249361592814001829U;
            aOrbiterI = RotL64((aOrbiterI * 14597139848072319685U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3254456186337366437U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3472973415969046680U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14583566953969168353U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7905718972111691591U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15941413652144021522U;
            aOrbiterE = RotL64((aOrbiterE * 3473779492962783565U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10583964125960308762U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13659925272340853715U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16708294803316630743U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9487054537489454887U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13287757570441887517U;
            aOrbiterG = RotL64((aOrbiterG * 17351439045329892107U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15279245465808571942U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12424999114621745879U;
            aOrbiterF = RotL64((aOrbiterF * 2274918760256527137U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13915392738892970475U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13797668053788805126U;
            aOrbiterH = RotL64((aOrbiterH * 13752161103680525317U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14344766585550401077U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13727554194373146727U;
            aOrbiterK = RotL64((aOrbiterK * 17164450431362670223U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1332966642432651232U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 938583742533681467U;
            aOrbiterC = RotL64((aOrbiterC * 13323340043936037549U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5659239372701978244U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8501778564909302938U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15629932660749672503U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1698500835332753591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12029393034357490020U;
            aOrbiterJ = RotL64((aOrbiterJ * 18176507271635640153U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 42U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 50U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 56U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11166U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 14180U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14596U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((aIndex + 13925U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 7632760812370906911U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 39U)) + 6007174525479723089U) + aNonceWordF;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 5U)) + 3362829642521821048U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 43U)) + 18009548556107978286U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 17880909432272697327U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 53U)) + 15961567935420752568U) + aNonceWordM;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 51U)) + 10136559064656837921U) + aPhaseFOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 17622019364405410277U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 47U)) + 6927494824421416306U;
            aOrbiterF = (aWandererH + RotL64(aCross, 57U)) + 7125170407794874847U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 14U)) + 12342273503071032250U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14997696377476124836U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14874498694181230698U;
            aOrbiterE = RotL64((aOrbiterE * 4026127545746010937U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2549397729130885686U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4217995818662767955U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4706089044415442525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17983900172670031015U;
            aOrbiterB = RotL64((aOrbiterB * 541552737180932879U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1904937798143929988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10620877287033139483U;
            aOrbiterD = RotL64((aOrbiterD * 16711012562024287213U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15681091173163181525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2655543246639000084U;
            aOrbiterK = RotL64((aOrbiterK * 16686375598149755947U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2647895110857289213U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5581609212017175954U;
            aOrbiterF = RotL64((aOrbiterF * 15330263616699031311U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13609076329627787987U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6244266279516622070U;
            aOrbiterH = RotL64((aOrbiterH * 12488345779236971095U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5289624364508923581U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16351476803965903112U;
            aOrbiterI = RotL64((aOrbiterI * 9012522724650442597U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2731198704224650506U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4177455951984414332U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2567165277406175517U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3031687737578718714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4866790771642413883U;
            aOrbiterC = RotL64((aOrbiterC * 1139524449666360541U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12903299652398385014U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 7632760812370906911U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 7924544687662448385U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 46U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterF, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18179U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21213U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20592U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17960U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 5573188770530340913U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 5U)) + 1431772230889897111U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 48U)) + 4809192776429682319U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 23U)) + 5576603692574369341U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 2720143226007220386U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 19U)) + 17220328778565331629U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + 9629485808442089423U) + aNonceWordP;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 29U)) + 1136998437010390983U;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 11893390497814523841U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 27U)) + 1764986431917532370U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 35U)) + 1741014798007010376U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12221368453236547044U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7694538641172350430U;
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17472344518811560603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3308740700728172984U;
            aOrbiterH = RotL64((aOrbiterH * 15290400462887712083U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9535358833412446771U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterI = RotL64((aOrbiterI * 17405609148475445743U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14850451970047190039U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11932493299452443256U;
            aOrbiterK = RotL64((aOrbiterK * 7964808728820467795U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5972619895614731870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17174497535809891690U;
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 17412894714378898351U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14675615208706549810U;
            aOrbiterE = RotL64((aOrbiterE * 7864845089606499769U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16116792108013658523U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9702262005960966336U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 970452849653781703U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17337264966818542841U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7004462033775827275U;
            aOrbiterG = RotL64((aOrbiterG * 11943575980344402681U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17499850384482055438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1839357713256560566U;
            aOrbiterC = RotL64((aOrbiterC * 12943750650487416281U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8144238113917577524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 888195876227325908U;
            aOrbiterF = RotL64((aOrbiterF * 7941506708630993709U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5081763359501717653U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5573188770530340913U;
            aOrbiterJ = RotL64((aOrbiterJ * 9699901099898698965U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterG, 42U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 34U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22186U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 22774U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23611U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26389U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 48U)) + 3255291173184001106U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 19U)) + 15308468160116255528U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + 18186972408589866656U) + aNonceWordA;
            aOrbiterH = (aWandererD + RotL64(aCross, 11U)) + 4439324265978331914U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 39U)) + 13099263173016322486U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 7041561081767500660U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 6196422612687812971U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 37U)) + 7664260932541281413U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 57U)) + 17802347823020441056U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 21U)) + 4253107484061190446U;
            aOrbiterI = ((((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 13799496534030645312U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14252892847595951926U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5663527578664291422U;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11148755959699137661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17036900929333594592U;
            aOrbiterG = RotL64((aOrbiterG * 16041243617369003291U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2403828181385259549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17813580350434928194U;
            aOrbiterE = RotL64((aOrbiterE * 13666780980793857831U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 5623611126885414523U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10602620906929686163U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18015916257203385982U;
            aOrbiterF = RotL64((aOrbiterF * 10684090189688871993U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13592915735376305773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13995866908043417505U;
            aOrbiterH = RotL64((aOrbiterH * 3802175869395887331U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8200465989447697618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9866671660800629464U;
            aOrbiterK = RotL64((aOrbiterK * 2138851839905326265U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11557528777230608777U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 131060617338185060U;
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13404720733342982167U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13128574378042136042U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 5805270317312187011U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15879295432652112238U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9433361543323748909U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3592390041363796221U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6262775775981534941U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3255291173184001106U;
            aOrbiterA = RotL64((aOrbiterA * 2748492753337241005U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterD, 54U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterA, 58U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27454U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 29912U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30398U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28904U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 16802219662864902427U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 5U)) + 14332033461409490629U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererG + RotL64(aIngress, 60U)) + 8781794298640286845U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 29U)) + 8459933908074937264U;
            aOrbiterK = (aWandererA + RotL64(aCross, 37U)) + 1883580287986004426U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 17500258188004626118U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + 7934811305150872870U) + aNonceWordH;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 6380363892361098905U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 12623079132626676910U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 22U)) + 10455208121949202703U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 27U)) + 8805532707916767629U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9161544391400377699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3501434325829663268U;
            aOrbiterH = RotL64((aOrbiterH * 7933545151293799637U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 651783304096081996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 441505031509930622U;
            aOrbiterK = RotL64((aOrbiterK * 8045355432310956143U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1771159983581326424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15227946417377695989U;
            aOrbiterG = RotL64((aOrbiterG * 1563141188972797601U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4153717524193279095U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4404521756523902829U;
            aOrbiterD = RotL64((aOrbiterD * 1410342912973206203U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6231945075461813285U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3864780227164426690U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18031353247480673617U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1509699687948576558U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17316114302489411191U;
            aOrbiterA = RotL64((aOrbiterA * 15490661284980281585U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2250572827340157410U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6403966113144372915U;
            aOrbiterC = RotL64((aOrbiterC * 726441947009132383U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2329903609147403156U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2486330017319455238U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17427461345935191757U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9333421733051210144U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14779925626161889533U;
            aOrbiterE = RotL64((aOrbiterE * 9120486933147706541U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4343688173541745311U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12686722305368397686U;
            aOrbiterB = RotL64((aOrbiterB * 17484250022537912537U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3745163111502795473U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16802219662864902427U;
            aOrbiterJ = RotL64((aOrbiterJ * 4343730534036919417U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 34U));
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterF, 27U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 24U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 66U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 6965U)) & W_KEY1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 521U)) & W_KEY1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2846U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 2168513956284366370U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 10290361969974613111U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 15673836275828498050U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 43U)) + 16600540024145812236U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 51U)) + 9428052101528111892U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 37U)) + 12763657928312763377U;
            aOrbiterD = (aWandererD + RotL64(aCross, 23U)) + 10751286982008662485U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 47U)) + 1708230173038057979U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 56U)) + 4011389705422783816U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11704428328093077714U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterG = RotL64((aOrbiterG * 6374289210096410907U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1870865272102705804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3574214263751923179U;
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 984611970726966186U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15207945449947643672U;
            aOrbiterH = RotL64((aOrbiterH * 9539470161576639981U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4181398506373973169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15222345431506025949U;
            aOrbiterE = RotL64((aOrbiterE * 6925143692628659467U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15023513452326240962U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14965669361708810699U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7985755518735406360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 225592097619240187U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3659537916566939383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17043668033610689611U;
            aOrbiterD = RotL64((aOrbiterD * 10797634709118100773U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10217321522161675848U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8013663869536146842U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2293233079384777175U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13762445330867496042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2692400019659269106U;
            aOrbiterB = RotL64((aOrbiterB * 167704184292219399U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 46U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 42U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + aPhaseCWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 56U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13746U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 8445U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15552U)) & W_KEY1], 22U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10429U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 380024772508948442U;
            aOrbiterC = (aWandererI + RotL64(aCross, 46U)) + 7649029098162567210U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 5329304598870421851U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 12306118665045151326U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 960751560457324256U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 51U)) + 3244070254386191876U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 15733408571609521746U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 42U)) + 17623448932647018544U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 37U)) + 8787759896149035829U) + aPhaseCOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14741681792348288162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8801731213568307302U;
            aOrbiterI = RotL64((aOrbiterI * 12127126999570616489U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9872248187499779222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15407371518644528235U;
            aOrbiterB = RotL64((aOrbiterB * 1245102406469471673U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4242060317152943062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9942784962409917541U;
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7296348796484458631U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15061417216070157797U;
            aOrbiterG = RotL64((aOrbiterG * 10349554676953256231U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3233185810644297433U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9241229457641024287U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2728237515724597517U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8464051359381554575U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3307872165699029375U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4859663401033023433U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5482617843966711997U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4442149210462943872U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8979352218576515647U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10591636597580147381U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14925122230279312217U;
            aOrbiterD = RotL64((aOrbiterD * 15038171961638724013U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9772367878232735350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15800661165607190092U;
            aOrbiterC = RotL64((aOrbiterC * 10493976952980533589U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 14U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17083U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 21986U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20612U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 17892U)) & W_KEY1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 16160838483846078448U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 57U)) + 15404960896190227946U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 3U)) + 16904160594024977199U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + 17790460246821031802U) + aPhaseCOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 16395168254086971959U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + 7484373204039901786U) + aPhaseCOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 40U)) + RotL64(aCarry, 37U)) + 18026814691322913510U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 19U)) + 15244817793136966450U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 13U)) + 5795491730356335666U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3163873518027801504U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2690791759507349172U;
            aOrbiterA = RotL64((aOrbiterA * 16677948635136515083U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17898067251167087906U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8028010015006604239U;
            aOrbiterD = RotL64((aOrbiterD * 5601629670521300241U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7304739457289910555U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6476837815096530043U;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14242499233467960602U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17305645693017634630U;
            aOrbiterJ = RotL64((aOrbiterJ * 14442976693206929569U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9772864059444171908U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7897200728282156408U;
            aOrbiterF = RotL64((aOrbiterF * 816306719390807411U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4890999319172950996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8165132649356094963U;
            aOrbiterB = RotL64((aOrbiterB * 17297706071263690189U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9342923520083533265U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7213639583505088067U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1349251979649428909U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4079475132684197272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3350998022472827283U;
            aOrbiterG = RotL64((aOrbiterG * 948841791460066265U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2479140576609216238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7703147534931674972U;
            aOrbiterI = RotL64((aOrbiterI * 11419116495223970801U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 14U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterF, 60U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27310U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25003U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26949U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29645U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 19U)) + (RotL64(aIngress, 34U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 21U)) + 17936518874386450467U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 13722737841589910344U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 11774969167948715796U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 48U)) + 3640101505680493777U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 3U)) + 1369495382725650822U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 29U)) + 11827310354654653345U) + aPhaseCOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 186037671377175394U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 39U)) + 11428829344234627340U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 56U)) + 2275016369870029068U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15471646673734798328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12172082573115640145U;
            aOrbiterF = RotL64((aOrbiterF * 9629417882787847753U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6626736341348283154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12220614992483863623U;
            aOrbiterJ = RotL64((aOrbiterJ * 8137086205714097487U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13157102324253760215U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterD = RotL64((aOrbiterD * 5060677690991506895U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11007575246013796426U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11721585930088637162U;
            aOrbiterA = RotL64((aOrbiterA * 15009627907125738519U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5720789204450196217U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3094696226821431648U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4412033981712165541U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14675830108100986773U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9444071495289719645U;
            aOrbiterE = RotL64((aOrbiterE * 10983136361953366557U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5106753847015199956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7585421898593510010U;
            aOrbiterH = RotL64((aOrbiterH * 140996914192351011U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11746948407655524690U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16336323220286344483U;
            aOrbiterB = RotL64((aOrbiterB * 6590417628835864497U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8030445186765781136U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 276034088015165891U;
            aOrbiterG = RotL64((aOrbiterG * 7626025612710225099U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 30U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 18U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 4U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6764U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1987U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4032U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4997U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 4739486756133131180U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 16089707555501328184U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 43U)) + 15310047330238536453U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 7901411596386834955U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 29U)) + 4357555491060982163U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15667085602825720102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8520635334382269253U;
            aOrbiterA = RotL64((aOrbiterA * 7348648918661047791U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1772509779231068315U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15336170957886025677U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10996880551392077399U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8628770833489469980U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15469234024247246228U;
            aOrbiterG = RotL64((aOrbiterG * 8905266995119987947U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10796430900884288328U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10660110397012853289U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9140007610912037461U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11202284258711214794U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17509491802893182994U;
            aOrbiterD = RotL64((aOrbiterD * 9329107599972703671U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 22U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16378U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 13664U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15144U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 10611U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 20U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 16424657151168221875U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 23U)) + 17150123681886380361U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 37U)) + 16041993588694572757U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 9871185846434828537U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 3U)) + 11227236398354430757U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5399325217402192631U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9248828789282890454U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6733832755349139621U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9041370494203701062U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14944424084524970764U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10283363059424655079U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5481938174456671041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14783648629543752715U;
            aOrbiterI = RotL64((aOrbiterI * 7260164783191886395U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12355573914530445723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9863991559011968318U;
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16149688605937250965U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterC = RotL64((aOrbiterC * 12199934305374582599U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 24U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 21U)) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20143U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 19250U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21106U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20771U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 6163290588946759209U) + aPhaseDOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 7342672468560105447U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 11U)) + 11574563167017282321U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 2254820206194758964U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 30U)) + 1469783447473099498U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14174828900676165088U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16277954291890598132U;
            aOrbiterD = RotL64((aOrbiterD * 4608888834164373691U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14845750668693136766U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 150099699692047766U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7644895634421086357U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1200784917165131703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9469982764806754302U;
            aOrbiterJ = RotL64((aOrbiterJ * 17851969334511301943U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10956702761701710182U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7915506894975487807U;
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17335794183733623213U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 557028996286989506U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 58U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27530U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28113U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28298U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 24918U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 27U)) + 12632404972795375757U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 57U)) + 5351879979055988456U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 3597737727467443413U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 2830846754917852318U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 47U)) + 17311925960294518018U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2083584640523695383U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15049343611387010158U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5567816356477420399U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6443050378205811147U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6021965178697344070U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6054064448935006741U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5080289878758029976U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 576927745306972983U;
            aOrbiterA = RotL64((aOrbiterA * 16008958833683246115U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4728489691382690859U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6184355840165758855U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1515043910404156423U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11220539885798595450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11091438724966718214U;
            aOrbiterD = RotL64((aOrbiterD * 8225347114759391961U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterA, 12U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3587U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5749U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4026U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3587U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 35U)) + 3339283916456813609U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 11339086426180649584U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 16819191669329316585U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 29U)) + 8361916937762630725U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 5U)) + 18031328374429899857U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 18261756894092897276U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 41U)) + 4250319792907645666U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1492411503643460886U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17369549067879344180U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2947354306696216579U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7301713524358676722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18205555540941493267U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9209505304067579944U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8811497120829041188U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14707301680850257294U;
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10080595991787801029U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6822892187784299166U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7417016898027778287U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10860U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 10609U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12682U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 8508U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 50U)) + RotL64(aCarry, 19U)) + 5697928251815176134U;
            aOrbiterB = (aWandererF + RotL64(aCross, 57U)) + 337587740689259575U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 4927686903263973950U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 43U)) + 3742409032569801033U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 11U)) + 1608092659172197650U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 15848744267145717509U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 27U)) + 15300174177963339253U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14162868453323648628U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12020167069983729869U;
            aOrbiterJ = RotL64((aOrbiterJ * 2071080217680099017U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16259538291658723956U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8516686212464112245U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4731296903548893627U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3722184575520553132U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5663609293306386784U;
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15265344442454471986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3050323350098829515U;
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1093356813820599238U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15167726103772238440U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15170797965325981472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14710892030473425181U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 48U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18061U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17739U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17755U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20426U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aScatter, 35U)) + 10881271196314989997U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 6406461249988567558U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 41U)) + 17255067918280095959U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 16690850682497718411U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 5576201059361086866U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 12U)) + 11991259685693687554U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 5U)) + 14652535244217836909U) + aPhaseEOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1701789037170782122U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 953429054903473833U;
            aOrbiterJ = RotL64((aOrbiterJ * 13482379459700651427U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12064513610469714211U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7993881398822002424U;
            aOrbiterB = RotL64((aOrbiterB * 11572884842788918377U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14421313768013320050U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11112386845630998889U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11771526352030371669U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17069630896535699015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3308240081138623373U;
            aOrbiterK = RotL64((aOrbiterK * 10449509484417835159U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17615529807112933619U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11782807146851563541U;
            aOrbiterF = RotL64((aOrbiterF * 12992075832343669221U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14401645829607611983U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6736397344219993532U;
            aOrbiterI = RotL64((aOrbiterI * 1667287547938175641U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6446974060524700550U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7840991992443308254U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6891023544882740107U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 36U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32695U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30835U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30446U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31547U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 29U)) + 10915618884692072446U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12634922308499254909U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 6533934734564499389U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 37U)) + 6744203303756105181U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 60U)) + 13086782386652045658U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 5693840533331397822U;
            aOrbiterK = (aWandererC + RotL64(aCross, 3U)) + 1803663542535024611U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3597219300593287708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1429753448204448904U;
            aOrbiterD = RotL64((aOrbiterD * 10927459251773273143U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17229017825587322715U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1137574712801062932U;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2401991077004083378U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1332473247826139292U;
            aOrbiterB = RotL64((aOrbiterB * 15029831858261506447U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11730946340796899885U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15319163439700390962U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1349242001887975499U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4744141870145159917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6067132201862688684U;
            aOrbiterH = RotL64((aOrbiterH * 6046100687757836027U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14991509179286371800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4342608825699398682U;
            aOrbiterJ = RotL64((aOrbiterJ * 10240526103933275875U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3727521409410742075U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3302027219498304367U;
            aOrbiterK = RotL64((aOrbiterK * 12153634588200479559U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 4U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 41U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_BasketBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3484U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 7335U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4259U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 7241U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 701291026547470433U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 17283292650462111643U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 29U)) + 9969124091931303406U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 889176772718046988U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 60U)) + 6054541844643748084U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14703226235143028132U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7977975878522921062U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9030855800028448469U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16894322614172266274U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12160451749345900570U;
            aOrbiterB = RotL64((aOrbiterB * 18055355572903901749U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10870847008043897470U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8159920947172520247U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4833194641611011805U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2440099120969517932U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2428396147731468007U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9363073341539598441U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2213226274394673479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7079731443427765333U;
            aOrbiterC = RotL64((aOrbiterC * 16918930776877030559U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 42U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 14U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 4U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8895U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 11816U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16020U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 14839U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + 15045917390223766480U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 21U)) + 10763054007033668758U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 13190170142593666607U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 9657025731441167065U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 12U)) + RotL64(aCarry, 37U)) + 11433367178975954211U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17904920143996810366U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3244383020512113283U;
            aOrbiterK = RotL64((aOrbiterK * 552521443123433353U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6538815775171139091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7195368312757976343U;
            aOrbiterG = RotL64((aOrbiterG * 10515679176134176565U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 18134430713910279374U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6571776588427107976U;
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11830778129647517758U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9793702760907767365U;
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2287235876793192036U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8951959188326141794U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9968356718110753845U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 4U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 39U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21951U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17223U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23601U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 20660U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 42U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 15652862298542575895U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 16925323928418184554U;
            aOrbiterF = (aWandererC + RotL64(aCross, 51U)) + 4413861484961668394U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 2215946422098155969U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 29U)) + 14975185533513111110U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9711613814905834552U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13154957291850149471U;
            aOrbiterF = RotL64((aOrbiterF * 17049677190793844477U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5058313016418534840U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15011423472941211620U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6125316151731105673U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2030053257469580168U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 150530795186791193U;
            aOrbiterK = RotL64((aOrbiterK * 11106050063717096073U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10878237472104183427U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11724672539469573109U;
            aOrbiterG = RotL64((aOrbiterG * 16158741837357985395U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9589700906445846956U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1367381624958248949U;
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterK, 40U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29535U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25838U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30218U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 30697U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 77518479758428414U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 4832061802166300011U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 11695291171006574112U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 7467412817843260094U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + 17801484124471154757U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5555455638503958639U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5669470540733721606U;
            aOrbiterA = RotL64((aOrbiterA * 17219613748084498879U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3042388456327784163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2236734925228156691U;
            aOrbiterK = RotL64((aOrbiterK * 10076582424701705531U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14459720401528685450U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4814967631216658856U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18288097536171386643U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16950679344449075945U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6262238639302011050U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3522256359074996724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterD = RotL64((aOrbiterD * 6787771338063891989U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 28U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2134U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 1935U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 931U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7485U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 26U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 6916817163240024692U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 40U)) + RotL64(aCarry, 23U)) + 14554930751292077817U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 53U)) + 1098305064484336101U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 21U)) + 12192821172420471527U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 2435134991707318845U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1896745368738512624U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1114996424222923873U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6248754732325773087U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9839135798371512656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8037967239603177043U;
            aOrbiterH = RotL64((aOrbiterH * 7848951103759663025U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15185468738487237432U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4912098316394854543U;
            aOrbiterF = RotL64((aOrbiterF * 3072785550384399929U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13142688607850380888U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4507379759608945839U;
            aOrbiterB = RotL64((aOrbiterB * 2989332387754215967U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7299006009652289342U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5390655277207053627U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10973744708856143715U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 58U)) + aOrbiterF) + aPhaseGWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16366U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((aIndex + 15233U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9417U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 11677U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 39U)) + (RotL64(aCross, 60U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 6733949564325516029U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 41U)) + 7304098437143918796U;
            aOrbiterG = (aWandererB + RotL64(aCross, 29U)) + 3923949518391777800U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 14243591003388927124U) + aPhaseGOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 43U)) + 18329498724605410406U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13118172167747037249U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5272025143849174212U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9935990954321437743U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16075917179214318424U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15263590648674658399U;
            aOrbiterC = RotL64((aOrbiterC * 9918239923411740337U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13730046728289525921U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7703141464499623408U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5886009900621521987U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1382279753822135359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2973369221699098292U;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11578274119583013219U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3419411247737896674U;
            aOrbiterK = RotL64((aOrbiterK * 17814942652262802991U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 38U) + aOrbiterC) + RotL64(aOrbiterA, 44U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22711U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 20876U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18506U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21420U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 12615321415808640429U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 43U)) + 15712784676459931207U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 11013335427004930046U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 37U)) + 8298733856304768806U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 6207732959150824216U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9769864876127544038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10782181918651152563U;
            aOrbiterB = RotL64((aOrbiterB * 16814396040248716483U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5790454015845620939U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15606578025386733803U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7079287329365566355U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5522352539991175304U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5993355818572869649U;
            aOrbiterD = RotL64((aOrbiterD * 15221467311057431139U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10864534396947622047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14191181677234981396U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2258570108233924592U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 22U)) + aOrbiterD) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28940U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27587U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26144U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 29300U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 47U)) + 15036852811491820366U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 305637140752898475U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 11948631574496129610U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 3U)) + 5321623592482991426U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 35U)) + 4075270159062690728U) + aPhaseGOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15111580500356908928U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7244150695504160363U;
            aOrbiterE = RotL64((aOrbiterE * 2445733898697939969U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5131563519577488862U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5881954992088651371U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12780935808751507998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12599159643925470226U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17690046932587062701U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9466589929741834066U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6093158735705189789U;
            aOrbiterI = RotL64((aOrbiterI * 7453778295800853653U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17461243886150519249U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15456408913739900718U;
            aOrbiterK = RotL64((aOrbiterK * 16093292401746174671U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4123U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7744U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6783U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 718U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 7632760812370906911U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 6007174525479723089U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 36U)) + 3362829642521821048U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 18009548556107978286U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 21U)) + 17880909432272697327U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15961567935420752568U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10136559064656837921U;
            aOrbiterK = RotL64((aOrbiterK * 14473810261421912849U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17622019364405410277U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6927494824421416306U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2686290883767829973U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7125170407794874847U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12342273503071032250U;
            aOrbiterH = RotL64((aOrbiterH * 867417849555857179U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14997696377476124836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14874498694181230698U;
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2549397729130885686U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4217995818662767955U;
            aOrbiterI = RotL64((aOrbiterI * 5525525344485251063U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 52U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 60U)) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14767U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10047U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12579U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 9835U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 26U)) + 7270044678408187242U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + 10192278965379756766U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 17568666746676060748U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 14312927531124963037U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 9825825726152087706U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9696778570255265896U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17657841352013417228U;
            aOrbiterJ = RotL64((aOrbiterJ * 17562220176018833833U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16207815085909628439U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1752979206374514227U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14182667540650694199U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10456310689643905854U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16127830548663742550U;
            aOrbiterA = RotL64((aOrbiterA * 4355938404839045417U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2940917376003930842U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7353596864777649953U;
            aOrbiterH = RotL64((aOrbiterH * 7499468723171042005U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12725092740446150705U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5791296650856037010U;
            aOrbiterB = RotL64((aOrbiterB * 760379251950502133U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 28U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterB, 60U)) + aPhaseHWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20103U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20777U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17770U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 19634U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 56U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 898812731947995389U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 57U)) + 8677347622525527167U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 41U)) + 770321564027567654U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 11020474858081526395U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 5U)) + 17289793580414993470U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10111912559295118444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8083622125544542011U;
            aOrbiterH = RotL64((aOrbiterH * 3610772128071340341U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7149858558922988240U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5919683821379905699U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16705119888884231567U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6860902846079238714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15083517836867542075U;
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14852868368708376381U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9860233289028878323U;
            aOrbiterE = RotL64((aOrbiterE * 13418143547952204667U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 772406119079116272U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7971141501337627589U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aPhaseHWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30802U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29497U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25452U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 25593U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 11U)) + 12809562813316740345U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 16074921689983846769U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 23U)) + 14027986153007120145U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 35U)) + 7633455951809250227U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 340989348513370174U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5307820377645020116U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8402492604131262157U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5605285015771527274U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5293500434746182790U;
            aOrbiterE = RotL64((aOrbiterE * 17674669610895537063U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7263156475892261811U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10672879570907433005U;
            aOrbiterH = RotL64((aOrbiterH * 2506338667179450741U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16659226780900986107U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9774892622769850665U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10728057184108279042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5032485856947407217U;
            aOrbiterB = RotL64((aOrbiterB * 16651577903809154285U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 28U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
