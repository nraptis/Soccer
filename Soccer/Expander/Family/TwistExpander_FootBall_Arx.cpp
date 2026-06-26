#include "TwistExpander_FootBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_FootBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEC7B1A9F59DAA9C3ULL + 0xA2E3F213E1C63416ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB0AABC6319BA70E9ULL + 0xE8D8234379D22C71ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD2CA87F80029690FULL + 0x81F8FD5E55C1D04FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x86433C38EB5ED769ULL + 0xA929478770E4B55BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE9DD5F0A4D05D9F1ULL + 0xE15039DBB7589681ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE11598DC8562EC23ULL + 0xC0886EB6306F965CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEC07D640C5F1BB43ULL + 0xC102CD62AAB348EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE97DE9EBE5E36C15ULL + 0xC55B241623A58B63ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1320U)) & S_BLOCK1], 4U) ^ RotL64(mSnow[((aIndex + 4299U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordF, 24U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 181U)) & S_BLOCK1], 11U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 3352U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 6521330037475130256U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 41U)) + 12611880456055428940U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 12061611078130934708U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 37U)) + 1558112410801116984U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 5U)) + 10509115227850160786U) + RotL64(aNonceWordG, 43U);
            aOrbiterG = ((aWandererE + RotL64(aScatter, 47U)) + 4045915960688792066U) + RotL64(aNonceWordB, 13U);
            aOrbiterK = (aWandererI + RotL64(aIngress, 43U)) + 1196541286513243082U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 15564991032722373702U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 21U)) + 4897765238703641798U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 18U)) + 12327429514907752733U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 6189189797708711636U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6374267075282018852U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1888758503831341439U;
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14956857689299491800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterG = RotL64((aOrbiterG * 9166712966729591953U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16086885494838105042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10854345917959911439U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7078313614360332089U;
            aOrbiterH = RotL64((aOrbiterH * 9864025732292844871U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15083669236062255011U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 594879695916679116U;
            aOrbiterK = RotL64((aOrbiterK * 9852515479152735283U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6721466068234534523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 475816724162626782U;
            aOrbiterB = RotL64((aOrbiterB * 4799725182757588407U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4341655358154605899U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15477254302340298586U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13961520225881974201U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10179091913200895775U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6310490897546909571U;
            aOrbiterA = RotL64((aOrbiterA * 15080621088825477613U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13462682513035460711U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16739138858084100385U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterC = RotL64((aOrbiterC * 16386371811268298031U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13608837667062268989U) + RotL64(aNonceWordD, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12902415667552110103U;
            aOrbiterE = RotL64((aOrbiterE * 16398790854093048017U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16596211634603915761U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6521330037475130256U;
            aOrbiterJ = RotL64((aOrbiterJ * 631958426544321145U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + RotL64(aNonceWordH, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 50U)) + aOrbiterG) + RotL64(aNonceWordC, 52U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 24U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordF, 54U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 9059U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((aIndex + 10522U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10250U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 7656U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 58U)) + 6733949564325516029U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordD, 13U);
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 7304098437143918796U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 3923949518391777800U;
            aOrbiterK = (aWandererB + RotL64(aCross, 21U)) + 14243591003388927124U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 37U)) + 18329498724605410406U) + RotL64(aNonceWordB, 3U);
            aOrbiterI = (aWandererC + RotL64(aCross, 19U)) + 13118172167747037249U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 5U)) + 5272025143849174212U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 53U)) + 16075917179214318424U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 23U)) + 15263590648674658399U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 13730046728289525921U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 7703141464499623408U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1382279753822135359U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2973369221699098292U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11578274119583013219U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3419411247737896674U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17814942652262802991U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2582783513078999303U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3959762790273529677U;
            aOrbiterB = RotL64((aOrbiterB * 383974377372162751U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 465795011576934604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17880826624185821135U;
            aOrbiterD = RotL64((aOrbiterD * 4445949147592860913U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10819659185349413173U) + RotL64(aNonceWordA, 9U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17298208553586835030U;
            aOrbiterC = RotL64((aOrbiterC * 1965860510614222093U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12585880006661489402U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16650193903267408586U;
            aOrbiterA = RotL64((aOrbiterA * 5781132589396936615U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 885882046325991589U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 869560078374809974U) ^ RotL64(aNonceWordF, 55U);
            aOrbiterK = RotL64((aOrbiterK * 13440973563438747181U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11871305571797951851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6044048326509186958U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 622564532811968856U;
            aOrbiterJ = RotL64((aOrbiterJ * 14988345089359014037U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17133994029325040272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8612895899003926829U;
            aOrbiterG = RotL64((aOrbiterG * 2128664397481732179U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2169081503433534750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6733949564325516029U;
            aOrbiterF = RotL64((aOrbiterF * 10062179904046311601U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 34U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + RotL64(aNonceWordC, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterC, 52U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + RotL64(aNonceWordG, 30U));
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 14U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 48U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 11629U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15119U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordG, 4U)) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14349U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 11295U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 10U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 439898681482066326U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 54U)) + 17362083676671776094U;
            aOrbiterE = (aWandererI + RotL64(aCross, 23U)) + 6418499837265155024U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 17262244253027454972U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 2382066162993139503U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + 14345808395587174135U) + RotL64(aNonceWordH, 45U);
            aOrbiterC = (aWandererE + RotL64(aPrevious, 46U)) + 7534743166385552851U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 3U)) + 16994453324688523966U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 7079553728544045092U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 41U)) + 3562822704508440641U) + RotL64(aNonceWordE, 39U);
            aOrbiterI = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 13990892681975857821U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1796728922368577238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6605161260520067178U;
            aOrbiterE = RotL64((aOrbiterE * 8147537646591674091U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13994083795942328918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6144523182899107711U;
            aOrbiterH = RotL64((aOrbiterH * 4153879991344611283U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12247462325297436642U) + RotL64(aNonceWordG, 37U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1065809332002012789U;
            aOrbiterK = RotL64((aOrbiterK * 5496601177032953251U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10147919864511540753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17138553441127273354U;
            aOrbiterG = RotL64((aOrbiterG * 5773875596275267871U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2653924016109573974U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6254416952351699582U;
            aOrbiterA = RotL64((aOrbiterA * 12756861659704947257U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 813046408080197079U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9624466135414123483U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6960320253124395015U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 972586705850825744U) + RotL64(aNonceWordC, 50U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 155283774901960223U;
            aOrbiterD = RotL64((aOrbiterD * 9928051687724257041U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 18200100644751360406U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1168426822045686004U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5867027156069481313U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2271564377169233643U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1896317305868283986U;
            aOrbiterC = RotL64((aOrbiterC * 8080751157990019287U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10209708407397294552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 947585551223387294U;
            aOrbiterB = RotL64((aOrbiterB * 15339472308062247067U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12313594490465462211U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 439898681482066326U;
            aOrbiterI = RotL64((aOrbiterI * 12336632799055203705U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aNonceWordF, 21U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 46U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterC, 44U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 28U) + aOrbiterF) + RotL64(aOrbiterD, 46U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aNonceWordA, 7U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 20333U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 19463U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21323U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 21022U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 18U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 47U)) + 13714409587461539863U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 27U)) + 14101156723903265839U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 30U)) + 7063754562895369001U) + RotL64(aNonceWordE, 47U);
            aOrbiterA = (aWandererK + RotL64(aScatter, 23U)) + 12320578575245519386U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 11744826789631008424U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 13U)) + 8744816505096675597U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 60U)) + 10405435520084528645U) + RotL64(aNonceWordF, 25U);
            aOrbiterG = (aWandererG + RotL64(aCross, 37U)) + 1463157688070683543U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 12379603577919617703U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 1343439118031348146U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 43U)) + 16118850268070235540U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14116264435819277136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterB = RotL64((aOrbiterB * 1495818611622063967U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14806408656041403829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterC = RotL64((aOrbiterC * 9913158908301414861U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 17063874769147888574U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 17U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterD = RotL64((aOrbiterD * 9042782809534196563U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2550285599827162167U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17801534123304996448U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2160836889363614721U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6456685241021762041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17064208177372969289U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13726627607233302493U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18279938244131982650U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8211002229712129419U;
            aOrbiterE = RotL64((aOrbiterE * 12931373380977640645U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12795832560781931767U) + RotL64(aNonceWordG, 42U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 286378504074349650U;
            aOrbiterK = RotL64((aOrbiterK * 85453101173293509U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5835304250436889513U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12704972686724379659U;
            aOrbiterF = RotL64((aOrbiterF * 1198789639656336053U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12555700587254295099U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6740149669657971715U;
            aOrbiterI = RotL64((aOrbiterI * 9376048577305482691U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1541392147096889431U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16891341703173286949U;
            aOrbiterH = RotL64((aOrbiterH * 697452963711223355U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8811637585092392653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13714409587461539863U;
            aOrbiterA = RotL64((aOrbiterA * 2578939920876994763U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aCarry, 21U)) + RotL64(aNonceWordA, 49U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 24U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + RotL64(aCarry, 53U)) + RotL64(aNonceWordB, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 54U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordB, 12U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 23396U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23217U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 58U) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27271U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23076U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 6U)) + 1042610313571524121U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 3505725321008825582U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 23U)) + 12584654563843782991U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 51U)) + 6645399144515770935U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 37U)) + 3608978423753715584U;
            aOrbiterH = ((((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 8089198857670370983U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordD, 13U);
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 21U)) + 15207251813516399879U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 9579268660105824516U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 13U)) + 16055044469473802812U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 39U)) + 583811872609805949U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 28U)) + 7027491967970873942U) + RotL64(aNonceWordE, 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 18256061823189677508U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12708429127816136937U;
            aOrbiterJ = RotL64((aOrbiterJ * 12593886633108075321U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12169216645156306078U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12694325407567795065U;
            aOrbiterH = RotL64((aOrbiterH * 3711789483877261899U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16109994660203297503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4234704064165718913U;
            aOrbiterF = RotL64((aOrbiterF * 730085881474787681U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14119541943554602878U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8777769004811352951U;
            aOrbiterC = RotL64((aOrbiterC * 2556957257736134223U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15642663488392549609U) + RotL64(aNonceWordG, 31U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11594468530833278624U;
            aOrbiterA = RotL64((aOrbiterA * 6639306656361601143U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7365350535791499871U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5965170981970155956U;
            aOrbiterG = RotL64((aOrbiterG * 1898702752753066851U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9115232101451815522U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9433983580038990072U;
            aOrbiterE = RotL64((aOrbiterE * 1951249217843992179U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8810565477444156140U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12081286530401844859U;
            aOrbiterD = RotL64((aOrbiterD * 1991383259486140229U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7498045374283306625U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13095973566401200720U;
            aOrbiterI = RotL64((aOrbiterI * 2657451581036351987U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 18205793828042507364U) + RotL64(aNonceWordF, 7U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3339020890428651569U;
            aOrbiterB = RotL64((aOrbiterB * 10195916881103252701U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16957913958369950483U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1042610313571524121U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11206619213970727629U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 28U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + RotL64(aNonceWordA, 8U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordH, 17U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 30U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordF, 14U)) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 30293U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27403U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordD, 58U)) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28790U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31629U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 23U)) + 14157904117287696136U;
            aOrbiterH = (aWandererG + RotL64(aCross, 21U)) + 7369512677371640676U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 8411250745902073798U) + RotL64(aNonceWordH, 37U);
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 5U)) + 5002041814539710275U) + RotL64(aNonceWordC, 55U);
            aOrbiterG = ((aWandererB + RotL64(aScatter, 10U)) + RotL64(aCarry, 53U)) + 9538041410816283124U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 19U)) + 5210700103927513061U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 7600709399101287982U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 39U)) + 2366369466696580499U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 5544575244203019109U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 14U)) + 8710073749110329779U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 27U)) + 15998211310115361630U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15354357553877376422U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10657523549259276169U;
            aOrbiterB = RotL64((aOrbiterB * 13695239532898311073U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10405750198355464768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3465819693133515142U;
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16724189641701408630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3484340153620198872U;
            aOrbiterC = RotL64((aOrbiterC * 17247547677520703125U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7420442404884871126U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11138445997256757636U;
            aOrbiterD = RotL64((aOrbiterD * 11167543379937571127U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1428191560884663125U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16950093140800653985U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 17288299075036481960U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordE, 21U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13793597915359681028U;
            aOrbiterA = RotL64((aOrbiterA * 9639204979982125757U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5017972942710079726U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12409957957614320964U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10273295741911545745U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12487994181992095174U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1573393166996612118U;
            aOrbiterE = RotL64((aOrbiterE * 13364311829104520751U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13227642825780350128U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7961292096150889569U) ^ RotL64(aNonceWordG, 15U);
            aOrbiterF = RotL64((aOrbiterF * 16627209081334341289U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10312485102088913337U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3177620041478410950U;
            aOrbiterH = RotL64((aOrbiterH * 15918551366833593853U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2599092792737616563U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14157904117287696136U;
            aOrbiterK = RotL64((aOrbiterK * 14883446269291639813U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 28U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordD, 54U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aNonceWordA, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 40U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 14U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_FootBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x91CB661F42BB70DBULL + 0xAA53E27E4811F99FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E8DEDD73A42AE8DULL + 0xA43A50095C0D502DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDDCF23ADE4BFDF09ULL + 0xAE506430F7F5F66EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE39D7EC8260F7357ULL + 0xF4331C63FAD721BDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB9FAF05602F9768DULL + 0x9F666977EBD03F6BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x814541200DB30355ULL + 0xAEF52EE38D13CC9FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x92C8F0D191D554B5ULL + 0xD3727C5D8C8E2C65ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x83E37121BC064BBDULL + 0x9AC44EBA763DA0C6ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4428U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2805U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordE, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6795U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 6039U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 28U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 30U)) + 14179205183062705133U) + RotL64(aNonceWordH, 59U);
            aOrbiterD = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 210032324058740920U) + RotL64(aNonceWordA, 46U);
            aOrbiterA = (aWandererC + RotL64(aCross, 19U)) + 7387115089142500152U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 35U)) + 17583362781238061430U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 11U)) + 4991442849150005943U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 2891376254689854555U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 10523274382407446239U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 53U)) + 3861893764676218667U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 26U)) + 3366674459852093746U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5898492634386601145U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7047353571244768721U;
            aOrbiterA = RotL64((aOrbiterA * 2257518291062508467U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14374108805453186316U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8763667021501226510U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7694695426430267863U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18261523829316379575U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 650477532238860965U;
            aOrbiterB = RotL64((aOrbiterB * 8291758490821819851U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2162326554604894042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5776546692501825278U;
            aOrbiterG = RotL64((aOrbiterG * 14911545784585246537U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3501863793638415049U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14853789267425352958U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10590325397179928739U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15399673014671329743U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12253428583438990426U;
            aOrbiterK = RotL64((aOrbiterK * 12052855472196447849U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13202953937621953839U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7547616636832698398U;
            aOrbiterC = RotL64((aOrbiterC * 9533399972562428073U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15709801946594868318U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12458677982746610971U) ^ RotL64(aNonceWordE, 47U);
            aOrbiterD = RotL64((aOrbiterD * 6662570874316418993U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6957370791367530127U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10511379961344950861U) ^ RotL64(aNonceWordB, 5U);
            aOrbiterE = RotL64((aOrbiterE * 15551333099264031337U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 56U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterC, 24U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + RotL64(aCarry, 41U)) + RotL64(aNonceWordF, 15U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aNonceWordC, 41U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 56U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12407U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11043U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 22U) ^ RotL64(aNonceWordG, 57U)) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12369U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 14860U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 24U)) + 11039986441331892533U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 6256024955965426119U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterD = (aWandererK + RotL64(aPrevious, 39U)) + 9857443189988995666U;
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 11900944813380998208U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 35U)) + 8422577734978875541U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 60U)) + 3100835100713928724U) + RotL64(aNonceWordC, 35U);
            aOrbiterB = (aWandererB + RotL64(aIngress, 43U)) + 11871553509810206993U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 17614749493763417027U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 3638372131856199916U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6582275259281025770U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17016882418498941958U;
            aOrbiterD = RotL64((aOrbiterD * 4269869255230867823U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1747214688658984715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9356088987044015278U;
            aOrbiterE = RotL64((aOrbiterE * 16221733545319753695U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4056238112133473456U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16013150119949532998U;
            aOrbiterB = RotL64((aOrbiterB * 12913648646318115315U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16076621211111834889U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9940824359571581765U) ^ RotL64(aNonceWordF, 5U);
            aOrbiterF = RotL64((aOrbiterF * 11624767861336495331U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15624084004784515753U) + RotL64(aNonceWordB, 10U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7630989544834680335U;
            aOrbiterH = RotL64((aOrbiterH * 12261063237156822067U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18003586430673313786U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1654118743290334161U;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3254189676528343910U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15629083361573065165U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17024833368570949107U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10056859810555674806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15976683222786846254U;
            aOrbiterJ = RotL64((aOrbiterJ * 2801754232182942635U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11872378594829637933U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7633773773528713489U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8218288492011593353U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI + (((RotL64(aCross, 42U) + aOrbiterH) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 47U)) + RotL64(aNonceWordA, 49U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + RotL64(aNonceWordD, 9U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 52U) + aOrbiterJ) + RotL64(aOrbiterF, 48U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordF, 22U)) ^ RotL64(aNonceWordA, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17213U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 20646U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20475U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 22141U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 13U)) + 12426357877879529292U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 37U)) + 12604900366173639176U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 47U)) + 13511119007338929401U) + RotL64(aNonceWordB, 51U);
            aOrbiterB = (aWandererC + RotL64(aPrevious, 41U)) + 9878720081166788060U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 15463195409806395076U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 23U)) + 6407922778852833423U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 51U)) + 7690427254160734016U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordA, 13U);
            aOrbiterH = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 18030974031722143619U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 58U)) + 17983938038322737041U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16605512170117753884U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 681802273302348322U;
            aOrbiterJ = RotL64((aOrbiterJ * 14608920184802647123U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15550312921312083819U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17824154101711884508U;
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1939207786756735430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3132864634777826569U;
            aOrbiterB = RotL64((aOrbiterB * 13606281919426730325U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12822929773923954849U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16576106045887115660U;
            aOrbiterK = RotL64((aOrbiterK * 16370914370769903051U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2398825881649235260U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 23U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13700821892926092479U;
            aOrbiterD = RotL64((aOrbiterD * 10830623703416956043U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2439833784883391606U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterF = RotL64((aOrbiterF * 3797380922767479287U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9165457123134229670U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8736642509192659417U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16219277537523484065U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9232719746484835693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7826680628853322541U;
            aOrbiterH = RotL64((aOrbiterH * 12578050118133526187U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14323652326982518782U) + RotL64(aNonceWordC, 42U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2254524512851399313U;
            aOrbiterA = RotL64((aOrbiterA * 4119339547645451149U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 6U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 22U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aNonceWordG, 7U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 30U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aNonceWordF, 49U));
            aWandererK = aWandererK + ((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27667U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 28008U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26671U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 31178U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 57U)) + 15910560457440369082U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 47U)) + 17953072986407436888U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 24U)) + 15446940721193538669U) + RotL64(aNonceWordA, 34U);
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 3020785262774422009U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 7001288645424994404U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 29U)) + 13385250665458462689U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 4U)) + 4841895644623005949U) + RotL64(aNonceWordB, 17U);
            aOrbiterB = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 13053476783239482065U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 641996979335975244U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16211238020928688299U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12715448751323279480U;
            aOrbiterC = RotL64((aOrbiterC * 2116880429675303291U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9035070625716345139U) + RotL64(aNonceWordG, 21U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterJ = RotL64((aOrbiterJ * 10405728912339646693U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1177103851507561053U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9040984343694325070U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13334258224023902365U;
            aOrbiterG = RotL64((aOrbiterG * 4782523727707164869U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1079824790138592518U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 14024082692012948652U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ RotL64(aNonceWordH, 57U);
            aOrbiterD = RotL64((aOrbiterD * 3219489374333737903U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2966776524421278970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5510281854029308547U;
            aOrbiterB = RotL64((aOrbiterB * 9275402927591867297U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7126632329316720048U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1476827035602733472U;
            aOrbiterE = RotL64((aOrbiterE * 2217671289726794033U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6470212302133184965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4172257438373147415U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4449314239630366533U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 38U) + aOrbiterI) + RotL64(aOrbiterJ, 56U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aNonceWordD, 55U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + RotL64(aNonceWordC, 45U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_FootBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFC7E4E87C58CFC9BULL + 0xC06D231AB6F41C01ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA81418B68D9B8F7BULL + 0xB711445444027FC6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDAC86081FC2E3DCDULL + 0xCCB6A37544021CB3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF10019347C7202C3ULL + 0xC31FFF76AD852DF0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x96A32CC60141E19BULL + 0x9CDD88648DCB8A72ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA9B83F8B0D7CDF5FULL + 0xBE56AFFE8B739810ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC30BF72102F6092FULL + 0xD46F03B2F534847AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCC4EABF0C6E08265ULL + 0x963EDF5115A54D63ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordF, 52U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4433U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2107U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 40U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4822U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 6886U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 40U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 43U)) + 8866844335448071821U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 15159698739856430085U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordH, 5U);
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 9582805772989594633U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 51U)) + 1438538239931588373U) + RotL64(aNonceWordA, 34U);
            aOrbiterG = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 10862044156620436139U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13682173320058164615U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8351013291045977592U;
            aOrbiterI = RotL64((aOrbiterI * 5722336275651615473U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 15777857431516633916U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 59U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16178966745333885377U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7545129923202147703U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9031889187993001617U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17118710301967158153U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 642109145903321046U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9186268569255318035U) ^ RotL64(aNonceWordD, 7U);
            aOrbiterJ = RotL64((aOrbiterJ * 10714674348507516749U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6091345356803675860U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterG = RotL64((aOrbiterG * 15415157927185637717U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 6U));
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordF, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + RotL64(aNonceWordG, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10231U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11113U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordD, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14084U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 15222U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 15920462086654025436U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 10U)) + 487844076858004017U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordG, 6U);
            aOrbiterA = ((aWandererE + RotL64(aScatter, 47U)) + 14502883786442630566U) + RotL64(aNonceWordE, 49U);
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 3787107318658233674U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 12548777544693755491U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4907309444075181683U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18342396700266492072U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14842961036061482089U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13503051997624242670U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17845742460521374571U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1366356786138085155U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8640887211877858169U) + RotL64(aNonceWordA, 55U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5273913123709097537U;
            aOrbiterD = RotL64((aOrbiterD * 1661149444148461791U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17756844173695563883U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6713055830729302951U) ^ RotL64(aNonceWordF, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 2832836748513174311U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5106468334224035972U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10228769728713526172U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 60U)) + RotL64(aNonceWordC, 25U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 59U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16676U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24358U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21206U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19772U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 3U)) + 3236820517816085022U;
            aOrbiterD = ((((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 741288875914097926U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 61U);
            aOrbiterK = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 8417246926007729580U) + RotL64(aNonceWordD, 53U);
            aOrbiterI = ((aWandererI + RotL64(aCross, 30U)) + 9715717805774537170U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 14360243844821619482U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10760908100206775334U) + RotL64(aNonceWordH, 59U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3434641779946167811U;
            aOrbiterK = RotL64((aOrbiterK * 3305698324169010803U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7885568822756234567U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3041563437672051294U;
            aOrbiterD = RotL64((aOrbiterD * 11440300917533482297U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 15761355327564963516U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1158633562785937421U;
            aOrbiterA = RotL64((aOrbiterA * 15511324886867188235U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9338581575871970653U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9172038894262857354U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3110871165285625807U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14653924713599790081U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3854497592598563309U;
            aOrbiterJ = RotL64((aOrbiterJ * 11737111068815795303U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterK, 26U));
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 6U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordG, 55U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordD, 54U)) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31099U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32029U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28750U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28531U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 7948891781097675369U) + RotL64(aNonceWordB, 21U);
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + 13928362874228230226U) + RotL64(aNonceWordC, 53U);
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 10776180542602258926U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 5735115172149470447U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 39U)) + 5353591822981766987U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 562301708107268570U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10467810247578364868U;
            aOrbiterK = RotL64((aOrbiterK * 10449089554007059823U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14541630141152308564U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2350076897065139429U;
            aOrbiterD = RotL64((aOrbiterD * 12222554362482034393U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17519109078651162228U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6061035173339902910U;
            aOrbiterI = RotL64((aOrbiterI * 10021905773432907835U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15654836633731000065U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13723521735153718904U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 2849680038315532197U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 41U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17336102435576647923U;
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordA, 46U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 38U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordE, 59U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 47U);
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

void TwistExpander_FootBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF2AB082C3A11B041ULL + 0xD7F67F26E2821C64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8C4013B0C84D77ABULL + 0xE67CD876CBFE1823ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD1325D91EE9EC6C3ULL + 0xA0CD7A56365E20DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD496419F51F6C517ULL + 0xB83C705E697FDA16ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD153426B1BA1A861ULL + 0xDDFFF258932926B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9E3A0282FEC5CB75ULL + 0xE5A47B2B3014184AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE70B42BF9931693FULL + 0x82613BC2B1E85B59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xADC3F36840D7BA67ULL + 0x9A810DC3969F6A9FULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1731U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 4812U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3278U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5526U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 41U)) + 4751694786009671052U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 9U);
            aOrbiterA = (aWandererE + RotL64(aPrevious, 51U)) + 16362725160370844224U;
            aOrbiterH = (aWandererF + RotL64(aCross, 58U)) + 6360885380915941057U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 5154536007972297036U;
            aOrbiterF = ((((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 9362540581874808253U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 59U);
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 13902493871525612934U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 10208452885367546542U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3117030377279160998U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17286247690414027870U;
            aOrbiterH = RotL64((aOrbiterH * 4896931759653832095U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3930314320040949141U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7289525252391668404U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15452162299105112187U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 3434167955466809185U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17852573095128575663U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1485660158767033425U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 6137259687928853253U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13992510605237574698U;
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6470556523400123474U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4333255670390099293U;
            aOrbiterK = RotL64((aOrbiterK * 11089933812030082647U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7700424876430257995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16920736951239453071U;
            aOrbiterC = RotL64((aOrbiterC * 8920407493132380497U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1635071690430295730U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9966700845966398620U;
            aOrbiterA = RotL64((aOrbiterA * 17210048121896546867U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aNonceWordD, 22U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterD, 26U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aNonceWordA, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordG, 4U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14717U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 15964U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 42U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11133U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 9664U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 13U)) + 5041131702736607991U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 37U)) + 9295010428212681446U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 58U)) + 6235875895358766017U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 2622227802531866918U) + RotL64(aNonceWordG, 37U);
            aOrbiterE = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 3888894734834524972U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 241682012014701753U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 15758000422451568079U) + RotL64(aNonceWordB, 38U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2061944548396976912U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8177144990755754531U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12702392689484397947U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 554978075608818497U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 250408260560714933U;
            aOrbiterB = RotL64((aOrbiterB * 1295379390497107727U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8700027645880997552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10026130047465480902U;
            aOrbiterC = RotL64((aOrbiterC * 12417270861933696623U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9785843014096326696U) + RotL64(aNonceWordH, 47U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9998582683258411251U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7197956237569462269U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13817734599383455151U) + RotL64(aNonceWordF, 61U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6647207154174092691U;
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4957715980509035719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4994885315786213197U;
            aOrbiterG = RotL64((aOrbiterG * 5676683798126497011U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5072908311783966503U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5535039946192891515U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2989412783482309753U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 48U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordA, 31U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 4U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG + ((((RotL64(aCross, 10U) + RotL64(aOrbiterH, 43U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceWordD, 45U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22397U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19259U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24084U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23843U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 17264605017518259932U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 3U)) + 15209184354580778643U) + RotL64(aNonceWordF, 23U);
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + 3299527965014731384U) + RotL64(aNonceWordE, 37U);
            aOrbiterG = (aWandererD + RotL64(aScatter, 19U)) + 16293096431816127821U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 11031983436878828337U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 9188018632448236358U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 46U)) + 13420816400363406556U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2485063384097917101U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordB, 43U);
            aOrbiterC = RotL64((aOrbiterC * 8813152992957361153U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10730544971770435788U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10431767565618874806U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4723078464590561545U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14883796491656899074U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13465877783538483706U) ^ RotL64(aNonceWordG, 34U);
            aOrbiterI = RotL64((aOrbiterI * 14311686051108108503U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13322163435314643713U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4950101626975919939U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17961706029559914243U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18146616411403012772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8414050129421955787U;
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + RotL64(aNonceWordD, 27U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordC, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordG, 18U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26071U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26747U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31309U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27404U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 13481227414590594621U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 13U)) + 17425964381118918026U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordG, 37U);
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 4792004356135956581U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 11926849936000639098U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 27U)) + 990697329347742142U) + RotL64(aNonceWordB, 26U);
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 37U)) + 9307721505373076588U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 4U)) + RotL64(aCarry, 3U)) + 17605732738841908719U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13110764518634187439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17970109897810645911U;
            aOrbiterI = RotL64((aOrbiterI * 10395095143998920213U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10273133817644703654U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11239046688920468137U) ^ RotL64(aNonceWordA, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 5197802934333553327U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8355821483275763145U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ RotL64(aNonceWordF, 55U);
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5381663179722418112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9551368011768104906U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16264476585232221270U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7721417776432288282U;
            aOrbiterB = RotL64((aOrbiterB * 10267770327791051869U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 339418090653475277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3247926250495935511U;
            aOrbiterA = RotL64((aOrbiterA * 16824669543765729097U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3390560045236418590U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3894024951542543635U;
            aOrbiterF = RotL64((aOrbiterF * 10599637790900418767U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + RotL64(aNonceWordE, 61U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordH, 45U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_FootBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x841F9272E2FFADB7ULL + 0xFCEB1F7760E4293AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9297A5BC8844B83FULL + 0x932D20F287DB002CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA8AE9EC9557522DDULL + 0xF7E176E91582A2DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x94A1E902C1FE012FULL + 0xEE48223EF86C8E65ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x92353330B719F0F5ULL + 0xF13A13EDF70275E6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC8E6078C0FF461BFULL + 0xE06D5D63F0DA320CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCFD6BE663E84306DULL + 0xC56B4A7977893DEDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB76B2418CBA585D1ULL + 0xCD6E1A9CD5BB31BEULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 20U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4681U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 2496U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 47U)) ^ RotL64(aNonceWordE, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 628U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7380U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + 16651241552253078315U) + RotL64(aNonceWordB, 9U);
            aOrbiterD = (((aWandererH + RotL64(aIngress, 29U)) + 4558144676982478003U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            aOrbiterG = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 8814884320080367550U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 23U)) + 16011579668555672117U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 4738918668759862438U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 51U)) + 12526083125540985108U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 8048723561746000552U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1082218464034639039U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8432043246965946816U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7801965585991025451U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9982080524048636852U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6720069955755215919U) ^ RotL64(aNonceWordG, 52U);
            aOrbiterE = RotL64((aOrbiterE * 1025046364205332059U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1019035028070247757U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7360619079463870467U;
            aOrbiterK = RotL64((aOrbiterK * 6623074813047915863U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10893918488381348474U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1390297670907738019U) ^ RotL64(aNonceWordC, 61U);
            aOrbiterF = RotL64((aOrbiterF * 11909657437658597735U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12512200589031203480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14741471280748399540U;
            aOrbiterJ = RotL64((aOrbiterJ * 3012135242889901095U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8543897248359826770U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8545972622733791272U;
            aOrbiterI = RotL64((aOrbiterI * 11793879362775346821U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7049384618581928664U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14730773807906925408U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10711566871536755073U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aNonceWordD, 27U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aNonceWordH, 25U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 54U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 20U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordA, 28U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11771U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8972U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 40U) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12070U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15954U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 16183871922837164759U) + RotL64(aNonceWordD, 7U);
            aOrbiterI = (aWandererA + RotL64(aCross, 47U)) + 7002058258090219055U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 53U)) + 5650868611888303705U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 11899839660943876690U) + RotL64(aNonceWordA, 37U);
            aOrbiterC = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 15349649504488111111U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 11U)) + 14060149569086744970U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 3U)) + 12920917574225030112U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2831994965175330135U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18312543585028439192U;
            aOrbiterG = RotL64((aOrbiterG * 11618182708195744321U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11657562205118394239U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10850792819281246052U;
            aOrbiterK = RotL64((aOrbiterK * 10663100544207879337U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17810371216216125323U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7963413941144223128U;
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5498715358793875584U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9256727548911651373U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10498848323914000989U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17246360111302191699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18309978718113983369U) ^ RotL64(aNonceWordE, 38U);
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3100998994319502921U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8129301860291235970U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17847033539279176187U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1889641029473279114U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16538494307002917945U) ^ RotL64(aNonceWordC, 21U);
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 26U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 29U)) + RotL64(aNonceWordF, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aNonceWordB, 15U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 42U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordE, 56U)) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20950U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20720U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordG, 58U)) ^ RotL64(aNonceWordB, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22446U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 17445U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U)) + (RotL64(aIngress, 28U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 19U)) + 5160910997561396461U;
            aOrbiterH = ((((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 14920764751058512062U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 5U);
            aOrbiterK = (aWandererE + RotL64(aIngress, 13U)) + 6080952401749660022U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 17667234330526298627U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 3U)) + 760630072638686756U) + RotL64(aNonceWordG, 60U);
            aOrbiterF = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 3504157162816997476U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 27U)) + 9489022223422585882U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1149898536879968964U) + RotL64(aNonceWordD, 15U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10492284328940025310U;
            aOrbiterK = RotL64((aOrbiterK * 7893416766300156495U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13213275606286399312U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10557118912847180413U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10077877991284587845U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15618980209023994776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5268600749854045564U;
            aOrbiterB = RotL64((aOrbiterB * 3849660559223919613U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8011552687609649990U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3148133096349525066U;
            aOrbiterC = RotL64((aOrbiterC * 5245156554959620007U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12032847944237867285U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14999005703490824673U;
            aOrbiterD = RotL64((aOrbiterD * 6631584955208646049U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5426735969392906710U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3593177531650386729U;
            aOrbiterF = RotL64((aOrbiterF * 12997284886192717043U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1701444719333347373U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15928731228196894960U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterI = RotL64((aOrbiterI * 1919318226904213433U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aNonceWordH, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordF, 49U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterC, 58U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24966U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24858U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordD, 40U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25310U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 29837U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 4U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 12U)) + 12136097566601676613U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 7969431322248040056U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 3U)) + 10530676021510553889U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 8740777303075445264U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 47U)) + 13249434169895564739U) + RotL64(aNonceWordH, 31U);
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 15529577005925628472U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 57U)) + 344627093687331562U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordC, 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8824277416519988893U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5636276438449709875U;
            aOrbiterE = RotL64((aOrbiterE * 222817930773618893U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2079413361031851552U) + RotL64(aNonceWordE, 38U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7807998179168655561U;
            aOrbiterF = RotL64((aOrbiterF * 961456853699784753U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13589392896232029112U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10733011474804473996U;
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15934162328347805968U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7573511217796245232U;
            aOrbiterG = RotL64((aOrbiterG * 10694563909931636155U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4828475187337891975U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13284974329890393113U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10831075817642374287U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13173869918669643112U) + RotL64(aNonceWordD, 25U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15841507674783398167U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15632933198136963277U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14168272451055700516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + RotL64(aNonceWordB, 49U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 4U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterE) + RotL64(aNonceWordF, 55U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_FootBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB3D24499B021994DULL + 0xA78324A3B028972CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD7515CD31CCE83CDULL + 0x9C6B7B13E7452440ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF6778D9C8CB686BBULL + 0xE41F0902C342A543ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB6C9957C206A10D5ULL + 0x95B57F5C402F8C4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8E0CEAE9B9E708DFULL + 0xC0F5349FF8D9473CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF0631EDFE0DC802DULL + 0xD6C6C59DB81D3232ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBFB650E7A0E46DBFULL + 0xBE3D65AF863208CAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE9EB6102D10B2703ULL + 0x9604BBFD270C0D76ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7837U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3104U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordD, 60U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4344U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3845U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 57U)) + 13880995121909552664U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 41U)) + 14534942818069300546U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 39U)) + 17745973100886007133U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 46U)) + 2249805580771946872U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 29U)) + 4460116116396439410U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 23U)) + 3378683994078106878U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 3992996501048809123U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 43U)) + 12057768808864451929U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 52U)) + RotL64(aCarry, 27U)) + 4115362079047921130U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 15297384955502206698U) + RotL64(aNonceWordB, 57U);
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 13U)) + 17623548383481905636U) + RotL64(aNonceWordG, 9U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3559213898000162417U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14807313864347885885U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11222085523291581822U;
            aOrbiterK = RotL64((aOrbiterK * 12580941911587215653U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 916681229436292462U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2441350114032314686U) ^ RotL64(aNonceWordA, 29U);
            aOrbiterD = RotL64((aOrbiterD * 7336079498999018067U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7361470539894653271U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12153585147213579808U) ^ RotL64(aNonceWordE, 25U);
            aOrbiterI = RotL64((aOrbiterI * 3040327545467672961U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13566300726101613579U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14875254144748509128U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9268158535644002904U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14144295981814993491U;
            aOrbiterE = RotL64((aOrbiterE * 12739937231684038161U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13861225650900541642U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12620513474052058164U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18141974182442267181U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14163773386433257965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5725700029399455855U;
            aOrbiterB = RotL64((aOrbiterB * 10446930901088908809U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16644838246877860102U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6611825438224873117U;
            aOrbiterF = RotL64((aOrbiterF * 5336239588054125897U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9408958265247071226U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16980073477599191801U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7985839560318985205U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6513029242607881518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13880995121909552664U;
            aOrbiterH = RotL64((aOrbiterH * 17463079726765044639U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + RotL64(aNonceWordC, 19U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 50U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aNonceWordD, 30U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 6U) + RotL64(aOrbiterK, 26U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16325U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 9833U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 23U)) ^ RotL64(aNonceWordD, 34U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15363U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12931U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 34U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 60U)) + 9751314027302668907U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 12175450995523107056U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 3U)) + 17519694958730119552U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 37U)) + 9093525527925682263U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 19U)) + 3713831321786810138U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 10108355209191835040U) + RotL64(aNonceWordD, 15U);
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 44U)) + RotL64(aCarry, 13U)) + 12956307447311314768U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 39U)) + 1904298513945877359U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 23U)) + 4658049993308574460U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 53U)) + 9826333658248851902U) + RotL64(aNonceWordC, 31U);
            aOrbiterA = (aWandererK + RotL64(aScatter, 13U)) + 12058666914724365134U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2516574707110528099U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13335308331049750235U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5880227828760598587U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8230749255538495304U) + RotL64(aNonceWordA, 47U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12387639130570188998U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8459259798142872020U;
            aOrbiterJ = RotL64((aOrbiterJ * 8001346480955847013U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16083784052002800300U) + RotL64(aNonceWordE, 38U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1957284290736468379U;
            aOrbiterI = RotL64((aOrbiterI * 5046501301740813065U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7349538179311335863U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16395170077006105258U;
            aOrbiterE = RotL64((aOrbiterE * 4230485452156662763U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3317652065873784068U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5517155804799120700U;
            aOrbiterD = RotL64((aOrbiterD * 9789270651974719183U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5568525912112200094U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9334250662962319598U;
            aOrbiterB = RotL64((aOrbiterB * 5034887614541768961U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5641394627075994165U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13524971148931512745U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15124425790244392471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7896294947517723306U;
            aOrbiterC = RotL64((aOrbiterC * 7526632360108129915U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15241686066829586263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12099799118961857495U;
            aOrbiterH = RotL64((aOrbiterH * 10456171163074630861U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17529688916595727188U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9751314027302668907U;
            aOrbiterA = RotL64((aOrbiterA * 521888849578281715U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterC, 58U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + RotL64(aNonceWordH, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aNonceWordF, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 26U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordA, 41U)) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18296U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20095U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 6U) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22835U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 17768U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 35U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 6068543441070417854U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + 2995980468193441856U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 19U)) + 18020277482171594003U;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 4293807434721230702U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            aOrbiterF = (aWandererF + RotL64(aIngress, 51U)) + 7980599111583893156U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + 8593141111851052016U) + RotL64(aNonceWordA, 5U);
            aOrbiterD = (aWandererC + RotL64(aScatter, 37U)) + 5903487523900084325U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 6U)) + 15112035513447930209U;
            aOrbiterE = (aWandererK + RotL64(aCross, 53U)) + 9854037263057006439U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 16759760289688823193U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 35U)) + 12622628933030601390U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1264668857268123425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16302812053619101593U;
            aOrbiterA = RotL64((aOrbiterA * 18291400055836111547U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16087995784896123610U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7970269262800468363U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5331477046030959632U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16534913204255550893U;
            aOrbiterG = RotL64((aOrbiterG * 1013433634373673565U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11042821902537871209U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8069677512345031660U) ^ RotL64(aNonceWordD, 18U);
            aOrbiterF = RotL64((aOrbiterF * 13622218526054132397U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5737130058129936372U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1076627182956662997U) ^ RotL64(aNonceWordC, 59U);
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13911061091801078190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15397603151098990373U;
            aOrbiterK = RotL64((aOrbiterK * 1802890451633592245U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15137326716738637972U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11248737008959896786U;
            aOrbiterI = RotL64((aOrbiterI * 90789374131547005U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1847847987633923657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10560748778679145431U;
            aOrbiterJ = RotL64((aOrbiterJ * 2919333327817231099U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2703726238610290251U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12950671360471467310U;
            aOrbiterD = RotL64((aOrbiterD * 7490327691501537047U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10331504168520449467U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1541527607705280906U;
            aOrbiterE = RotL64((aOrbiterE * 14197400812600186171U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9135056476214341809U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6068543441070417854U;
            aOrbiterC = RotL64((aOrbiterC * 14102524444094948875U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 20U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordG, 39U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aNonceWordB, 37U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 44U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordA, 4U)) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25425U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29283U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordD, 40U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31873U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 30774U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCross, 4U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 11480359716598965890U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 11U)) + 15431182525482873419U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 11360504974812776707U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 23U)) + 9292576416573382769U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 48U)) + 1549257414531028975U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 5347769463033129317U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 21U)) + 17019199177478377234U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 39U)) + 16558106007323125094U) + RotL64(aNonceWordF, 34U);
            aOrbiterK = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 3976182233825939422U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 6U)) + 2889047161195954395U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 57U)) + 2241831345026962605U) + RotL64(aNonceWordB, 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12850802412140579294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13541744735436450160U;
            aOrbiterC = RotL64((aOrbiterC * 906089290000537439U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2085863085516538212U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2969034221711544086U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7768528124408400403U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6482666944512391472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16969153556875844613U;
            aOrbiterA = RotL64((aOrbiterA * 9483462388353216219U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 5161314086757363678U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordC, 47U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7150282484670673211U;
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5465304381272305847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2344610773390354017U;
            aOrbiterB = RotL64((aOrbiterB * 17010258514288089191U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8335906578006588582U) + RotL64(aNonceWordG, 3U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13668796013474193793U;
            aOrbiterK = RotL64((aOrbiterK * 8228000547141147777U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9663362594301419686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3683773739120343413U;
            aOrbiterG = RotL64((aOrbiterG * 8319320803406104749U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2538583190438044942U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4454069062219406996U;
            aOrbiterF = RotL64((aOrbiterF * 16329554225309389599U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17177136683616247897U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3680497519697457252U;
            aOrbiterI = RotL64((aOrbiterI * 6479357366957384599U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16812938441063719463U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4545693142067578891U;
            aOrbiterJ = RotL64((aOrbiterJ * 17479957806084346527U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9232311730019478327U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11480359716598965890U;
            aOrbiterH = RotL64((aOrbiterH * 6678546065399772697U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 6U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aNonceWordE, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + RotL64(aNonceWordH, 55U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 28U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_FootBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8F0D546599C60BC3ULL + 0x86DD30B2D1C6069FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC3796B2CFCF9C065ULL + 0xAA060A587D5E9D5EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFD5AA391FF6297E3ULL + 0x96DA183FBD1222BBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8D33FFC8B6256D59ULL + 0xFCF18688F7D88225ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE2CD7E42F2B51027ULL + 0xA448732E1CFE94ADULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB6CC2029DB4343E5ULL + 0xD24C86E97337F921ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB74F01AF5DC8585ULL + 0xBDCCD818C12C245FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAD62A0A1DCF11E8FULL + 0x8D2BA13E7E1D93F0ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordG, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2509U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 4738U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4700U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 583U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 50U)) + RotL64(aCarry, 3U)) + 12426357877879529292U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 12604900366173639176U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 11U)) + 13511119007338929401U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 9878720081166788060U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 15463195409806395076U) + RotL64(aNonceWordB, 7U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 56U)) + 6407922778852833423U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 7690427254160734016U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 18030974031722143619U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 39U)) + 17983938038322737041U) + RotL64(aNonceWordC, 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16605512170117753884U) + RotL64(aNonceWordA, 29U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 681802273302348322U;
            aOrbiterJ = RotL64((aOrbiterJ * 14608920184802647123U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15550312921312083819U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1939207786756735430U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3132864634777826569U;
            aOrbiterH = RotL64((aOrbiterH * 13606281919426730325U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12822929773923954849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16576106045887115660U;
            aOrbiterG = RotL64((aOrbiterG * 16370914370769903051U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2398825881649235260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13700821892926092479U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10830623703416956043U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2439833784883391606U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15870638514107637833U;
            aOrbiterF = RotL64((aOrbiterF * 3797380922767479287U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9165457123134229670U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8736642509192659417U) ^ RotL64(aNonceWordH, 25U);
            aOrbiterB = RotL64((aOrbiterB * 16219277537523484065U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9232719746484835693U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7826680628853322541U;
            aOrbiterE = RotL64((aOrbiterE * 12578050118133526187U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14323652326982518782U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2254524512851399313U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4119339547645451149U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 60U)) + aOrbiterB) + RotL64(aNonceWordD, 16U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 34U)) + aOrbiterG) + RotL64(aCarry, 41U)) + RotL64(aNonceWordF, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6312U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 10461U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6519U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 9158U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 28U)) + 4622023259121087483U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 10253505250223501352U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 17133877904420462669U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 6162827793741796700U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 9610986424765907615U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 11U)) + 11210747154264753754U) + RotL64(aNonceWordE, 35U);
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 16554205219580654546U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 23U)) + 10352576357413766388U) + RotL64(aNonceWordD, 13U);
            aOrbiterD = (aWandererJ + RotL64(aScatter, 58U)) + 3651845783283479752U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 18145542190463500476U) + RotL64(aNonceWordB, 5U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5415609566767162857U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6474184559323816389U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2033734872464201570U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3507213117125813345U;
            aOrbiterA = RotL64((aOrbiterA * 5453058336688881113U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8716253393049851856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 695984869565941856U;
            aOrbiterI = RotL64((aOrbiterI * 8377921610764044735U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7661578828878284931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 906654265099155956U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8117625377607536949U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6050049984731254612U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17882717590338190821U;
            aOrbiterD = RotL64((aOrbiterD * 10807367411402733215U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4996521991532815957U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4246460672800604436U;
            aOrbiterH = RotL64((aOrbiterH * 12047466401960824903U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8700148116452518842U) + RotL64(aNonceWordH, 49U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10039050281847466206U;
            aOrbiterJ = RotL64((aOrbiterJ * 11884791271239660157U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4513844680425845372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3037563127442815153U;
            aOrbiterC = RotL64((aOrbiterC * 18363509277992292407U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1005237931570968724U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1373258132025712065U;
            aOrbiterB = RotL64((aOrbiterB * 10458020799382532395U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterD, 18U)) + aOrbiterC) + RotL64(aNonceWordF, 61U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 44U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aNonceWordC, 36U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererI, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 40U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14876U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 13865U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordF, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10939U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 12430U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 2558105147674438050U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 14U)) + 15856662514774702561U) + RotL64(aNonceWordE, 41U);
            aOrbiterG = (aWandererE + RotL64(aIngress, 5U)) + 13346869226246584582U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 47U)) + 7632111846116243973U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 2102101361626976279U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 5605968705067851563U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 51U)) + 6842483186584326681U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 10U)) + 5559797213819425064U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 19U)) + 12422313931331576759U) + RotL64(aNonceWordD, 10U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2751024420047872601U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14366375309473793217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11971479429768505316U;
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3947595951884469542U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17882767922372770896U) ^ RotL64(aNonceWordC, 15U);
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 513871456983509223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5951677013597794294U;
            aOrbiterD = RotL64((aOrbiterD * 8508629569649935293U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 437626309049021931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 466674061172005705U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1310502572084891157U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12362602809233133718U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10525852878882195702U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17927000184308583095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 566723721423470052U;
            aOrbiterH = RotL64((aOrbiterH * 17710534355278632573U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9504585484034413577U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4614306037721859929U) ^ RotL64(aNonceWordG, 47U);
            aOrbiterB = RotL64((aOrbiterB * 170807293799483539U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1463218357720031588U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4036696102163560633U;
            aOrbiterI = RotL64((aOrbiterI * 15389914226155130065U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + RotL64(aNonceWordH, 39U));
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + RotL64(aNonceWordF, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterI, 44U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18547U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20842U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordH, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17822U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18833U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 43U)) + 14624277139785904404U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + 6966977309498165611U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 12U)) + 205536824352530761U;
            aOrbiterF = (aWandererG + RotL64(aCross, 19U)) + 16629575265808255692U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 596881340147972746U) + RotL64(aNonceWordG, 51U);
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + 11944412799107412650U) + RotL64(aNonceWordD, 13U);
            aOrbiterA = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 4615021315668210206U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 52U)) + 8497630055977606216U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 11131601107309336885U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5935883479805510099U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15629346719765798174U;
            aOrbiterC = RotL64((aOrbiterC * 8535523790685945275U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5279128339113651273U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16778365912440331821U;
            aOrbiterJ = RotL64((aOrbiterJ * 705421028266789241U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16003052937645491524U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6723226158737614764U;
            aOrbiterA = RotL64((aOrbiterA * 16690657664909260573U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9785784358981219543U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10055457337292292710U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17919129940751761111U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11779163108592974175U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1177999477942202687U;
            aOrbiterF = RotL64((aOrbiterF * 13475069421684114643U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 9190694445141492214U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordB, 54U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15605342360346353457U;
            aOrbiterD = RotL64((aOrbiterD * 14547769706392595647U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14877565450677523492U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1074095623308025684U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7884068939436891093U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12803174154216941583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8813356463693637033U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4898237214617563167U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6063909634038581414U) + RotL64(aNonceWordF, 27U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15112191502834052566U;
            aOrbiterI = RotL64((aOrbiterI * 6780741782103553485U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aNonceWordA, 31U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 14U));
            aWandererC = aWandererC + ((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aNonceWordE, 39U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordH, 58U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24505U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26501U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 30U) ^ RotL64(aNonceWordG, 41U)) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24591U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 22800U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 12027839670755583592U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 30U)) + 15380130703509859843U) + RotL64(aNonceWordE, 17U);
            aOrbiterA = (aWandererE + RotL64(aCross, 53U)) + 4590907433867798074U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 35U)) + 1754574023602519724U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordA, 30U);
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 9832756659564903767U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 5035088494491470403U;
            aOrbiterH = (aWandererH + RotL64(aCross, 18U)) + 14199170923323644638U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 5U)) + 8325619421264440438U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 969534320779067977U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 270575869402913847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13344806516599578910U;
            aOrbiterA = RotL64((aOrbiterA * 10193544126281901579U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15143147951139409101U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14425582489214169238U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16893787086337916355U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13951127523239064584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8258920744278218901U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 7408161179397242453U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ RotL64(aNonceWordH, 23U);
            aOrbiterF = RotL64((aOrbiterF * 975737128100519169U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8581481606764773468U) + RotL64(aNonceWordF, 55U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10078416198417433133U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1102721083915858247U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18299772198826189580U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18304668908084397946U;
            aOrbiterB = RotL64((aOrbiterB * 10589455451200578687U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16729632621573817223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13362300981585573239U;
            aOrbiterH = RotL64((aOrbiterH * 9824473895535518785U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8629682832849915380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6852852009091469641U;
            aOrbiterC = RotL64((aOrbiterC * 11912646687050011915U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7433098156961745198U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10931806208899417308U;
            aOrbiterD = RotL64((aOrbiterD * 14699197041038067483U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 20U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aNonceWordB, 25U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterH, 24U)) + RotL64(aNonceWordD, 13U));
            aWandererG = aWandererG + ((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27341U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 32337U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32568U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28301U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 56U)) + 12262991801139086177U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 7963038771924890197U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 19U)) + 15540520327933568896U) + RotL64(aNonceWordG, 3U);
            aOrbiterF = (aWandererC + RotL64(aCross, 43U)) + 8745565892055020722U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 23U)) + 16619329199683755286U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 10U)) + RotL64(aCarry, 11U)) + 10865705026433867260U;
            aOrbiterE = ((((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 2743368697984518059U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordH, 40U);
            aOrbiterH = (aWandererD + RotL64(aCross, 29U)) + 5556006271515473135U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 5355833281353498588U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8313616108963479829U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16657121016801866434U;
            aOrbiterB = RotL64((aOrbiterB * 331533349428472477U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16532226425013000833U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5800465874932467232U;
            aOrbiterI = RotL64((aOrbiterI * 5966395771690704577U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17882948163883121328U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 15029375310296563175U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordA, 49U);
            aOrbiterE = RotL64((aOrbiterE * 17021415832288477713U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10170682648007918739U) + RotL64(aNonceWordF, 39U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11829089574189398773U;
            aOrbiterH = RotL64((aOrbiterH * 15755874363488568849U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1746524867389196322U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10217423427886742775U;
            aOrbiterA = RotL64((aOrbiterA * 9166162099575333519U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1338457710729082656U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1319981417675542556U;
            aOrbiterJ = RotL64((aOrbiterJ * 9518448254565489715U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3985281993069194761U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7281264481139915593U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13498446162967276739U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17394503335338855566U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1430703546991948227U;
            aOrbiterC = RotL64((aOrbiterC * 1623206122475721175U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 472559435062214929U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8065899137826178995U;
            aOrbiterK = RotL64((aOrbiterK * 13287499768933229539U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 24U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aNonceWordC, 45U));
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererG = aWandererG + ((((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + RotL64(aNonceWordB, 17U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

void TwistExpander_FootBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC831468E1CF0B2E1ULL + 0xD01F88E25FFDCEFEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBA0C284993EF4F29ULL + 0xF459BFCDA09BE5D6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x94192E9FB43D323DULL + 0x9295D03740C030F9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBC843010D4A2BE1DULL + 0x8850A6032E3D8F90ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC60CEF4ED42B18ADULL + 0xCE46B54EB12032D1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBB5EA3C6E95343F5ULL + 0xA9BAC895DA97000BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDC49058783FFFEC1ULL + 0xCBD674AAC58E5F02ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB36DD5B3B06685A1ULL + 0xDC80E36A6840E82BULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordD, 60U)) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3947U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 1367U)) & W_KEY1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 12U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5041U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4141U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 16519040829220310189U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 6888002778416941825U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 27U)) + 1310832187746534025U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 5890888009051281674U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 37U)) + 5143864838362464857U) + RotL64(aNonceWordG, 48U);
            aOrbiterH = (((aWandererD + RotL64(aScatter, 11U)) + 15591534069452660003U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterA = (aWandererK + RotL64(aPrevious, 60U)) + 1466867671765325096U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13931443680107902488U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15400747367673245552U;
            aOrbiterC = RotL64((aOrbiterC * 7011651369456453127U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2836975369734495759U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2370720358274970117U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4615571902817575375U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3470677184188006133U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7175584278499266723U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10067096593682482345U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6095078817776863055U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2176637999243513070U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterA = RotL64((aOrbiterA * 12215701810843975501U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5580391239754903129U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15196125567953871184U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12686361960729564519U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12787014151503209931U) + RotL64(aNonceWordC, 49U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1523153207064063495U;
            aOrbiterF = RotL64((aOrbiterF * 3113907543551927561U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12973289026485937829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9087439766232078173U;
            aOrbiterE = RotL64((aOrbiterE * 5817029335999350327U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + RotL64(aNonceWordB, 61U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterA, 4U)) + RotL64(aNonceWordF, 23U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordF, 12U)) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8584U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7321U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 60U) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8054U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 10763U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 3U)) + 16451272412693907816U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 42U)) + 10099485419723255462U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 17668900099534923192U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 5497093724143181753U) + RotL64(aNonceWordH, 15U);
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 57U)) + 10354044773550071706U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 12728258851198019099U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 29U)) + 4144050505314242618U) + RotL64(aNonceWordD, 25U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14133805325480076530U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 308863673210602899U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2672613556981540433U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11741180130160569753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12926863156769180448U;
            aOrbiterA = RotL64((aOrbiterA * 9726030996091054939U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 211920854786494259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9164711974854618892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6667377062281954219U;
            aOrbiterH = RotL64((aOrbiterH * 2603737166987437649U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4559040002406721850U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1749875480850675109U;
            aOrbiterI = RotL64((aOrbiterI * 15822640067349481089U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9555365165561936366U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18289733999504213574U;
            aOrbiterB = RotL64((aOrbiterB * 14156217554673229429U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 8727162691639622461U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 31U);
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 291406782452963706U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordA, 13U);
            aOrbiterG = RotL64((aOrbiterG * 8413500075082350243U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 10U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aNonceWordC, 55U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 34U)) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 50U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordH, 27U)) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12270U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 15773U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordG, 40U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12731U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 12005U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 39U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + 4739486756133131180U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 16089707555501328184U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 15310047330238536453U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 11U)) + 7901411596386834955U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 27U)) + 4357555491060982163U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordD, 27U);
            aOrbiterH = (((aWandererD + RotL64(aCross, 40U)) + RotL64(aCarry, 13U)) + 15667085602825720102U) + RotL64(aNonceWordB, 21U);
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 8520635334382269253U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1772509779231068315U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15336170957886025677U;
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8628770833489469980U) + RotL64(aNonceWordA, 49U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15469234024247246228U;
            aOrbiterA = RotL64((aOrbiterA * 8905266995119987947U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10796430900884288328U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10660110397012853289U;
            aOrbiterG = RotL64((aOrbiterG * 9140007610912037461U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11202284258711214794U) + RotL64(aNonceWordG, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17509491802893182994U;
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16212572740740103554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2190030203761579226U;
            aOrbiterK = RotL64((aOrbiterK * 3101886685668871045U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12014337082293041909U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3733531010807001506U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5797362244066062299U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7100994963061975529U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17837541162838600258U;
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordC, 26U)) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 26U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordF, 55U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordB, 38U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21329U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 17809U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19660U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16533U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 21U)) + 18144572925667544139U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 5659758077574059728U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 6343330616999166392U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 57U)) + 17754639838410839447U) + RotL64(aNonceWordC, 53U);
            aOrbiterF = ((aWandererK + RotL64(aScatter, 35U)) + 9451843819849581729U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 7957854457197462212U) + RotL64(aNonceWordA, 43U);
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 10U)) + 1461994799722205010U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18002214276252170177U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14689869073147027164U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterG = RotL64((aOrbiterG * 12242482963989582191U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3978104368003440293U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8512135845221335386U;
            aOrbiterI = RotL64((aOrbiterI * 10506667163729414667U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1477533446382953439U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2166717790929947990U;
            aOrbiterB = RotL64((aOrbiterB * 6538884492418324461U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8082437060686606995U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4363687722464700362U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15782763348014924206U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12248271773316742521U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17244849374768558859U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1030743048280579012U) ^ RotL64(aNonceWordG, 47U);
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 18U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aNonceWordD, 15U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aNonceWordH, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordG, 11U)) ^ RotL64(aNonceWordF, 54U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24673U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 25865U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 26U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24730U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22241U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 15726877954695761686U) + aPhaseAOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 14187652171881943587U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 8420423151313882782U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 13U)) + 14942322692433259283U) + RotL64(aNonceWordH, 23U);
            aOrbiterB = (aWandererD + RotL64(aIngress, 3U)) + 7272331475919796255U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 53U)) + 154504365041805840U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 29U)) + 17475491222554948786U) + RotL64(aNonceWordB, 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5759181483165339605U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5993060214499322845U;
            aOrbiterG = RotL64((aOrbiterG * 10799489831896153301U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10901786237875941844U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17135786595614068473U;
            aOrbiterH = RotL64((aOrbiterH * 15923538730142047043U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 5208202073886811165U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordD, 61U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6821452921018900631U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13119330055184115669U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13348064837402206969U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterC = RotL64((aOrbiterC * 300168481725373093U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8130283784171430891U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6351113882502502876U;
            aOrbiterB = RotL64((aOrbiterB * 15960622823993072903U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 6894708729226455769U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17138279326229372741U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12987698199066890628U;
            aOrbiterJ = RotL64((aOrbiterJ * 12665716655177320977U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 44U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterC);
            aWandererD = aWandererD + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + RotL64(aCarry, 41U)) + RotL64(aNonceWordA, 43U)) + aPhaseAWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + RotL64(aNonceWordE, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 22U) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28209U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27912U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 51U) ^ RotL64(aNonceWordE, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27315U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31027U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 35U)) + 7722279280863371124U;
            aOrbiterC = (aWandererG + RotL64(aCross, 11U)) + 11584220561732385598U;
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 7834679350105534657U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterE = (aWandererD + RotL64(aIngress, 51U)) + 11347994382444180879U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 9449903188047063431U;
            aOrbiterA = ((((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 6516243976652795170U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 41U);
            aOrbiterG = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 8420815253991184777U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9081386852515170937U) + RotL64(aNonceWordC, 11U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14375955191735286867U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2772840314542262283U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 880757589768436072U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 3349856625725164229U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ RotL64(aNonceWordB, 43U);
            aOrbiterH = RotL64((aOrbiterH * 681514212582331781U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7826309957607577207U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8057435761214313635U;
            aOrbiterA = RotL64((aOrbiterA * 4718430712767038607U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9565237500443303103U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15893066735310588501U;
            aOrbiterG = RotL64((aOrbiterG * 8457633439171452397U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3276844534476430842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6828644383891274120U;
            aOrbiterJ = RotL64((aOrbiterJ * 979580351653410157U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2815676923011504251U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5030251870850928417U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7075653570570819253U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13464083008377887034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8994560761846897590U;
            aOrbiterC = RotL64((aOrbiterC * 9892839554658865143U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + RotL64(aNonceWordG, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 50U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + RotL64(aNonceWordH, 28U)) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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

void TwistExpander_FootBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDBC0511554F77E05ULL + 0xCEFAD4CB1C738DFCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCAD57508F1D4A7BBULL + 0xB74D58ADDA5D64BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAC5F09161947D4E9ULL + 0xA12D0CFFD5CD6E9CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBFDCFF32FFA72791ULL + 0xEBC899BC7CFEB8F3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9B11AD22409EFC3DULL + 0xF95D79B7C651AC94ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBD4BA265EF3E2FB9ULL + 0xFAEE4DF58EBC0220ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE1FC3CB6B11829A9ULL + 0xFB930F77D415766CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCBFF60A6A55671B9ULL + 0xEAD528466C0C3D0DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 456U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 284U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2443U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1522U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 47U)) + (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 5041131702736607991U) + RotL64(aNonceWordF, 38U);
            aOrbiterD = ((aWandererF + RotL64(aIngress, 21U)) + 9295010428212681446U) + aPhaseBOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 43U)) + 6235875895358766017U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 6U)) + RotL64(aCarry, 53U)) + 2622227802531866918U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 3888894734834524972U) + RotL64(aNonceWordD, 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 241682012014701753U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15758000422451568079U;
            aOrbiterG = RotL64((aOrbiterG * 14719166949665416221U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2061944548396976912U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8177144990755754531U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12702392689484397947U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 554978075608818497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8700027645880997552U) + RotL64(aNonceWordH, 51U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10026130047465480902U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12417270861933696623U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9785843014096326696U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9998582683258411251U) ^ RotL64(aNonceWordB, 15U);
            aOrbiterF = RotL64((aOrbiterF * 7197956237569462269U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + RotL64(aNonceWordE, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aNonceWordA, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordA, 4U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6357U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 9869U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6868U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8762U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 4739486756133131180U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 35U)) + 16089707555501328184U) + aPhaseBOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordB, 57U);
            aOrbiterD = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 15310047330238536453U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 7901411596386834955U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 14U)) + 4357555491060982163U) + RotL64(aNonceWordG, 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15667085602825720102U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8520635334382269253U;
            aOrbiterD = RotL64((aOrbiterD * 7348648918661047791U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1772509779231068315U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15336170957886025677U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10996880551392077399U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8628770833489469980U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15469234024247246228U;
            aOrbiterE = RotL64((aOrbiterE * 8905266995119987947U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10796430900884288328U) + RotL64(aNonceWordH, 27U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10660110397012853289U) ^ RotL64(aNonceWordD, 48U);
            aOrbiterI = RotL64((aOrbiterI * 9140007610912037461U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11202284258711214794U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17509491802893182994U;
            aOrbiterH = RotL64((aOrbiterH * 9329107599972703671U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordE, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 22U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordC, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 38U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 54U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12523U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 15311U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordA, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11018U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14163U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 6U)) + 1866656689936219099U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 19U)) + 2312314528139448289U;
            aOrbiterB = ((((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 3554037526469185237U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterH = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 405707755060974111U) + RotL64(aNonceWordG, 43U);
            aOrbiterD = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 1862976326004007697U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12992483065443288263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3793854946371595197U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterB = RotL64((aOrbiterB * 1819119223110966487U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4244007978867369382U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10280867500312580308U;
            aOrbiterI = RotL64((aOrbiterI * 13729899124177931289U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 472563452959164242U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12041770406895816553U;
            aOrbiterJ = RotL64((aOrbiterJ * 17811798500132002631U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6118634015704900486U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13637107920449233307U;
            aOrbiterH = RotL64((aOrbiterH * 17712028184714868053U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16673735670669318830U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8602681273646630496U) ^ RotL64(aNonceWordF, 51U);
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 52U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 54U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 52U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aNonceWordD, 31U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordC, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19185U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16882U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordG, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18549U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19036U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 48U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 3339283916456813609U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 3U)) + 11339086426180649584U) + RotL64(aNonceWordA, 5U);
            aOrbiterA = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 16819191669329316585U;
            aOrbiterG = ((((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 8361916937762630725U) + aPhaseBOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 61U);
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 35U)) + 18031328374429899857U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18261756894092897276U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4250319792907645666U;
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1492411503643460886U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17369549067879344180U;
            aOrbiterF = RotL64((aOrbiterF * 2947354306696216579U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 7301713524358676722U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordH, 55U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2985193736033012535U;
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14086975808140927408U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 18205555540941493267U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 28U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterJ = RotL64((aOrbiterJ * 3009081009044782443U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 42U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 14U)) + aOrbiterJ) + RotL64(aNonceWordF, 15U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aNonceWordD, 45U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordG, 58U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24923U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 24191U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 54U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21950U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 26669U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 4476099022490972343U) + aPhaseBOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 39U)) + 16836423700375760429U;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 8850577488928703557U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordH, 49U);
            aOrbiterE = (((aWandererI + RotL64(aIngress, 50U)) + RotL64(aCarry, 51U)) + 7091631824560042743U) + RotL64(aNonceWordD, 20U);
            aOrbiterI = (aWandererC + RotL64(aPrevious, 19U)) + 12560498899956759494U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7797973377112012161U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6173820673874805794U;
            aOrbiterA = RotL64((aOrbiterA * 15741300047917486527U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 10805025132310245348U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7139216143268029968U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8349754682635765573U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8241544862261635722U) + RotL64(aNonceWordA, 9U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4735527016563596150U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6621354217673598381U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5166171126690294033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11117641762075368393U;
            aOrbiterF = RotL64((aOrbiterF * 4980156869201219393U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6312932356458415421U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1304139291184508668U;
            aOrbiterE = RotL64((aOrbiterE * 90744653170922319U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 40U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordG, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 53U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 28U)) + RotL64(aNonceWordE, 15U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29476U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 29251U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordG, 56U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30542U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 32643U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 4204560462077827182U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 6572370199668594039U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 15958999876732622825U) + RotL64(aNonceWordE, 55U);
            aOrbiterC = ((aWandererI + RotL64(aCross, 41U)) + 9969349486879280377U) + RotL64(aNonceWordG, 57U);
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 5U)) + 15450238998293956181U) + aPhaseBOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9128619863683138259U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5691270563628979565U) ^ RotL64(aNonceWordF, 53U);
            aOrbiterJ = RotL64((aOrbiterJ * 2170424734274640859U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5901029710568933106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10442738941988588834U;
            aOrbiterD = RotL64((aOrbiterD * 7386621444831603817U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3508116020325721993U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13221917083569767259U;
            aOrbiterH = RotL64((aOrbiterH * 6845108555710135357U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11627915460377128176U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17858261365514253433U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 4294837988806295989U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 36U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11242915481585070249U;
            aOrbiterA = RotL64((aOrbiterA * 17540688242763829319U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aNonceWordA, 27U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordB, 9U)) + aPhaseBWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_FootBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB639E9C353F4DC19ULL + 0xE7D94416AB37125DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x887F706458129FD9ULL + 0xBFE44FE26430E329ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x90AF04507D13B80DULL + 0xC9DE9C5B435D4D2AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA9D437F7183DC343ULL + 0x885F1462D47FE8BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF69F72EAA2E28E91ULL + 0xFD648014E72D90F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD238476134BF6581ULL + 0x94D3AA85BAE4F3B1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x81C68E3F08088585ULL + 0xCCC63B1C6E058673ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC897D9547D9A5273ULL + 0xAF12D7418FFF9021ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordG, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4009U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 6867U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 46U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1088U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 6715U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 12222235191147985484U) + RotL64(aNonceWordD, 31U);
            aOrbiterG = ((aWandererD + RotL64(aIngress, 12U)) + RotL64(aCarry, 47U)) + 16367317014523328414U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 3511378091284703789U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 19U)) + 15247492830966725949U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 7745995913390407897U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 27U)) + 6463593307540108810U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 43U)) + 1101669311005268630U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 34U)) + 12988052764067518580U) + RotL64(aNonceWordA, 9U);
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 47U)) + 17717179747434679772U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11662190906682400416U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6563014073547628748U;
            aOrbiterC = RotL64((aOrbiterC * 16967910471722117761U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13099094932059419219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16342730862261868847U;
            aOrbiterI = RotL64((aOrbiterI * 10988124108686164829U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16855346813127524624U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6570063128502306944U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4571570049463124831U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11328352033809240501U) + RotL64(aNonceWordF, 37U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11640986648833160901U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2895830492089678919U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2675226158571501666U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17700531248266458165U;
            aOrbiterJ = RotL64((aOrbiterJ * 2231403813970188657U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7729597396731910874U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterE = RotL64((aOrbiterE * 149009041406406517U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9178769489257842683U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9020154972097834926U;
            aOrbiterB = RotL64((aOrbiterB * 8910504667566521429U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 1317403761217790562U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordH, 29U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17151528554929201571U;
            aOrbiterG = RotL64((aOrbiterG * 3735945655450625203U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11621882033959669977U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10289504450815075623U;
            aOrbiterF = RotL64((aOrbiterF * 13365982786836243195U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 52U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 44U));
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + RotL64(aNonceWordB, 17U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 16U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9719U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15549U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10010U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 11810U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 13278949403988203974U) + RotL64(aNonceWordG, 13U);
            aOrbiterG = (aWandererE + RotL64(aIngress, 34U)) + 9213599924054673756U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 47U)) + 1255746482932381798U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 57U)) + 11575321997144516122U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 15881587525529432437U;
            aOrbiterI = (aWandererC + RotL64(aCross, 6U)) + 9846195809864862707U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 12319815691858217670U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 16322617427294439587U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 43U)) + 16332130810525887437U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 59U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4920951156015336794U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16767126455124552329U;
            aOrbiterF = RotL64((aOrbiterF * 4440352337076842603U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12553595911087945223U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1437522202135436142U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterA = RotL64((aOrbiterA * 2001992794165550905U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12313100454852227143U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2761983020631055729U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3874839760378039509U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17635303588421554367U) + RotL64(aNonceWordD, 50U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 788212489507463763U;
            aOrbiterJ = RotL64((aOrbiterJ * 17896475584538528059U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5192552894670654434U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterC = RotL64((aOrbiterC * 8077237651953896479U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16113417046719114943U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1096874945215225916U;
            aOrbiterD = RotL64((aOrbiterD * 17308604412622879833U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7610274704570171595U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10466070212284342550U;
            aOrbiterE = RotL64((aOrbiterE * 6449728258497920613U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6777845928873855221U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5251515022021984126U;
            aOrbiterI = RotL64((aOrbiterI * 9018277343404261611U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13849343158824111498U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7977711210181714021U;
            aOrbiterG = RotL64((aOrbiterG * 4182053966171053577U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 36U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterI, 50U)) + RotL64(aNonceWordB, 25U));
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aNonceWordA, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 46U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordD, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23063U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 22238U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23230U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 19104U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 20U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 11210042748013785976U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 42U)) + 4584747303233477454U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 8878765929792969517U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 57U)) + 2172232330280041122U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 53U)) + 8378937026022264016U) + aPhaseCOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + 8683007464695824208U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 29U)) + 9564352997357118134U) + RotL64(aNonceWordB, 43U);
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 41U)) + 11713878436769887528U) + RotL64(aNonceWordA, 39U);
            aOrbiterC = (aWandererF + RotL64(aScatter, 23U)) + 8052917623074021077U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7720597162792145185U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2602847785328475621U;
            aOrbiterE = RotL64((aOrbiterE * 14065077077207224525U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17813669222300509724U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 8724263063156573013U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordH, 8U);
            aOrbiterA = RotL64((aOrbiterA * 3632927017737834359U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6882429835961613492U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13213313479525717359U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterD = RotL64((aOrbiterD * 2411431247725974895U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2401526093648669573U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3616448566579979749U;
            aOrbiterH = RotL64((aOrbiterH * 13323155103752121393U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18268262471839710401U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5116424918948694752U;
            aOrbiterB = RotL64((aOrbiterB * 7641143782996332069U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11405305689555640431U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12427591396711015574U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8112834135715541223U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16960781161508084626U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12382604781005282628U;
            aOrbiterI = RotL64((aOrbiterI * 17196168631120103115U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10054839091354729292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4167641616532985407U;
            aOrbiterJ = RotL64((aOrbiterJ * 919291747187787625U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14383737233143309039U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16258779988369405932U;
            aOrbiterC = RotL64((aOrbiterC * 8348773195366160215U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 52U)) + aOrbiterD) + RotL64(aNonceWordG, 29U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterH, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 60U) + RotL64(aOrbiterH, 10U)) + aOrbiterE) + RotL64(aNonceWordF, 61U)) + aPhaseCWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25615U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 29471U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordG, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26866U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 27794U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 42U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + 2330952702412094686U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 6U)) + 7820188225935060799U) + RotL64(aNonceWordC, 14U);
            aOrbiterG = (aWandererF + RotL64(aPrevious, 35U)) + 9347644591709839145U;
            aOrbiterC = (aWandererI + RotL64(aCross, 41U)) + 2288624878446846870U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 9358977729492824128U;
            aOrbiterB = (aWandererG + RotL64(aCross, 21U)) + 1858511275052455039U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 13715478509322292552U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 16413396625604260455U) + RotL64(aNonceWordF, 7U);
            aOrbiterD = ((aWandererH + RotL64(aScatter, 14U)) + 17714322215518432705U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16188315436202861122U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5564445841368207813U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14125834616162835983U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13717068949900594673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14143659432287313765U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5729546141908425670U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4297827922736712074U;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 829520109395163673U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2907177944512117206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterC = RotL64((aOrbiterC * 17927994356809011637U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1344592529249949068U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6470438516791143572U) ^ RotL64(aNonceWordH, 3U);
            aOrbiterB = RotL64((aOrbiterB * 13339390828725370475U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5217751823741520847U) + RotL64(aNonceWordE, 15U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5371275223586938039U;
            aOrbiterE = RotL64((aOrbiterE * 12318403075523724125U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14218103150268532919U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1367628876596800571U;
            aOrbiterD = RotL64((aOrbiterD * 13777531272321533137U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2372041991018455610U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9870744274890595581U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12093443117747395585U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 36U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordD, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + RotL64(aNonceWordA, 37U));
            aWandererH = aWandererH + (((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aPhaseCWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterA, 42U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_FootBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDFC6019081C198ABULL + 0xFA50D1DF6519E081ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE97C8CDD33C02A39ULL + 0xFF260AE7EED5F355ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF815A2E04FE25441ULL + 0xD791C4D3E7288955ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9D90BF474159E7D3ULL + 0x9105F2492201ED13ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD9C945FA4E1BF793ULL + 0xF608D7C19BBED350ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9855247E8F9A5B4FULL + 0x8E918BF1751CF880ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD805E9AF94080645ULL + 0xFD9ADDCF75C01507ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCECBB0B040EE4041ULL + 0x9B8BCF2DE74ECC65ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 44U) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1384U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3196U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 40U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4901U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3043U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 41U)) + 11410829607777684449U;
            aOrbiterF = (aWandererB + RotL64(aCross, 18U)) + 7502698839700975347U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 13267685058252106173U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 3U)) + 238242706996630625U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 53U)) + 8184695499511454281U;
            aOrbiterA = (aWandererF + RotL64(aCross, 39U)) + 12767823220461985403U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 12293198423143850330U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 11149495229952495939U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 14U)) + 7556992689338382800U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 19U);
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 3431338808774134649U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 35U)) + 16863099140844995099U) + RotL64(aNonceWordG, 17U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17872458049880677604U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16760153457252546974U;
            aOrbiterK = RotL64((aOrbiterK * 11225037229069712805U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3115544493537438408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4359882942759752958U;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13387113067202396536U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12955690074544490161U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15614054443728226807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterJ = RotL64((aOrbiterJ * 4484917074808974359U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4599016263007782537U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9962305629016158048U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1496184427500037279U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8428467674122750557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3938884087806393439U;
            aOrbiterB = RotL64((aOrbiterB * 12810531094050481761U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6018636830758044658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1510372000641305416U;
            aOrbiterE = RotL64((aOrbiterE * 9002834928626918247U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17592782466215337843U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8119921507606870360U;
            aOrbiterF = RotL64((aOrbiterF * 1299795061644535485U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8753237702359236964U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12389957327067768090U;
            aOrbiterD = RotL64((aOrbiterD * 4586786761936601607U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17791633199762408683U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11606494383812053915U;
            aOrbiterI = RotL64((aOrbiterI * 13041480602055778521U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 4418614662439151979U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 61U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11410829607777684449U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterG = RotL64((aOrbiterG * 3342270212301058781U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + RotL64(aCarry, 19U)) + RotL64(aNonceWordD, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB + ((RotL64(aScatter, 52U) + aOrbiterC) + RotL64(aOrbiterE, 26U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 42U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 44U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + RotL64(aNonceWordC, 52U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6845U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 6848U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordB, 48U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8435U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 8052U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 28U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 5U)) + 8367680518550579791U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 11491674725611181241U) + RotL64(aNonceWordD, 7U);
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 37U)) + 16673861720782164214U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 9786610124108350855U;
            aOrbiterK = (aWandererC + RotL64(aCross, 51U)) + 5745080601557577637U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 48U)) + 1959402215131684684U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 6121650036079196522U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 12016309761037342392U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + 5986936646177049603U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 42U)) + 1000367700904043468U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 53U)) + 17425288243569101032U) + RotL64(aNonceWordB, 60U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4856917474950325209U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16312111093223166419U) ^ RotL64(aNonceWordH, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 11046477664487805241U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 456110002032422270U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11393724374787795662U;
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8378176867715697176U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8086186452345234815U;
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8470349167474173245U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2528229938740192694U;
            aOrbiterA = RotL64((aOrbiterA * 8717790851266520943U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13247168811545753141U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8745293957516815264U;
            aOrbiterF = RotL64((aOrbiterF * 14270617180621072619U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6165915500564961987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12015407798844173213U;
            aOrbiterI = RotL64((aOrbiterI * 3913451986559154153U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 545006684939922156U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16366753936267185001U;
            aOrbiterG = RotL64((aOrbiterG * 6495185976430013201U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3097605623436091728U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15950167830259022926U;
            aOrbiterC = RotL64((aOrbiterC * 4415538963984293323U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8356327899232213426U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10183421678251169945U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9474380650337109299U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16327340177970834683U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7086901180933495535U) ^ RotL64(aNonceWordC, 47U);
            aOrbiterD = RotL64((aOrbiterD * 1276521829484494857U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13421211370092080006U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8367680518550579791U;
            aOrbiterB = RotL64((aOrbiterB * 12256662446176946163U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aNonceWordF, 51U));
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + RotL64(aNonceWordG, 59U));
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 54U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordA, 40U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13233U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11335U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordB, 50U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14172U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 14878U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 56U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 56U)) + 9654059367478508868U) + RotL64(aNonceWordC, 21U);
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 11U)) + 6473006635864677427U) + RotL64(aNonceWordE, 15U);
            aOrbiterC = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 6944184481315853243U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 23U)) + 4061496421939102306U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 15791809275719085463U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 43U)) + 14050798802646323055U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 39U)) + 12072905924741758266U;
            aOrbiterD = (aWandererH + RotL64(aCross, 51U)) + 17639076509231343896U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 3U)) + 12195388285571234715U;
            aOrbiterA = (aWandererA + RotL64(aCross, 13U)) + 4325404419499496529U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 41U)) + 5910567888204238382U) + aPhaseDOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13092940059929942699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13381962590820308761U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6345904465930943295U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15622862439323440527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14027151901132249793U;
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4584410023907605157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15763755180625487157U;
            aOrbiterJ = RotL64((aOrbiterJ * 6755736130607297639U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17023059745666559199U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5298529579288492971U;
            aOrbiterK = RotL64((aOrbiterK * 2483562793328357721U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2870152867331654736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12017191100173748848U;
            aOrbiterD = RotL64((aOrbiterD * 9958191466506480519U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15899529176182436062U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16482713846343388735U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 719465695044265601U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12943393531812774449U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9881108254540483225U;
            aOrbiterE = RotL64((aOrbiterE * 8011108108007885059U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3532054586199716750U) + RotL64(aNonceWordH, 17U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7142230313294797435U;
            aOrbiterH = RotL64((aOrbiterH * 14154176174768868421U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 733958394016131587U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2060800099014517137U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterB = RotL64((aOrbiterB * 12988885554457108631U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2278498033811574812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15342071118593803929U;
            aOrbiterI = RotL64((aOrbiterI * 7842196613533603835U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12987212219357101955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9654059367478508868U;
            aOrbiterF = RotL64((aOrbiterF * 11796100167917742307U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 6U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aNonceWordF, 26U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererD = aWandererD + ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21656U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 21702U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordD, 42U)) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17762U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21267U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 14U)) + 12029393034357490020U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 4526754731580694987U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 17060419646421271853U;
            aOrbiterB = (aWandererF + RotL64(aCross, 47U)) + 4128488893837059683U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 29U)) + 12706894827547160110U) + RotL64(aNonceWordB, 59U);
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 37U)) + 12506324593645825056U) + aPhaseDOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 19U)) + 12581344490649250025U) + RotL64(aNonceWordH, 15U);
            aOrbiterJ = ((aWandererE + RotL64(aCross, 57U)) + 14357032418199130132U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 15341977701796331249U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 12U)) + RotL64(aCarry, 47U)) + 7086602307544733241U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 39U)) + 12398300065276832486U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2499745046076601988U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7249361592814001829U;
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3254456186337366437U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3472973415969046680U;
            aOrbiterF = RotL64((aOrbiterF * 14583566953969168353U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7905718972111691591U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15941413652144021522U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3473779492962783565U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10583964125960308762U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13659925272340853715U;
            aOrbiterC = RotL64((aOrbiterC * 16708294803316630743U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9487054537489454887U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13287757570441887517U) ^ RotL64(aNonceWordA, 28U);
            aOrbiterJ = RotL64((aOrbiterJ * 17351439045329892107U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15279245465808571942U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12424999114621745879U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2274918760256527137U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13915392738892970475U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13797668053788805126U) ^ RotL64(aNonceWordE, 41U);
            aOrbiterD = RotL64((aOrbiterD * 13752161103680525317U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14344766585550401077U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13727554194373146727U;
            aOrbiterI = RotL64((aOrbiterI * 17164450431362670223U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1332966642432651232U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 938583742533681467U;
            aOrbiterE = RotL64((aOrbiterE * 13323340043936037549U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5659239372701978244U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8501778564909302938U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15629932660749672503U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1698500835332753591U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12029393034357490020U;
            aOrbiterB = RotL64((aOrbiterB * 18176507271635640153U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordC, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 54U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + RotL64(aNonceWordG, 7U));
            aWandererD = aWandererD + ((RotL64(aCross, 22U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 14U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aScatter, 26U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordD, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25703U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26699U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26996U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27145U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCarry, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aScatter, 48U)) + 2177539223979303669U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 3962004686551521471U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + 8457602312617147662U) + RotL64(aNonceWordH, 36U);
            aOrbiterJ = (aWandererA + RotL64(aCross, 3U)) + 18011802451816510632U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 23U)) + 9046101759168876832U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 11135620637431969597U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 5U)) + 15913029940697999701U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 16304193109948135982U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 57U)) + 13208892298820080981U;
            aOrbiterC = (aWandererF + RotL64(aCross, 18U)) + 4182377898949419225U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 51U)) + 13970137023071326151U) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 8402396284835248583U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8859190834060657829U;
            aOrbiterH = RotL64((aOrbiterH * 13552418608113716117U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9760005337757990392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14108277760135744897U;
            aOrbiterD = RotL64((aOrbiterD * 4474681104256093885U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12226316121949012350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3456392186754113960U;
            aOrbiterE = RotL64((aOrbiterE * 8704729827929941215U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5004087958637038973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7176881295123125567U;
            aOrbiterC = RotL64((aOrbiterC * 15272157962928021009U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10889800478505074438U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13728832441482547824U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterG = RotL64((aOrbiterG * 17588477761978646139U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17345665880706866772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 301139993853297566U;
            aOrbiterJ = RotL64((aOrbiterJ * 5812445396758354505U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2061389844760610160U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13631862266139238355U;
            aOrbiterB = RotL64((aOrbiterB * 143613352104722701U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10767186080827509622U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4893486019456886013U;
            aOrbiterA = RotL64((aOrbiterA * 5194746459545610901U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11264795916303477037U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16013652139405432608U;
            aOrbiterI = RotL64((aOrbiterI * 14924257021089920495U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5209743554932653849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13160179712987277456U;
            aOrbiterK = RotL64((aOrbiterK * 5003755912040281427U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12440615920191945386U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2177539223979303669U;
            aOrbiterF = RotL64((aOrbiterF * 3565122523239344029U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceWordE, 61U));
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 26U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + RotL64(aNonceWordF, 7U));
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 44U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31916U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 29726U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 34U) ^ RotL64(aNonceWordB, 43U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29481U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 27870U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aPrevious, 27U)) + 5480870806135400132U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 19U)) + 8034874599430768743U) + aPhaseDOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 23U)) + 4006919843736863767U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 44U)) + 2988069748674633718U) + RotL64(aNonceWordB, 7U);
            aOrbiterC = ((aWandererH + RotL64(aIngress, 41U)) + 12347295651973135786U) + RotL64(aNonceWordF, 37U);
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 14152683894431568192U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 53U)) + 15765143815254196598U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 10473067082331244233U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 29U)) + 1089466925383677249U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 13215039929873682230U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 12U)) + RotL64(aCarry, 43U)) + 3957997712247961479U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10023907397941685546U) + RotL64(aNonceWordE, 19U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14593012591254614353U;
            aOrbiterB = RotL64((aOrbiterB * 17111300092082154687U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13353797968154036726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9259966668512102858U;
            aOrbiterC = RotL64((aOrbiterC * 8326732574268308221U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10757861831070349321U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10530223113483866178U;
            aOrbiterI = RotL64((aOrbiterI * 11269177745265396583U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7554320926405521865U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 6978052067277966996U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordC, 11U);
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1053695861967171420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15980734683539854451U;
            aOrbiterE = RotL64((aOrbiterE * 3208466640010555357U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17041258393808061556U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12846551858751995530U;
            aOrbiterA = RotL64((aOrbiterA * 9303891433380993639U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14617434286683320666U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3999309956180741302U;
            aOrbiterF = RotL64((aOrbiterF * 15037707937050015205U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13452627760403094126U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2633241575260427158U;
            aOrbiterH = RotL64((aOrbiterH * 2638570213290747581U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15575035993965639421U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7829837426112185905U;
            aOrbiterG = RotL64((aOrbiterG * 17059814556114938275U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12565466096663867876U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4845209979900289818U;
            aOrbiterK = RotL64((aOrbiterK * 14990494169374347835U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13472490162287247012U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5480870806135400132U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9150331893094034245U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 38U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aNonceWordD, 4U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 56U)) + aOrbiterD) + RotL64(aNonceWordH, 29U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_FootBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8FAEFF0ADC973D59ULL + 0xC81A108035F4637DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA1E1BC0BDC22194BULL + 0xE7B69AFBB036C9E5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEF8245BF2684D7CDULL + 0x920085687F7A220AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC4A7D00B9635D735ULL + 0xADE070F1AD2650BDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDD2295D9EB94566DULL + 0xB32C12F2A539E2EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCF45D41584F99CFBULL + 0x85CC49C4F50ADB06ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE7D506CE3AA32BD3ULL + 0xF44BB46DF9D70A78ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF257FD641395B091ULL + 0xEA05301346C006B8ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordF, 44U)) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4464U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 3794U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3791U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 272U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 53U)) + 6973892330986118220U) + RotL64(aNonceWordD, 59U);
            aOrbiterC = (aWandererK + RotL64(aScatter, 58U)) + 9886813896272094864U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 10996306582517553173U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 5U)) + 8490648283899856223U) + RotL64(aNonceWordE, 11U);
            aOrbiterF = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 105141713530704655U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 37U)) + 3114337422810562588U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 56U)) + 980857684690886131U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 6562042345807072665U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 15665371138706353619U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 43U)) + 18113013571374375028U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 39U)) + 17405346422601997299U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5130876096426182506U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1813821672299154629U;
            aOrbiterB = RotL64((aOrbiterB * 15478100342425611875U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15793814882743306728U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13925299440495476399U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12049601510660117401U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9924458846049579438U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 7810034662781768090U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12812586478656872854U) + RotL64(aNonceWordF, 16U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5709576448057435237U;
            aOrbiterD = RotL64((aOrbiterD * 9101555233909853025U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7839807649914541516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4717944526755429647U;
            aOrbiterK = RotL64((aOrbiterK * 8515229146471335721U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3933911971504256022U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4814079680865379831U;
            aOrbiterI = RotL64((aOrbiterI * 15100740696230557391U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18352577312212175569U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9670612998448920742U;
            aOrbiterJ = RotL64((aOrbiterJ * 5743579439303300553U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 72737302703035726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10032869372369626210U;
            aOrbiterC = RotL64((aOrbiterC * 7449905669249993731U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2669999453643982386U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2016129534922291383U;
            aOrbiterF = RotL64((aOrbiterF * 11730911201750754301U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5108689262300895422U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3753457479225942895U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11503304711866175497U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 859776381005289485U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6973892330986118220U;
            aOrbiterG = RotL64((aOrbiterG * 12337041087475258221U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 10U)) + aOrbiterC) + RotL64(aNonceWordC, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 36U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 56U)) + RotL64(aNonceWordA, 61U));
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererF = aWandererF + (((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7712U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((aIndex + 10627U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordD, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10145U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10492U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 12U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 4773124477323378268U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 29U)) + 16848723289435796005U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 57U)) + 13846642134917107058U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 6472057872482789939U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 19U)) + 2747019500690707226U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 3U)) + 9003965289739733880U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 57U)) + 3013390651936257377U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 50U)) + 3331004709895625067U;
            aOrbiterE = (aWandererI + RotL64(aCross, 43U)) + 15355010435553517129U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 23U)) + 7709870658004280052U) + RotL64(aNonceWordA, 31U);
            aOrbiterF = (((aWandererK + RotL64(aIngress, 11U)) + 13568728443963926564U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordG, 22U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12409548853419307131U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 969183352023661537U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15370309834426476775U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3896803894396631184U;
            aOrbiterD = RotL64((aOrbiterD * 11018830202891911603U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10848873633291935766U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8252290890093788010U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9201553615601641350U;
            aOrbiterI = RotL64((aOrbiterI * 420321130559162915U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14014209645503188472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4015071464301844550U;
            aOrbiterE = RotL64((aOrbiterE * 17444195018239904971U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16173085647514027347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16916627014974363360U;
            aOrbiterA = RotL64((aOrbiterA * 7699587344277490953U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1591680303404522110U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 16499606051269327916U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordF, 23U);
            aOrbiterB = RotL64((aOrbiterB * 814405848002794813U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6932673635509444619U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8745681160108707944U;
            aOrbiterJ = RotL64((aOrbiterJ * 14565255558668084787U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10387263947888920455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2553335462317280031U;
            aOrbiterG = RotL64((aOrbiterG * 7253573275397985211U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17449861295444216249U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15716408844914738774U;
            aOrbiterH = RotL64((aOrbiterH * 10132631423215542589U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16974370193820578179U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4773124477323378268U;
            aOrbiterF = RotL64((aOrbiterF * 8982190762960590543U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 4U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + RotL64(aNonceWordD, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordH, 9U)) + aPhaseEWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 44U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16195U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 12304U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 10U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13576U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15068U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 13U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 13U)) + 3561491146322798260U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 7075025056181885339U) + RotL64(aNonceWordE, 43U);
            aOrbiterD = (aWandererH + RotL64(aScatter, 23U)) + 9230910887904171613U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 44U)) + 4119781172609908917U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 17155609083870983149U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 53U)) + 2423018561430181695U) + RotL64(aNonceWordD, 57U);
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 12957280305617615744U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 20U)) + RotL64(aCarry, 43U)) + 2461704174772065813U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 7907123257849391997U;
            aOrbiterA = (aWandererB + RotL64(aCross, 11U)) + 7257868138318960007U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 29U)) + 16425903703085702285U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2990822664594079467U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5654819006718953817U;
            aOrbiterD = RotL64((aOrbiterD * 4465096036756887801U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12183676471235678779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15026286960542123922U;
            aOrbiterF = RotL64((aOrbiterF * 17199049329995315279U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12169080607071830522U) + RotL64(aNonceWordA, 11U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2906296852254787499U) ^ RotL64(aNonceWordG, 54U);
            aOrbiterE = RotL64((aOrbiterE * 6754514406846040163U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3029858695410344584U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14406410317495954566U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11048818178401163861U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13622063920319445043U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2516025554421589857U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2642646089141233277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12761571777929273548U;
            aOrbiterA = RotL64((aOrbiterA * 5518252696078700127U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7753802695131502382U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8510425459525030222U;
            aOrbiterC = RotL64((aOrbiterC * 12412361423636026483U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13522645164493316722U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1437430302489702713U;
            aOrbiterB = RotL64((aOrbiterB * 14019316635365783545U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14745189473423751499U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16968328257002103715U;
            aOrbiterK = RotL64((aOrbiterK * 17915588590593471981U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5001838243344386314U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13506188720092630563U;
            aOrbiterJ = RotL64((aOrbiterJ * 7010027510838271877U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16902624500530747723U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3561491146322798260U;
            aOrbiterG = RotL64((aOrbiterG * 95761172090277669U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterA, 26U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + RotL64(aNonceWordC, 39U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + (((((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordH, 53U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19817U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18704U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 6U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21002U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 16798U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 48U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 19U)) + 9471546960258473684U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 18050235435948942244U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 23U)) + 3005107102671544641U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 17898396434573801850U) + RotL64(aNonceWordB, 61U);
            aOrbiterE = (aWandererJ + RotL64(aScatter, 34U)) + 15071602525497771648U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 27U)) + 5780119462702672108U;
            aOrbiterB = (aWandererI + RotL64(aCross, 53U)) + 13301326224151025687U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 18129323022260575961U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 41U)) + 1199228670638790709U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 5U)) + 1839199978088021020U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 4999517042246790165U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16674732686428431869U) + RotL64(aNonceWordA, 49U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15908873150953195581U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11204775359756474667U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2525984309543939465U;
            aOrbiterC = RotL64((aOrbiterC * 3988529812023791571U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4566345170476825512U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14876612901557406267U;
            aOrbiterB = RotL64((aOrbiterB * 9047956948845135339U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14926290877038883931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12710203178186614846U;
            aOrbiterD = RotL64((aOrbiterD * 14841163494801662515U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7315094513967387996U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11050116830482816766U;
            aOrbiterI = RotL64((aOrbiterI * 3702999495721152019U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4505368486032503953U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17905748055257551092U;
            aOrbiterK = RotL64((aOrbiterK * 14775870175093453197U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5728886950801376350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17998141690182325170U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16008599930125391379U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4325978018819134558U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13526905108565989379U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121321495714166291U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10597169665474269506U) + RotL64(aNonceWordC, 19U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7500801022830471869U;
            aOrbiterA = RotL64((aOrbiterA * 3702717219742363777U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17063616328548689935U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9471546960258473684U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3029748230803396737U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterE, 46U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 21U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + RotL64(aNonceWordD, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterA) + RotL64(aNonceWordH, 8U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 48U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22518U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23697U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22268U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 23736U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + 1888427424966603593U) + RotL64(aNonceWordA, 43U);
            aOrbiterK = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 5436761445660415091U) + RotL64(aNonceWordG, 25U);
            aOrbiterF = (aWandererJ + RotL64(aIngress, 58U)) + 17322876217962143270U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 5U)) + 9728299982740564979U;
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 301720335271716921U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 23U)) + 8069685428854814396U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 47U)) + 1973715500949100991U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 12U)) + 87666408799854155U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 12195436904339035245U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 4578742069143400295U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 19U)) + 7828776048774876484U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17203146364542781833U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16913369550858890466U;
            aOrbiterF = RotL64((aOrbiterF * 13534417587921978507U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9632761514552265402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9106637671877341286U;
            aOrbiterH = RotL64((aOrbiterH * 9073709119482640391U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15423680889126750876U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6087310684583331882U;
            aOrbiterA = RotL64((aOrbiterA * 8964465129744898619U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5420955876411796789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14166807419730848032U;
            aOrbiterE = RotL64((aOrbiterE * 442659738632823751U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8118312450347026824U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4253043584558403086U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5651748455190536467U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 8810774678371762700U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12218479555589447835U;
            aOrbiterC = RotL64((aOrbiterC * 11026364205248516355U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11389930523582876358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16334420553471379915U;
            aOrbiterJ = RotL64((aOrbiterJ * 13830132212033904777U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18201289372553710279U) + RotL64(aNonceWordB, 61U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7196540389657785361U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13058135202554889791U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2601046573550065116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2243003381737071984U;
            aOrbiterI = RotL64((aOrbiterI * 10518763530499878945U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6058992247656841580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10083863011670540073U;
            aOrbiterK = RotL64((aOrbiterK * 17908394295613117155U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8505005026063156940U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1888427424966603593U) ^ RotL64(aNonceWordE, 54U);
            aOrbiterG = RotL64((aOrbiterG * 18298382581929885653U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 44U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 14U)) + aOrbiterA) + RotL64(aNonceWordD, 31U)) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aNonceWordC, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 60U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 52U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordF, 34U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29451U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 30714U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordA, 42U)) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31914U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30693U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 57U)) + 1042610313571524121U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 50U)) + 3505725321008825582U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 29U)) + 12584654563843782991U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 41U)) + 6645399144515770935U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 17U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 3608978423753715584U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 8089198857670370983U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 37U)) + 15207251813516399879U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 9579268660105824516U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 5U)) + 16055044469473802812U) + RotL64(aNonceWordD, 46U);
            aOrbiterC = (aWandererD + RotL64(aPrevious, 10U)) + 583811872609805949U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 7027491967970873942U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18256061823189677508U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12708429127816136937U;
            aOrbiterJ = RotL64((aOrbiterJ * 12593886633108075321U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12169216645156306078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16109994660203297503U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4234704064165718913U;
            aOrbiterH = RotL64((aOrbiterH * 730085881474787681U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14119541943554602878U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8777769004811352951U;
            aOrbiterA = RotL64((aOrbiterA * 2556957257736134223U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15642663488392549609U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11594468530833278624U;
            aOrbiterI = RotL64((aOrbiterI * 6639306656361601143U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7365350535791499871U) + RotL64(aNonceWordF, 49U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5965170981970155956U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1898702752753066851U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9115232101451815522U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9433983580038990072U;
            aOrbiterC = RotL64((aOrbiterC * 1951249217843992179U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8810565477444156140U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12081286530401844859U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1991383259486140229U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7498045374283306625U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13095973566401200720U;
            aOrbiterG = RotL64((aOrbiterG * 2657451581036351987U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18205793828042507364U) + RotL64(aNonceWordB, 25U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3339020890428651569U;
            aOrbiterE = RotL64((aOrbiterE * 10195916881103252701U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16957913958369950483U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1042610313571524121U;
            aOrbiterK = RotL64((aOrbiterK * 11206619213970727629U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceWordH, 19U));
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterB, 34U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + RotL64(aNonceWordE, 15U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterC, 26U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_FootBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB2D4B3628BA3E1CFULL + 0xB5AE1C94E9007BFDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x805DCAC8C63C210FULL + 0xD12B3989EE7A0CEBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA809EF248A7FADCBULL + 0xEF3CA5A719618B4BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE16F1170EE5AB6E5ULL + 0xBD397FE0A0BE50AFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC722C9B3AE7D4603ULL + 0xCDC95D24ADE24BAAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA788136C41A2D97DULL + 0xE523759180BFAB50ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x91D0C11E36D7E2EFULL + 0xA04CAAEA9DFF3124ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x85BBA54332A4B929ULL + 0x9C10690F86942C39ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordB, 6U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4583U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 52U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5442U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1742U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 13U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 1297415699043177788U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 5U)) + 17583786534509260153U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 27U)) + 643197858925708798U) + RotL64(aNonceWordE, 14U);
            aOrbiterA = ((aWandererE + RotL64(aCross, 14U)) + RotL64(aCarry, 27U)) + 5062653766915694874U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 7034273638367180511U;
            aOrbiterD = (aWandererK + RotL64(aCross, 53U)) + 2026909726972916996U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 21U)) + 2785690475553211646U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterK = (aWandererI + RotL64(aScatter, 57U)) + 2910341716302991892U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 2834181605200829791U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 60U)) + 13323052600571281928U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 37U)) + 10434901530315760460U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 247903955625194782U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5196515747387257163U;
            aOrbiterG = RotL64((aOrbiterG * 1799024689023272275U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7196305682377987476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14777739876892587484U;
            aOrbiterD = RotL64((aOrbiterD * 95220583948241581U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10609060796540136671U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8386027207212484155U;
            aOrbiterI = RotL64((aOrbiterI * 4855610536246556893U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 729659744301903424U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordG, 49U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2350564261412606157U;
            aOrbiterA = RotL64((aOrbiterA * 16713856782349084977U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16611987556673864177U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4654808490980989596U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8189569777087686263U;
            aOrbiterE = RotL64((aOrbiterE * 17278657566389299577U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10932857495004451792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1833880112534916813U;
            aOrbiterF = RotL64((aOrbiterF * 8004341577533825681U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13100236350175516423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2773759534195186313U;
            aOrbiterH = RotL64((aOrbiterH * 3194954066097323161U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13963126688973399221U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1464529855671190406U;
            aOrbiterJ = RotL64((aOrbiterJ * 6129954747502059213U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9489842625026216815U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17806120432918490594U;
            aOrbiterK = RotL64((aOrbiterK * 349307975773661379U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13833297268854563081U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1297415699043177788U) ^ RotL64(aNonceWordF, 9U);
            aOrbiterB = RotL64((aOrbiterB * 4818542043777342249U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 26U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 34U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aNonceWordC, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterE, 18U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordF, 30U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9009U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 5990U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 41U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8175U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 10091U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 3U)) + 6069475454765660321U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 20U)) + 11483704742497268068U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 41U)) + 11055697447388986418U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 10897095046039997004U) + RotL64(aNonceWordH, 51U);
            aOrbiterI = (aWandererJ + RotL64(aScatter, 13U)) + 4731637118230457840U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 35U)) + 13855839187084986751U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 5328208115460188239U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 12479538544291412985U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 27U)) + 10740165998792608231U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 37U)) + 6492798157284955373U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 13056825957483891921U) + RotL64(aNonceWordF, 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2068184064919194657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5656302738780746294U;
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11193756120230763294U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17306750816837208999U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12952818800389361804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15380412293642628312U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7706090204767242996U) + RotL64(aNonceWordD, 53U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17819762117328075515U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6481384240915075101U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4836701121865783029U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 754936290510338717U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15510875946573720154U) ^ RotL64(aNonceWordG, 37U);
            aOrbiterH = RotL64((aOrbiterH * 2994718968852184303U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9245381722813944586U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2629847912019726214U;
            aOrbiterJ = RotL64((aOrbiterJ * 6718795794951106961U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3909987749797113773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9277056074757335265U;
            aOrbiterG = RotL64((aOrbiterG * 11580847505996697115U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12577180954515966707U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9144513680789115458U;
            aOrbiterA = RotL64((aOrbiterA * 8880777678193004979U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1544232962956974411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2658275904714859636U;
            aOrbiterC = RotL64((aOrbiterC * 1926083316365175327U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5733515391293514025U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6069475454765660321U;
            aOrbiterD = RotL64((aOrbiterD * 9627476106108146391U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 30U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 50U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordA, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordC, 4U));
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 12U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12994U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 11412U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordB, 43U)) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13078U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14784U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 16802219662864902427U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 19U)) + 14332033461409490629U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 8781794298640286845U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 43U)) + 8459933908074937264U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterE = (aWandererB + RotL64(aScatter, 35U)) + 1883580287986004426U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 38U)) + 17500258188004626118U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 7934811305150872870U;
            aOrbiterH = (aWandererK + RotL64(aCross, 21U)) + 6380363892361098905U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 11U)) + 12623079132626676910U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 3U)) + 10455208121949202703U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + 8805532707916767629U) + RotL64(aNonceWordC, 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9161544391400377699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3501434325829663268U;
            aOrbiterG = RotL64((aOrbiterG * 7933545151293799637U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 651783304096081996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 441505031509930622U;
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1771159983581326424U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15227946417377695989U) ^ RotL64(aNonceWordG, 7U);
            aOrbiterA = RotL64((aOrbiterA * 1563141188972797601U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4153717524193279095U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4404521756523902829U;
            aOrbiterE = RotL64((aOrbiterE * 1410342912973206203U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6231945075461813285U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3864780227164426690U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18031353247480673617U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1509699687948576558U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17316114302489411191U;
            aOrbiterD = RotL64((aOrbiterD * 15490661284980281585U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2250572827340157410U) + RotL64(aNonceWordA, 21U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6403966113144372915U;
            aOrbiterF = RotL64((aOrbiterF * 726441947009132383U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2329903609147403156U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2486330017319455238U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17427461345935191757U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9333421733051210144U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14779925626161889533U;
            aOrbiterC = RotL64((aOrbiterC * 9120486933147706541U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4343688173541745311U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12686722305368397686U;
            aOrbiterI = RotL64((aOrbiterI * 17484250022537912537U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3745163111502795473U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16802219662864902427U;
            aOrbiterJ = RotL64((aOrbiterJ * 4343730534036919417U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 36U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterA, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + (((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + RotL64(aCarry, 3U)) + RotL64(aNonceWordF, 24U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 14U));
            aWandererK = aWandererK + ((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aNonceWordE, 55U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 30U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20091U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 16940U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordD, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17531U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((aIndex + 19957U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 19U)) + 8506388683755208267U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 47U)) + 2179323259055019735U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 5U)) + 3345902531140983016U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 57U)) + 17456139311481306584U;
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 14587864088462311164U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + 13178947246650647057U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 41U)) + 12866578138946916962U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 51U)) + 13098524333655118173U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 24U)) + RotL64(aCarry, 29U)) + 15451329483787541982U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 53U)) + 9494299579678389385U) + RotL64(aNonceWordB, 3U);
            aOrbiterE = (aWandererE + RotL64(aPrevious, 29U)) + 15581954810375490643U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4487042505730624892U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2774455928791636186U) ^ RotL64(aNonceWordA, 7U);
            aOrbiterI = RotL64((aOrbiterI * 15847933919136777451U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12435319582397755819U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10077180055177766823U;
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10391963896910956455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6149237416725301794U;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15673402771629639978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14729117178956592426U;
            aOrbiterF = RotL64((aOrbiterF * 9070464269215820531U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14492001279368870240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6278248084483259952U;
            aOrbiterG = RotL64((aOrbiterG * 16731228350971263873U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15727518866499740411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8652631010810965473U;
            aOrbiterA = RotL64((aOrbiterA * 9508484121620912715U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13660890300188313775U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14699253534935936300U;
            aOrbiterB = RotL64((aOrbiterB * 3978135617259934869U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1621689916308271346U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5651399428852950385U;
            aOrbiterE = RotL64((aOrbiterE * 12220143634120124133U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9833573729127477238U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11171647423058940388U;
            aOrbiterD = RotL64((aOrbiterD * 9692915620701425697U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10346908196429120039U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11972183669378621435U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12364429258926549335U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11063215816236490488U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8506388683755208267U) ^ RotL64(aNonceWordC, 4U);
            aOrbiterJ = RotL64((aOrbiterJ * 11514304191652750181U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterK, 10U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 24U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aNonceWordE, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordH, 61U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordC, 58U)) ^ RotL64(aNonceWordB, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22369U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 23120U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordF, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25948U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 22621U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 10812151398716051703U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 18202551453336003710U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 41U)) + 9434410809101973752U) + RotL64(aNonceWordE, 59U);
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 12955829998028534045U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 21U)) + 12271740641929640181U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 38U)) + RotL64(aCarry, 43U)) + 14009351527014534752U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 35U)) + 4316296955679133450U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + 16473324966997442872U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 3U)) + 15735123324965019802U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 50U)) + 17656375090484080236U) + RotL64(aNonceWordG, 49U);
            aOrbiterG = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 16066325053456055298U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12908968778503516903U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12761433987676836197U;
            aOrbiterK = RotL64((aOrbiterK * 1023329467480907925U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12737513138040664509U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14535795767570998392U) ^ RotL64(aNonceWordB, 35U);
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14370908061811284364U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7001358781208669795U;
            aOrbiterJ = RotL64((aOrbiterJ * 11641248025734015835U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7298578161120090849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10498302152357484629U;
            aOrbiterD = RotL64((aOrbiterD * 13144110412179037175U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11447343228638006767U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 18284143620422655675U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 572862190073605651U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5918253208127360199U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3910541329178205943U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4550654545328228103U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10357053096941367910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5610891501128498748U;
            aOrbiterE = RotL64((aOrbiterE * 8676370811772047449U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9049881176058575811U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6307599924966452216U;
            aOrbiterF = RotL64((aOrbiterF * 5551444450572055895U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17109966783467892046U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11563095828344462249U;
            aOrbiterG = RotL64((aOrbiterG * 15463753739272001875U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3739147427725509014U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5324449517615050698U) ^ RotL64(aNonceWordA, 44U);
            aOrbiterI = RotL64((aOrbiterI * 5926079615575226853U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5706251076252597592U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10812151398716051703U;
            aOrbiterB = RotL64((aOrbiterB * 5666491216813197045U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + RotL64(aNonceWordF, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 54U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 28U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aNonceWordD, 25U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30847U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30567U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28891U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 31454U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 29U)) + 4179952823252098240U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 54U)) + 3745613452332101749U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 2955689793395307176U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 57U)) + 5639060180251322019U) + RotL64(aNonceWordF, 50U);
            aOrbiterA = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 7901969163853586463U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 41U)) + 2242166787816318119U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 5239936443960750064U) + RotL64(aNonceWordC, 21U);
            aOrbiterH = (aWandererI + RotL64(aIngress, 36U)) + 13939136954732185558U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 21U)) + 17058884136712717463U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 18148618660054585941U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 39U)) + 7022023484530327814U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7722084537340095637U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11764151879690934182U;
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16412785901758144708U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9666718667728274824U) ^ RotL64(aNonceWordA, 35U);
            aOrbiterA = RotL64((aOrbiterA * 10865799822751771795U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4307127540152109364U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2457646804702647606U;
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3179394870088602208U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 504977947273774249U) ^ RotL64(aNonceWordD, 19U);
            aOrbiterC = RotL64((aOrbiterC * 16190282058883481551U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16182729401018310837U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7110817020445860609U;
            aOrbiterH = RotL64((aOrbiterH * 13371352088428584087U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12960656706837391973U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7103806893724395904U;
            aOrbiterI = RotL64((aOrbiterI * 14365984439655979791U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1248300178080633527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7195473175424961337U;
            aOrbiterK = RotL64((aOrbiterK * 4633558992739305045U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13007951568242991449U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10296811247653636372U;
            aOrbiterG = RotL64((aOrbiterG * 16469682651380549395U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13922797949001028335U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16773545425463040155U;
            aOrbiterJ = RotL64((aOrbiterJ * 10639282630227832397U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2888887140296117803U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10279517418046269817U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8600355360339461535U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17303373436784809093U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4179952823252098240U;
            aOrbiterD = RotL64((aOrbiterD * 3675754609699406437U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 50U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + RotL64(aNonceWordG, 17U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 18U)) + aOrbiterC) + RotL64(aNonceWordE, 41U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_FootBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBCE114C647049E87ULL + 0xA4D52554FDF2913CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD48D615C77C454DFULL + 0xCFE2C0F8785887E2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEA5EA418D999917DULL + 0xF5C94CE2705F188CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFEC6CA888873CE8DULL + 0xF63B891EE8A37653ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDAD93AF43C640E0FULL + 0x9CD3E4DBA05CA404ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE62556707A406549ULL + 0x992343BA5DC2618FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC7111A793E2CDDABULL + 0xD534304753F10D43ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD97631E2230EF00FULL + 0x9A23C98C4B65C8A9ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordB, 48U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2629U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 231U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 473U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1202U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 13U)) + 13854738573712660276U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 16835460633412286294U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 46U)) + 6785859293758091931U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 43U)) + 126317283127992659U) + RotL64(aNonceWordF, 12U);
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 7568963536291415413U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 21U)) + 12294016745653004819U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 18269588932920281147U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 5872406424994751026U) + RotL64(aNonceWordB, 7U);
            aOrbiterD = (aWandererE + RotL64(aScatter, 48U)) + 7764434758831474129U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 41U)) + 4804168969415573371U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 959601763507651280U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9257644462479293048U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14332699366894494579U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10487012596470786004U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 612729229562321440U;
            aOrbiterK = RotL64((aOrbiterK * 11380387280507726003U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7845523921295625315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12742115479740024747U;
            aOrbiterF = RotL64((aOrbiterF * 15578543510683986421U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10294667720904610944U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14369711143154904567U;
            aOrbiterG = RotL64((aOrbiterG * 13753005602288309379U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10918344717497681894U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18136794828308636957U;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14378638206724886404U) + RotL64(aNonceWordG, 35U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7077588188450008059U;
            aOrbiterD = RotL64((aOrbiterD * 485375960462924335U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8941870012851971932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15242087859620352399U;
            aOrbiterI = RotL64((aOrbiterI * 4963002810455992839U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10395280254030875387U) + RotL64(aNonceWordD, 5U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6826595516076975980U;
            aOrbiterB = RotL64((aOrbiterB * 6198886240333178001U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10407910809564430664U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6368255889263255730U;
            aOrbiterJ = RotL64((aOrbiterJ * 3809496492809859731U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6365669830464231626U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 596785214258266904U;
            aOrbiterH = RotL64((aOrbiterH * 6338109335634389561U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4807438574488830717U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13854738573712660276U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6954368463489446551U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterG, 10U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 26U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aNonceWordE, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 50U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 14U) ^ RotL64(aNonceWordG, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8428U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6427U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordH, 42U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7101U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 8290U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 5510690816044082200U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 39U)) + 15967820875033940530U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 23U)) + 539348720848176221U;
            aOrbiterE = (aWandererD + RotL64(aCross, 19U)) + 15779318183635560817U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 14511058534424187469U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 41U)) + 5811130556873428391U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 35U)) + 1085928476499444025U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 37U)) + 6973335316600768130U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 10747243745475009744U) + RotL64(aNonceWordE, 59U);
            aOrbiterI = (((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 51U)) + 1072260008981349754U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 57U)) + 2018772405352495753U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1092091597048996547U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15103140149542167197U;
            aOrbiterB = RotL64((aOrbiterB * 621856991658027989U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13194619321108681542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16749188603268621850U;
            aOrbiterK = RotL64((aOrbiterK * 9575408950550922039U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7427959503086895166U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9895804051379551393U) ^ RotL64(aNonceWordF, 17U);
            aOrbiterH = RotL64((aOrbiterH * 2701997336201570715U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4526020800679774259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4484850928870048176U;
            aOrbiterC = RotL64((aOrbiterC * 17556987520625677313U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1837404844299040155U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15213208978489570694U;
            aOrbiterG = RotL64((aOrbiterG * 7062740584650274133U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9615231781751396800U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15872192167825648096U;
            aOrbiterF = RotL64((aOrbiterF * 2900526493682580729U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12530672039655918903U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10617836782870315804U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterE = RotL64((aOrbiterE * 9716778004909794973U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 550750725406860977U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3498554352021622907U;
            aOrbiterD = RotL64((aOrbiterD * 9846933294851238495U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4059346317776216057U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14161853870874499023U;
            aOrbiterA = RotL64((aOrbiterA * 8601560894939097781U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4088411647683253905U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9321241420172776158U;
            aOrbiterI = RotL64((aOrbiterI * 4167888281125330225U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8527337525861632945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5510690816044082200U;
            aOrbiterJ = RotL64((aOrbiterJ * 12464836001483233379U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterH, 24U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aNonceWordA, 60U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererA = aWandererA + (((((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 57U)) + RotL64(aNonceWordD, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 10U) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16299U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 14919U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordF, 56U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16218U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12341U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 24U)) + 16424657151168221875U;
            aOrbiterG = (aWandererI + RotL64(aCross, 39U)) + 17150123681886380361U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 57U)) + 16041993588694572757U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 9871185846434828537U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + 11227236398354430757U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 47U)) + 5399325217402192631U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 13U)) + 9248828789282890454U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 9041370494203701062U) + RotL64(aNonceWordH, 51U);
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 14944424084524970764U) + RotL64(aNonceWordB, 40U);
            aOrbiterD = (aWandererA + RotL64(aCross, 47U)) + 5481938174456671041U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 41U)) + 14783648629543752715U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12355573914530445723U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9863991559011968318U;
            aOrbiterE = RotL64((aOrbiterE * 8495251211794343179U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16149688605937250965U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 106041828692026825U;
            aOrbiterI = RotL64((aOrbiterI * 12199934305374582599U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8076098639554567792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11155119311895580013U;
            aOrbiterG = RotL64((aOrbiterG * 1495180896564818647U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6847612160595917702U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16094377920388017367U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4875801863643206333U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13584719866672696684U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13446209321646234607U;
            aOrbiterJ = RotL64((aOrbiterJ * 9945349065094781529U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15829806645369560988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12573767256739062550U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterD = RotL64((aOrbiterD * 5649504278826069077U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3850030870300393809U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11857593987748189858U;
            aOrbiterB = RotL64((aOrbiterB * 15942863910931814193U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5505918410521728373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12949653497121247860U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 90944913639560027U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2448323375614082955U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4386059032042654583U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11730132905525317201U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 108129028178045299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 18292666533864994149U) ^ RotL64(aNonceWordF, 19U);
            aOrbiterK = RotL64((aOrbiterK * 2599590507178673531U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10771402979550786312U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16424657151168221875U;
            aOrbiterH = RotL64((aOrbiterH * 6255743082177474607U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + RotL64(aNonceWordE, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 58U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aNonceWordD, 37U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20881U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 18131U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordH, 14U)) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19792U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 19131U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 5160910997561396461U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 20U)) + 14920764751058512062U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + 6080952401749660022U) + RotL64(aNonceWordC, 55U);
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 17667234330526298627U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 39U)) + 760630072638686756U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 47U)) + 3504157162816997476U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 9489022223422585882U) + RotL64(aNonceWordG, 7U);
            aOrbiterA = (aWandererH + RotL64(aPrevious, 58U)) + 1149898536879968964U;
            aOrbiterE = (aWandererE + RotL64(aCross, 23U)) + 10492284328940025310U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 11U)) + 13213275606286399312U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 43U)) + 10557118912847180413U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15618980209023994776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5268600749854045564U;
            aOrbiterJ = RotL64((aOrbiterJ * 3849660559223919613U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8011552687609649990U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3148133096349525066U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterD = RotL64((aOrbiterD * 5245156554959620007U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12032847944237867285U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14999005703490824673U;
            aOrbiterH = RotL64((aOrbiterH * 6631584955208646049U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5426735969392906710U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3593177531650386729U;
            aOrbiterI = RotL64((aOrbiterI * 12997284886192717043U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1701444719333347373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15928731228196894960U;
            aOrbiterA = RotL64((aOrbiterA * 1919318226904213433U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 5960179456039157036U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 52U);
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5716434224061596483U;
            aOrbiterE = RotL64((aOrbiterE * 3731976564761202801U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2136841536293340279U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12969550408652728526U;
            aOrbiterB = RotL64((aOrbiterB * 7612191387451455137U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3641997570461447114U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4677572491523684525U;
            aOrbiterG = RotL64((aOrbiterG * 2730358077882211651U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2741372094325164504U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4998631511811832690U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10619395395977372695U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6260464862798783617U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16489087874167346533U;
            aOrbiterK = RotL64((aOrbiterK * 11278053967185244867U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7043760915859224327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5160910997561396461U;
            aOrbiterC = RotL64((aOrbiterC * 15260149870590431675U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 60U));
            aWandererK = aWandererK + (((RotL64(aCross, 44U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + RotL64(aNonceWordD, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + ((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + RotL64(aNonceWordF, 3U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 34U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordD, 41U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23828U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 25158U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26240U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25925U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aPrevious, 19U)) + 15188686795415908074U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 52U)) + RotL64(aCarry, 21U)) + 17310049041983079779U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 8246925977992441471U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 21U)) + 8644260919918112781U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 35U)) + 13401663736874819483U) + RotL64(aNonceWordA, 19U);
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 7940358935238314973U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 13278990328548007839U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 37U)) + 11346868298353840706U) + RotL64(aNonceWordG, 41U);
            aOrbiterD = (aWandererJ + RotL64(aScatter, 43U)) + 2374077904806833579U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 30U)) + 6978903378645019166U;
            aOrbiterE = (aWandererC + RotL64(aCross, 23U)) + 11951633297870965212U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17398460995357409673U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1215437945597836770U;
            aOrbiterC = RotL64((aOrbiterC * 9322970054123481621U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1878751468043972239U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5343002808239712390U;
            aOrbiterJ = RotL64((aOrbiterJ * 11878640995447558811U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9884918450053276861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15894599082080422550U;
            aOrbiterF = RotL64((aOrbiterF * 8359936745539546131U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13917339232771145459U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18101134009493720683U;
            aOrbiterH = RotL64((aOrbiterH * 15835859435306756387U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3830086372356903769U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15894394599564584010U;
            aOrbiterG = RotL64((aOrbiterG * 9513921913446609263U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5127590955274245812U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 9410946933309720054U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordE, 42U);
            aOrbiterA = RotL64((aOrbiterA * 14507476989423060561U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15544384157294987085U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 998801294460434123U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterB = RotL64((aOrbiterB * 5946968142746472745U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16442095194965452163U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14294936349037516932U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14655345374740882581U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16680659892463349201U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10921918150041635666U;
            aOrbiterE = RotL64((aOrbiterE * 2908474941036821745U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15350264522133299871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16413848767507968239U;
            aOrbiterK = RotL64((aOrbiterK * 10226942289998651355U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11963105565077056299U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15188686795415908074U;
            aOrbiterI = RotL64((aOrbiterI * 13002484121826831091U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + RotL64(aCarry, 13U)) + RotL64(aNonceWordD, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + RotL64(aNonceWordB, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererD = aWandererD + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 10U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27679U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30743U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29881U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28871U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aIngress, 53U)) + 3973833383430652211U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 39U)) + 5760227042747169187U) + RotL64(aNonceWordD, 31U);
            aOrbiterE = (aWandererI + RotL64(aCross, 57U)) + 4923009065139227286U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 1477807307009107590U;
            aOrbiterK = (aWandererF + RotL64(aCross, 41U)) + 5707194514329007301U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 5340439728375269724U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 20U)) + 17080457898946572387U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + 281559150259472813U) + RotL64(aNonceWordA, 37U);
            aOrbiterD = ((aWandererK + RotL64(aIngress, 37U)) + 16160633048230910560U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 35U)) + 9003989610509592121U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 19U)) + 10579322462808454333U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15059383289528723069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10417647757852880956U;
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14484665027393813330U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12344463053485837974U;
            aOrbiterK = RotL64((aOrbiterK * 5762654194001525041U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5826453246659297805U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12547902286376986223U;
            aOrbiterF = RotL64((aOrbiterF * 2982850000322672789U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9637855144278126174U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 2132744427444501938U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) ^ RotL64(aNonceWordC, 50U);
            aOrbiterC = RotL64((aOrbiterC * 5911587798564836199U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9248933938130311231U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13274297928717090383U;
            aOrbiterG = RotL64((aOrbiterG * 2901398809555237563U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3690262236918560930U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3626005326410800344U;
            aOrbiterD = RotL64((aOrbiterD * 13030443356669355355U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10801089744186148218U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5446653082176311031U;
            aOrbiterI = RotL64((aOrbiterI * 4594267575901248321U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3205541585889107366U) + RotL64(aNonceWordG, 3U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4532327942368884436U;
            aOrbiterJ = RotL64((aOrbiterJ * 16287094987689326229U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9755333481079721632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 722154154363571049U;
            aOrbiterB = RotL64((aOrbiterB * 11002432494248958957U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8071668483354405205U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8770466248803121315U;
            aOrbiterH = RotL64((aOrbiterH * 12780438190628717807U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1999251593502332271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3973833383430652211U;
            aOrbiterA = RotL64((aOrbiterA * 5325244982474631559U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 14U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 54U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aNonceWordE, 39U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 17U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 22U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 40U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_FootBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3978U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 6799U)) & W_KEY1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1729U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5501U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 13924571355038625040U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 52U)) + 16328300979357156658U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 3947771961206012461U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 43U)) + 15428284250569311285U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 21U)) + 5777369485254032486U;
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 16813320300717644673U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 16689933050200758251U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 1856422419049390708U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 39U)) + 18214498743831925517U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18278550878494094923U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 797712062039591797U;
            aOrbiterF = RotL64((aOrbiterF * 7212998747080137625U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15854849439012341347U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 996882939768167773U;
            aOrbiterI = RotL64((aOrbiterI * 14936703950807908575U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3005829974130671692U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8793495343509953906U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14065479348374612031U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7710453029930631112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9511995836117707047U;
            aOrbiterB = RotL64((aOrbiterB * 7250766204781428201U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 670902975693341744U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9045820304668279777U;
            aOrbiterG = RotL64((aOrbiterG * 18373074917532639027U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12417212387607119470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12816983560669985622U;
            aOrbiterE = RotL64((aOrbiterE * 8406003970221889847U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17245432086377688540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6806521945548502014U;
            aOrbiterD = RotL64((aOrbiterD * 11335859481858640857U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 8947500746292365294U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4468060468522895852U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7022481284816599797U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9892975931958803992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3042599331526937836U;
            aOrbiterJ = RotL64((aOrbiterJ * 3308512896171443645U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterC, 18U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aPhaseCWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14382U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 11336U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10320U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 12852U)) & W_KEY1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 11U)) + 12692813903177772178U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 27U)) + 7112496446691277899U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 52U)) + RotL64(aCarry, 27U)) + 2112247138290568813U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 35U)) + 3699421080882855947U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 13761832028354380922U;
            aOrbiterC = (aWandererD + RotL64(aCross, 57U)) + 9243822514887600214U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 39U)) + 6863833516853046129U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 8863897995943098018U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 20U)) + 13346785686701467520U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15309543066305531619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17515530938817919111U;
            aOrbiterE = RotL64((aOrbiterE * 16625193986319048245U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 760493237816424254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7282586354117620860U;
            aOrbiterA = RotL64((aOrbiterA * 2327153408185290635U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4129706068526969105U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7020175432730888755U;
            aOrbiterK = RotL64((aOrbiterK * 10095158356907592239U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9102258982216515596U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10822031305361453690U;
            aOrbiterD = RotL64((aOrbiterD * 2036205056490578491U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12571477440964330246U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8436347026653095199U;
            aOrbiterJ = RotL64((aOrbiterJ * 17930734781213681573U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14214789872073941940U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12915911919403385001U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13161681603528031511U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15443240166233851298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7311369180113240915U;
            aOrbiterI = RotL64((aOrbiterI * 13339195007946889423U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12976516224995960015U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7823308381434556721U;
            aOrbiterC = RotL64((aOrbiterC * 502385172763861451U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4829417661664149137U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16306394751966719700U;
            aOrbiterG = RotL64((aOrbiterG * 5294376579588592157U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterA, 12U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 41U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterH, 28U)) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21417U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 22942U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18540U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16937U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 1297415699043177788U) + aPhaseCOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 5U)) + 17583786534509260153U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 643197858925708798U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 52U)) + 5062653766915694874U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 35U)) + 7034273638367180511U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 2026909726972916996U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 2785690475553211646U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 28U)) + 2910341716302991892U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 2834181605200829791U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13323052600571281928U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10434901530315760460U;
            aOrbiterK = RotL64((aOrbiterK * 2042210188346767033U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 247903955625194782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterJ = RotL64((aOrbiterJ * 1799024689023272275U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7196305682377987476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14777739876892587484U;
            aOrbiterH = RotL64((aOrbiterH * 95220583948241581U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10609060796540136671U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8386027207212484155U;
            aOrbiterI = RotL64((aOrbiterI * 4855610536246556893U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 729659744301903424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16611987556673864177U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1525195188708550503U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10045858602151004553U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4654808490980989596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8189569777087686263U;
            aOrbiterC = RotL64((aOrbiterC * 17278657566389299577U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10932857495004451792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1833880112534916813U;
            aOrbiterD = RotL64((aOrbiterD * 8004341577533825681U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13100236350175516423U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2773759534195186313U;
            aOrbiterE = RotL64((aOrbiterE * 3194954066097323161U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 20U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32575U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27055U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27945U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 30210U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 53U)) + 2915859148137000694U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 46U)) + 210680583721444425U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 6668118118775650387U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 15794200818099010989U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 19U)) + 6565076707062828369U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 23U)) + 16323164497808856719U) + aPhaseCOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 60U)) + 7965435318816716560U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 7390281030573369017U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 35U)) + 2269738866911824875U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9664014216039993873U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18284857398028357633U;
            aOrbiterA = RotL64((aOrbiterA * 8402008251343393737U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 367667619795303009U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7935945060956274197U;
            aOrbiterH = RotL64((aOrbiterH * 5481786693511955209U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16683666162337789540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10655658270998102390U;
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8307037916581540297U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3247742749860703524U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10446792483683818139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16374602929344972364U;
            aOrbiterB = RotL64((aOrbiterB * 12599903932725787599U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2411334498322777183U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1093701164116833765U;
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17018480952982840635U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17348395690080029814U;
            aOrbiterJ = RotL64((aOrbiterJ * 6212591395713433257U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16111252311283623152U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12776492920397785951U;
            aOrbiterG = RotL64((aOrbiterG * 6136009241593081821U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12214538600808144816U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10043377462096783363U;
            aOrbiterD = RotL64((aOrbiterD * 14639467375095185877U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterH, 60U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 41U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 12U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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

void TwistExpander_FootBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6104U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4356U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1313U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 3838U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 8685374557928800912U) + aPhaseDOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 3482312691892161229U) + aPhaseDOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 21U)) + 6948130297389161165U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 12U)) + 5506385663788942690U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 17859982009307397161U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9178488809207094043U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1835479501226057169U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5671861318767342087U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5368101733632614939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9050459666576835422U;
            aOrbiterB = RotL64((aOrbiterB * 10351719549990259551U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9042186993119635078U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17528342580198295025U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14316671546614386775U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6495418332558436882U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8834495762667327342U;
            aOrbiterE = RotL64((aOrbiterE * 10783141541937645995U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4364314196965690905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6357485231062120459U;
            aOrbiterG = RotL64((aOrbiterG * 289429584586504995U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10985U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12519U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13708U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10702U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 12U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 29U)) + 5480870806135400132U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 8034874599430768743U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 4006919843736863767U) + aPhaseDOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 2988069748674633718U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 48U)) + 12347295651973135786U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14152683894431568192U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15765143815254196598U;
            aOrbiterE = RotL64((aOrbiterE * 8948877544291035189U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10473067082331244233U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1089466925383677249U;
            aOrbiterD = RotL64((aOrbiterD * 17334888609179149753U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13215039929873682230U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3957997712247961479U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7631186240013784703U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10023907397941685546U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14593012591254614353U;
            aOrbiterB = RotL64((aOrbiterB * 17111300092082154687U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13353797968154036726U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9259966668512102858U;
            aOrbiterH = RotL64((aOrbiterH * 8326732574268308221U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterD, 34U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16795U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 21005U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18369U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 17810U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 47U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12669015908335980355U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 18U)) + 5438715179868613192U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 13172104448184536460U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 13421421503244744803U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 41U)) + 13327113302994856582U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4671768205922454413U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5355759962838579929U;
            aOrbiterF = RotL64((aOrbiterF * 15080379163499722187U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6691720614265406851U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7063906424700911378U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17091734375516280675U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17328616394166672263U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1542940602574207068U;
            aOrbiterG = RotL64((aOrbiterG * 8981679306319627975U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7203866278803132454U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 993485696233139264U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11609009908810366447U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15659679028507488331U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18321361454094675842U;
            aOrbiterB = RotL64((aOrbiterB * 3966860765622641843U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 38U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aCross, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25189U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 31889U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25241U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 28797U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 21U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 24U)) + 1393781663398437180U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 17414594746688585273U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 2823888497053071250U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 17032631958617884859U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 15222697630461125019U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15737414920751551780U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1357196111055783001U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8225423829221938165U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5315122321649251691U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7893744655508595974U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17863000246694319149U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16721939414324611738U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3444375866323610848U;
            aOrbiterA = RotL64((aOrbiterA * 10874157227815775661U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1825716513674511632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15582066843912467318U;
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15673590949193923915U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13887365046280406413U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3169061375011420121U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_FootBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7793U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 5634U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6486U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 2009U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 5906639480605353429U;
            aOrbiterH = (aWandererK + RotL64(aCross, 51U)) + 5293518570213287605U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 15383185501428521377U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 27U)) + 15364072512743978902U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 36U)) + 4525473357144014271U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 10400911938125603074U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + 16417506293824627550U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2419329331753341815U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14929222427923332069U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11596261802662514979U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16771573504983922586U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1863466450051787622U;
            aOrbiterF = RotL64((aOrbiterF * 2585626547126027053U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12895350137096692415U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3700979086526298327U;
            aOrbiterA = RotL64((aOrbiterA * 10279730254867618193U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1977099106211282426U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6144698304096915742U;
            aOrbiterK = RotL64((aOrbiterK * 5039822990560519609U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3858895556659724975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1283646340363435327U;
            aOrbiterD = RotL64((aOrbiterD * 11622421841377018069U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6240532051889108891U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 757364889381634634U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 943852137901972945U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5272945693977418174U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6850528198786172283U;
            aOrbiterH = RotL64((aOrbiterH * 1966383079897679953U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11323U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13817U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16280U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15802U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aScatter, 58U)) + 17936518874386450467U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 13722737841589910344U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 35U)) + 11774969167948715796U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 21U)) + 3640101505680493777U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 1369495382725650822U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 11827310354654653345U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 47U)) + 186037671377175394U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11428829344234627340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2275016369870029068U;
            aOrbiterD = RotL64((aOrbiterD * 14936799202145280833U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15471646673734798328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12172082573115640145U;
            aOrbiterB = RotL64((aOrbiterB * 9629417882787847753U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6626736341348283154U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12220614992483863623U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8137086205714097487U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13157102324253760215U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4143587482368093601U;
            aOrbiterK = RotL64((aOrbiterK * 5060677690991506895U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11007575246013796426U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11721585930088637162U;
            aOrbiterA = RotL64((aOrbiterA * 15009627907125738519U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5720789204450196217U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3094696226821431648U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4412033981712165541U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14675830108100986773U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9444071495289719645U;
            aOrbiterC = RotL64((aOrbiterC * 10983136361953366557U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 42U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22691U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24253U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18966U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 17398U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 10U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 37U)) + 1142447269198373880U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + 10581460640040336191U) + aPhaseEOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 14703062773878202900U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 19U)) + 15737525756286914746U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 16178774478273186999U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 19U)) + 2514897053906809160U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 27U)) + 13702496607592508464U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18030885275418337965U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5241783876161655984U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10970981186787227937U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2807052676283587925U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8022804576763271327U;
            aOrbiterK = RotL64((aOrbiterK * 11727096043219370577U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15597099852232205860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1538435607932096400U;
            aOrbiterH = RotL64((aOrbiterH * 7900752511710516981U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11147868774413615365U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9325213746830411568U;
            aOrbiterD = RotL64((aOrbiterD * 561819005818948769U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13792300423550555634U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3134856508983945719U;
            aOrbiterJ = RotL64((aOrbiterJ * 4271845067763664863U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8654966018053784882U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8937113935476779267U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4135676350355234788U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11407912615743682678U;
            aOrbiterF = RotL64((aOrbiterF * 2773506587480714695U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 42U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30710U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31293U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27915U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 29784U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 2330952702412094686U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 43U)) + 7820188225935060799U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 9347644591709839145U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 3U)) + 2288624878446846870U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 23U)) + 9358977729492824128U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 51U)) + 1858511275052455039U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 13715478509322292552U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16413396625604260455U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17714322215518432705U;
            aOrbiterK = RotL64((aOrbiterK * 1904184102419934333U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16188315436202861122U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5564445841368207813U;
            aOrbiterG = RotL64((aOrbiterG * 14125834616162835983U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13717068949900594673U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterC = RotL64((aOrbiterC * 17281441046722262917U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5729546141908425670U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4297827922736712074U;
            aOrbiterD = RotL64((aOrbiterD * 13631630436759768885U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 829520109395163673U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11547160328525174295U;
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2907177944512117206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11100346409065275671U;
            aOrbiterE = RotL64((aOrbiterE * 17927994356809011637U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1344592529249949068U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6470438516791143572U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13339390828725370475U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 60U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_FootBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 795U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 2930U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6905U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 3919U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 12615321415808640429U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 15712784676459931207U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 42U)) + 11013335427004930046U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 51U)) + 8298733856304768806U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 6207732959150824216U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9769864876127544038U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10782181918651152563U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16814396040248716483U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5790454015845620939U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15606578025386733803U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7079287329365566355U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5522352539991175304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5993355818572869649U;
            aOrbiterI = RotL64((aOrbiterI * 15221467311057431139U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10864534396947622047U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12090053126235913528U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7250801471645972261U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14191181677234981396U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2258570108233924592U;
            aOrbiterK = RotL64((aOrbiterK * 8307541155393855209U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 36U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 54U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13376U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 13476U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14981U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9848U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 52U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 16424657151168221875U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 17150123681886380361U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 16041993588694572757U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 9871185846434828537U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 11227236398354430757U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5399325217402192631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9248828789282890454U;
            aOrbiterG = RotL64((aOrbiterG * 6733832755349139621U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9041370494203701062U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14944424084524970764U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10283363059424655079U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5481938174456671041U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12355573914530445723U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9863991559011968318U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8495251211794343179U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16149688605937250965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 106041828692026825U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12199934305374582599U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 42U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 4U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17883U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 19127U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16844U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 23923U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 13854738573712660276U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 16835460633412286294U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 6785859293758091931U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 41U)) + 126317283127992659U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 5U)) + 7568963536291415413U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12294016745653004819U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 18269588932920281147U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9031152619272892317U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5872406424994751026U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7764434758831474129U;
            aOrbiterH = RotL64((aOrbiterH * 3772146788188420071U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4804168969415573371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 959601763507651280U;
            aOrbiterC = RotL64((aOrbiterC * 4647396592804833217U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9257644462479293048U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14332699366894494579U;
            aOrbiterI = RotL64((aOrbiterI * 8829304078930625541U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10487012596470786004U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 612729229562321440U;
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 20U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 60U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32748U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27356U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27827U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28378U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 40U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 27U)) + 14249093584376402677U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 8756965951816492264U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 11221139480258176330U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 17218894445564194851U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 19U)) + 8064642692524949490U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5822093203710704646U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3217799620158102238U;
            aOrbiterJ = RotL64((aOrbiterJ * 2806328682494910635U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2613757677892120843U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13647481499551657237U;
            aOrbiterK = RotL64((aOrbiterK * 5517563514031899891U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3545714196663685016U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9735422670576621521U;
            aOrbiterA = RotL64((aOrbiterA * 7276207208162697249U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3911046580637583767U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9315984027042049203U;
            aOrbiterF = RotL64((aOrbiterF * 12568550776487242469U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8926367674641729058U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11035347490524961446U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_FootBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4728U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1608U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2347U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 1003U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 16124889768301047791U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 11912338587186717280U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 8594012868813114354U) + aPhaseGOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 27U)) + 18281043566156682815U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 5U)) + 16853106130200942302U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2611212958619673086U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 18039472325066855180U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10213999643376367785U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14495785571345122046U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4556063793412832418U;
            aOrbiterB = RotL64((aOrbiterB * 13166927543135467627U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14896419970271244358U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 880028529183500036U;
            aOrbiterC = RotL64((aOrbiterC * 14228281807461251361U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2379557167489415783U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11854373946064529806U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 150755294320438887U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1487252775956449964U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12777924204511625545U;
            aOrbiterD = RotL64((aOrbiterD * 1366019527386994789U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 50U)) + aOrbiterC) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11623U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((aIndex + 9299U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8974U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16225U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 39U)) + 785861751704720606U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 15968088718435606299U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 1393976526590347151U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 19U)) + 17240750947292745884U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 4921576136163183137U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3334047873553153032U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15086509978458408698U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2162818176367899893U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 892391205397581998U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2965686403183767521U;
            aOrbiterJ = RotL64((aOrbiterJ * 709160942482770225U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14632215393655706170U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15740589515342377322U;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11131164813943086445U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6988080581278900960U;
            aOrbiterK = RotL64((aOrbiterK * 6412189142344044255U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16021254613117657178U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6183615599897921154U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + aPhaseGWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterI, 54U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24047U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24068U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23447U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19089U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererC + RotL64(aScatter, 28U)) + RotL64(aCarry, 51U)) + 4739486756133131180U) + aPhaseGOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 16089707555501328184U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 15310047330238536453U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 7901411596386834955U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 11U)) + 4357555491060982163U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15667085602825720102U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8520635334382269253U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7348648918661047791U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1772509779231068315U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15336170957886025677U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8628770833489469980U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15469234024247246228U;
            aOrbiterC = RotL64((aOrbiterC * 8905266995119987947U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10796430900884288328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11202284258711214794U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17509491802893182994U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 34U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 56U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30659U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31801U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25736U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 28243U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 3U)) + 6467297102954816305U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 35U)) + 7921154109831114952U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 5701131763215638919U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 43U)) + 10022999076719002684U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 4367135243038982316U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14445846824810383592U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7683697954545773253U;
            aOrbiterG = RotL64((aOrbiterG * 4832124801510084629U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17517006750428030899U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2052484792684025476U;
            aOrbiterC = RotL64((aOrbiterC * 12463117571122469643U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6279463052085808926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 679280153651813684U;
            aOrbiterH = RotL64((aOrbiterH * 3047031560593583881U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2939516520188460569U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1960616434964712325U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15145998415466343039U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12273819390719947361U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5685033154709449397U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aPhaseGWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 44U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_FootBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 133U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 806U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 717U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 79U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 60U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 11U)) + 3612110001869385068U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 41U)) + 16340824141280225936U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 15222338965130765231U) + aPhaseHOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 6649270508107155041U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 3U)) + 768217258655426384U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4481855259658861851U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18318041934562434016U;
            aOrbiterC = RotL64((aOrbiterC * 14913761339765234979U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4212457153804401807U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16143621095636987628U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6576072860505961427U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2095664232866642086U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13679353177869884790U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11582168502846418236U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 135539430034462861U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10451330452898542191U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12951448817640617841U;
            aOrbiterE = RotL64((aOrbiterE * 4141870904192742091U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 30U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10917U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11424U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13783U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 12825U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 29U)) + 6916817163240024692U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 19U)) + 14554930751292077817U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 42U)) + RotL64(aCarry, 51U)) + 1098305064484336101U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 12192821172420471527U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 2435134991707318845U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1896745368738512624U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1114996424222923873U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6248754732325773087U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9839135798371512656U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8037967239603177043U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7848951103759663025U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15185468738487237432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4912098316394854543U;
            aOrbiterI = RotL64((aOrbiterI * 3072785550384399929U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13142688607850380888U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4507379759608945839U;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7299006009652289342U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5390655277207053627U;
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 56U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererB, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21923U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23079U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23464U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 20700U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 7075016829833562104U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 53U)) + 8783765886115517036U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 2996723892384565829U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 39U)) + 9494134707342189476U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 3U)) + 5052642981395679904U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8766787055127962238U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4467211954388738079U;
            aOrbiterF = RotL64((aOrbiterF * 8599295330343804047U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8030255604633658608U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16962408063455702251U;
            aOrbiterK = RotL64((aOrbiterK * 11171737929747471631U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3768222186567699076U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14930990410207899871U;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14179761938395502502U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1879084742719898108U;
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5535012408925981515U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12792553516710295939U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8577530993755159329U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25808U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 24881U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25293U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27480U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 29U)) + (RotL64(aCarry, 60U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 1898718075389870739U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + 5631794889237247403U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 18219714659484524607U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 58U)) + 15419581386225732921U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 9125575431710198210U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12205871520544965505U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7617534300497343422U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10052675719887595625U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18017579105368135814U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10693882161946020042U;
            aOrbiterC = RotL64((aOrbiterC * 2326507900303932855U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11669615701700895306U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11045110212889232165U;
            aOrbiterD = RotL64((aOrbiterD * 5965171269273719849U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18019107802806469913U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12315940560472528716U;
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4899009736070044310U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17412253404253730364U;
            aOrbiterI = RotL64((aOrbiterI * 10791901166391946485U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterD, 28U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
