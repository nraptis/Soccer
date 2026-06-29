#include "TwistExpander_Golf_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Golf_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC27FB9BDEC7C7863ULL + 0xD9988AD541C2ED52ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC3626E77B204EAC5ULL + 0x94B19ED1632631ADULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x85DEEDD5E68DEEF9ULL + 0xE797710D7404A42AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x96716A57B06CFEF3ULL + 0x94ED8B560E37DB98ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9552877B1310540DULL + 0xB0070F3FE03A31A0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x87650D49C5A0DA17ULL + 0xA8FA0A8B46076708ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCD3DFFA6BA355479ULL + 0x8C2B8F79B9B046FFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEEAD24E9658FC7E7ULL + 0xE78823EB582F636BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA9F8F0A02C887C57ULL + 0xB90E57834CD4B124ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC361D72A7211FDF1ULL + 0xF2D4EBB13DB90766ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE76045238418A4CBULL + 0xE5E1A6AD96A819F5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8E3F84607E29119FULL + 0x9978979FCFCD10A9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8A9DA7D0F3030FDBULL + 0x98B47AA1DAF51808ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8256CD962C0DDC8BULL + 0xEA42803BA413A395ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBAD6346BD9231A15ULL + 0x9D181D88571BA5DCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAC88E48C603FBD6DULL + 0x9448A424C74FCBB5ULL);
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
            aIngress = RotL64(mSource[((aIndex + 2406U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((aIndex + 836U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2391U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1911U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 53U)) + 9435962834163239322U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 10524704356081318973U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 7403401305665208680U) + aNonceWordO;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 30U)) + 7525414805023556493U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 13U)) + 1116686470029070951U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 13257612299137802420U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 51U)) + 9181543003986598283U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 9739384852307501107U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 26U)) + 11308402900229016057U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 39U)) + 14935167593705272337U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 3U)) + 7171824007631943535U) + aNonceWordA;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8068411284829563567U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12350207458513447578U;
            aOrbiterE = RotL64((aOrbiterE * 813973258659041895U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17039236343991574134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18291683592714999632U;
            aOrbiterK = RotL64((aOrbiterK * 7771718817924840713U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6239616841884430968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10604527977569876774U;
            aOrbiterF = RotL64((aOrbiterF * 6972820410084939637U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1707724300671717658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3802268808625297647U;
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9423064323799920219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 242153923313096551U;
            aOrbiterI = RotL64((aOrbiterI * 12117679073775630197U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 945801070951928277U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13094814302414492064U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14638176479878969775U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7572219725951040117U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16494986983782503428U;
            aOrbiterH = RotL64((aOrbiterH * 2739189408707408171U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10949497978229234856U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11219643352002119905U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16900635614259262873U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14245670385849499678U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13771155918235018585U;
            aOrbiterC = RotL64((aOrbiterC * 14121731385133220921U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15722734439532828816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11032710342174118366U;
            aOrbiterB = RotL64((aOrbiterB * 16096465375397981585U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2071496769185495150U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9435962834163239322U;
            aOrbiterD = RotL64((aOrbiterD * 10640995428633266765U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterI, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 8777U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 10409U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9906U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((aIndex + 5800U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 38U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 15549114274303128055U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 53U)) + 16466750056388063241U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 47U)) + 12209449840836787142U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 14551496099734294336U) + aNonceWordA;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 3U)) + 6266576428679808622U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 16892841575635668152U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 7375966221423362125U) + aNonceWordG;
            aOrbiterA = ((aWandererF + RotL64(aCross, 50U)) + 11926105302821753530U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 57U)) + 16219253791550461124U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 7299056065319248160U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 21U)) + 15234001484933728439U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6615802589932632120U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5481176858895819247U;
            aOrbiterK = RotL64((aOrbiterK * 3604590158551984877U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17220507586542139380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14137921473739415340U;
            aOrbiterG = RotL64((aOrbiterG * 10634645686035907603U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16981960446540932787U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10897565927079518588U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2746889569299593263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4894117146736361379U;
            aOrbiterF = RotL64((aOrbiterF * 2656750612042673191U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18294823016957137777U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 86828501068883383U;
            aOrbiterB = RotL64((aOrbiterB * 11432686669235402365U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6322053762209547826U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6754524552483363820U;
            aOrbiterA = RotL64((aOrbiterA * 1746163087826694641U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7306452650619361017U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12717201204443785828U;
            aOrbiterD = RotL64((aOrbiterD * 6121251603905574991U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10422327053543898585U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14786413282036348183U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8713024293107068275U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4599182534559908397U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5080179685914177581U;
            aOrbiterE = RotL64((aOrbiterE * 14984675846207762951U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6527649204956325409U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8327234966110052920U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9343969092668123661U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7845497893651522069U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15549114274303128055U;
            aOrbiterH = RotL64((aOrbiterH * 15263427406359082909U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterI, 44U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 38U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11444U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 12099U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14071U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 14317U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 11U)) + 1708250618750199233U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 12009147777553691142U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 8393982703399156592U) + aNonceWordI;
            aOrbiterE = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 3247327098356831221U) + aNonceWordE;
            aOrbiterC = (aWandererC + RotL64(aScatter, 48U)) + 3403590155376353737U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 23U)) + 18197244558104735044U) + aNonceWordC;
            aOrbiterI = (aWandererJ + RotL64(aCross, 35U)) + 3096253642040701606U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 21U)) + 8012692688785412179U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + 17531946907545680745U) + aNonceWordB;
            aOrbiterD = (aWandererD + RotL64(aIngress, 18U)) + 17687695944270225817U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 37U)) + 16147773866007628769U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18244641303026196497U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8839160526348897457U;
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10599266240854068246U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13311591601230386375U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4629354220460621284U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17775391885312236187U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17078153810088721310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9470436761716263000U;
            aOrbiterD = RotL64((aOrbiterD * 5431855497250357229U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3305863413630104742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14377172434239576161U;
            aOrbiterE = RotL64((aOrbiterE * 6880176890091033423U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 415687827894226513U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16975319836893760993U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 6597144958013976445U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12707054129431596074U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8974182792497231239U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 7874658957269462717U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10826131924322955095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4168545139712703154U;
            aOrbiterH = RotL64((aOrbiterH * 10305904857550051705U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4539070253658625193U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3737870219498561326U;
            aOrbiterB = RotL64((aOrbiterB * 13130847633918921393U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11563084648810555040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7410695535361901473U;
            aOrbiterC = RotL64((aOrbiterC * 7540855656023807389U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6687453696858775037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1708250618750199233U;
            aOrbiterK = RotL64((aOrbiterK * 13104250803527718135U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 44U)) + aOrbiterC) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 19442U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 17366U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19472U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17226U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17253U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 51U)) + 8375305456876489425U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16193562952772453047U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 23U)) + 18088652458594816223U) + aNonceWordC;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 767344788620249944U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 13U)) + 7705194930396368752U) + aNonceWordA;
            aOrbiterA = (aWandererI + RotL64(aCross, 10U)) + 3829736891311272834U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + 9881681671347640061U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 29U)) + 1721196560190164264U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 3002652618388454213U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 21U)) + 9811621464004005202U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 18U)) + 5652598941069986530U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6250499348327316328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterI = RotL64((aOrbiterI * 16446892258704281903U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13800298546867243172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12256104592865905782U;
            aOrbiterJ = RotL64((aOrbiterJ * 16983140179497142713U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17817225416918329229U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17738671327352776217U;
            aOrbiterK = RotL64((aOrbiterK * 393488251327705063U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6816031224188400541U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16989563985059237014U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8677884225771717797U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16891524847268207549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1833508573940405571U;
            aOrbiterD = RotL64((aOrbiterD * 9709196587703979539U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12729999421507068973U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6839758643521968957U;
            aOrbiterC = RotL64((aOrbiterC * 16350557395881283975U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8524167125469267428U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14741523560290472617U;
            aOrbiterH = RotL64((aOrbiterH * 4367850822282205897U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10983798459868424892U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5649250846622078964U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 7149612714806023987U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8587302028325090061U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17457129226030333666U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18107356450566915215U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15600113588474915690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6595247491374683783U;
            aOrbiterG = RotL64((aOrbiterG * 1432432381540098765U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13246325856585534283U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8375305456876489425U;
            aOrbiterE = RotL64((aOrbiterE * 8331406038795786099U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 36U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25123U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 23367U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22587U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 24998U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23740U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 25311U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 52U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 48U)) + 18319689184146942855U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 8041304130090501019U;
            aOrbiterI = (aWandererK + RotL64(aCross, 39U)) + 11347064191990897738U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 15242243470024447468U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 29U)) + 10619749107163611105U) + aNonceWordB;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 3U)) + 14795614276221947128U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 1578095288886372393U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 53U)) + 13593906305770501684U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 35U)) + 8919815528334599172U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 50U)) + 17425548324720065145U) + aNonceWordN;
            aOrbiterD = (aWandererB + RotL64(aScatter, 57U)) + 11125018338392347335U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3779189180734244399U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10958224663276134041U;
            aOrbiterI = RotL64((aOrbiterI * 6206963519509783781U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4317305352561612995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4501071771615514619U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6486573807774431753U;
            aOrbiterA = RotL64((aOrbiterA * 324029625116648669U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15714881857668975753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3506619392820235900U;
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5295711072762443783U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11192836530396570648U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 4361810118382207039U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7993389678399774574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12551394763541226695U;
            aOrbiterH = RotL64((aOrbiterH * 11903486656172026403U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11553674370322129668U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4459881583199320245U;
            aOrbiterJ = RotL64((aOrbiterJ * 2805857426321555685U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3053507713574219459U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15458441755058850309U;
            aOrbiterF = RotL64((aOrbiterF * 7296609957819165877U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17429750026356459756U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17114614857181230304U;
            aOrbiterD = RotL64((aOrbiterD * 10541235280918902739U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8958993884028672039U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 18319689184146942855U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5430881344386342703U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterI, 42U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 56U)) + aOrbiterI) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 30166U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 32277U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28276U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32276U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28847U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29517U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 35U)) + 439898681482066326U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 29U)) + 17362083676671776094U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aWandererK + RotL64(aIngress, 44U)) + 6418499837265155024U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 17262244253027454972U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 2382066162993139503U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 11U)) + 14345808395587174135U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 39U)) + 7534743166385552851U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 6U)) + RotL64(aCarry, 51U)) + 16994453324688523966U;
            aOrbiterK = (aWandererE + RotL64(aCross, 41U)) + 7079553728544045092U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 3U)) + 3562822704508440641U) + aNonceWordF;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 37U)) + 13990892681975857821U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 1796728922368577238U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6605161260520067178U;
            aOrbiterG = RotL64((aOrbiterG * 8147537646591674091U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13994083795942328918U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6144523182899107711U;
            aOrbiterF = RotL64((aOrbiterF * 4153879991344611283U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12247462325297436642U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1065809332002012789U;
            aOrbiterC = RotL64((aOrbiterC * 5496601177032953251U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10147919864511540753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17138553441127273354U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5773875596275267871U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2653924016109573974U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 813046408080197079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9624466135414123483U;
            aOrbiterJ = RotL64((aOrbiterJ * 6960320253124395015U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 972586705850825744U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 155283774901960223U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9928051687724257041U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18200100644751360406U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1168426822045686004U;
            aOrbiterD = RotL64((aOrbiterD * 5867027156069481313U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2271564377169233643U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1896317305868283986U;
            aOrbiterI = RotL64((aOrbiterI * 8080751157990019287U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10209708407397294552U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 947585551223387294U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15339472308062247067U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12313594490465462211U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 439898681482066326U;
            aOrbiterB = RotL64((aOrbiterB * 12336632799055203705U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 52U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 50U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 40U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Golf_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE44842D690A86A5FULL + 0xCB482028C92D15FAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDE4005C7EEBF6595ULL + 0xF5A8FAD566357629ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9C83F5352B69F7F7ULL + 0xCAB8E3D31F337A56ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE6C72820FA130E85ULL + 0xD521D72CE7EFD687ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF2B6E1005D31B2DULL + 0xB59F574E0701C92CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAF9EEEE55363EBD1ULL + 0xCE0726BD65E34996ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE705BA79997C3E35ULL + 0xE8A34F782E6925BBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC09AA88EC6AC4D51ULL + 0xBA8AFEDB8B8E6CEAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC37F9176055755E5ULL + 0xF4F84671757F2493ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEC3D75B80A25AF67ULL + 0xC8B0CC7FE9E62D64ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFC48E3B5434AABE9ULL + 0xDF8B993E2FC93EF2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8AE79C587AFA1923ULL + 0x81EFDA2A84CC4F3FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBA084609C160FB8BULL + 0xB347FCAF11F18FB6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAC4CCD8BB1C063D1ULL + 0x9D4D81A25B112BF3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x87658FE2086BC2EFULL + 0xE504EA9F5FBD2CFAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x828717C4D59D9D9BULL + 0xBFCF3DB20A0B8FDFULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2104U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3736U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1070U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneD[((aIndex + 2711U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 13854738573712660276U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 46U)) + 16835460633412286294U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 39U)) + 6785859293758091931U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 126317283127992659U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 57U)) + 7568963536291415413U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 52U)) + RotL64(aCarry, 37U)) + 12294016745653004819U) + aNonceWordC;
            aOrbiterK = (aWandererA + RotL64(aCross, 29U)) + 18269588932920281147U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + 5872406424994751026U) + aNonceWordD;
            aOrbiterG = (aWandererE + RotL64(aIngress, 23U)) + 7764434758831474129U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4804168969415573371U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 959601763507651280U;
            aOrbiterH = RotL64((aOrbiterH * 4647396592804833217U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9257644462479293048U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14332699366894494579U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 8829304078930625541U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10487012596470786004U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 612729229562321440U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11380387280507726003U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7845523921295625315U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12742115479740024747U;
            aOrbiterG = RotL64((aOrbiterG * 15578543510683986421U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10294667720904610944U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14369711143154904567U;
            aOrbiterD = RotL64((aOrbiterD * 13753005602288309379U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10918344717497681894U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18136794828308636957U;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14378638206724886404U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 7077588188450008059U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 485375960462924335U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8941870012851971932U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15242087859620352399U;
            aOrbiterF = RotL64((aOrbiterF * 4963002810455992839U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10395280254030875387U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6826595516076975980U;
            aOrbiterC = RotL64((aOrbiterC * 6198886240333178001U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 52U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 24U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 42U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 34U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9126U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 11546U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13594U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9527U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 14403U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererD + RotL64(aScatter, 18U)) + 4622023259121087483U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 10253505250223501352U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 57U)) + 17133877904420462669U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + 6162827793741796700U) + aNonceWordM;
            aOrbiterK = (aWandererH + RotL64(aIngress, 27U)) + 9610986424765907615U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 11210747154264753754U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 10U)) + 16554205219580654546U) + aNonceWordN;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 10352576357413766388U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 37U)) + 3651845783283479752U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18145542190463500476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5415609566767162857U;
            aOrbiterB = RotL64((aOrbiterB * 6474184559323816389U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2033734872464201570U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3507213117125813345U;
            aOrbiterF = RotL64((aOrbiterF * 5453058336688881113U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8716253393049851856U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 695984869565941856U;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7661578828878284931U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 906654265099155956U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8117625377607536949U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6050049984731254612U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17882717590338190821U;
            aOrbiterI = RotL64((aOrbiterI * 10807367411402733215U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4996521991532815957U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4246460672800604436U;
            aOrbiterA = RotL64((aOrbiterA * 12047466401960824903U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8700148116452518842U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10039050281847466206U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11884791271239660157U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4513844680425845372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3037563127442815153U;
            aOrbiterD = RotL64((aOrbiterD * 18363509277992292407U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1005237931570968724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1373258132025712065U;
            aOrbiterE = RotL64((aOrbiterE * 10458020799382532395U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 18U));
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 14U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 12U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18854U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 21678U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23334U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19222U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24502U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16983U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 60U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 11U)) + 6521330037475130256U) + aNonceWordC;
            aOrbiterH = (aWandererG + RotL64(aScatter, 47U)) + 12611880456055428940U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 12061611078130934708U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 1558112410801116984U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 10509115227850160786U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + 4045915960688792066U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 19U)) + 1196541286513243082U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 5U)) + 15564991032722373702U) + aNonceWordA;
            aOrbiterF = (aWandererA + RotL64(aCross, 38U)) + 4897765238703641798U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12327429514907752733U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6189189797708711636U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9017615866338877651U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6374267075282018852U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1888758503831341439U;
            aOrbiterB = RotL64((aOrbiterB * 74387714918264257U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14956857689299491800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14879361107223331957U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 9166712966729591953U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16086885494838105042U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 10854345917959911439U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7078313614360332089U;
            aOrbiterJ = RotL64((aOrbiterJ * 9864025732292844871U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15083669236062255011U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 594879695916679116U;
            aOrbiterE = RotL64((aOrbiterE * 9852515479152735283U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6721466068234534523U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 475816724162626782U;
            aOrbiterD = RotL64((aOrbiterD * 4799725182757588407U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4341655358154605899U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15477254302340298586U;
            aOrbiterF = RotL64((aOrbiterF * 13961520225881974201U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10179091913200895775U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6310490897546909571U;
            aOrbiterK = RotL64((aOrbiterK * 15080621088825477613U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 34U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26018U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 28115U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 27006U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29911U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24983U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 27462U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 5U)) + 2915859148137000694U;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 210680583721444425U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 18U)) + 6668118118775650387U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 41U)) + 15794200818099010989U) + aNonceWordB;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 6565076707062828369U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 27U)) + 16323164497808856719U) + aNonceWordA;
            aOrbiterH = ((aWandererA + RotL64(aCross, 57U)) + 7965435318816716560U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 27U)) + 7390281030573369017U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 2269738866911824875U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9664014216039993873U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18284857398028357633U;
            aOrbiterI = RotL64((aOrbiterI * 8402008251343393737U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 367667619795303009U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7935945060956274197U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16683666162337789540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10655658270998102390U;
            aOrbiterE = RotL64((aOrbiterE * 15231596813382239841U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8307037916581540297U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3247742749860703524U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052136713218656641U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10446792483683818139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16374602929344972364U;
            aOrbiterH = RotL64((aOrbiterH * 12599903932725787599U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2411334498322777183U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1093701164116833765U;
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17018480952982840635U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 17348395690080029814U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16111252311283623152U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12776492920397785951U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6136009241593081821U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12214538600808144816U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10043377462096783363U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14639467375095185877U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 18U));
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 22U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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

void TwistExpander_Golf_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC01BCC2D88878BC7ULL + 0xC3647D88E26D547CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE6824338D40F9659ULL + 0xCFB750A8BBD5A08FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEF23DDBE4421BAF1ULL + 0xAFC9E92829DBD821ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA3AD63740AFE40BDULL + 0xE546CA13AEE92C9AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD57F8B13B8FE447BULL + 0xF4925BEB0F518DDBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC4D444FFCF879003ULL + 0x9B51129C1892A7BDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA6F5EF3B29076E67ULL + 0xFECF0EEDE9393797ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD633067BF4B74533ULL + 0x88540FEE3E674156ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB5A6400F82CAA35BULL + 0xA8E2F2B46BB564CAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDE146F6B09E70A6DULL + 0xCA81170823DA69ECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC1FEA02F23B9D98FULL + 0xB8A020CD3730C6A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9D2733DC85E9A8DFULL + 0xCB49288F45482EDDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC4279893E5F67977ULL + 0xF81396EE61A63B5AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE0A79D87A6C98B85ULL + 0xC00A2787842798EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD4B716F104CC8C91ULL + 0xF13345D81CEA28B3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA78AEE8DED6D9B4DULL + 0xC151287084A3BCE9ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6701U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 1756U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 3238U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7245U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6174U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 35U)) + 9654059367478508868U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 6473006635864677427U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 6944184481315853243U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 4061496421939102306U) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aIngress, 19U)) + 15791809275719085463U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14050798802646323055U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12072905924741758266U;
            aOrbiterG = RotL64((aOrbiterG * 4757104346636738119U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17639076509231343896U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12195388285571234715U;
            aOrbiterI = RotL64((aOrbiterI * 4317060502521195769U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4325404419499496529U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5910567888204238382U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 11503787177122206937U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13092940059929942699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13381962590820308761U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 6345904465930943295U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15622862439323440527U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14027151901132249793U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2273573821630510087U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererF, 4U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9459U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 12052U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10188U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15822U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15677U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10483U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 10U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 15036852811491820366U) + aNonceWordJ;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 305637140752898475U) + aNonceWordA;
            aOrbiterK = ((aWandererE + RotL64(aCross, 37U)) + 11948631574496129610U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 5321623592482991426U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aWandererC + RotL64(aCross, 58U)) + 4075270159062690728U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15111580500356908928U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7244150695504160363U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 2445733898697939969U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 5131563519577488862U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5881954992088651371U;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12780935808751507998U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12599159643925470226U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9466589929741834066U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6093158735705189789U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7453778295800853653U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17461243886150519249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15456408913739900718U;
            aOrbiterA = RotL64((aOrbiterA * 16093292401746174671U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 23U)) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 48U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21247U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 24220U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18128U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18869U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21594U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20145U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 898812731947995389U) + aNonceWordP;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + 8677347622525527167U) + aNonceWordD;
            aOrbiterI = ((((aWandererH + RotL64(aIngress, 36U)) + RotL64(aCarry, 5U)) + 770321564027567654U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 11020474858081526395U) + aNonceWordM;
            aOrbiterF = ((aWandererI + RotL64(aCross, 57U)) + 17289793580414993470U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10111912559295118444U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8083622125544542011U;
            aOrbiterI = RotL64((aOrbiterI * 3610772128071340341U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7149858558922988240U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5919683821379905699U;
            aOrbiterA = RotL64((aOrbiterA * 16705119888884231567U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 6860902846079238714U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15083517836867542075U;
            aOrbiterH = RotL64((aOrbiterH * 4686657139237578325U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14852868368708376381U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9860233289028878323U;
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 772406119079116272U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7971141501337627589U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 10168120622976358617U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 22U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29423U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 30161U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30302U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31515U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27145U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28241U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 28039U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 35U)) + 12131317914288566437U) + aNonceWordG;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 21U)) + 5672805657999385496U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 3581710244233124197U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 15251296040538489436U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 4U)) + RotL64(aCarry, 21U)) + 11295008604679904153U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2230897493419504490U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7109600123297458999U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8267799351136506307U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 13119156643107683803U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14755160867807355250U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10007087518844899239U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16829363373287496832U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16981122946707720883U;
            aOrbiterK = RotL64((aOrbiterK * 5394974422201576627U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8806000776958603317U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16810923047720876014U;
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8129657889554436328U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8653100378491974463U;
            aOrbiterF = RotL64((aOrbiterF * 11395283153912468661U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 20U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererB, 22U);
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

void TwistExpander_Golf_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA52919A809D9611DULL + 0xF628331F40B5CDEAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEE19202835A9F08FULL + 0x836FD6DB4112B595ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD2272AB0B81178FFULL + 0xA99213C17F8234E3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF52C5788FBD286D9ULL + 0xBDC56A8AB9E3756FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x814205F06BE01431ULL + 0xE3C7F23375C0A27EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCC5EF98EA90D7367ULL + 0xEB94BAAB35EC3A26ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBD029DF1D3314D0BULL + 0xF851CA2B4A65C445ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAA18AA14AD8699DDULL + 0xD4B35FEC8AE43BABULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xABAA296711A6618BULL + 0xDDBC33A9236109D4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9E45EF1BC75E3807ULL + 0xBCCF802F7B0DBD7CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x851B2ADC8BDF90FFULL + 0xB833E086D83EDEE6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE72F5413413162B1ULL + 0xCA174599C8A8ECB1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAEDEF5DBD1F5B40BULL + 0x8D38639DBAEC3641ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCDA3E37072CE8B3FULL + 0xB30A686A28A9C4E2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9B1189A6E8E4186DULL + 0xED33EAFA339DE8F9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD928CE82DA7C3CEBULL + 0xF89AD234C70F8ED6ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aOperationLaneB, aWorkLaneA, aOperationLaneA, aOperationLaneC, aWorkLaneB, aFireLaneC, aOperationLaneD, aWorkLaneC, aFireLaneB, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7734U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 127U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1571U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1638U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3105U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 5913U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 51U)) + 4384716820085860551U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 9715780315942116888U) + aNonceWordG;
            aOrbiterA = (aWandererK + RotL64(aScatter, 14U)) + 15963520052789178632U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 14346700690686392938U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + 6005518012489966643U) + aNonceWordP;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 21U)) + 2506732930310252119U) + aNonceWordJ;
            aOrbiterD = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 16782163084851775826U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 823673076571076303U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1634084509064077736U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1128407326773234517U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1288134975466877686U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4321412662318298283U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 220430672180734911U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10223923547068528867U;
            aOrbiterE = RotL64((aOrbiterE * 12577370238343872139U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11696469696177647608U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6545430420379636963U;
            aOrbiterD = RotL64((aOrbiterD * 8387163146257553773U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5624403902454498793U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9468064161002030997U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 8243560528100864595U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4619361544913629805U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12682446273369750704U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10879074713156075641U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterK, 20U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10581U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 13919U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14545U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15398U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15245U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14432U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 30U) + RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 1898718075389870739U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 24U)) + 5631794889237247403U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 18219714659484524607U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 15419581386225732921U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 5U)) + 9125575431710198210U) + aNonceWordG;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 35U)) + 12205871520544965505U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 7617534300497343422U) + aNonceWordH;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18017579105368135814U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10693882161946020042U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 2326507900303932855U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 11669615701700895306U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11045110212889232165U;
            aOrbiterA = RotL64((aOrbiterA * 5965171269273719849U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18019107802806469913U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12315940560472528716U;
            aOrbiterF = RotL64((aOrbiterF * 4505122470351404065U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4899009736070044310U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17412253404253730364U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10791901166391946485U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4826286251927854181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4523455921321845084U;
            aOrbiterE = RotL64((aOrbiterE * 14534103906736598099U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4132514462154182215U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7164745605985109269U;
            aOrbiterG = RotL64((aOrbiterG * 14107325508977225261U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6297434295807635654U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8813887638672996646U;
            aOrbiterC = RotL64((aOrbiterC * 17495632530773158201U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 34U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18533U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 17148U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21258U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21529U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21405U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16970U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 6467297102954816305U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 37U)) + 7921154109831114952U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 5701131763215638919U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 10022999076719002684U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 3U)) + 4367135243038982316U) + aNonceWordE;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 26U)) + 14445846824810383592U) + aNonceWordD;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 7683697954545773253U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17517006750428030899U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2052484792684025476U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 12463117571122469643U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6279463052085808926U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 679280153651813684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3047031560593583881U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2939516520188460569U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1960616434964712325U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 15145998415466343039U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12273819390719947361U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5685033154709449397U;
            aOrbiterG = RotL64((aOrbiterG * 9845666295874714959U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9314494172199500653U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15757631834636427621U;
            aOrbiterE = RotL64((aOrbiterE * 15483543888965744529U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10878078046389399574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3583495913766365232U;
            aOrbiterF = RotL64((aOrbiterF * 2913540984990155225U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7385544065754622301U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16839599460207922881U;
            aOrbiterK = RotL64((aOrbiterK * 240651605910592561U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 13U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 44U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26680U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 31536U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 31188U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26593U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27506U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27220U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 15316464782468770057U;
            aOrbiterH = (aWandererD + RotL64(aCross, 35U)) + 6642872057476351588U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 660732654689529192U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 7235418086884000655U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + 14784518476694580493U) + aNonceWordM;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 50U)) + 12222433977933449375U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 43U)) + 8573001207708329927U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16035256260815013172U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15767726974121910203U;
            aOrbiterK = RotL64((aOrbiterK * 719060452537759331U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17712217935322939971U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13488963456923357159U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10222949131965611079U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1495561412321657209U;
            aOrbiterH = RotL64((aOrbiterH * 9706305581868526265U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16156530750584361434U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7773792489045606309U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10730624207715601393U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 11544578291333360613U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 3665587867634242865U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 4840528190844842595U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15248434984650998090U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15487979645426567581U;
            aOrbiterE = RotL64((aOrbiterE * 10868107809356766183U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6972347795052712690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16074994810010431338U;
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 22U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 47U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 26U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Golf_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8ADA5A9996AE70E5ULL + 0xA3CA3A7D1D2EBE87ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8EBC2D4DA536A597ULL + 0xEAA0F981F1BE78D2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE956A5A0955CAF19ULL + 0xE6C3D0B183156C7AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD11EC8B55DA52275ULL + 0xCB25BDFC5490A392ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF25FC03696257ED5ULL + 0x858CA99F8BC1FDFBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE5E1B217C23022E1ULL + 0xF0C28330A7697C1EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9EC4625AA1E0B6B9ULL + 0x94E5ED603FDE7FB0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE1AE3CAB78DF0D43ULL + 0xD80C1E428A199920ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xED8473CC6D31BC4DULL + 0xFB1B3BFEE067FF09ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCD22C626E3356887ULL + 0xE0064DF4B35D7419ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD0B0C77432FCAA17ULL + 0x974C721AA9DE38E9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x88B86ADEDF357169ULL + 0xB1F5C2ED58925972ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE4EC1B425304AB17ULL + 0xB731519FC30A4D42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB46C47BD8DC8D0FFULL + 0xC8EF9279E2627836ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB27B9426264904C1ULL + 0xEA5319705B070840ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB33E514E478A79E9ULL + 0xF4EBCB302DBAFEBFULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneA, aOperationLaneA, aExpandLaneB, aOperationLaneB, aOperationLaneC, aExpandLaneC, aFireLaneB, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8006U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 2605U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1536U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6678U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7847U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 5902U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 58U)) + 14624277139785904404U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 6966977309498165611U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 11U)) + 205536824352530761U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 19U)) + 16629575265808255692U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 596881340147972746U) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 11944412799107412650U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + 4615021315668210206U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8497630055977606216U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11131601107309336885U;
            aOrbiterK = RotL64((aOrbiterK * 18028349768453554935U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5935883479805510099U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15629346719765798174U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 8535523790685945275U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5279128339113651273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16778365912440331821U;
            aOrbiterD = RotL64((aOrbiterD * 705421028266789241U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16003052937645491524U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6723226158737614764U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16690657664909260573U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9785784358981219543U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10055457337292292710U;
            aOrbiterH = RotL64((aOrbiterH * 17919129940751761111U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11779163108592974175U) + aNonceWordM;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 1177999477942202687U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 13475069421684114643U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9190694445141492214U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15605342360346353457U;
            aOrbiterF = RotL64((aOrbiterF * 14547769706392595647U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11159U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 8875U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15311U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8891U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13931U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8398U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 26U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 2101601659597850213U) + aNonceWordC;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 2759794072560720121U) + aNonceWordH;
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 9443562552411269339U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 10801360546699857975U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 30U)) + 8020716394829332019U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 1021894212367773801U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 13346855534622490176U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16359309548462953836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12642446944680783519U;
            aOrbiterA = RotL64((aOrbiterA * 12197935153255283321U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8197424982767553380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14346334610901859094U;
            aOrbiterF = RotL64((aOrbiterF * 16982899923227935679U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 14171304260534233539U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 334531601308283605U;
            aOrbiterB = RotL64((aOrbiterB * 5012968232749075075U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10707856298471572695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18364775750091914766U;
            aOrbiterI = RotL64((aOrbiterI * 15735143943129143265U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8531394793118363836U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 475199047053777179U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 567682016232278157U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2068146551757663119U;
            aOrbiterH = RotL64((aOrbiterH * 1557877740957797555U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7776122587613256525U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16430938890724272256U;
            aOrbiterD = RotL64((aOrbiterD * 4540270493783593257U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18593U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 24381U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20288U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21442U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23626U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18478U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 11998579547770778580U) + aNonceWordH;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 13U)) + 8409465187298704610U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aWandererF + RotL64(aCross, 54U)) + 3470222286110333500U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 5704486785203069994U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 47U)) + 10334944660253279633U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 7626852700722567477U) + aNonceWordA;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 19U)) + 14631310754943209743U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 807160297237854120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5624154783624196107U;
            aOrbiterJ = RotL64((aOrbiterJ * 2404066593958052159U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4971444394698940423U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6340057638461027062U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12027586111086798629U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9003019862787819481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13632057463595873033U;
            aOrbiterG = RotL64((aOrbiterG * 12575202147280216765U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12766104026871797746U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4062118445824915939U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 5258212525426469978U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9956946981015983939U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 8106382657040497669U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10837606223056473999U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13292864885504191134U;
            aOrbiterE = RotL64((aOrbiterE * 4445739587553669471U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 166087925900318658U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4411147600413147773U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25838U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 27794U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30662U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26096U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26101U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 26890U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 37U)) + 7075016829833562104U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 29U)) + 8783765886115517036U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + 2996723892384565829U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 9494134707342189476U;
            aOrbiterC = (aWandererH + RotL64(aCross, 51U)) + 5052642981395679904U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 8766787055127962238U) + aNonceWordP;
            aOrbiterK = ((((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 21U)) + 4467211954388738079U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 8030255604633658608U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16962408063455702251U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11171737929747471631U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3768222186567699076U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14930990410207899871U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 10930005786146268241U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14179761938395502502U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1879084742719898108U;
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5535012408925981515U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 12792553516710295939U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 8577530993755159329U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8979253163346099252U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5559189896063990740U;
            aOrbiterI = RotL64((aOrbiterI * 8832485423727331621U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13937564337299044079U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2393376759689394948U;
            aOrbiterK = RotL64((aOrbiterK * 2352815657830413941U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12647519563697356479U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10946871249960389549U;
            aOrbiterD = RotL64((aOrbiterD * 6272580371881237173U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF9A1528FB469E9ABULL + 0xE41AA756EF668DA7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA6BA0FD86E69F203ULL + 0x851BAAEE2746CC54ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC658FEFBCE5349C7ULL + 0xD6B78BEE9C73C2E6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD44968510C4589EDULL + 0xB59C8E6E822E4B72ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF524224E8160579ULL + 0x941632EB10356A56ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE5FE4139AC92CFF1ULL + 0xA88CA82F2E3BD79BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9E7D84144D48D619ULL + 0x999468CAF39D31EAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDB45C7971C88C13DULL + 0xE42AFBF62F6D50E7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA23CFA81CB981F63ULL + 0xEB7364004D7B33C4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFDA1344E2B0D51F1ULL + 0xEBB4C84474E4CE48ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBF8C64B3BB7AD17BULL + 0xBA734C0A1ED1A8F3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x81CFF552BC4B6A79ULL + 0xB3C479B96FB2E2B2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBE8B3F7C25C52AD9ULL + 0x85A6BEE7EF02E345ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF6D5850292ADEA13ULL + 0xDC019276A11D1647ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9C407A557B04ED31ULL + 0xEB2289897746B436ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD7893DCF1DFBB703ULL + 0x860A303472DC3601ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD, aFireLaneD, aOperationLaneA, aFireLaneC, aWorkLaneA, aOperationLaneB, aFireLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneD, aFireLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 246U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 7257U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 8150U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6378U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3213U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7871U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 51U)) + 9220392006207660113U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 11305018553489132882U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 5860373868073513684U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 23U)) + 12319586170883987589U) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 30U)) + 14072333614354649021U) + aNonceWordL;
            aOrbiterG = (aWandererD + RotL64(aScatter, 37U)) + 9332158529453194608U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 3860569321145958686U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + 8119005668901240093U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 39U)) + 13918259792880333239U) + aNonceWordA;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 13U)) + 6938856216758228704U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 57U)) + 3960905839118710604U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6043879193734253929U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15691425268831319195U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7189195135654636271U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14912209933584715274U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterA = RotL64((aOrbiterA * 3942858974766467849U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4966642362507707776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6962226782462822861U;
            aOrbiterJ = RotL64((aOrbiterJ * 3647802407741095419U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12409120845092026295U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2302946450253872465U;
            aOrbiterI = RotL64((aOrbiterI * 7099576330777297911U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16118304388937163838U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15968419034359049422U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11736207775827080165U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17098982091525008231U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10298979200690822062U;
            aOrbiterH = RotL64((aOrbiterH * 12620028874653521945U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 552826643694256437U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11786560990790695378U;
            aOrbiterC = RotL64((aOrbiterC * 11190309640069208311U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13730399230389329793U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17614226859252305432U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 2640019643570222977U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1062738267846296283U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13959480457644980835U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1194145909157002977U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4635071137794189167U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13374502212707796180U;
            aOrbiterG = RotL64((aOrbiterG * 129680788767298945U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11479902881487238033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9220392006207660113U;
            aOrbiterF = RotL64((aOrbiterF * 1437457810224888809U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererF = aWandererF + (((((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 27U)) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 40U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 44U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9935U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 15319U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 9709U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12129U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9149U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8831U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 23U)) + 10726035965553989335U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 967354339530195662U) + aNonceWordC;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 43U)) + 10834593005478605624U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 41U)) + 1012888282838656933U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 34U)) + 15283530351725183253U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 11724495956731703750U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 4288330117317505776U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 53U)) + 10894778070022873473U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 50U)) + 15563886747621617467U) + aNonceWordB;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 11182488628562891937U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 39U)) + 10420140066310588580U) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11775138062167543111U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16545391898578161683U;
            aOrbiterA = RotL64((aOrbiterA * 14588306527161321535U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1550144656312299266U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14903504853138279883U;
            aOrbiterK = RotL64((aOrbiterK * 8003033561266164387U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 309935535526750396U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13991265868040011411U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 2887531132228588441U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1755976294857114222U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2259275858478396846U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 7416165760067878161U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4838175912944552936U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12307900457200936013U;
            aOrbiterH = RotL64((aOrbiterH * 14719363144850838805U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18025411832912225805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 981375022769564523U;
            aOrbiterJ = RotL64((aOrbiterJ * 15869361544011831483U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3174014054982742562U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8119692378748963609U;
            aOrbiterF = RotL64((aOrbiterF * 3072354179707448489U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14502863160788675807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1207582534593709516U;
            aOrbiterD = RotL64((aOrbiterD * 3045412087535529357U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5838011917777875072U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 434594114594643600U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1591023655239709931U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15711060039063734443U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8307150522686198490U;
            aOrbiterC = RotL64((aOrbiterC * 2082452039297764679U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5805686529930815226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10726035965553989335U;
            aOrbiterG = RotL64((aOrbiterG * 5563221485243331689U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 10U)) + aOrbiterK) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 46U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22658U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 16688U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23293U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20442U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17044U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 16641U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 27U)) + 3105313968748067810U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 9977249451119627064U) + aNonceWordG;
            aOrbiterH = (aWandererB + RotL64(aCross, 11U)) + 17941392803495349366U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 56U)) + 4279533326705471133U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 13983828966811580039U) + aNonceWordC;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 3983490984234810378U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + 308786542215259956U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererF + RotL64(aScatter, 51U)) + 8443607695364427037U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 44U)) + 14939626441464340668U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + 9350693577306121110U) + aNonceWordH;
            aOrbiterE = (aWandererH + RotL64(aCross, 39U)) + 1717071159396961752U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15911765265202100610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14898546272333182767U;
            aOrbiterH = RotL64((aOrbiterH * 2674900543810733067U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3560903518513465868U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5367062725726860234U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 8521908836601319553U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15233321480618877327U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9288449812290126074U;
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5504840529511585676U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6825598386801620046U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11666542445846250077U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6433024450721339470U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 97934156644929458U;
            aOrbiterC = RotL64((aOrbiterC * 8630530773006923215U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3260053604798744515U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 16539416623243059076U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 12199577351166064503U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9814290051339038920U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13280156404507444041U;
            aOrbiterA = RotL64((aOrbiterA * 15269010043398910061U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11853942590993546833U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13207869904312989977U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15503461937625795969U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14536032167989376750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3693282775047432356U;
            aOrbiterF = RotL64((aOrbiterF * 5290349323647887877U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5803176485246280271U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16702526675475954730U;
            aOrbiterJ = RotL64((aOrbiterJ * 13695676754973145769U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16454171963808313625U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3105313968748067810U;
            aOrbiterK = RotL64((aOrbiterK * 16572687178789102843U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 28U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 36U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24685U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 30376U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 31377U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25718U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26320U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 26801U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 15904465836916519864U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 42U)) + RotL64(aCarry, 29U)) + 17725629806317789307U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 13794170125914914828U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 23U)) + 2149055907476874332U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererG + RotL64(aScatter, 3U)) + 5342047776745074649U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 48U)) + 8268148484060546838U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 10821151364028563719U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 37U)) + 4294213820894407378U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 13U)) + 10884726101307943090U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 16432210042202444824U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 27U)) + 15196602644336228055U) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14117787670220328165U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 219833877949480215U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 10736293047771972173U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3326396981881473962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14918513066311426279U;
            aOrbiterJ = RotL64((aOrbiterJ * 14269763278564574663U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11795234681370163206U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3068267285352664813U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15746255933920904619U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 245233356957999496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 709926406353796673U;
            aOrbiterA = RotL64((aOrbiterA * 13627039596842073595U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5378105439430271038U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10114555061122044430U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5351295043424885549U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13233010815716769713U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8231291294833548389U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 10840516135212753869U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7160760224172419829U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14767926435411546785U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1643485739468851073U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4464245330038080103U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15778166658285494712U;
            aOrbiterK = RotL64((aOrbiterK * 13980891936095282989U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2426340576450960905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6030631392508241438U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13921288910299408423U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15990180955119402476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8707879851984546959U;
            aOrbiterD = RotL64((aOrbiterD * 13794027045755532979U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11665969506971636052U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15904465836916519864U;
            aOrbiterC = RotL64((aOrbiterC * 17042355185093585101U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 40U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 4U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Golf_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8EA11987346CB549ULL + 0x8692A33AD6032CCFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFFD073A5C048C7C1ULL + 0xC14BE99B6C0CBBC7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBBD514994A64FC37ULL + 0xFBA5BBED0B9CD26CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE887DE8A6A4258A5ULL + 0xFF879613941B03E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD475734E5B682627ULL + 0xAF30F2F22E530F8AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFE2E765B6DBC4C03ULL + 0xD2224BD815C8A373ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBB6ECA69AB68AD83ULL + 0xFCEFC8AC923DBDB5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF60010EB9882BCE1ULL + 0xBA2A8F16456DB3A3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9355A7DE6C132625ULL + 0xA8BD6C875DE9497DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE355F92D65D30969ULL + 0xD26C3BE73989B6C0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC5D0836B83E0AFA9ULL + 0xDCDBEC5453E7696BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE26A1FCA4C9B6E5BULL + 0xB6D2FBE835822662ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBFCD1201572E9977ULL + 0x8149F57866CA9463ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC64F45975AA0FC55ULL + 0xEAA144A98D381A8EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCD0D9D5BA0666619ULL + 0xDF8E8DCB3EB7CBA7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD293D83E6C25CC73ULL + 0xA22804A9827C1E70ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aWorkLaneA, aFireLaneD, aExpandLaneB, aFireLaneA, aWorkLaneC, aExpandLaneC, aWorkLaneB, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2475U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 1509U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2029U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6679U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3882U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6205U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 53U)) + 1393781663398437180U) + aNonceWordO;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 46U)) + 17414594746688585273U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 2823888497053071250U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 5U)) + 17032631958617884859U) + aNonceWordL;
            aOrbiterJ = (aWandererB + RotL64(aCross, 57U)) + 15222697630461125019U;
            aOrbiterK = ((((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 15737414920751551780U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 1357196111055783001U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 18U)) + 5315122321649251691U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 39U)) + 7893744655508595974U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16721939414324611738U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3444375866323610848U;
            aOrbiterA = RotL64((aOrbiterA * 10874157227815775661U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1825716513674511632U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15582066843912467318U;
            aOrbiterK = RotL64((aOrbiterK * 12765146555943757373U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15673590949193923915U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13887365046280406413U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3169061375011420121U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 12730414371734709356U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4819112390640821927U;
            aOrbiterI = RotL64((aOrbiterI * 8782547948627685451U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3089925954422937464U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7180179304678622530U;
            aOrbiterE = RotL64((aOrbiterE * 16118051565147747413U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17030269962085008657U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6675917351883004046U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14134335325316949687U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12572022803491077491U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2801421744689267375U;
            aOrbiterJ = RotL64((aOrbiterJ * 315045745990934023U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4335148696780313055U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12526298573395110141U;
            aOrbiterD = RotL64((aOrbiterD * 11276803410698178607U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6984239833558496091U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12195433952105336808U;
            aOrbiterB = RotL64((aOrbiterB * 8642600547427664495U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 10U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 28U)) + aOrbiterH) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14358U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 11796U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15752U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12632U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14450U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11159U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 5173905450211892891U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 35U)) + 3555542451908039957U;
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 4U)) + RotL64(aCarry, 23U)) + 11559884700283861559U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + 1352524329968738673U) + aNonceWordM;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 47U)) + 8914206450420616349U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + 2251523378498463946U) + aNonceWordB;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 43U)) + 9541575923299247038U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 47U)) + 1239854507907214595U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 29U)) + 17698101462598498934U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12305566971683256060U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13804545036303215569U;
            aOrbiterF = RotL64((aOrbiterF * 10359543704152744971U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10239749097704329264U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4212214906286320308U;
            aOrbiterK = RotL64((aOrbiterK * 3661436621615751071U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12192418916967430783U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17376102613298827459U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18129393209955439341U;
            aOrbiterC = RotL64((aOrbiterC * 6404089025014118979U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4014763724300253568U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17325007199676828814U;
            aOrbiterD = RotL64((aOrbiterD * 1420888274815627083U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15480474849292388685U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14357924730184375449U;
            aOrbiterJ = RotL64((aOrbiterJ * 16723492259068034209U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4335731868597970070U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8296023680394303015U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 14027415401430120543U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2807312426993262800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15510369660839648501U;
            aOrbiterA = RotL64((aOrbiterA * 18207954408298333959U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12597844696606519907U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7231012798553551535U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2841306785994479299U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 56U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 60U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20241U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 24318U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 22968U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21544U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21001U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21766U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 2974056819475622600U) + aNonceWordC;
            aOrbiterA = ((aWandererH + RotL64(aCross, 18U)) + 7345051759236356098U) + aNonceWordG;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 12738468816846628882U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 7694520596043297922U;
            aOrbiterH = (aWandererE + RotL64(aCross, 47U)) + 5530753590015084774U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 5U)) + 3776309161718383105U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 56U)) + 784780304358106404U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 43U)) + 8999942326995036509U) + aNonceWordA;
            aOrbiterF = ((aWandererG + RotL64(aCross, 23U)) + 5194986506064092779U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7920040007459652762U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11311997270710107937U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5365231114813547251U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2358235238039571072U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterI = RotL64((aOrbiterI * 17150786106857185467U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14526050556461782864U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6937282036603272474U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14954512365270028029U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10105832250694931310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3884223553012098137U;
            aOrbiterF = RotL64((aOrbiterF * 16340956813003906195U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10385284339549648087U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1257633893341505930U;
            aOrbiterD = RotL64((aOrbiterD * 2669950791270500977U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5528890519572824318U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15664241747527713256U;
            aOrbiterH = RotL64((aOrbiterH * 16670884497088220497U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14264122979415331887U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17985061405540198036U;
            aOrbiterJ = RotL64((aOrbiterJ * 2729487440173395133U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1663986734997903415U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3706166884286400587U;
            aOrbiterE = RotL64((aOrbiterE * 10549736618301955745U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27412U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 27857U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30304U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32750U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24890U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 31680U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 42U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 8402620908307642697U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 52U)) + RotL64(aCarry, 41U)) + 11347672014525086047U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 2816462912503401876U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 6940159795470696093U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 23U)) + 9134692490095883851U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 27U)) + 4999455497008026526U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 5U)) + 5992451460350651332U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererI + RotL64(aCross, 48U)) + 3417087346651371924U) + aNonceWordO;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 57U)) + 3612773820086198270U) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 463398077083428570U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11249391303705089012U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7106735772303292983U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17027535139825739501U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 568131384979596481U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4793712537158004047U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10415170179135963622U;
            aOrbiterD = RotL64((aOrbiterD * 13729564030210361415U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2391473979460065630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4240058362680064261U;
            aOrbiterJ = RotL64((aOrbiterJ * 12375884373396400889U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9963957011090031698U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3325305624067445525U;
            aOrbiterF = RotL64((aOrbiterF * 3128542681461806309U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2094945647665114693U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10703615640774042674U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12641986098450423751U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3768738815518590289U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15021301790376706827U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 14445850924223550339U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10571246886181608316U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5130325144599151793U;
            aOrbiterC = RotL64((aOrbiterC * 3185251943547657467U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8617523421720966373U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 16574597770835250074U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 1759209403428937799U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 28U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterJ, 34U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Golf_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF6C345E6D7AEF10DULL + 0x933D1DD7AF09B71EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x94006A07E021E523ULL + 0x9B145AB66C023002ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA54FC6E6D1825E11ULL + 0xED4E18461BA1ECA2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB40A046387F5B3B1ULL + 0xDE60122AFC81D48CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8A52D361FF065BADULL + 0x8D7C90F231E9CAAAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD203F74132DF06CBULL + 0xA74E3EF3735B3C66ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC9FEC70A53274F01ULL + 0xA05191EC99FCAD68ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAD6640F0A3552FADULL + 0xEBA9621E0B55224BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD79EBD0166C5A46FULL + 0xE8EA4C6DB434FA13ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBA60F99CDF650E0DULL + 0xDAB4CEDBBE0163C3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x970B29DF331F82B7ULL + 0xCBF7322B650C36C2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD00D36972697A257ULL + 0xFEF5E2D1174436DDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB24A64B4607EED47ULL + 0x84CE27F48EC489C2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFA6BCB15032727C9ULL + 0xA3FC7DC7EB1F74A6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x96D60DD2857D2FC1ULL + 0x948F980631130A6CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB3C6D282B614523FULL + 0xDF2727CAE51735C8ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aOperationLaneA, aOperationLaneD, aExpandLaneB, aOperationLaneB, aFireLaneC, aExpandLaneC, aOperationLaneC, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6099U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 6740U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6573U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 75U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 300U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 2904U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 40U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 2672739400294801233U) + aNonceWordO;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 53U)) + 8475624545015101850U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 35U)) + 1252755112289831257U) + aNonceWordN;
            aOrbiterC = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 7938039507649183387U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 8167413146948861022U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 21U)) + 17712313989694374353U) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 7637042279892596975U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15770412950033467341U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3951812021898608685U;
            aOrbiterD = RotL64((aOrbiterD * 6623127125223204737U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8656983621098246507U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17943342344730687317U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 16495519451034883813U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3087677463651608668U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16493240011924342788U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7750923317452683057U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2185924841611106546U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14676868738946722416U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6849098251696302393U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2599806275837778069U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17817755047153606419U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9900465270314068757U;
            aOrbiterC = RotL64((aOrbiterC * 9267925873983176685U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11380000891112113701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15930503831156546113U;
            aOrbiterI = RotL64((aOrbiterI * 14450535035065393845U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterF) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10166U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 11157U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11646U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16131U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15713U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 8645U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 14U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 14179205183062705133U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 52U)) + 210032324058740920U) + aNonceWordO;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 7387115089142500152U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 13U)) + 17583362781238061430U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aIngress, 43U)) + 4991442849150005943U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2891376254689854555U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + 10523274382407446239U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3861893764676218667U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3366674459852093746U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 14005994095369483813U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5898492634386601145U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7047353571244768721U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 2257518291062508467U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14374108805453186316U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8763667021501226510U;
            aOrbiterG = RotL64((aOrbiterG * 7694695426430267863U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 18261523829316379575U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 650477532238860965U;
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2162326554604894042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5776546692501825278U;
            aOrbiterK = RotL64((aOrbiterK * 14911545784585246537U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3501863793638415049U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14853789267425352958U;
            aOrbiterB = RotL64((aOrbiterB * 10590325397179928739U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15399673014671329743U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12253428583438990426U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12052855472196447849U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 18U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18891U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 23211U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 21636U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23783U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20552U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17518U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 12615321415808640429U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 15712784676459931207U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 11013335427004930046U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 12U)) + 8298733856304768806U) + aNonceWordF;
            aOrbiterI = (aWandererF + RotL64(aScatter, 41U)) + 6207732959150824216U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 5U)) + 9769864876127544038U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererK + RotL64(aCross, 19U)) + 10782181918651152563U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5790454015845620939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15606578025386733803U;
            aOrbiterD = RotL64((aOrbiterD * 7079287329365566355U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5522352539991175304U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5993355818572869649U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15221467311057431139U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10864534396947622047U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12090053126235913528U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7250801471645972261U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14191181677234981396U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2258570108233924592U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 8307541155393855209U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8448114811381534603U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2702389315763499817U;
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17202184076718780200U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 150549910056015002U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 195034681254956335U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4910512055808124967U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4783477997418403079U;
            aOrbiterH = RotL64((aOrbiterH * 861977492146512865U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 30U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32591U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 29398U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25245U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25572U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31132U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28331U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 44U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 966899917801652720U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + 10996327672320748649U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 4188171566846621107U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 5886209243097387959U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 19U)) + 14940428957136728111U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 60U)) + 179187285531914832U) + aNonceWordB;
            aOrbiterG = (aWandererF + RotL64(aScatter, 29U)) + 6685351948936817752U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1894506461704029700U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4182760368636977082U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 972988091869133921U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12523318028514940790U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5059306166973366892U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2857409765717296483U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5890872367917643851U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17747338389865221534U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5306740664798049267U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13906227834259884100U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7152105382899756368U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 6772157117358310485U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17868101884759619240U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11758843266314148347U;
            aOrbiterA = RotL64((aOrbiterA * 5919135169337501485U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13950566197090324859U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17278105609930477854U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11431842718945107359U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9556785965646738355U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 841298436857932987U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 15077843186688841797U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 42U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Golf_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x98BC3F27E29F80F9ULL + 0x867A0AECFD7BB5D3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF3A4383A3B3CE90DULL + 0xAFC82243399D7CEBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA757C00BC1DC04EDULL + 0xA1F839FE73077E1EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE29A8A2079454DD1ULL + 0x8BC8F89DF47D07B9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9CEE8B0175E32417ULL + 0xA2DABF86FBC3092BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x81E6778045C65795ULL + 0xC95B600761421B3DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x90294F4145B14D53ULL + 0x8FCDA3E42A4F4DC0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xED74F211E9EEE01DULL + 0x9D353F0D35BDC5FBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x93C7DFA790D4A4C7ULL + 0x9D1660E72CD5A861ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDA2E444E28822717ULL + 0x980977C544DEEE46ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE26348F59126A0FDULL + 0xD0F1F14BE3B34A49ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x86FE0D5F66DF4D79ULL + 0xD4DB347CA772D6F1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA67C4D35E68CFEF7ULL + 0xAF3A235DFB0D573AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFE7C95D4BC147EADULL + 0x92BC6E4E792BBCF2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB26CAA80E94C158BULL + 0xFD70D811D81C0D13ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBDF3E102D0F28129ULL + 0xEABFBFF18FB2C3FDULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2295U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[((aIndex + 328U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2687U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 963U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 12809562813316740345U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 27U)) + 17084212535326321199U) + aNonceWordO;
            aOrbiterI = (aWandererK + RotL64(aIngress, 47U)) + 16074921689983846769U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 35U)) + 14027986153007120145U;
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 7633455951809250227U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererB + RotL64(aCross, 4U)) + 340989348513370174U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 5307820377645020116U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5605285015771527274U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5293500434746182790U;
            aOrbiterI = RotL64((aOrbiterI * 17674669610895537063U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7263156475892261811U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10672879570907433005U;
            aOrbiterA = RotL64((aOrbiterA * 2506338667179450741U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16659226780900986107U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9774892622769850665U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 7487477727543183211U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10728057184108279042U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5032485856947407217U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 14642241075374862345U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8386481273395203518U;
            aOrbiterF = RotL64((aOrbiterF * 11649977733867003445U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2874153265304098104U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11519900149177261000U;
            aOrbiterK = RotL64((aOrbiterK * 2010158758971864505U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8885690878540115768U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4482143389870987714U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7105332459437434281U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 42U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterH, 58U)) + aNonceWordC) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 54U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererB = aWandererB + (((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U)) + aNonceWordB) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 2839U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2956U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3687U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3620U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 44U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 52U)) + RotL64(aCarry, 21U)) + 14157904117287696136U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 29U)) + 7369512677371640676U) + aNonceWordN;
            aOrbiterB = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 8411250745902073798U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 5002041814539710275U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 3U)) + 9538041410816283124U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 23U)) + 5210700103927513061U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererK + RotL64(aCross, 43U)) + 7600709399101287982U) + aNonceWordO;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2366369466696580499U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5544575244203019109U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8710073749110329779U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15998211310115361630U;
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15354357553877376422U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10657523549259276169U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10405750198355464768U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3465819693133515142U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14678343718277562799U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16724189641701408630U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 3484340153620198872U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 17247547677520703125U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7420442404884871126U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11138445997256757636U;
            aOrbiterI = RotL64((aOrbiterI * 11167543379937571127U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1428191560884663125U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16950093140800653985U;
            aOrbiterC = RotL64((aOrbiterC * 4423012306984814805U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterC, 12U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterF, 21U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aNonceWordE);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6764U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 5719U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7912U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7297U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6201U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 14499676118633326000U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 22U)) + 17191273593018552288U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 4085176294948097737U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 11U)) + 11112671474158908186U) + aNonceWordE;
            aOrbiterD = ((aWandererE + RotL64(aCross, 5U)) + 8745787969012266485U) + aNonceWordO;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 29U)) + 18074049663777707948U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 2543758649719164688U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4659584749412700523U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 974639159259871273U;
            aOrbiterJ = RotL64((aOrbiterJ * 17918719351847605523U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9211220687971081987U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8567024626862182714U;
            aOrbiterA = RotL64((aOrbiterA * 7755874089832496393U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5803002132294840900U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11968489432878148467U;
            aOrbiterC = RotL64((aOrbiterC * 4501441062617123165U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9470807228394903442U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1692347973120388469U;
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16510815732690193145U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 755159406833096510U;
            aOrbiterD = RotL64((aOrbiterD * 14091736464659561165U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1518824876475937620U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 701225390867330446U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12264618860580199927U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8425976693733003889U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7182176375442410367U;
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 20U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aNonceWordP) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 34U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 18U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aNonceWordN);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10833U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 8968U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 8304U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 10204U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8338U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8785U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 50U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 7722279280863371124U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 36U)) + RotL64(aCarry, 29U)) + 11584220561732385598U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 7834679350105534657U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + 11347994382444180879U) + aNonceWordI;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + 9449903188047063431U) + aNonceWordC;
            aOrbiterK = (aWandererI + RotL64(aCross, 21U)) + 6516243976652795170U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 8420815253991184777U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9081386852515170937U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14375955191735286867U;
            aOrbiterG = RotL64((aOrbiterG * 2772840314542262283U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 880757589768436072U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3349856625725164229U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 681514212582331781U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7826309957607577207U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8057435761214313635U;
            aOrbiterK = RotL64((aOrbiterK * 4718430712767038607U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9565237500443303103U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3276844534476430842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6828644383891274120U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2815676923011504251U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5030251870850928417U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7075653570570819253U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13464083008377887034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8994560761846897590U;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterK, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13112U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 13267U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13177U)) & W_KEY1], 23U) ^ RotL64(mSource[((aIndex + 13297U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13476U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12198U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 13565U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 12122689833405846292U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 9640400270962766788U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 9141937998266739071U) + aNonceWordC;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 12899395770434090537U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 56U)) + 13457918115408031842U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 29U)) + 15134784483576000943U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererK + RotL64(aCross, 3U)) + 12540961268790055438U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6306886773092764230U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13573343491337243121U;
            aOrbiterE = RotL64((aOrbiterE * 15893457012357368707U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8545588657348974413U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 10891410570357275120U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 5399310978367842841U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2877137119767060151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9178097682386595144U;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15528007881855616978U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11368419529245281435U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12433207037378339309U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5932738914934356645U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 5551842263864055419U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 16093776759971522681U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3824433359595690603U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17184628855571662441U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 691208053136187317U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8724462245014132623U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7481349499528092352U;
            aOrbiterD = RotL64((aOrbiterD * 8212182934509617583U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 12U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + aNonceWordH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 21U)) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordA) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13963U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14501U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15278U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14284U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14087U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16374U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16260U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 1866656689936219099U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 19U)) + 2312314528139448289U;
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 3554037526469185237U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 35U)) + 405707755060974111U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 3U)) + 1862976326004007697U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 12992483065443288263U;
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 3793854946371595197U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4244007978867369382U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10280867500312580308U;
            aOrbiterJ = RotL64((aOrbiterJ * 13729899124177931289U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 472563452959164242U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12041770406895816553U;
            aOrbiterI = RotL64((aOrbiterI * 17811798500132002631U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6118634015704900486U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13637107920449233307U;
            aOrbiterE = RotL64((aOrbiterE * 17712028184714868053U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16673735670669318830U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8602681273646630496U;
            aOrbiterC = RotL64((aOrbiterC * 6995213887710749241U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7683264695930369476U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9146674871199188218U;
            aOrbiterA = RotL64((aOrbiterA * 7403427067419261981U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 3012935612827493084U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1259789268731661945U;
            aOrbiterF = RotL64((aOrbiterF * 2372843620327050137U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5623690455471160780U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18355567776031865462U;
            aOrbiterD = RotL64((aOrbiterD * 9553862670107886679U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aNonceWordO) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17948U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 16783U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 16388U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16783U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16808U)) & W_KEY1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19057U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17785U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererI + RotL64(aCross, 60U)) + 6024062041314952357U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + 18340757093658015585U) + aPhaseGOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 27U)) + 11911120493880346751U) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 17428074353884654439U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 11U)) + 12790849760814795936U) + aNonceWordI;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 12633397052172117800U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 11946150433665237945U) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16842157900909419285U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14186235783224155962U;
            aOrbiterE = RotL64((aOrbiterE * 10521157787073684417U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13284904542579767591U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11609181965078844357U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5455780554452453513U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9628562297095374984U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7850281529011259759U;
            aOrbiterD = RotL64((aOrbiterD * 17611485102925470357U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 257458718073794527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10693404545773519306U;
            aOrbiterJ = RotL64((aOrbiterJ * 14821443722828498323U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3430519236533871460U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6183054506953198055U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 6121082743789970911U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2905610989884221654U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4472163910775333862U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 7770678426310856745U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16870142883133769663U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1403692060594816451U;
            aOrbiterA = RotL64((aOrbiterA * 9740854430251597879U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 42U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 50U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19206U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 21266U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19614U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 20965U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20252U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20665U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19783U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 19967U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 9041099828460168106U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 12883711604096848454U) + aNonceWordF;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 57U)) + 17420968786226443079U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 36U)) + RotL64(aCarry, 51U)) + 3448213891716125104U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 5U)) + 11866455977445336560U) + aPhaseGOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 29U)) + 4119356835384495905U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 43U)) + 2186212599698637068U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6506144898969301620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12556800923644051626U;
            aOrbiterJ = RotL64((aOrbiterJ * 15961043406612913121U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4075551535185182945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17877694808492008749U;
            aOrbiterB = RotL64((aOrbiterB * 901315308379887473U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5553428900598223316U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14362304852277160675U;
            aOrbiterA = RotL64((aOrbiterA * 11415103199856419303U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9174200302876075831U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16110739511917638547U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7004356839428657949U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10189881974519849402U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 2128076632642616677U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 8860453653433114929U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18133523799074400083U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9916472958834153766U;
            aOrbiterH = RotL64((aOrbiterH * 3454601168808001733U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10274457562795569227U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14134814273275356425U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15912501063665343159U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordI) + aPhaseGWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererB = aWandererB + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 22U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordM) + aPhaseGWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22142U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 22037U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23105U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24503U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22492U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24516U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23202U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23862U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 18U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 28U)) + 13350544654542863236U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 12364346790125404372U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 3U)) + 9738750172849512764U) + aNonceWordG;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 21U)) + 3781373837635491421U) + aNonceWordP;
            aOrbiterD = (aWandererD + RotL64(aScatter, 41U)) + 16635020317512702337U;
            aOrbiterG = ((((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 5383653921676231276U) + aPhaseGOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 10181959815492056493U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10005510924273927017U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9524687662265740565U;
            aOrbiterK = RotL64((aOrbiterK * 13687380438646756931U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4259138552009771014U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8973051213213726023U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12625091476068190979U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17602611840127337490U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18102186122213487888U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2629927500298092976U;
            aOrbiterD = RotL64((aOrbiterD * 6983280164448292723U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2491581597835795234U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9506602492971620955U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9559829640915637163U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13422942713680612924U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15037354693234876601U;
            aOrbiterA = RotL64((aOrbiterA * 12692376075738621447U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12896066842192894694U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2202952306291905855U;
            aOrbiterH = RotL64((aOrbiterH * 6779368532763429997U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aPhaseGWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + aNonceWordC);
            aWandererD = aWandererD + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordD) + aPhaseGWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26245U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 25613U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25033U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26790U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26207U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27294U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25561U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25511U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 966899917801652720U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 36U)) + 10996327672320748649U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 4188171566846621107U) + aNonceWordN;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 19U)) + 5886209243097387959U) + aNonceWordD;
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + 14940428957136728111U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 11U)) + 179187285531914832U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 6685351948936817752U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1894506461704029700U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 4182760368636977082U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 972988091869133921U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12523318028514940790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5059306166973366892U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2857409765717296483U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5890872367917643851U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17747338389865221534U;
            aOrbiterD = RotL64((aOrbiterD * 5306740664798049267U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13906227834259884100U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7152105382899756368U;
            aOrbiterH = RotL64((aOrbiterH * 6772157117358310485U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17868101884759619240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11758843266314148347U;
            aOrbiterJ = RotL64((aOrbiterJ * 5919135169337501485U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13950566197090324859U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17278105609930477854U;
            aOrbiterI = RotL64((aOrbiterI * 11431842718945107359U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9556785965646738355U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 841298436857932987U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15077843186688841797U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 4U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 12U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 19U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordO) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28210U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneD[((aIndex + 29626U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28981U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 29261U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28680U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29998U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29824U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27990U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 11U)) + 12206125048349568300U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 5843520589343188818U) + aPhaseHOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 12195046124287121687U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 16769779119214020640U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + 5257603646260695833U) + aNonceWordL;
            aOrbiterF = (aWandererD + RotL64(aIngress, 53U)) + 8523523946234886745U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 7316024684200084096U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11996978575084115207U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15491711479085513628U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 15136690392026011819U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6036648530996821484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 926323222234121863U;
            aOrbiterK = RotL64((aOrbiterK * 6639661141258803779U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2700323841295743492U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5852273765810284935U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16665696735016345215U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11697397483133538067U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17777142964957007194U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 6338967222543284999U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10892176201151170298U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11759700374509499684U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247697264744736081U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11343756773329590643U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15785048929757652350U;
            aOrbiterA = RotL64((aOrbiterA * 17208103574389502597U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7508839228498497238U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13088508510402094665U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15730279447009669103U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + aNonceWordF) + aPhaseHWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 37U)) + aNonceWordC) + aPhaseHWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aCross, 60U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32141U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 32234U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31054U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32545U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32564U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 32061U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 47U)) + 7075016829833562104U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 54U)) + 8783765886115517036U) + aNonceWordL;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 2996723892384565829U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 41U)) + 9494134707342189476U) + aNonceWordD;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 5052642981395679904U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 21U)) + 8766787055127962238U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 4467211954388738079U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8030255604633658608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16962408063455702251U;
            aOrbiterC = RotL64((aOrbiterC * 11171737929747471631U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3768222186567699076U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14930990410207899871U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 10930005786146268241U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14179761938395502502U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterK = RotL64((aOrbiterK * 16783034788172670121U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5535012408925981515U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 12792553516710295939U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8979253163346099252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5559189896063990740U;
            aOrbiterJ = RotL64((aOrbiterJ * 8832485423727331621U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13937564337299044079U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2393376759689394948U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2352815657830413941U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12647519563697356479U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 10946871249960389549U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 6272580371881237173U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aNonceWordK) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 36U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 36U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Golf_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF0E098305905BBB5ULL + 0xCCCF2B9CDD2E72D8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9E02AE1D772FC9C7ULL + 0x8EFFAE69F1E98E64ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE301A84146FBAFF7ULL + 0xE5B8125CAED09E37ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEB2C96C179012797ULL + 0xBF0249294F0BE132ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEA5574CC3CEB1591ULL + 0xF7A4A58A73A26E0CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF9678D5AD9FC708DULL + 0xBCC98F74248F1A3BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8FB16B0864E63023ULL + 0xDADC4174A2017809ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF82DD801C6A3034FULL + 0xB08C93E194BFB4A5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFC036953001408EDULL + 0xBCE3638644CE45CFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB86B34F1BEA2E403ULL + 0xB4F565C112C6FB72ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDD946EB9EE3D96E7ULL + 0x926B876A2FE8ECFBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA4A26D18062B5DB1ULL + 0x81C5E690D2A60C36ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD394CE97561A5EEFULL + 0xB0504769E620ED49ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF26B2CD8B97B50ADULL + 0xE5ABDBAEFCE41180ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9EFC200C9FE97653ULL + 0x8F7978FFFC025D3BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB0C87DB6E8A638D9ULL + 0xCA256AFA62FBEB2AULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneD, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1861U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 4075U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3550U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1117U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 369U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 3621877681473089725U) + aPhaseAOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 3U)) + 4451752751536414717U) + aNonceWordC;
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + 11371625415377772117U) + aNonceWordJ;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 6046792758881150619U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 8213166120394461682U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4343156661140422645U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11105271483234947905U;
            aOrbiterF = RotL64((aOrbiterF * 853531080115819287U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 348904609985341372U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12924652822526858767U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 2801892489296408735U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7461211697358520287U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16551553555297890558U;
            aOrbiterA = RotL64((aOrbiterA * 16432952324635746293U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11908056404140782995U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 9147367258259948715U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 10777628928376261667U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8876461054692728610U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 10546855952702525404U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 10071104785895309677U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 22U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10456U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 9894U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 6729U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9813U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 5591U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 43U)) + 4773124477323378268U) + aNonceWordA;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 16848723289435796005U) + aNonceWordD;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 21U)) + 13846642134917107058U) + aNonceWordN;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 6472057872482789939U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 2747019500690707226U) + aPhaseAOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9003965289739733880U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3013390651936257377U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11081353600889943167U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3331004709895625067U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15355010435553517129U;
            aOrbiterF = RotL64((aOrbiterF * 8322759117004876831U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7709870658004280052U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13568728443963926564U;
            aOrbiterD = RotL64((aOrbiterD * 6736090830113688981U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12409548853419307131U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 969183352023661537U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 5549220554838837145U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15370309834426476775U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3896803894396631184U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11018830202891911603U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 16217U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 12034U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 11260U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13323U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11987U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12171U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 4259993311776766595U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 2857813330021126753U) + aNonceWordN;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 29U)) + 1345396841329442896U) + aNonceWordL;
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 12U)) + RotL64(aCarry, 57U)) + 320992148982301024U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + 5619109532065293074U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10380157329426706345U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 12449831150625409695U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 3354095240459774437U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7847096607042268396U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 11707184096803214678U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 1959476948106553973U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9893643746186827088U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 333687403830908774U;
            aOrbiterG = RotL64((aOrbiterG * 17911256836121454271U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13837360705077441580U) + aNonceWordE;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 4367119682175710689U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1193493435041306784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15062951612027370606U;
            aOrbiterA = RotL64((aOrbiterA * 2509383510565136549U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 10U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aNonceWordB) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21212U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((aIndex + 17331U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16853U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21177U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20979U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21466U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 29U)) + 15188686795415908074U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 39U)) + 17310049041983079779U) + aNonceWordA;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 8246925977992441471U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 21U)) + 8644260919918112781U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 13401663736874819483U) + aNonceWordJ;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7940358935238314973U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13278990328548007839U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 285726811877787411U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11346868298353840706U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2374077904806833579U;
            aOrbiterE = RotL64((aOrbiterE * 1765686942154321425U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6978903378645019166U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11951633297870965212U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 12778236598654492185U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17398460995357409673U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 1215437945597836770U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 9322970054123481621U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 1878751468043972239U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5343002808239712390U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11878640995447558811U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 56U)) + aOrbiterA) + aNonceWordL) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterA) + aNonceWordG) + aPhaseAWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21866U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 23138U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 23293U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23709U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23710U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23272U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 3199575576585871314U;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 2533378188975571824U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 6819782112558312658U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + 12690060987724798497U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 36U)) + 7088375139715629606U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17785618677423695666U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1714999280296491277U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7675674437417383741U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 17611338506932491624U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6475727359297421201U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 15133348244242438069U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2347744591204119530U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2739317903351401068U;
            aOrbiterE = RotL64((aOrbiterE * 15435029315209475631U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8663535261373274338U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8205245127823536479U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8916510616749754516U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3944805940148512932U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18082271583211389701U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 48U)) + aOrbiterF) + aNonceWordC);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordD) + aPhaseAWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32570U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 30398U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28987U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32474U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28811U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31084U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 17081642665820489793U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 39U)) + 14468854040067229623U) + aNonceWordB;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 2249450222593057429U) + aNonceWordJ;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 43U)) + 14964389079511378664U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 21U)) + 17003491054252360650U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12710882240582032588U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9887078182156755359U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8205865025853482573U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7665284531810584704U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7304284015511876717U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 6193179739025093929U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5517927023543751734U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17704756310857362759U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15826832172923213591U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11347400363019508578U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11696395232760991243U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10875780291242873583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7808740614343437672U;
            aOrbiterH = RotL64((aOrbiterH * 8889516201913716283U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 44U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aNonceWordM) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 53U)) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Golf_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB0686F9A6EAC9F17ULL + 0x923FDADAF7447B1BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x86904D5959538037ULL + 0xF6B6F352616AB9B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF7A331DAEB0ABFA9ULL + 0x87893F0C87A9266EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDCC282C1D6892A4BULL + 0xE6BF8B697A46DD0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFFB4C7A9E2F65867ULL + 0xAFFF41D8EA0A8A7CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE95ECE7F8637BC15ULL + 0xE9AD3F70880446F8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF769C1CC4C708A3BULL + 0xBF9999B27606BA5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF2154B008B4FAD5ULL + 0xF4DD40A2A1CC35F8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x89A7D9F356FB9E13ULL + 0xF60D29DD974C3E13ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAD20B8B8FFD13E99ULL + 0xC79BF00540ED3607ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAEBDCAB54AEC25BFULL + 0x802EF32174B19D62ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD6480AB0191029E1ULL + 0xDD15326E4137547DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA8EB886B6D785EDDULL + 0x8985957838B7A27BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD10970979B6B9531ULL + 0xCFFD393AA9DDE22BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB171E7095DA850CFULL + 0xDCBEEEBFE07C3F25ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF131EAD1DFF0A1BBULL + 0xC8031CEB9540067CULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC, aInvestLaneC, aExpandLaneD, aFireLaneB, aInvestLaneD, aFireLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneA, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3444U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 3870U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4904U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5286U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 288U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1006U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 50U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 47U)) + 11450949896247900941U) + aPhaseBOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 3905542253538116335U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 24U)) + 9529740545977785305U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 51U)) + 1856876631533143492U) + aPhaseBOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + 84253466320181686U) + aNonceWordJ;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 3U)) + 12577480918745432444U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 5625703170397704029U) + aNonceWordM;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 694608607323629282U) + aNonceWordP;
            aOrbiterH = (aWandererD + RotL64(aCross, 56U)) + 3993981243536262204U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4119215953484892051U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8785040118556157146U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 17113521266125471625U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16234403619456882890U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10398727475672860610U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5086871400049644715U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18327987141759096769U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2645964788056875452U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8778681366114628045U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2859452497983106129U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7196557924940881076U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 14415389907490256711U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 930127943984174668U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15673596916054795749U;
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16673140529110941163U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2258448294877833760U;
            aOrbiterD = RotL64((aOrbiterD * 1821550319748977445U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6870209259643931219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12749790107942194104U;
            aOrbiterA = RotL64((aOrbiterA * 4871407285968611725U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17131374134617173866U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6426448390733751612U;
            aOrbiterG = RotL64((aOrbiterG * 12490559588384058417U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 15592826434339731146U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14182944418026376183U;
            aOrbiterH = RotL64((aOrbiterH * 7218860482893476233U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 54U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10420U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 9008U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6149U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6176U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6106U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7767U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8236U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 42U)) + 4384716820085860551U) + aNonceWordG;
            aOrbiterK = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 9715780315942116888U) + aNonceWordK;
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 15963520052789178632U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 23U)) + 14346700690686392938U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 57U)) + 6005518012489966643U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 50U)) + RotL64(aCarry, 37U)) + 2506732930310252119U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 16782163084851775826U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 11U)) + 823673076571076303U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 35U)) + 1634084509064077736U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1288134975466877686U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 2998220403162908444U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 4321412662318298283U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 220430672180734911U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10223923547068528867U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12577370238343872139U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 79691451831797107U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8971444023498649419U;
            aOrbiterK = RotL64((aOrbiterK * 7148919880477390009U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 5624403902454498793U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9468064161002030997U;
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8728730962617599223U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9099675924074253030U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3298303921318288541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5953276499411658358U;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6725769507592688539U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1057277456510215817U;
            aOrbiterC = RotL64((aOrbiterC * 8269412198279297075U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 54U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 52U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterE, 10U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13132U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 15527U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 11146U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14649U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 16245U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 5480870806135400132U) + aPhaseBOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 53U)) + 8034874599430768743U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 19U)) + 4006919843736863767U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 24U)) + 2988069748674633718U;
            aOrbiterD = ((((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 12347295651973135786U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aCross, 13U)) + 14152683894431568192U) + aNonceWordH;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 37U)) + 15765143815254196598U) + aNonceWordJ;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 10473067082331244233U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 30U)) + 1089466925383677249U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13215039929873682230U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3957997712247961479U;
            aOrbiterA = RotL64((aOrbiterA * 7631186240013784703U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10023907397941685546U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14593012591254614353U;
            aOrbiterD = RotL64((aOrbiterD * 17111300092082154687U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13353797968154036726U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9259966668512102858U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 8326732574268308221U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10757861831070349321U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10530223113483866178U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11269177745265396583U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 7554320926405521865U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6978052067277966996U;
            aOrbiterE = RotL64((aOrbiterE * 18020134738536217801U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1053695861967171420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15980734683539854451U;
            aOrbiterJ = RotL64((aOrbiterJ * 3208466640010555357U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17041258393808061556U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12846551858751995530U;
            aOrbiterI = RotL64((aOrbiterI * 9303891433380993639U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14617434286683320666U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3999309956180741302U;
            aOrbiterH = RotL64((aOrbiterH * 15037707937050015205U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13452627760403094126U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2633241575260427158U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 2638570213290747581U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 38U) + aOrbiterJ) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 42U)) + aOrbiterC) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20160U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 18397U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 17348U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18392U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 17083U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererG + RotL64(aScatter, 3U)) + 8793908991006073956U) + aPhaseBOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 23U)) + 2932916283348441943U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 11069042087940968262U;
            aOrbiterH = (aWandererE + RotL64(aCross, 14U)) + 14369628676782894441U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 8602903272780978282U) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aIngress, 57U)) + 3827036107178568820U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 8905245209036772489U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 13331387530760017893U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 48U)) + 9880107580289737823U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10199619040626900278U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2466307560891374281U;
            aOrbiterD = RotL64((aOrbiterD * 6295342978834217571U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13973403407981259448U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2851460278409385243U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10365453393815690776U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5058198848163792422U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10500434740387593487U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5946747708776079787U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11289798395177667084U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14327152153231286666U;
            aOrbiterK = RotL64((aOrbiterK * 18155778059595245561U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8065137263811956313U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3865153574847924816U;
            aOrbiterI = RotL64((aOrbiterI * 9495741102667755161U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18102279969722473375U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6306428427188742325U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 17826782872351406167U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16953348204663693724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11950791817032898613U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 1498946055469611133U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11980823193543752994U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17845490308799454871U;
            aOrbiterG = RotL64((aOrbiterG * 16385153013485463791U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + aNonceWordI) + aPhaseBWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 38U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 18U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24680U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((aIndex + 21873U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27047U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25551U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24826U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 701291026547470433U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 23U)) + 17283292650462111643U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 28U)) + 9969124091931303406U) + aNonceWordL;
            aOrbiterK = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 889176772718046988U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 6054541844643748084U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 51U)) + 14703226235143028132U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 18U)) + 7977975878522921062U) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 43U)) + 16894322614172266274U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + 12160451749345900570U) + aNonceWordO;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10870847008043897470U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8159920947172520247U;
            aOrbiterA = RotL64((aOrbiterA * 4833194641611011805U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 2440099120969517932U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2428396147731468007U;
            aOrbiterC = RotL64((aOrbiterC * 9363073341539598441U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2213226274394673479U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7079731443427765333U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16918930776877030559U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 958896789550478970U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10788682955708075458U;
            aOrbiterK = RotL64((aOrbiterK * 913321215613559729U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2003386579317564870U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8419686358774204999U;
            aOrbiterG = RotL64((aOrbiterG * 6547052526438697621U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6989167615157578904U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17636634003643824148U;
            aOrbiterD = RotL64((aOrbiterD * 11038576417283732937U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13824962118933907859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9543912892587859646U;
            aOrbiterI = RotL64((aOrbiterI * 14736710162285997415U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15729878041027706114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9542137475454825463U;
            aOrbiterF = RotL64((aOrbiterF * 11420547128115090491U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5327302277575009955U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2707383132257428583U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 6120763309390182129U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28005U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 31366U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29594U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29475U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28912U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 22U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 19U)) + 4068921616130916949U) + aNonceWordE;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 12077715273915151726U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 16047546802670596833U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 11U)) + 9690277462716999763U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 35U)) + 14484814700447992628U) + aNonceWordC;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + 17089267243053958210U) + aNonceWordA;
            aOrbiterF = (aWandererF + RotL64(aIngress, 24U)) + 9138746214446211147U;
            aOrbiterC = (aWandererE + RotL64(aCross, 39U)) + 10181001536979097045U;
            aOrbiterI = ((((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 6657458969093373191U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7515983477876590988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3039935555863947600U;
            aOrbiterH = RotL64((aOrbiterH * 12511160550780270119U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16209389224740851136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 725253312098083182U;
            aOrbiterG = RotL64((aOrbiterG * 17535989492095522597U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13307041115748941383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7159572004825238263U;
            aOrbiterC = RotL64((aOrbiterC * 4855009895002398449U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12027236743251643820U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8717826175991286553U;
            aOrbiterD = RotL64((aOrbiterD * 1175614802543098451U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4769096034227659937U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11201226563992939616U;
            aOrbiterF = RotL64((aOrbiterF * 15595355978388159931U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17295978531215563256U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11850923890626719833U;
            aOrbiterE = RotL64((aOrbiterE * 3854851059897397075U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14139441565288097706U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 988684899382304485U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 11929090869999700891U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6159251276942253175U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 4849529993914550651U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 18240712676783671317U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6679745455842119497U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15838404437552215214U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17357853511591350887U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 42U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 18U)) + aOrbiterC) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterB, 36U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 5U);
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

void TwistExpander_Golf_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA25FEA67FA1E25F9ULL + 0xD2DD4FA8F633ED99ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAD7E97AD7A61C6C7ULL + 0xBF4AB80F90DB9979ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD7B284C6E9B59373ULL + 0xB2EF34914477CB70ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9E204C97F0D5704FULL + 0xED4B3A89B7981082ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCA3418239C8E98DFULL + 0xE246A0342AB2E0B5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x85B03A828593CFC7ULL + 0xE46255BCC478F6A9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF078EAAA57DAEBBFULL + 0xC4540E7D2B2A4EFBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC252323FF6DFDC21ULL + 0x890056116D187F40ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA708F5064AF747A1ULL + 0xDE08299FCF2426F7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x861B4C67DA20F0F9ULL + 0x9B20113586EEAFA1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDC70FA71F103772FULL + 0xB1E6FE1ABC4EEBC6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFD82922BEAE49273ULL + 0xEF441D10C4F5758AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD913706ED9017DEBULL + 0xCC822FC7425D95A0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD11E60F46073691DULL + 0xDFA99EC9BAE0E0F3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF59EBD9970E53607ULL + 0xD6172CF132A311A6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x88BA177BD8C900A7ULL + 0xABC6D1F31E870A4EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1363U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 1399U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1853U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1343U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 386U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 1268U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 41U)) + 1866656689936219099U) + aNonceWordM;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 2312314528139448289U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 48U)) + 3554037526469185237U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + 405707755060974111U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 1862976326004007697U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 19U)) + 12992483065443288263U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 3793854946371595197U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4244007978867369382U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10280867500312580308U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 13729899124177931289U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 472563452959164242U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12041770406895816553U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 17811798500132002631U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6118634015704900486U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13637107920449233307U;
            aOrbiterA = RotL64((aOrbiterA * 17712028184714868053U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16673735670669318830U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8602681273646630496U;
            aOrbiterE = RotL64((aOrbiterE * 6995213887710749241U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7683264695930369476U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9146674871199188218U;
            aOrbiterK = RotL64((aOrbiterK * 7403427067419261981U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3012935612827493084U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1259789268731661945U;
            aOrbiterF = RotL64((aOrbiterF * 2372843620327050137U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5623690455471160780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 18355567776031865462U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9553862670107886679U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 4U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA + (((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U)) + aNonceWordI) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 54U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordO) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10827U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 7685U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6762U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 7413U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7299U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8830U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 7289U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 51U)) + 1557680213571812384U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 7387349725778021121U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 13U)) + 15379264067601586976U) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 57U)) + 3730195724576043708U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 30U)) + 9637070085323827066U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 1170865717363676184U) + aNonceWordO;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 2750833653175252030U) + aNonceWordD;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 15118992811225568305U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4974092922102988451U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10575977398702460975U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10625719096296719514U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 855167122475471865U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 7441090331293158773U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11322911068958340262U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterK = RotL64((aOrbiterK * 10059025861172038183U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14263701737208936392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 678723206735649084U;
            aOrbiterH = RotL64((aOrbiterH * 10823239851733632227U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15652053114252065230U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1705225940224061401U;
            aOrbiterJ = RotL64((aOrbiterJ * 3626023093533713579U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6826394665732900206U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11902946775066981141U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18300629262162694137U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9802212958998591310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14001358545610206524U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13172645840788327099U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + aPhaseDWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14710U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 14866U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14006U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14062U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 13016U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 6342299552323486695U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 12692748514781367538U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 8202639945493229155U) + aNonceWordD;
            aOrbiterK = ((aWandererF + RotL64(aCross, 19U)) + 4439975701793231639U) + aNonceWordP;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 13U)) + 16774235182859553759U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererK + RotL64(aScatter, 52U)) + 8764155413335405667U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 7167848811974967685U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16768278912125334220U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9090838954826296201U;
            aOrbiterG = RotL64((aOrbiterG * 5459329624017272077U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7644075729758006298U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17326182797908071215U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2408330168749256075U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16158809721888137555U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8029938783858263694U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12628072435324195483U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8716553521415553404U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 7012599977009208840U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 8775355876188948851U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13250558696578541499U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13705957059101025396U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 16889495686487056367U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2796775206291902461U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13741676263512390669U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10455782033465595947U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1691908360612389252U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4114939415206031540U;
            aOrbiterE = RotL64((aOrbiterE * 2797401802892718297U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aNonceWordH);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + aNonceWordE) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19108U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneA[((aIndex + 17317U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16963U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20474U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 20652U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 36U)) + 6069475454765660321U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 11483704742497268068U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 11055697447388986418U) + aNonceWordH;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 10897095046039997004U) + aNonceWordO;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 47U)) + 4731637118230457840U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 19U)) + 13855839187084986751U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 29U)) + 5328208115460188239U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12479538544291412985U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10740165998792608231U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14046827922294477379U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6492798157284955373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13056825957483891921U;
            aOrbiterI = RotL64((aOrbiterI * 14882112110627751751U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2068184064919194657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5656302738780746294U;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11193756120230763294U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17306750816837208999U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7949360041241439741U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12952818800389361804U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15380412293642628312U;
            aOrbiterE = RotL64((aOrbiterE * 2914662289178925547U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7706090204767242996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14598802276412649570U;
            aOrbiterH = RotL64((aOrbiterH * 4821408736292041399U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17819762117328075515U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 6481384240915075101U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 4836701121865783029U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 52U) + RotL64(aOrbiterE, 14U)) + aOrbiterK) + aNonceWordN) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterH, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24056U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 23631U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25735U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22019U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneA[((aIndex + 25408U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 10881271196314989997U) + aNonceWordI;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + 6406461249988567558U) + aNonceWordM;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 17255067918280095959U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 16690850682497718411U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 50U)) + 5576201059361086866U) + aNonceWordG;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 19U)) + 11991259685693687554U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 14652535244217836909U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1701789037170782122U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 953429054903473833U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13482379459700651427U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12064513610469714211U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7993881398822002424U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11572884842788918377U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14421313768013320050U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11112386845630998889U;
            aOrbiterA = RotL64((aOrbiterA * 11771526352030371669U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17069630896535699015U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 3308240081138623373U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 10449509484417835159U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17615529807112933619U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11782807146851563541U;
            aOrbiterD = RotL64((aOrbiterD * 12992075832343669221U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14401645829607611983U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6736397344219993532U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1667287547938175641U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6446974060524700550U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7840991992443308254U;
            aOrbiterG = RotL64((aOrbiterG * 6891023544882740107U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 12U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 60U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27774U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 27501U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29518U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32235U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31307U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 44U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 4752759164691497960U) + aNonceWordF;
            aOrbiterG = (aWandererG + RotL64(aIngress, 51U)) + 12088872623537639782U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 3734943577379734227U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 13U)) + 8854778183012444234U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 57U)) + 16948373492893967275U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + 7962415690046184385U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 40U)) + RotL64(aCarry, 37U)) + 1872682375669714454U) + aNonceWordK;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7776801806943853566U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16665439117257230732U;
            aOrbiterK = RotL64((aOrbiterK * 6866375628213114965U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11088186766134265676U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10850237991780969350U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7547414856143095121U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6464817712131305812U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 244557182884209844U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13261563971157415841U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2323811103717827362U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 11483723582415081925U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12338803568475493422U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2811342930111104982U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 5020981755203607757U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5554497011738996057U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12712169745460598698U;
            aOrbiterI = RotL64((aOrbiterI * 1985586486150377769U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17415058661427002973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9430421222715343818U;
            aOrbiterG = RotL64((aOrbiterG * 10321140659099470811U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + aNonceWordL) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 36U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Golf_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8AB88DABF8C0BD91ULL + 0x85FBCF7834CA40C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAD5BF1E8C1DEB667ULL + 0x874CDDA860C69E14ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA3516F723F4897E9ULL + 0xC7C6747516264B9FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD8EE8517ADD8BC41ULL + 0x8F3B68725FCF7DB9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC119BED194A32CABULL + 0xE6D94593ED176123ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDAD3E0333A8D0CD5ULL + 0xD7B1C45614C629FAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA861E9542CBBF185ULL + 0xD6273F7BBEBDF8D7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCF8AD9930635289FULL + 0x9E2AF27BEAD16D7DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x92A3643E3CEE6077ULL + 0x9DB71894BD884E11ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xECCCBE193615B73BULL + 0x856DFF73E18F3FA8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEDD77D5281059455ULL + 0xA80466D61064ABB2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xED309874B9218F2BULL + 0x80A17C4AB10AA591ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8D10D56F6E735ED9ULL + 0xE06F6470CC0E0B55ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC702849FF8E34F65ULL + 0xEE98CE39E7C6629DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAF62346F58919B19ULL + 0x88F6EB30A756171DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF33133C437BE3637ULL + 0xA217DDFF2821235BULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2559U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 2859U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4806U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1038U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3060U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3265U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 29U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (aWandererE + RotL64(aIngress, 12U)) + 14157904117287696136U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 41U)) + 7369512677371640676U;
            aOrbiterK = (aWandererI + RotL64(aCross, 19U)) + 8411250745902073798U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 5002041814539710275U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 43U)) + 9538041410816283124U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 27U)) + 5210700103927513061U) + aNonceWordM;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 53U)) + 7600709399101287982U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 57U)) + 2366369466696580499U;
            aOrbiterB = ((((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 5544575244203019109U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 8710073749110329779U) + aNonceWordJ;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 48U)) + 15998211310115361630U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15354357553877376422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10657523549259276169U;
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10405750198355464768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3465819693133515142U;
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16724189641701408630U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3484340153620198872U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17247547677520703125U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7420442404884871126U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11138445997256757636U;
            aOrbiterE = RotL64((aOrbiterE * 11167543379937571127U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1428191560884663125U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 16950093140800653985U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 4423012306984814805U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17288299075036481960U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13793597915359681028U;
            aOrbiterJ = RotL64((aOrbiterJ * 9639204979982125757U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5017972942710079726U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12409957957614320964U;
            aOrbiterH = RotL64((aOrbiterH * 10273295741911545745U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12487994181992095174U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1573393166996612118U;
            aOrbiterG = RotL64((aOrbiterG * 13364311829104520751U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13227642825780350128U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7961292096150889569U;
            aOrbiterD = RotL64((aOrbiterD * 16627209081334341289U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10312485102088913337U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3177620041478410950U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 15918551366833593853U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2599092792737616563U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14157904117287696136U;
            aOrbiterA = RotL64((aOrbiterA * 14883446269291639813U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 26U)) + aOrbiterF) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 10U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5652U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 7393U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6522U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 7523U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9123U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6704U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8623U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererF + RotL64(aCross, 5U)) + 9220392006207660113U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 11305018553489132882U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 53U)) + 5860373868073513684U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 60U)) + 12319586170883987589U;
            aOrbiterK = (aWandererE + RotL64(aCross, 21U)) + 14072333614354649021U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 9332158529453194608U) + aNonceWordH;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 41U)) + 3860569321145958686U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 3U)) + 8119005668901240093U) + aPhaseEOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 13918259792880333239U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 6938856216758228704U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 3960905839118710604U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6043879193734253929U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15691425268831319195U;
            aOrbiterB = RotL64((aOrbiterB * 7189195135654636271U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14912209933584715274U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16180183395910618923U;
            aOrbiterK = RotL64((aOrbiterK * 3942858974766467849U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4966642362507707776U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6962226782462822861U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3647802407741095419U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12409120845092026295U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2302946450253872465U;
            aOrbiterG = RotL64((aOrbiterG * 7099576330777297911U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16118304388937163838U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15968419034359049422U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11736207775827080165U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17098982091525008231U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10298979200690822062U;
            aOrbiterI = RotL64((aOrbiterI * 12620028874653521945U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 552826643694256437U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11786560990790695378U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 11190309640069208311U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13730399230389329793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17614226859252305432U;
            aOrbiterA = RotL64((aOrbiterA * 2640019643570222977U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1062738267846296283U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13959480457644980835U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1194145909157002977U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4635071137794189167U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13374502212707796180U;
            aOrbiterE = RotL64((aOrbiterE * 129680788767298945U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11479902881487238033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9220392006207660113U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 1437457810224888809U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 52U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 38U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 54U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 26U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 10950U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 15030U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15504U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12429U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 12729U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 701291026547470433U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 37U)) + 17283292650462111643U;
            aOrbiterK = (aWandererD + RotL64(aCross, 39U)) + 9969124091931303406U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 35U)) + 889176772718046988U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 5U)) + 6054541844643748084U;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 50U)) + RotL64(aCarry, 37U)) + 14703226235143028132U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 7977975878522921062U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 29U)) + 16894322614172266274U;
            aOrbiterI = (aWandererI + RotL64(aCross, 47U)) + 12160451749345900570U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 12U)) + 10870847008043897470U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 21U)) + 8159920947172520247U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2440099120969517932U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2428396147731468007U;
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 2213226274394673479U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7079731443427765333U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16918930776877030559U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 958896789550478970U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10788682955708075458U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 913321215613559729U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2003386579317564870U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8419686358774204999U;
            aOrbiterA = RotL64((aOrbiterA * 6547052526438697621U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6989167615157578904U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17636634003643824148U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 11038576417283732937U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13824962118933907859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9543912892587859646U;
            aOrbiterD = RotL64((aOrbiterD * 14736710162285997415U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15729878041027706114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9542137475454825463U;
            aOrbiterG = RotL64((aOrbiterG * 11420547128115090491U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5327302277575009955U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2707383132257428583U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6120763309390182129U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9008601903853562620U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11050463189491777908U;
            aOrbiterC = RotL64((aOrbiterC * 9178386878636430553U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14683684132116778056U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5390271065690907120U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17903005409098232619U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5183407290520277451U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 701291026547470433U;
            aOrbiterJ = RotL64((aOrbiterJ * 16329261100139524239U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterE, 34U)) + aNonceWordL);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 26U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterB, 60U)) + aPhaseEWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21126U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 21256U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16963U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16453U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((aIndex + 19130U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 39U)) + 17470880031634374199U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 23U)) + 757565846006937746U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 3U)) + 9419282475801345674U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererG + RotL64(aScatter, 58U)) + 2014248014107898196U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 41U)) + 15113928519446490441U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 47U)) + 7346126964886259935U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 5594123113093162359U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 5659237263369402005U) + aNonceWordM;
            aOrbiterK = ((aWandererE + RotL64(aCross, 27U)) + 11565709683423969703U) + aNonceWordL;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 16782863743534856287U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aScatter, 21U)) + 13499100900072115907U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11414447651044205242U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7545993795121430538U;
            aOrbiterG = RotL64((aOrbiterG * 10758488381206257261U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11778229237616454988U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2544793391976514665U;
            aOrbiterA = RotL64((aOrbiterA * 4021060413798523299U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9972156716619459164U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17651030383827445664U;
            aOrbiterI = RotL64((aOrbiterI * 6742914240706775487U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17439147296849134543U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10021926927948343656U;
            aOrbiterF = RotL64((aOrbiterF * 18139540407315440909U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9309867875882669289U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14951424455944346337U;
            aOrbiterK = RotL64((aOrbiterK * 10569523948169951309U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2166343974068770659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11386993629011562026U;
            aOrbiterC = RotL64((aOrbiterC * 3091639433512536097U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 5747849744680120960U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4019290369160113026U;
            aOrbiterJ = RotL64((aOrbiterJ * 5567515306039646735U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3820540009554769592U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8210747198363020939U;
            aOrbiterH = RotL64((aOrbiterH * 16215133106542452509U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3006494852696036003U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2736305345451919450U;
            aOrbiterB = RotL64((aOrbiterB * 11993452696344358247U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6148431711118275178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6986633012691940738U;
            aOrbiterD = RotL64((aOrbiterD * 15672039482523804893U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7837859154831245165U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17470880031634374199U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 2153299273348512243U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterJ, 20U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aNonceWordB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26833U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneB[((aIndex + 23484U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25943U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26147U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24102U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25751U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 34U)) + 6654158889644956636U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 37U)) + 9045779659363991870U) + aNonceWordN;
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 3888897662136993491U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 27U)) + 6882016842864459345U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 27U)) + 15601891715956172291U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 5176811598629335350U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 47U)) + 12519945150889074325U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 23U)) + 4552583214397603278U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 53U)) + 14225482701804864688U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 5485298070606280363U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 3U)) + 11237713257388094289U) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14340345895626142788U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16275167270553643347U;
            aOrbiterC = RotL64((aOrbiterC * 7308578867128951199U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14041860597556520250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1436068974197066343U;
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11483155566419547004U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4608508534724289325U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 13461385011638899485U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2389196334288832895U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4062682330273866602U;
            aOrbiterF = RotL64((aOrbiterF * 8787682133271101901U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5655656046585592034U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7977947821249746880U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 10082104644185964787U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11653718118543974168U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5456429682072377614U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12504180638665296649U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12457179652004203574U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 445821754230182952U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 16043092621697786393U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12429505513284703263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12480745784412363537U;
            aOrbiterE = RotL64((aOrbiterE * 643617210585287593U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6952219750393303609U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13965647644550998416U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5395755018020115073U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5602193483992512507U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9593414134773695959U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2186313187456153775U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16469843418561148995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6654158889644956636U;
            aOrbiterD = RotL64((aOrbiterD * 17490973872858383001U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aNonceWordO) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterF, 48U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 24U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30688U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 30239U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30640U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30140U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27664U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 22U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 41U)) + 3973833383430652211U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 5760227042747169187U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 58U)) + 4923009065139227286U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 21U)) + 1477807307009107590U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 43U)) + 5707194514329007301U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 5340439728375269724U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 26U)) + 17080457898946572387U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 281559150259472813U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 51U)) + 16160633048230910560U) + aNonceWordB;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 9003989610509592121U) + aNonceWordO;
            aOrbiterK = ((aWandererG + RotL64(aCross, 35U)) + 10579322462808454333U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15059383289528723069U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10417647757852880956U;
            aOrbiterF = RotL64((aOrbiterF * 1457919230286043137U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14484665027393813330U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12344463053485837974U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 5762654194001525041U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5826453246659297805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12547902286376986223U;
            aOrbiterD = RotL64((aOrbiterD * 2982850000322672789U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9637855144278126174U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2132744427444501938U;
            aOrbiterG = RotL64((aOrbiterG * 5911587798564836199U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9248933938130311231U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13274297928717090383U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2901398809555237563U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3690262236918560930U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3626005326410800344U;
            aOrbiterB = RotL64((aOrbiterB * 13030443356669355355U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10801089744186148218U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5446653082176311031U;
            aOrbiterH = RotL64((aOrbiterH * 4594267575901248321U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3205541585889107366U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4532327942368884436U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16287094987689326229U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9755333481079721632U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 722154154363571049U;
            aOrbiterA = RotL64((aOrbiterA * 11002432494248958957U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8071668483354405205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8770466248803121315U;
            aOrbiterC = RotL64((aOrbiterC * 12780438190628717807U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1999251593502332271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3973833383430652211U;
            aOrbiterK = RotL64((aOrbiterK * 5325244982474631559U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 22U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 58U));
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterC, 52U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 57U)) + aNonceWordF) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Golf_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAAC313F80DCC58BBULL + 0xC34C351169782737ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x87FF1FCC9AB4E44BULL + 0xB55EAFD9732BD64BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCBE3CDB692BB49FFULL + 0xA10DF6F2A6A196F5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE8664A69B5247C79ULL + 0xB7A2668A8D7CC8CAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFD949712FD47BD41ULL + 0xC641565EB00CF2D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF800192C27A41F3DULL + 0x9E3586694FF61836ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8E7BBB15AAE6BA1BULL + 0xBB67C80D8143E14EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFEE224AB1B896D0FULL + 0x8022972603C9942AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF23333D046FF0A4BULL + 0xE04051DF0C57D636ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAAD27E09DCCBCBE7ULL + 0xA113604619085189ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE828234CD0C1F2F5ULL + 0x9A4B1EB22230DDD8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAFDE93EF3082592BULL + 0xA24BAF6A50E95042ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC51AC77AFAD6E541ULL + 0xD8FED59EE5466FF2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA4FE367DA7A3EB61ULL + 0xAE90AFC0FE13CA4DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9DF1EF7ED06B939FULL + 0xC10AC342795E3DB5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x82A3317CB3059A2DULL + 0x873BDCF38EA1080AULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneD, aSnowLaneC, aSnowLaneB, aInvestLaneD, aSnowLaneD, aInvestLaneC, aExpandLaneA, aInvestLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aInvestLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 60U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 3168U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 2901U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4000U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2329U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 3141U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 18U)) + 5568146815535263910U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 29U)) + 7736084960873834666U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + 1336413621817562093U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 23U)) + 5218462026934984692U;
            aOrbiterH = ((((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 7048890985969555935U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererE + RotL64(aCross, 53U)) + 13415955213864702118U) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aIngress, 58U)) + 5657023257021528548U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 14338310943137497116U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 12305161641833950473U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14514226578370459131U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12692904083266024340U;
            aOrbiterC = RotL64((aOrbiterC * 14800805065279908839U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11012959130001327964U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 7106471380403489078U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 515626559384817223U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3718101961355280891U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6720867800318913440U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14497243926965866546U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 13595058589060114653U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5789056168233262435U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14438482587495779937U;
            aOrbiterJ = RotL64((aOrbiterJ * 10593535547917767263U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 313917798940179945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15241845511889502917U;
            aOrbiterG = RotL64((aOrbiterG * 16483477103771326107U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3591957424821693032U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1559050939014453558U;
            aOrbiterE = RotL64((aOrbiterE * 17933346117866604725U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15340590914441451383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5538037287390050110U;
            aOrbiterD = RotL64((aOrbiterD * 4082576643144951473U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4151270491894969214U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 263593701314144898U;
            aOrbiterB = RotL64((aOrbiterB * 10372046955804512457U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 24U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 28U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneB
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 7163U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 8734U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8937U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9387U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6917U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8763U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5754U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 23U)) + 1042610313571524121U) + aNonceWordC;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 53U)) + 3505725321008825582U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 12584654563843782991U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 40U)) + 6645399144515770935U) + aNonceWordJ;
            aOrbiterK = ((aWandererG + RotL64(aCross, 57U)) + 3608978423753715584U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 8089198857670370983U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 15207251813516399879U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 3U)) + 9579268660105824516U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 34U)) + RotL64(aCarry, 41U)) + 16055044469473802812U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 583811872609805949U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7027491967970873942U;
            aOrbiterC = RotL64((aOrbiterC * 12686754713465826139U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18256061823189677508U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12708429127816136937U;
            aOrbiterG = RotL64((aOrbiterG * 12593886633108075321U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12169216645156306078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12694325407567795065U;
            aOrbiterB = RotL64((aOrbiterB * 3711789483877261899U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16109994660203297503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4234704064165718913U;
            aOrbiterJ = RotL64((aOrbiterJ * 730085881474787681U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14119541943554602878U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8777769004811352951U;
            aOrbiterK = RotL64((aOrbiterK * 2556957257736134223U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15642663488392549609U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11594468530833278624U;
            aOrbiterI = RotL64((aOrbiterI * 6639306656361601143U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7365350535791499871U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5965170981970155956U;
            aOrbiterA = RotL64((aOrbiterA * 1898702752753066851U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9115232101451815522U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9433983580038990072U;
            aOrbiterD = RotL64((aOrbiterD * 1951249217843992179U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8810565477444156140U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12081286530401844859U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1991383259486140229U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 18U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 46U) + aOrbiterC) + RotL64(aOrbiterG, 10U)) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12749U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 13970U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 15828U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15099U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10982U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (((aWandererA + RotL64(aIngress, 43U)) + 3255291173184001106U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 15308468160116255528U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 39U)) + 18186972408589866656U) + aNonceWordJ;
            aOrbiterH = ((((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 4439324265978331914U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 47U)) + 13099263173016322486U) + aNonceWordL;
            aOrbiterF = (aWandererG + RotL64(aScatter, 51U)) + 7041561081767500660U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 35U)) + 6196422612687812971U;
            aOrbiterI = (aWandererC + RotL64(aCross, 11U)) + 7664260932541281413U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 28U)) + 17802347823020441056U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 4253107484061190446U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13799496534030645312U;
            aOrbiterE = RotL64((aOrbiterE * 9167675060053848207U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14252892847595951926U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterG = RotL64((aOrbiterG * 18314294235895182465U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11148755959699137661U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 17036900929333594592U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2403828181385259549U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17813580350434928194U;
            aOrbiterH = RotL64((aOrbiterH * 13666780980793857831U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5623611126885414523U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10602620906929686163U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18015916257203385982U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 10684090189688871993U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13592915735376305773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13995866908043417505U;
            aOrbiterI = RotL64((aOrbiterI * 3802175869395887331U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8200465989447697618U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9866671660800629464U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2138851839905326265U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11557528777230608777U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 131060617338185060U;
            aOrbiterK = RotL64((aOrbiterK * 11068705423012265209U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 56U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aNonceWordA) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterE, 40U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20878U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((aIndex + 20396U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 19226U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21294U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 17000U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 20U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 3612110001869385068U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 16340824141280225936U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 30U)) + 15222338965130765231U) + aNonceWordH;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 5U)) + 6649270508107155041U) + aNonceWordD;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 37U)) + 768217258655426384U) + aNonceWordJ;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 51U)) + 4481855259658861851U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 41U)) + 18318041934562434016U;
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 4212457153804401807U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 12U)) + 16143621095636987628U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2095664232866642086U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4339527736737366572U;
            aOrbiterJ = RotL64((aOrbiterJ * 17503569508822244125U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13679353177869884790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11582168502846418236U;
            aOrbiterA = RotL64((aOrbiterA * 135539430034462861U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10451330452898542191U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12951448817640617841U;
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15389161934419370747U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 4754886272708253014U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 16638243718191281597U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11746389873929280688U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 12042680172517298768U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2648103752465009244U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 451594673632597973U;
            aOrbiterD = RotL64((aOrbiterD * 8496763663271072425U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5696534794094099710U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14609435045257077395U;
            aOrbiterC = RotL64((aOrbiterC * 14658408563237468407U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11599395126850950133U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12699598504604446664U;
            aOrbiterK = RotL64((aOrbiterK * 14313494063098111823U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9398465148537154745U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 12139736860648011256U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 15257503229375247987U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + aNonceWordE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 10U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 14U));
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26473U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneD[((aIndex + 23124U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26667U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25492U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 26571U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 50U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 21U)) + 7651355040951791298U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 39U)) + 13988210277931659312U) + aNonceWordI;
            aOrbiterB = (aWandererH + RotL64(aCross, 10U)) + 9846849412579537783U;
            aOrbiterI = ((((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 12746719939495876158U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererD + RotL64(aCross, 53U)) + 11498066185182895284U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 11101058955193080232U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 15513734459555672046U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 19U)) + 15711108675349394643U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 4771231759949468556U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11449258010811305256U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17036938391509986723U;
            aOrbiterB = RotL64((aOrbiterB * 7411466953205347639U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6999245666776654250U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2106819066263369528U;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12716183358903477216U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16752724547046059889U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11475905692393034141U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17623077680983093163U) + aNonceWordA;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 6726003022297274986U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 14709385877103232653U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2842410225096524740U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9235178377537910514U;
            aOrbiterK = RotL64((aOrbiterK * 11813751114775673845U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2619888019860844610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6295481948199619613U;
            aOrbiterD = RotL64((aOrbiterD * 15429161806953951205U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9724921158061115570U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4070976180958458679U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6080566609081811453U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5864247978960125554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7771249710071026757U;
            aOrbiterI = RotL64((aOrbiterI * 4787660062590737657U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15006900854988166845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2755659268987119046U;
            aOrbiterE = RotL64((aOrbiterE * 8043939381186802359U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 20U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterC, 48U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29001U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 27762U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 32335U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29976U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 31993U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 24U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 898812731947995389U) + aNonceWordE;
            aOrbiterH = (aWandererC + RotL64(aScatter, 26U)) + 8677347622525527167U;
            aOrbiterC = ((((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 770321564027567654U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 39U)) + 11020474858081526395U) + aNonceWordL;
            aOrbiterK = (aWandererA + RotL64(aIngress, 11U)) + 17289793580414993470U;
            aOrbiterF = (aWandererH + RotL64(aCross, 34U)) + 10111912559295118444U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 43U)) + 8083622125544542011U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 7149858558922988240U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 47U)) + 5919683821379905699U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6860902846079238714U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15083517836867542075U;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14852868368708376381U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 9860233289028878323U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 772406119079116272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8478568022896691911U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4027604850785607101U;
            aOrbiterH = RotL64((aOrbiterH * 4826627523578901467U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17199331557841535430U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7515957656979776361U;
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17138249294921502391U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16236812863923234668U;
            aOrbiterI = RotL64((aOrbiterI * 2925542836624164807U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16941524155859123682U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11240343728857342866U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 7281012444214294659U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15163914964139858328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6673576554415729652U;
            aOrbiterD = RotL64((aOrbiterD * 1558880328574736975U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5399050402101642989U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11806006719060024615U;
            aOrbiterB = RotL64((aOrbiterB * 15782156615926092159U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 26U) + aOrbiterD) + RotL64(aOrbiterH, 28U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 6U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Golf_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE9130C11763A9153ULL + 0xB8A5C62726C0D5B5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDFBAF7EEA98D72E7ULL + 0x87F16992FBAA8195ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x81A62B3A00E8A68DULL + 0x8CDB402774B1E8C4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9FAABEF1059DB911ULL + 0x84841DFE93ACA29DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB0F612CB8FA5AD9BULL + 0xE692BE3751B5AD75ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x95D202BBBEDCCEA9ULL + 0xFC72873F74364470ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC7C56497BD403813ULL + 0xD0D33EE65B196F9FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD7AE08713D649F31ULL + 0xEC57508E1AF36740ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAF6EAB6DD145A217ULL + 0xD0571DB059F9FB9AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE7730F3AA6097331ULL + 0xAEA09FDC3DF5BFC9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC52BACC5F3AFC93BULL + 0xA77D74D51B499284ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD433405F7309E3DDULL + 0x9B8B6EDDE68C80F7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF6D669B75D6E3E1ULL + 0x99345235B69ADB7FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEFF23A73283EBCCBULL + 0x9DF2EBA11FC540BDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8C6EE32FDCFE23CBULL + 0xFB7B0867D4271BBAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFC500A5D5051642FULL + 0xB2EFAA4D7C399233ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneD, aInvestLaneB, aWorkLaneB, aFireLaneB, aExpandLaneA, aInvestLaneC, aExpandLaneB, aInvestLaneA, aExpandLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3663U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneB[((aIndex + 2145U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4143U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1248U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 333U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4628U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 29U)) + 6521330037475130256U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 19U)) + 12611880456055428940U) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aCross, 41U)) + 12061611078130934708U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 3U)) + 1558112410801116984U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 10509115227850160786U) + aPhaseHOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 53U)) + 4045915960688792066U) + aNonceWordN;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 1196541286513243082U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15564991032722373702U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4897765238703641798U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9693901276712946763U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12327429514907752733U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 6189189797708711636U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9017615866338877651U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6374267075282018852U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1888758503831341439U;
            aOrbiterJ = RotL64((aOrbiterJ * 74387714918264257U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14956857689299491800U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14879361107223331957U;
            aOrbiterK = RotL64((aOrbiterK * 9166712966729591953U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16086885494838105042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10854345917959911439U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7078313614360332089U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15083669236062255011U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 594879695916679116U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 9852515479152735283U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 58U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aNonceWordJ);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + aNonceWordB) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5773U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((aIndex + 6201U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10912U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((aIndex + 9838U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7253U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7619U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10445U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 2225397913940961213U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 8342544893601343643U) + aNonceWordG;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 53U)) + 162922186381417187U) + aNonceWordE;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 11660218373710972210U) + aNonceWordL;
            aOrbiterE = ((aWandererK + RotL64(aCross, 19U)) + 14909034764605802354U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 47U)) + 16776955237009701511U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 38U)) + 5834487809188925253U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1498492772767040320U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4161765458781579617U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15535994410289065281U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10511923076962447765U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8575954471692620021U;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6536325446331340573U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1790628986900286346U;
            aOrbiterC = RotL64((aOrbiterC * 5262997114200816715U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2623814807619278590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11676970995834706612U;
            aOrbiterA = RotL64((aOrbiterA * 10057461115132434901U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13836786354224256591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6293096163612129260U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 8977954126326217153U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4271144764978661248U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15938494256992560202U;
            aOrbiterF = RotL64((aOrbiterF * 10004841288382726739U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11038155227307702976U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12408749795071243930U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5527720475032868855U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 10U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + aNonceWordK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + aNonceWordI) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12256U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneA[((aIndex + 15681U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 14557U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11573U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneC[((aIndex + 15307U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 38U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 36U)) + RotL64(aCarry, 57U)) + 12311607308490066301U) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 53U)) + 13100864684740679846U) + aNonceWordJ;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 43U)) + 13697304189274329704U) + aNonceWordF;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 9047976902871216732U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 5U)) + 2147897579538537888U) + aPhaseHOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 19U)) + 2072444829390996142U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 2129307836981020908U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10663145333751112064U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15019844390503785459U;
            aOrbiterG = RotL64((aOrbiterG * 7442321463110790449U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5460865577557928142U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15806522559993224197U;
            aOrbiterJ = RotL64((aOrbiterJ * 8722932687972240099U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6361113778657833389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8306013884615042570U;
            aOrbiterH = RotL64((aOrbiterH * 8234258702656728667U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4038420580499706912U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11908091484457158973U;
            aOrbiterK = RotL64((aOrbiterK * 3964111175645156719U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11133912466611921250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2469227904206936928U;
            aOrbiterI = RotL64((aOrbiterI * 2704438771198001599U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13234017916788297295U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9061117693840451988U;
            aOrbiterA = RotL64((aOrbiterA * 3637440416741459419U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 12013423690843812324U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14371779015144617412U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3359568073302062667U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 38U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterG, 22U));
            aWandererH = aWandererH + (((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 27U)) + aNonceWordA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aNonceWordP) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19463U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 18497U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20575U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19406U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneD[((aIndex + 20621U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererA + RotL64(aCross, 29U)) + 6342299552323486695U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 12692748514781367538U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 8202639945493229155U;
            aOrbiterD = ((((aWandererJ + RotL64(aIngress, 10U)) + RotL64(aCarry, 27U)) + 4439975701793231639U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 41U)) + 16774235182859553759U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 23U)) + 8764155413335405667U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 7167848811974967685U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16768278912125334220U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9090838954826296201U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5459329624017272077U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 7644075729758006298U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17326182797908071215U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2408330168749256075U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16158809721888137555U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8029938783858263694U;
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8716553521415553404U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7012599977009208840U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8775355876188948851U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13250558696578541499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2796775206291902461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13741676263512390669U;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1691908360612389252U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4114939415206031540U;
            aOrbiterD = RotL64((aOrbiterD * 2797401802892718297U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aNonceWordO) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 4U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24564U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 26559U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22522U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24764U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 23737U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 12262991801139086177U) + aNonceWordJ;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 7963038771924890197U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 15540520327933568896U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 20U)) + 8745565892055020722U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 57U)) + 16619329199683755286U) + aNonceWordI;
            aOrbiterH = (aWandererH + RotL64(aCross, 29U)) + 10865705026433867260U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 11U)) + 2743368697984518059U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5556006271515473135U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5355833281353498588U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 4190140212757841511U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8313616108963479829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16657121016801866434U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 331533349428472477U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16532226425013000833U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5800465874932467232U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17882948163883121328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15029375310296563175U;
            aOrbiterH = RotL64((aOrbiterH * 17021415832288477713U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10170682648007918739U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11829089574189398773U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15755874363488568849U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1746524867389196322U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10217423427886742775U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9166162099575333519U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1338457710729082656U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1319981417675542556U;
            aOrbiterD = RotL64((aOrbiterD * 9518448254565489715U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 41U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 58U)) + aOrbiterJ) + aNonceWordE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 24U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29235U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 30366U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29792U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30828U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 31846U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 41U)) + 4622023259121087483U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 11U)) + 10253505250223501352U) + aNonceWordD;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 17133877904420462669U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 35U)) + 6162827793741796700U) + aNonceWordL;
            aOrbiterA = (aWandererI + RotL64(aIngress, 29U)) + 9610986424765907615U;
            aOrbiterK = ((((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 11210747154264753754U) + aPhaseHOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 16554205219580654546U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10352576357413766388U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3651845783283479752U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1011289824180799641U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18145542190463500476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5415609566767162857U;
            aOrbiterD = RotL64((aOrbiterD * 6474184559323816389U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2033734872464201570U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3507213117125813345U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5453058336688881113U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8716253393049851856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 695984869565941856U;
            aOrbiterA = RotL64((aOrbiterA * 8377921610764044735U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7661578828878284931U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 906654265099155956U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 8117625377607536949U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6050049984731254612U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17882717590338190821U;
            aOrbiterH = RotL64((aOrbiterH * 10807367411402733215U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4996521991532815957U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4246460672800604436U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12047466401960824903U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterF, 4U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseHWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 3U);
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

void TwistExpander_Golf_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 708U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 1004U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2067U)) & W_KEY1], 14U) ^ RotL64(mSource[((aIndex + 2269U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 17074147006464019918U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 43U)) + 10559516626129419928U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 39U)) + 13280363679503946221U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 18U)) + 17657115422132457413U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 13325837013304973008U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 3059707750486106037U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 29U)) + 4529045702503050852U;
            aOrbiterD = (aWandererF + RotL64(aCross, 58U)) + 10726578475550904292U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 51U)) + 14832537837996659885U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 220094417441809246U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15343130035105342194U;
            aOrbiterE = RotL64((aOrbiterE * 7984652435043810845U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16592263353426409884U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15649290906447931918U;
            aOrbiterK = RotL64((aOrbiterK * 8405875177836650731U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11437410545843708269U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5859769136073011444U;
            aOrbiterA = RotL64((aOrbiterA * 1065016088086441107U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15188064100307340341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4367466521843260049U;
            aOrbiterI = RotL64((aOrbiterI * 15916715854192820923U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8482617283860566845U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2585745804937342972U;
            aOrbiterJ = RotL64((aOrbiterJ * 8267269625632139809U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1687641344403425541U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13667916445979421400U;
            aOrbiterF = RotL64((aOrbiterF * 8191322670355590027U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7684258716388029228U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14764266202380443369U;
            aOrbiterD = RotL64((aOrbiterD * 1746254773647650741U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12685190466981675661U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9958374400222383893U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12696606920219838929U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1352584794098160330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16057453941015251708U;
            aOrbiterG = RotL64((aOrbiterG * 6051546505117202495U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 52U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 38U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4550U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4687U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4024U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3153U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 9107326720193244489U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 58U)) + 10868585484401664145U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 23U)) + 13637736741437846622U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 11U)) + 6130725216183918844U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 35U)) + 2063834478521338187U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 54U)) + 8564870627911949158U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 29U)) + 6524015751064086390U) + aPhaseAOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 9874937766875388236U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 14723718409522680894U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13767059954741528279U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6387608251033722169U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6601902195707980693U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5391425980008431000U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11524218415655093779U;
            aOrbiterJ = RotL64((aOrbiterJ * 12508457981779189389U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 155510463350385905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8662160162966241542U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5092555636369853727U;
            aOrbiterE = RotL64((aOrbiterE * 433807340167635499U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7163345798448796101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 695089002178413267U;
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5409173939213468972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12376011890751302027U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7809614158898158383U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13845113198736843629U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13031938699536449576U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3983178190194056516U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1341678482929213405U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5567935037909671790U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17137042627663349797U;
            aOrbiterF = RotL64((aOrbiterF * 13535586899620672373U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 60U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6312U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadB[((aIndex + 7052U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6555U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7439U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7596U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 57U)) + 3917730204724097072U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 1874642340716212824U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 6900165757434854160U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 12750946097023807161U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 43U)) + 6563216048479513594U;
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 14960240191349450795U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 11U)) + 16306180275951788289U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 21U)) + 6502066618271045547U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 6U)) + 6219852857850888738U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2272931312452845850U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3028929882263199463U;
            aOrbiterI = RotL64((aOrbiterI * 11005324285856805069U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6067393030073568112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10094809900437037258U;
            aOrbiterG = RotL64((aOrbiterG * 18095564940730322769U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5962414178157074575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15755563045799129417U;
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6321455513889880590U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1197435601998121700U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8423760160877540210U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8090246492554850768U;
            aOrbiterA = RotL64((aOrbiterA * 2949407491181921633U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11436635942985063755U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17086363141014359856U;
            aOrbiterC = RotL64((aOrbiterC * 10504127577318206801U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10734017887545474935U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 375515325165740779U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9980486695448151709U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5217148491945389821U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14696058217023530058U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11026674782236654799U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterF, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10410U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 9992U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 10183U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 10238U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8316U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 10922U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 1142447269198373880U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 58U)) + 10581460640040336191U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 14703062773878202900U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 11U)) + 15737525756286914746U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 37U)) + 16178774478273186999U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 54U)) + 2514897053906809160U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 47U)) + 13702496607592508464U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 18030885275418337965U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 19U)) + 5241783876161655984U) + aPhaseBOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2807052676283587925U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8022804576763271327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15597099852232205860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1538435607932096400U;
            aOrbiterH = RotL64((aOrbiterH * 7900752511710516981U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11147868774413615365U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9325213746830411568U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 561819005818948769U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13792300423550555634U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3134856508983945719U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4271845067763664863U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8654966018053784882U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8937113935476779267U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4135676350355234788U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11407912615743682678U;
            aOrbiterI = RotL64((aOrbiterI * 2773506587480714695U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10966950663872392059U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6686634993700944582U;
            aOrbiterA = RotL64((aOrbiterA * 2509459942163678241U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14154407529749257990U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18054640398549782388U;
            aOrbiterC = RotL64((aOrbiterC * 7830759861389060149U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14623473030642960240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1857945571104460086U;
            aOrbiterF = RotL64((aOrbiterF * 18039903315045620079U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 44U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12802U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 13231U)) & W_KEY1], 38U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13129U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 11875U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10930U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12228U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((aIndex + 12807U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 18U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 7893287783892523139U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 23U)) + 10257331997383491153U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 14562226733652231753U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 40U)) + RotL64(aCarry, 5U)) + 14320342577110737851U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 35U)) + 9816717579822880756U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 9558926960095881953U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 9230371862654338324U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 29U)) + 6414274291252913420U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 54U)) + 13868546184398350849U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16940736952569949038U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2866957764814864371U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3554702178644797003U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7916721976073979724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1602444214978842275U;
            aOrbiterC = RotL64((aOrbiterC * 11072503711308122385U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9529061385251008037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8402775110887376588U;
            aOrbiterF = RotL64((aOrbiterF * 13980225144628227381U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15003592180290390713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14195681406520825751U;
            aOrbiterA = RotL64((aOrbiterA * 11455000833788877217U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3263577002367714202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12019422062655581928U;
            aOrbiterB = RotL64((aOrbiterB * 5002313835338447799U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8508638054582582917U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6536618106353552880U;
            aOrbiterK = RotL64((aOrbiterK * 6233964121117511885U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9654542989321430868U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7019594782797863244U;
            aOrbiterI = RotL64((aOrbiterI * 1234877854354279981U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8256061220727519919U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9232754129467036130U;
            aOrbiterE = RotL64((aOrbiterE * 17556001874302369781U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5608829951337740378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12632120498473345701U;
            aOrbiterD = RotL64((aOrbiterD * 6994794653605831925U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 26U)) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 30U));
            aWandererK = aWandererK + (((RotL64(aScatter, 28U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14584U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15980U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15344U)) & W_KEY1], 44U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15916U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15289U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13740U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14684U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 1557680213571812384U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 18U)) + RotL64(aCarry, 57U)) + 7387349725778021121U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 23U)) + 15379264067601586976U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 3730195724576043708U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 43U)) + 9637070085323827066U;
            aOrbiterK = (aWandererI + RotL64(aCross, 3U)) + 1170865717363676184U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + 2750833653175252030U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 58U)) + 15118992811225568305U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 37U)) + 4974092922102988451U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10625719096296719514U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 855167122475471865U;
            aOrbiterC = RotL64((aOrbiterC * 7441090331293158773U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11322911068958340262U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4334591909425429835U;
            aOrbiterK = RotL64((aOrbiterK * 10059025861172038183U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14263701737208936392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 678723206735649084U;
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15652053114252065230U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1705225940224061401U;
            aOrbiterF = RotL64((aOrbiterF * 3626023093533713579U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6826394665732900206U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11902946775066981141U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18300629262162694137U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9802212958998591310U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14001358545610206524U;
            aOrbiterI = RotL64((aOrbiterI * 13172645840788327099U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4299184726135884309U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7288757011999872416U;
            aOrbiterA = RotL64((aOrbiterA * 16806027820468277393U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 233801262480580205U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14208660347238680268U;
            aOrbiterJ = RotL64((aOrbiterJ * 6299693448313154603U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9217797359740446104U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 18165073197136050838U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11677479094709512887U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 34U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 28U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + aPhaseBWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterK, 52U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18998U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17648U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 16611U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 16876U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17813U)) & W_KEY1], 57U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16819U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17577U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 48U)) + RotL64(aCarry, 37U)) + 14823268998003220191U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 15295237288788213847U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 53U)) + 16434853402001133899U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 7555911304407871631U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 44U)) + 14977248264994834620U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 9707764144919392380U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 1277304385464681529U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 3089786220465849395U) + aPhaseCOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 3700503853358695085U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3240054112993517371U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16897532076915366859U;
            aOrbiterA = RotL64((aOrbiterA * 4120874717534309035U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18167359289798364307U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterI = RotL64((aOrbiterI * 9334066154398059075U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15363069206212330251U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14858164441499725158U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14931933411393847915U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5357144808788707522U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2910681277417754860U;
            aOrbiterG = RotL64((aOrbiterG * 13170868582159347059U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9824408699018165151U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 368370224788793300U;
            aOrbiterC = RotL64((aOrbiterC * 14358982366258729959U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7095398304588825115U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11418879758164313554U;
            aOrbiterD = RotL64((aOrbiterD * 5983520332639771791U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2171599720681913272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17593730219647495033U;
            aOrbiterB = RotL64((aOrbiterB * 12926053208918563087U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17755947635188715523U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14565740605227022106U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15866418354612945335U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14538017880915584414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6174566474851449123U;
            aOrbiterE = RotL64((aOrbiterE * 179569008593475683U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 34U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21801U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 20427U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19932U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19540U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21549U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19383U)) & W_KEY1], 53U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21693U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 21621U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 77518479758428414U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 24U)) + 4832061802166300011U) + aPhaseCOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 37U)) + 11695291171006574112U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 7467412817843260094U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 17801484124471154757U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 5555455638503958639U;
            aOrbiterB = (aWandererD + RotL64(aCross, 29U)) + 5669470540733721606U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 13U)) + 3042388456327784163U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 42U)) + RotL64(aCarry, 19U)) + 2236734925228156691U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14459720401528685450U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4814967631216658856U;
            aOrbiterE = RotL64((aOrbiterE * 18288097536171386643U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16950679344449075945U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterK = RotL64((aOrbiterK * 9942659897425088183U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3522256359074996724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12524717897707074242U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13891759914865623828U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11910250571469028666U;
            aOrbiterF = RotL64((aOrbiterF * 12311343917878428995U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2240189915640314069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5365912986308810837U;
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9323732721344489753U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13087326560957916553U;
            aOrbiterB = RotL64((aOrbiterB * 14659491687401151733U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16398238057564892809U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11517870519285159224U;
            aOrbiterI = RotL64((aOrbiterI * 1501848878469712681U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7758285512254776734U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17475149091906684720U;
            aOrbiterC = RotL64((aOrbiterC * 6015816725428299273U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2051631493975035243U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11684740065349595315U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10918975496337269197U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 58U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 54U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22165U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 22506U)) & W_KEY1], 10U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23931U)) & W_KEY1], 37U) ^ RotL64(aFireLaneC[((aIndex + 23430U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23878U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23085U)) & S_BLOCK1], 50U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24112U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21968U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 13U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 60U)) + 8402620908307642697U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 29U)) + 11347672014525086047U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 19U)) + 2816462912503401876U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 23U)) + 6940159795470696093U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 51U)) + 9134692490095883851U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 3U)) + 4999455497008026526U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 43U)) + 5992451460350651332U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 3417087346651371924U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 3612773820086198270U) + aPhaseCOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 463398077083428570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11249391303705089012U;
            aOrbiterC = RotL64((aOrbiterC * 7106735772303292983U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17027535139825739501U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 568131384979596481U;
            aOrbiterJ = RotL64((aOrbiterJ * 5683451044852895957U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4793712537158004047U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10415170179135963622U;
            aOrbiterE = RotL64((aOrbiterE * 13729564030210361415U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2391473979460065630U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4240058362680064261U;
            aOrbiterD = RotL64((aOrbiterD * 12375884373396400889U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9963957011090031698U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3325305624067445525U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3128542681461806309U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2094945647665114693U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10703615640774042674U;
            aOrbiterA = RotL64((aOrbiterA * 12641986098450423751U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3768738815518590289U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15021301790376706827U;
            aOrbiterG = RotL64((aOrbiterG * 14445850924223550339U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10571246886181608316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5130325144599151793U;
            aOrbiterB = RotL64((aOrbiterB * 3185251943547657467U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8617523421720966373U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16574597770835250074U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1759209403428937799U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 4U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 26U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 56U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25309U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 25271U)) & W_KEY1], 20U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25526U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 26801U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27279U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25291U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26553U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((aIndex + 25134U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aCross, 43U)) + 15045917390223766480U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 53U)) + 10763054007033668758U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 39U)) + 13190170142593666607U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 27U)) + 9657025731441167065U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 13U)) + 11433367178975954211U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 21U)) + 17904920143996810366U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 3244383020512113283U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 5U)) + 6538815775171139091U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 10U)) + RotL64(aCarry, 37U)) + 7195368312757976343U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 18134430713910279374U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6571776588427107976U;
            aOrbiterC = RotL64((aOrbiterC * 11916502085252589161U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11830778129647517758U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9793702760907767365U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4096246227968677179U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2287235876793192036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8951959188326141794U;
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7583061790273240157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3571364625022806085U;
            aOrbiterH = RotL64((aOrbiterH * 6238360922735480669U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13869345563551689212U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 277480328952975002U;
            aOrbiterB = RotL64((aOrbiterB * 1057564597096163085U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4983735092494677578U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9490022869381030928U;
            aOrbiterE = RotL64((aOrbiterE * 12926352917961703123U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7928039573014765566U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6504190875809407084U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14648214826494826711U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2787985600176307413U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16308785053443116826U;
            aOrbiterG = RotL64((aOrbiterG * 17867565986311256691U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12788128335006767824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1187040019537798339U;
            aOrbiterA = RotL64((aOrbiterA * 10834905007658184183U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 48U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH + ((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 38U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererG, 48U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29975U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 28439U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28670U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27917U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29403U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27509U)) & S_BLOCK1], 52U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27314U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29449U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 6U)) + 1866656689936219099U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 47U)) + 2312314528139448289U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 57U)) + 3554037526469185237U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 35U)) + 405707755060974111U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 51U)) + 1862976326004007697U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 12992483065443288263U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 30U)) + 3793854946371595197U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 4244007978867369382U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 10280867500312580308U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 472563452959164242U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12041770406895816553U;
            aOrbiterC = RotL64((aOrbiterC * 17811798500132002631U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6118634015704900486U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13637107920449233307U;
            aOrbiterH = RotL64((aOrbiterH * 17712028184714868053U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16673735670669318830U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8602681273646630496U;
            aOrbiterA = RotL64((aOrbiterA * 6995213887710749241U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7683264695930369476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9146674871199188218U;
            aOrbiterB = RotL64((aOrbiterB * 7403427067419261981U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3012935612827493084U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1259789268731661945U;
            aOrbiterI = RotL64((aOrbiterI * 2372843620327050137U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5623690455471160780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 18355567776031865462U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9553862670107886679U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7705134893833304792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4435192506444773834U;
            aOrbiterE = RotL64((aOrbiterE * 5249651218395299501U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6204683785806409075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17886971535016484255U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6047216474762933535U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4430578901091376829U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 607557685798141547U;
            aOrbiterG = RotL64((aOrbiterG * 12342665567201483107U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterG, 4U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31949U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32258U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32394U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31264U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31727U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31318U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 39U)) + 7075016829833562104U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 20U)) + 8783765886115517036U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 2996723892384565829U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 13U)) + 9494134707342189476U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 5052642981395679904U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 43U)) + 8766787055127962238U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 37U)) + 4467211954388738079U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 53U)) + 8030255604633658608U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 47U)) + 16962408063455702251U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3768222186567699076U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14930990410207899871U;
            aOrbiterA = RotL64((aOrbiterA * 10930005786146268241U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14179761938395502502U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterK = RotL64((aOrbiterK * 16783034788172670121U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5535012408925981515U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12792553516710295939U;
            aOrbiterB = RotL64((aOrbiterB * 8577530993755159329U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8979253163346099252U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5559189896063990740U;
            aOrbiterI = RotL64((aOrbiterI * 8832485423727331621U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13937564337299044079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2393376759689394948U;
            aOrbiterD = RotL64((aOrbiterD * 2352815657830413941U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12647519563697356479U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10946871249960389549U;
            aOrbiterH = RotL64((aOrbiterH * 6272580371881237173U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13376798695582123147U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10958115913599631271U;
            aOrbiterC = RotL64((aOrbiterC * 18233981473003345217U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4283914227806672773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 910842005516235816U;
            aOrbiterJ = RotL64((aOrbiterJ * 6722229871617873429U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1509644316619370324U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 165987596716078174U;
            aOrbiterG = RotL64((aOrbiterG * 13600064054240185123U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 6U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 34U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4563U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 3881U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1126U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 427U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 18302975933754610273U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 27U)) + 16736972646771456082U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 17389406266488137442U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + 5252511566486165539U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 18U)) + 5730715427422747640U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 6412695646456045825U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 9539701605708994494U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18355107116412945722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11735742491750132942U;
            aOrbiterJ = RotL64((aOrbiterJ * 18129835093627763685U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12363819388562658842U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5861430292304371543U;
            aOrbiterA = RotL64((aOrbiterA * 12989055611235382695U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15027487084595017708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7012850020745791926U;
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11904871669287886120U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11199760114477343208U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3856004502263742700U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3705931243173921893U;
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12305785390539209389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18057980996551978823U;
            aOrbiterK = RotL64((aOrbiterK * 4850564181113470859U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3229431819292153014U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2994716629242460094U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1029427328395257917U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 42U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5468U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 7743U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 6673U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5739U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 10764U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 8367680518550579791U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 57U)) + 11491674725611181241U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 16673861720782164214U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 9786610124108350855U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 5745080601557577637U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 37U)) + 1959402215131684684U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 4U)) + 6121650036079196522U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12016309761037342392U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5986936646177049603U;
            aOrbiterA = RotL64((aOrbiterA * 3585650475703294895U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1000367700904043468U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 17425288243569101032U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2174614006719048535U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4856917474950325209U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16312111093223166419U;
            aOrbiterD = RotL64((aOrbiterD * 11046477664487805241U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 456110002032422270U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11393724374787795662U;
            aOrbiterF = RotL64((aOrbiterF * 1176984359123668389U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8378176867715697176U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8086186452345234815U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8450438271765985235U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8470349167474173245U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2528229938740192694U;
            aOrbiterI = RotL64((aOrbiterI * 8717790851266520943U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13247168811545753141U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8745293957516815264U;
            aOrbiterH = RotL64((aOrbiterH * 14270617180621072619U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterD, 50U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14755U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 14111U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13739U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12211U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15045U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14695U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aPrevious, 13U)) + 8604208734152026945U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 1374329953253889829U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 21U)) + 5779278910548228339U;
            aOrbiterI = (aWandererF + RotL64(aCross, 60U)) + 17670451230882805140U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 8193848740764866860U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + 15801168428145650104U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 2584718176087499066U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14950366247822737997U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9779293225265670135U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11625969538497982117U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8688968319288372383U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13665723186950342601U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 292035540396910837U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9395428688359973510U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2152719218018108418U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15271961483518392671U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1350324137411377992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8729317951386057921U;
            aOrbiterI = RotL64((aOrbiterI * 6008790836417785083U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6317310451893678411U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10175620379041384281U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14079679617394330781U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1203082119358827708U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 523869107818193101U;
            aOrbiterF = RotL64((aOrbiterF * 4629501113595689157U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4028324959540432983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterE = RotL64((aOrbiterE * 6037306615787729185U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 18U));
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20323U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 16447U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18250U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19032U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17927U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21048U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 53U)) + 11480359716598965890U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + 15431182525482873419U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 11360504974812776707U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 9292576416573382769U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 1549257414531028975U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 5347769463033129317U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 29U)) + 17019199177478377234U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16558106007323125094U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3976182233825939422U;
            aOrbiterE = RotL64((aOrbiterE * 4392162052317572289U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2889047161195954395U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2241831345026962605U;
            aOrbiterK = RotL64((aOrbiterK * 5757458560979927857U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12850802412140579294U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13541744735436450160U;
            aOrbiterD = RotL64((aOrbiterD * 906089290000537439U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2085863085516538212U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2969034221711544086U;
            aOrbiterG = RotL64((aOrbiterG * 7768528124408400403U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6482666944512391472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16969153556875844613U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9483462388353216219U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5161314086757363678U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5465304381272305847U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2344610773390354017U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17010258514288089191U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 50U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22833U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 25444U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26869U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22530U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24911U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 25567U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 20U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 16462052553719977502U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 51U)) + 12337064059566619581U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 60U)) + 15801005007094515447U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + 8228706742665081656U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 11006723027845190869U;
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 18173765337829177450U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 530215083653542558U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6608611827035564511U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2246051826221626809U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6333352641495253539U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5228575308895381421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10999213210689606857U;
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3773371037240485696U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8887985779436152504U;
            aOrbiterD = RotL64((aOrbiterD * 698713082830739677U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11150566414723818350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8336366151003049546U;
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13233968794237090787U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8172558473508478819U;
            aOrbiterE = RotL64((aOrbiterE * 17837070423649268435U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 133564480283347997U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15104810248883567064U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 706802420642303533U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9138629520201127075U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13993086066341664080U;
            aOrbiterC = RotL64((aOrbiterC * 4875046427147105077U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterD, 60U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31804U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 31972U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27768U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29114U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30125U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 28630U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 898812731947995389U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 5U)) + 8677347622525527167U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 770321564027567654U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 24U)) + 11020474858081526395U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 13U)) + 17289793580414993470U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 10111912559295118444U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 51U)) + 8083622125544542011U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7149858558922988240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5919683821379905699U;
            aOrbiterG = RotL64((aOrbiterG * 16705119888884231567U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6860902846079238714U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15083517836867542075U;
            aOrbiterB = RotL64((aOrbiterB * 4686657139237578325U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14852868368708376381U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9860233289028878323U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13418143547952204667U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 772406119079116272U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7971141501337627589U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8478568022896691911U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4027604850785607101U;
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17199331557841535430U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7515957656979776361U;
            aOrbiterI = RotL64((aOrbiterI * 5468950152869656599U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17138249294921502391U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16236812863923234668U;
            aOrbiterE = RotL64((aOrbiterE * 2925542836624164807U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterB, 44U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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

void TwistExpander_Golf_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneA, aInvestLaneD, aInvestLaneB, aSnowLaneB, aExpandLaneA, aWorkLaneA, aExpandLaneD, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3273U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 2680U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 4618U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5142U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3222U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2206U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 35U)) + 12583180859826261500U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 9067093488553721468U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 12173106198862881754U;
            aOrbiterK = (aWandererA + RotL64(aCross, 58U)) + 11333491014394592654U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 3511883526940919554U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 29U)) + 7416810692106273044U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 37U)) + 8341174972619784110U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 39U)) + 2220852854836962979U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 46U)) + 8090781422229383825U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 2338801236599102223U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 13U)) + 12484514711848308104U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13684861340589131816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12796636819991873058U;
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7634198650894837690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10240326122201201762U;
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4162814763739453934U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2766504649149048469U;
            aOrbiterH = RotL64((aOrbiterH * 16731843453895178671U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11051393030148769655U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17687055068651386665U;
            aOrbiterA = RotL64((aOrbiterA * 1042927176246229537U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3353615315436983420U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5971640796220306310U;
            aOrbiterK = RotL64((aOrbiterK * 15804313508835034807U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12299773092762384765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7435804907797063411U;
            aOrbiterE = RotL64((aOrbiterE * 9848139805288165965U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8735783937125735699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11903126115475835615U;
            aOrbiterC = RotL64((aOrbiterC * 16942088822124940265U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4427166023462475475U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6011733469446008137U;
            aOrbiterD = RotL64((aOrbiterD * 17298067225913923517U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18341473946127677319U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5423774915753911947U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14985099502923458523U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2384393657884193014U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2650593524388493958U;
            aOrbiterI = RotL64((aOrbiterI * 892985816665547945U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15991261431384033176U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12583180859826261500U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14394838775646875599U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 52U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 46U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 60U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9591U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 6650U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10719U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((aIndex + 7369U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9442U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9878U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8274U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 4752759164691497960U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 35U)) + 12088872623537639782U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 23U)) + 3734943577379734227U;
            aOrbiterB = (aWandererH + RotL64(aCross, 13U)) + 8854778183012444234U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 16948373492893967275U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 53U)) + 7962415690046184385U;
            aOrbiterH = (aWandererF + RotL64(aCross, 44U)) + 1872682375669714454U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 7776801806943853566U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 16665439117257230732U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 51U)) + 11088186766134265676U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + 10850237991780969350U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6464817712131305812U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13261563971157415841U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2323811103717827362U;
            aOrbiterG = RotL64((aOrbiterG * 11483723582415081925U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12338803568475493422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2811342930111104982U;
            aOrbiterH = RotL64((aOrbiterH * 5020981755203607757U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5554497011738996057U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12712169745460598698U;
            aOrbiterB = RotL64((aOrbiterB * 1985586486150377769U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17415058661427002973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9430421222715343818U;
            aOrbiterA = RotL64((aOrbiterA * 10321140659099470811U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3926618548181233180U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6172453297026957838U;
            aOrbiterF = RotL64((aOrbiterF * 1161551082037835233U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8633288765997226004U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17270881130844274342U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8888559940161770791U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12232950994807835262U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15352600312956742750U;
            aOrbiterK = RotL64((aOrbiterK * 6140396356904933003U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5614120002595447983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1920822446545182835U;
            aOrbiterC = RotL64((aOrbiterC * 17049182594382482085U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 625576652179261739U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2362773059031414585U;
            aOrbiterE = RotL64((aOrbiterE * 17049048587829564949U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16749690978107177915U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4752759164691497960U;
            aOrbiterJ = RotL64((aOrbiterJ * 8442185754037031199U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterA, 54U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH + ((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15769U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 12603U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11287U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14409U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11872U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 19U)) + 1457104756581596530U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 23U)) + 6127240317844622874U;
            aOrbiterH = (aWandererK + RotL64(aCross, 54U)) + 16492290056044189421U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 10963676850938416468U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 4872917367399752405U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 41U)) + 15218882377875616148U;
            aOrbiterC = (aWandererF + RotL64(aCross, 47U)) + 5934166612122118251U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 14215280930872003003U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 11428034799044600979U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 5453003654321728726U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 14U)) + 14273775120265649389U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 328723770018440271U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13032190719588211088U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2386881543033598494U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1649501123340887116U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16462401546754210583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1510579201823042227U;
            aOrbiterI = RotL64((aOrbiterI * 16287912400104043275U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6889066000014251983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11324594596597724357U;
            aOrbiterC = RotL64((aOrbiterC * 15344987814648586023U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12237796033168436537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17306069670330000343U;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14197284538008811658U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4754134852883071927U;
            aOrbiterE = RotL64((aOrbiterE * 3484427259538998699U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17201907781639753736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8318419319239859855U;
            aOrbiterF = RotL64((aOrbiterF * 10320390501983802091U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16012488623961565780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15583721012865354925U;
            aOrbiterJ = RotL64((aOrbiterJ * 10656414363201743961U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14680351201973315018U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14483973292275372321U;
            aOrbiterA = RotL64((aOrbiterA * 9279222721410811027U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16324317860030681248U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7038506963317910910U;
            aOrbiterD = RotL64((aOrbiterD * 2960451734542956767U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12767672960346001218U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1457104756581596530U;
            aOrbiterG = RotL64((aOrbiterG * 1560375242310194691U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterK, 38U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 20U) + aOrbiterF) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21660U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneA[((aIndex + 20632U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 17840U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17780U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17001U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 3255291173184001106U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 48U)) + 15308468160116255528U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 18186972408589866656U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 21U)) + 4439324265978331914U;
            aOrbiterD = (aWandererF + RotL64(aCross, 3U)) + 13099263173016322486U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 7041561081767500660U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 6196422612687812971U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 52U)) + 7664260932541281413U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 57U)) + 17802347823020441056U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 5U)) + 4253107484061190446U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 13799496534030645312U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14252892847595951926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11148755959699137661U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17036900929333594592U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16041243617369003291U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2403828181385259549U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17813580350434928194U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13666780980793857831U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5623611126885414523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7293224381174846969U;
            aOrbiterK = RotL64((aOrbiterK * 7032561584670788117U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10602620906929686163U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18015916257203385982U;
            aOrbiterB = RotL64((aOrbiterB * 10684090189688871993U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13592915735376305773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13995866908043417505U;
            aOrbiterG = RotL64((aOrbiterG * 3802175869395887331U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8200465989447697618U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9866671660800629464U;
            aOrbiterI = RotL64((aOrbiterI * 2138851839905326265U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11557528777230608777U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 131060617338185060U;
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13404720733342982167U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13128574378042136042U;
            aOrbiterA = RotL64((aOrbiterA * 5805270317312187011U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15879295432652112238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9433361543323748909U;
            aOrbiterE = RotL64((aOrbiterE * 3592390041363796221U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6262775775981534941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3255291173184001106U;
            aOrbiterH = RotL64((aOrbiterH * 2748492753337241005U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterF, 34U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 40U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22780U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 24169U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26251U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23171U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23674U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 27U)) + 6771552164800695068U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 12131763371571322040U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 3326182381395522013U;
            aOrbiterB = (aWandererI + RotL64(aCross, 43U)) + 12288775097697156383U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 36U)) + 5195948373449796741U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 14404044002250137144U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 41U)) + 11142382920035825426U;
            aOrbiterH = (aWandererC + RotL64(aCross, 53U)) + 2967149520256475485U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 1470907369577818097U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 9231668148004163910U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 60U)) + 13078929163913892386U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9485274692075657877U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12216951187543631673U;
            aOrbiterA = RotL64((aOrbiterA * 6571066246507310805U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6933334652581744234U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17260276102423580920U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 387767848169714392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8597538259308082638U;
            aOrbiterB = RotL64((aOrbiterB * 4888054690557707241U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7996708724489146033U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15357384191688149939U;
            aOrbiterJ = RotL64((aOrbiterJ * 9827691726832491373U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17739222908739454637U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1614322333281471170U;
            aOrbiterF = RotL64((aOrbiterF * 7063116837752240891U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4531604274893197209U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3453280714992341288U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8390029711127907805U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 116623650872661533U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6565636510115095988U;
            aOrbiterD = RotL64((aOrbiterD * 9691897067492501177U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10303258439817808058U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10917642773040237611U;
            aOrbiterI = RotL64((aOrbiterI * 10232856828372963363U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2087058228468680821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3691125545393861889U;
            aOrbiterE = RotL64((aOrbiterE * 1768745056298937903U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9240209357066002219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7645250700232422804U;
            aOrbiterK = RotL64((aOrbiterK * 6762116797395687607U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9859862257084218280U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6771552164800695068U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11063630807191661109U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 44U)) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 48U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31739U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 29480U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 32616U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27709U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 28011U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 24U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 11U)) + 1364174714924216027U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 13561796874229506613U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 21U)) + 11845572344206238305U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 46U)) + 15762708240326773763U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 1157119665207900473U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 6823546624372055260U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 35U)) + 14465564210523945121U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 57U)) + 10667464548080807531U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 38U)) + RotL64(aCarry, 53U)) + 13445737493224316575U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 23U)) + 3009837893785957665U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 19U)) + 2886920524111083752U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10886177449328249656U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15067759884678100433U;
            aOrbiterE = RotL64((aOrbiterE * 5724566815989860041U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18307930462682331536U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8791864377579255801U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9265158882471421767U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 805797468642992351U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5743305867058244964U;
            aOrbiterB = RotL64((aOrbiterB * 16263000753351131717U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17102025528234481273U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1841579177327486899U;
            aOrbiterG = RotL64((aOrbiterG * 3841603385577825265U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2189493507896508972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18209567010094914374U;
            aOrbiterJ = RotL64((aOrbiterJ * 3737080408976852351U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6697069234216868330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 927471474577415372U;
            aOrbiterD = RotL64((aOrbiterD * 10680760991009199309U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13155854301197725408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1014625081915435892U;
            aOrbiterC = RotL64((aOrbiterC * 11592754232949990435U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12697209921410914931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11555096613655648647U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4598821388864997089U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9335308231651271690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3160859883353473444U;
            aOrbiterA = RotL64((aOrbiterA * 4753600703924906409U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15681189182414315768U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3147692210581710663U;
            aOrbiterH = RotL64((aOrbiterH * 6271949093080510861U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5373388632562432117U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1364174714924216027U;
            aOrbiterF = RotL64((aOrbiterF * 4694926665965807945U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterB, 50U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 39U));
            aWandererE = aWandererE + ((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 6U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Golf_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5272U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 3325U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5214U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8031U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1782U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 6881U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 16519040829220310189U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 6888002778416941825U;
            aOrbiterG = (aWandererH + RotL64(aCross, 29U)) + 1310832187746534025U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 5890888009051281674U) + aPhaseGOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 5U)) + 5143864838362464857U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15591534069452660003U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1466867671765325096U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1277202105237572301U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13931443680107902488U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15400747367673245552U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7011651369456453127U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2836975369734495759U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2370720358274970117U;
            aOrbiterB = RotL64((aOrbiterB * 4615571902817575375U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3470677184188006133U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7175584278499266723U;
            aOrbiterI = RotL64((aOrbiterI * 10067096593682482345U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6095078817776863055U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2176637999243513070U;
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14879U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 15057U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13347U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13280U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11712U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11474U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 23U)) + 4752759164691497960U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 12088872623537639782U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 3734943577379734227U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 51U)) + 8854778183012444234U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 23U)) + 16948373492893967275U) + aPhaseGOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7962415690046184385U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1872682375669714454U;
            aOrbiterK = RotL64((aOrbiterK * 959061892772099785U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7776801806943853566U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16665439117257230732U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6866375628213114965U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11088186766134265676U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10850237991780969350U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7547414856143095121U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6464817712131305812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 244557182884209844U;
            aOrbiterI = RotL64((aOrbiterI * 2394270354887582889U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13261563971157415841U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2323811103717827362U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11483723582415081925U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 10U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20545U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 17105U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17785U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20022U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19501U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 23472U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 15910560457440369082U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 17953072986407436888U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 15446940721193538669U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 4U)) + 3020785262774422009U) + aPhaseGOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + 7001288645424994404U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13385250665458462689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4841895644623005949U;
            aOrbiterF = RotL64((aOrbiterF * 3898487345974386945U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13053476783239482065U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 641996979335975244U;
            aOrbiterJ = RotL64((aOrbiterJ * 3697673197256549833U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16211238020928688299U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12715448751323279480U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2116880429675303291U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17784406727699995290U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16626339815786580778U;
            aOrbiterD = RotL64((aOrbiterD * 13940754474750138041U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9035070625716345139U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6085848172494001945U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 14U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseGWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31075U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 29689U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 24640U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30516U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32043U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30088U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 60U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 9751314027302668907U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 12175450995523107056U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 17519694958730119552U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 18U)) + RotL64(aCarry, 39U)) + 9093525527925682263U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 39U)) + 3713831321786810138U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10108355209191835040U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12956307447311314768U;
            aOrbiterF = RotL64((aOrbiterF * 9198936928658626667U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1904298513945877359U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4658049993308574460U;
            aOrbiterD = RotL64((aOrbiterD * 10482422152074338611U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9826333658248851902U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12058666914724365134U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2516574707110528099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8230749255538495304U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterB = RotL64((aOrbiterB * 7097036838156464969U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 46U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 42U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Golf_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1017U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 7249U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 653U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7747U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6965U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3908U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 4179952823252098240U) + aPhaseHOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 3745613452332101749U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 2955689793395307176U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 54U)) + 5639060180251322019U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 21U)) + 7901969163853586463U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2242166787816318119U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5239936443960750064U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2752853245379816327U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13939136954732185558U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17058884136712717463U;
            aOrbiterH = RotL64((aOrbiterH * 7222348891215482977U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18148618660054585941U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7022023484530327814U;
            aOrbiterB = RotL64((aOrbiterB * 650100011311048589U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7722084537340095637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11764151879690934182U;
            aOrbiterD = RotL64((aOrbiterD * 12264384877711365655U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16412785901758144708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9666718667728274824U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 6U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10782U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 13894U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 8991U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12804U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10172U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 10453U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 9133751643283278896U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 24U)) + 8971581804375380408U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 35U)) + 12559650383714566592U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 15753206088872859163U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 7640756270450762350U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7340073357551376125U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5270256573644196046U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13286406906662922841U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3567367996479995928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11939634537492733738U;
            aOrbiterI = RotL64((aOrbiterI * 5640541900117183639U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7051817732424527120U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1730487669951837941U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15191634337956285841U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18009252467909454817U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2361024272031696442U;
            aOrbiterE = RotL64((aOrbiterE * 15215151562500226027U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15902755877642960397U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12243517544704116184U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2576071074148141447U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 48U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17901U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 18449U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17374U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19733U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18155U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18866U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 26U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 4U)) + RotL64(aCarry, 57U)) + 17711946802293254150U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 21U)) + 16652362590489569378U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 6972810344198183097U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 13117100889782940546U) + aPhaseHOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 41U)) + 13199305696782626591U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 992156184392760945U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13791265442074543880U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1263919538622722673U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17057087245252294859U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13444195995883541046U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13067044288608808777U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6723678233676059420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7913379431208430475U;
            aOrbiterC = RotL64((aOrbiterC * 2295062944289127123U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4481887195529300665U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11892724101424384078U;
            aOrbiterA = RotL64((aOrbiterA * 3468639499716604111U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7700902083270424194U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1888001433557140271U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8975562955027025349U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 44U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26700U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 26334U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28722U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25732U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25038U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31831U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + 5295352595333316211U) + aPhaseHOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 2341795367042042605U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 10122175780504033663U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 10084612804696198554U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 43U)) + 16470424309851045971U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 656016130975227994U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15313268829659834317U;
            aOrbiterA = RotL64((aOrbiterA * 3553315008401417123U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3795220914993923394U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14044442220988813825U;
            aOrbiterH = RotL64((aOrbiterH * 3270650852546606835U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3804224626734584802U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7980006306010255693U;
            aOrbiterD = RotL64((aOrbiterD * 13958505239726088561U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13746830564584711549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11852212099729274845U;
            aOrbiterJ = RotL64((aOrbiterJ * 2164880979318247855U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9083223471018084847U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13706723820703853346U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11361854103656219887U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterE, 37U));
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
