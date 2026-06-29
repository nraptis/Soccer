#include "TwistExpander_Soccer_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Soccer_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBA5548B5E9E8CB5BULL + 0x94FEE28308C43A03ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD027F14364C1E85BULL + 0xD41695FCA04C0335ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9605B062E2D0E3EFULL + 0x96977F1A490239DFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E69B3C4BD9BC3F5ULL + 0xE4633055D150AEBAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9DB78520A9A155DFULL + 0xCECA4A55BBE4523CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB6D88805E8C7F93FULL + 0x8CFF5CCCAA30D711ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8FEEE57300857B13ULL + 0xC9678F23149C3D70ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF163A47E9EC5EFDDULL + 0x84966452210CE9A5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9D61DCF14C8FF77FULL + 0x9DCCB31DA31EA1F2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8126474B628A9C67ULL + 0x94D8D00D880BAC51ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCF9F0BB29903AB37ULL + 0xDD72A583D7B1E0B2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x983A00403B5A10E9ULL + 0xEAC1DC2ED5786AD6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF42B2ACCDDC0409FULL + 0xD95A1C1E71B68325ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x955B5ACFB435E935ULL + 0x849E0A2D49DF1B14ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE957E906828D3563ULL + 0xFCDFDABAF9485F0FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x99F2FD980D951BF7ULL + 0xA53F36156BCF2933ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3325U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 2209U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3278U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 956U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 13583136155674166402U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 19U)) + 12830472187484919497U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 18081197909484522509U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 52U)) + 8680634051297891550U) + aNonceWordH;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 5U)) + 13939998767458656823U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aCross, 13U)) + 1795730579103692594U) + aNonceWordB;
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 17369751719734069999U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 35U)) + 224769585901248068U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 37U)) + 4133547085925268180U;
            aOrbiterH = ((((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 7022512056309567391U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererA + RotL64(aCross, 42U)) + RotL64(aCarry, 21U)) + 10319484359046945495U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10483878349412282069U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6481381149199985736U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13721077228796934509U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9704818014314175007U;
            aOrbiterB = RotL64((aOrbiterB * 760445624027740287U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6253040047758584339U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16890211690273641226U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6216227831265032436U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9201669637050388263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5106927540934338576U;
            aOrbiterG = RotL64((aOrbiterG * 6368134569042291431U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10080368957861445998U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10784789383436485808U;
            aOrbiterK = RotL64((aOrbiterK * 3794918350254445939U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15426339824951793026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17637144549368340331U;
            aOrbiterH = RotL64((aOrbiterH * 10971293914614704441U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9941300382181962134U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8118046374121322097U;
            aOrbiterC = RotL64((aOrbiterC * 8481945819050983127U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5138086185042567633U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7279942739248982986U;
            aOrbiterD = RotL64((aOrbiterD * 12911998308338410917U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12135610639038562853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12945353426409788798U;
            aOrbiterA = RotL64((aOrbiterA * 7434977715954413699U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7534876598022096222U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13583136155674166402U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 8194058098043157015U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 34U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 14U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 36U) + aOrbiterH) + RotL64(aOrbiterB, 34U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 53U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 10050U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 9610U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7337U)) & S_BLOCK1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8323U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 12583180859826261500U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 13U)) + 9067093488553721468U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 12173106198862881754U) + aNonceWordO;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 53U)) + 11333491014394592654U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 34U)) + 3511883526940919554U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 57U)) + 7416810692106273044U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 8341174972619784110U) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 2220852854836962979U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 27U)) + 8090781422229383825U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 30U)) + 2338801236599102223U;
            aOrbiterA = (aWandererG + RotL64(aCross, 51U)) + 12484514711848308104U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13684861340589131816U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12796636819991873058U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 5533508014234835669U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7634198650894837690U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10240326122201201762U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8758703497719125901U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4162814763739453934U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2766504649149048469U;
            aOrbiterJ = RotL64((aOrbiterJ * 16731843453895178671U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11051393030148769655U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17687055068651386665U;
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3353615315436983420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5971640796220306310U;
            aOrbiterB = RotL64((aOrbiterB * 15804313508835034807U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12299773092762384765U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7435804907797063411U;
            aOrbiterG = RotL64((aOrbiterG * 9848139805288165965U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8735783937125735699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11903126115475835615U;
            aOrbiterK = RotL64((aOrbiterK * 16942088822124940265U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4427166023462475475U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6011733469446008137U;
            aOrbiterE = RotL64((aOrbiterE * 17298067225913923517U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18341473946127677319U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5423774915753911947U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 14985099502923458523U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2384393657884193014U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2650593524388493958U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 892985816665547945U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15991261431384033176U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12583180859826261500U;
            aOrbiterA = RotL64((aOrbiterA * 14394838775646875599U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 24U)) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 12251U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 15502U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15469U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 16281U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 53U)) + 13174219512651137892U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 2715455762789269341U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 1338018183235594313U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 4U)) + 16566866551729552930U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 43U)) + 6901845297307236726U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 2476078302049201718U) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + 15531109473927052260U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 19U)) + 4087849380858572351U) + aNonceWordF;
            aOrbiterA = (aWandererE + RotL64(aIngress, 35U)) + 5167830630098599644U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 24U)) + 7275995452428627217U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 14794340370010024117U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8509217403041662849U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2321522025240806996U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5676672952755594051U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2304681269233504384U;
            aOrbiterI = RotL64((aOrbiterI * 15731441084605554497U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8383399721062437300U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13181984036942227666U;
            aOrbiterC = RotL64((aOrbiterC * 1648761328771932069U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13602604532551684210U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12725687663616352843U;
            aOrbiterA = RotL64((aOrbiterA * 4684699861686199753U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5831790822416009806U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4535048543735457407U;
            aOrbiterF = RotL64((aOrbiterF * 12076777878870257053U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10617608605149381858U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5244225377862618630U;
            aOrbiterG = RotL64((aOrbiterG * 15307177251167023999U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18229989093139888456U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9728120630096192811U;
            aOrbiterK = RotL64((aOrbiterK * 16052574428163231023U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1312233443099767304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8043115602160128619U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 9365756845731616963U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4679339316686216023U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 211799535650113758U;
            aOrbiterJ = RotL64((aOrbiterJ * 1478368466990144107U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13307123762743628190U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7093673238704478497U;
            aOrbiterE = RotL64((aOrbiterE * 13273906568866802561U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16396459072175632290U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13174219512651137892U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7581008806810219369U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 40U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20905U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((aIndex + 20838U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20209U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 16759U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21410U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 19U)) + 3650233661228036955U) + aNonceWordK;
            aOrbiterI = (aWandererC + RotL64(aIngress, 41U)) + 11607036400067735729U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 58U)) + 3899614406903883035U;
            aOrbiterD = ((((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 8159156925629965143U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aCross, 43U)) + 7148903913967261270U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 21U)) + 9161665622287517848U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 53U)) + 2981535013474059469U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 27U)) + 15812469008200319549U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 43U)) + 14687469489893270300U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 6025209349511417063U;
            aOrbiterA = (aWandererA + RotL64(aCross, 23U)) + 12964750392311112676U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6572355895765394340U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3542300121890027981U;
            aOrbiterJ = RotL64((aOrbiterJ * 11201491178181273935U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6477175684045398359U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1081388388827929314U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8752188637514143529U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13754328481584620771U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3684673342659575917U;
            aOrbiterC = RotL64((aOrbiterC * 6139923312873039143U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6542045150319909445U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5352102692424060388U;
            aOrbiterK = RotL64((aOrbiterK * 7385758355501860261U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9110100774657340354U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2813273684436269057U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10468759062594022273U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5860425751137403755U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1598622981888978548U;
            aOrbiterH = RotL64((aOrbiterH * 651816500461718345U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14710305692377606725U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16280545617802383463U;
            aOrbiterE = RotL64((aOrbiterE * 12541767206978802063U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6849565243667718750U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12152381961996750050U;
            aOrbiterA = RotL64((aOrbiterA * 11185935780063403807U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1318947876257794796U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5447559252769140391U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 13683733413554766327U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2766869582494246454U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15757729967222729304U;
            aOrbiterB = RotL64((aOrbiterB * 1858683399257513171U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13063432816787882618U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3650233661228036955U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 16230564672533821641U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24097U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 24963U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23251U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26081U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24676U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 26071U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 439898681482066326U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 14U)) + 17362083676671776094U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 21U)) + 6418499837265155024U;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 17262244253027454972U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 2382066162993139503U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 43U)) + 14345808395587174135U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + 7534743166385552851U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 18U)) + 16994453324688523966U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 27U)) + 7079553728544045092U) + aNonceWordH;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + 3562822704508440641U) + aNonceWordK;
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 13990892681975857821U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1796728922368577238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6605161260520067178U;
            aOrbiterH = RotL64((aOrbiterH * 8147537646591674091U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13994083795942328918U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 6144523182899107711U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 4153879991344611283U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12247462325297436642U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1065809332002012789U;
            aOrbiterA = RotL64((aOrbiterA * 5496601177032953251U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10147919864511540753U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17138553441127273354U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5773875596275267871U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2653924016109573974U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6254416952351699582U;
            aOrbiterJ = RotL64((aOrbiterJ * 12756861659704947257U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 813046408080197079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9624466135414123483U;
            aOrbiterF = RotL64((aOrbiterF * 6960320253124395015U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 972586705850825744U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 155283774901960223U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9928051687724257041U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18200100644751360406U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1168426822045686004U;
            aOrbiterE = RotL64((aOrbiterE * 5867027156069481313U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2271564377169233643U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1896317305868283986U;
            aOrbiterB = RotL64((aOrbiterB * 8080751157990019287U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 10209708407397294552U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 947585551223387294U;
            aOrbiterK = RotL64((aOrbiterK * 15339472308062247067U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12313594490465462211U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 439898681482066326U;
            aOrbiterC = RotL64((aOrbiterC * 12336632799055203705U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterK, 60U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 46U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32328U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 31916U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28282U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31589U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27721U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 31127U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 31301U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 47U)) + 3236820517816085022U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 11U)) + 741288875914097926U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 60U)) + 8417246926007729580U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 19U)) + 9715717805774537170U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 53U)) + 14360243844821619482U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 21U)) + 10760908100206775334U) + aNonceWordB;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 27U)) + 3434641779946167811U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 39U)) + 7885568822756234567U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 43U)) + 3041563437672051294U) + aNonceWordH;
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 15761355327564963516U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 1158633562785937421U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9338581575871970653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14653924713599790081U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3854497592598563309U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 11737111068815795303U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16286980180327600557U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5092583772591249756U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13955105624639442903U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4288397994175567333U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15584236478994873104U;
            aOrbiterE = RotL64((aOrbiterE * 1860480595862755379U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5557463939827483792U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2659814275753280856U;
            aOrbiterG = RotL64((aOrbiterG * 17702430405693184643U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6941807963525063449U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2040598555191211307U;
            aOrbiterA = RotL64((aOrbiterA * 14750544987531722765U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 347572666231116258U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 779304821185302523U;
            aOrbiterJ = RotL64((aOrbiterJ * 14180254150318109855U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10632524582873079742U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9761308771280517212U;
            aOrbiterI = RotL64((aOrbiterI * 13926235411726048921U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2097439707055737964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2813977930321463948U;
            aOrbiterB = RotL64((aOrbiterB * 14983538728730662603U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6080592019313796689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5396623654821376409U;
            aOrbiterF = RotL64((aOrbiterF * 15478858835919398677U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8460497459575045342U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3236820517816085022U;
            aOrbiterK = RotL64((aOrbiterK * 5530411244458067093U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 52U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 54U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 26U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Soccer_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC6FE67CAD09AACBBULL + 0xE2A17EBD583568C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDB8507252ADB9375ULL + 0xA26BEA0CA340C9FBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA28B48A382EC735DULL + 0x9DE2843F4F481987ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA445F70952E823F3ULL + 0xD70E9F915CA8838CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC0D3A0B654F5E639ULL + 0xCEF58BE0556BD997ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB4DDF62122BC8BFBULL + 0x90A4DE765CEF7551ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAE52C9FB102CDCF1ULL + 0x8F858604E9ED616FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEBECB809BC8CDDC5ULL + 0xD109259E3BF23B13ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB3D9F92FBC2E1EEFULL + 0xB5A97F26508B7C96ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBAD0F5D359CC06E7ULL + 0xC59791CA140F5FD4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF600CA7C97A6BD97ULL + 0xCC1216C70AEFECE0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x93CBED3D696008BFULL + 0xA29F6A5B66A21600ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEB34BC53D9291031ULL + 0xE600EAD68CA59C61ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE6B31DBB672D38B9ULL + 0xEBC4D19C56AF2570ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD3DD159F315B84A1ULL + 0xA2B98F7D4600310EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFB951FB0BFC09A99ULL + 0xE19CB00D85D9197CULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 45U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 689U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2229U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 5123U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 6654158889644956636U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 11U)) + 9045779659363991870U) + aNonceWordI;
            aOrbiterC = (aWandererH + RotL64(aIngress, 52U)) + 3888897662136993491U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 47U)) + 6882016842864459345U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 15601891715956172291U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 43U)) + 5176811598629335350U) + aNonceWordO;
            aOrbiterF = ((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 12519945150889074325U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 4552583214397603278U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 14225482701804864688U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5485298070606280363U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11237713257388094289U;
            aOrbiterC = RotL64((aOrbiterC * 11032429223099413011U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14340345895626142788U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7308578867128951199U), 39U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 14041860597556520250U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterE = RotL64((aOrbiterE * 3938460345031496843U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11483155566419547004U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4608508534724289325U;
            aOrbiterK = RotL64((aOrbiterK * 13461385011638899485U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2389196334288832895U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4062682330273866602U;
            aOrbiterF = RotL64((aOrbiterF * 8787682133271101901U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5655656046585592034U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7977947821249746880U;
            aOrbiterI = RotL64((aOrbiterI * 10082104644185964787U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11653718118543974168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5456429682072377614U;
            aOrbiterH = RotL64((aOrbiterH * 12504180638665296649U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12457179652004203574U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 445821754230182952U;
            aOrbiterJ = RotL64((aOrbiterJ * 16043092621697786393U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12429505513284703263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12480745784412363537U;
            aOrbiterB = RotL64((aOrbiterB * 643617210585287593U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 56U) + RotL64(aOrbiterK, 30U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 34U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 7189U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 10814U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 8651U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7215U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7407U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 51U)) + 2177539223979303669U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 29U)) + 3962004686551521471U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + 8457602312617147662U) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 3U)) + 18011802451816510632U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aScatter, 10U)) + 9046101759168876832U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 11135620637431969597U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 35U)) + 15913029940697999701U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 16304193109948135982U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 20U)) + RotL64(aCarry, 27U)) + 13208892298820080981U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4182377898949419225U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13970137023071326151U;
            aOrbiterI = RotL64((aOrbiterI * 9075061559681739865U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8402396284835248583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9760005337757990392U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14108277760135744897U;
            aOrbiterK = RotL64((aOrbiterK * 4474681104256093885U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12226316121949012350U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 3456392186754113960U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 8704729827929941215U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5004087958637038973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7176881295123125567U;
            aOrbiterD = RotL64((aOrbiterD * 15272157962928021009U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10889800478505074438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13728832441482547824U;
            aOrbiterA = RotL64((aOrbiterA * 17588477761978646139U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17345665880706866772U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 301139993853297566U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5812445396758354505U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2061389844760610160U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterG = RotL64((aOrbiterG * 143613352104722701U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10767186080827509622U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4893486019456886013U;
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 60U));
            aWandererG = aWandererG + (((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 36U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 24U)) + aOrbiterK) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 16256U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 12199U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11188U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12501U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneC[((aIndex + 12425U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 18U)) + 7948891781097675369U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 53U)) + 13928362874228230226U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 10776180542602258926U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 57U)) + 5735115172149470447U) + aNonceWordN;
            aOrbiterE = (aWandererA + RotL64(aIngress, 3U)) + 5353591822981766987U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 36U)) + 562301708107268570U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 10467810247578364868U) + aNonceWordE;
            aOrbiterH = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 14541630141152308564U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 13U)) + 2350076897065139429U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17519109078651162228U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10021905773432907835U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15654836633731000065U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13723521735153718904U;
            aOrbiterE = RotL64((aOrbiterE * 14459516479283070563U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7671010488872356142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11485114338165600777U;
            aOrbiterH = RotL64((aOrbiterH * 4162584865462407791U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8759060657343458985U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11009137869375286581U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15792999392743144135U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6180808423175992479U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 13681230339693676907U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 361487389591183005U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15292753806514404853U;
            aOrbiterJ = RotL64((aOrbiterJ * 17478232597253311153U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14929153438443362045U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7904556383593914086U;
            aOrbiterD = RotL64((aOrbiterD * 2484130486635511403U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3793180909904286848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10391957637467171320U;
            aOrbiterG = RotL64((aOrbiterG * 505484041943467117U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 12U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19984U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 18919U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17464U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20790U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17423U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 13U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 19U)) + 898812731947995389U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 35U)) + 8677347622525527167U) + aNonceWordD;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 19U)) + 770321564027567654U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 11020474858081526395U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 17289793580414993470U) + aNonceWordL;
            aOrbiterG = (aWandererB + RotL64(aIngress, 12U)) + 10111912559295118444U;
            aOrbiterD = (aWandererH + RotL64(aCross, 5U)) + 8083622125544542011U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 29U)) + 7149858558922988240U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 39U)) + 5919683821379905699U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6860902846079238714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15083517836867542075U;
            aOrbiterE = RotL64((aOrbiterE * 4686657139237578325U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14852868368708376381U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9860233289028878323U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 772406119079116272U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7971141501337627589U;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8478568022896691911U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17199331557841535430U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5468950152869656599U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17138249294921502391U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16236812863923234668U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 2925542836624164807U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16941524155859123682U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11240343728857342866U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7281012444214294659U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15163914964139858328U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6673576554415729652U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1558880328574736975U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5399050402101642989U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11806006719060024615U;
            aOrbiterK = RotL64((aOrbiterK * 15782156615926092159U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 46U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterF, 58U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aNonceWordP);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 23781U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneD[((aIndex + 22140U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25871U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 24382U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 4U)) + 4384716820085860551U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 9715780315942116888U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 57U)) + 15963520052789178632U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 14346700690686392938U) + aNonceWordA;
            aOrbiterA = (aWandererD + RotL64(aCross, 44U)) + 6005518012489966643U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 29U)) + 2506732930310252119U) + aNonceWordJ;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 16782163084851775826U) + aNonceWordC;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 13U)) + 823673076571076303U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 39U)) + 1634084509064077736U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1288134975466877686U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2998220403162908444U;
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 220430672180734911U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10223923547068528867U;
            aOrbiterA = RotL64((aOrbiterA * 12577370238343872139U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11696469696177647608U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6545430420379636963U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 8387163146257553773U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 79691451831797107U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8971444023498649419U;
            aOrbiterH = RotL64((aOrbiterH * 7148919880477390009U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5624403902454498793U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9468064161002030997U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4619361544913629805U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12682446273369750704U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 10879074713156075641U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8728730962617599223U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9099675924074253030U;
            aOrbiterC = RotL64((aOrbiterC * 5525644236954497523U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3298303921318288541U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5953276499411658358U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10565471305001292693U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6725769507592688539U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1057277456510215817U;
            aOrbiterI = RotL64((aOrbiterI * 8269412198279297075U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 20U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 24U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 26U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterH, 34U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 32241U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30976U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29741U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 29493U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 18180797995100240808U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 58U)) + 6585906608223552885U) + aNonceWordK;
            aOrbiterD = (aWandererF + RotL64(aScatter, 47U)) + 14088708930575939855U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 43U)) + 468974153311516044U) + aNonceWordG;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 12481951025619894110U) + aNonceWordD;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 53U)) + 17227987923860711763U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 39U)) + 4373962756657477139U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 2077576476565420951U) + aNonceWordL;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 30U)) + RotL64(aCarry, 23U)) + 17435011300234663764U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4118039398293246896U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13724716599855216683U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17556333902751079677U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12391461204689596339U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9900605191533799627U;
            aOrbiterI = RotL64((aOrbiterI * 13553565332531046301U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 972946858824366125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15442851427306771601U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7303586227288294037U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15406402525021428799U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12650358753454105119U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1483710933373510492U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6531763256577221891U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18065810162229740788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2355285311890287611U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1287783821903407734U;
            aOrbiterB = RotL64((aOrbiterB * 8054011680932255985U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9282654686791135654U) + aNonceWordE;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 15488608017745542551U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 7858866274035085123U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13296835576073421802U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7127700236018338741U;
            aOrbiterK = RotL64((aOrbiterK * 11246173563106014149U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 56U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + ((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 40U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 21U);
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

void TwistExpander_Soccer_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA7A0A1A26D7C0DE3ULL + 0xAEBF0742B4B096BEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFA589CAEFC2E9E63ULL + 0xEB5A5EE3952EFBC9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD6F4CC856B656BD1ULL + 0xF74BF4AC98CCE0FDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE45A294D64812F01ULL + 0xFC9CC88D2EE970DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEF9CCA5553F65E33ULL + 0xD71ED6C6C8C99313ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD2472A15BCBF6F4FULL + 0xCDC43E13D65C2099ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC81CA2AB02AF6DFDULL + 0xB69444BFDCE156A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC12024BDFAD8DC9FULL + 0xD6057A49EF0469F8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8CCB1E3FB50A10E5ULL + 0x9A54044CFD73F509ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x878B8B6AA3F1F7DBULL + 0xE34F9AA077892140ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9FCC4C2013333255ULL + 0x801778AE16EB6888ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD844152EBF292F93ULL + 0xFB03C486B01ADFB4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC350992D90B84FE9ULL + 0xDDCD6BAA85C6D698ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x81DD2509DFCDC285ULL + 0xA6D15961E942C301ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8C0ACD849DE77109ULL + 0xED1E2EE7964C186CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE64049A0BDED77D5ULL + 0xE631B80D261209F3ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5804U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 7596U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6812U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8151U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3006U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2013U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 26U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 28U)) + RotL64(aCarry, 5U)) + 9654059367478508868U) + aNonceWordA;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 6473006635864677427U) + aNonceWordD;
            aOrbiterG = ((aWandererI + RotL64(aCross, 5U)) + 6944184481315853243U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 4061496421939102306U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 57U)) + 15791809275719085463U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 14050798802646323055U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12072905924741758266U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 4757104346636738119U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17639076509231343896U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12195388285571234715U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4317060502521195769U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4325404419499496529U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5910567888204238382U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 11503787177122206937U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13092940059929942699U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15622862439323440527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14027151901132249793U;
            aOrbiterH = RotL64((aOrbiterH * 2273573821630510087U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterH, 48U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 39U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aNonceWordH);
            aWandererD = aWandererD + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9650U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 9843U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12843U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10144U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8921U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15747U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15350U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 13U)) + 1364174714924216027U) + aNonceWordF;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 13561796874229506613U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 29U)) + 11845572344206238305U) + aNonceWordC;
            aOrbiterA = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 15762708240326773763U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 29U)) + 1157119665207900473U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6823546624372055260U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14465564210523945121U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 10957323253786161255U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10667464548080807531U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13445737493224316575U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12137295000900795711U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3009837893785957665U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2886920524111083752U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15308180928967762543U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 10886177449328249656U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15067759884678100433U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18307930462682331536U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8791864377579255801U;
            aOrbiterJ = RotL64((aOrbiterJ * 9265158882471421767U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 14U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aNonceWordI);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 21U)) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 52U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22091U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 21686U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21059U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24216U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18060U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18920U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 16709U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 10U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 17225673071833726819U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 53U)) + 10301458382103627331U) + aNonceWordE;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 26U)) + RotL64(aCarry, 5U)) + 3960233050857362414U;
            aOrbiterA = ((((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 17768665685046605837U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 14471018461213959767U) + aNonceWordP;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10730597892721340453U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14863394003122760542U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17731557030589257169U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9948587274816688296U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3573569431435100993U;
            aOrbiterA = RotL64((aOrbiterA * 2303922230056523077U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8153670675740450590U) + aNonceWordF;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 16438856577722561424U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 4689247488336908827U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15765587867581925041U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1082039522061775213U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4202521649260798876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15877659681260461141U;
            aOrbiterD = RotL64((aOrbiterD * 11369910758551088173U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 28U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 22U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 11U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31910U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 31643U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31837U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 31304U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26895U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28969U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29377U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 10404808878585437255U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 13U)) + 10587858736301591439U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 37U)) + 1430530909801644435U) + aNonceWordG;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 9090938022430118902U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 23U)) + 12936604311751121235U) + aNonceWordK;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 1000583006020232032U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12352532088997042232U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 494418029883239087U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16723410947058502564U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16614089235313154270U;
            aOrbiterI = RotL64((aOrbiterI * 11530998303573027827U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4245553025593349277U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3353146318549477494U;
            aOrbiterJ = RotL64((aOrbiterJ * 14246377408238318091U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5935727336135635196U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10312187090293319667U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1395964500396711899U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12192843181244744484U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2542570124502586365U;
            aOrbiterE = RotL64((aOrbiterE * 17222847847573534963U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aCross, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 44U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Soccer_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE18D52E81F7E8A37ULL + 0xFC4D9A6FF88CE195ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD3F3129C1DB0A14DULL + 0xAB119A53AEF61517ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCFDF7D448C92159DULL + 0xCFE12EAA5A279048ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF69451A298BA4E97ULL + 0x945A6A09D6A0EF74ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC37BB46C07DB5FF7ULL + 0xD0A11CF16E40CBFAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD46C31F3E4C37091ULL + 0xEDC7C0D913C3495DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCBF161CCA22ED41DULL + 0xF49B8CDBC23401DDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA7D640A2C6AF5E9DULL + 0xFAC81DB93996DDF3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9AA70D7F2428D679ULL + 0xF03BCF8DFAC4BEAFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8D57AB3F6664ED3BULL + 0xB4C05C35C572B829ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDCCCA6FDCE03F907ULL + 0xFBEBFC759057712DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFE9078262C508F21ULL + 0xCA18802628ACE32CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFE1691E0214C21C7ULL + 0xE1DE432B141B47F6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x822DD6350B784E4BULL + 0xDF181931F0717C35ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAF27B0185152069FULL + 0xA1EA80F34A228A68ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD732DA8D779F982BULL + 0x89C292E30EC7D885ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7513U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 3500U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 690U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3251U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1720U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6242U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 58U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 13499155707765393469U) + aNonceWordC;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 5U)) + 3740324981823726185U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 5470765363949735652U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 3446436171274452326U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 1778929412631211933U) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 14666308799855220954U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 48U)) + 4548410236791175055U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5829739767694190372U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14319231414903675748U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4966501102515775601U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1513851750246111405U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1685620217748986019U;
            aOrbiterJ = RotL64((aOrbiterJ * 9286548037413609445U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16284162182006054402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6271539598462003309U;
            aOrbiterD = RotL64((aOrbiterD * 13923286694131331137U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12669312437565969473U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6315983824634946566U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17106616474222892782U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 167205520766791073U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13350266700180455548U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4608846311203767162U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2504857468837437365U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14195866746143604365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7917977448256795054U;
            aOrbiterK = RotL64((aOrbiterK * 5927771378657284557U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 20U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13000U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 10505U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14725U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11868U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14849U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9394U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9096U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 28U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 29U)) + 12380376990224645149U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 35U)) + 18296928500297384014U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 5U)) + 3550626816361145100U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 2667792936946706027U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 57U)) + 12020969779370926953U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 3U)) + 737340727886903447U) + aNonceWordJ;
            aOrbiterA = ((((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 1681797651799760502U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2956186342689489064U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1876852870402977177U;
            aOrbiterF = RotL64((aOrbiterF * 8875540081346621757U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 6433205819353555071U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9065076854974222998U;
            aOrbiterE = RotL64((aOrbiterE * 5459675878087242021U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3254410578766789992U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2005081975473815576U;
            aOrbiterK = RotL64((aOrbiterK * 9947701153722014085U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15992999234834560419U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3458344156815120948U;
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17069783053664877727U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1260234710193913099U;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3825186451876061335U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2905344294992827535U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 2469896090698580795U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18141402347899180617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8760129857609925066U;
            aOrbiterH = RotL64((aOrbiterH * 2507999156108123047U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 26U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19490U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 16856U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22225U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23019U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21109U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21777U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22274U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 13714409587461539863U) + aNonceWordH;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 14101156723903265839U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 51U)) + 7063754562895369001U) + aNonceWordM;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 19U)) + 12320578575245519386U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 27U)) + 11744826789631008424U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 35U)) + 8744816505096675597U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 43U)) + 10405435520084528645U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1463157688070683543U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12379603577919617703U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14858901470015109311U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1343439118031348146U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16118850268070235540U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11184386483735388257U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14116264435819277136U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14806408656041403829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11569345414052398227U;
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17063874769147888574U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9927420478679581917U;
            aOrbiterG = RotL64((aOrbiterG * 9042782809534196563U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2550285599827162167U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17801534123304996448U;
            aOrbiterK = RotL64((aOrbiterK * 2160836889363614721U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6456685241021762041U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17064208177372969289U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13726627607233302493U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 10U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27522U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 30503U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31760U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 25609U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32461U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25432U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31308U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 29U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 41U)) + 16016931609704150191U) + aNonceWordA;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 14511433515861302636U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 11691237442613269593U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 29U)) + 16383220587320484649U) + aNonceWordG;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 5U)) + 14293015313458219868U) + aNonceWordN;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 4407695248205526670U;
            aOrbiterA = (aWandererA + RotL64(aCross, 57U)) + 1158323195324398372U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6577683409653864555U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 171080079472863843U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 3063978974927752653U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5766333425872228205U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16173508656917582960U;
            aOrbiterI = RotL64((aOrbiterI * 12187968015372936695U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 11781450063402219202U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13033139686637576694U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4331137994135472025U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4006310759400926020U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13156817947481574467U;
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12791290558893516411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 989729955679243234U;
            aOrbiterE = RotL64((aOrbiterE * 8757228712495095017U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 838379839663022790U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2830743864262313606U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10173947177104802797U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2146646527331684652U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4629168181742174906U;
            aOrbiterG = RotL64((aOrbiterG * 9046124907945045131U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + aNonceWordK);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Soccer_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x84AF6E931B67E0EFULL + 0x9512BB7CE0BAB687ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFF3C9FDD860757D3ULL + 0xF1A8F2F4A284424FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA81FF1E5A52041C9ULL + 0xBEFB6D919CAFECE9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB608EA6C059C885FULL + 0xC6551B167C6B9B4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x96BED94C0D198237ULL + 0xD12CE525497AD37CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8289025373F57339ULL + 0xB2D234F123242B25ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA1F2C09B77C4ED2DULL + 0xCF2CB9A80375F8EAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAD2CD62A74C0176FULL + 0xAD4989054E78EB80ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x94E94C72A56A6925ULL + 0xC147EE306BA1C549ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC39E95C7803EFEAFULL + 0xBA5163F81644917CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD8192A76F1306323ULL + 0x91EDDC5B37093EB8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9475F4968A8E5191ULL + 0xB8A629BAE2CBB1C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA8EAFBDF0CEAA787ULL + 0xF9429494B84C792EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDAA88117F207ABEFULL + 0xB3468B75161D7A1EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEAAEE13316D59349ULL + 0xC67E609194F64BDBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBFF71A07330595CBULL + 0xDCC14043CCAEEF3FULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3560U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 4780U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4635U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2553U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 2422U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 24U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 11177787645248006236U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 51U)) + 3808340254579817169U) + aNonceWordB;
            aOrbiterD = (aWandererC + RotL64(aIngress, 57U)) + 828030667598518279U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 16177835921238398371U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 41U)) + 5518747735458708741U) + aNonceWordD;
            aOrbiterG = (((aWandererD + RotL64(aCross, 6U)) + 17346319082399995165U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 6397156921893030937U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15559381654710713582U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 940404446491415088U;
            aOrbiterD = RotL64((aOrbiterD * 16401260971303026881U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8047166032048732645U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4688468645859470491U;
            aOrbiterC = RotL64((aOrbiterC * 14383536431614496369U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3710878044770337260U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 116343189456629220U;
            aOrbiterI = RotL64((aOrbiterI * 5637725064169289339U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 883908030159391659U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18058691521694880482U;
            aOrbiterG = RotL64((aOrbiterG * 3132200449123497619U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17521015077103586117U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12658899101297839881U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12229480388278883300U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16206524049491531816U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 11122340196620859805U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5743265849441077466U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8903956475200417109U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterD, 22U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9088U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((aIndex + 8368U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 6619U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10665U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7351U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10134U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 13U)) + 6163290588946759209U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 3U)) + 7342672468560105447U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 51U)) + 11574563167017282321U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 2254820206194758964U) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 35U)) + 1469783447473099498U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 14174828900676165088U) + aNonceWordA;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 16277954291890598132U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14845750668693136766U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 150099699692047766U;
            aOrbiterB = RotL64((aOrbiterB * 7644895634421086357U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1200784917165131703U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9469982764806754302U;
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 10956702761701710182U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7915506894975487807U;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17335794183733623213U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 557028996286989506U;
            aOrbiterD = RotL64((aOrbiterD * 3993359298602424281U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1597385667771002414U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4376417959915162639U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4626236858205178149U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 549770198518993876U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 756554555648070919U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7298557532533152193U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3336802611342112013U;
            aOrbiterH = RotL64((aOrbiterH * 14679103452120080499U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 4U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14158U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 13254U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 13511U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14522U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 13365U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 47U)) + 9041099828460168106U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + 12883711604096848454U) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 11U)) + 17420968786226443079U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 56U)) + RotL64(aCarry, 35U)) + 3448213891716125104U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 11866455977445336560U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 19U)) + 4119356835384495905U) + aNonceWordL;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 2186212599698637068U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 6506144898969301620U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12556800923644051626U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15961043406612913121U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4075551535185182945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17877694808492008749U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 901315308379887473U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5553428900598223316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14362304852277160675U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9174200302876075831U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16110739511917638547U;
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10189881974519849402U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2128076632642616677U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 8860453653433114929U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18133523799074400083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9916472958834153766U;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10274457562795569227U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14134814273275356425U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 15912501063665343159U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 28U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19717U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 20616U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 18831U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17789U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 17671U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 42U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 4384716820085860551U) + aNonceWordE;
            aOrbiterA = (aWandererA + RotL64(aIngress, 13U)) + 9715780315942116888U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 3U)) + 15963520052789178632U) + aNonceWordJ;
            aOrbiterD = ((aWandererD + RotL64(aCross, 57U)) + 14346700690686392938U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 6005518012489966643U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 39U)) + 2506732930310252119U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 3U)) + 16782163084851775826U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 823673076571076303U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1634084509064077736U;
            aOrbiterB = RotL64((aOrbiterB * 1128407326773234517U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 1288134975466877686U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4321412662318298283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 220430672180734911U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10223923547068528867U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11696469696177647608U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterG = RotL64((aOrbiterG * 8387163146257553773U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 79691451831797107U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8971444023498649419U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 7148919880477390009U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5624403902454498793U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9468064161002030997U;
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4619361544913629805U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12682446273369750704U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aScatter, 38U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 52U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 25663U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 23165U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24010U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 22893U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 20U)) + 13499155707765393469U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 3U)) + 3740324981823726185U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 27U)) + 5470765363949735652U) + aNonceWordF;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 13U)) + 3446436171274452326U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 1778929412631211933U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 14666308799855220954U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 4548410236791175055U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5829739767694190372U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14319231414903675748U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4966501102515775601U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1513851750246111405U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1685620217748986019U;
            aOrbiterK = RotL64((aOrbiterK * 9286548037413609445U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16284162182006054402U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13923286694131331137U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12669312437565969473U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11894755313393001665U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 12556759675372354075U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 6315983824634946566U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17106616474222892782U;
            aOrbiterF = RotL64((aOrbiterF * 167205520766791073U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13350266700180455548U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4608846311203767162U;
            aOrbiterA = RotL64((aOrbiterA * 2504857468837437365U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14195866746143604365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7917977448256795054U;
            aOrbiterE = RotL64((aOrbiterE * 5927771378657284557U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 12U)) + aOrbiterK) + aNonceWordJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 29157U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 28313U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32387U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 29121U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 51U)) + 11998579547770778580U) + aNonceWordA;
            aOrbiterD = (aWandererE + RotL64(aScatter, 13U)) + 8409465187298704610U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 3470222286110333500U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 5704486785203069994U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 29U)) + 10334944660253279633U) + aNonceWordC;
            aOrbiterI = ((aWandererA + RotL64(aCross, 37U)) + 7626852700722567477U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 21U)) + 14631310754943209743U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 807160297237854120U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5624154783624196107U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 2404066593958052159U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4971444394698940423U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6340057638461027062U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12027586111086798629U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9003019862787819481U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13632057463595873033U;
            aOrbiterE = RotL64((aOrbiterE * 12575202147280216765U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12766104026871797746U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4062118445824915939U;
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5258212525426469978U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9956946981015983939U;
            aOrbiterH = RotL64((aOrbiterH * 8106382657040497669U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10837606223056473999U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13292864885504191134U;
            aOrbiterI = RotL64((aOrbiterI * 4445739587553669471U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 166087925900318658U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6786842221885441388U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 4411147600413147773U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
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

void TwistExpander_Soccer_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFF6A4C6CD46B6AABULL + 0x94BAC2DC35E695FAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA24DAF2FCA4E8FB3ULL + 0xC93EED34636E0DDEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD2A2A2BFC3CAC1C5ULL + 0xCD5829A1256479CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBEDABAF2DD0FE297ULL + 0xAD7269F9D34A6EDFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEAB8B5BCC6AA72BBULL + 0xD89DC0E44550CE17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBF7C917A34A1A8D1ULL + 0xDFE1866CBC89492DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEB0178520CD47FD9ULL + 0xEB1D10CBDC36F657ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD13AB588D33EFF8DULL + 0x9194CE1D657452A0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x92DE13D86C56449BULL + 0xBEDB5CF47ECD3B1DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x93423ACC756A41E9ULL + 0xF4CF613339EDEAE0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBB2050C8970A31EDULL + 0x8BE996CBB5F49F54ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9CA61819831D7AE7ULL + 0xE103A3C57E23D778ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x967EFDD483369961ULL + 0xC8CA23ADB873F290ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8B73396369C129D5ULL + 0x852C224A1EC2DC42ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9F068923DE71C415ULL + 0x8039195BB980A6CDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB09C01129216A325ULL + 0x96E2002DA5BF009EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3846U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 1201U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2700U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4257U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6843U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6679U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aIngress, 23U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 2783898056762489197U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 30U)) + RotL64(aCarry, 3U)) + 7177192902873343053U) + aNonceWordH;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 12254703232691980774U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 51U)) + 15446547245691219559U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 5U)) + 888475203006174856U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 37U)) + 3649183529366307877U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + 4642631047518805167U) + aNonceWordO;
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 6108329730724782250U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 8334054653023816636U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 5891895375031474350U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 44U)) + 3176720746238477862U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6111038696865301675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11914998302228682704U;
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17005063057791320948U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18333780598768130670U;
            aOrbiterC = RotL64((aOrbiterC * 5416759844884107303U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2056115016443263153U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10245512728872962677U;
            aOrbiterH = RotL64((aOrbiterH * 707106795383284903U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4810366069422162351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3051442983125942469U;
            aOrbiterD = RotL64((aOrbiterD * 13558537578054436423U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9285068547223654308U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13067251130180968842U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7000687697769766605U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3203670242792002165U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1770881716916463461U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13870229847371882171U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16286823712870537410U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13067191141829694202U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 15629974528467350445U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3414576315085336932U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8979691827341555245U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15971594804040295757U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11370607523115189596U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1346943598249651668U;
            aOrbiterF = RotL64((aOrbiterF * 4994794423314630209U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2441719135451272926U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3347272129827184676U;
            aOrbiterA = RotL64((aOrbiterA * 10434510775894776597U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 1116857329130532047U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2783898056762489197U;
            aOrbiterI = RotL64((aOrbiterI * 9504855173533274401U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 26U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 20U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 26U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 26U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 46U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10163U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 14597U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9750U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 9268U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15575U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8600U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13126U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 60U)) + 14214886793361825363U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 17267959031078766320U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 27U)) + 16436067429484887644U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 9885951769332633820U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 43U)) + 12971711341813893304U) + aNonceWordI;
            aOrbiterB = (aWandererC + RotL64(aScatter, 47U)) + 199970353398450154U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 41U)) + 1237341696444162094U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 39U)) + 7991128854417613360U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + 14809029847149045833U) + aNonceWordG;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 2559509556915775947U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 14336829730147834160U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8853631886733610440U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13346159398673246914U;
            aOrbiterK = RotL64((aOrbiterK * 13660497151446983393U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12121095718571872976U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16239781125815589804U;
            aOrbiterG = RotL64((aOrbiterG * 5157009090454962231U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 9051377033794324106U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13805815136723461780U;
            aOrbiterD = RotL64((aOrbiterD * 571129481747181357U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14849157800322754413U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18116651528452542634U;
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4105057226952948599U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5911714320560994391U;
            aOrbiterF = RotL64((aOrbiterF * 1796514171654961389U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4439149331729987587U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10278532228230163632U;
            aOrbiterA = RotL64((aOrbiterA * 17428224919864716517U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2342456582668741750U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2360578572554664800U;
            aOrbiterE = RotL64((aOrbiterE * 1108428466956691925U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12132934875391401246U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17213278726790245812U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 11904899990681410419U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7994340481560109811U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13735851271080138255U;
            aOrbiterC = RotL64((aOrbiterC * 12387076892129731557U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6682417543888875268U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15642799286975840550U;
            aOrbiterI = RotL64((aOrbiterI * 7861250716882028053U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9839299346094784067U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14214886793361825363U;
            aOrbiterB = RotL64((aOrbiterB * 2103132743364916037U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 40U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aCross, 50U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 46U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18692U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 21969U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22313U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17941U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16665U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20337U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18385U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 18U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 11U)) + 5173905450211892891U) + aNonceWordK;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 3555542451908039957U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 11559884700283861559U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 35U)) + 1352524329968738673U) + aNonceWordH;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 29U)) + 8914206450420616349U) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aCross, 27U)) + 2251523378498463946U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 22U)) + 9541575923299247038U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 1239854507907214595U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 5U)) + 17698101462598498934U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 51U)) + 12305566971683256060U) + aNonceWordD;
            aOrbiterC = (aWandererC + RotL64(aCross, 41U)) + 13804545036303215569U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10239749097704329264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4212214906286320308U;
            aOrbiterF = RotL64((aOrbiterF * 3661436621615751071U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12192418916967430783U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4475514289326450361U;
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17376102613298827459U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 18129393209955439341U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6404089025014118979U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4014763724300253568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17325007199676828814U;
            aOrbiterE = RotL64((aOrbiterE * 1420888274815627083U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15480474849292388685U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14357924730184375449U;
            aOrbiterI = RotL64((aOrbiterI * 16723492259068034209U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4335731868597970070U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8296023680394303015U;
            aOrbiterD = RotL64((aOrbiterD * 14027415401430120543U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2807312426993262800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15510369660839648501U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 18207954408298333959U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12597844696606519907U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7231012798553551535U;
            aOrbiterC = RotL64((aOrbiterC * 2841306785994479299U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 849663631945232360U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4002310581470781194U;
            aOrbiterB = RotL64((aOrbiterB * 2148877014350721479U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16067735571435654555U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4607980694199923842U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 10401780756830017477U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5346879191913449715U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5173905450211892891U;
            aOrbiterG = RotL64((aOrbiterG * 15360571827429301833U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 22U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 48U)) + aOrbiterB) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 38U) + aOrbiterF) + RotL64(aOrbiterE, 54U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27919U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 28591U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31493U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30274U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31583U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28332U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26446U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 19U)) + 4259993311776766595U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 2857813330021126753U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 1345396841329442896U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 21U)) + 320992148982301024U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 57U)) + 5619109532065293074U) + aNonceWordA;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 10380157329426706345U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 48U)) + 12449831150625409695U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 7847096607042268396U) + aNonceWordH;
            aOrbiterC = (aWandererD + RotL64(aIngress, 37U)) + 11707184096803214678U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + 9893643746186827088U) + aNonceWordI;
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + 333687403830908774U) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13837360705077441580U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4367119682175710689U;
            aOrbiterF = RotL64((aOrbiterF * 10295744669174603401U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1193493435041306784U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15062951612027370606U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16000173839235429105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15294482444605409961U;
            aOrbiterJ = RotL64((aOrbiterJ * 1031800997944302665U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5720749055549773527U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17248674962996093668U;
            aOrbiterE = RotL64((aOrbiterE * 15730637462755795591U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16956840483882091059U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9637715107943515594U;
            aOrbiterA = RotL64((aOrbiterA * 8878362378343603463U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7147495779349862274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7508890985889484275U;
            aOrbiterI = RotL64((aOrbiterI * 17728368447504622035U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4407738164617959366U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17027017782352660454U;
            aOrbiterH = RotL64((aOrbiterH * 417183060881259295U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3174658601748235285U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9779053567370714831U;
            aOrbiterC = RotL64((aOrbiterC * 6383245776181968033U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16256981360027888091U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12778335633397105924U;
            aOrbiterK = RotL64((aOrbiterK * 10821225965811763659U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13985909343937844583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14307218309393008729U;
            aOrbiterB = RotL64((aOrbiterB * 12053366452617039877U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 15549857305890093491U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4259993311776766595U;
            aOrbiterG = RotL64((aOrbiterG * 13703695714360435719U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 18U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterB, 30U));
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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

void TwistExpander_Soccer_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDF78D747AC93F95FULL + 0xB9F94D5E2C5F3BFAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBD088F315005E753ULL + 0x829F93D2CEB25432ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEE0E6A448330E8B7ULL + 0xFB56AE23D6C0FB64ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA3411264651A66C3ULL + 0xD96285D4BC293E8EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9EA9008814184863ULL + 0xC55A595EAE74002AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE3D2D761B5F7E889ULL + 0x890F83607227D0F6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB928BB1DBA751987ULL + 0xD69BBE59808C4FFFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD1E9F84C6709BE77ULL + 0xC4B1639ACB63E76AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD45E62F6D04981F1ULL + 0x9B59F70C595B299DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC59D2DED0DFF11C3ULL + 0x87BE623A167C0FB4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA93DCD508A96535ULL + 0xC81F9A5FF927E80EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFAE63CEEF2847A37ULL + 0xFBE66D500511ABCDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBDF437A8CC13EDF9ULL + 0xA5CD4EDE9702BB5BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC393F0E7266A1C6BULL + 0xD6F03085AEDE6F9DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD80B9205C2BAB5DBULL + 0xBA7A35BD4D2AB32DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8BDB2410695C39E1ULL + 0xD9FB5F923E149E35ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4712U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 4004U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4452U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4234U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3848U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3611U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 4384716820085860551U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 9715780315942116888U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 6U)) + 15963520052789178632U;
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 14346700690686392938U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 51U)) + 6005518012489966643U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 39U)) + 2506732930310252119U;
            aOrbiterH = ((((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 16782163084851775826U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 27U)) + 823673076571076303U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 13U)) + 1634084509064077736U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1288134975466877686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2998220403162908444U;
            aOrbiterC = RotL64((aOrbiterC * 4321412662318298283U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 220430672180734911U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10223923547068528867U;
            aOrbiterG = RotL64((aOrbiterG * 12577370238343872139U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11696469696177647608U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterH = RotL64((aOrbiterH * 8387163146257553773U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 79691451831797107U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8971444023498649419U;
            aOrbiterI = RotL64((aOrbiterI * 7148919880477390009U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5624403902454498793U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9468064161002030997U;
            aOrbiterB = RotL64((aOrbiterB * 8243560528100864595U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4619361544913629805U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12682446273369750704U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10879074713156075641U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8728730962617599223U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 9099675924074253030U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 5525644236954497523U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3298303921318288541U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5953276499411658358U;
            aOrbiterJ = RotL64((aOrbiterJ * 10565471305001292693U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6725769507592688539U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1057277456510215817U;
            aOrbiterA = RotL64((aOrbiterA * 8269412198279297075U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 42U) + aOrbiterC) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 14U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 36U) + aOrbiterH) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11399U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 8868U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11315U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 10247U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10201U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16262U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12028U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 8506388683755208267U) + aNonceWordG;
            aOrbiterE = (aWandererE + RotL64(aIngress, 29U)) + 2179323259055019735U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 41U)) + 3345902531140983016U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 35U)) + 17456139311481306584U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 53U)) + 14587864088462311164U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 13178947246650647057U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 5U)) + 12866578138946916962U) + aNonceWordK;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 13098524333655118173U;
            aOrbiterI = (aWandererG + RotL64(aCross, 24U)) + 15451329483787541982U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9494299579678389385U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15581954810375490643U;
            aOrbiterC = RotL64((aOrbiterC * 13670002280188424825U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4487042505730624892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2774455928791636186U;
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12435319582397755819U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10077180055177766823U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 3924363471701748703U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10391963896910956455U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6149237416725301794U;
            aOrbiterB = RotL64((aOrbiterB * 10115917698918612823U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15673402771629639978U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14729117178956592426U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9070464269215820531U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14492001279368870240U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6278248084483259952U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16731228350971263873U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15727518866499740411U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8652631010810965473U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9508484121620912715U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13660890300188313775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14699253534935936300U;
            aOrbiterJ = RotL64((aOrbiterJ * 3978135617259934869U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1621689916308271346U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5651399428852950385U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12220143634120124133U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 24U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20914U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 18083U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19094U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22332U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21469U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19211U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22605U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 15904465836916519864U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 39U)) + 17725629806317789307U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 11U)) + 13794170125914914828U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 2149055907476874332U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 5342047776745074649U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 18U)) + 8268148484060546838U) + aNonceWordO;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 10821151364028563719U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 4294213820894407378U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 51U)) + 10884726101307943090U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16432210042202444824U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15196602644336228055U;
            aOrbiterH = RotL64((aOrbiterH * 12680438355124070237U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14117787670220328165U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 219833877949480215U;
            aOrbiterJ = RotL64((aOrbiterJ * 10736293047771972173U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3326396981881473962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14918513066311426279U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11795234681370163206U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3068267285352664813U;
            aOrbiterG = RotL64((aOrbiterG * 15746255933920904619U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 245233356957999496U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 709926406353796673U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 13627039596842073595U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5378105439430271038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10114555061122044430U;
            aOrbiterB = RotL64((aOrbiterB * 5351295043424885549U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13233010815716769713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8231291294833548389U;
            aOrbiterD = RotL64((aOrbiterD * 10840516135212753869U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7160760224172419829U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14767926435411546785U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1643485739468851073U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4464245330038080103U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15778166658285494712U;
            aOrbiterA = RotL64((aOrbiterA * 13980891936095282989U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterB, 12U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG + ((((RotL64(aCross, 28U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 52U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28678U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 26982U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32358U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28506U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30822U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32245U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29039U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 36U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 14157904117287696136U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 57U)) + 7369512677371640676U) + aNonceWordD;
            aOrbiterC = (aWandererK + RotL64(aScatter, 46U)) + 8411250745902073798U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 5002041814539710275U) + aNonceWordG;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 9538041410816283124U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 21U)) + 5210700103927513061U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aCross, 27U)) + 7600709399101287982U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 21U)) + 2366369466696580499U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + 5544575244203019109U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8710073749110329779U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15998211310115361630U;
            aOrbiterC = RotL64((aOrbiterC * 15275657696897688955U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15354357553877376422U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10657523549259276169U;
            aOrbiterE = RotL64((aOrbiterE * 13695239532898311073U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10405750198355464768U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3465819693133515142U;
            aOrbiterD = RotL64((aOrbiterD * 14678343718277562799U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16724189641701408630U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 3484340153620198872U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 17247547677520703125U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7420442404884871126U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11138445997256757636U;
            aOrbiterJ = RotL64((aOrbiterJ * 11167543379937571127U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1428191560884663125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16950093140800653985U;
            aOrbiterA = RotL64((aOrbiterA * 4423012306984814805U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17288299075036481960U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13793597915359681028U;
            aOrbiterG = RotL64((aOrbiterG * 9639204979982125757U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5017972942710079726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12409957957614320964U;
            aOrbiterK = RotL64((aOrbiterK * 10273295741911545745U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12487994181992095174U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1573393166996612118U;
            aOrbiterF = RotL64((aOrbiterF * 13364311829104520751U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 14U)) + aOrbiterG) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 46U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Soccer_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE3314FAFE96B61EDULL + 0xCFD97A14F2D062D0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCF0814CB30011D35ULL + 0xC61F197F2C890033ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA36E9730B9F015C5ULL + 0xA73D0E02D58E2E3AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x82BED677ACD3962DULL + 0xFEA474F2292F51CEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD5033F4AAA0BE76DULL + 0xF253E5B5E5958E36ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEEE0F85DD4009165ULL + 0xC12EE4983D6A11FAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD9F415B447427FCBULL + 0x9A5230BF9F447A50ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3035A5B826F87B1ULL + 0xC8DAFDA0BEE17EA2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC0EF178D25D7C4BDULL + 0x844BEB60C2A299D2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBE94F270FC8271E7ULL + 0xFD4F95AE4609B873ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDAE36F13259ECBAFULL + 0xCBC67AED5682726AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x890CDAD1719F6F3FULL + 0xEC894C434EB23CB1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9B2041DD8E02295DULL + 0x90C57D2B8F1F9B9FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8B27770EB1DF06C5ULL + 0xB408D1DD94995B6BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x933F1F8B33F9A02FULL + 0xA9DA0874F418DFAAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB9EBE80824B52F1DULL + 0xD08B79DCE6D2AB65ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6823U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 1087U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4869U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6731U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2768U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4847U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 28U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 57U)) + 9133751643283278896U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 12U)) + 8971581804375380408U) + aNonceWordC;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 12559650383714566592U) + aNonceWordH;
            aOrbiterH = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 15753206088872859163U) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 39U)) + 7640756270450762350U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 47U)) + 7340073357551376125U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 5270256573644196046U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3567367996479995928U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11939634537492733738U;
            aOrbiterA = RotL64((aOrbiterA * 5640541900117183639U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7051817732424527120U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1730487669951837941U;
            aOrbiterK = RotL64((aOrbiterK * 15191634337956285841U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18009252467909454817U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2361024272031696442U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15902755877642960397U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12243517544704116184U;
            aOrbiterH = RotL64((aOrbiterH * 2576071074148141447U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16846181962302186187U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 636121425116506681U;
            aOrbiterF = RotL64((aOrbiterF * 17075030673338779993U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6887385655828217318U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3705834550934775862U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 11275428284929594435U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11165142437077969438U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6426659930331618269U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 17170640810530893705U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12535U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((aIndex + 12265U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 12545U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13545U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12840U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11270U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8857U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 57U)) + 3339283916456813609U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 11339086426180649584U) + aNonceWordJ;
            aOrbiterI = (aWandererF + RotL64(aCross, 12U)) + 16819191669329316585U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 8361916937762630725U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 18031328374429899857U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 51U)) + 18261756894092897276U) + aNonceWordP;
            aOrbiterG = (((aWandererI + RotL64(aCross, 5U)) + 4250319792907645666U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1492411503643460886U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17369549067879344180U;
            aOrbiterI = RotL64((aOrbiterI * 2947354306696216579U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7301713524358676722U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2985193736033012535U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 14086975808140927408U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18205555540941493267U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16967799565443938873U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9209505304067579944U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3522631966146762306U;
            aOrbiterE = RotL64((aOrbiterE * 3441982898533162599U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8811497120829041188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14707301680850257294U;
            aOrbiterK = RotL64((aOrbiterK * 11383709499376464085U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10080595991787801029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6822892187784299166U;
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterD, 48U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18469U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22205U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 18169U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 22897U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21562U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22192U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18766U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 11U)) + 7896237440058555694U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 11870529476037558635U) + aNonceWordE;
            aOrbiterC = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 9158983227801569448U) + aNonceWordF;
            aOrbiterK = (aWandererH + RotL64(aIngress, 20U)) + 4710172270996950329U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 47U)) + 14634482800356647630U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aWandererK + RotL64(aCross, 3U)) + 8822207952170610891U;
            aOrbiterG = ((((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 13755891414028982553U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4555293067488040719U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2816805148093762081U;
            aOrbiterC = RotL64((aOrbiterC * 16838149138341713943U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2122631477965135190U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4592922416380416071U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 11644507904538573165U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7102471666524164715U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 938587316977094680U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18258015823797023523U;
            aOrbiterF = RotL64((aOrbiterF * 6068819567674605919U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5809987756043471595U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5083075160112581620U;
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5960021727750946496U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5967477320950630150U;
            aOrbiterJ = RotL64((aOrbiterJ * 330964768256424655U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6578428711689296132U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5601728218197771276U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9552559022315971847U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + aNonceWordH);
            aWandererD = aWandererD + (((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 53U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 56U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32620U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 25655U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 28244U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 32643U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29012U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32053U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25000U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 2571116506511057880U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + 13112435411509707292U) + aNonceWordI;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 10403251762787357256U) + aNonceWordA;
            aOrbiterB = (aWandererB + RotL64(aScatter, 29U)) + 8461951095541400405U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 9890793478557463815U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 54U)) + 3030229465991783707U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + 7273848154043719247U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10681774862516028276U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7105082755586853104U;
            aOrbiterC = RotL64((aOrbiterC * 12217705329504230357U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 6588579345319551129U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14616333550242386092U;
            aOrbiterB = RotL64((aOrbiterB * 2934574715879306337U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15439666290229654921U) + aNonceWordB;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 3360304356760164799U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 5164191920584106237U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14438730801970761889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14515616787452085729U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2041601927968559821U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4167853822635132419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8950982233003320239U;
            aOrbiterH = RotL64((aOrbiterH * 887144270884244907U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12391327853728029953U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7100871010552394421U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 16552349374101955967U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15381697462381887944U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6801677551341079401U;
            aOrbiterK = RotL64((aOrbiterK * 13325954438427340703U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 50U)) + aOrbiterC) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Soccer_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAF7F574D75D6ED75ULL + 0xC32BCEC322F5EF13ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBA411259BE158781ULL + 0x802961B54EA3F7FBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA24028D9CDBE83BBULL + 0x8ECAD2E191519837ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB8A9FEDE221A16D1ULL + 0xDC2B6AF23DDD6561ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xABFEA86636D8BA27ULL + 0xC42C357113A32E17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFF16FB229C62AED3ULL + 0xF49CAFEF4CFBE87CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAA978ABE390C9741ULL + 0xEA35F61397AE8431ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB1C255466E078E4BULL + 0xCD4CD1D28C6482DCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC7BEC42C249E0CA9ULL + 0xE0B0B5B35618757DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x94C98E9481450BC5ULL + 0xF6D4828F1809A070ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF6CF4361C33FFC6BULL + 0xABADAFB90AC741A0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x865D253C4BD4B56FULL + 0xD366B50DE87459DCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAAA0358986C2EFF3ULL + 0xDB3E2DE515D5BD69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x939E6BC9A9DCDA6FULL + 0xD97845C89DDC0EFDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x98CCF7F1528F3363ULL + 0xD9E7531C7F7C3192ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDC04CF9C8CBEFF81ULL + 0xAE461642CA232DF3ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1163U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 910U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 461U)) & W_KEY1], 34U) ^ RotL64(mSource[((aIndex + 1884U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 7790166497945719700U) + aNonceWordC;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 7136208896846119188U;
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 12123156943355100886U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 35U)) + 5095546037880875199U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 11U)) + 17642705393916765992U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 19U)) + 9918479837334416990U) + aNonceWordI;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 60U)) + 4890009823843176466U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17652590786213674124U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 870002527644696135U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 915408393979165539U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12545429703552643682U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5310272867406182581U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 10420003334833925011U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3264719049050179440U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1967241238180278937U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13004319774269457957U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 773883832927040736U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12766817190261232485U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 7448864556802318431U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 260069382395598265U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15462103891287350123U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5029268763635635753U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4072032867513289827U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17153061419083897076U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 11934532169271718913U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 6207264270332656966U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18048064697837314947U;
            aOrbiterF = RotL64((aOrbiterF * 13632594619404208489U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 18U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 5U)) + aNonceWordA) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4424U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4879U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3792U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3138U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 8988572360732005217U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 58U)) + 17889613225105985335U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 15563478320513948626U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + 3441351228410524816U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 4425592689451435346U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 11U)) + 12733160231627305928U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 39U)) + 3574152157304607854U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15167631896729808783U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15822667973915417055U;
            aOrbiterB = RotL64((aOrbiterB * 5155661648455308057U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17181685481076577637U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9979204751408873468U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8244434774754786565U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1334240485667164762U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9190066751460137016U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 14585141844653660363U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15465215829109246336U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2305208282453624419U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10257861974108363283U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16951510027310993926U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11117938943423526901U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7805486716716924787U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12461379120662979432U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11719697049048823897U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 14880996802304818757U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6843357278142933570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterA = RotL64((aOrbiterA * 9786435451654365097U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 56U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + aNonceWordI) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6561U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 7808U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7046U)) & W_KEY1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7412U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6633U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 13924571355038625040U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererF + RotL64(aCross, 41U)) + 16328300979357156658U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 3947771961206012461U) + aNonceWordA;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 24U)) + RotL64(aCarry, 37U)) + 15428284250569311285U) + aNonceWordL;
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 5777369485254032486U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 35U)) + 16813320300717644673U) + aNonceWordK;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 16689933050200758251U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1856422419049390708U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 18214498743831925517U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 10744120577560529379U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18278550878494094923U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 797712062039591797U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7212998747080137625U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15854849439012341347U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 996882939768167773U;
            aOrbiterG = RotL64((aOrbiterG * 14936703950807908575U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3005829974130671692U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8793495343509953906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7710453029930631112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9511995836117707047U;
            aOrbiterD = RotL64((aOrbiterD * 7250766204781428201U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 670902975693341744U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9045820304668279777U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 18373074917532639027U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12417212387607119470U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12816983560669985622U;
            aOrbiterC = RotL64((aOrbiterC * 8406003970221889847U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 26U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + aNonceWordH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10760U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 9693U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 8205U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 8416U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9228U)) & W_KEY1], 22U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10175U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + 14823268998003220191U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 52U)) + RotL64(aCarry, 53U)) + 15295237288788213847U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 16434853402001133899U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 7555911304407871631U) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + 14977248264994834620U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 43U)) + 9707764144919392380U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 13U)) + 1277304385464681529U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3089786220465849395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3700503853358695085U;
            aOrbiterJ = RotL64((aOrbiterJ * 2079089949442685421U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3240054112993517371U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16897532076915366859U;
            aOrbiterG = RotL64((aOrbiterG * 4120874717534309035U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 18167359289798364307U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8870819278575769863U;
            aOrbiterB = RotL64((aOrbiterB * 9334066154398059075U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15363069206212330251U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 14858164441499725158U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 14931933411393847915U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5357144808788707522U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2910681277417754860U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9824408699018165151U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 368370224788793300U;
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7095398304588825115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11418879758164313554U;
            aOrbiterH = RotL64((aOrbiterH * 5983520332639771791U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 20U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aNonceWordH) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + aNonceWordL) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 56U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13110U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 11485U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13620U)) & W_KEY1], 23U) ^ RotL64(mSource[((aIndex + 13153U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12576U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11956U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneC[((aIndex + 11791U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 10U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 57U)) + 12262991801139086177U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 7963038771924890197U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 21U)) + 15540520327933568896U) + aNonceWordB;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 57U)) + 8745565892055020722U) + aNonceWordF;
            aOrbiterI = ((aWandererG + RotL64(aCross, 51U)) + 16619329199683755286U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 10865705026433867260U) + aNonceWordN;
            aOrbiterB = ((((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 2743368697984518059U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5556006271515473135U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5355833281353498588U;
            aOrbiterA = RotL64((aOrbiterA * 4190140212757841511U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8313616108963479829U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16657121016801866434U;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16532226425013000833U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5800465874932467232U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 5966395771690704577U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17882948163883121328U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15029375310296563175U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17021415832288477713U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10170682648007918739U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11829089574189398773U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 15755874363488568849U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1746524867389196322U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10217423427886742775U;
            aOrbiterH = RotL64((aOrbiterH * 9166162099575333519U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1338457710729082656U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1319981417675542556U;
            aOrbiterC = RotL64((aOrbiterC * 9518448254565489715U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13883U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13974U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15456U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15859U)) & W_KEY1], 46U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14500U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14616U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15122U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 57U)) + 4384716820085860551U) + aNonceWordM;
            aOrbiterC = (aWandererI + RotL64(aScatter, 5U)) + 9715780315942116888U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 29U)) + 15963520052789178632U;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 14346700690686392938U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 6005518012489966643U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 51U)) + 2506732930310252119U) + aNonceWordO;
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 3U)) + 16782163084851775826U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 823673076571076303U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1634084509064077736U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 1128407326773234517U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1288134975466877686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2998220403162908444U;
            aOrbiterJ = RotL64((aOrbiterJ * 4321412662318298283U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 220430672180734911U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10223923547068528867U;
            aOrbiterH = RotL64((aOrbiterH * 12577370238343872139U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterF = RotL64((aOrbiterF * 8387163146257553773U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 79691451831797107U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8971444023498649419U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7148919880477390009U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5624403902454498793U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9468064161002030997U;
            aOrbiterB = RotL64((aOrbiterB * 8243560528100864595U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4619361544913629805U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterA = RotL64((aOrbiterA * 10879074713156075641U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17778U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 16506U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 17644U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneA[((aIndex + 17142U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17459U)) & W_KEY1], 14U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17285U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17288U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 50U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + 14249093584376402677U) + aPhaseGOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + 8756965951816492264U) + aNonceWordF;
            aOrbiterE = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 35U)) + 11221139480258176330U) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 17218894445564194851U) + aNonceWordN;
            aOrbiterD = (aWandererA + RotL64(aCross, 41U)) + 8064642692524949490U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 5822093203710704646U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 3217799620158102238U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2613757677892120843U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13647481499551657237U;
            aOrbiterE = RotL64((aOrbiterE * 5517563514031899891U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3545714196663685016U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9735422670576621521U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 7276207208162697249U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3911046580637583767U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9315984027042049203U;
            aOrbiterB = RotL64((aOrbiterB * 12568550776487242469U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8926367674641729058U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11035347490524961446U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 10948288997163592463U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10748158733051120339U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2467801787989056455U;
            aOrbiterJ = RotL64((aOrbiterJ * 12621934274702358977U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9244415080474351390U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8517784887959492079U;
            aOrbiterD = RotL64((aOrbiterD * 17022899813765884147U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8409307332803038455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11043806021873232950U;
            aOrbiterC = RotL64((aOrbiterC * 8294888329708842989U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 54U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aNonceWordH) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 3U)) + aNonceWordE) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20213U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 19878U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19559U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 21821U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21161U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21321U)) & W_KEY1], 11U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19530U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 19812U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 13915875634607599122U) + aNonceWordH;
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 1695770381382411673U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 51U)) + 3709105579778295511U;
            aOrbiterI = ((((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 7673376335333251804U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 34U)) + 8814147709738503518U) + aNonceWordI;
            aOrbiterF = (aWandererF + RotL64(aCross, 57U)) + 13451412605350381172U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 5U)) + 6447870234069609538U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13419487997946496825U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5478309847615220345U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12953043149543448765U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3635184969215610049U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12527903812035294828U;
            aOrbiterH = RotL64((aOrbiterH * 12540800512035534967U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1684685110885338814U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12860354576326835090U;
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9081823570147481835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14369321778210049109U;
            aOrbiterA = RotL64((aOrbiterA * 17865953349448767035U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11518132079084873250U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 11893535026126957389U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 15751374986135615095U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7084079180579206226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2999676609847603277U;
            aOrbiterB = RotL64((aOrbiterB * 14602698397511266403U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17683445810614029153U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11576460512964896969U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5243651036457051155U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 44U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aPhaseGWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 24405U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 23588U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22211U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24159U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23696U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24247U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22066U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21967U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 7651355040951791298U) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 29U)) + 13988210277931659312U) + aNonceWordJ;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 9846849412579537783U) + aNonceWordA;
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 12746719939495876158U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 37U)) + 11498066185182895284U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 11101058955193080232U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 14U)) + 15513734459555672046U) + aPhaseGOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15711108675349394643U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4771231759949468556U;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11449258010811305256U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17036938391509986723U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7411466953205347639U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6999245666776654250U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2106819066263369528U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13005885810757743129U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12716183358903477216U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16752724547046059889U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17623077680983093163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6726003022297274986U;
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2842410225096524740U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9235178377537910514U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11813751114775673845U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2619888019860844610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6295481948199619613U;
            aOrbiterB = RotL64((aOrbiterB * 15429161806953951205U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25544U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 27178U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 27212U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 26802U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26139U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26994U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26850U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26387U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 35U)) + 18302975933754610273U) + aNonceWordL;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 19U)) + 16736972646771456082U) + aNonceWordP;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 17389406266488137442U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 5252511566486165539U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 13U)) + 5730715427422747640U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aCross, 39U)) + 6412695646456045825U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 27U)) + 9539701605708994494U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18355107116412945722U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11735742491750132942U;
            aOrbiterB = RotL64((aOrbiterB * 18129835093627763685U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12363819388562658842U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5861430292304371543U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 12989055611235382695U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15027487084595017708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7012850020745791926U;
            aOrbiterA = RotL64((aOrbiterA * 15952928839355613939U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11904871669287886120U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11199760114477343208U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3856004502263742700U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3705931243173921893U;
            aOrbiterG = RotL64((aOrbiterG * 10334871178498711485U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12305785390539209389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18057980996551978823U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4850564181113470859U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3229431819292153014U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 2994716629242460094U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 1029427328395257917U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 57U)) + aNonceWordN) + aPhaseHWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 60U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27859U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 28730U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28115U)) & W_KEY1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28111U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28645U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28315U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28098U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 28180U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 51U)) + 1393781663398437180U) + aNonceWordC;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 17414594746688585273U;
            aOrbiterA = ((((aWandererB + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 2823888497053071250U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 37U)) + 17032631958617884859U) + aNonceWordF;
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 15222697630461125019U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 15737414920751551780U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 19U)) + 1357196111055783001U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5315122321649251691U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7893744655508595974U;
            aOrbiterA = RotL64((aOrbiterA * 17863000246694319149U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16721939414324611738U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3444375866323610848U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10874157227815775661U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 1825716513674511632U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15582066843912467318U;
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 15673590949193923915U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13887365046280406413U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 3169061375011420121U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12730414371734709356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4819112390640821927U;
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3089925954422937464U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7180179304678622530U;
            aOrbiterD = RotL64((aOrbiterD * 16118051565147747413U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17030269962085008657U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6675917351883004046U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14134335325316949687U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 50U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 22U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordL) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31030U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 32236U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30557U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30445U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30444U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31850U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 11U)) + 2786079456995203065U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 29U)) + 7237256119153857253U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 9310834010563647604U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 17361734905706517877U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aCross, 27U)) + 15837111231884647451U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 3U)) + 18065431964418026445U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 35U)) + 3029123922999952652U) + aNonceWordA;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5166926595573507837U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1918425684273807598U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16616641579714896719U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4724551751012661440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1818014487579644390U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14904092108647864911U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6670090372241084216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8485757110007268693U;
            aOrbiterC = RotL64((aOrbiterC * 11876760095108618363U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4928130251509514742U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2528788422725346792U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2860387120895147503U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12927802338151379368U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 8876144125458603029U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18029699867733207083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13361836994951253312U;
            aOrbiterA = RotL64((aOrbiterA * 5349767426256597073U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11957294454794128079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3755417922063414648U;
            aOrbiterH = RotL64((aOrbiterH * 13896364063651241401U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 4U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererE, 36U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Soccer_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE2A365316150DEABULL + 0xF3535BE9987A5B32ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDB146B9FD90722FBULL + 0xE386B5A2091023C2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x84AFCF9D62990DD3ULL + 0xFEC9845A5D9A3D01ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9EEB290BA9BFC591ULL + 0xD01622B995AD5923ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE1AA6AC5B23EDBA9ULL + 0x9941BB16A42A6A2CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB11ADB0490916E19ULL + 0xD25C2B263270895AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCC2720B873EA22B7ULL + 0xDF392DFB1BC1228FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD31BC0EDBC6EF739ULL + 0x9FAA67364AC0F062ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE4976A9007CA720BULL + 0xE560D9CB3EBE9DC2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDB44201FE4830091ULL + 0x9FD3D78E87320921ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD4B4ED488E5E138DULL + 0xCBDA146E2570357CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCD743CE7CBF812F7ULL + 0xC8EF3316B01088C0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB28F0931444BD84BULL + 0x934CD3BB37E4F9C6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBAF28E42680A15A1ULL + 0xA2A9A53C741D379BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8A6842B50AB8A1B5ULL + 0xF7852AB3DE8D05C1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xADA6FCA5043E01E3ULL + 0xD0AC2E41EC61282EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 141U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 161U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4082U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4762U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3076U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1691U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 3U)) + 17470880031634374199U;
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 13U)) + 757565846006937746U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 9419282475801345674U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 2014248014107898196U) + aPhaseAOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 21U)) + 15113928519446490441U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7346126964886259935U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5594123113093162359U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 18043634828891483403U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5659237263369402005U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11565709683423969703U;
            aOrbiterF = RotL64((aOrbiterF * 16731289017588574671U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16782863743534856287U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13499100900072115907U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 5567729598873214433U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11414447651044205242U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7545993795121430538U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 10758488381206257261U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 11778229237616454988U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2544793391976514665U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4021060413798523299U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterF, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5694U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 5524U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8871U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 9491U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8529U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7634U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6140U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 17074147006464019918U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 43U)) + 10559516626129419928U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 13280363679503946221U) + aNonceWordD;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 17657115422132457413U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 23U)) + 13325837013304973008U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3059707750486106037U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4529045702503050852U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12889277842182219673U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 10726578475550904292U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14832537837996659885U;
            aOrbiterK = RotL64((aOrbiterK * 808060368961520519U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 220094417441809246U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15343130035105342194U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 7984652435043810845U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16592263353426409884U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15649290906447931918U;
            aOrbiterF = RotL64((aOrbiterF * 8405875177836650731U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11437410545843708269U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5859769136073011444U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1065016088086441107U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 52U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 29U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12154U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 12680U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 14274U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16002U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11244U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 8975885703279267062U) + aNonceWordL;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 8664844915562660637U) + aNonceWordP;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 14U)) + 12281774799736296726U) + aPhaseAOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 15347461352311329726U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 29U)) + 12967500561828907834U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5002833859280402726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11908257536954668983U;
            aOrbiterH = RotL64((aOrbiterH * 4384790916151202785U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17017174811949227162U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16851323125613931180U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12446990992858763577U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13469326957728686706U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5228638551056105241U;
            aOrbiterF = RotL64((aOrbiterF * 13369947664646167255U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 11945166198089308564U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16268645041872996022U;
            aOrbiterG = RotL64((aOrbiterG * 5391448793718370911U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14781204627695095701U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5365325354838101092U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 8017284997946310807U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 12U)) + aOrbiterJ);
            aWandererK = aWandererK + (((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U)) + aNonceWordI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16982U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((aIndex + 16512U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18819U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17307U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 21344U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 13880995121909552664U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 14534942818069300546U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 17745973100886007133U) + aNonceWordP;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 14U)) + 2249805580771946872U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 57U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3378683994078106878U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3992996501048809123U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 13273544260537223797U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12057768808864451929U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4115362079047921130U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12263015903331031345U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15297384955502206698U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17623548383481905636U;
            aOrbiterB = RotL64((aOrbiterB * 7487278217901483685U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3559213898000162417U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14807313864347885885U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11222085523291581822U;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterH, 30U)) + aNonceWordO) + aPhaseAWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aNonceWordB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25202U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 26234U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26516U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24542U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23770U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 5576732410244514238U) + aNonceWordD;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 5U)) + 2833808925935929629U) + aNonceWordJ;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 60U)) + 3670188682914544792U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 15759072378887814995U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 13934007231137439994U) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11022225696007690512U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16989177104453635790U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156758251105809453U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9256930045263527091U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17788596104417068290U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 675554110563253305U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17044369456673337625U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 1310908395523250343U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 16305084373037705921U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12067065689034065422U) + aNonceWordH;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 15130844248737512262U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14532689204495587494U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8198147292120244178U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1418356389507740991U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 54U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + aPhaseAWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aNonceWordK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 46U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30772U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 28238U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31925U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31938U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 31988U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 29U)) + 3238389262925516513U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 12381787182611386995U) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 7883885539305181549U;
            aOrbiterJ = ((((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 1185413044597727092U) + aPhaseAOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 20U)) + 15219353497204773135U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7533774715626734082U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2599930450937763464U;
            aOrbiterK = RotL64((aOrbiterK * 13207380361960949159U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16074720663961214284U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15483613196360051221U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11717479088020532861U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9396557867081376268U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9668459976852660245U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11748505665890567063U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9037269914643207212U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16936742640861088240U;
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 16481274825758546398U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 481851372837611166U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2225030139210599207U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 22U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordE);
            aWandererG = aWandererG + (((((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 27U)) + aNonceWordH) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 12U)) + aNonceWordP);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Soccer_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE44CB55A0979D5B9ULL + 0xD5F598586EB29FF8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF3C15E7C8FA5E02DULL + 0xB206F431D76484DCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB1AA5E201C388561ULL + 0xC7D6D7684CB640A2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE82E3AB44E3EA427ULL + 0x949DF8EC656C75A2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA155501663367947ULL + 0xC2202B0B4B1F0FAFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCB1D4FCB2ED4BAB1ULL + 0x8D37A557E0879834ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9FDA2E7AEBAA8E69ULL + 0x81EF0337FBE4D283ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF96F8988EDF4C6BDULL + 0xB0DD2EB7AE44BAEEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC0AB0319E329D665ULL + 0xA5A2FA0E6A7A6F73ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA6B845BFF54B5B2BULL + 0xA7524140EDBDB187ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE27C0F1BB75C46F5ULL + 0xA58BEC6285577054ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD55E0652BB89E3EFULL + 0xF7FE64DDB5859150ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEBEEEF08DB2658D1ULL + 0xD004B83D8850793EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE2DFA36964D60D3ULL + 0x9F8B761FF53C9040ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE86F1AD595E019C7ULL + 0x9D20A8AEA3A2BE74ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCF5C5859137C8767ULL + 0xE1162FAA770F0D2DULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5075U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 495U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2573U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4949U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7371U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1384U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 60U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 5721224134332887360U) + aNonceWordE;
            aOrbiterD = ((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 6892749729775049095U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 37U)) + 3884839462099556836U) + aPhaseBOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 11U)) + 4365431706830216193U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + 15501528746571578773U) + aNonceWordC;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 4505911326320650606U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 48U)) + 1865129050927879580U) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 53U)) + 2011737665969640369U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 27U)) + 611672935827062688U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 663547038310431047U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5468932264754299556U;
            aOrbiterH = RotL64((aOrbiterH * 11968657455484578525U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17920294117231191705U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 486058453837528110U;
            aOrbiterA = RotL64((aOrbiterA * 8851102552244026737U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2789178451938129313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 420772587981211184U;
            aOrbiterJ = RotL64((aOrbiterJ * 17402987842294006667U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16196774774442181825U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16264169656793713547U;
            aOrbiterB = RotL64((aOrbiterB * 6900221986041638783U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10207659833859860796U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 8593749091183323678U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 10696776033512404927U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7224922076047787384U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15366267474865172373U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 10134187073321814217U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4235342515820080294U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5239480080426950612U;
            aOrbiterK = RotL64((aOrbiterK * 12077621553561927079U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10891752830598395582U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7797358829694471108U;
            aOrbiterD = RotL64((aOrbiterD * 7621206775460997431U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3755715857903753416U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3172069024987421726U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16048490837178650865U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 52U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 24U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15131U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((aIndex + 10332U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12352U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 11233U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15314U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13946U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11654U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 34U)) + 6163290588946759209U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 7342672468560105447U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 47U)) + 11574563167017282321U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 2254820206194758964U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 23U)) + 1469783447473099498U) + aNonceWordK;
            aOrbiterA = ((aWandererK + RotL64(aCross, 51U)) + 14174828900676165088U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 16277954291890598132U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 18U)) + 14845750668693136766U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 150099699692047766U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1200784917165131703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9469982764806754302U;
            aOrbiterJ = RotL64((aOrbiterJ * 17851969334511301943U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10956702761701710182U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7915506894975487807U;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17335794183733623213U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 557028996286989506U;
            aOrbiterG = RotL64((aOrbiterG * 3993359298602424281U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1597385667771002414U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterE = RotL64((aOrbiterE * 4626236858205178149U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 549770198518993876U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 756554555648070919U;
            aOrbiterD = RotL64((aOrbiterD * 16272320259614325355U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7298557532533152193U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3336802611342112013U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 14679103452120080499U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2314938232094714365U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12215066333571149153U;
            aOrbiterC = RotL64((aOrbiterC * 10747052773052630601U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7762752719356805046U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6519429915769040078U;
            aOrbiterH = RotL64((aOrbiterH * 15548676502167938513U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7556691736109752918U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13731245903412646404U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15581965016668635409U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 42U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aCross, 18U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19453U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 21723U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21638U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24200U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24506U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20204U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17360U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 6916817163240024692U;
            aOrbiterA = ((((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 14554930751292077817U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererH + RotL64(aIngress, 43U)) + 1098305064484336101U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 11U)) + 12192821172420471527U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 21U)) + 2435134991707318845U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 1896745368738512624U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + 1114996424222923873U) + aNonceWordD;
            aOrbiterK = (aWandererF + RotL64(aScatter, 47U)) + 9839135798371512656U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 26U)) + 8037967239603177043U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15185468738487237432U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4912098316394854543U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 3072785550384399929U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13142688607850380888U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4507379759608945839U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2989332387754215967U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7299006009652289342U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5390655277207053627U;
            aOrbiterJ = RotL64((aOrbiterJ * 10973744708856143715U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6744737023577785725U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15539737698867067285U;
            aOrbiterK = RotL64((aOrbiterK * 4686092035261336911U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13329866734681377952U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13284937458969166257U;
            aOrbiterA = RotL64((aOrbiterA * 3965985432462699445U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8695002088915702168U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3858059421620839286U;
            aOrbiterE = RotL64((aOrbiterE * 9559783727301092937U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6609163873243179836U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9416165620556710540U;
            aOrbiterD = RotL64((aOrbiterD * 240385043740268229U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1578449067529000433U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14309000104419489303U;
            aOrbiterF = RotL64((aOrbiterF * 7599078306153684729U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15785180680737461320U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10099222679918382021U;
            aOrbiterH = RotL64((aOrbiterH * 2012232597046182581U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterE, 36U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aPhaseBWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 12U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 38U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26125U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 26617U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32013U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 32512U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28597U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27217U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 31599U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 18U)) + 8685374557928800912U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 3482312691892161229U) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + 6948130297389161165U) + aPhaseBOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 53U)) + 5506385663788942690U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 17859982009307397161U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 34U)) + 9178488809207094043U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererA + RotL64(aScatter, 43U)) + 1835479501226057169U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 5368101733632614939U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 9050459666576835422U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9042186993119635078U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17528342580198295025U;
            aOrbiterI = RotL64((aOrbiterI * 14316671546614386775U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6495418332558436882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8834495762667327342U;
            aOrbiterD = RotL64((aOrbiterD * 10783141541937645995U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4364314196965690905U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6357485231062120459U;
            aOrbiterF = RotL64((aOrbiterF * 289429584586504995U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3321488322626415347U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10817330671781848737U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 15875919466358823335U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17974092279281611763U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15187929795092006849U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13482063681546475923U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14466266308157364963U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6232152545071397380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17488906002621373262U;
            aOrbiterH = RotL64((aOrbiterH * 4719340606442742577U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12444819880507588549U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13808941689757772497U;
            aOrbiterA = RotL64((aOrbiterA * 6541360905282412317U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8049361354387692374U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7137831335606542401U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11022231291507235007U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 40U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordB) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterD, 28U)) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 48U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 40U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Soccer_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFC546B843A0A81BDULL + 0x8A2872AD249FD027ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDC99221877B495CBULL + 0xE9ADBA1E3057828FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE7612C8BD76439ADULL + 0xDC319021D7063D10ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8E99281AC3296B71ULL + 0xE312BE31C4013E57ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCC48028D618E3737ULL + 0xBD6ED147C5E43B26ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF304D89F792E59C1ULL + 0x83E62F75032E95EDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEDFD4509B9D28A43ULL + 0xDEDA610391D29752ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xED7D66E7BA5D028FULL + 0x89AF93F1AE2A52ECULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8C374B6C2BA8F7C1ULL + 0x80872A3E24161DA3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB727D683BBA4A24FULL + 0xCFE7F02FF2D9F6E2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB46DE49C040AE6A7ULL + 0xDCEBF2E2642C6F8EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x93CC7CDA103CC983ULL + 0xF9567A7AB65A0F06ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x93DE480203BD3853ULL + 0xF5308E5A0F768029ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE24FDBB39782EF87ULL + 0xCF1AAEBDE5EAFBB5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9D5BEAB7CD12951BULL + 0xAFD89E81386A00C9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9E4BA1F9479CF60FULL + 0xAF4EF6B8098887ACULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 381U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 628U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 916U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2182U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3004U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1220U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 19U)) + 12669015908335980355U;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 5438715179868613192U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 5U)) + 13172104448184536460U) + aNonceWordD;
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 13421421503244744803U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 13327113302994856582U) + aNonceWordL;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 23U)) + 4671768205922454413U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 41U)) + 5355759962838579929U) + aNonceWordA;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6691720614265406851U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7063906424700911378U;
            aOrbiterJ = RotL64((aOrbiterJ * 17091734375516280675U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17328616394166672263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1542940602574207068U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 8981679306319627975U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7203866278803132454U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 993485696233139264U;
            aOrbiterF = RotL64((aOrbiterF * 11609009908810366447U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15659679028507488331U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 18321361454094675842U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3966860765622641843U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9633319822696783352U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3496559332232402963U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1918349708324205526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7701088402761359134U;
            aOrbiterD = RotL64((aOrbiterD * 9649485438465644795U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6006824348814439686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 18088375375347012557U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12801082943086128385U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordP) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7205U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 10703U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7622U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 7957U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8032U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9500U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6897U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 43U)) + 1457104756581596530U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 6127240317844622874U) + aNonceWordC;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 16492290056044189421U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 10963676850938416468U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 4872917367399752405U) + aNonceWordK;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 52U)) + 15218882377875616148U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 5934166612122118251U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14215280930872003003U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 11428034799044600979U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 12162528943733976177U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5453003654321728726U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14273775120265649389U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5139018128323795309U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 328723770018440271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13032190719588211088U;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2386881543033598494U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1649501123340887116U;
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16462401546754210583U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1510579201823042227U;
            aOrbiterJ = RotL64((aOrbiterJ * 16287912400104043275U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6889066000014251983U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11324594596597724357U;
            aOrbiterF = RotL64((aOrbiterF * 15344987814648586023U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12237796033168436537U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17306069670330000343U;
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterK, 3U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererF = aWandererF + (((((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 58U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordM) + aPhaseDWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11232U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 13810U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 13168U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13717U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 15789U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererK + RotL64(aIngress, 5U)) + 8367680518550579791U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererJ + RotL64(aCross, 47U)) + 11491674725611181241U;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 16673861720782164214U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererD + RotL64(aScatter, 21U)) + 9786610124108350855U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 53U)) + 5745080601557577637U) + aNonceWordA;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 1959402215131684684U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 6121650036079196522U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12016309761037342392U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5986936646177049603U;
            aOrbiterI = RotL64((aOrbiterI * 3585650475703294895U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 1000367700904043468U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17425288243569101032U;
            aOrbiterH = RotL64((aOrbiterH * 2174614006719048535U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4856917474950325209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16312111093223166419U;
            aOrbiterA = RotL64((aOrbiterA * 11046477664487805241U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 456110002032422270U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11393724374787795662U;
            aOrbiterJ = RotL64((aOrbiterJ * 1176984359123668389U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8378176867715697176U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8086186452345234815U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8470349167474173245U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2528229938740192694U;
            aOrbiterF = RotL64((aOrbiterF * 8717790851266520943U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13247168811545753141U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8745293957516815264U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14270617180621072619U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 10U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 34U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 53U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17204U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 20380U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20328U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17507U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 20798U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 53U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 57U)) + 12262991801139086177U) + aNonceWordN;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 7963038771924890197U) + aPhaseDOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 15540520327933568896U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + 8745565892055020722U) + aNonceWordA;
            aOrbiterE = (aWandererE + RotL64(aIngress, 29U)) + 16619329199683755286U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 13U)) + 10865705026433867260U) + aNonceWordM;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 21U)) + 2743368697984518059U) + aPhaseDOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5556006271515473135U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5355833281353498588U;
            aOrbiterA = RotL64((aOrbiterA * 4190140212757841511U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8313616108963479829U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16657121016801866434U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 331533349428472477U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16532226425013000833U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 5800465874932467232U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 5966395771690704577U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17882948163883121328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15029375310296563175U;
            aOrbiterG = RotL64((aOrbiterG * 17021415832288477713U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10170682648007918739U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11829089574189398773U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 15755874363488568849U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1746524867389196322U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10217423427886742775U;
            aOrbiterB = RotL64((aOrbiterB * 9166162099575333519U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1338457710729082656U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1319981417675542556U;
            aOrbiterD = RotL64((aOrbiterD * 9518448254565489715U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 12U)) + aOrbiterA) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26310U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 24869U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24707U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22195U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 26432U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (((aWandererI + RotL64(aCross, 47U)) + 17454559218352016650U) + aPhaseDOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aIngress, 23U)) + 8005709669325164803U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 13393741948412816357U) + aNonceWordG;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 3665865624348875553U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 8334142570031883436U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 5U)) + 17226066128706139657U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 35U)) + 3319093033121522613U) + aPhaseDOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6657535603401588798U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5469746182326331147U;
            aOrbiterD = RotL64((aOrbiterD * 11315450342347794329U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17846791786050221418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15939541003714896288U;
            aOrbiterF = RotL64((aOrbiterF * 1400351482213119809U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12076763190461077406U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3594038213596405284U;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8301291631324464622U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8460406137668390582U;
            aOrbiterG = RotL64((aOrbiterG * 9117147929757711595U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7612394867020871200U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8525076134853103975U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 5790440201072204659U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11929899088215090379U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7119509166360685726U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5081078459225240607U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17149991983909906705U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 950223374568067343U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterJ, 20U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32579U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 27753U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27766U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28065U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29341U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + 7790166497945719700U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 3U)) + 7136208896846119188U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 12123156943355100886U) + aNonceWordK;
            aOrbiterG = (aWandererB + RotL64(aScatter, 35U)) + 5095546037880875199U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 57U)) + 17642705393916765992U) + aNonceWordA;
            aOrbiterE = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 9918479837334416990U) + aNonceWordF;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 22U)) + RotL64(aCarry, 47U)) + 4890009823843176466U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17652590786213674124U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 870002527644696135U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 915408393979165539U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12545429703552643682U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5310272867406182581U;
            aOrbiterC = RotL64((aOrbiterC * 10420003334833925011U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3264719049050179440U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1967241238180278937U;
            aOrbiterE = RotL64((aOrbiterE * 13004319774269457957U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 773883832927040736U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 12766817190261232485U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 7448864556802318431U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 260069382395598265U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 15462103891287350123U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 5029268763635635753U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4072032867513289827U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17153061419083897076U;
            aOrbiterG = RotL64((aOrbiterG * 11934532169271718913U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6207264270332656966U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 18048064697837314947U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13632594619404208489U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 44U);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterI, 60U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Soccer_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF431A4A30F6D729BULL + 0xAD09B96E54BD7087ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEF8689E4D276DB71ULL + 0x939F69D20F154A95ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC4AD1BFEBE58148FULL + 0xC066345B94197454ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8109E7C4DEE37E49ULL + 0xFBFA17B825A61718ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA575936B5B74E0E7ULL + 0xCDA60FA276F19598ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCD9E1DFD91562417ULL + 0xF4C1D69A1A775099ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEDBF6753C6421A09ULL + 0xA8B84586A48051A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x85F45C7DA9D5EA9DULL + 0x97E7C84E8D370353ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB1FD32F8A6661677ULL + 0xAF29682D32D2D38EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF008D005CAB58C63ULL + 0x97C172CE0B07C677ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA06038D3A503167ULL + 0xA1B8E8BC041A963CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC9F21DFA31A1168BULL + 0xA9330D2EE69DB2A1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF65AD7FEAE09D2A7ULL + 0xB7EDDD6ACC61F3A0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x98DC369DDA48EBF5ULL + 0xF6F0337883980191ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD13970BF5C7966CBULL + 0x8FA9638421FB5E5CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCB253D206F52557DULL + 0xE3A2EFFDF4C17BC2ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3360U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 3262U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4979U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1199U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3510U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3634U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 42U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 41U)) + 9471546960258473684U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 36U)) + 18050235435948942244U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 11U)) + 3005107102671544641U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 17898396434573801850U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 15071602525497771648U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 3U)) + 5780119462702672108U) + aNonceWordF;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 43U)) + 13301326224151025687U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 18129323022260575961U) + aNonceWordA;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 26U)) + 1199228670638790709U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 47U)) + 1839199978088021020U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 13U)) + 4999517042246790165U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8788607633376516299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15143903839930468749U;
            aOrbiterE = RotL64((aOrbiterE * 12735914889325422675U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16674732686428431869U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15908873150953195581U;
            aOrbiterG = RotL64((aOrbiterG * 18049755517524334107U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11204775359756474667U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 2525984309543939465U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 3988529812023791571U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4566345170476825512U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14876612901557406267U;
            aOrbiterK = RotL64((aOrbiterK * 9047956948845135339U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14926290877038883931U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12710203178186614846U;
            aOrbiterA = RotL64((aOrbiterA * 14841163494801662515U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7315094513967387996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11050116830482816766U;
            aOrbiterI = RotL64((aOrbiterI * 3702999495721152019U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4505368486032503953U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17905748055257551092U;
            aOrbiterB = RotL64((aOrbiterB * 14775870175093453197U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5728886950801376350U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17998141690182325170U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 16008599930125391379U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4325978018819134558U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13526905108565989379U;
            aOrbiterD = RotL64((aOrbiterD * 14121321495714166291U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10597169665474269506U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7500801022830471869U;
            aOrbiterH = RotL64((aOrbiterH * 3702717219742363777U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17063616328548689935U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9471546960258473684U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 3029748230803396737U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 56U) + aOrbiterF) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterI, 48U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aNonceWordG) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 14U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6278U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneC[((aIndex + 8158U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7601U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 9368U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10426U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10294U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6852U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 11480359716598965890U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 10U)) + 15431182525482873419U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 43U)) + 11360504974812776707U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 41U)) + 9292576416573382769U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 3U)) + 1549257414531028975U) + aNonceWordJ;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 5347769463033129317U) + aNonceWordM;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 58U)) + 17019199177478377234U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 27U)) + 16558106007323125094U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 35U)) + 3976182233825939422U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 47U)) + 2889047161195954395U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 2241831345026962605U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12850802412140579294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13541744735436450160U;
            aOrbiterA = RotL64((aOrbiterA * 906089290000537439U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2085863085516538212U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2969034221711544086U;
            aOrbiterG = RotL64((aOrbiterG * 7768528124408400403U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6482666944512391472U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16969153556875844613U;
            aOrbiterK = RotL64((aOrbiterK * 9483462388353216219U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5161314086757363678U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7150282484670673211U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 8522427002337918663U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5465304381272305847U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 2344610773390354017U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 17010258514288089191U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8335906578006588582U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13668796013474193793U;
            aOrbiterB = RotL64((aOrbiterB * 8228000547141147777U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9663362594301419686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3683773739120343413U;
            aOrbiterE = RotL64((aOrbiterE * 8319320803406104749U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2538583190438044942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4454069062219406996U;
            aOrbiterC = RotL64((aOrbiterC * 16329554225309389599U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17177136683616247897U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3680497519697457252U;
            aOrbiterH = RotL64((aOrbiterH * 6479357366957384599U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16812938441063719463U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4545693142067578891U;
            aOrbiterD = RotL64((aOrbiterD * 17479957806084346527U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 9232311730019478327U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11480359716598965890U;
            aOrbiterF = RotL64((aOrbiterF * 6678546065399772697U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 42U)) + aOrbiterB) + aNonceWordD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 20U));
            aWandererH = aWandererH + ((RotL64(aCross, 48U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13227U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 14991U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11202U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10986U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12308U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 10U)) + 13204735390996728477U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + 851171359595647173U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + 16745304202825290723U) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 562392736584913979U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 57U)) + 3244267012529053918U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 53U)) + 17282536111067869133U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 18U)) + 14851130066471729068U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 23U)) + 5256130407952363129U) + aNonceWordL;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 2904742485828362001U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 3723346325449225387U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 21U)) + 5344621093694027341U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12919263300833603026U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17989801264160996071U;
            aOrbiterK = RotL64((aOrbiterK * 15468293047311883751U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5022175042377172157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16684822380107847758U;
            aOrbiterG = RotL64((aOrbiterG * 2834049270263837537U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2740326510600876682U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13981423865219318820U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 14593082145080056441U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 231945878229848395U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14139797734944312580U;
            aOrbiterD = RotL64((aOrbiterD * 6492256080432266407U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16704102101387552373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8506734780526852552U;
            aOrbiterA = RotL64((aOrbiterA * 4684566118627414659U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2774630043988894695U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12490034334296488127U;
            aOrbiterI = RotL64((aOrbiterI * 16765455396278233145U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 545238171291436006U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1023872898002379590U;
            aOrbiterC = RotL64((aOrbiterC * 8626333831510136515U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5065187021047872560U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10391809965648089863U;
            aOrbiterB = RotL64((aOrbiterB * 10912471108849550469U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5576919045471579002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9761904001375034639U;
            aOrbiterH = RotL64((aOrbiterH * 8612901811320541361U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2001472279505185946U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11576457012366242134U;
            aOrbiterE = RotL64((aOrbiterE * 1070815118051466731U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17713147845216099336U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13204735390996728477U;
            aOrbiterF = RotL64((aOrbiterF * 10889281795183444943U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 12U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterA, 46U)) + aNonceWordN);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 34U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aNonceWordE) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19937U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((aIndex + 19222U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 16401U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17015U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((aIndex + 18923U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererF + RotL64(aPrevious, 27U)) + 3561491146322798260U;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 7075025056181885339U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 42U)) + 9230910887904171613U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 11U)) + 4119781172609908917U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 5U)) + 17155609083870983149U) + aNonceWordG;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 47U)) + 2423018561430181695U) + aNonceWordC;
            aOrbiterK = (aWandererC + RotL64(aIngress, 23U)) + 12957280305617615744U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 19U)) + 2461704174772065813U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 50U)) + RotL64(aCarry, 41U)) + 7907123257849391997U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 7257868138318960007U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 16425903703085702285U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2990822664594079467U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5654819006718953817U;
            aOrbiterE = RotL64((aOrbiterE * 4465096036756887801U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12183676471235678779U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15026286960542123922U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 17199049329995315279U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12169080607071830522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2906296852254787499U;
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3029858695410344584U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14406410317495954566U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11048818178401163861U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13622063920319445043U;
            aOrbiterC = RotL64((aOrbiterC * 2516025554421589857U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2642646089141233277U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12761571777929273548U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5518252696078700127U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7753802695131502382U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8510425459525030222U;
            aOrbiterH = RotL64((aOrbiterH * 12412361423636026483U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13522645164493316722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1437430302489702713U;
            aOrbiterK = RotL64((aOrbiterK * 14019316635365783545U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14745189473423751499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16968328257002103715U;
            aOrbiterA = RotL64((aOrbiterA * 17915588590593471981U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5001838243344386314U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13506188720092630563U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7010027510838271877U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 16902624500530747723U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3561491146322798260U;
            aOrbiterD = RotL64((aOrbiterD * 95761172090277669U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 44U));
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 46U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererA, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26073U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 26197U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 22494U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25871U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 25688U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 58U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 19U)) + 4752759164691497960U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 54U)) + 12088872623537639782U) + aNonceWordO;
            aOrbiterF = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 3734943577379734227U) + aNonceWordN;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 8854778183012444234U) + aNonceWordA;
            aOrbiterI = (aWandererE + RotL64(aCross, 13U)) + 16948373492893967275U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 7962415690046184385U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 47U)) + 1872682375669714454U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 41U)) + 7776801806943853566U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 58U)) + 16665439117257230732U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 11088186766134265676U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 11U)) + 10850237991780969350U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6464817712131305812U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 244557182884209844U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2394270354887582889U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13261563971157415841U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2323811103717827362U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11483723582415081925U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12338803568475493422U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2811342930111104982U;
            aOrbiterC = RotL64((aOrbiterC * 5020981755203607757U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5554497011738996057U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12712169745460598698U;
            aOrbiterH = RotL64((aOrbiterH * 1985586486150377769U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17415058661427002973U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9430421222715343818U;
            aOrbiterA = RotL64((aOrbiterA * 10321140659099470811U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3926618548181233180U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6172453297026957838U;
            aOrbiterD = RotL64((aOrbiterD * 1161551082037835233U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8633288765997226004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17270881130844274342U;
            aOrbiterI = RotL64((aOrbiterI * 8888559940161770791U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12232950994807835262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15352600312956742750U;
            aOrbiterB = RotL64((aOrbiterB * 6140396356904933003U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5614120002595447983U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1920822446545182835U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17049182594382482085U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 625576652179261739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2362773059031414585U;
            aOrbiterK = RotL64((aOrbiterK * 17049048587829564949U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16749690978107177915U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4752759164691497960U;
            aOrbiterG = RotL64((aOrbiterG * 8442185754037031199U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 10U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterI, 53U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterH, 48U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27773U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 30659U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30084U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28695U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneB[((aIndex + 30989U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 29U)) + 2783898056762489197U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 19U)) + 7177192902873343053U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 24U)) + RotL64(aCarry, 41U)) + 12254703232691980774U;
            aOrbiterI = (aWandererC + RotL64(aCross, 53U)) + 15446547245691219559U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 888475203006174856U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 11U)) + 3649183529366307877U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 37U)) + 4642631047518805167U) + aNonceWordF;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 39U)) + 6108329730724782250U) + aNonceWordP;
            aOrbiterC = (aWandererK + RotL64(aIngress, 43U)) + 8334054653023816636U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 5891895375031474350U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 56U)) + 3176720746238477862U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6111038696865301675U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11914998302228682704U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17005063057791320948U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18333780598768130670U;
            aOrbiterB = RotL64((aOrbiterB * 5416759844884107303U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2056115016443263153U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10245512728872962677U;
            aOrbiterE = RotL64((aOrbiterE * 707106795383284903U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4810366069422162351U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3051442983125942469U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13558537578054436423U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9285068547223654308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3203670242792002165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1770881716916463461U;
            aOrbiterK = RotL64((aOrbiterK * 13870229847371882171U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16286823712870537410U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13067191141829694202U;
            aOrbiterC = RotL64((aOrbiterC * 15629974528467350445U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3414576315085336932U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8979691827341555245U;
            aOrbiterH = RotL64((aOrbiterH * 15971594804040295757U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11370607523115189596U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1346943598249651668U;
            aOrbiterJ = RotL64((aOrbiterJ * 4994794423314630209U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2441719135451272926U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3347272129827184676U;
            aOrbiterI = RotL64((aOrbiterI * 10434510775894776597U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1116857329130532047U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 2783898056762489197U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9504855173533274401U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 40U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aNonceWordD) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 56U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 4U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 12U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Soccer_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8117221B559AB1FDULL + 0xF23364DFB0D85822ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE813020E5D320823ULL + 0xB7DFAAFC697643F2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9DF9F58A70F9E08FULL + 0xF6536B4C5C23CD51ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD57AD6475AC3B467ULL + 0xE50F3D3E931AA358ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC86F874739194F01ULL + 0xD82A5C7E57CE4AF1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE42C88C7846D0A93ULL + 0x9195BE21CC40C00EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x97789A3F3372DAD1ULL + 0xE4C81D201566B4B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8E2601937B427D75ULL + 0xBB2ABC5ED2476406ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAC4A19B6026F3727ULL + 0xFD14A168093A11F9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8BB724770D63D57ULL + 0xC02CEAB60E07BA22ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEE5A299E6719BFB3ULL + 0x9B3F59C0B9D163F7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB5E925F16B3B0D3BULL + 0xC3D341E27F3C9BBFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9BF317D63C9D827DULL + 0xABFAEE4E4E956B0DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE9C7008BB9C252E3ULL + 0xFA7A221F32B810D6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAFB3B65439052CD5ULL + 0xD60D2830EE4F2203ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAB79ED017B63F05DULL + 0x8378326F7553A1AEULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5002U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 4581U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3693U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 638U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4211U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 461U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 12U)) + 2101601659597850213U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 5U)) + 2759794072560720121U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 9443562552411269339U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 10801360546699857975U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 23U)) + 8020716394829332019U) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aScatter, 41U)) + 1021894212367773801U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 13346855534622490176U;
            aOrbiterA = (aWandererH + RotL64(aCross, 60U)) + 16359309548462953836U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 12642446944680783519U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8197424982767553380U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14346334610901859094U;
            aOrbiterB = RotL64((aOrbiterB * 16982899923227935679U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14171304260534233539U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterC = RotL64((aOrbiterC * 5012968232749075075U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10707856298471572695U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18364775750091914766U;
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8531394793118363836U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15352876929406908882U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 567682016232278157U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2068146551757663119U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 1557877740957797555U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7776122587613256525U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16430938890724272256U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4540270493783593257U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11912000645055436094U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16800749242578741498U;
            aOrbiterA = RotL64((aOrbiterA * 17804584625034241737U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5909199180260499150U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5751089915336865588U;
            aOrbiterJ = RotL64((aOrbiterJ * 15376689503142397927U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3478216857728853008U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 18007567146937338241U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6620498877303917855U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 22U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 22U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + aNonceWordK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 48U) + RotL64(aOrbiterC, 18U)) + aOrbiterA) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5680U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 9541U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9383U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 6630U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9751U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10689U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9329U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 29U)) + (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 35U)) + 15036852811491820366U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 46U)) + 305637140752898475U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 23U)) + 11948631574496129610U) + aNonceWordP;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 11U)) + 5321623592482991426U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 4075270159062690728U;
            aOrbiterE = (aWandererK + RotL64(aCross, 41U)) + 15111580500356908928U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 7244150695504160363U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 5131563519577488862U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 29U)) + 5881954992088651371U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12780935808751507998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12599159643925470226U;
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9466589929741834066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6093158735705189789U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17461243886150519249U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15456408913739900718U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11260643903290392780U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7870342756041882616U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 2431528656086173419U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 134484990005888936U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10626896209992890407U;
            aOrbiterB = RotL64((aOrbiterB * 12034131076645285597U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14031164129515132292U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1771835705730244212U;
            aOrbiterA = RotL64((aOrbiterA * 186981668443596623U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16395472745067254664U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1455944290845294254U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6757824754363319079U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17866422769075350837U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10226884082632410805U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 206035536985843815U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14474587247775371703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8501763445324525303U;
            aOrbiterE = RotL64((aOrbiterE * 5298694643596784007U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterD, 48U));
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 40U)) + aOrbiterA) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14309U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 12603U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 12055U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14837U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16160U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 11U)) + 7896237440058555694U;
            aOrbiterD = (aWandererK + RotL64(aCross, 47U)) + 11870529476037558635U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 9158983227801569448U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 23U)) + 4710172270996950329U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 14634482800356647630U) + aNonceWordK;
            aOrbiterE = (aWandererH + RotL64(aScatter, 53U)) + 8822207952170610891U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 5U)) + 13755891414028982553U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 4555293067488040719U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 37U)) + 2816805148093762081U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2122631477965135190U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4592922416380416071U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 11644507904538573165U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7102471666524164715U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17274623547879474204U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 938587316977094680U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18258015823797023523U;
            aOrbiterC = RotL64((aOrbiterC * 6068819567674605919U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5809987756043471595U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5083075160112581620U;
            aOrbiterH = RotL64((aOrbiterH * 3313957222154937503U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5960021727750946496U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5967477320950630150U;
            aOrbiterE = RotL64((aOrbiterE * 330964768256424655U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6578428711689296132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5601728218197771276U;
            aOrbiterJ = RotL64((aOrbiterJ * 9552559022315971847U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7923809409017855241U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 16479366540906497019U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 7118578387798460919U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17000467091738009736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6801634573655508028U;
            aOrbiterI = RotL64((aOrbiterI * 10584635770060137089U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 123668445682719574U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14462802805503986316U;
            aOrbiterG = RotL64((aOrbiterG * 12398236364304875941U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterH, 60U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 19U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 24U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 48U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20177U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 21465U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 19549U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19070U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19693U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 27U)) + 17912271996338180948U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 13U)) + 13259276608841847058U) + aNonceWordP;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 23U)) + 16225936008657276089U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 4U)) + 2243058962151834071U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 39U)) + 10637439274127347861U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 15312219216405992627U;
            aOrbiterB = ((((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 2393933972129878613U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 4327069337247976513U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 60U)) + 8307656353434167837U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17299145556933889336U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14458100581172798164U;
            aOrbiterI = RotL64((aOrbiterI * 16543734663677070509U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6410095654927998067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6168964796264687686U;
            aOrbiterA = RotL64((aOrbiterA * 16218071040190475953U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3667999465041020730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterE = RotL64((aOrbiterE * 6427266472526362663U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12941668202330045095U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4222032891850449934U;
            aOrbiterJ = RotL64((aOrbiterJ * 17292856787431308097U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1346342592002730785U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16860611785008118820U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 384963420804756607U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3193572711804730241U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5866881282680588589U;
            aOrbiterD = RotL64((aOrbiterD * 9226331800853634597U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17180332731328479126U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10222097519535882241U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 9422887302872778795U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8863502179821584859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14872318155712512999U;
            aOrbiterC = RotL64((aOrbiterC * 11830641277356873233U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16478790641892781150U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8414944141232294781U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17443775794621154023U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 42U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 56U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterE, 14U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererH, 50U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24515U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 24830U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22529U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23922U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 22227U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + 13960289014350612206U) + aNonceWordD;
            aOrbiterF = (aWandererB + RotL64(aCross, 3U)) + 3483331015269589730U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 19U)) + 6873299241002444518U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 46U)) + 3562094007125534229U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 11422367439932782705U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 532453428514259816U) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 13U)) + 17810941465810193088U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 11869759058631106331U) + aNonceWordM;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 30U)) + 8837581071876177566U) + aNonceWordO;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17185378327053837778U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7578253375676981500U;
            aOrbiterD = RotL64((aOrbiterD * 13371647568758721729U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17112646434432814442U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14949096407295697881U;
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4259590620758467836U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6534899413644542303U;
            aOrbiterJ = RotL64((aOrbiterJ * 7987609419215568661U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2637407498893694243U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15819295597921425711U;
            aOrbiterB = RotL64((aOrbiterB * 5202015597375051399U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6373559542002699718U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11694562937392022505U;
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3308736483775453062U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12749929710650475901U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 248428400724560945U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1569528215675579656U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 1044077933631689572U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 6443796233912755143U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8393422728124537471U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2002732612516530754U;
            aOrbiterI = RotL64((aOrbiterI * 13702146823622364279U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13469191942843147943U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7633171368709520560U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9713514012478203047U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 56U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterC, 10U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29448U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 31990U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 28070U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30803U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30598U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + 8020711767807230555U) + aNonceWordD;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 15368693777246341570U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + 5117523734225562401U) + aNonceWordH;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 27U)) + 13155269151097507808U) + aNonceWordM;
            aOrbiterI = (aWandererF + RotL64(aScatter, 60U)) + 9879303753623578272U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 35U)) + 1165799257173794826U) + aNonceWordN;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 47U)) + 930641942062732091U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 11330571332221123153U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 22U)) + RotL64(aCarry, 41U)) + 2862963158282518899U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6019186399361476659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1924419843785161958U;
            aOrbiterH = RotL64((aOrbiterH * 9485557122500346869U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12618629043591380461U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9334176504266512405U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16829692481030013551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5604784396927022709U;
            aOrbiterG = RotL64((aOrbiterG * 2833893610883508353U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16124030106598549644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16571659812830230677U;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15171089673591843703U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 2826755560293849328U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 9397017963457655287U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7318560453127859950U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3039196878830506712U;
            aOrbiterI = RotL64((aOrbiterI * 3140508261330698717U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8850992055588337843U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4219373528176869146U;
            aOrbiterJ = RotL64((aOrbiterJ * 1310964742529956743U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1341474458715938799U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15937557372891732898U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11437307017920192915U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 10U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererI = aWandererI + (((((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 5U)) + aNonceWordP) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Soccer_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDDAE41CCEA1BED5BULL + 0x9DF6811D5B6D2BF5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x955A4473BB3A21B3ULL + 0x906BF5CAE2531EECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB0F3757FE83E002FULL + 0xA04E2B54EF9C5E2BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA3365970AD0FA701ULL + 0xB2DDA567ECE0ACFBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9DD9D1114AB6B183ULL + 0xD348FD76A8DCFADFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF9A60A795B11B227ULL + 0x934282DAFFEE0CF2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF1C6782AA94C1021ULL + 0x9CAB473DE481BCB0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD2D20866548857EDULL + 0x8205EBF9EEF91EF1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE613A5784AD4AD29ULL + 0x95C5B0F3D21742B1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF569FFFC25EBC867ULL + 0xBCB2E4AE43F74556ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB6E3210CE610C44BULL + 0xF0DB8D47236CD6DBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD8DF579B7F430969ULL + 0xF43CE1D618389340ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x90CE5709EF971F3DULL + 0xFBC8859684299C3AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8A4A3CC14BEBD2ADULL + 0x9224CC4B01053A61ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x873D266659598713ULL + 0xFB043D121C2E46C4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x99F15C89B400B8BDULL + 0xDC450BEA40DA018FULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 943U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 262U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3498U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1043U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 290U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2792U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 22U)) + 15549114274303128055U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 16466750056388063241U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + 12209449840836787142U) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + 14551496099734294336U) + aNonceWordC;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 6266576428679808622U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 16892841575635668152U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 7375966221423362125U) + aNonceWordL;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 11926105302821753530U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16219253791550461124U;
            aOrbiterC = RotL64((aOrbiterC * 2117550758226173419U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7299056065319248160U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 15234001484933728439U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 8182244796017018911U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6615802589932632120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5481176858895819247U;
            aOrbiterD = RotL64((aOrbiterD * 3604590158551984877U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17220507586542139380U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterH = RotL64((aOrbiterH * 10634645686035907603U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16981960446540932787U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10897565927079518588U;
            aOrbiterA = RotL64((aOrbiterA * 418843936329303571U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2746889569299593263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4894117146736361379U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18294823016957137777U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 86828501068883383U;
            aOrbiterB = RotL64((aOrbiterB * 11432686669235402365U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 22U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + aNonceWordG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 54U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6179U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((aIndex + 6048U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9555U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((aIndex + 9660U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8777U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10024U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8288U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 43U)) + 7651355040951791298U) + aNonceWordA;
            aOrbiterE = (aWandererI + RotL64(aCross, 57U)) + 13988210277931659312U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 9846849412579537783U) + aNonceWordM;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + 12746719939495876158U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 36U)) + 11498066185182895284U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 11101058955193080232U) + aNonceWordB;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 15513734459555672046U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15711108675349394643U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4771231759949468556U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9806191054594333615U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11449258010811305256U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17036938391509986723U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7411466953205347639U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6999245666776654250U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2106819066263369528U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13005885810757743129U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12716183358903477216U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 16752724547046059889U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17623077680983093163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6726003022297274986U;
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2842410225096524740U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9235178377537910514U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 11813751114775673845U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2619888019860844610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6295481948199619613U;
            aOrbiterE = RotL64((aOrbiterE * 15429161806953951205U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aNonceWordE);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH + ((((RotL64(aCross, 14U) + aOrbiterF) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14378U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((aIndex + 14903U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13841U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14045U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12661U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 41U)) + 12027839670755583592U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 15380130703509859843U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 54U)) + 4590907433867798074U) + aNonceWordI;
            aOrbiterC = ((aWandererB + RotL64(aCross, 13U)) + 1754574023602519724U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 9832756659564903767U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 5035088494491470403U) + aNonceWordA;
            aOrbiterB = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 14199170923323644638U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8325619421264440438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 969534320779067977U;
            aOrbiterK = RotL64((aOrbiterK * 17767548306355264705U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 270575869402913847U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13344806516599578910U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10193544126281901579U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15143147951139409101U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 14425582489214169238U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 16893787086337916355U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13951127523239064584U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14177925225918293579U;
            aOrbiterA = RotL64((aOrbiterA * 13079514031864998485U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8258920744278218901U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7408161179397242453U;
            aOrbiterD = RotL64((aOrbiterD * 975737128100519169U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8581481606764773468U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10078416198417433133U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1102721083915858247U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 18299772198826189580U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18304668908084397946U;
            aOrbiterB = RotL64((aOrbiterB * 10589455451200578687U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 58U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18078U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 21200U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21213U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18593U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((aIndex + 21050U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 12692813903177772178U) + aNonceWordD;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 5U)) + 7112496446691277899U) + aNonceWordC;
            aOrbiterB = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 2112247138290568813U) + aNonceWordE;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 3699421080882855947U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 60U)) + 13761832028354380922U) + aPhaseHOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererF + RotL64(aCross, 53U)) + 9243822514887600214U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 43U)) + 6863833516853046129U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8863897995943098018U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13346785686701467520U;
            aOrbiterB = RotL64((aOrbiterB * 18074843497158380703U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15309543066305531619U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17515530938817919111U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16625193986319048245U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 760493237816424254U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7282586354117620860U;
            aOrbiterJ = RotL64((aOrbiterJ * 2327153408185290635U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4129706068526969105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7020175432730888755U;
            aOrbiterH = RotL64((aOrbiterH * 10095158356907592239U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9102258982216515596U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 10822031305361453690U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 2036205056490578491U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12571477440964330246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8436347026653095199U;
            aOrbiterI = RotL64((aOrbiterI * 17930734781213681573U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14214789872073941940U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12915911919403385001U;
            aOrbiterK = RotL64((aOrbiterK * 13161681603528031511U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aNonceWordM) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererF = aWandererF + (((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 53U)) + aNonceWordL) + aPhaseHWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25705U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 26506U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26152U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26934U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22775U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 16424657151168221875U) + aNonceWordM;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 27U)) + 17150123681886380361U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + 16041993588694572757U) + aNonceWordE;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 9871185846434828537U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 11227236398354430757U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 44U)) + 5399325217402192631U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 21U)) + 9248828789282890454U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9041370494203701062U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14944424084524970764U;
            aOrbiterF = RotL64((aOrbiterF * 10283363059424655079U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5481938174456671041U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14783648629543752715U;
            aOrbiterD = RotL64((aOrbiterD * 7260164783191886395U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 12355573914530445723U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterG = RotL64((aOrbiterG * 8495251211794343179U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16149688605937250965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 106041828692026825U;
            aOrbiterK = RotL64((aOrbiterK * 12199934305374582599U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8076098639554567792U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11155119311895580013U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1495180896564818647U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6847612160595917702U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16094377920388017367U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 4875801863643206333U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13584719866672696684U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13446209321646234607U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 9945349065094781529U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererD = aWandererD + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordO) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 4U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29163U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 30530U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29662U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31120U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneB[((aIndex + 32295U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 1393781663398437180U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 28U)) + RotL64(aCarry, 3U)) + 17414594746688585273U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 21U)) + 2823888497053071250U) + aNonceWordL;
            aOrbiterG = ((((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 17032631958617884859U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererF + RotL64(aScatter, 35U)) + 15222697630461125019U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 11U)) + 15737414920751551780U) + aNonceWordF;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 1357196111055783001U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5315122321649251691U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7893744655508595974U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17863000246694319149U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16721939414324611738U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3444375866323610848U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 10874157227815775661U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1825716513674511632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15582066843912467318U;
            aOrbiterH = RotL64((aOrbiterH * 12765146555943757373U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15673590949193923915U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13887365046280406413U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3169061375011420121U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12730414371734709356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4819112390640821927U;
            aOrbiterF = RotL64((aOrbiterF * 8782547948627685451U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3089925954422937464U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7180179304678622530U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16118051565147747413U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 17030269962085008657U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6675917351883004046U;
            aOrbiterG = RotL64((aOrbiterG * 14134335325316949687U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordP) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Soccer_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 39U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 977U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1073U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 1518U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 58U)) + 13174219512651137892U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 2715455762789269341U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 43U)) + 1338018183235594313U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 16566866551729552930U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 35U)) + 6901845297307236726U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 27U)) + 2476078302049201718U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 48U)) + 15531109473927052260U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 4087849380858572351U;
            aOrbiterA = (aWandererD + RotL64(aCross, 39U)) + 5167830630098599644U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7275995452428627217U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14794340370010024117U;
            aOrbiterC = RotL64((aOrbiterC * 8779497557416568379U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8509217403041662849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2321522025240806996U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5676672952755594051U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2304681269233504384U;
            aOrbiterF = RotL64((aOrbiterF * 15731441084605554497U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8383399721062437300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13181984036942227666U;
            aOrbiterK = RotL64((aOrbiterK * 1648761328771932069U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13602604532551684210U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12725687663616352843U;
            aOrbiterJ = RotL64((aOrbiterJ * 4684699861686199753U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5831790822416009806U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4535048543735457407U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12076777878870257053U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10617608605149381858U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5244225377862618630U;
            aOrbiterB = RotL64((aOrbiterB * 15307177251167023999U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18229989093139888456U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9728120630096192811U;
            aOrbiterD = RotL64((aOrbiterD * 16052574428163231023U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1312233443099767304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8043115602160128619U;
            aOrbiterA = RotL64((aOrbiterA * 9365756845731616963U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 52U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 56U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterF) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4210U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 4600U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3989U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4485U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 10U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 18191288703716505885U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 9824014524910417136U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 3U)) + 11953012029254917548U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 39U)) + 6297568011027199089U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + 2576999400457367975U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 35U)) + 13176139160575558254U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 9978408174563621810U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 51U)) + 16765834875061607142U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 58U)) + 16534507305459121344U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3114710944346151807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10240517868726718592U;
            aOrbiterE = RotL64((aOrbiterE * 4645691562915606463U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10721450637990777883U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16689590768796583952U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3046344179729901637U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2427422768928450209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13495584061816457831U;
            aOrbiterH = RotL64((aOrbiterH * 6670984773768885119U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7058636403765106682U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9897341853944713767U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14286816859999869231U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17749559755733386064U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12515645083926326659U;
            aOrbiterD = RotL64((aOrbiterD * 6582878478865838245U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2625692458813609962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10596240255026143019U;
            aOrbiterA = RotL64((aOrbiterA * 11605800195771080135U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12374290338067865540U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1507386663796330249U;
            aOrbiterG = RotL64((aOrbiterG * 1210241080424446087U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9288099549484146726U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15159312464747000702U;
            aOrbiterI = RotL64((aOrbiterI * 500055502081347757U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14998608679505446229U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17625038109437732009U;
            aOrbiterF = RotL64((aOrbiterF * 14785862243019841689U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterC, 12U)) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 28U) + RotL64(aOrbiterC, 4U)) + aOrbiterK) + aPhaseAWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6530U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadB[((aIndex + 5597U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8047U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6380U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 7684U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 29U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 6U)) + RotL64(aCarry, 47U)) + 8506388683755208267U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 2179323259055019735U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 23U)) + 3345902531140983016U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 17456139311481306584U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 14587864088462311164U;
            aOrbiterK = (aWandererK + RotL64(aCross, 18U)) + 13178947246650647057U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 47U)) + 12866578138946916962U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 53U)) + 13098524333655118173U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 13U)) + 15451329483787541982U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9494299579678389385U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15581954810375490643U;
            aOrbiterE = RotL64((aOrbiterE * 13670002280188424825U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4487042505730624892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2774455928791636186U;
            aOrbiterH = RotL64((aOrbiterH * 15847933919136777451U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12435319582397755819U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10077180055177766823U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3924363471701748703U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10391963896910956455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6149237416725301794U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10115917698918612823U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15673402771629639978U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14729117178956592426U;
            aOrbiterC = RotL64((aOrbiterC * 9070464269215820531U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14492001279368870240U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6278248084483259952U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16731228350971263873U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15727518866499740411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8652631010810965473U;
            aOrbiterD = RotL64((aOrbiterD * 9508484121620912715U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13660890300188313775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14699253534935936300U;
            aOrbiterK = RotL64((aOrbiterK * 3978135617259934869U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1621689916308271346U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5651399428852950385U;
            aOrbiterG = RotL64((aOrbiterG * 12220143634120124133U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 12U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterG, 6U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 37U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10507U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 10445U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 8813U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 8634U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9071U)) & W_KEY1], 54U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8648U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 57U)) + 13650869943246163567U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 50U)) + RotL64(aCarry, 51U)) + 3435284932011770999U) + aPhaseBOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 43U)) + 12388155658186776579U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 2374345913955712039U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 6095094526980292156U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 5U)) + 4965147025852444174U;
            aOrbiterH = (aWandererI + RotL64(aCross, 12U)) + 3261881216269075298U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 29U)) + 4939780217097329222U;
            aOrbiterK = (aWandererK + RotL64(aCross, 23U)) + 3019862009792676287U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 901910626217143974U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3647055146712366383U;
            aOrbiterF = RotL64((aOrbiterF * 1792602402476450009U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7731765438957392967U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13409819457393479741U;
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5415832109107794258U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8876738832313114471U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1304277600444504135U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17135570542519390359U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2373193062766802082U;
            aOrbiterE = RotL64((aOrbiterE * 4213691513185791519U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16318403285501718552U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8456043288604687045U;
            aOrbiterA = RotL64((aOrbiterA * 10556964529144571683U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10572534930284516528U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14616251186735204677U;
            aOrbiterK = RotL64((aOrbiterK * 2048651204265459805U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2837006243817205610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5315917323622194254U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4080522050089666599U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12084676282761185907U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7922080344175593788U;
            aOrbiterJ = RotL64((aOrbiterJ * 7603522302708937379U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17620847289789547792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12140386059533463650U;
            aOrbiterD = RotL64((aOrbiterD * 1443266480620969535U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 6U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 27U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 58U));
            aWandererI = aWandererI + ((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11509U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 11902U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11508U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 11847U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11064U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12283U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 11569U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 4204560462077827182U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 19U)) + 6572370199668594039U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 10U)) + 15958999876732622825U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 9969349486879280377U;
            aOrbiterB = (aWandererC + RotL64(aCross, 35U)) + 15450238998293956181U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 9128619863683138259U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 24U)) + 5691270563628979565U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + 5901029710568933106U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 47U)) + 10442738941988588834U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3508116020325721993U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13221917083569767259U;
            aOrbiterK = RotL64((aOrbiterK * 6845108555710135357U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11627915460377128176U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17858261365514253433U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7535577636975884641U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4294837988806295989U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11242915481585070249U;
            aOrbiterA = RotL64((aOrbiterA * 17540688242763829319U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13030663829236027109U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7451948220723185149U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5191778587712222029U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5575508866505031037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5161096033789876794U;
            aOrbiterE = RotL64((aOrbiterE * 16843827915802461797U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3980482740649505122U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11188906150207270241U;
            aOrbiterF = RotL64((aOrbiterF * 408550837615188413U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4435504916461645189U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9970252853543702833U;
            aOrbiterG = RotL64((aOrbiterG * 5829143716916091997U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3766347619186305854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11004616087340082895U;
            aOrbiterB = RotL64((aOrbiterB * 14469267845747063735U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17600791542296175812U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2556224430252009744U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14469426539907112137U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 18U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 48U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15608U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneC[((aIndex + 15648U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15640U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14731U)) & W_KEY1], 56U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14908U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13814U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15988U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 17074147006464019918U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 51U)) + 10559516626129419928U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 13280363679503946221U;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 17657115422132457413U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 14U)) + 13325837013304973008U;
            aOrbiterE = (aWandererA + RotL64(aCross, 35U)) + 3059707750486106037U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 4529045702503050852U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 5U)) + 10726578475550904292U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 58U)) + 14832537837996659885U) + aPhaseBOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 220094417441809246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15343130035105342194U;
            aOrbiterI = RotL64((aOrbiterI * 7984652435043810845U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16592263353426409884U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15649290906447931918U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8405875177836650731U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11437410545843708269U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5859769136073011444U;
            aOrbiterE = RotL64((aOrbiterE * 1065016088086441107U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15188064100307340341U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4367466521843260049U;
            aOrbiterK = RotL64((aOrbiterK * 15916715854192820923U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8482617283860566845U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2585745804937342972U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8267269625632139809U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1687641344403425541U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13667916445979421400U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8191322670355590027U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7684258716388029228U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14764266202380443369U;
            aOrbiterC = RotL64((aOrbiterC * 1746254773647650741U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12685190466981675661U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9958374400222383893U;
            aOrbiterG = RotL64((aOrbiterG * 12696606920219838929U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1352584794098160330U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16057453941015251708U;
            aOrbiterB = RotL64((aOrbiterB * 6051546505117202495U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterH, 26U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 6U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18175U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 17696U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 16723U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((aIndex + 18326U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17438U)) & W_KEY1], 30U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16917U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17061U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 20U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 48U)) + 17668251151213543491U;
            aOrbiterH = (aWandererE + RotL64(aCross, 5U)) + 16101602509895104517U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 57U)) + 9083915270773304935U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 12810720730318214811U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 13U)) + 18113428002071925621U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 1582208899354109878U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 41U)) + 4180688104819188154U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 36U)) + RotL64(aCarry, 37U)) + 8954598189262820611U) + aPhaseCOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 19U)) + 15360094153175355879U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8383954114668216260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15626783326234049197U;
            aOrbiterJ = RotL64((aOrbiterJ * 15058420415480073793U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10609978564404958066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterK = RotL64((aOrbiterK * 4590620354119899777U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 760077259110786536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3597338735888033063U;
            aOrbiterH = RotL64((aOrbiterH * 6548831472863517621U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4431777844935985157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10710423172154671296U;
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10240882795242085185U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7826053487019825891U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9418883403715727353U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11507423614799075545U;
            aOrbiterG = RotL64((aOrbiterG * 16189463984557044693U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11545217316421066655U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 617921402135485341U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8182920764965471653U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14456933220749921009U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7990243583564535387U;
            aOrbiterB = RotL64((aOrbiterB * 5994900368027985469U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14023633125757654751U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11319146808574958827U;
            aOrbiterA = RotL64((aOrbiterA * 13676159969338309307U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 6U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 24U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 60U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20396U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 21765U)) & S_BLOCK1], 36U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19972U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20391U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21143U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21388U)) & W_KEY1], 44U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19747U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19563U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 5088525177670191619U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 9966456257813932112U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 7707646574027146307U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 75480203757681173U;
            aOrbiterI = (aWandererI + RotL64(aCross, 11U)) + 384659134071835163U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + 3158769775373307778U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 19U)) + 17360830943513941272U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 3U)) + 5317278822721604586U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 60U)) + 1371427105215954781U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3162710551223553423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5332921933853550756U;
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10572462410297815854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10234389605554817892U;
            aOrbiterI = RotL64((aOrbiterI * 2130374833440291193U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13421365517991380605U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10186643614984034083U;
            aOrbiterD = RotL64((aOrbiterD * 8554471709467808453U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4742438973260817120U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6081590345899008846U;
            aOrbiterC = RotL64((aOrbiterC * 7069396301823124931U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15360092808493795340U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12186413069553132646U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3815981440611914267U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16756221656224451552U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12232880965861373143U;
            aOrbiterJ = RotL64((aOrbiterJ * 14196910735715726471U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10090954323470840557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15615770271463853537U;
            aOrbiterB = RotL64((aOrbiterB * 13544181592829027283U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 556029032505658411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13311879111583579039U;
            aOrbiterF = RotL64((aOrbiterF * 3924744868168749003U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8646360871497847336U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2064833941982069154U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10016546852137913163U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 56U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterK, 42U)) + aPhaseCWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterJ, 4U));
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 24495U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 22947U)) & W_KEY1], 34U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22986U)) & W_KEY1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22931U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23451U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23299U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23948U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24536U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 10U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 24U)) + RotL64(aCarry, 3U)) + 10915618884692072446U;
            aOrbiterG = (aWandererD + RotL64(aCross, 5U)) + 12634922308499254909U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 43U)) + 6533934734564499389U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 13U)) + 6744203303756105181U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 13086782386652045658U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 18U)) + 5693840533331397822U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 39U)) + 1803663542535024611U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 3597219300593287708U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 57U)) + 1429753448204448904U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17229017825587322715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1137574712801062932U;
            aOrbiterE = RotL64((aOrbiterE * 3645832160939819415U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2401991077004083378U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1332473247826139292U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11730946340796899885U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15319163439700390962U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1349242001887975499U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4744141870145159917U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6067132201862688684U;
            aOrbiterI = RotL64((aOrbiterI * 6046100687757836027U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14991509179286371800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4342608825699398682U;
            aOrbiterG = RotL64((aOrbiterG * 10240526103933275875U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3727521409410742075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3302027219498304367U;
            aOrbiterD = RotL64((aOrbiterD * 12153634588200479559U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6039539483340398858U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2902581519976937051U;
            aOrbiterF = RotL64((aOrbiterF * 2057584328877854239U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12332784713738947242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13761272577223712786U;
            aOrbiterJ = RotL64((aOrbiterJ * 14930145045480030821U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2947946397617043735U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11107014023853644521U;
            aOrbiterH = RotL64((aOrbiterH * 15030903626191481831U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 48U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aPhaseCWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 36U)) + aOrbiterG) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25169U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 26363U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25377U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26650U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26676U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26765U)) & S_BLOCK1], 34U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25245U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((aIndex + 25774U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 44U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + 7896237440058555694U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 11870529476037558635U;
            aOrbiterH = (aWandererD + RotL64(aCross, 11U)) + 9158983227801569448U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 42U)) + RotL64(aCarry, 35U)) + 4710172270996950329U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 51U)) + 14634482800356647630U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 29U)) + 8822207952170610891U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 23U)) + 13755891414028982553U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 38U)) + 4555293067488040719U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2816805148093762081U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2122631477965135190U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4592922416380416071U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11644507904538573165U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7102471666524164715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17274623547879474204U;
            aOrbiterG = RotL64((aOrbiterG * 5443572270546181789U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 938587316977094680U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18258015823797023523U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6068819567674605919U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5809987756043471595U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5083075160112581620U;
            aOrbiterA = RotL64((aOrbiterA * 3313957222154937503U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5960021727750946496U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5967477320950630150U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 330964768256424655U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6578428711689296132U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5601728218197771276U;
            aOrbiterJ = RotL64((aOrbiterJ * 9552559022315971847U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7923809409017855241U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16479366540906497019U;
            aOrbiterI = RotL64((aOrbiterI * 7118578387798460919U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17000467091738009736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6801634573655508028U;
            aOrbiterE = RotL64((aOrbiterE * 10584635770060137089U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 123668445682719574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14462802805503986316U;
            aOrbiterF = RotL64((aOrbiterF * 12398236364304875941U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 48U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 28U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29242U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 27368U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28868U)) & W_KEY1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27612U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27586U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28970U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28684U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27598U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 21U)) + 6318740973868639425U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 5487840061430920881U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 10258706763248072672U;
            aOrbiterF = (aWandererE + RotL64(aCross, 53U)) + 18356875269730338208U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + 12883160282903147010U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 47U)) + 1010140474942697730U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 43U)) + 17733939421700898293U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 27U)) + 13693055887924981201U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 23U)) + 14574732452793385269U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10832873941223609012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8212600587135328040U;
            aOrbiterD = RotL64((aOrbiterD * 5334613996794796145U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5312744319781971178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6173741211706546923U;
            aOrbiterA = RotL64((aOrbiterA * 12854414066390848249U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3693249147883790810U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18365859989736602556U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3348463719324104997U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10645056678337549771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1175668356822251045U;
            aOrbiterH = RotL64((aOrbiterH * 6579675292775345579U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13556844570541823717U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4790355739411849736U;
            aOrbiterJ = RotL64((aOrbiterJ * 4083544011788850307U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14905575502272644116U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17047244574558476634U;
            aOrbiterK = RotL64((aOrbiterK * 2356386971503880047U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10161614295718414869U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13413914082651612468U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16224039093981079491U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6072693130156927774U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4333656233793103787U;
            aOrbiterB = RotL64((aOrbiterB * 9374745547133955709U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17209776289202130250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11752001118070361543U;
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 36U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterD, 34U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 14U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31659U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30402U)) & W_KEY1], 44U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31209U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31935U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32694U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31674U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 58U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 16200278595895089008U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 47U)) + 1029614154810465897U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 18U)) + 7129562468705441295U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 14388903902433951274U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 57U)) + 1013568949315967455U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 41U)) + 3128823373497815651U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 23U)) + 14525694606889470589U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 27U)) + 14443983602196782887U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 12244220415328641190U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10477159225338766614U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2842870123078131566U;
            aOrbiterK = RotL64((aOrbiterK * 11522265477555954071U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8621138818955849917U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5038396344400303181U;
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2768613802894372496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2027754864051410015U;
            aOrbiterD = RotL64((aOrbiterD * 2461322540050569287U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2848088309172056399U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15017458513904884651U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9926904679902843055U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9079797279596336139U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15424866642305110811U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12912331089970158845U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13751764050290602740U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7694557131324740282U;
            aOrbiterG = RotL64((aOrbiterG * 14980807690491467023U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3508673897305667669U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3600868397311393233U;
            aOrbiterH = RotL64((aOrbiterH * 5165032044164139165U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1222655844979128996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2257342337168905875U;
            aOrbiterI = RotL64((aOrbiterI * 6198995971182272119U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6290990717563682725U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15308494772443447109U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1925593111157842325U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 44U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + aPhaseDWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 58U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 30U);
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

void TwistExpander_Soccer_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3656U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 1318U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2084U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2054U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6216U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7546U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 3236820517816085022U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 741288875914097926U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + 8417246926007729580U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 54U)) + 9715717805774537170U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 14360243844821619482U;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 10760908100206775334U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + 3434641779946167811U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7885568822756234567U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3041563437672051294U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11440300917533482297U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15761355327564963516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1158633562785937421U;
            aOrbiterC = RotL64((aOrbiterC * 15511324886867188235U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9338581575871970653U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14653924713599790081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3854497592598563309U;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16286980180327600557U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5092583772591249756U;
            aOrbiterI = RotL64((aOrbiterI * 13955105624639442903U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4288397994175567333U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15584236478994873104U;
            aOrbiterG = RotL64((aOrbiterG * 1860480595862755379U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5557463939827483792U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2659814275753280856U;
            aOrbiterB = RotL64((aOrbiterB * 17702430405693184643U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterA, 51U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13830U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 16097U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9110U)) & S_BLOCK1], 18U) ^ RotL64(aFireLaneC[((aIndex + 15983U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8284U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10682U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13936U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 37U)) + 2330952702412094686U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 7820188225935060799U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 30U)) + 9347644591709839145U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 13U)) + 2288624878446846870U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 9358977729492824128U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 1858511275052455039U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 43U)) + 13715478509322292552U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16413396625604260455U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17714322215518432705U;
            aOrbiterJ = RotL64((aOrbiterJ * 1904184102419934333U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16188315436202861122U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5564445841368207813U;
            aOrbiterI = RotL64((aOrbiterI * 14125834616162835983U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13717068949900594673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5729546141908425670U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4297827922736712074U;
            aOrbiterE = RotL64((aOrbiterE * 13631630436759768885U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 829520109395163673U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11547160328525174295U;
            aOrbiterF = RotL64((aOrbiterF * 4759690159673049775U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2907177944512117206U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11100346409065275671U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17927994356809011637U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1344592529249949068U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6470438516791143572U;
            aOrbiterD = RotL64((aOrbiterD * 13339390828725370475U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 36U) + aOrbiterI) + RotL64(aOrbiterD, 21U));
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19296U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 17393U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22974U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 22991U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21126U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17101U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 17607U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 50U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 57U)) + 7651355040951791298U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 13988210277931659312U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 43U)) + 9846849412579537783U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 20U)) + 12746719939495876158U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 11498066185182895284U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 11101058955193080232U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 15513734459555672046U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15711108675349394643U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4771231759949468556U;
            aOrbiterI = RotL64((aOrbiterI * 9806191054594333615U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11449258010811305256U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17036938391509986723U;
            aOrbiterD = RotL64((aOrbiterD * 7411466953205347639U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6999245666776654250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2106819066263369528U;
            aOrbiterH = RotL64((aOrbiterH * 13005885810757743129U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12716183358903477216U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16752724547046059889U;
            aOrbiterG = RotL64((aOrbiterG * 11475905692393034141U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17623077680983093163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6726003022297274986U;
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2842410225096524740U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9235178377537910514U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11813751114775673845U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2619888019860844610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6295481948199619613U;
            aOrbiterE = RotL64((aOrbiterE * 15429161806953951205U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 46U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30245U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 28813U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31054U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28462U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26000U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25009U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24736U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 5U)) + 9888431329297626900U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 2937735167534624403U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 17626022970343789617U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 21U)) + 5665660859333693743U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 5U)) + 1060537034632076669U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 11U)) + 743777763907175800U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + 5744905970181808845U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3545351394494002180U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4877547088414106007U;
            aOrbiterB = RotL64((aOrbiterB * 5416792889338547109U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11669378338379598445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13984945589234919765U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1433097875470903205U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 716415411025451152U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8542286150858297810U;
            aOrbiterE = RotL64((aOrbiterE * 9139015340823332449U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12932391786479661299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14005503313299177013U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 802663466907819743U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9382792812676318046U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5138554251079724724U;
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8522380066269546172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11825536408101906458U;
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 20U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Soccer_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3399U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((aIndex + 1825U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7992U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3764U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2345U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3753U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 13880995121909552664U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 37U)) + 14534942818069300546U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 13U)) + 17745973100886007133U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 5U)) + 2249805580771946872U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 35U)) + 4460116116396439410U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 27U)) + 3378683994078106878U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 48U)) + 3992996501048809123U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 12057768808864451929U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 4115362079047921130U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 11U)) + 15297384955502206698U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 43U)) + 17623548383481905636U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3559213898000162417U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12311605719074507335U;
            aOrbiterJ = RotL64((aOrbiterJ * 3982199462062847697U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14807313864347885885U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11222085523291581822U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 916681229436292462U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2441350114032314686U;
            aOrbiterB = RotL64((aOrbiterB * 7336079498999018067U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7361470539894653271U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12153585147213579808U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3040327545467672961U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13566300726101613579U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14875254144748509128U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9268158535644002904U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14144295981814993491U;
            aOrbiterI = RotL64((aOrbiterI * 12739937231684038161U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13861225650900541642U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12620513474052058164U;
            aOrbiterH = RotL64((aOrbiterH * 18141974182442267181U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14163773386433257965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5725700029399455855U;
            aOrbiterK = RotL64((aOrbiterK * 10446930901088908809U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16644838246877860102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6611825438224873117U;
            aOrbiterA = RotL64((aOrbiterA * 5336239588054125897U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9408958265247071226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16980073477599191801U;
            aOrbiterG = RotL64((aOrbiterG * 7985839560318985205U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6513029242607881518U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13880995121909552664U;
            aOrbiterF = RotL64((aOrbiterF * 17463079726765044639U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 34U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 58U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10551U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((aIndex + 14812U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12119U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 11639U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16141U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12808U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9269U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 3248574644570178787U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 35U)) + 4506961512959200024U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 3U)) + 8423739774540738590U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 27U)) + 6593975869641735337U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 16441716090557369103U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 40U)) + 7936601450453207914U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 13333752583560167065U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 43U)) + 8013703284795432973U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 2349852779887439236U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 30U)) + 5318539364763284138U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 37U)) + 11450957608502944376U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9058992558327552687U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 632095686920230926U;
            aOrbiterD = RotL64((aOrbiterD * 12460364388358520799U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14734218428913777098U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16344357661370784442U;
            aOrbiterF = RotL64((aOrbiterF * 15049472842002138369U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2981145363531184308U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14176472085175714494U;
            aOrbiterJ = RotL64((aOrbiterJ * 2584623327412130939U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11198457590069700889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 952584436750426828U;
            aOrbiterE = RotL64((aOrbiterE * 1165713888651280355U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4311591763498985972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16194341833989936369U;
            aOrbiterH = RotL64((aOrbiterH * 9997934560195932575U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7560794022401107431U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10683789740265711603U;
            aOrbiterC = RotL64((aOrbiterC * 15637823045351977883U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11614366395125937178U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10750771385100564416U;
            aOrbiterG = RotL64((aOrbiterG * 4987921274272444283U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2934697034132204529U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4646873794658020363U;
            aOrbiterI = RotL64((aOrbiterI * 10555456865641580175U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7913681837683568905U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17603563535330106340U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17882943067522319671U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15375641415139193079U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17059712718085411887U;
            aOrbiterK = RotL64((aOrbiterK * 13722089235751208215U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14022558453716067200U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3248574644570178787U;
            aOrbiterB = RotL64((aOrbiterB * 15249135451439374621U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 14U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16816U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 21082U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 24172U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24423U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19149U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18391U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 22594U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 38U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 10U)) + 8506388683755208267U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 2179323259055019735U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 43U)) + 3345902531140983016U;
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 17456139311481306584U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 41U)) + 14587864088462311164U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 21U)) + 13178947246650647057U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 12866578138946916962U;
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 13098524333655118173U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 15451329483787541982U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 52U)) + RotL64(aCarry, 39U)) + 9494299579678389385U;
            aOrbiterD = (aWandererG + RotL64(aCross, 35U)) + 15581954810375490643U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4487042505730624892U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2774455928791636186U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15847933919136777451U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12435319582397755819U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10077180055177766823U;
            aOrbiterI = RotL64((aOrbiterI * 3924363471701748703U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10391963896910956455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6149237416725301794U;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15673402771629639978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14729117178956592426U;
            aOrbiterB = RotL64((aOrbiterB * 9070464269215820531U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14492001279368870240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6278248084483259952U;
            aOrbiterJ = RotL64((aOrbiterJ * 16731228350971263873U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15727518866499740411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8652631010810965473U;
            aOrbiterE = RotL64((aOrbiterE * 9508484121620912715U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13660890300188313775U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14699253534935936300U;
            aOrbiterF = RotL64((aOrbiterF * 3978135617259934869U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1621689916308271346U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5651399428852950385U;
            aOrbiterD = RotL64((aOrbiterD * 12220143634120124133U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9833573729127477238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11171647423058940388U;
            aOrbiterK = RotL64((aOrbiterK * 9692915620701425697U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10346908196429120039U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11972183669378621435U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12364429258926549335U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11063215816236490488U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8506388683755208267U;
            aOrbiterH = RotL64((aOrbiterH * 11514304191652750181U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 60U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28114U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 28604U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25588U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 24597U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25354U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29382U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26313U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 36U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 5568146815535263910U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 3U)) + 7736084960873834666U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 1336413621817562093U;
            aOrbiterG = (aWandererE + RotL64(aCross, 54U)) + 5218462026934984692U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 51U)) + 7048890985969555935U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 27U)) + 13415955213864702118U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 47U)) + 5657023257021528548U;
            aOrbiterE = (aWandererD + RotL64(aCross, 43U)) + 14338310943137497116U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 29U)) + 12305161641833950473U;
            aOrbiterA = (aWandererA + RotL64(aCross, 12U)) + 14514226578370459131U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 12692904083266024340U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11012959130001327964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7106471380403489078U;
            aOrbiterI = RotL64((aOrbiterI * 515626559384817223U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3718101961355280891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13364192077222322664U;
            aOrbiterC = RotL64((aOrbiterC * 1411328915372590283U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6720867800318913440U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14497243926965866546U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13595058589060114653U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5789056168233262435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14438482587495779937U;
            aOrbiterB = RotL64((aOrbiterB * 10593535547917767263U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 313917798940179945U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15241845511889502917U;
            aOrbiterD = RotL64((aOrbiterD * 16483477103771326107U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3591957424821693032U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1559050939014453558U;
            aOrbiterH = RotL64((aOrbiterH * 17933346117866604725U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15340590914441451383U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5538037287390050110U;
            aOrbiterK = RotL64((aOrbiterK * 4082576643144951473U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4151270491894969214U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 263593701314144898U;
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9025145270653080646U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6867950904094870056U;
            aOrbiterJ = RotL64((aOrbiterJ * 9975247022340627751U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3183454301841252109U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3054904157641290615U;
            aOrbiterA = RotL64((aOrbiterA * 4092317552439599475U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1768555574434776135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5568146815535263910U;
            aOrbiterE = RotL64((aOrbiterE * 12466957001078663927U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 50U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Soccer_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3196U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 6083U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 3714U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1276U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7370U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 599U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 16519040829220310189U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 39U)) + 6888002778416941825U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 56U)) + RotL64(aCarry, 43U)) + 1310832187746534025U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 5890888009051281674U) + aPhaseGOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 5143864838362464857U) + aPhaseGOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15591534069452660003U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1466867671765325096U;
            aOrbiterF = RotL64((aOrbiterF * 1277202105237572301U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13931443680107902488U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15400747367673245552U;
            aOrbiterJ = RotL64((aOrbiterJ * 7011651369456453127U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2836975369734495759U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2370720358274970117U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4615571902817575375U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3470677184188006133U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7175584278499266723U;
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6095078817776863055U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2176637999243513070U;
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 18U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 50U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13140U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 16159U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9270U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12856U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12474U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 16007U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 50U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 10726035965553989335U) + aPhaseGOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 967354339530195662U;
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 10834593005478605624U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 1012888282838656933U) + aPhaseGOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 51U)) + 15283530351725183253U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11724495956731703750U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4288330117317505776U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2738997410474076757U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10894778070022873473U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15563886747621617467U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17884709931569040065U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11182488628562891937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10420140066310588580U;
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11775138062167543111U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16545391898578161683U;
            aOrbiterA = RotL64((aOrbiterA * 14588306527161321535U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1550144656312299266U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14903504853138279883U;
            aOrbiterG = RotL64((aOrbiterG * 8003033561266164387U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 50U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20421U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 18134U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20473U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23643U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21202U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21782U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 13204735390996728477U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + 851171359595647173U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 21U)) + 16745304202825290723U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 29U)) + 562392736584913979U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 3244267012529053918U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17282536111067869133U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14851130066471729068U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6308165353504550619U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5256130407952363129U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2904742485828362001U;
            aOrbiterK = RotL64((aOrbiterK * 12941135856735075457U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3723346325449225387U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5344621093694027341U;
            aOrbiterI = RotL64((aOrbiterI * 9044881458629673499U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12919263300833603026U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17989801264160996071U;
            aOrbiterB = RotL64((aOrbiterB * 15468293047311883751U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5022175042377172157U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16684822380107847758U;
            aOrbiterF = RotL64((aOrbiterF * 2834049270263837537U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 14U)) + aOrbiterI) + aPhaseGWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25621U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 27188U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 32343U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25504U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28557U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29004U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 6733949564325516029U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 7304098437143918796U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 3923949518391777800U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 12U)) + 14243591003388927124U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 57U)) + 18329498724605410406U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13118172167747037249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5272025143849174212U;
            aOrbiterA = RotL64((aOrbiterA * 9935990954321437743U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16075917179214318424U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15263590648674658399U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9918239923411740337U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13730046728289525921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7703141464499623408U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5886009900621521987U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1382279753822135359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2973369221699098292U;
            aOrbiterK = RotL64((aOrbiterK * 7440242040663550631U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11578274119583013219U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3419411247737896674U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17814942652262802991U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_Soccer_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3315U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 1705U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6176U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6635U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5490U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 441U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 57U)) + 11700815697312060726U) + aPhaseHOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 11808423452327465441U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 19U)) + 8670503858631730886U) + aPhaseHOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 2400061067991988544U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 16163118178366229686U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3280178595904941068U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3298683600817047727U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9865649058799255343U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16321624053445183574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6730229877611375225U;
            aOrbiterE = RotL64((aOrbiterE * 2022290495153519279U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10162830636713641322U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15646771327759599256U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14841751262270544102U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9545541117228834895U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14676615635857599982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1231768638470558855U;
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterI, 22U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12578U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 9887U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16315U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15460U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9565U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14754U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 11210042748013785976U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 4584747303233477454U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 29U)) + 8878765929792969517U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 38U)) + RotL64(aCarry, 13U)) + 2172232330280041122U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 8378937026022264016U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8683007464695824208U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9564352997357118134U;
            aOrbiterC = RotL64((aOrbiterC * 17869948990449143305U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11713878436769887528U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8052917623074021077U;
            aOrbiterI = RotL64((aOrbiterI * 7450115139081623477U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7720597162792145185U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2602847785328475621U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14065077077207224525U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17813669222300509724U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8724263063156573013U;
            aOrbiterA = RotL64((aOrbiterA * 3632927017737834359U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6882429835961613492U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13213313479525717359U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2411431247725974895U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 38U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21706U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 18504U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20290U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21395U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24165U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21795U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 42U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 9774364261626083532U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 18059001521926116420U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 10615626210406381148U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 10536484278007898620U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 43U)) + 13320663045139972700U) + aPhaseHOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17127001787268166583U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16742574590844166551U;
            aOrbiterH = RotL64((aOrbiterH * 17828964140627204983U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8347719720758228053U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13502468705946051986U;
            aOrbiterJ = RotL64((aOrbiterJ * 13822952083584784695U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3512687886188904904U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 495660316165795934U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6724596801190194913U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5092722552034477356U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15641128019608284015U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3621036395703527059U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15421873776811085458U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17978775513204574125U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18359600395119440183U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 4U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32576U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 29927U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 25273U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29295U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31829U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 30330U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 38U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 12690502671561165478U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 14U)) + 17519943923428102801U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 27U)) + 10705515807975331385U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 16586447272278538179U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 8006560996840971798U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12928600185788857701U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14240723153798267172U;
            aOrbiterH = RotL64((aOrbiterH * 7446040187505339853U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8636219177994872072U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7586790235186467512U;
            aOrbiterD = RotL64((aOrbiterD * 15052686382507614169U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1103807034179512424U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7547526530239498693U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3360295583636013509U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8380239679344786397U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5354724308093372953U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8390902801141804609U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3507306189192059486U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18336280496510253103U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
