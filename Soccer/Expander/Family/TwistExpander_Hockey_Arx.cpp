#include "TwistExpander_Hockey_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Hockey_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC1B2363C00C3392DULL + 0xFCD2C0FF3A8881C9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9903D200C9BFD0B3ULL + 0xB9F9093CB8E33302ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE8AC5632336A9769ULL + 0xCF54D211A67C2634ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD682C3F48C40D97DULL + 0x9DE678BBC03BE6E8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE807C737D4FCB0D9ULL + 0xA3F066B8A67A189CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD6C761C710F15C21ULL + 0xE34CE453126B4A49ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA1EE8B583A7DE075ULL + 0x90E9E6453AE7D5C3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x992A9D301D1E5CA1ULL + 0xFBD9BBE47916D608ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD979E10B7133F217ULL + 0xCB5F289DAB5BC181ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC8B0FECA9EE252E1ULL + 0xAAFAA0D62E0AC8B4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBC643C9617797711ULL + 0x8C46F6494383D0A6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA667961650EB4281ULL + 0x8C607E4AD3175223ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDECED1157CEC9037ULL + 0xBD91983C641106FFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x83544C85616F54BBULL + 0xC3CE0D5874C5A4A1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBDC1680223123C57ULL + 0x95DC48150D1E988FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE9FC6597D840D2ADULL + 0xD8DDD1E408F25D1EULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5448U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 1961U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 5129U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1884U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 50U)) + 1393781663398437180U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 17414594746688585273U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 37U)) + 2823888497053071250U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 5U)) + 17032631958617884859U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 43U)) + 15222697630461125019U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 15737414920751551780U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 41U)) + 1357196111055783001U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 35U)) + 5315122321649251691U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 7893744655508595974U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 53U)) + 16721939414324611738U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 3444375866323610848U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1825716513674511632U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15582066843912467318U;
            aOrbiterE = RotL64((aOrbiterE * 12765146555943757373U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15673590949193923915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13887365046280406413U;
            aOrbiterI = RotL64((aOrbiterI * 3169061375011420121U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12730414371734709356U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4819112390640821927U;
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3089925954422937464U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7180179304678622530U;
            aOrbiterB = RotL64((aOrbiterB * 16118051565147747413U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17030269962085008657U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6675917351883004046U;
            aOrbiterH = RotL64((aOrbiterH * 14134335325316949687U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12572022803491077491U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2801421744689267375U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 315045745990934023U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4335148696780313055U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12526298573395110141U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11276803410698178607U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6984239833558496091U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12195433952105336808U;
            aOrbiterJ = RotL64((aOrbiterJ * 8642600547427664495U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6392683095502982341U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18047201953488013325U;
            aOrbiterG = RotL64((aOrbiterG * 16151795290455603489U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15433458942878109208U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1700365768743794306U;
            aOrbiterF = RotL64((aOrbiterF * 16151638348775286903U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10951473638533187729U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1393781663398437180U;
            aOrbiterA = RotL64((aOrbiterA * 2661447713922232789U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 22U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 50U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + (((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 24U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8471U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10106U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 9514U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 7082U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 6521330037475130256U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + 12611880456055428940U) + aNonceWordP;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 21U)) + 12061611078130934708U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 1558112410801116984U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 10509115227850160786U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 3U)) + 4045915960688792066U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 41U)) + 1196541286513243082U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 15564991032722373702U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 4897765238703641798U;
            aOrbiterH = (aWandererC + RotL64(aCross, 24U)) + 12327429514907752733U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 6189189797708711636U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6374267075282018852U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1888758503831341439U;
            aOrbiterG = RotL64((aOrbiterG * 74387714918264257U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14956857689299491800U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14879361107223331957U;
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16086885494838105042U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8069724185844303923U;
            aOrbiterA = RotL64((aOrbiterA * 8878470736758734353U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10854345917959911439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7078313614360332089U;
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15083669236062255011U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 594879695916679116U;
            aOrbiterB = RotL64((aOrbiterB * 9852515479152735283U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6721466068234534523U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 475816724162626782U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4799725182757588407U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4341655358154605899U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15477254302340298586U;
            aOrbiterD = RotL64((aOrbiterD * 13961520225881974201U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10179091913200895775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6310490897546909571U;
            aOrbiterI = RotL64((aOrbiterI * 15080621088825477613U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13462682513035460711U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16739138858084100385U;
            aOrbiterE = RotL64((aOrbiterE * 16386371811268298031U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13608837667062268989U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12902415667552110103U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 16398790854093048017U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16596211634603915761U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6521330037475130256U;
            aOrbiterK = RotL64((aOrbiterK * 631958426544321145U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 60U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 40U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 52U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11519U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 11443U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 15008U)) & S_BLOCK1], 35U) ^ RotL64(pSnow[((aIndex + 16279U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 19U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 40U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + 4970414922752555648U) + aNonceWordM;
            aOrbiterF = ((aWandererC + RotL64(aCross, 57U)) + 9462756592787669327U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 42U)) + RotL64(aCarry, 29U)) + 3948790686662213095U) + aNonceWordD;
            aOrbiterI = (aWandererA + RotL64(aIngress, 11U)) + 14542857212241578311U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 3387479009827029547U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 13U)) + 1411421370057797877U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 21U)) + 16894451466895681236U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 37U)) + 12727136462290223542U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 26U)) + 4625389198191960525U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 3471881403786164913U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 6433115856048534831U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9825592965466157982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1553125767261293088U;
            aOrbiterG = RotL64((aOrbiterG * 411535191177308781U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9951616357109647617U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11231080382787286889U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 14024961994986659187U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13419663264017317947U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4835055642466215566U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17898065852351759171U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14558747666410946768U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterD = RotL64((aOrbiterD * 5681766019285559739U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11910501376797343986U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15074100100781785300U;
            aOrbiterB = RotL64((aOrbiterB * 228976960937473851U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12415377930578091821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14882039078390681802U;
            aOrbiterJ = RotL64((aOrbiterJ * 13855446647753150713U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8094338361713756895U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5478280604704108822U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18062931724700600993U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6977017654546871841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4131602217285988962U;
            aOrbiterI = RotL64((aOrbiterI * 11865422227883712419U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9619228479582032318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13506679497441415586U;
            aOrbiterC = RotL64((aOrbiterC * 5789932662418992799U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10180259475831448124U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4721628773773094283U;
            aOrbiterK = RotL64((aOrbiterK * 10834196399754443771U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7898137727558813688U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4970414922752555648U;
            aOrbiterA = RotL64((aOrbiterA * 6651835668618579479U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 26U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterD, 24U));
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20446U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20776U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21039U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 21578U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 13U)) + 1708250618750199233U) + aNonceWordD;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 12009147777553691142U) + aNonceWordJ;
            aOrbiterI = (aWandererF + RotL64(aCross, 11U)) + 8393982703399156592U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 13U)) + 3247327098356831221U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 21U)) + 3403590155376353737U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 48U)) + 18197244558104735044U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 43U)) + 3096253642040701606U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 39U)) + 8012692688785412179U) + aNonceWordN;
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 17531946907545680745U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 17687695944270225817U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 16147773866007628769U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18244641303026196497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8839160526348897457U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 14268021129087663397U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10599266240854068246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2056723540756216155U;
            aOrbiterA = RotL64((aOrbiterA * 13311591601230386375U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4629354220460621284U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9505955649473204942U;
            aOrbiterB = RotL64((aOrbiterB * 17775391885312236187U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17078153810088721310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9470436761716263000U;
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3305863413630104742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14377172434239576161U;
            aOrbiterC = RotL64((aOrbiterC * 6880176890091033423U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 415687827894226513U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16975319836893760993U;
            aOrbiterH = RotL64((aOrbiterH * 6597144958013976445U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12707054129431596074U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8974182792497231239U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7874658957269462717U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10826131924322955095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4168545139712703154U;
            aOrbiterG = RotL64((aOrbiterG * 10305904857550051705U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4539070253658625193U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3737870219498561326U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13130847633918921393U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11563084648810555040U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7410695535361901473U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7540855656023807389U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6687453696858775037U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1708250618750199233U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13104250803527718135U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 14U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 60U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aCross, 42U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25559U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 25294U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25706U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 26084U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 53U)) + 14624277139785904404U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 6966977309498165611U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 205536824352530761U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 4U)) + RotL64(aCarry, 39U)) + 16629575265808255692U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + 596881340147972746U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 41U)) + 11944412799107412650U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 35U)) + 4615021315668210206U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + 8497630055977606216U) + aNonceWordP;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 20U)) + RotL64(aCarry, 35U)) + 11131601107309336885U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 11U)) + 5935883479805510099U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 15629346719765798174U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5279128339113651273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16778365912440331821U;
            aOrbiterE = RotL64((aOrbiterE * 705421028266789241U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16003052937645491524U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6723226158737614764U;
            aOrbiterJ = RotL64((aOrbiterJ * 16690657664909260573U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9785784358981219543U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10055457337292292710U;
            aOrbiterB = RotL64((aOrbiterB * 17919129940751761111U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11779163108592974175U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1177999477942202687U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13475069421684114643U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9190694445141492214U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15605342360346353457U;
            aOrbiterC = RotL64((aOrbiterC * 14547769706392595647U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14877565450677523492U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1074095623308025684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7884068939436891093U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12803174154216941583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8813356463693637033U;
            aOrbiterF = RotL64((aOrbiterF * 4898237214617563167U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6063909634038581414U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15112191502834052566U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6780741782103553485U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13926459034757240311U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4324555954703597591U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18068922072149745351U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7183063131331255506U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18072787091203847052U;
            aOrbiterI = RotL64((aOrbiterI * 12530396154012878153U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10143386327707219710U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14624277139785904404U;
            aOrbiterD = RotL64((aOrbiterD * 12100828883424264587U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 26U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterB, 21U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31003U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 28064U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32107U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30205U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 47U)) + 13053031069776604052U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 1331396630251085122U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 41U)) + 15879286043343942393U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 23U)) + 13590365633321406830U) + aNonceWordM;
            aOrbiterJ = (aWandererH + RotL64(aCross, 21U)) + 14569235423040242618U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 43U)) + 11397370636618371560U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 29U)) + 3455933494593971847U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 1307153376443784593U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 58U)) + 10688618762584786871U) + aNonceWordG;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 17746248451153600096U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 19U)) + 8512568600755410158U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8950230550112591092U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17790968369472845496U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12583323865381967534U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11243927099685293887U;
            aOrbiterJ = RotL64((aOrbiterJ * 12867003042486433971U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9690268715525781389U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7466066217365074653U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17565696765505320889U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3673528673209875118U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14079103852360952255U;
            aOrbiterI = RotL64((aOrbiterI * 17449228863409999629U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6747836856132250630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5027692924422297153U;
            aOrbiterD = RotL64((aOrbiterD * 2492421273167124437U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11370341866003395776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14013204893442579282U;
            aOrbiterA = RotL64((aOrbiterA * 6602239957997240785U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3436953430697936790U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6399073534839993637U;
            aOrbiterK = RotL64((aOrbiterK * 14186050072610021241U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7054057507823631422U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5752085719673338095U;
            aOrbiterC = RotL64((aOrbiterC * 13252660162476029593U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10628323020010327594U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5029617362660411790U;
            aOrbiterE = RotL64((aOrbiterE * 7230663968894173433U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 6816547880074551571U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6683840259024813282U;
            aOrbiterH = RotL64((aOrbiterH * 13145224557159574541U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5952768353050729617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13053031069776604052U;
            aOrbiterF = RotL64((aOrbiterF * 13710064584055068065U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 6U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 34U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
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

void TwistExpander_Hockey_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDABB94B79ECDEEBBULL + 0xAB798DE5F32A9DC5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC679398320382FAFULL + 0xF20E068D755BC5E2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFC316FD465E42C43ULL + 0x9EB357F6D8D5BCBAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA15BF7F4FF03616BULL + 0xD863103F9248317FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8C19E686689D22B9ULL + 0xC55C6317287B7DC1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE23851C8C587507DULL + 0x8A6543819DD55349ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDDBFBE0C3BBB0A99ULL + 0xEA3EC114EF0D4D16ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF1215B0C7BABF763ULL + 0xED1AFFC14441F6FCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x921C6845D4CD676BULL + 0xD46482811C4C139FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBFA63BF25A07305BULL + 0x9BEE71B10A722F1EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE4C125C5ACFEE807ULL + 0x9709A6C6BEC40DE2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCAB964119F40FFCFULL + 0xB4C09D5BF51C7D04ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE945DD9E73376D57ULL + 0x9000876D37DAA1F7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEA5245AC568DBA43ULL + 0xC5DB27CA9828C901ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8C64C86F36597B21ULL + 0xD24569590112BEE7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x95B6579FA79AF923ULL + 0xC06A78A572B9EB6FULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4709U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2397U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2902U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 1374U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 11U)) + 5041131702736607991U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 37U)) + 9295010428212681446U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 52U)) + RotL64(aCarry, 39U)) + 6235875895358766017U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 57U)) + 2622227802531866918U) + aNonceWordG;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 3888894734834524972U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 241682012014701753U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 41U)) + 15758000422451568079U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 48U)) + 2061944548396976912U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 27U)) + 8177144990755754531U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 554978075608818497U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 250408260560714933U;
            aOrbiterB = RotL64((aOrbiterB * 1295379390497107727U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8700027645880997552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10026130047465480902U;
            aOrbiterH = RotL64((aOrbiterH * 12417270861933696623U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9785843014096326696U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9998582683258411251U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7197956237569462269U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13817734599383455151U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6647207154174092691U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 1578528131687283531U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4957715980509035719U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4994885315786213197U;
            aOrbiterE = RotL64((aOrbiterE * 5676683798126497011U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 5072908311783966503U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5535039946192891515U;
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6594577050344146271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8750154123258714856U;
            aOrbiterJ = RotL64((aOrbiterJ * 6942158167127532003U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3514769314840874873U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8626045200273524281U;
            aOrbiterF = RotL64((aOrbiterF * 4315441782689789689U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8524870284841706517U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1841819423572964209U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 9802481758007234681U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterJ, 48U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + aNonceWordM);
            aWandererH = aWandererH + (((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 54U)) + aOrbiterC) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10296U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 11928U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11058U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15527U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 27U)) + 12849591986267890852U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 14U)) + 8232614804696815750U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 41U)) + 12141567259210877281U) + aNonceWordM;
            aOrbiterB = (aWandererD + RotL64(aIngress, 37U)) + 2928641981037885644U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 980733350554783938U;
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 2683985177993350746U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 14532148403815527355U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 23U)) + 7736296629433884203U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + 10428437770166310549U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18327174144859461029U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2715987179577753597U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12606153309690753435U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17123256945895150555U;
            aOrbiterJ = RotL64((aOrbiterJ * 13469111258504672565U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9057777759026189541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18064460487552100483U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11477276762421684083U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3886501230380184395U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18318375441973295081U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13849305985380030986U;
            aOrbiterH = RotL64((aOrbiterH * 12962140243967824959U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10240409420338313641U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18360586077779529086U;
            aOrbiterA = RotL64((aOrbiterA * 18196875422391501927U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16801797158622424257U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4950305991208513887U;
            aOrbiterB = RotL64((aOrbiterB * 4437082499761416951U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15790878572843321918U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9808781805065559728U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 9394280083159162953U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11974996650410830731U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4955004489435232515U;
            aOrbiterG = RotL64((aOrbiterG * 13301966529515483085U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 46U) + aOrbiterD) + RotL64(aOrbiterK, 48U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20327U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 17580U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20179U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 22625U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 47U)) + 4384716820085860551U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 5U)) + 9715780315942116888U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 15963520052789178632U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 56U)) + 14346700690686392938U) + aNonceWordP;
            aOrbiterC = (aWandererK + RotL64(aIngress, 19U)) + 6005518012489966643U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 2506732930310252119U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 11U)) + 16782163084851775826U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 823673076571076303U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 34U)) + 1634084509064077736U) + aNonceWordF;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1288134975466877686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2998220403162908444U;
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 220430672180734911U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10223923547068528867U;
            aOrbiterE = RotL64((aOrbiterE * 12577370238343872139U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11696469696177647608U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6545430420379636963U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8387163146257553773U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 79691451831797107U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8971444023498649419U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 7148919880477390009U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5624403902454498793U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9468064161002030997U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8243560528100864595U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 4619361544913629805U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12682446273369750704U;
            aOrbiterJ = RotL64((aOrbiterJ * 10879074713156075641U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8728730962617599223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9099675924074253030U;
            aOrbiterK = RotL64((aOrbiterK * 5525644236954497523U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3298303921318288541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5953276499411658358U;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6725769507592688539U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1057277456510215817U;
            aOrbiterF = RotL64((aOrbiterF * 8269412198279297075U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterB, 26U));
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterC, 34U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25737U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 29417U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27573U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 25728U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 58U)) + 3650233661228036955U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + 11607036400067735729U) + aNonceWordA;
            aOrbiterD = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 3899614406903883035U) + aNonceWordP;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 5U)) + 8159156925629965143U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 7148903913967261270U) + aNonceWordD;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 9161665622287517848U;
            aOrbiterK = (aWandererK + RotL64(aCross, 43U)) + 2981535013474059469U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 30U)) + 15812469008200319549U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 35U)) + 14687469489893270300U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6025209349511417063U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12964750392311112676U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12955480283032701843U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6572355895765394340U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3542300121890027981U;
            aOrbiterH = RotL64((aOrbiterH * 11201491178181273935U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6477175684045398359U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1081388388827929314U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 8752188637514143529U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13754328481584620771U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3684673342659575917U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6139923312873039143U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6542045150319909445U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5352102692424060388U;
            aOrbiterE = RotL64((aOrbiterE * 7385758355501860261U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9110100774657340354U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2813273684436269057U;
            aOrbiterI = RotL64((aOrbiterI * 10468759062594022273U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5860425751137403755U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1598622981888978548U;
            aOrbiterG = RotL64((aOrbiterG * 651816500461718345U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14710305692377606725U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16280545617802383463U;
            aOrbiterC = RotL64((aOrbiterC * 12541767206978802063U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6849565243667718750U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12152381961996750050U;
            aOrbiterF = RotL64((aOrbiterF * 11185935780063403807U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 6U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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

void TwistExpander_Hockey_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xED2B0A60F158BC29ULL + 0xD3AB0AEAEDF3BC61ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x96CAAE9A737358B5ULL + 0xBE5F1F5DE6383577ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAE239B3A31759981ULL + 0xCBE640AD107DA3CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9EF1FEC4168A655FULL + 0xA8D69713182FBF11ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDD2F84E7FBCA4BB9ULL + 0xB43BB4FD87C24988ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD24FA24CA3089EBBULL + 0xEEE4BD1C9C3F05A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC49C892508947D29ULL + 0x8E493DE6807BFDC5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF29CF31848E38D87ULL + 0xEC1C7E408CBF8BBBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBD0E7BE4098EDE37ULL + 0xC48F24C4493FD3D1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE3E063FB3B576EE5ULL + 0xFE24D3D5EF4F213CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF72499BEA775EB4FULL + 0x8D506598E25664B6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEF327F2FCF3FAC27ULL + 0xB6F4DAC334EB91B2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE0C965330E4FD8B9ULL + 0x874EA34FDCB93AD0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94DF9C9613EB1B27ULL + 0xAE36ACFB42BFE489ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE6B8B3A57CFFB89FULL + 0xA77F822435827A2AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB49EB3E4E477BDD7ULL + 0xC420F03AB16BEF61ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4496U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((aIndex + 5074U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6938U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1806U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCross, 51U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 2330952702412094686U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 7820188225935060799U) + aNonceWordE;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 21U)) + 9347644591709839145U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 42U)) + RotL64(aCarry, 35U)) + 2288624878446846870U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 3U)) + 9358977729492824128U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1858511275052455039U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13715478509322292552U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 15552121744869003235U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16413396625604260455U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17714322215518432705U;
            aOrbiterB = RotL64((aOrbiterB * 1904184102419934333U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16188315436202861122U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5564445841368207813U;
            aOrbiterH = RotL64((aOrbiterH * 14125834616162835983U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13717068949900594673U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterF = RotL64((aOrbiterF * 17281441046722262917U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5729546141908425670U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4297827922736712074U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterB, 56U)) + RotL64(aCarry, 27U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15776U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10233U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10662U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 9759U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 50U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 5173905450211892891U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 11U)) + 3555542451908039957U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 11559884700283861559U) + aNonceWordH;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 1352524329968738673U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 27U)) + 8914206450420616349U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2251523378498463946U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9541575923299247038U;
            aOrbiterI = RotL64((aOrbiterI * 1066487482799638689U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1239854507907214595U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 17698101462598498934U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 2304948713665996433U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12305566971683256060U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13804545036303215569U;
            aOrbiterJ = RotL64((aOrbiterJ * 10359543704152744971U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10239749097704329264U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4212214906286320308U;
            aOrbiterC = RotL64((aOrbiterC * 3661436621615751071U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12192418916967430783U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17497164630368757887U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16729U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 16747U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17801U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 16656U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 5U)) + 12029393034357490020U) + aNonceWordG;
            aOrbiterH = ((((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 4526754731580694987U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 53U)) + 17060419646421271853U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 53U)) + 4128488893837059683U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 12706894827547160110U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12506324593645825056U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12581344490649250025U;
            aOrbiterC = RotL64((aOrbiterC * 16311882267466003291U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14357032418199130132U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15341977701796331249U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6332369248718076031U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 7086602307544733241U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12398300065276832486U;
            aOrbiterE = RotL64((aOrbiterE * 18157408831225635333U), 39U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 2499745046076601988U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7249361592814001829U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14597139848072319685U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3254456186337366437U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3472973415969046680U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 14583566953969168353U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 6U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 24U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32393U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 27218U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27110U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27698U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 12U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 57U)) + 17454559218352016650U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 44U)) + 8005709669325164803U) + aNonceWordL;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 13393741948412816357U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 3665865624348875553U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 8334142570031883436U) + aNonceWordN;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17226066128706139657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3319093033121522613U;
            aOrbiterE = RotL64((aOrbiterE * 17961784341097933029U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6657535603401588798U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5469746182326331147U;
            aOrbiterI = RotL64((aOrbiterI * 11315450342347794329U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17846791786050221418U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15939541003714896288U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1400351482213119809U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12076763190461077406U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3594038213596405284U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10244002692575821495U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8301291631324464622U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 8460406137668390582U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 9117147929757711595U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 26U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterI, 38U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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

void TwistExpander_Hockey_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x883A6EF6A589B32FULL + 0x994E23F3F6F8CB04ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAF10DA01F95730D1ULL + 0xC9569F80CFB26010ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA28768FE4A34974BULL + 0xF79315E754416759ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBAF705CEE6707E45ULL + 0x83352B910F256B53ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE0C978334A03A401ULL + 0xF404C15CE5C518D2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFDC5D8E8EC7C7525ULL + 0xA70C7217270447D2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9B72DEEA7096714BULL + 0xB65524553BBFDB53ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x91FDFA74F9155975ULL + 0xD448C7B77D570DEEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFC92156F79F2E86BULL + 0x96167CD0F7AB6ED6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFAD136137D4DD70DULL + 0xEA668DC4E293C66DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA1A4EBF5384BB3F9ULL + 0x831DFEC0202F34B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE9422CEBAC4CA68DULL + 0x8292B51CA0AECA2EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF58D55AD74E44F2FULL + 0xE3B51D1567869B6FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDE8F97CC1FD1B87DULL + 0xADBBF0546E733423ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA4B0D069B2DDC2BDULL + 0xC61C9F3B47E0CEFCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEED12FEED17951A9ULL + 0xB411E8566AAC2DBDULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7248U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 5240U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1858U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4584U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 24U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 8506388683755208267U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 2179323259055019735U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 3345902531140983016U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + 17456139311481306584U) + aNonceWordI;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 35U)) + 14587864088462311164U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 60U)) + 13178947246650647057U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 12866578138946916962U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13098524333655118173U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15451329483787541982U;
            aOrbiterF = RotL64((aOrbiterF * 13580376920467431451U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9494299579678389385U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15581954810375490643U;
            aOrbiterC = RotL64((aOrbiterC * 13670002280188424825U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4487042505730624892U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2774455928791636186U;
            aOrbiterB = RotL64((aOrbiterB * 15847933919136777451U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12435319582397755819U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10077180055177766823U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3924363471701748703U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10391963896910956455U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6149237416725301794U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10115917698918612823U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15673402771629639978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14729117178956592426U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14492001279368870240U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6278248084483259952U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + aOrbiterA) + RotL64(aOrbiterB, 4U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13552U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 16142U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14735U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 15460U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 40U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 8988572360732005217U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 17889613225105985335U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + 15563478320513948626U) + aNonceWordD;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 3441351228410524816U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 21U)) + 4425592689451435346U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 12733160231627305928U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aCross, 47U)) + 3574152157304607854U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15167631896729808783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15822667973915417055U;
            aOrbiterJ = RotL64((aOrbiterJ * 5155661648455308057U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17181685481076577637U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9979204751408873468U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8244434774754786565U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1334240485667164762U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9190066751460137016U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15465215829109246336U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2305208282453624419U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10257861974108363283U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16951510027310993926U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11117938943423526901U;
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12461379120662979432U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11719697049048823897U;
            aOrbiterC = RotL64((aOrbiterC * 14880996802304818757U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6843357278142933570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterA = RotL64((aOrbiterA * 9786435451654365097U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 54U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20581U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23509U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17580U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 23649U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 60U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 41U)) + 9446153639709651566U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 20U)) + RotL64(aCarry, 11U)) + 10550762260670758167U) + aNonceWordE;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 7062634922142578383U) + aNonceWordB;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 9178499097812764515U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + 6887103379773525538U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 47U)) + 6239750312052010257U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 35U)) + 17645022614523287959U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3639618183259408272U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3131737117548745095U;
            aOrbiterH = RotL64((aOrbiterH * 6585057380704940395U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7253994382396406554U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15217993711938379561U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12594152227603630033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11250170200489647869U;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12936942656624279424U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10990736056052106149U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7123916809953459187U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12787293075893090465U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17154990205620778151U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 10031369940028159521U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1270827262969060301U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 1517262088236356107U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 830330490987911853U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6828309232554560547U;
            aOrbiterB = RotL64((aOrbiterB * 9742464176986145819U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 12U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31750U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31609U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30167U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27381U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 35U)) + 9435962834163239322U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 41U)) + 10524704356081318973U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 21U)) + 7403401305665208680U) + aNonceWordD;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 7525414805023556493U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 1116686470029070951U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 11U)) + 13257612299137802420U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 48U)) + RotL64(aCarry, 11U)) + 9181543003986598283U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9739384852307501107U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11308402900229016057U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12690186771773188967U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14935167593705272337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7171824007631943535U;
            aOrbiterI = RotL64((aOrbiterI * 4839974427616194289U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8068411284829563567U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12350207458513447578U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 813973258659041895U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17039236343991574134U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18291683592714999632U;
            aOrbiterB = RotL64((aOrbiterB * 7771718817924840713U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6239616841884430968U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10604527977569876774U;
            aOrbiterG = RotL64((aOrbiterG * 6972820410084939637U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1707724300671717658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3802268808625297647U;
            aOrbiterF = RotL64((aOrbiterF * 11296811630387191563U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9423064323799920219U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 242153923313096551U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12117679073775630197U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 38U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordI);
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

void TwistExpander_Hockey_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x87582F6521305D99ULL + 0xA6657688BD9B29ADULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA2EFB7850F5F58EBULL + 0xC91020ED093ABFCBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9EB77EFB8B36007DULL + 0xFCE7A5F9967142EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFF4C75BA760934B7ULL + 0x8BB39A6E36DD9765ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC248D92A2A0D83FFULL + 0x807E5CFB80F5776EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC164F626BDA3466DULL + 0xDCFC5D89EE3ECC18ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1908E7C50AAA367ULL + 0x99626E73DDC9B131ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x89776EDEE998EE0BULL + 0xA6C8F41399DEA602ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x999A53597C180675ULL + 0xF2FFCB3E56559804ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDA2814375C245567ULL + 0xB31AE8E90624493EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDFC844A48D3B4125ULL + 0xCE591B16A14DE655ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE2BCAD661BDFFFEBULL + 0xF55C878E58178AB5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC18E2C0695D0FF1ULL + 0xE4292ECBABA4272AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE462F1B450B3EBE5ULL + 0x9D17998324F1506EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCE51BD5B953D6B0DULL + 0x8F6FFCA740BFE457ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB9EA68A853FB52B5ULL + 0x9387664DE7DCBBF2ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7451U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7631U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5523U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5768U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 30U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 439898681482066326U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 17362083676671776094U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + 6418499837265155024U) + aNonceWordO;
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 17262244253027454972U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererF + RotL64(aCross, 4U)) + 2382066162993139503U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 53U)) + 14345808395587174135U) + aNonceWordB;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 13U)) + 7534743166385552851U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16994453324688523966U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7079553728544045092U;
            aOrbiterK = RotL64((aOrbiterK * 10104892188895367489U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3562822704508440641U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13990892681975857821U;
            aOrbiterJ = RotL64((aOrbiterJ * 8352929306654078795U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 1796728922368577238U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6605161260520067178U;
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13994083795942328918U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6144523182899107711U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4153879991344611283U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12247462325297436642U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1065809332002012789U;
            aOrbiterE = RotL64((aOrbiterE * 5496601177032953251U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10147919864511540753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17138553441127273354U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5773875596275267871U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2653924016109573974U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6254416952351699582U;
            aOrbiterG = RotL64((aOrbiterG * 12756861659704947257U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterK, 22U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11219U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14478U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13581U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10350U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 11U)) + 2974056819475622600U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 7345051759236356098U) + aNonceWordO;
            aOrbiterG = (aWandererF + RotL64(aIngress, 34U)) + 12738468816846628882U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 7694520596043297922U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 5530753590015084774U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 23U)) + 3776309161718383105U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 51U)) + 784780304358106404U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8999942326995036509U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5194986506064092779U;
            aOrbiterG = RotL64((aOrbiterG * 15070787038006135963U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7920040007459652762U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11311997270710107937U;
            aOrbiterA = RotL64((aOrbiterA * 6227571709361790209U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5365231114813547251U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 2735881715888325759U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2358235238039571072U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 18059414891616491807U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17150786106857185467U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14526050556461782864U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6937282036603272474U;
            aOrbiterB = RotL64((aOrbiterB * 14954512365270028029U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10105832250694931310U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3884223553012098137U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 16340956813003906195U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10385284339549648087U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1257633893341505930U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 2669950791270500977U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 58U));
            aWandererH = aWandererH + ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19222U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 19430U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18355U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18847U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 12690502671561165478U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 27U)) + 17519943923428102801U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 41U)) + 10705515807975331385U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 16586447272278538179U) + aNonceWordO;
            aOrbiterE = ((aWandererH + RotL64(aCross, 53U)) + 8006560996840971798U) + aNonceWordC;
            aOrbiterF = (aWandererG + RotL64(aScatter, 47U)) + 12928600185788857701U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 14240723153798267172U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8636219177994872072U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7586790235186467512U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052686382507614169U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1103807034179512424U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7547526530239498693U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 3360295583636013509U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8380239679344786397U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5690809173787433519U;
            aOrbiterC = RotL64((aOrbiterC * 5354724308093372953U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8390902801141804609U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3507306189192059486U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18336280496510253103U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 6190745292098482871U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8065418693975056902U;
            aOrbiterE = RotL64((aOrbiterE * 6414621418430102589U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12111755051718111803U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7605877769709909297U;
            aOrbiterF = RotL64((aOrbiterF * 17525248694315944599U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5969794501112646237U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5127559299360591476U;
            aOrbiterD = RotL64((aOrbiterD * 4521563633438853069U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 20U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29380U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31035U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32503U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((aIndex + 29700U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 19U)) + 10336802574069791273U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 169025388197058936U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 6541354188379168846U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 16223920526599306104U) + aNonceWordP;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 13U)) + 12756613707692514808U) + aNonceWordK;
            aOrbiterA = (aWandererF + RotL64(aIngress, 50U)) + 5082475548176484035U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 27U)) + 4907435526952698526U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14236627073831834337U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11502511046130497584U;
            aOrbiterJ = RotL64((aOrbiterJ * 3460330807286625917U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3679044835550219497U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8631695922983532915U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10582608424233200966U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10449735026385340313U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4628253464169957835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17664454668473204465U;
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3798386391743884889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9816600392407327227U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16781971616348376878U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 4U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
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

void TwistExpander_Hockey_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC760C078501E779BULL + 0xC2B33CE91B6290D5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAA4634207E7765F5ULL + 0x99222AFB03BDE412ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC47BE9C9A55CE629ULL + 0xB4760F7E640B7628ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBAA6F4C24983241DULL + 0xBA0BBA8B0AE9221FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDD2F1409390402D9ULL + 0xAEBF3DDB6FECCC1BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB5A36660DBB7B075ULL + 0x8A378A48705C78CAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE7F43FFE8ED570BFULL + 0xED09D8FA727F9BFFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9F12814D36274CFFULL + 0xFAD2DEED8ED7C6BAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9939EEC45C2008B7ULL + 0x85A230DBF3464115ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD9C17A3AA20FF299ULL + 0xBB1D1FC3542F31BBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB14AAF54197140EDULL + 0xF0451F6E037D9E4AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC377CC4AB16C76A1ULL + 0x901A5676CD53732FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDC133A1CE26E826DULL + 0xD4B0B00EF4D11B7DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFEC2FFB1FD43F7BDULL + 0xA5914E7D3B2EE535ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x826280050E3AE8D7ULL + 0xF67135C7A51E75A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDDE3D2C2BE9EEFFFULL + 0xE35852FB05F16B5CULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7393U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 3327U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2570U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 2020U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 8988572360732005217U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 17889613225105985335U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 15563478320513948626U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 11U)) + 3441351228410524816U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 41U)) + 4425592689451435346U) + aNonceWordD;
            aOrbiterH = (aWandererB + RotL64(aCross, 51U)) + 12733160231627305928U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 3574152157304607854U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 57U)) + 15167631896729808783U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 15822667973915417055U) + aNonceWordC;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 14U)) + 17181685481076577637U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 29U)) + 9979204751408873468U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1334240485667164762U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9190066751460137016U;
            aOrbiterG = RotL64((aOrbiterG * 14585141844653660363U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15465215829109246336U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2305208282453624419U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10257861974108363283U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16951510027310993926U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11117938943423526901U;
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12461379120662979432U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11719697049048823897U;
            aOrbiterC = RotL64((aOrbiterC * 14880996802304818757U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6843357278142933570U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12727898578324702374U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9786435451654365097U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18127999660067652233U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11754709060558683082U;
            aOrbiterJ = RotL64((aOrbiterJ * 12798744012150745847U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16940151146420516184U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12924950783056761895U;
            aOrbiterI = RotL64((aOrbiterI * 8898170377271926745U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14829713915929878471U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 840466047621042565U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 10748511630509529489U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11469637840333471085U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5561780312837795893U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11935079844970978957U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1059834104159730610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10122108814456766430U;
            aOrbiterK = RotL64((aOrbiterK * 2184693583782179921U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14857099570072635006U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8988572360732005217U;
            aOrbiterE = RotL64((aOrbiterE * 14409836741925393077U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + RotL64(aOrbiterB, 26U)) + aOrbiterK) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterB, 34U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12336U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11344U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9475U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 12386U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aPrevious, 42U)) + 14214886793361825363U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 17267959031078766320U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aCross, 29U)) + 16436067429484887644U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 57U)) + 9885951769332633820U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 12971711341813893304U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 5U)) + 199970353398450154U) + aNonceWordK;
            aOrbiterD = (aWandererI + RotL64(aIngress, 13U)) + 1237341696444162094U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 21U)) + 7991128854417613360U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 11U)) + 14809029847149045833U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 2559509556915775947U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 48U)) + 14336829730147834160U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8853631886733610440U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13346159398673246914U;
            aOrbiterE = RotL64((aOrbiterE * 13660497151446983393U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12121095718571872976U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16239781125815589804U;
            aOrbiterH = RotL64((aOrbiterH * 5157009090454962231U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9051377033794324106U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13805815136723461780U;
            aOrbiterC = RotL64((aOrbiterC * 571129481747181357U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14849157800322754413U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18116651528452542634U;
            aOrbiterD = RotL64((aOrbiterD * 3638480428016835537U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4105057226952948599U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5911714320560994391U;
            aOrbiterJ = RotL64((aOrbiterJ * 1796514171654961389U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4439149331729987587U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10278532228230163632U;
            aOrbiterK = RotL64((aOrbiterK * 17428224919864716517U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2342456582668741750U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2360578572554664800U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1108428466956691925U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12132934875391401246U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 17213278726790245812U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 11904899990681410419U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7994340481560109811U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13735851271080138255U;
            aOrbiterF = RotL64((aOrbiterF * 12387076892129731557U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6682417543888875268U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15642799286975840550U;
            aOrbiterA = RotL64((aOrbiterA * 7861250716882028053U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9839299346094784067U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14214886793361825363U;
            aOrbiterG = RotL64((aOrbiterG * 2103132743364916037U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 58U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererH = aWandererH + (((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20584U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 21905U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17188U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 20045U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 21U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 29U)) + 14499676118633326000U) + aNonceWordC;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 17191273593018552288U) + aNonceWordH;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 13U)) + 4085176294948097737U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 11112671474158908186U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 26U)) + 8745787969012266485U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 39U)) + 18074049663777707948U;
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 2543758649719164688U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 35U)) + 4659584749412700523U) + aNonceWordI;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 974639159259871273U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 53U)) + 9211220687971081987U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 20U)) + 8567024626862182714U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5803002132294840900U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11968489432878148467U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 9470807228394903442U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1692347973120388469U;
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16510815732690193145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 755159406833096510U;
            aOrbiterI = RotL64((aOrbiterI * 14091736464659561165U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1518824876475937620U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 701225390867330446U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8425976693733003889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7182176375442410367U;
            aOrbiterA = RotL64((aOrbiterA * 8860605703761731859U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4546566785167467924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2593340999038753749U;
            aOrbiterE = RotL64((aOrbiterE * 10152461487764567563U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9756331608356622299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5511625814747641978U;
            aOrbiterH = RotL64((aOrbiterH * 4806076157539829529U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8694400787420160733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12648969491371382682U;
            aOrbiterG = RotL64((aOrbiterG * 5346585704222643759U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15261238546696118531U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14236129054778329471U;
            aOrbiterD = RotL64((aOrbiterD * 11789581469516267749U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16251500056378064213U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 790320176607605195U;
            aOrbiterK = RotL64((aOrbiterK * 15706130623435648555U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17114773669444878655U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14499676118633326000U;
            aOrbiterC = RotL64((aOrbiterC * 8095707555083587081U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + ((RotL64(aCross, 54U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + aNonceWordB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterC, 48U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterH, 6U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32551U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32733U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28704U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 30698U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 11U)) + 3550722402315312207U) + aNonceWordD;
            aOrbiterE = (aWandererI + RotL64(aScatter, 3U)) + 16724184551669522754U;
            aOrbiterD = (aWandererA + RotL64(aCross, 53U)) + 981751330116773021U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 39U)) + 7891159229704944868U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 13618396711464799841U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 50U)) + RotL64(aCarry, 41U)) + 5969291018449003648U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 23U)) + 14595540413313640042U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 3287990436916111762U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 29U)) + 12534369400200483704U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 27U)) + 2277312067930392274U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 58U)) + 10026320559261334353U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11258082063135659551U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1445958517675746990U;
            aOrbiterD = RotL64((aOrbiterD * 10062265337488757971U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1011298251290970844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9966279022928268335U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10285993486057704393U;
            aOrbiterA = RotL64((aOrbiterA * 15965714363201157535U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16005362468813966136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 223843444699390781U;
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18178876294968532775U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12490136112181806806U;
            aOrbiterI = RotL64((aOrbiterI * 16380841616662993709U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8775696166557913635U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16464340319444310842U;
            aOrbiterH = RotL64((aOrbiterH * 18111632334728200721U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6296039992673546227U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7152939277656436037U;
            aOrbiterF = RotL64((aOrbiterF * 15183918431501487319U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14066791413416223271U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5026743227399908016U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5891343232759075675U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12923870516588764609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2509970166609982397U;
            aOrbiterB = RotL64((aOrbiterB * 10708677957633925007U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15155802288437422950U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15615656627428205711U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6199439196177598589U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17233751123865498186U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3550722402315312207U;
            aOrbiterG = RotL64((aOrbiterG * 2247546626523919155U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 30U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 22U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordL);
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

void TwistExpander_Hockey_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x90C86A3078259427ULL + 0xDC2E686E36589FB5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC94107C04BD7E06DULL + 0x99A3D274B5B4EE77ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCE4B3C2A6D725947ULL + 0xE2D3CC259CE1803AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDA701BE939FBD41BULL + 0x90A3ECB179EE88C2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE5DC9D77D493B29ULL + 0xE41A63007ACEF9DBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x97CD88DC9364ACA9ULL + 0xF34F3387181A0288ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x83755B8F037852ABULL + 0xE58450BFCD0D2124ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC0DE92D692164F79ULL + 0xF5CADD70CC5CE2BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9F6AD53001BB57B1ULL + 0xC2FA220BF88DDA25ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA82E60EDD801E2FFULL + 0xD31F13FC8FA15E68ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBBC4CF41C5CB225DULL + 0xAE370448E206C5A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB505A30ADE17F4CBULL + 0xC0020A7CF2968370ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x986E170330241317ULL + 0xCE73E1B33B9000DDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB74656CE61482EDDULL + 0xCD71265336FBD054ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD548C4FACB1229A9ULL + 0x878CA03385FAF178ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAA6565757F9088F7ULL + 0xCC9A2043F7FF52ADULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5292U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 4007U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1967U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 219U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 11U)) + 13583136155674166402U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 5U)) + 12830472187484919497U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 3U)) + 18081197909484522509U) + aNonceWordM;
            aOrbiterI = (aWandererF + RotL64(aScatter, 43U)) + 8680634051297891550U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 13939998767458656823U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 1795730579103692594U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 24U)) + 17369751719734069999U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 39U)) + 224769585901248068U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 57U)) + 4133547085925268180U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7022512056309567391U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10319484359046945495U;
            aOrbiterA = RotL64((aOrbiterA * 3400140531307001933U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10483878349412282069U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6481381149199985736U;
            aOrbiterH = RotL64((aOrbiterH * 9701719367082506253U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13721077228796934509U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9704818014314175007U;
            aOrbiterE = RotL64((aOrbiterE * 760445624027740287U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6253040047758584339U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16890211690273641226U;
            aOrbiterC = RotL64((aOrbiterC * 5622534399866057841U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6216227831265032436U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 2023609047004658739U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 3252332895698310147U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9201669637050388263U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5106927540934338576U;
            aOrbiterI = RotL64((aOrbiterI * 6368134569042291431U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10080368957861445998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10784789383436485808U;
            aOrbiterG = RotL64((aOrbiterG * 3794918350254445939U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15426339824951793026U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17637144549368340331U;
            aOrbiterD = RotL64((aOrbiterD * 10971293914614704441U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9941300382181962134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8118046374121322097U;
            aOrbiterJ = RotL64((aOrbiterJ * 8481945819050983127U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 12U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 48U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 18U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererF, 12U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9042U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8239U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7094U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6976U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 20U)) + RotL64(aCarry, 39U)) + 14499676118633326000U) + aNonceWordD;
            aOrbiterG = ((aWandererB + RotL64(aCross, 39U)) + 17191273593018552288U) + aNonceWordG;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 4085176294948097737U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 57U)) + 11112671474158908186U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 35U)) + 8745787969012266485U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 29U)) + 18074049663777707948U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 2543758649719164688U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 5U)) + 4659584749412700523U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 21U)) + 974639159259871273U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9211220687971081987U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8567024626862182714U;
            aOrbiterK = RotL64((aOrbiterK * 7755874089832496393U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5803002132294840900U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11968489432878148467U;
            aOrbiterJ = RotL64((aOrbiterJ * 4501441062617123165U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 9470807228394903442U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1692347973120388469U;
            aOrbiterF = RotL64((aOrbiterF * 17433393164156231575U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16510815732690193145U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 755159406833096510U;
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1518824876475937620U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 701225390867330446U;
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8425976693733003889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7182176375442410367U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8860605703761731859U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4546566785167467924U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2593340999038753749U;
            aOrbiterA = RotL64((aOrbiterA * 10152461487764567563U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9756331608356622299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5511625814747641978U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 4806076157539829529U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8694400787420160733U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12648969491371382682U;
            aOrbiterG = RotL64((aOrbiterG * 5346585704222643759U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterH, 30U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + aNonceWordA);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 42U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13910U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15480U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13236U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15013U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aCross, 41U)) + 11998579547770778580U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 60U)) + 8409465187298704610U) + aNonceWordD;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 5U)) + 3470222286110333500U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 5704486785203069994U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 10334944660253279633U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 7626852700722567477U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 14631310754943209743U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 46U)) + 807160297237854120U) + aNonceWordC;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 19U)) + 5624154783624196107U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4971444394698940423U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6340057638461027062U;
            aOrbiterK = RotL64((aOrbiterK * 12027586111086798629U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12766104026871797746U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5258212525426469978U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9956946981015983939U;
            aOrbiterE = RotL64((aOrbiterE * 8106382657040497669U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10837606223056473999U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 13292864885504191134U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 166087925900318658U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16888086378070246404U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5240855484445974002U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 402652898573422271U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6874866669211571608U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 732890824978127460U;
            aOrbiterJ = RotL64((aOrbiterJ * 3776365957702257453U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5541380495707308058U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17947326584411475765U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10920952349981652899U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 10U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 40U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 58U)) + aOrbiterG) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19011U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20836U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18020U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20063U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 43U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 14U)) + 1557680213571812384U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 43U)) + 7387349725778021121U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 35U)) + 15379264067601586976U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 3730195724576043708U) + aNonceWordD;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 9637070085323827066U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 39U)) + 1170865717363676184U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 53U)) + 2750833653175252030U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 15118992811225568305U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 29U)) + 4974092922102988451U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10625719096296719514U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 855167122475471865U;
            aOrbiterB = RotL64((aOrbiterB * 7441090331293158773U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11322911068958340262U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4334591909425429835U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14263701737208936392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 678723206735649084U;
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15652053114252065230U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1705225940224061401U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3626023093533713579U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6826394665732900206U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11902946775066981141U;
            aOrbiterD = RotL64((aOrbiterD * 18300629262162694137U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9802212958998591310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14001358545610206524U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13172645840788327099U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4299184726135884309U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7288757011999872416U;
            aOrbiterA = RotL64((aOrbiterA * 16806027820468277393U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 233801262480580205U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14208660347238680268U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6299693448313154603U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9217797359740446104U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 18165073197136050838U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11677479094709512887U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 36U));
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23723U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26086U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25536U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22641U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 18U)) + 1898718075389870739U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 35U)) + 5631794889237247403U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 18219714659484524607U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 15419581386225732921U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 9125575431710198210U;
            aOrbiterA = (aWandererB + RotL64(aCross, 56U)) + 12205871520544965505U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 7617534300497343422U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 51U)) + 18017579105368135814U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 27U)) + 10693882161946020042U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11669615701700895306U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11045110212889232165U;
            aOrbiterD = RotL64((aOrbiterD * 5965171269273719849U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18019107802806469913U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12315940560472528716U;
            aOrbiterA = RotL64((aOrbiterA * 4505122470351404065U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4899009736070044310U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17412253404253730364U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4826286251927854181U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4523455921321845084U;
            aOrbiterH = RotL64((aOrbiterH * 14534103906736598099U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4132514462154182215U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7164745605985109269U;
            aOrbiterE = RotL64((aOrbiterE * 14107325508977225261U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6297434295807635654U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8813887638672996646U;
            aOrbiterG = RotL64((aOrbiterG * 17495632530773158201U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11086381278955626084U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5660733992573928887U;
            aOrbiterK = RotL64((aOrbiterK * 11248164458720777889U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14851044686208609882U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12707776386060264479U;
            aOrbiterF = RotL64((aOrbiterF * 4470919091467313071U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 11508023384209716657U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11752973809740920034U;
            aOrbiterB = RotL64((aOrbiterB * 10212754472298834769U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterB, 50U));
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterK, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 11U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 46U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27755U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32532U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27363U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30555U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 29U)) + 4476099022490972343U) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aIngress, 58U)) + 16836423700375760429U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 43U)) + 8850577488928703557U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 53U)) + 7091631824560042743U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 12560498899956759494U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 14U)) + 7797973377112012161U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 19U)) + 6173820673874805794U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 10805025132310245348U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 7139216143268029968U) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8241544862261635722U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4735527016563596150U;
            aOrbiterF = RotL64((aOrbiterF * 6621354217673598381U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5166171126690294033U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11117641762075368393U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4980156869201219393U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6312932356458415421U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1304139291184508668U;
            aOrbiterC = RotL64((aOrbiterC * 90744653170922319U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10085025354842771067U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16745854428789531080U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1945983905747274355U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2497187958708890337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16069701876646548995U;
            aOrbiterD = RotL64((aOrbiterD * 16606039730973709495U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17242004368025978091U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12334315722243232121U;
            aOrbiterI = RotL64((aOrbiterI * 16528598396696346719U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8007042082518126895U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5665686359038811484U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 11289316305875751813U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3913477186958600592U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16918984318564170343U;
            aOrbiterA = RotL64((aOrbiterA * 5128293326494417281U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10227611546502931418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7187623463085447228U;
            aOrbiterH = RotL64((aOrbiterH * 8479839369622163181U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 40U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 38U) + aOrbiterG) + RotL64(aOrbiterD, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC59164FFDC77882FULL + 0xA47703F0B7EE2360ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA0F41BD89E7858DBULL + 0xF1E0B3EFB9F07F42ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC01463BF88A8A94BULL + 0x8AF10A2A26017565ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE37E4EE382B3EF3DULL + 0xAB66A59B404FF292ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF68FA6D1DCF0AC6DULL + 0xE93F070E5F805C9EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x88423050F3DCFBFDULL + 0x8F230CDE26BA6442ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE47BAB0B2611996DULL + 0xD16C1251EE7A63DAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8596708A7F85CB59ULL + 0xF5A4FC25F5E94C2EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC751182FA98CDF75ULL + 0xA28FAE5EF517A918ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC37BBABC8D647709ULL + 0x95664A32CD34765FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC2E44FF0230DA479ULL + 0xBB5A2EA094334B73ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDFEB9947D0A180F1ULL + 0xA27BAADD35C7C08EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF00BF1715A9C943DULL + 0xF9DBA10C9D55CC26ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAC05A2E1C7976E61ULL + 0xA08AD188D9EB57B0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF33BEBEC4EDAB797ULL + 0xCDE9DA020C34A54CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x83C8342610175029ULL + 0xFDC9EC3085664731ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 383U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 1284U)) & W_KEY1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5355U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5384U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 9751314027302668907U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 42U)) + 12175450995523107056U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 51U)) + 17519694958730119552U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 9093525527925682263U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 35U)) + 3713831321786810138U) + aPhaseAOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 10108355209191835040U) + aNonceWordD;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 12956307447311314768U) + aPhaseAOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1904298513945877359U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4658049993308574460U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10482422152074338611U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9826333658248851902U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12058666914724365134U;
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2516574707110528099U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13335308331049750235U;
            aOrbiterF = RotL64((aOrbiterF * 5880227828760598587U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8230749255538495304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12387639130570188998U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8459259798142872020U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8001346480955847013U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 16083784052002800300U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1957284290736468379U;
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7349538179311335863U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16395170077006105258U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 4230485452156662763U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aNonceWordC) + aPhaseAWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 54U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9264U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 8518U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9086U)) & W_KEY1], 34U) ^ RotL64(aKeyRowReadB[((aIndex + 8267U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 34U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 37U)) + 7948891781097675369U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 13928362874228230226U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 43U)) + 10776180542602258926U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 5735115172149470447U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 51U)) + 5353591822981766987U) + aNonceWordN;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 562301708107268570U) + aNonceWordM;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 4U)) + 10467810247578364868U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14541630141152308564U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2350076897065139429U;
            aOrbiterA = RotL64((aOrbiterA * 12222554362482034393U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17519109078651162228U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6061035173339902910U;
            aOrbiterG = RotL64((aOrbiterG * 10021905773432907835U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15654836633731000065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13723521735153718904U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2849680038315532197U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17336102435576647923U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10984689101753586739U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7671010488872356142U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11485114338165600777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8759060657343458985U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11009137869375286581U;
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15792999392743144135U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 6180808423175992479U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 13681230339693676907U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 12U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererF = aWandererF + (((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 19U)) + aNonceWordE) + aPhaseAWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14695U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 13130U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14634U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11210U)) & W_KEY1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 27U)) + 6243113109470883144U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 19U)) + 3891552123999605832U) + aNonceWordG;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 13U)) + 8758797898587019128U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 57U)) + 1005891374086408851U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 3U)) + 3713426782180050764U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 18358143862391573534U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 17504394029693712404U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 5312729289027417014U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2560873623431186029U;
            aOrbiterA = RotL64((aOrbiterA * 16843728573219210173U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16309322822806704211U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10195513918020652600U;
            aOrbiterH = RotL64((aOrbiterH * 14569219741824123715U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2552116263258744287U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7732784879810980089U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15041929399477790999U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16499127570665381507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10890036715535519036U;
            aOrbiterD = RotL64((aOrbiterD * 9065115450010475187U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16288944603478791554U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14542766121469312846U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8435383464425875209U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5973595239494084696U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1820492719977197097U;
            aOrbiterJ = RotL64((aOrbiterJ * 16164917159141304405U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10489529555776381736U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6392552206958240484U;
            aOrbiterB = RotL64((aOrbiterB * 11761477994533503307U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 54U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16843U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18892U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19878U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19717U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 47U)) + 6654158889644956636U;
            aOrbiterI = ((((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 9045779659363991870U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 3888897662136993491U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 6882016842864459345U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 3U)) + 15601891715956172291U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererC + RotL64(aIngress, 41U)) + 5176811598629335350U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 60U)) + 12519945150889074325U) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4552583214397603278U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14225482701804864688U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8526052833180466359U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5485298070606280363U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11237713257388094289U;
            aOrbiterB = RotL64((aOrbiterB * 11032429223099413011U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14340345895626142788U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16275167270553643347U;
            aOrbiterI = RotL64((aOrbiterI * 7308578867128951199U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14041860597556520250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1436068974197066343U;
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11483155566419547004U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4608508534724289325U;
            aOrbiterH = RotL64((aOrbiterH * 13461385011638899485U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2389196334288832895U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4062682330273866602U;
            aOrbiterF = RotL64((aOrbiterF * 8787682133271101901U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5655656046585592034U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 7977947821249746880U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 10082104644185964787U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 6U)) + aOrbiterI) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 21U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererK, 36U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23401U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 25481U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26495U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 26956U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 4739486756133131180U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 41U)) + 16089707555501328184U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 15310047330238536453U;
            aOrbiterC = ((((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 57U)) + 7901411596386834955U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 4357555491060982163U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 13U)) + 15667085602825720102U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererI + RotL64(aCross, 27U)) + 8520635334382269253U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1772509779231068315U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15336170957886025677U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10996880551392077399U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8628770833489469980U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15469234024247246228U;
            aOrbiterA = RotL64((aOrbiterA * 8905266995119987947U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10796430900884288328U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10660110397012853289U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9140007610912037461U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11202284258711214794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17509491802893182994U;
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16212572740740103554U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2190030203761579226U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3101886685668871045U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12014337082293041909U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3733531010807001506U;
            aOrbiterJ = RotL64((aOrbiterJ * 5797362244066062299U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7100994963061975529U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17837541162838600258U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 8745987361678166553U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30327U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27429U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29324U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29915U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 47U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 11480359716598965890U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 57U)) + 15431182525482873419U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 11360504974812776707U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + 9292576416573382769U) + aNonceWordJ;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 1549257414531028975U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 30U)) + 5347769463033129317U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 17019199177478377234U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16558106007323125094U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3976182233825939422U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 4392162052317572289U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2889047161195954395U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2241831345026962605U;
            aOrbiterD = RotL64((aOrbiterD * 5757458560979927857U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12850802412140579294U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13541744735436450160U;
            aOrbiterJ = RotL64((aOrbiterJ * 906089290000537439U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2085863085516538212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2969034221711544086U;
            aOrbiterA = RotL64((aOrbiterA * 7768528124408400403U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6482666944512391472U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16969153556875844613U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 9483462388353216219U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5161314086757363678U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5465304381272305847U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2344610773390354017U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 12U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 19U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterH, 37U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Hockey_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB3FC0FE18C4B1657ULL + 0xF140900171493399ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA669430E29E8477FULL + 0xD21D2807AFA1DC0AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF616D29D49057EF5ULL + 0xD7E4A8FEEFED407DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA46AB7797DC0D03BULL + 0xDF7985020FF73FBAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA77D96BB3F74527FULL + 0xCE16003693FB9BCCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xECC1871536E44B9FULL + 0xA700EBBEB83BD3BAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC7AA2ADD11430BB9ULL + 0xEA753BA3240E4FEFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAD7791A393B48B77ULL + 0xD3275733C41C607CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC344C79B124C9D63ULL + 0xB0D0A424AFC32B8FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCD2DED989CE8647BULL + 0x8918F273942B8AFAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8118B552C238B857ULL + 0xC29E8656667972FEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x95C85C16B7AEDE31ULL + 0xC7671071979676ADULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC95B12B37CC77ECDULL + 0xBB81BD67F49AF364ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x90E55EBA4F4062D5ULL + 0xBB3610996B26924EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC5FFE832468C0C3FULL + 0xA8CF06489A346FCDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8FEF3DF67282DE05ULL + 0x8754DA609F59A718ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 423U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4037U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3124U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 388U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + 16124889768301047791U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 11912338587186717280U) + aNonceWordH;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 12U)) + RotL64(aCarry, 5U)) + 8594012868813114354U) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 18281043566156682815U;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 16853106130200942302U) + aPhaseBOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2611212958619673086U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18039472325066855180U;
            aOrbiterB = RotL64((aOrbiterB * 10213999643376367785U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14495785571345122046U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4556063793412832418U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13166927543135467627U), 53U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 14896419970271244358U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 880028529183500036U;
            aOrbiterF = RotL64((aOrbiterF * 14228281807461251361U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 2379557167489415783U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11854373946064529806U;
            aOrbiterC = RotL64((aOrbiterC * 150755294320438887U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1487252775956449964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12777924204511625545U;
            aOrbiterE = RotL64((aOrbiterE * 1366019527386994789U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + (((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterC, 54U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8052U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 10880U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10122U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 10532U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 14823268998003220191U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 15295237288788213847U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 43U)) + 16434853402001133899U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 7555911304407871631U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 13U)) + 14977248264994834620U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9707764144919392380U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1277304385464681529U;
            aOrbiterH = RotL64((aOrbiterH * 2864691650462053463U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3089786220465849395U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3700503853358695085U;
            aOrbiterB = RotL64((aOrbiterB * 2079089949442685421U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3240054112993517371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16897532076915366859U;
            aOrbiterC = RotL64((aOrbiterC * 4120874717534309035U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 18167359289798364307U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8870819278575769863U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9334066154398059075U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15363069206212330251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14858164441499725158U;
            aOrbiterG = RotL64((aOrbiterG * 14931933411393847915U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 30U)) + aOrbiterC) + aNonceWordH) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 22U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aNonceWordF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15950U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 14922U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15995U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16270U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 12131317914288566437U) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aCross, 57U)) + 5672805657999385496U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 3581710244233124197U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 15251296040538489436U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 28U)) + 11295008604679904153U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2230897493419504490U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7109600123297458999U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8267799351136506307U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13119156643107683803U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14755160867807355250U;
            aOrbiterA = RotL64((aOrbiterA * 10007087518844899239U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16829363373287496832U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16981122946707720883U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 5394974422201576627U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8806000776958603317U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 16810923047720876014U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 17872735050219539145U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8129657889554436328U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8653100378491974463U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + aNonceWordM) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 48U);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17171U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17293U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20516U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 18146U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 9888431329297626900U;
            aOrbiterG = (aWandererK + RotL64(aCross, 3U)) + 2937735167534624403U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 17626022970343789617U) + aPhaseBOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 43U)) + 5665660859333693743U) + aNonceWordE;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 1060537034632076669U) + aPhaseBOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 743777763907175800U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5744905970181808845U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 17426701505806885785U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3545351394494002180U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4877547088414106007U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5416792889338547109U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11669378338379598445U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13984945589234919765U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1433097875470903205U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 451996840039906781U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 716415411025451152U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8542286150858297810U;
            aOrbiterE = RotL64((aOrbiterE * 9139015340823332449U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 14U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordN) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25146U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25689U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26428U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 23383U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 14U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 9471546960258473684U) + aPhaseBOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 18050235435948942244U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 3005107102671544641U) + aNonceWordH;
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + 17898396434573801850U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 47U)) + 15071602525497771648U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5780119462702672108U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13301326224151025687U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 2868878978993219351U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18129323022260575961U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1199228670638790709U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1780426336211781025U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1839199978088021020U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4999517042246790165U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8788607633376516299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15143903839930468749U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 12735914889325422675U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16674732686428431869U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aNonceWordO) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 34U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27996U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32604U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30549U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31574U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 12615321415808640429U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 15712784676459931207U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 37U)) + 11013335427004930046U) + aNonceWordL;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 8298733856304768806U) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 21U)) + 6207732959150824216U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9769864876127544038U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 10782181918651152563U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 16814396040248716483U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5790454015845620939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15606578025386733803U;
            aOrbiterD = RotL64((aOrbiterD * 7079287329365566355U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5522352539991175304U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5993355818572869649U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15221467311057431139U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10864534396947622047U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12090053126235913528U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14191181677234981396U) + aNonceWordO;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 2258570108233924592U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 8307541155393855209U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 36U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + (((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Hockey_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEE72028D488195D7ULL + 0xB078E28D43F195F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCEF7D56C33AE5A45ULL + 0x81B73F08CA5E53ABULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD3C86718DF3DE511ULL + 0xBF224FA1A50F9C20ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8A6213D9564027C1ULL + 0xA815C65A7A98CE43ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD9B9359A93B7BCADULL + 0xD6546719541E8D9DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9A5B3D15B323B17FULL + 0xBC3722D59992A734ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA9EB7ECE12D3360FULL + 0xE7851AF4C660BF02ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA956C3E47519D14DULL + 0x8CC970EFFF3DFC50ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBCDA4ADD9AE3A7C7ULL + 0xB51F5D52F8133646ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBD543923DAE996ABULL + 0xD0AAAC2EB761C7C6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDA985550DB3DAE49ULL + 0xF2B7A1F29D0CFA9EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC2557FD7058A3E2FULL + 0xA0D7B1E8BFD11E6DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAEE398DB4DB2444FULL + 0xF696ABC1C8031A4DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF4CA895D044168A5ULL + 0xDEC0670E6F4E7AF8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF3F0B002391648AFULL + 0x9A970EB761203D3FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC0E7B67A5E53EE85ULL + 0xD29FEF5353E5DA0CULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7794U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 1893U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4848U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 2379U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 41U)) + 1364174714924216027U) + aPhaseCOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 13561796874229506613U) + aNonceWordP;
            aOrbiterD = ((aWandererD + RotL64(aCross, 18U)) + 11845572344206238305U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 35U)) + 15762708240326773763U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 51U)) + 1157119665207900473U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 6823546624372055260U) + aNonceWordG;
            aOrbiterI = (aWandererC + RotL64(aCross, 57U)) + 14465564210523945121U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 12U)) + 10667464548080807531U) + aNonceWordE;
            aOrbiterG = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 13445737493224316575U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3009837893785957665U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2886920524111083752U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15308180928967762543U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10886177449328249656U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15067759884678100433U;
            aOrbiterJ = RotL64((aOrbiterJ * 5724566815989860041U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18307930462682331536U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8791864377579255801U;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 805797468642992351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5743305867058244964U;
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17102025528234481273U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1841579177327486899U;
            aOrbiterB = RotL64((aOrbiterB * 3841603385577825265U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2189493507896508972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18209567010094914374U;
            aOrbiterE = RotL64((aOrbiterE * 3737080408976852351U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6697069234216868330U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 927471474577415372U;
            aOrbiterI = RotL64((aOrbiterI * 10680760991009199309U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13155854301197725408U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1014625081915435892U;
            aOrbiterA = RotL64((aOrbiterA * 11592754232949990435U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12697209921410914931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11555096613655648647U;
            aOrbiterK = RotL64((aOrbiterK * 4598821388864997089U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 52U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 28U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10915U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 11663U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15612U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11999U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 12U)) + 6771552164800695068U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 12131763371571322040U) + aPhaseCOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 3326182381395522013U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 12288775097697156383U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 43U)) + 5195948373449796741U) + aNonceWordD;
            aOrbiterD = (aWandererI + RotL64(aScatter, 58U)) + 14404044002250137144U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 47U)) + 11142382920035825426U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 3U)) + 2967149520256475485U) + aNonceWordP;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 51U)) + 1470907369577818097U) + aPhaseCOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9231668148004163910U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13078929163913892386U;
            aOrbiterC = RotL64((aOrbiterC * 7509829068700523627U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9485274692075657877U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12216951187543631673U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6571066246507310805U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6933334652581744234U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17260276102423580920U;
            aOrbiterJ = RotL64((aOrbiterJ * 7796879893790990605U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 387767848169714392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8597538259308082638U;
            aOrbiterB = RotL64((aOrbiterB * 4888054690557707241U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7996708724489146033U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15357384191688149939U;
            aOrbiterH = RotL64((aOrbiterH * 9827691726832491373U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17739222908739454637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1614322333281471170U;
            aOrbiterE = RotL64((aOrbiterE * 7063116837752240891U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4531604274893197209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3453280714992341288U;
            aOrbiterK = RotL64((aOrbiterK * 8390029711127907805U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 116623650872661533U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6565636510115095988U;
            aOrbiterD = RotL64((aOrbiterD * 9691897067492501177U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10303258439817808058U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10917642773040237611U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10232856828372963363U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 24U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 14U));
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 34U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordB) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19424U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24023U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18280U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 19911U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 9774364261626083532U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 23U)) + 18059001521926116420U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 10615626210406381148U) + aPhaseCOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 53U)) + 10536484278007898620U;
            aOrbiterC = (aWandererF + RotL64(aCross, 28U)) + 13320663045139972700U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 35U)) + 17127001787268166583U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 13U)) + 16742574590844166551U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 8347719720758228053U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 18U)) + 13502468705946051986U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3512687886188904904U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 495660316165795934U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6724596801190194913U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5092722552034477356U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15641128019608284015U;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15421873776811085458U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17978775513204574125U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 18359600395119440183U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16617179197537669849U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1931805387534012528U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3400139345857733775U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9544923119559308431U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12930999400470173353U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16791006919271490005U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13673733276226249890U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2032263473309124738U;
            aOrbiterA = RotL64((aOrbiterA * 3088728329261360607U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14868502349358414206U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10116495537187552321U;
            aOrbiterK = RotL64((aOrbiterK * 1380512121796709469U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5341113995358179244U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8415417980279705731U;
            aOrbiterD = RotL64((aOrbiterD * 8521501372683793821U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2462819265072352463U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7657062767608441931U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15554638801273540163U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 28U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 48U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 14U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26004U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30405U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32633U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27599U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 60U)) + 5041131702736607991U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererK + RotL64(aScatter, 29U)) + 9295010428212681446U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 6235875895358766017U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 2622227802531866918U) + aNonceWordK;
            aOrbiterC = (aWandererE + RotL64(aScatter, 37U)) + 3888894734834524972U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 241682012014701753U) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aCross, 19U)) + 15758000422451568079U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 56U)) + 2061944548396976912U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 8177144990755754531U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 554978075608818497U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 250408260560714933U;
            aOrbiterD = RotL64((aOrbiterD * 1295379390497107727U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8700027645880997552U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10026130047465480902U;
            aOrbiterC = RotL64((aOrbiterC * 12417270861933696623U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9785843014096326696U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9998582683258411251U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13817734599383455151U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 6647207154174092691U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4957715980509035719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 4994885315786213197U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 5676683798126497011U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5072908311783966503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5535039946192891515U;
            aOrbiterA = RotL64((aOrbiterA * 2989412783482309753U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6594577050344146271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8750154123258714856U;
            aOrbiterJ = RotL64((aOrbiterJ * 6942158167127532003U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3514769314840874873U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8626045200273524281U;
            aOrbiterI = RotL64((aOrbiterI * 4315441782689789689U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8524870284841706517U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1841819423572964209U;
            aOrbiterH = RotL64((aOrbiterH * 9802481758007234681U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + RotL64(aOrbiterG, 14U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + aNonceWordF) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterA, 10U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFDB529AA054C2183ULL + 0x8660A509FEEEE4F4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDBCD44D4984CC8C7ULL + 0xF7523DFB5AA6D936ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD428C9A7CA7DA22BULL + 0xA720A61BD1696D96ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA4205E19C9D3F08DULL + 0xEA0DC63A1B18712BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD631061D27817F3FULL + 0xCF7D0C04787B82D8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC3AA0FB52DC74AD7ULL + 0x8C17BCE0860BDAE8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC524E2D9F7542E91ULL + 0x822E766EC99E723CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC2F3716E331FC443ULL + 0xDF90EF85F7C64F5AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x86C07A972B080BD1ULL + 0xB7201CF0B81D163BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD5F4C93FE02457DBULL + 0xD7E0A89C1BEA94F7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBCCE744A9B5A9DCFULL + 0x85A5E5B96FB94E13ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x82F8FACB3B81B51BULL + 0x933FDD40FE910C8AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEB294125BAADE361ULL + 0xB0B7642D62C560F2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD39BA69384052DFDULL + 0x87BA768D52364C0BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCFC53D6F7271627BULL + 0xBF029ACE462224C5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEFD7D1224B9EB739ULL + 0x8E9E07E43A868DABULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 696U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((aIndex + 1742U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3184U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 3705U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 13U)) + 6163290588946759209U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 19U)) + 7342672468560105447U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 11574563167017282321U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 60U)) + 2254820206194758964U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 1469783447473099498U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 23U)) + 14174828900676165088U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 11U)) + 16277954291890598132U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 29U)) + 14845750668693136766U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 150099699692047766U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 4U)) + RotL64(aCarry, 53U)) + 1200784917165131703U) + aNonceWordA;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 27U)) + 9469982764806754302U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10956702761701710182U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7915506894975487807U;
            aOrbiterB = RotL64((aOrbiterB * 8874108311712727983U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17335794183733623213U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 557028996286989506U;
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1597385667771002414U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4376417959915162639U;
            aOrbiterJ = RotL64((aOrbiterJ * 4626236858205178149U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 549770198518993876U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 756554555648070919U;
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7298557532533152193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3336802611342112013U;
            aOrbiterK = RotL64((aOrbiterK * 14679103452120080499U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2314938232094714365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12215066333571149153U;
            aOrbiterI = RotL64((aOrbiterI * 10747052773052630601U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7762752719356805046U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7556691736109752918U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13731245903412646404U;
            aOrbiterE = RotL64((aOrbiterE * 15581965016668635409U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5910925625723735162U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 16037704866415841869U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 11628217027073824759U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12605882248192797360U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9579778913978981884U;
            aOrbiterG = RotL64((aOrbiterG * 5372577227818787957U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6063171520266734946U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6163290588946759209U;
            aOrbiterA = RotL64((aOrbiterA * 291843698316138251U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 34U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 10U)) + aOrbiterG) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9254U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 10163U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9425U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9456U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 18191288703716505885U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 50U)) + 9824014524910417136U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 35U)) + 11953012029254917548U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 6297568011027199089U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 5U)) + 2576999400457367975U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 13U)) + 13176139160575558254U;
            aOrbiterB = ((((aWandererG + RotL64(aCross, 52U)) + RotL64(aCarry, 37U)) + 9978408174563621810U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 57U)) + 16765834875061607142U) + aPhaseDOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 16534507305459121344U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 3114710944346151807U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 10240517868726718592U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10721450637990777883U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16689590768796583952U;
            aOrbiterH = RotL64((aOrbiterH * 3046344179729901637U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2427422768928450209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13495584061816457831U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6670984773768885119U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7058636403765106682U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9897341853944713767U;
            aOrbiterE = RotL64((aOrbiterE * 14286816859999869231U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17749559755733386064U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12515645083926326659U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6582878478865838245U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2625692458813609962U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10596240255026143019U;
            aOrbiterG = RotL64((aOrbiterG * 11605800195771080135U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12374290338067865540U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1507386663796330249U;
            aOrbiterF = RotL64((aOrbiterF * 1210241080424446087U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9288099549484146726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15159312464747000702U;
            aOrbiterC = RotL64((aOrbiterC * 500055502081347757U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14998608679505446229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17625038109437732009U;
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10543192232885637211U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10330547522729618042U;
            aOrbiterA = RotL64((aOrbiterA * 7635903835474874057U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5753298214283941201U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15943436872588208065U;
            aOrbiterJ = RotL64((aOrbiterJ * 17704547766822075741U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5757218926946874970U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 18191288703716505885U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2644970408001409575U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 10U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterD, 12U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12414U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 14923U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12285U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15987U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 20U)) + 8767379393098711499U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 7168159491580816433U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 9879279829061883406U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 53U)) + 10537167136053399303U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 23U)) + 2839070018069188936U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 13844278063968429732U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 57U)) + 11278946626186474646U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + 11798425216660557799U) + aNonceWordN;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 13U)) + 7618446090703335192U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 695423597006983660U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 14344728202803488813U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11656100506575697086U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10384358779985773937U;
            aOrbiterH = RotL64((aOrbiterH * 247494692039140973U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17585001605131977341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9964478171465522911U;
            aOrbiterD = RotL64((aOrbiterD * 13484044854790175315U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2710943171829692624U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17809072853457153057U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 16341884203303271365U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12814092033910687774U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1743186323268668740U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11150822630624332557U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10750472346626754704U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15925901217078035356U;
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2569102106359362359U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8868261301410769739U;
            aOrbiterB = RotL64((aOrbiterB * 3662495603133918101U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2143691008373582476U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 10606616796243205921U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 15794414817813485643U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16258070651850746855U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11720192793689633315U;
            aOrbiterK = RotL64((aOrbiterK * 14475623219460678021U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8230871037292355675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16898650748046368353U;
            aOrbiterG = RotL64((aOrbiterG * 7368697435476300255U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9071122174426904737U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4506737259011736474U;
            aOrbiterC = RotL64((aOrbiterC * 11903039808814842447U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4545409671845718259U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8767379393098711499U;
            aOrbiterI = RotL64((aOrbiterI * 1210632171306946669U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterE, 42U)) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererK = aWandererK + ((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 18U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + aNonceWordI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17778U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 17791U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17937U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 20548U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 11U)) + 9751314027302668907U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 47U)) + 12175450995523107056U;
            aOrbiterA = (aWandererK + RotL64(aCross, 30U)) + 17519694958730119552U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 41U)) + 9093525527925682263U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 53U)) + 3713831321786810138U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 10108355209191835040U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 27U)) + 12956307447311314768U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 1904298513945877359U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 4658049993308574460U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 14U)) + 9826333658248851902U) + aPhaseDOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 12058666914724365134U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2516574707110528099U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13335308331049750235U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8230749255538495304U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16536559486797811486U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 7097036838156464969U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12387639130570188998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8459259798142872020U;
            aOrbiterF = RotL64((aOrbiterF * 8001346480955847013U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16083784052002800300U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterD = RotL64((aOrbiterD * 5046501301740813065U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7349538179311335863U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16395170077006105258U;
            aOrbiterI = RotL64((aOrbiterI * 4230485452156662763U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3317652065873784068U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterG = RotL64((aOrbiterG * 9789270651974719183U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5568525912112200094U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9334250662962319598U;
            aOrbiterC = RotL64((aOrbiterC * 5034887614541768961U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5641394627075994165U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13524971148931512745U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3699457147759854357U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15124425790244392471U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7896294947517723306U;
            aOrbiterH = RotL64((aOrbiterH * 7526632360108129915U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15241686066829586263U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12099799118961857495U;
            aOrbiterB = RotL64((aOrbiterB * 10456171163074630861U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17529688916595727188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9751314027302668907U;
            aOrbiterK = RotL64((aOrbiterK * 521888849578281715U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 24U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 44U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererK, 42U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24606U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26144U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22637U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26972U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 52U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 5171470532667965920U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 47U)) + 750549462358682403U;
            aOrbiterG = (aWandererE + RotL64(aCross, 54U)) + 3325689257577120525U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 18031575461559790826U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 37U)) + 13874739537012288677U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 4250029868785016865U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aScatter, 23U)) + 8211158803112611161U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + 1083939790236786027U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 13U)) + 3446525462376962464U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 43U)) + 6973817815000417325U) + aNonceWordF;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 29U)) + 15230876489676945543U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9359727659738755880U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8775170107816327654U;
            aOrbiterG = RotL64((aOrbiterG * 6910680458261008653U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11958941755525038545U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 16966819714283167348U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14556087985619763243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17915047508377045221U;
            aOrbiterC = RotL64((aOrbiterC * 6727635453185130109U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8578745677485367222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7002181668717618866U;
            aOrbiterJ = RotL64((aOrbiterJ * 12329703532414955235U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3569939503066735457U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2956247934282522184U;
            aOrbiterA = RotL64((aOrbiterA * 9946650822131152531U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4285180013402474041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5976239869535619811U;
            aOrbiterK = RotL64((aOrbiterK * 3458095419039067465U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2424524955161695463U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6849595426583763537U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12727902040238318101U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11414890686374886716U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5668287266836153445U;
            aOrbiterF = RotL64((aOrbiterF * 8011885266143066285U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9976985606260445887U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9223940029500676834U;
            aOrbiterD = RotL64((aOrbiterD * 8508023992488499955U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4480967907876921958U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5132766654502526597U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 321625389942019245U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12921555132452983464U) + aNonceWordJ;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 5171470532667965920U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 9710487797420618879U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 10U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 52U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28332U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 28084U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29317U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32566U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 58U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 12311607308490066301U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 13100864684740679846U) + aNonceWordI;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 13697304189274329704U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 9047976902871216732U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 13U)) + 2147897579538537888U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 21U)) + 2072444829390996142U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 5U)) + 2129307836981020908U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 10663145333751112064U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 23U)) + 15019844390503785459U;
            aOrbiterG = (aWandererA + RotL64(aCross, 38U)) + 5460865577557928142U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 15806522559993224197U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6361113778657833389U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8306013884615042570U;
            aOrbiterH = RotL64((aOrbiterH * 8234258702656728667U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4038420580499706912U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11908091484457158973U;
            aOrbiterE = RotL64((aOrbiterE * 3964111175645156719U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11133912466611921250U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2469227904206936928U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2704438771198001599U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13234017916788297295U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9061117693840451988U;
            aOrbiterC = RotL64((aOrbiterC * 3637440416741459419U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12013423690843812324U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14371779015144617412U;
            aOrbiterI = RotL64((aOrbiterI * 3359568073302062667U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10044883414565441442U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 14334898081890462218U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 4878939077928220019U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13788962593988366125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8377887372059713516U;
            aOrbiterG = RotL64((aOrbiterG * 1925913354197206851U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4584439257847749371U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13335592911357756498U;
            aOrbiterA = RotL64((aOrbiterA * 6515028218115896375U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11166747459333977215U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2368465601636093120U;
            aOrbiterK = RotL64((aOrbiterK * 1929974840976648333U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4538402006569031063U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3397601475441212067U;
            aOrbiterB = RotL64((aOrbiterB * 12043369327112500565U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4804403185062062524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12311607308490066301U;
            aOrbiterF = RotL64((aOrbiterF * 10281231071618984185U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 22U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 36U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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

void TwistExpander_Hockey_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAC9150BE8257A6F7ULL + 0xC32C7A82B4894EB4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x94D1046EB31E622DULL + 0xDC20C59C03E5F6BFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x894F97FD79AFE2E1ULL + 0xA913BEC8F1AFD151ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDC41D6F277D6E1FBULL + 0x99C1845B943C7FA4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD9ED3B80DCD58039ULL + 0x9F9672823ACD4C8EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB26DEED995F582C3ULL + 0x94F8C68D9823A62DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEA3DE845DA3BA3E1ULL + 0xFBF4C782B38D84D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB159B6774915D8D5ULL + 0xB8D92CF78C1D83D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFFDC644131FB4175ULL + 0xBFB7D2FB8F3B9106ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC6E4DA129C21C25BULL + 0xF8B95139D7C2BAD3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8892F4C3E5C90AE3ULL + 0xBEF51C46F881734FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDA960B26AE8BF8CDULL + 0xBB8456B4912748C2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9FEF327CD8CF6971ULL + 0xFC85AEB185B26726ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB7AA395D5615A3FBULL + 0x838E65FFAF9EAD61ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAC1B2272673D5A57ULL + 0x94E16596FFD06469ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA703318EFB803BC5ULL + 0xCA5373AF197F2A84ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4141U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2765U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3289U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1791U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 41U)) + 9471546960258473684U) + aNonceWordI;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 19U)) + 18050235435948942244U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 51U)) + 3005107102671544641U) + aNonceWordM;
            aOrbiterH = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 17898396434573801850U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 58U)) + 15071602525497771648U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 21U)) + 5780119462702672108U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 53U)) + 13301326224151025687U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + 18129323022260575961U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 1199228670638790709U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 1839199978088021020U) + aNonceWordB;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 44U)) + 4999517042246790165U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8788607633376516299U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15143903839930468749U;
            aOrbiterB = RotL64((aOrbiterB * 12735914889325422675U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16674732686428431869U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15908873150953195581U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18049755517524334107U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11204775359756474667U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2525984309543939465U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3988529812023791571U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4566345170476825512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14876612901557406267U;
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14926290877038883931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12710203178186614846U;
            aOrbiterE = RotL64((aOrbiterE * 14841163494801662515U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7315094513967387996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11050116830482816766U;
            aOrbiterA = RotL64((aOrbiterA * 3702999495721152019U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4505368486032503953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17905748055257551092U;
            aOrbiterC = RotL64((aOrbiterC * 14775870175093453197U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5728886950801376350U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17998141690182325170U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16008599930125391379U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4325978018819134558U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13526905108565989379U;
            aOrbiterD = RotL64((aOrbiterD * 14121321495714166291U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10597169665474269506U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7500801022830471869U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3702717219742363777U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17063616328548689935U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9471546960258473684U;
            aOrbiterG = RotL64((aOrbiterG * 3029748230803396737U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 28U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 24U));
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6996U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 6193U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8354U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 10741U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 10U)) + 18302975933754610273U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 21U)) + 16736972646771456082U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 53U)) + 17389406266488137442U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 5252511566486165539U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 5730715427422747640U) + aNonceWordB;
            aOrbiterA = (aWandererA + RotL64(aIngress, 3U)) + 6412695646456045825U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 51U)) + 9539701605708994494U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 29U)) + 18355107116412945722U;
            aOrbiterI = (aWandererD + RotL64(aCross, 29U)) + 11735742491750132942U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 47U)) + 12363819388562658842U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 57U)) + 5861430292304371543U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15027487084595017708U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7012850020745791926U;
            aOrbiterC = RotL64((aOrbiterC * 15952928839355613939U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11904871669287886120U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11199760114477343208U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3856004502263742700U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3705931243173921893U;
            aOrbiterH = RotL64((aOrbiterH * 10334871178498711485U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12305785390539209389U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18057980996551978823U;
            aOrbiterF = RotL64((aOrbiterF * 4850564181113470859U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3229431819292153014U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2994716629242460094U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1029427328395257917U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9796307843453735512U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2957260393651252432U;
            aOrbiterE = RotL64((aOrbiterE * 7261055869794739609U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4060469664218866340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17462081697889685330U;
            aOrbiterD = RotL64((aOrbiterD * 7712009170974461225U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13638660073917821172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15202349592659062565U;
            aOrbiterA = RotL64((aOrbiterA * 4514326257446024301U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12071949111168967041U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11930843273199806728U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16229663295689525137U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11294220104731500296U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 440743185210586759U;
            aOrbiterB = RotL64((aOrbiterB * 14810195235168807229U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8514240764798061804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18302975933754610273U;
            aOrbiterG = RotL64((aOrbiterG * 1972439346780950873U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 30U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aNonceWordK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 44U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 50U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12526U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14559U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15144U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 12787U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 964165145848253292U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 53U)) + 10645976767204934746U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 27U)) + 8241612229349212650U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 4159196033256913347U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 37U)) + 7194795864620233507U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 34U)) + 7638928444536778384U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 11819105916503968109U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 5U)) + 18052213302858186237U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 19U)) + 8663575313970041570U) + aNonceWordM;
            aOrbiterK = ((aWandererB + RotL64(aCross, 10U)) + 16644136720439299786U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 43U)) + 16930316530442679864U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16251107616988250593U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7171986193609401665U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17885046834432626644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7757069274715713557U;
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2212805322061155615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6368539134638838822U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5264326094252925613U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6126345334815012938U;
            aOrbiterG = RotL64((aOrbiterG * 17180934809764905307U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13826731214018407061U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6621261811613643620U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5964406317285863781U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2167324450276308078U;
            aOrbiterK = RotL64((aOrbiterK * 1098346374733634905U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16740710162977859724U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8236083581048717923U;
            aOrbiterB = RotL64((aOrbiterB * 4364887787000704039U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13967473987446124012U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5136051802217149813U;
            aOrbiterI = RotL64((aOrbiterI * 13997246005108872883U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5842999397215390366U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8621394946580065499U;
            aOrbiterE = RotL64((aOrbiterE * 11658023035736362355U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18086875424872976900U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7429246355923896047U;
            aOrbiterC = RotL64((aOrbiterC * 5077079237334961761U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 18123753993386959014U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 964165145848253292U;
            aOrbiterH = RotL64((aOrbiterH * 3178072569980307307U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 6U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 30U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17937U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20880U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16601U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17008U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 17225673071833726819U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 10301458382103627331U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 24U)) + 3960233050857362414U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 17768665685046605837U) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aIngress, 51U)) + 14471018461213959767U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 29U)) + 10730597892721340453U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 14863394003122760542U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 9948587274816688296U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 19U)) + 3573569431435100993U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererH + RotL64(aScatter, 44U)) + 8153670675740450590U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 16438856577722561424U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15765587867581925041U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1082039522061775213U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17023740047246402641U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4202521649260798876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15877659681260461141U;
            aOrbiterH = RotL64((aOrbiterH * 11369910758551088173U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2551560426129646123U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 3005102326163906320U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1675501058857208089U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12774812270956702043U;
            aOrbiterJ = RotL64((aOrbiterJ * 5488437008504905105U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1044886020922563597U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4857445127457225171U;
            aOrbiterF = RotL64((aOrbiterF * 13223560654459705259U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11548725551787560962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2434677823189765161U;
            aOrbiterI = RotL64((aOrbiterI * 4283026044563670969U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9606875320524736294U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13732615866277657704U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13921743663803299567U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13350829301153929899U;
            aOrbiterC = RotL64((aOrbiterC * 11858642286713079795U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9473349030551400156U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7446792050826434742U;
            aOrbiterB = RotL64((aOrbiterB * 6619682184124713031U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17970527747978977453U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2326714817603921480U;
            aOrbiterG = RotL64((aOrbiterG * 14581676978186226887U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7875511075130474136U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17225673071833726819U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1196024136909896027U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 26U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 50U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26862U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 23294U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24418U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 26157U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 2168513956284366370U;
            aOrbiterH = (aWandererA + RotL64(aCross, 27U)) + 10290361969974613111U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 46U)) + 15673836275828498050U) + aNonceWordH;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 16600540024145812236U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 9428052101528111892U) + aNonceWordI;
            aOrbiterD = (aWandererC + RotL64(aCross, 53U)) + 12763657928312763377U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + 10751286982008662485U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 1708230173038057979U) + aNonceWordP;
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 4011389705422783816U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 18U)) + 11704428328093077714U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 37U)) + 2055336619674699284U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1870865272102705804U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3574214263751923179U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 13132083406834413563U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 984611970726966186U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15207945449947643672U;
            aOrbiterD = RotL64((aOrbiterD * 9539470161576639981U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4181398506373973169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15222345431506025949U;
            aOrbiterA = RotL64((aOrbiterA * 6925143692628659467U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15023513452326240962U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14965669361708810699U;
            aOrbiterI = RotL64((aOrbiterI * 587008860996713147U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7985755518735406360U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 225592097619240187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3659537916566939383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17043668033610689611U;
            aOrbiterB = RotL64((aOrbiterB * 10797634709118100773U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10217321522161675848U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8013663869536146842U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2293233079384777175U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13762445330867496042U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2692400019659269106U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 167704184292219399U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18232551682424867647U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14785847596876239854U;
            aOrbiterG = RotL64((aOrbiterG * 4569180925037758487U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5910282247522389536U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16556038638738871204U;
            aOrbiterH = RotL64((aOrbiterH * 18356922295088260901U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 141620663839815754U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2168513956284366370U;
            aOrbiterF = RotL64((aOrbiterF * 8605382725635471683U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 54U)) + aOrbiterB) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterF, 10U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27731U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 27786U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32265U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30191U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 1142447269198373880U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 10581460640040336191U) + aNonceWordN;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 52U)) + 14703062773878202900U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 37U)) + 15737525756286914746U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 41U)) + 16178774478273186999U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 2514897053906809160U;
            aOrbiterG = (aWandererK + RotL64(aCross, 58U)) + 13702496607592508464U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 35U)) + 18030885275418337965U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 21U)) + 5241783876161655984U) + aNonceWordB;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 2807052676283587925U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 13U)) + 8022804576763271327U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15597099852232205860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1538435607932096400U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11147868774413615365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13792300423550555634U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3134856508983945719U;
            aOrbiterJ = RotL64((aOrbiterJ * 4271845067763664863U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8654966018053784882U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8937113935476779267U;
            aOrbiterG = RotL64((aOrbiterG * 7386875687217705855U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4135676350355234788U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11407912615743682678U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 2773506587480714695U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10966950663872392059U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6686634993700944582U;
            aOrbiterE = RotL64((aOrbiterE * 2509459942163678241U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14154407529749257990U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18054640398549782388U;
            aOrbiterB = RotL64((aOrbiterB * 7830759861389060149U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14623473030642960240U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1857945571104460086U;
            aOrbiterD = RotL64((aOrbiterD * 18039903315045620079U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17650774450811065797U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9458168381246672881U;
            aOrbiterC = RotL64((aOrbiterC * 3452665113988737563U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16604923466236483242U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12447748535184711684U;
            aOrbiterA = RotL64((aOrbiterA * 5982708155382249061U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9589720286549780720U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1142447269198373880U;
            aOrbiterH = RotL64((aOrbiterH * 8176719948031280789U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 54U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 24U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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

void TwistExpander_Hockey_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xADA29FCF6779D5DDULL + 0xF9FA13A6A4A27B41ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8B28E93A29C82A1DULL + 0x8A181C77DD128DDAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x87FC3505DF46788FULL + 0x910DB4182B838792ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBDFA0F4FE6109953ULL + 0x8DF1906781F9576EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFF47034694ECE2E5ULL + 0xFF1BC818DE7159F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBD47B0C0CE256C4BULL + 0x92730CB4E8480E41ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD75DA2B3179B5C1BULL + 0xA53E2DA2B581AB31ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBEEEDB5D2D5F331FULL + 0xDA5B6A45D09AA453ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB5410D9760D94E0DULL + 0xDC769666F27941B2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB901CBF38A40FC51ULL + 0xFE77D97EFA9D047AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA31C3259F5FE78F9ULL + 0xD758806A39348245ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8E2207128A79E7C3ULL + 0x9621D9DAE296D24DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA13CAFA816252DBFULL + 0x81B99DF2CE85C02CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC7F0584CEE312107ULL + 0xA3C744360C709053ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF17E5622C9E9DB0BULL + 0xD4912B3DAC775EC8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC033946B97384825ULL + 0xE092C470DCBB2F94ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 996U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((aIndex + 2819U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4955U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 3856U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 60U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 13880995121909552664U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 4U)) + 14534942818069300546U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 41U)) + 17745973100886007133U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 21U)) + 2249805580771946872U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 4460116116396439410U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 51U)) + 3378683994078106878U) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 3992996501048809123U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 23U)) + 12057768808864451929U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 44U)) + 4115362079047921130U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 15297384955502206698U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 13U)) + 17623548383481905636U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3559213898000162417U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12311605719074507335U;
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14807313864347885885U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11222085523291581822U;
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 916681229436292462U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2441350114032314686U;
            aOrbiterE = RotL64((aOrbiterE * 7336079498999018067U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7361470539894653271U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12153585147213579808U;
            aOrbiterK = RotL64((aOrbiterK * 3040327545467672961U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13566300726101613579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14875254144748509128U;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9268158535644002904U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14144295981814993491U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12739937231684038161U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13861225650900541642U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12620513474052058164U;
            aOrbiterI = RotL64((aOrbiterI * 18141974182442267181U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14163773386433257965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5725700029399455855U;
            aOrbiterF = RotL64((aOrbiterF * 10446930901088908809U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16644838246877860102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6611825438224873117U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5336239588054125897U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9408958265247071226U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16980073477599191801U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 7985839560318985205U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6513029242607881518U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13880995121909552664U;
            aOrbiterB = RotL64((aOrbiterB * 17463079726765044639U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 34U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 18U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 4U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5493U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 8848U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8100U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10347U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 785861751704720606U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 15968088718435606299U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 47U)) + 1393976526590347151U) + aNonceWordP;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 21U)) + 17240750947292745884U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 39U)) + 4921576136163183137U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 57U)) + 3334047873553153032U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 41U)) + 15086509978458408698U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 43U)) + 892391205397581998U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 23U)) + 2965686403183767521U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 19U)) + 14632215393655706170U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererE + RotL64(aScatter, 26U)) + 15740589515342377322U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11131164813943086445U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterB = RotL64((aOrbiterB * 6412189142344044255U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16021254613117657178U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6183615599897921154U;
            aOrbiterG = RotL64((aOrbiterG * 9976411093264211033U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12533992547026652747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3104325358982904219U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14977348108778147265U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3878525937957474644U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2120435259884368445U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15964718652193073177U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14928658302694194856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9121310461310309348U;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3715693239100476493U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7336577492932262490U;
            aOrbiterD = RotL64((aOrbiterD * 11074754160002665253U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2312452827448455675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4322756069651934618U;
            aOrbiterJ = RotL64((aOrbiterJ * 6908893297397073539U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4962079617577705818U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5072727464750706525U;
            aOrbiterF = RotL64((aOrbiterF * 4947670001221089155U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4553791875259778686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15823770920225774233U;
            aOrbiterI = RotL64((aOrbiterI * 409663191536830375U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9468608484284459072U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8658861660659699947U;
            aOrbiterE = RotL64((aOrbiterE * 2933359123761406353U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14453429515273506170U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 785861751704720606U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3544627380583668815U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF + ((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterH, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 37U));
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 48U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aNonceWordJ);
            aWandererE = aWandererE + (((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 43U)) + aNonceWordF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordO) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 60U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11985U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 15951U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12273U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 15985U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 12U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 15813325389431304548U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 2223874171125403602U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 23U)) + 5510483568496824130U) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 21U)) + 15474152493495661876U) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aIngress, 39U)) + 16846339705130829195U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 42U)) + 1289670576865739669U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 18017354919647006944U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 53U)) + 8539685539928984921U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 13U)) + 3333721400836704048U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 2261560416623815491U;
            aOrbiterB = (aWandererD + RotL64(aCross, 47U)) + 4377786131746816567U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18047393176583722719U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8184724021940434631U;
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10469895939183324807U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14543391765109879223U;
            aOrbiterA = RotL64((aOrbiterA * 4817987697437667225U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5757225781746158178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3539000495894022869U;
            aOrbiterE = RotL64((aOrbiterE * 1032298408884695925U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11288971092707065923U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterH = RotL64((aOrbiterH * 3323838837427471051U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7120580145300417101U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6977246291769372866U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17625434527765525937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3299714663631376190U;
            aOrbiterC = RotL64((aOrbiterC * 6532628892760776767U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10331889953489885250U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8550932256881727932U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13085531621192583719U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11151195711186126257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2552002192824926483U;
            aOrbiterG = RotL64((aOrbiterG * 9754056316698523849U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8038115194286715268U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16594489591573505305U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1241387574663818247U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13476964484361081681U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2136330439951908303U;
            aOrbiterF = RotL64((aOrbiterF * 12728359054660550527U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 231990686776499700U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15813325389431304548U;
            aOrbiterB = RotL64((aOrbiterB * 9155088985405261637U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererG = aWandererG + ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 50U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + (((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 22U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererD, 28U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17131U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 18262U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16695U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21640U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + 439898681482066326U) + aNonceWordM;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 17362083676671776094U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 23U)) + 6418499837265155024U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 6U)) + 17262244253027454972U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 43U)) + 2382066162993139503U) + aNonceWordB;
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 14345808395587174135U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 7534743166385552851U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 16994453324688523966U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 40U)) + 7079553728544045092U) + aNonceWordC;
            aOrbiterD = (aWandererK + RotL64(aIngress, 29U)) + 3562822704508440641U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 53U)) + 13990892681975857821U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1796728922368577238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6605161260520067178U;
            aOrbiterJ = RotL64((aOrbiterJ * 8147537646591674091U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13994083795942328918U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6144523182899107711U;
            aOrbiterK = RotL64((aOrbiterK * 4153879991344611283U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12247462325297436642U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1065809332002012789U;
            aOrbiterG = RotL64((aOrbiterG * 5496601177032953251U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10147919864511540753U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17138553441127273354U;
            aOrbiterI = RotL64((aOrbiterI * 5773875596275267871U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2653924016109573974U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterA = RotL64((aOrbiterA * 12756861659704947257U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 813046408080197079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9624466135414123483U;
            aOrbiterC = RotL64((aOrbiterC * 6960320253124395015U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 972586705850825744U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 155283774901960223U;
            aOrbiterD = RotL64((aOrbiterD * 9928051687724257041U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18200100644751360406U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1168426822045686004U;
            aOrbiterF = RotL64((aOrbiterF * 5867027156069481313U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2271564377169233643U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1896317305868283986U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8080751157990019287U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10209708407397294552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 947585551223387294U;
            aOrbiterB = RotL64((aOrbiterB * 15339472308062247067U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12313594490465462211U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 439898681482066326U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12336632799055203705U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 58U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aNonceWordL) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 50U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25743U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26967U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26032U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 23041U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 20U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aScatter, 26U)) + RotL64(aCarry, 3U)) + 8767379393098711499U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 47U)) + 7168159491580816433U;
            aOrbiterK = (aWandererF + RotL64(aCross, 51U)) + 9879279829061883406U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 10537167136053399303U;
            aOrbiterE = (aWandererI + RotL64(aCross, 11U)) + 2839070018069188936U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 13844278063968429732U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 20U)) + 11278946626186474646U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 57U)) + 11798425216660557799U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 23U)) + 7618446090703335192U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 43U)) + 695423597006983660U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 39U)) + 14344728202803488813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11656100506575697086U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10384358779985773937U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 247494692039140973U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17585001605131977341U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9964478171465522911U;
            aOrbiterC = RotL64((aOrbiterC * 13484044854790175315U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2710943171829692624U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17809072853457153057U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 16341884203303271365U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12814092033910687774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1743186323268668740U;
            aOrbiterG = RotL64((aOrbiterG * 11150822630624332557U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10750472346626754704U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15925901217078035356U;
            aOrbiterI = RotL64((aOrbiterI * 9276504171291801637U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2569102106359362359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8868261301410769739U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 3662495603133918101U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2143691008373582476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10606616796243205921U;
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16258070651850746855U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11720192793689633315U;
            aOrbiterH = RotL64((aOrbiterH * 14475623219460678021U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8230871037292355675U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16898650748046368353U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7368697435476300255U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9071122174426904737U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4506737259011736474U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11903039808814842447U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4545409671845718259U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8767379393098711499U;
            aOrbiterE = RotL64((aOrbiterE * 1210632171306946669U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterK, 50U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 6U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27677U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 27581U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27980U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 32061U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 57U)) + (RotL64(aCross, 44U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 1952750591494698524U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 4488270851303332830U) + aNonceWordC;
            aOrbiterH = (aWandererK + RotL64(aIngress, 14U)) + 2738763375328927635U;
            aOrbiterC = (aWandererE + RotL64(aCross, 11U)) + 6728843649480454340U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 21U)) + 10490717875258865358U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 41U)) + 1429288737812910205U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 27U)) + 2761375016998907636U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 51U)) + 1088988605204499835U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 24U)) + 6829840407300289709U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 9267240337867690471U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 8120113021183975703U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1340980511302566784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11874452169979878835U;
            aOrbiterH = RotL64((aOrbiterH * 8638486178860092537U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1872314794140971426U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6013952618696225751U;
            aOrbiterF = RotL64((aOrbiterF * 7994863587373565715U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3644011378086236002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8501867691997891731U;
            aOrbiterJ = RotL64((aOrbiterJ * 7115282675461711509U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 2493546555198066143U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5179240189571799179U;
            aOrbiterG = RotL64((aOrbiterG * 1267579130962756135U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11273348247858394197U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4577476419423118925U;
            aOrbiterA = RotL64((aOrbiterA * 8427261005061162673U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6201955123046621919U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3930651302557530185U;
            aOrbiterI = RotL64((aOrbiterI * 1563512534463027965U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7571426325227856019U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11098508505512361002U;
            aOrbiterD = RotL64((aOrbiterD * 9229352429618815089U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6154830144380484305U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4282054616147137364U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14984813139796280171U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14818120999774989697U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12174471855744785761U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 3061488029278974095U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3117297607579915182U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2979217539186455309U;
            aOrbiterB = RotL64((aOrbiterB * 12235308335184626143U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 824986728082249286U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1952750591494698524U;
            aOrbiterC = RotL64((aOrbiterC * 10162288961171400541U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 36U)) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 40U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 10U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Hockey_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB973282426B5306FULL + 0xB4E2CF0525AAF711ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC3325954C3234C81ULL + 0x88AFD798EF645E60ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC7E92B6AD071BF29ULL + 0x893823E3F0C3C618ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCC71901EA395D419ULL + 0xB337473A56A94F57ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB1944EAD6769C78DULL + 0xA9E3238DA052550CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE835830B47155EE7ULL + 0x89CB439C1EC4EAC4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED18640F7FF290A9ULL + 0xBA2C1E6FF90F416AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x92EA9AC92075390FULL + 0x9CBBFC253810101DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC4C8488D568DB32DULL + 0xA0E31BD79EB2B063ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFEAAF849D88A68DDULL + 0xFA9A925F230D09A0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFC3D50D1377F4519ULL + 0xA17D67302A1C7447ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE064B97C180A9599ULL + 0xD1D2B3040E228279ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8C1229290ECDDC97ULL + 0x8B6527DA29586DD2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE881C78CD551DF23ULL + 0xBABE407069A6F68AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD157C563E4FCE119ULL + 0x9656DB0DD1B5F1AFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFFE1173DBC628E5FULL + 0xEEDE3ED952567C1DULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2684U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 3824U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3342U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4225U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 12U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 8767379393098711499U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 7168159491580816433U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 23U)) + 9879279829061883406U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 10537167136053399303U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 13U)) + 2839070018069188936U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 58U)) + 13844278063968429732U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 11278946626186474646U;
            aOrbiterD = (aWandererH + RotL64(aCross, 19U)) + 11798425216660557799U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + 7618446090703335192U) + aNonceWordF;
            aOrbiterK = ((aWandererE + RotL64(aCross, 35U)) + 695423597006983660U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 14344728202803488813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11656100506575697086U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10384358779985773937U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17585001605131977341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9964478171465522911U;
            aOrbiterH = RotL64((aOrbiterH * 13484044854790175315U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2710943171829692624U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17809072853457153057U;
            aOrbiterI = RotL64((aOrbiterI * 16341884203303271365U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12814092033910687774U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1743186323268668740U;
            aOrbiterC = RotL64((aOrbiterC * 11150822630624332557U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10750472346626754704U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15925901217078035356U;
            aOrbiterB = RotL64((aOrbiterB * 9276504171291801637U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2569102106359362359U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8868261301410769739U;
            aOrbiterJ = RotL64((aOrbiterJ * 3662495603133918101U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2143691008373582476U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10606616796243205921U;
            aOrbiterE = RotL64((aOrbiterE * 15794414817813485643U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16258070651850746855U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11720192793689633315U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 14475623219460678021U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8230871037292355675U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16898650748046368353U;
            aOrbiterA = RotL64((aOrbiterA * 7368697435476300255U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9071122174426904737U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4506737259011736474U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11903039808814842447U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4545409671845718259U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8767379393098711499U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1210632171306946669U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterG, 6U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5748U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6153U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5617U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 7824U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 28U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 57U)) + 5568146815535263910U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 7736084960873834666U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 1336413621817562093U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 46U)) + 5218462026934984692U) + aNonceWordD;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 53U)) + 7048890985969555935U) + aNonceWordG;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 37U)) + 13415955213864702118U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 5657023257021528548U;
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 14338310943137497116U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 51U)) + 12305161641833950473U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 18U)) + 14514226578370459131U) + aNonceWordC;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 27U)) + 12692904083266024340U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11012959130001327964U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7106471380403489078U;
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3718101961355280891U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6720867800318913440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14497243926965866546U;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5789056168233262435U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14438482587495779937U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 10593535547917767263U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 313917798940179945U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15241845511889502917U;
            aOrbiterG = RotL64((aOrbiterG * 16483477103771326107U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3591957424821693032U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1559050939014453558U;
            aOrbiterJ = RotL64((aOrbiterJ * 17933346117866604725U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15340590914441451383U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5538037287390050110U;
            aOrbiterI = RotL64((aOrbiterI * 4082576643144951473U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4151270491894969214U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 263593701314144898U;
            aOrbiterH = RotL64((aOrbiterH * 10372046955804512457U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9025145270653080646U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6867950904094870056U;
            aOrbiterE = RotL64((aOrbiterE * 9975247022340627751U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3183454301841252109U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3054904157641290615U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4092317552439599475U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1768555574434776135U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5568146815535263910U;
            aOrbiterC = RotL64((aOrbiterC * 12466957001078663927U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + ((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 42U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 30U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14512U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15134U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14332U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13283U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 6U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 701291026547470433U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 46U)) + 17283292650462111643U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + 9969124091931303406U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 5U)) + 889176772718046988U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 3U)) + 6054541844643748084U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 13U)) + 14703226235143028132U) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aIngress, 39U)) + 7977975878522921062U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 16894322614172266274U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 19U)) + 12160451749345900570U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 22U)) + RotL64(aCarry, 29U)) + 10870847008043897470U) + aNonceWordB;
            aOrbiterI = ((aWandererC + RotL64(aCross, 11U)) + 8159920947172520247U) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2440099120969517932U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2428396147731468007U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 9363073341539598441U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2213226274394673479U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7079731443427765333U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16918930776877030559U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 958896789550478970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10788682955708075458U;
            aOrbiterD = RotL64((aOrbiterD * 913321215613559729U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2003386579317564870U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8419686358774204999U;
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6989167615157578904U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17636634003643824148U;
            aOrbiterJ = RotL64((aOrbiterJ * 11038576417283732937U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13824962118933907859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9543912892587859646U;
            aOrbiterA = RotL64((aOrbiterA * 14736710162285997415U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15729878041027706114U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9542137475454825463U;
            aOrbiterH = RotL64((aOrbiterH * 11420547128115090491U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5327302277575009955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2707383132257428583U;
            aOrbiterF = RotL64((aOrbiterF * 6120763309390182129U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9008601903853562620U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11050463189491777908U;
            aOrbiterK = RotL64((aOrbiterK * 9178386878636430553U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14683684132116778056U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5390271065690907120U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17903005409098232619U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5183407290520277451U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 701291026547470433U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16329261100139524239U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterF, 58U));
            aWandererE = aWandererE + ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19590U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 16516U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18328U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16864U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 50U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 53U)) + 1297415699043177788U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 57U)) + 17583786534509260153U;
            aOrbiterC = (aWandererF + RotL64(aCross, 4U)) + 643197858925708798U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 5062653766915694874U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 11U)) + 7034273638367180511U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 39U)) + 2026909726972916996U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 2785690475553211646U) + aNonceWordN;
            aOrbiterD = (aWandererB + RotL64(aIngress, 41U)) + 2910341716302991892U;
            aOrbiterB = (aWandererK + RotL64(aCross, 47U)) + 2834181605200829791U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 13323052600571281928U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 22U)) + 10434901530315760460U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 247903955625194782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5196515747387257163U;
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7196305682377987476U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14777739876892587484U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 95220583948241581U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10609060796540136671U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8386027207212484155U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4855610536246556893U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 729659744301903424U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2350564261412606157U;
            aOrbiterH = RotL64((aOrbiterH * 16713856782349084977U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16611987556673864177U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1525195188708550503U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 10045858602151004553U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4654808490980989596U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8189569777087686263U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17278657566389299577U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10932857495004451792U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1833880112534916813U;
            aOrbiterJ = RotL64((aOrbiterJ * 8004341577533825681U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13100236350175516423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2773759534195186313U;
            aOrbiterE = RotL64((aOrbiterE * 3194954066097323161U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13963126688973399221U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1464529855671190406U;
            aOrbiterF = RotL64((aOrbiterF * 6129954747502059213U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9489842625026216815U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17806120432918490594U;
            aOrbiterK = RotL64((aOrbiterK * 349307975773661379U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13833297268854563081U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1297415699043177788U;
            aOrbiterA = RotL64((aOrbiterA * 4818542043777342249U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 48U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK + ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 60U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterE, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21939U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 24994U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25862U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 22509U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 12029393034357490020U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 4526754731580694987U) + aNonceWordN;
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 17060419646421271853U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 34U)) + RotL64(aCarry, 35U)) + 4128488893837059683U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 27U)) + 12706894827547160110U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 3U)) + 12506324593645825056U;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 12581344490649250025U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aWandererH + RotL64(aScatter, 41U)) + 14357032418199130132U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 58U)) + 15341977701796331249U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 11U)) + 7086602307544733241U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 5U)) + 12398300065276832486U) + aNonceWordL;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 2499745046076601988U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7249361592814001829U;
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3254456186337366437U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3472973415969046680U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14583566953969168353U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7905718972111691591U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15941413652144021522U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 3473779492962783565U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10583964125960308762U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13659925272340853715U;
            aOrbiterA = RotL64((aOrbiterA * 16708294803316630743U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9487054537489454887U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13287757570441887517U;
            aOrbiterE = RotL64((aOrbiterE * 17351439045329892107U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15279245465808571942U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12424999114621745879U;
            aOrbiterJ = RotL64((aOrbiterJ * 2274918760256527137U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13915392738892970475U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13797668053788805126U;
            aOrbiterI = RotL64((aOrbiterI * 13752161103680525317U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14344766585550401077U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13727554194373146727U;
            aOrbiterK = RotL64((aOrbiterK * 17164450431362670223U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1332966642432651232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 938583742533681467U;
            aOrbiterB = RotL64((aOrbiterB * 13323340043936037549U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5659239372701978244U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8501778564909302938U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 15629932660749672503U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1698500835332753591U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12029393034357490020U;
            aOrbiterD = RotL64((aOrbiterD * 18176507271635640153U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 46U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 6U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 21U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27997U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30597U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29077U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30286U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 17668251151213543491U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 21U)) + 16101602509895104517U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 41U)) + 9083915270773304935U) + aNonceWordK;
            aOrbiterH = (aWandererK + RotL64(aIngress, 10U)) + 12810720730318214811U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 18113428002071925621U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 1582208899354109878U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 35U)) + 4180688104819188154U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 23U)) + 8954598189262820611U;
            aOrbiterD = (aWandererC + RotL64(aCross, 37U)) + 15360094153175355879U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 35U)) + 8383954114668216260U) + aNonceWordN;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 27U)) + 15626783326234049197U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10609978564404958066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17656516608997517984U;
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 760077259110786536U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3597338735888033063U;
            aOrbiterG = RotL64((aOrbiterG * 6548831472863517621U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4431777844935985157U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10710423172154671296U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16267496318491473315U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10240882795242085185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7826053487019825891U;
            aOrbiterI = RotL64((aOrbiterI * 15053729937684375907U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9418883403715727353U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11507423614799075545U;
            aOrbiterC = RotL64((aOrbiterC * 16189463984557044693U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11545217316421066655U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 617921402135485341U;
            aOrbiterD = RotL64((aOrbiterD * 8182920764965471653U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14456933220749921009U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7990243583564535387U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5994900368027985469U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14023633125757654751U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11319146808574958827U;
            aOrbiterB = RotL64((aOrbiterB * 13676159969338309307U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14161653180846538446U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17993503892528842342U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 12184170842617942651U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10449311783872638478U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17210495321003036773U;
            aOrbiterF = RotL64((aOrbiterF * 17591257107603354151U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14586515403314763393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17668251151213543491U;
            aOrbiterH = RotL64((aOrbiterH * 9367185933291003363U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 54U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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

void TwistExpander_Hockey_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2390U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 8089U)) & W_KEY1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2963U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1326U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 43U)) + 13174219512651137892U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 18U)) + 2715455762789269341U) + aPhaseCOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 1338018183235594313U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 51U)) + 16566866551729552930U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 6901845297307236726U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 39U)) + 2476078302049201718U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 24U)) + 15531109473927052260U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 4087849380858572351U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 35U)) + 5167830630098599644U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7275995452428627217U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14794340370010024117U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8779497557416568379U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8509217403041662849U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2321522025240806996U;
            aOrbiterC = RotL64((aOrbiterC * 113568101672878697U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5676672952755594051U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2304681269233504384U;
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8383399721062437300U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13602604532551684210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12725687663616352843U;
            aOrbiterK = RotL64((aOrbiterK * 4684699861686199753U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5831790822416009806U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4535048543735457407U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12076777878870257053U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10617608605149381858U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5244225377862618630U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15307177251167023999U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18229989093139888456U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9728120630096192811U;
            aOrbiterB = RotL64((aOrbiterB * 16052574428163231023U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1312233443099767304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8043115602160128619U;
            aOrbiterE = RotL64((aOrbiterE * 9365756845731616963U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 22U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 10U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 60U)) + aPhaseCWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 10U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11160U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 11097U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13561U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 14795U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 48U)) + 13296600294247799698U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 11U)) + 5818503518080877515U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 6735784238734173597U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 7368398209488856201U;
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 961734029066455638U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 23U)) + 797011946660892011U) + aPhaseCOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 37U)) + 12841876018396622350U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 16213253970483895623U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 11U)) + 15186950557113470375U) + aPhaseCOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5117930310827477341U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12265429373166094162U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13920531346698601568U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterG = RotL64((aOrbiterG * 13950964363414164279U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7851960904825938443U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9501511171732550190U;
            aOrbiterA = RotL64((aOrbiterA * 5614164120361489613U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5663365182245722077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18171052650586819280U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3442698321538580861U;
            aOrbiterJ = RotL64((aOrbiterJ * 6317525514963824829U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1491052813469258970U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3956599824067616133U;
            aOrbiterI = RotL64((aOrbiterI * 2928600779267623085U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10963841237346073453U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2303020125591252534U;
            aOrbiterC = RotL64((aOrbiterC * 9969099842343321981U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14503856057958162356U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11147548150090597694U;
            aOrbiterK = RotL64((aOrbiterK * 11856382308792700441U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9191681438318311481U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13556072770381999852U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18316231099054203683U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 40U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 60U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 54U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 20U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21637U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 21133U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17884U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 20728U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 54U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 48U)) + 5573188770530340913U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 57U)) + 1431772230889897111U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 27U)) + 4809192776429682319U) + aPhaseCOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 3U)) + 5576603692574369341U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 2720143226007220386U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 53U)) + 17220328778565331629U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 43U)) + 9629485808442089423U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 1136998437010390983U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 21U)) + 11893390497814523841U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1764986431917532370U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1741014798007010376U;
            aOrbiterK = RotL64((aOrbiterK * 13414914086049500731U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12221368453236547044U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7694538641172350430U;
            aOrbiterG = RotL64((aOrbiterG * 8439120733670016501U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17472344518811560603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterA = RotL64((aOrbiterA * 15290400462887712083U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9535358833412446771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterD = RotL64((aOrbiterD * 17405609148475445743U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14850451970047190039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11932493299452443256U;
            aOrbiterJ = RotL64((aOrbiterJ * 7964808728820467795U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5972619895614731870U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17174497535809891690U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17412894714378898351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14675615208706549810U;
            aOrbiterE = RotL64((aOrbiterE * 7864845089606499769U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16116792108013658523U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9702262005960966336U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 970452849653781703U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17337264966818542841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7004462033775827275U;
            aOrbiterI = RotL64((aOrbiterI * 11943575980344402681U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 60U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 56U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26653U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 24945U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26220U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 26181U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 1866656689936219099U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 12U)) + 2312314528139448289U;
            aOrbiterF = (aWandererE + RotL64(aCross, 3U)) + 3554037526469185237U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 405707755060974111U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 23U)) + 1862976326004007697U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 18U)) + 12992483065443288263U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 27U)) + 3793854946371595197U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 51U)) + 4244007978867369382U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 10280867500312580308U) + aPhaseCOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 472563452959164242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12041770406895816553U;
            aOrbiterF = RotL64((aOrbiterF * 17811798500132002631U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6118634015704900486U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13637107920449233307U;
            aOrbiterJ = RotL64((aOrbiterJ * 17712028184714868053U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16673735670669318830U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8602681273646630496U;
            aOrbiterH = RotL64((aOrbiterH * 6995213887710749241U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7683264695930369476U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9146674871199188218U;
            aOrbiterE = RotL64((aOrbiterE * 7403427067419261981U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3012935612827493084U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1259789268731661945U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2372843620327050137U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5623690455471160780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18355567776031865462U;
            aOrbiterI = RotL64((aOrbiterI * 9553862670107886679U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7705134893833304792U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4435192506444773834U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5249651218395299501U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6204683785806409075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17886971535016484255U;
            aOrbiterD = RotL64((aOrbiterD * 6047216474762933535U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4430578901091376829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 607557685798141547U;
            aOrbiterK = RotL64((aOrbiterK * 12342665567201483107U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 56U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aPhaseCWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 12U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Hockey_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 835U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 70U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3211U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 620U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 40U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 10805654776556844351U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 60U)) + 582794182442795335U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 43U)) + 2858343650974681068U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 8189584049022064284U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 1565100751996962893U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8062028016947611891U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8280504280578451745U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5212851648135050483U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11326869194491655350U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1671695656567777163U;
            aOrbiterG = RotL64((aOrbiterG * 7511554500524257921U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2349843105293943452U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13015545152052004254U;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16703354404749291869U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8713231044374305801U;
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11118401674497783533U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14857556493734710364U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 4U) + aOrbiterJ) + RotL64(aOrbiterG, 36U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13329U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13125U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16320U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14301U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 40U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 47U)) + 6771552164800695068U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + 12131763371571322040U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 3326182381395522013U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 12288775097697156383U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 11U)) + 5195948373449796741U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14404044002250137144U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11142382920035825426U;
            aOrbiterB = RotL64((aOrbiterB * 8134413822789107595U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2967149520256475485U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1470907369577818097U;
            aOrbiterJ = RotL64((aOrbiterJ * 9398653295177725883U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9231668148004163910U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13078929163913892386U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7509829068700523627U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9485274692075657877U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12216951187543631673U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6571066246507310805U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6933334652581744234U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17260276102423580920U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 52U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22493U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19572U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23229U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21298U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 10726035965553989335U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 50U)) + 967354339530195662U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 10834593005478605624U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 1012888282838656933U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 13U)) + 15283530351725183253U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11724495956731703750U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4288330117317505776U;
            aOrbiterD = RotL64((aOrbiterD * 2738997410474076757U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10894778070022873473U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15563886747621617467U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17884709931569040065U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11182488628562891937U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10420140066310588580U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13898299782819948719U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11775138062167543111U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16545391898578161683U;
            aOrbiterH = RotL64((aOrbiterH * 14588306527161321535U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1550144656312299266U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14903504853138279883U;
            aOrbiterC = RotL64((aOrbiterC * 8003033561266164387U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 4U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24641U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 27056U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31330U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 25803U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 48U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 29U)) + 15726877954695761686U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 57U)) + 14187652171881943587U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 8420423151313882782U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 14942322692433259283U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 12U)) + RotL64(aCarry, 35U)) + 7272331475919796255U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 154504365041805840U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17475491222554948786U;
            aOrbiterG = RotL64((aOrbiterG * 2095330528612694779U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5759181483165339605U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5993060214499322845U;
            aOrbiterB = RotL64((aOrbiterB * 10799489831896153301U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10901786237875941844U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17135786595614068473U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15923538730142047043U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5208202073886811165U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6821452921018900631U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13348064837402206969U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8967943922403445136U;
            aOrbiterE = RotL64((aOrbiterE * 300168481725373093U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 22U) + aOrbiterJ) + RotL64(aOrbiterB, 6U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Hockey_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1087U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3801U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7177U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 648U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 15910560457440369082U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 17953072986407436888U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 13U)) + 15446940721193538669U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 36U)) + 3020785262774422009U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 7001288645424994404U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 13385250665458462689U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 3U)) + 4841895644623005949U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13053476783239482065U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 641996979335975244U;
            aOrbiterG = RotL64((aOrbiterG * 3697673197256549833U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16211238020928688299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12715448751323279480U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17784406727699995290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16626339815786580778U;
            aOrbiterB = RotL64((aOrbiterB * 13940754474750138041U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9035070625716345139U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6085848172494001945U;
            aOrbiterJ = RotL64((aOrbiterJ * 10405728912339646693U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1177103851507561053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9040984343694325070U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13334258224023902365U;
            aOrbiterH = RotL64((aOrbiterH * 4782523727707164869U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1079824790138592518U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14024082692012948652U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3219489374333737903U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 42U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12059U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15813U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16028U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8588U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 52U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 9774364261626083532U;
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 18059001521926116420U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 10615626210406381148U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + 10536484278007898620U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 13320663045139972700U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 36U)) + 17127001787268166583U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 43U)) + 16742574590844166551U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8347719720758228053U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13502468705946051986U;
            aOrbiterJ = RotL64((aOrbiterJ * 13822952083584784695U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3512687886188904904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 495660316165795934U;
            aOrbiterI = RotL64((aOrbiterI * 6724596801190194913U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5092722552034477356U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15641128019608284015U;
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15421873776811085458U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17978775513204574125U;
            aOrbiterB = RotL64((aOrbiterB * 18359600395119440183U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16617179197537669849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterG = RotL64((aOrbiterG * 3400139345857733775U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9544923119559308431U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12930999400470173353U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16791006919271490005U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13673733276226249890U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2032263473309124738U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3088728329261360607U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterE, 50U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24461U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19450U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23161U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19579U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 4476099022490972343U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 16836423700375760429U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 8850577488928703557U;
            aOrbiterA = (aWandererE + RotL64(aCross, 36U)) + 7091631824560042743U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 47U)) + 12560498899956759494U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 19U)) + 7797973377112012161U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 6173820673874805794U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10805025132310245348U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7139216143268029968U;
            aOrbiterI = RotL64((aOrbiterI * 8349754682635765573U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8241544862261635722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4735527016563596150U;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5166171126690294033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11117641762075368393U;
            aOrbiterG = RotL64((aOrbiterG * 4980156869201219393U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6312932356458415421U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1304139291184508668U;
            aOrbiterA = RotL64((aOrbiterA * 90744653170922319U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10085025354842771067U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16745854428789531080U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1945983905747274355U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2497187958708890337U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16069701876646548995U;
            aOrbiterJ = RotL64((aOrbiterJ * 16606039730973709495U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17242004368025978091U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12334315722243232121U;
            aOrbiterB = RotL64((aOrbiterB * 16528598396696346719U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 22U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29731U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26275U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28301U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24627U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 22U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 7948891781097675369U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 35U)) + 13928362874228230226U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 10776180542602258926U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 5735115172149470447U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 5U)) + 5353591822981766987U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 562301708107268570U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 20U)) + 10467810247578364868U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14541630141152308564U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2350076897065139429U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12222554362482034393U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17519109078651162228U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6061035173339902910U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10021905773432907835U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15654836633731000065U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2849680038315532197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7671010488872356142U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11485114338165600777U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8759060657343458985U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11009137869375286581U;
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15792999392743144135U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6180808423175992479U;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 28U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Hockey_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5971U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1460U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 811U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3504U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 11698283336767769359U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 19U)) + 13297826354831483872U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 15254999058287530795U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 11U)) + 17474166585085346567U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 15684783498452840289U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5061229733465216486U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15370981279168377944U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15893028157665379361U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17966672773619554092U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14685092893994491068U;
            aOrbiterJ = RotL64((aOrbiterJ * 1627758964162892429U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12798804186209406389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2848444181474221574U;
            aOrbiterD = RotL64((aOrbiterD * 13730480364920876877U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8551142075919636146U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8833198159158950723U;
            aOrbiterF = RotL64((aOrbiterF * 7650289040764974737U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7351473160893666232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 46U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11141U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 13297U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15804U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 14262U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 4622023259121087483U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 28U)) + RotL64(aCarry, 11U)) + 10253505250223501352U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 17133877904420462669U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 6162827793741796700U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 9610986424765907615U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11210747154264753754U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16554205219580654546U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12754735039924859911U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10352576357413766388U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3651845783283479752U;
            aOrbiterF = RotL64((aOrbiterF * 1011289824180799641U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18145542190463500476U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5415609566767162857U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6474184559323816389U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2033734872464201570U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3507213117125813345U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5453058336688881113U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8716253393049851856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 695984869565941856U;
            aOrbiterH = RotL64((aOrbiterH * 8377921610764044735U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19051U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24451U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16560U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 19927U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 5960680319644404115U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 16050752633567034185U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 8447503223226854741U;
            aOrbiterA = (aWandererC + RotL64(aCross, 48U)) + 14176813813397917591U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 10534915376130006644U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6866224454375302514U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16506374165041008396U;
            aOrbiterB = RotL64((aOrbiterB * 1326855300197233833U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7167814023968794098U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13870852197416596664U;
            aOrbiterJ = RotL64((aOrbiterJ * 17015971222069856463U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18064038854848993105U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9869630811507771691U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13723164383800461387U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 863613100452759380U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16597969741225436529U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2680793528887208903U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6575347108051310653U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17062262265485019063U;
            aOrbiterE = RotL64((aOrbiterE * 7601045488473620019U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterB, 42U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30498U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 29423U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31129U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25187U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 39U)) + 8020711767807230555U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 15368693777246341570U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 30U)) + 5117523734225562401U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 13155269151097507808U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 9879303753623578272U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1165799257173794826U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 930641942062732091U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17151944851548731159U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11330571332221123153U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2862963158282518899U;
            aOrbiterI = RotL64((aOrbiterI * 13782195862525974199U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6019186399361476659U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1924419843785161958U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9485557122500346869U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12618629043591380461U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9334176504266512405U;
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16829692481030013551U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5604784396927022709U;
            aOrbiterH = RotL64((aOrbiterH * 2833893610883508353U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Hockey_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6492U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 4638U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3597U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 71U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 2783898056762489197U) + aPhaseGOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 7177192902873343053U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 12254703232691980774U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 11U)) + 15446547245691219559U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 29U)) + 888475203006174856U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3649183529366307877U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4642631047518805167U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14791564497487717167U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6108329730724782250U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8334054653023816636U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9352516059501924393U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5891895375031474350U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3176720746238477862U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1869961473768307911U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6111038696865301675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11914998302228682704U;
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17005063057791320948U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18333780598768130670U;
            aOrbiterH = RotL64((aOrbiterH * 5416759844884107303U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 42U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12829U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12824U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14379U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9924U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 2786079456995203065U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 37U)) + 7237256119153857253U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 9310834010563647604U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 5U)) + 17361734905706517877U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 15837111231884647451U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18065431964418026445U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3029123922999952652U;
            aOrbiterK = RotL64((aOrbiterK * 16309219658285890145U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5166926595573507837U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1918425684273807598U;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4724551751012661440U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1818014487579644390U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14904092108647864911U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6670090372241084216U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8485757110007268693U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11876760095108618363U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4928130251509514742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2528788422725346792U;
            aOrbiterE = RotL64((aOrbiterE * 1855982047967756661U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 40U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18916U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 20442U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22606U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21856U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 13854738573712660276U) + aPhaseGOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 16835460633412286294U;
            aOrbiterK = (aWandererK + RotL64(aCross, 6U)) + 6785859293758091931U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 47U)) + 126317283127992659U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 7568963536291415413U) + aPhaseGOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12294016745653004819U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 18269588932920281147U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9031152619272892317U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5872406424994751026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7764434758831474129U;
            aOrbiterH = RotL64((aOrbiterH * 3772146788188420071U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4804168969415573371U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 959601763507651280U;
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9257644462479293048U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14332699366894494579U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8829304078930625541U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10487012596470786004U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 612729229562321440U;
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 52U) + aOrbiterF) + RotL64(aOrbiterD, 48U));
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27756U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28689U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26854U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 32040U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 3U)) + 701291026547470433U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 17283292650462111643U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 11U)) + 9969124091931303406U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 889176772718046988U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 38U)) + RotL64(aCarry, 35U)) + 6054541844643748084U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14703226235143028132U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7977975878522921062U;
            aOrbiterF = RotL64((aOrbiterF * 9030855800028448469U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16894322614172266274U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12160451749345900570U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18055355572903901749U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10870847008043897470U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8159920947172520247U;
            aOrbiterJ = RotL64((aOrbiterJ * 4833194641611011805U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2440099120969517932U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2428396147731468007U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9363073341539598441U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2213226274394673479U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7079731443427765333U;
            aOrbiterD = RotL64((aOrbiterD * 16918930776877030559U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 56U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 52U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Hockey_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7247U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1195U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 533U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 7432U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 380024772508948442U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 7649029098162567210U) + aPhaseHOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 56U)) + 5329304598870421851U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 12306118665045151326U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + 960751560457324256U) + aPhaseHOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3244070254386191876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15733408571609521746U;
            aOrbiterJ = RotL64((aOrbiterJ * 11280008313548121407U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17623448932647018544U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8787759896149035829U;
            aOrbiterB = RotL64((aOrbiterB * 7092515868845497573U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14741681792348288162U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8801731213568307302U;
            aOrbiterF = RotL64((aOrbiterF * 12127126999570616489U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9872248187499779222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15407371518644528235U;
            aOrbiterK = RotL64((aOrbiterK * 1245102406469471673U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4242060317152943062U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9942784962409917541U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 888649755587764533U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 46U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15302U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 10037U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9136U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12844U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 21U)) + 11039986441331892533U) + aPhaseHOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 6256024955965426119U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 51U)) + 9857443189988995666U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 38U)) + RotL64(aCarry, 37U)) + 11900944813380998208U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 8422577734978875541U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3100835100713928724U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11871553509810206993U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15501681886909921677U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17614749493763417027U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3638372131856199916U;
            aOrbiterG = RotL64((aOrbiterG * 480683274898147025U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6582275259281025770U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17016882418498941958U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4269869255230867823U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1747214688658984715U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9356088987044015278U;
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4056238112133473456U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16013150119949532998U;
            aOrbiterC = RotL64((aOrbiterC * 12913648646318115315U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 56U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23697U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 23361U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24324U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 17366U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 60U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 11698283336767769359U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 43U)) + 13297826354831483872U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 15254999058287530795U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 17474166585085346567U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 54U)) + 15684783498452840289U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5061229733465216486U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15370981279168377944U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15893028157665379361U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17966672773619554092U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14685092893994491068U;
            aOrbiterK = RotL64((aOrbiterK * 1627758964162892429U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12798804186209406389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2848444181474221574U;
            aOrbiterI = RotL64((aOrbiterI * 13730480364920876877U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8551142075919636146U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8833198159158950723U;
            aOrbiterJ = RotL64((aOrbiterJ * 7650289040764974737U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7351473160893666232U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14204899612487622222U;
            aOrbiterE = RotL64((aOrbiterE * 6317485031956448029U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aPhaseHWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterK, 12U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29552U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26313U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25365U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28597U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererJ + RotL64(aIngress, 52U)) + 3255291173184001106U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 15308468160116255528U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 18186972408589866656U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 4439324265978331914U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 13099263173016322486U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7041561081767500660U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6196422612687812971U;
            aOrbiterJ = RotL64((aOrbiterJ * 13359900204297781063U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7664260932541281413U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17802347823020441056U;
            aOrbiterA = RotL64((aOrbiterA * 2220679459017369255U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4253107484061190446U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13799496534030645312U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14252892847595951926U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5663527578664291422U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18314294235895182465U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11148755959699137661U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17036900929333594592U;
            aOrbiterB = RotL64((aOrbiterB * 16041243617369003291U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 46U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
