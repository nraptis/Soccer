#include "TwistExpander_FootBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_FootBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xADB049B539D41BE7ULL + 0xD901947ED3663C41ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCD629196B9536F45ULL + 0xA9335E99156A868CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC37276AD455EB761ULL + 0xE269C6B41A1146C3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x88689AC11B9552A9ULL + 0xF55489997341129AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF091186FC1D1C619ULL + 0xAC75A5EC7CC05419ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xED611B0A420EAB6FULL + 0xA9B10D24EAEFCC96ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9BECB72CB1D3A8ADULL + 0xE5F45A1319EE4114ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x870C0B33C03EBD5DULL + 0x996056B6C98AA453ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB631428BCEA18791ULL + 0xE59D1837BC449AA4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC10CF5D91803CA37ULL + 0xCF8EAE267BB66D34ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE192341F08D1073DULL + 0xB98DA2EF3C0FB002ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA830EC6FCC8ACF01ULL + 0x97A7840828468E38ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF180E720E4B340BFULL + 0xD2CE0AEC6935ACD7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC56769D3EE5217BDULL + 0xA592C4C57E982385ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD95F9DAB69BB5B53ULL + 0xBB703696B1C91B01ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9B27BD4D48E63587ULL + 0xA592D58C96AB4A9DULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3403U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 3507U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 4559U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 728U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 13583136155674166402U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 27U)) + 12830472187484919497U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 3U)) + 18081197909484522509U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 29U)) + 8680634051297891550U;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 13939998767458656823U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 1795730579103692594U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 43U)) + 17369751719734069999U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 51U)) + 224769585901248068U) + aNonceWordN;
            aOrbiterK = (aWandererF + RotL64(aScatter, 19U)) + 4133547085925268180U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 7022512056309567391U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 41U)) + 10319484359046945495U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10483878349412282069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6481381149199985736U;
            aOrbiterH = RotL64((aOrbiterH * 9701719367082506253U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13721077228796934509U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9704818014314175007U;
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6253040047758584339U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16890211690273641226U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5622534399866057841U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6216227831265032436U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2023609047004658739U;
            aOrbiterF = RotL64((aOrbiterF * 3252332895698310147U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9201669637050388263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5106927540934338576U;
            aOrbiterC = RotL64((aOrbiterC * 6368134569042291431U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10080368957861445998U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10784789383436485808U;
            aOrbiterK = RotL64((aOrbiterK * 3794918350254445939U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15426339824951793026U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17637144549368340331U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9941300382181962134U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8118046374121322097U;
            aOrbiterB = RotL64((aOrbiterB * 8481945819050983127U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5138086185042567633U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7279942739248982986U;
            aOrbiterJ = RotL64((aOrbiterJ * 12911998308338410917U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12135610639038562853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12945353426409788798U;
            aOrbiterA = RotL64((aOrbiterA * 7434977715954413699U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7534876598022096222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13583136155674166402U;
            aOrbiterE = RotL64((aOrbiterE * 8194058098043157015U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 46U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 21U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 12U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8353U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10032U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6904U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 8185U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 48U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 43U)) + 3550722402315312207U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 16724184551669522754U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 4U)) + 981751330116773021U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + 7891159229704944868U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 13618396711464799841U;
            aOrbiterG = (aWandererC + RotL64(aCross, 39U)) + 5969291018449003648U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 37U)) + 14595540413313640042U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 3287990436916111762U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 57U)) + 12534369400200483704U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 27U)) + 2277312067930392274U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 10026320559261334353U) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11258082063135659551U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1445958517675746990U;
            aOrbiterK = RotL64((aOrbiterK * 10062265337488757971U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1011298251290970844U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9966279022928268335U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 10285993486057704393U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 15965714363201157535U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16005362468813966136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 223843444699390781U;
            aOrbiterA = RotL64((aOrbiterA * 665392038954573081U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18178876294968532775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12490136112181806806U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 16380841616662993709U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8775696166557913635U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16464340319444310842U;
            aOrbiterE = RotL64((aOrbiterE * 18111632334728200721U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6296039992673546227U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7152939277656436037U;
            aOrbiterD = RotL64((aOrbiterD * 15183918431501487319U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14066791413416223271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5026743227399908016U;
            aOrbiterG = RotL64((aOrbiterG * 5891343232759075675U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12923870516588764609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2509970166609982397U;
            aOrbiterB = RotL64((aOrbiterB * 10708677957633925007U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15155802288437422950U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15615656627428205711U;
            aOrbiterI = RotL64((aOrbiterI * 6199439196177598589U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17233751123865498186U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3550722402315312207U;
            aOrbiterH = RotL64((aOrbiterH * 2247546626523919155U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 14U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 39U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13071U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13330U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11277U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 14789U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 26U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 48U)) + RotL64(aCarry, 27U)) + 4752759164691497960U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 37U)) + 12088872623537639782U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 3734943577379734227U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 51U)) + 8854778183012444234U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + 16948373492893967275U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 23U)) + 7962415690046184385U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 46U)) + RotL64(aCarry, 35U)) + 1872682375669714454U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 3U)) + 7776801806943853566U) + aNonceWordD;
            aOrbiterC = (aWandererD + RotL64(aScatter, 57U)) + 16665439117257230732U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 11U)) + 11088186766134265676U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 39U)) + 10850237991780969350U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6464817712131305812U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 244557182884209844U;
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13261563971157415841U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2323811103717827362U;
            aOrbiterJ = RotL64((aOrbiterJ * 11483723582415081925U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12338803568475493422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2811342930111104982U;
            aOrbiterH = RotL64((aOrbiterH * 5020981755203607757U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 5554497011738996057U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12712169745460598698U;
            aOrbiterF = RotL64((aOrbiterF * 1985586486150377769U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17415058661427002973U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9430421222715343818U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10321140659099470811U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3926618548181233180U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6172453297026957838U;
            aOrbiterG = RotL64((aOrbiterG * 1161551082037835233U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8633288765997226004U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17270881130844274342U;
            aOrbiterK = RotL64((aOrbiterK * 8888559940161770791U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12232950994807835262U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15352600312956742750U;
            aOrbiterE = RotL64((aOrbiterE * 6140396356904933003U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5614120002595447983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1920822446545182835U;
            aOrbiterB = RotL64((aOrbiterB * 17049182594382482085U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 625576652179261739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2362773059031414585U;
            aOrbiterC = RotL64((aOrbiterC * 17049048587829564949U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16749690978107177915U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4752759164691497960U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8442185754037031199U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 18U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 6U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterH, 27U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 24U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18586U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 19144U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19684U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20913U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 10U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 46U)) + 1364174714924216027U) + aNonceWordN;
            aOrbiterB = (aWandererB + RotL64(aIngress, 43U)) + 13561796874229506613U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 11845572344206238305U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 15762708240326773763U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 51U)) + 1157119665207900473U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 29U)) + 6823546624372055260U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 14465564210523945121U) + aNonceWordG;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 27U)) + 10667464548080807531U;
            aOrbiterE = (aWandererG + RotL64(aCross, 60U)) + 13445737493224316575U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 3U)) + 3009837893785957665U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 21U)) + 2886920524111083752U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10886177449328249656U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15067759884678100433U;
            aOrbiterD = RotL64((aOrbiterD * 5724566815989860041U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18307930462682331536U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8791864377579255801U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 805797468642992351U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5743305867058244964U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17102025528234481273U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1841579177327486899U;
            aOrbiterH = RotL64((aOrbiterH * 3841603385577825265U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2189493507896508972U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18209567010094914374U;
            aOrbiterG = RotL64((aOrbiterG * 3737080408976852351U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6697069234216868330U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 927471474577415372U;
            aOrbiterE = RotL64((aOrbiterE * 10680760991009199309U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13155854301197725408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1014625081915435892U;
            aOrbiterA = RotL64((aOrbiterA * 11592754232949990435U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12697209921410914931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11555096613655648647U;
            aOrbiterC = RotL64((aOrbiterC * 4598821388864997089U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9335308231651271690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3160859883353473444U;
            aOrbiterK = RotL64((aOrbiterK * 4753600703924906409U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15681189182414315768U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3147692210581710663U;
            aOrbiterB = RotL64((aOrbiterB * 6271949093080510861U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5373388632562432117U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1364174714924216027U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4694926665965807945U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 42U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 34U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23455U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 24618U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23286U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23823U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 38U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 58U)) + 3236820517816085022U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 741288875914097926U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + 8417246926007729580U) + aNonceWordF;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 9715717805774537170U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 29U)) + 14360243844821619482U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 10760908100206775334U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 3434641779946167811U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 7885568822756234567U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 48U)) + 3041563437672051294U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 39U)) + 15761355327564963516U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 43U)) + 1158633562785937421U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9338581575871970653U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9172038894262857354U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3110871165285625807U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14653924713599790081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3854497592598563309U;
            aOrbiterK = RotL64((aOrbiterK * 11737111068815795303U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16286980180327600557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5092583772591249756U;
            aOrbiterA = RotL64((aOrbiterA * 13955105624639442903U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4288397994175567333U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15584236478994873104U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1860480595862755379U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5557463939827483792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2659814275753280856U;
            aOrbiterC = RotL64((aOrbiterC * 17702430405693184643U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6941807963525063449U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2040598555191211307U;
            aOrbiterF = RotL64((aOrbiterF * 14750544987531722765U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 347572666231116258U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 779304821185302523U;
            aOrbiterD = RotL64((aOrbiterD * 14180254150318109855U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10632524582873079742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9761308771280517212U;
            aOrbiterE = RotL64((aOrbiterE * 13926235411726048921U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2097439707055737964U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2813977930321463948U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 14983538728730662603U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6080592019313796689U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5396623654821376409U;
            aOrbiterJ = RotL64((aOrbiterJ * 15478858835919398677U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8460497459575045342U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 3236820517816085022U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 5530411244458067093U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28933U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32419U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27611U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31225U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 58U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 47U)) + 5721224134332887360U) + aNonceWordH;
            aOrbiterC = (aWandererK + RotL64(aIngress, 39U)) + 6892749729775049095U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 43U)) + 3884839462099556836U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 5U)) + 4365431706830216193U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 58U)) + RotL64(aCarry, 35U)) + 15501528746571578773U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 4505911326320650606U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 35U)) + 1865129050927879580U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 21U)) + 2011737665969640369U) + aNonceWordI;
            aOrbiterK = (aWandererH + RotL64(aScatter, 53U)) + 611672935827062688U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 663547038310431047U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 37U)) + 5468932264754299556U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17920294117231191705U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 486058453837528110U;
            aOrbiterE = RotL64((aOrbiterE * 8851102552244026737U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2789178451938129313U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 420772587981211184U;
            aOrbiterH = RotL64((aOrbiterH * 17402987842294006667U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16196774774442181825U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16264169656793713547U;
            aOrbiterB = RotL64((aOrbiterB * 6900221986041638783U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10207659833859860796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8593749091183323678U;
            aOrbiterJ = RotL64((aOrbiterJ * 10696776033512404927U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7224922076047787384U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15366267474865172373U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10134187073321814217U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4235342515820080294U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5239480080426950612U;
            aOrbiterK = RotL64((aOrbiterK * 12077621553561927079U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10891752830598395582U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7797358829694471108U;
            aOrbiterG = RotL64((aOrbiterG * 7621206775460997431U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3755715857903753416U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3172069024987421726U;
            aOrbiterD = RotL64((aOrbiterD * 16048490837178650865U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 8623351347363497301U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5895306804546658158U;
            aOrbiterI = RotL64((aOrbiterI * 1568542219600635919U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5026075347235960113U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3706258841140585921U;
            aOrbiterC = RotL64((aOrbiterC * 4911715089264902109U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6753904207571971217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5721224134332887360U;
            aOrbiterA = RotL64((aOrbiterA * 4531182106796534951U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 6U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 14U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_FootBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEBD31FD2AB22BF47ULL + 0xF10C7443EE8E6D9FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB375DD4CA95E6EB1ULL + 0xBC026F0116D10D76ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE1FE77C0A17627AFULL + 0xA226426B22B25BEDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x96E9262CA0D5A70FULL + 0x93B4BB1184DBBB0CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA09765478DE9B33BULL + 0xDE9A45A47E0391BBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x94904D6BFDAA489DULL + 0xE19F5C51C39CF1AFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEE52445A90808DD9ULL + 0xBBF6589FA60F65D4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCC7E211734F372F5ULL + 0x8F013C8FECDCE48BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC1C5FEF4B1C189B9ULL + 0xD18A8BC442B65C4BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDF6F2004C3E5055BULL + 0xB19C243F541C43B6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD2B098CB5EAA2F2FULL + 0xA27FF7B5E6CEC0FAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA488EB4206E21A5BULL + 0xD769E4CAB73FF4ABULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF0E8BFD5394C1A0FULL + 0xCBB6D0A97CA94656ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBAFD482738BA05A9ULL + 0xDBA0A4129D3FA9F0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDD8218E6BA6CB01DULL + 0x8F272C1E2F16A197ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB84C4A57DD5D699DULL + 0xDC05506CF79CC7C0ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3097U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 5447U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8113U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 261U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 4476099022490972343U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 16836423700375760429U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 56U)) + RotL64(aCarry, 11U)) + 8850577488928703557U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 11U)) + 7091631824560042743U;
            aOrbiterC = (aWandererD + RotL64(aCross, 29U)) + 12560498899956759494U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 7797973377112012161U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 60U)) + 6173820673874805794U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 10805025132310245348U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 19U)) + 7139216143268029968U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8241544862261635722U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 4735527016563596150U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6621354217673598381U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5166171126690294033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11117641762075368393U;
            aOrbiterG = RotL64((aOrbiterG * 4980156869201219393U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6312932356458415421U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1304139291184508668U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 90744653170922319U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10085025354842771067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16745854428789531080U;
            aOrbiterJ = RotL64((aOrbiterJ * 1945983905747274355U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2497187958708890337U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16069701876646548995U;
            aOrbiterI = RotL64((aOrbiterI * 16606039730973709495U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17242004368025978091U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12334315722243232121U;
            aOrbiterE = RotL64((aOrbiterE * 16528598396696346719U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8007042082518126895U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5665686359038811484U;
            aOrbiterH = RotL64((aOrbiterH * 11289316305875751813U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3913477186958600592U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16918984318564170343U;
            aOrbiterD = RotL64((aOrbiterD * 5128293326494417281U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10227611546502931418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7187623463085447228U;
            aOrbiterC = RotL64((aOrbiterC * 8479839369622163181U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 18U)) + aOrbiterG) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterH, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 60U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10288U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12228U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10836U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 13871U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 12426357877879529292U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 11U)) + 12604900366173639176U) + aNonceWordH;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 4U)) + RotL64(aCarry, 3U)) + 13511119007338929401U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 53U)) + 9878720081166788060U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererE + RotL64(aCross, 23U)) + 15463195409806395076U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 47U)) + 6407922778852833423U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 19U)) + 7690427254160734016U) + aNonceWordO;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 18030974031722143619U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 37U)) + 17983938038322737041U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16605512170117753884U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 681802273302348322U;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15550312921312083819U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17824154101711884508U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1939207786756735430U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3132864634777826569U;
            aOrbiterG = RotL64((aOrbiterG * 13606281919426730325U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12822929773923954849U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16576106045887115660U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16370914370769903051U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2398825881649235260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13700821892926092479U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10830623703416956043U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2439833784883391606U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15870638514107637833U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3797380922767479287U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9165457123134229670U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8736642509192659417U;
            aOrbiterB = RotL64((aOrbiterB * 16219277537523484065U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9232719746484835693U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7826680628853322541U;
            aOrbiterI = RotL64((aOrbiterI * 12578050118133526187U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14323652326982518782U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2254524512851399313U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4119339547645451149U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterG, 58U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterH, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 22U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23846U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 23015U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23724U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 22950U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 23U)) + 6771552164800695068U) + aNonceWordG;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 34U)) + 12131763371571322040U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 3326182381395522013U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + 12288775097697156383U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 29U)) + 5195948373449796741U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 14404044002250137144U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 13U)) + 11142382920035825426U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 2967149520256475485U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 42U)) + 1470907369577818097U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9231668148004163910U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13078929163913892386U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7509829068700523627U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9485274692075657877U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12216951187543631673U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6933334652581744234U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17260276102423580920U;
            aOrbiterE = RotL64((aOrbiterE * 7796879893790990605U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 387767848169714392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8597538259308082638U;
            aOrbiterF = RotL64((aOrbiterF * 4888054690557707241U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7996708724489146033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15357384191688149939U;
            aOrbiterI = RotL64((aOrbiterI * 9827691726832491373U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17739222908739454637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1614322333281471170U;
            aOrbiterG = RotL64((aOrbiterG * 7063116837752240891U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4531604274893197209U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3453280714992341288U;
            aOrbiterC = RotL64((aOrbiterC * 8390029711127907805U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 116623650872661533U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6565636510115095988U;
            aOrbiterJ = RotL64((aOrbiterJ * 9691897067492501177U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10303258439817808058U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10917642773040237611U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 10232856828372963363U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 50U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterC, 14U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 6U));
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30328U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27083U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31823U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26408U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 39U)) + 15316464782468770057U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 35U)) + 6642872057476351588U) + aNonceWordP;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 660732654689529192U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 7235418086884000655U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 14784518476694580493U) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 12222433977933449375U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 12U)) + 8573001207708329927U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 16035256260815013172U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 15767726974121910203U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17712217935322939971U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13488963456923357159U;
            aOrbiterG = RotL64((aOrbiterG * 16785285630840310405U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10222949131965611079U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1495561412321657209U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9706305581868526265U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16156530750584361434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7773792489045606309U;
            aOrbiterD = RotL64((aOrbiterD * 10730624207715601393U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11544578291333360613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3665587867634242865U;
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15248434984650998090U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15487979645426567581U;
            aOrbiterK = RotL64((aOrbiterK * 10868107809356766183U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6972347795052712690U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16074994810010431338U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1262655238856775853U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16851139687900415292U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14630026837021552812U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9577900853521254603U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14236330619137368169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17778707026111136216U;
            aOrbiterA = RotL64((aOrbiterA * 16239561893843454747U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9390961969105999083U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1174881758316573228U;
            aOrbiterJ = RotL64((aOrbiterJ * 6602061268277529311U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 18U));
            aWandererE = aWandererE + (((((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 52U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 36U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordI);
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

void TwistExpander_FootBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA76771495752A499ULL + 0xB5A9042D56A4A90BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8FA9D43EF970A747ULL + 0xD92A9AC05D0943EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF166FC6ACD80E0E3ULL + 0xA43CA5CE2BAE2F23ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFC14AA41C832ADD9ULL + 0xC199A0C6CCB63D2DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC9A57CCA700A4CC5ULL + 0x93A8F72AADE0B8BCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x90F5966D3A431F4BULL + 0xA5871E346C921779ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x99B65C4EF7F21BB9ULL + 0xBD0CE933EF53D357ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB5534D64E5A1454FULL + 0xE816EA6F038E9FE7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x80A5287B04AE0F05ULL + 0xE1A862A5E8913C56ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE6BC03A48B85BA9BULL + 0xB3B08F7266D58B2AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC2056B04798A1AB1ULL + 0xFA683B48DD8E7AE0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCE3C55CE42092047ULL + 0xAD07B55D6F392353ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8AC6EC65343C5E1DULL + 0xC4C6B4C1FD89E271ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB94316357630FB21ULL + 0x99D127D5A0889A6BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9C5D6F39DAD92FB3ULL + 0xE2608110E4DD5DC6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE1F6C2318EECC24FULL + 0xDE112550072C5B40ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6327U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8152U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3671U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 3849U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 23U)) + 11177787645248006236U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 51U)) + 3808340254579817169U) + aNonceWordO;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 828030667598518279U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 16177835921238398371U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 41U)) + 5518747735458708741U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17346319082399995165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6397156921893030937U;
            aOrbiterF = RotL64((aOrbiterF * 11203064569634132929U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15559381654710713582U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 940404446491415088U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16401260971303026881U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8047166032048732645U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4688468645859470491U;
            aOrbiterK = RotL64((aOrbiterK * 14383536431614496369U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 3710878044770337260U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 116343189456629220U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 5637725064169289339U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 883908030159391659U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 18058691521694880482U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 3132200449123497619U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11009U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14384U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11179U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 10755U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 14008824488073394623U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (((aWandererD + RotL64(aCross, 40U)) + RotL64(aCarry, 5U)) + 13317978415866411468U) + aNonceWordI;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 13209180141897453900U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 19U)) + 11870521586865233578U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 11U)) + 8052156380448047385U) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12158131176743680605U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14674467487607719347U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18372548574199176503U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18055496790566231147U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 3838105585041578784U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 1075709247574580091U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2839568255183054418U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11933612922864258179U;
            aOrbiterD = RotL64((aOrbiterD * 7571964469321160347U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6289849094151630580U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2640344350528492271U;
            aOrbiterE = RotL64((aOrbiterE * 16197726750829369365U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16306175266267657791U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3339898380394883600U;
            aOrbiterF = RotL64((aOrbiterF * 7105436590182982373U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterD, 29U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterD);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 43U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21082U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 19773U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21880U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20041U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 4739486756133131180U) + aNonceWordO;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 24U)) + RotL64(aCarry, 57U)) + 16089707555501328184U) + aNonceWordF;
            aOrbiterE = ((aWandererG + RotL64(aCross, 13U)) + 15310047330238536453U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 7901411596386834955U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 3U)) + 4357555491060982163U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15667085602825720102U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8520635334382269253U;
            aOrbiterE = RotL64((aOrbiterE * 7348648918661047791U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1772509779231068315U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 15336170957886025677U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 10996880551392077399U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 8628770833489469980U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15469234024247246228U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8905266995119987947U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10796430900884288328U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10660110397012853289U;
            aOrbiterH = RotL64((aOrbiterH * 9140007610912037461U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11202284258711214794U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17509491802893182994U;
            aOrbiterI = RotL64((aOrbiterI * 9329107599972703671U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 60U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordJ) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30407U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26197U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29561U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 31064U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 13499155707765393469U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 41U)) + 3740324981823726185U;
            aOrbiterA = ((((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 5470765363949735652U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((((aWandererA + RotL64(aScatter, 14U)) + RotL64(aCarry, 41U)) + 3446436171274452326U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 1778929412631211933U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14666308799855220954U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4548410236791175055U;
            aOrbiterA = RotL64((aOrbiterA * 6822908616815218501U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5829739767694190372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14319231414903675748U;
            aOrbiterF = RotL64((aOrbiterF * 4966501102515775601U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 1513851750246111405U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1685620217748986019U;
            aOrbiterE = RotL64((aOrbiterE * 9286548037413609445U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16284162182006054402U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12669312437565969473U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11894755313393001665U;
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + aNonceWordB);
            aWandererF = aWandererF + (((((RotL64(aScatter, 24U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererD = aWandererD + (((((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 19U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 34U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_FootBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x93D906D04EAC4F9FULL + 0xBF98CCE7DBC9B36EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xED164D98C7016A25ULL + 0xFDB8557F422D2506ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF9D6A4CB6E381BABULL + 0xE124D1AB7E2E9676ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA04E3D73157376B7ULL + 0xAA8C7D821995D5D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA5309B132FFE2667ULL + 0xB8D864827553EABFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA571106FBE7F97E5ULL + 0xC64F4F54AA66D681ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9C10621675B350FFULL + 0xE3018DFF4775F023ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB74005E34858F169ULL + 0xEA034D92601B19FDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB26548168FB35899ULL + 0xEB4D94CAE24B62A4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8E5204EBEDC811D7ULL + 0xD659DB9E39103A26ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD49B3207E1AB144BULL + 0x997FCD764C9928DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDCD00BCF3B60C37FULL + 0x8109054D40532E34ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC0ACEFC6C2EDC06BULL + 0x9143F784BF6BF37FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x836B6EFA6E80E50BULL + 0xC4C7F8DD6F4CE448ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9E4AD49759E56089ULL + 0xCA70C17FAEC803D1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC8A65AD619E7ECCFULL + 0x951120A47DF9FE57ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7100U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 654U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6331U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 4896U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 12U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 7075016829833562104U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aScatter, 13U)) + 8783765886115517036U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 35U)) + 2996723892384565829U;
            aOrbiterD = (aWandererI + RotL64(aCross, 3U)) + 9494134707342189476U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 5052642981395679904U) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aCross, 58U)) + 8766787055127962238U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 4467211954388738079U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8030255604633658608U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16962408063455702251U;
            aOrbiterB = RotL64((aOrbiterB * 11171737929747471631U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3768222186567699076U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14930990410207899871U;
            aOrbiterC = RotL64((aOrbiterC * 10930005786146268241U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14179761938395502502U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1879084742719898108U;
            aOrbiterG = RotL64((aOrbiterG * 16783034788172670121U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5535012408925981515U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12792553516710295939U;
            aOrbiterE = RotL64((aOrbiterE * 8577530993755159329U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8979253163346099252U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 5559189896063990740U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 8832485423727331621U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13937564337299044079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2352815657830413941U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12647519563697356479U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10946871249960389549U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6272580371881237173U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 60U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9906U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 8848U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8656U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 9965U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 27U)) + 18087125778766689269U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 13710545066503235196U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 1701939704736254645U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 8064093611384019909U) + aNonceWordF;
            aOrbiterF = (aWandererF + RotL64(aScatter, 52U)) + 16623332751533885431U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 15590129153794910109U) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 7413312683079107383U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4186064478651458810U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5501191643940735954U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14254804649177125269U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11064645242200570835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13825922087298055833U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7529317892716108867U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5944980709887369970U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8181136916070569646U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15442336949157292482U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11580554435240641337U;
            aOrbiterC = RotL64((aOrbiterC * 6654637892858767739U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11240018128174598322U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2027565596050777471U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18048186560314431815U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 16425887196883725233U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16828683527588834095U;
            aOrbiterJ = RotL64((aOrbiterJ * 17746289103235902485U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9923829146479008804U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6669171007279929454U;
            aOrbiterE = RotL64((aOrbiterE * 681823450939955099U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 46U) + RotL64(aOrbiterH, 46U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 19U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24323U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 20690U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23408U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17258U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aIngress, 12U)) + RotL64(aCarry, 51U)) + 13481227414590594621U) + aNonceWordG;
            aOrbiterI = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 17425964381118918026U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 4792004356135956581U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 57U)) + 11926849936000639098U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 43U)) + 990697329347742142U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 9307721505373076588U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 5U)) + 17605732738841908719U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13110764518634187439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17970109897810645911U;
            aOrbiterG = RotL64((aOrbiterG * 10395095143998920213U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10273133817644703654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11239046688920468137U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5197802934333553327U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8355821483275763145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15522151127786049345U;
            aOrbiterH = RotL64((aOrbiterH * 4844278537850520413U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5381663179722418112U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9551368011768104906U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14202470972121732997U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16264476585232221270U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7721417776432288282U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 10267770327791051869U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 339418090653475277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3247926250495935511U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3390560045236418590U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3894024951542543635U;
            aOrbiterA = RotL64((aOrbiterA * 10599637790900418767U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 44U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 27U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32149U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32210U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30818U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 30290U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 48U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 15549114274303128055U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 16466750056388063241U) + aNonceWordP;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 23U)) + 12209449840836787142U) + aNonceWordM;
            aOrbiterF = (aWandererD + RotL64(aIngress, 5U)) + 14551496099734294336U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 6266576428679808622U;
            aOrbiterA = (aWandererC + RotL64(aCross, 41U)) + 16892841575635668152U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 56U)) + 7375966221423362125U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11926105302821753530U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16219253791550461124U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2117550758226173419U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7299056065319248160U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 15234001484933728439U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 8182244796017018911U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6615802589932632120U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5481176858895819247U;
            aOrbiterH = RotL64((aOrbiterH * 3604590158551984877U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17220507586542139380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14137921473739415340U;
            aOrbiterG = RotL64((aOrbiterG * 10634645686035907603U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16981960446540932787U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10897565927079518588U;
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2746889569299593263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4894117146736361379U;
            aOrbiterF = RotL64((aOrbiterF * 2656750612042673191U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18294823016957137777U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 86828501068883383U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11432686669235402365U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 56U)) + aOrbiterB);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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

void TwistExpander_FootBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD5C2FC6D96FD8AC5ULL + 0xCC4FC035BB094626ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEEC6732ADD05074FULL + 0xE6A1271EFBA18AE7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x86E5E0D37791AFD7ULL + 0xFFA1A55D20A3D2F4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE3CF4D80D6BD4517ULL + 0xE6FD3DB09A3A4906ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF3F9EE2C974F6A13ULL + 0x8305C0F53FC77C7BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDBF191FE75AB3F2FULL + 0xC3752995291B2099ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEAF69DE4E0D92679ULL + 0xDFEA117E8E97358FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEC06CC0210E5998DULL + 0xC1AE95B1BFC07B07ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDCD1889F74B64CEDULL + 0xD383D351CC1C2E19ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8F9A239C10B37DE1ULL + 0x85AC34C9F5EDB276ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFB5444FAFAB45831ULL + 0xBCAEB2B74F67B4BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA162B4628A84D8B9ULL + 0xE1DFF193D403342AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x90A03068214DC963ULL + 0xFFED188E8EFABA57ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCCDA18F98E01B4BBULL + 0x83380A46831D3603ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x94857B4842F4188BULL + 0xD445E6524EF22D5CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x87F4DED642B40C3DULL + 0xD5421AD9BFD2CA3EULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6032U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7137U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6363U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6236U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 39U)) + 12849591986267890852U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 60U)) + 8232614804696815750U) + aNonceWordM;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 3U)) + 12141567259210877281U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 2928641981037885644U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 980733350554783938U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 2683985177993350746U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 11U)) + 14532148403815527355U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7736296629433884203U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10428437770166310549U;
            aOrbiterF = RotL64((aOrbiterF * 326634742742373401U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18327174144859461029U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6810436935194432002U;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12606153309690753435U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17123256945895150555U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9057777759026189541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18064460487552100483U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11477276762421684083U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3886501230380184395U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18318375441973295081U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13849305985380030986U;
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10240409420338313641U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18360586077779529086U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 6U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9885U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 11475U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10281U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 12126U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 21U)) + 3255291173184001106U) + aNonceWordG;
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 15308468160116255528U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 12U)) + RotL64(aCarry, 39U)) + 18186972408589866656U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 4439324265978331914U) + aNonceWordA;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 13099263173016322486U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 37U)) + 7041561081767500660U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 5U)) + 6196422612687812971U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7664260932541281413U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17802347823020441056U;
            aOrbiterK = RotL64((aOrbiterK * 2220679459017369255U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4253107484061190446U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13799496534030645312U;
            aOrbiterH = RotL64((aOrbiterH * 9167675060053848207U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14252892847595951926U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5663527578664291422U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11148755959699137661U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17036900929333594592U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2403828181385259549U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17813580350434928194U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13666780980793857831U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5623611126885414523U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7293224381174846969U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 7032561584670788117U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10602620906929686163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18015916257203385982U;
            aOrbiterI = RotL64((aOrbiterI * 10684090189688871993U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 22U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22165U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 17714U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16755U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 21910U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 2571116506511057880U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 11U)) + 13112435411509707292U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 10403251762787357256U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 5U)) + 8461951095541400405U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 37U)) + 9890793478557463815U) + aNonceWordP;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 3030229465991783707U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 7273848154043719247U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10681774862516028276U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7105082755586853104U;
            aOrbiterC = RotL64((aOrbiterC * 12217705329504230357U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6588579345319551129U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14616333550242386092U;
            aOrbiterJ = RotL64((aOrbiterJ * 2934574715879306337U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 15439666290229654921U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3360304356760164799U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14438730801970761889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14515616787452085729U;
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4167853822635132419U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterK = RotL64((aOrbiterK * 887144270884244907U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12391327853728029953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7100871010552394421U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16552349374101955967U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15381697462381887944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6801677551341079401U;
            aOrbiterF = RotL64((aOrbiterF * 13325954438427340703U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 52U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 36U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31924U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31465U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30636U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((aIndex + 29119U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 6654158889644956636U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 9045779659363991870U) + aNonceWordF;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 3888897662136993491U) + aNonceWordG;
            aOrbiterI = (aWandererF + RotL64(aIngress, 58U)) + 6882016842864459345U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 43U)) + 15601891715956172291U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 51U)) + 5176811598629335350U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 21U)) + 12519945150889074325U) + aNonceWordI;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4552583214397603278U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14225482701804864688U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8526052833180466359U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5485298070606280363U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11237713257388094289U;
            aOrbiterD = RotL64((aOrbiterD * 11032429223099413011U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14340345895626142788U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7308578867128951199U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14041860597556520250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11483155566419547004U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4608508534724289325U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 13461385011638899485U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2389196334288832895U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4062682330273866602U;
            aOrbiterI = RotL64((aOrbiterI * 8787682133271101901U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5655656046585592034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7977947821249746880U;
            aOrbiterK = RotL64((aOrbiterK * 10082104644185964787U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 4U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + (((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 27U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 46U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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

void TwistExpander_FootBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF5682E637385CB97ULL + 0xE8FE6952B5C5EF39ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBFBC0D3025873925ULL + 0x8B7FB1714F60FB8AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC7ACF7C860CF86DBULL + 0x82F0689CE5CED50AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xABD16E80E1D76913ULL + 0xD01900834B387C15ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCAD0FF2CD281AE81ULL + 0xA5E17C0124D4C356ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA204CA9D01ED09D5ULL + 0x8F5F97379C529A25ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1BC75F2374F727FULL + 0xB8B63697CFD9172AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9F2CA2ED77D288F5ULL + 0xA5C50A30866E9B60ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE9309C502FE0B4D7ULL + 0xC2D6D42F472C5DE8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB146099ECCD56C0FULL + 0xCEF52D44D45C96C4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA4C4468A2E289A43ULL + 0xCAEDED250AC5F76BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE1F0395500B304D5ULL + 0xC27F23023D1A30F4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF9678486A529C449ULL + 0xF6CC4CA865581799ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC3CB31F63DCBDD83ULL + 0x9E09DD54E7EB5C83ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF5F5FE8B105BB393ULL + 0x8413BBA22D2FC8FFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA82536FF03487D5BULL + 0x90BC2F004F5BFAAEULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 583U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5906U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2569U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 6121U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 21U)) + 9914837590440975587U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 3U)) + 6706125076401958051U) + aNonceWordE;
            aOrbiterH = (aWandererC + RotL64(aCross, 11U)) + 16570817772679258409U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 46U)) + 6843705658115186948U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 39U)) + 16099930446791572351U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 5420550009556030459U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 29U)) + 5729549069420177477U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 15590601126188675834U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 13044027390998620029U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 27U)) + 11068338135659636772U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 14U)) + 6584988841809544332U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8516813219883915404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10647314042912492785U;
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 201691689889605304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15512161798401184003U;
            aOrbiterF = RotL64((aOrbiterF * 11473219183982564709U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3883760518944464145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13861805129175491145U;
            aOrbiterJ = RotL64((aOrbiterJ * 17194438894492581181U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12019138626550801486U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13030350224959652248U;
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2643807255422544248U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4127143302485631794U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5441038881111578487U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14602951930809633069U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4555737199162278494U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12415825635220991865U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6343143902997169834U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10404783711336491985U;
            aOrbiterD = RotL64((aOrbiterD * 6235474458879439079U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7406959231434835393U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6684368109277850196U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8760360417572331159U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4835889355927954728U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7917682889852676712U;
            aOrbiterI = RotL64((aOrbiterI * 9045350756570117327U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10268055422944417055U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5563744562922937643U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12442484191329795173U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17244672945880141679U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9914837590440975587U;
            aOrbiterG = RotL64((aOrbiterG * 12269340309792850489U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterB, 34U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 46U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13798U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13291U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11538U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11571U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 28U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 13442819395490639310U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 53U)) + 8187292523194120936U) + aNonceWordI;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 3U)) + 11469697159823131388U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 19U)) + 13414083692375929653U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 51U)) + 11404010733687907517U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 13U)) + 6783212827186218247U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 41U)) + 8561131439340372614U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 43U)) + 6252609642004429113U) + aNonceWordH;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 35U)) + 12804867444200448952U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 5U)) + 2739648749603690781U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 14808861217017399752U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17588866502571268888U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterK = RotL64((aOrbiterK * 7688252946143263869U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15493099088132862949U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5175647411532429582U;
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14279707376173642767U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 6826363572161275158U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 5263708315440161809U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13267185753040999992U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9980987858092888720U;
            aOrbiterD = RotL64((aOrbiterD * 13210290848800728635U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3582972937645514549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10140409019562890804U;
            aOrbiterI = RotL64((aOrbiterI * 6944490201647678479U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6160444117287330557U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16344602960561293113U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2319964919335633293U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3497141036108337171U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12739932748793144857U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12820180915064791197U;
            aOrbiterG = RotL64((aOrbiterG * 5843849637411948699U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17572075652083359962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10684041099654982701U;
            aOrbiterA = RotL64((aOrbiterA * 7121293375756263771U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10739534650885677354U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9731206787727954809U;
            aOrbiterJ = RotL64((aOrbiterJ * 3730875775588585547U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9655432616347117764U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13442819395490639310U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 3650859301708619119U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterG, 38U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 21U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 12U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22490U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17511U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17724U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23488U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 17711946802293254150U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 60U)) + 16652362590489569378U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 6972810344198183097U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 39U)) + 13117100889782940546U) + aNonceWordC;
            aOrbiterI = (aWandererC + RotL64(aScatter, 53U)) + 13199305696782626591U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 29U)) + 992156184392760945U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 13791265442074543880U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 35U)) + 17057087245252294859U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 13444195995883541046U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 6U)) + 6723678233676059420U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 7913379431208430475U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4481887195529300665U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11892724101424384078U;
            aOrbiterK = RotL64((aOrbiterK * 3468639499716604111U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7700902083270424194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1888001433557140271U;
            aOrbiterJ = RotL64((aOrbiterJ * 8975562955027025349U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14996753906788986929U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 939004845422123765U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2507090308972292313U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11922230289291941807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15681187459741147199U;
            aOrbiterI = RotL64((aOrbiterI * 10124947739653819101U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9119043713532718155U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8327697433992362166U;
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13630755116592440359U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 771252613886022889U;
            aOrbiterA = RotL64((aOrbiterA * 2958918915223536519U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8524239721467527770U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17732617735422435572U;
            aOrbiterD = RotL64((aOrbiterD * 13992947983987668631U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5265753270696005619U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14456128349522985053U;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12909993509014176457U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10113568710432654194U;
            aOrbiterH = RotL64((aOrbiterH * 6857806395910432831U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14818978163348513071U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17843349910031998923U;
            aOrbiterE = RotL64((aOrbiterE * 13608449524810499593U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12589077818524017161U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17711946802293254150U;
            aOrbiterG = RotL64((aOrbiterG * 9454569713107675231U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 56U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 24U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26885U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27796U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29839U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 30897U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 6024062041314952357U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 43U)) + 18340757093658015585U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 54U)) + 11911120493880346751U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 39U)) + 17428074353884654439U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 41U)) + 12790849760814795936U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 12633397052172117800U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 11946150433665237945U;
            aOrbiterH = (aWandererH + RotL64(aCross, 23U)) + 16842157900909419285U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 14186235783224155962U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 13284904542579767591U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 56U)) + 11609181965078844357U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9628562297095374984U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7850281529011259759U;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 257458718073794527U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10693404545773519306U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 14821443722828498323U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3430519236533871460U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6183054506953198055U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 6121082743789970911U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2905610989884221654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterC = RotL64((aOrbiterC * 7770678426310856745U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16870142883133769663U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1403692060594816451U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16904169913507057108U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4773518591580333357U;
            aOrbiterF = RotL64((aOrbiterF * 5306070307776061267U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6528141733853494275U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11254806909313951442U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 6316669786405548827U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6857506858448143407U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2855763534355983644U;
            aOrbiterK = RotL64((aOrbiterK * 16881334940165182415U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12328391751024624740U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16475072086109949522U;
            aOrbiterE = RotL64((aOrbiterE * 15218626930666825883U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15505670341076785424U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6972128419331939330U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12206069109180246067U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7151546362283646210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6024062041314952357U;
            aOrbiterJ = RotL64((aOrbiterJ * 10243806128059850493U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 36U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterK, 56U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 37U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK + ((((RotL64(aCross, 6U) + RotL64(aOrbiterG, 60U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_FootBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC2673FC56B2A201DULL + 0xFE74FCB1A39F92B6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD10D46559E8F4C37ULL + 0x9C38583DF22147C8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC25D990481893C69ULL + 0xF1B7703FCDFE88CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCD1FE9CAF8C7C201ULL + 0x9E2126B173937EDAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC34B4E898D2D916BULL + 0xC16F1BE40E915F4AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x95B8B496E73D72EBULL + 0x82079FEC6C311FC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x95F4CF1C2340F097ULL + 0xFCACBCF1A27156F5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAF25FBE9BCB414DDULL + 0xBC51CE164D91C1A6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD6007A62AC8CD89DULL + 0x8B4CBED746245717ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD2B9166EF19F0DB3ULL + 0xC8C385027201246DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC60CFB1A9860EDB9ULL + 0xC11063A8458E5D07ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5DDBDB0395B1905ULL + 0xD142B5430A003D6CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA11F203844166037ULL + 0x9DF45B2B890B83E5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA5F64B92BD657951ULL + 0xC5658725D8194EFBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFB203BC813041C9BULL + 0xBA49BC39682AD2EAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBDFEA3AC51F7EEA3ULL + 0xAAD9F8AAF2DC2277ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1846U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3681U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1078U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4137U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 26U)) + 7075016829833562104U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 8783765886115517036U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 21U)) + 2996723892384565829U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 53U)) + 9494134707342189476U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 5052642981395679904U;
            aOrbiterF = ((((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 21U)) + 8766787055127962238U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 4467211954388738079U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 39U)) + 8030255604633658608U) + aNonceWordI;
            aOrbiterG = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 16962408063455702251U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3768222186567699076U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14930990410207899871U;
            aOrbiterA = RotL64((aOrbiterA * 10930005786146268241U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14179761938395502502U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1879084742719898108U;
            aOrbiterF = RotL64((aOrbiterF * 16783034788172670121U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5535012408925981515U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12792553516710295939U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8577530993755159329U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8979253163346099252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5559189896063990740U;
            aOrbiterG = RotL64((aOrbiterG * 8832485423727331621U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13937564337299044079U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12647519563697356479U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10946871249960389549U;
            aOrbiterH = RotL64((aOrbiterH * 6272580371881237173U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13376798695582123147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10958115913599631271U;
            aOrbiterC = RotL64((aOrbiterC * 18233981473003345217U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4283914227806672773U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 910842005516235816U;
            aOrbiterB = RotL64((aOrbiterB * 6722229871617873429U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1509644316619370324U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 165987596716078174U;
            aOrbiterJ = RotL64((aOrbiterJ * 13600064054240185123U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 40U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 46U) + RotL64(aOrbiterA, 18U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 24U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7018U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 8345U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6010U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10037U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 52U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 36U)) + 3339283916456813609U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 3U)) + 11339086426180649584U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 27U)) + 16819191669329316585U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + 8361916937762630725U) + aNonceWordE;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 11U)) + 18031328374429899857U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 18261756894092897276U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 4250319792907645666U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 1492411503643460886U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 48U)) + 17369549067879344180U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7301713524358676722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterD = RotL64((aOrbiterD * 7473297294949338265U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14086975808140927408U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10390516547834639800U;
            aOrbiterB = RotL64((aOrbiterB * 11441293212275890819U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9209505304067579944U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3522631966146762306U;
            aOrbiterE = RotL64((aOrbiterE * 3441982898533162599U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8811497120829041188U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14707301680850257294U;
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10080595991787801029U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1981637172055758689U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16463077485583119324U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2876782050665869121U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8383837717361569465U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2788511294985017326U;
            aOrbiterG = RotL64((aOrbiterG * 2809163242875130677U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3529607472855930041U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 22U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 30U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 6U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15305U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 14273U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15741U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11819U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 52U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 15549114274303128055U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 39U)) + 16466750056388063241U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 12209449840836787142U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + 14551496099734294336U) + aNonceWordO;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 39U)) + 6266576428679808622U) + aNonceWordD;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 16892841575635668152U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 43U)) + 7375966221423362125U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 29U)) + 11926105302821753530U) + aNonceWordI;
            aOrbiterK = (aWandererC + RotL64(aIngress, 48U)) + 16219253791550461124U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7299056065319248160U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15234001484933728439U;
            aOrbiterC = RotL64((aOrbiterC * 8182244796017018911U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6615802589932632120U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5481176858895819247U;
            aOrbiterA = RotL64((aOrbiterA * 3604590158551984877U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17220507586542139380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14137921473739415340U;
            aOrbiterG = RotL64((aOrbiterG * 10634645686035907603U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16981960446540932787U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10897565927079518588U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2746889569299593263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4894117146736361379U;
            aOrbiterE = RotL64((aOrbiterE * 2656750612042673191U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18294823016957137777U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 86828501068883383U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11432686669235402365U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6322053762209547826U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6754524552483363820U;
            aOrbiterB = RotL64((aOrbiterB * 1746163087826694641U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7306452650619361017U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12717201204443785828U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6121251603905574991U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10422327053543898585U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14786413282036348183U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8713024293107068275U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 20U) + RotL64(aOrbiterB, 10U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA + ((RotL64(aCross, 56U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterI, 48U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20287U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17091U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19236U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 17568U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 18U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 37U)) + 14249093584376402677U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 51U)) + 8756965951816492264U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 47U)) + 11221139480258176330U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 60U)) + 17218894445564194851U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 8064642692524949490U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 5822093203710704646U) + aNonceWordM;
            aOrbiterF = (aWandererG + RotL64(aScatter, 43U)) + 3217799620158102238U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 2613757677892120843U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 4U)) + 13647481499551657237U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3545714196663685016U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9735422670576621521U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7276207208162697249U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3911046580637583767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9315984027042049203U;
            aOrbiterK = RotL64((aOrbiterK * 12568550776487242469U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8926367674641729058U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11035347490524961446U;
            aOrbiterF = RotL64((aOrbiterF * 10948288997163592463U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10748158733051120339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2467801787989056455U;
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9244415080474351390U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8517784887959492079U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17022899813765884147U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8409307332803038455U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11043806021873232950U;
            aOrbiterD = RotL64((aOrbiterD * 8294888329708842989U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17512395828450251457U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16849067939795823992U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9361991804481514337U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17541946638063238056U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11430501673960586718U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15074409630605450091U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 78307505705383302U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4834528975263832983U;
            aOrbiterI = RotL64((aOrbiterI * 17245673681686752861U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 42U)) + aOrbiterI) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterI, 36U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23960U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23932U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22570U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22921U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 5U)) + 12262991801139086177U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 51U)) + 7963038771924890197U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 29U)) + 15540520327933568896U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 39U)) + 8745565892055020722U) + aNonceWordL;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 11U)) + 16619329199683755286U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 10865705026433867260U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 2743368697984518059U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 19U)) + 5556006271515473135U;
            aOrbiterE = (aWandererD + RotL64(aCross, 34U)) + 5355833281353498588U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8313616108963479829U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16657121016801866434U;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16532226425013000833U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5800465874932467232U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17882948163883121328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15029375310296563175U;
            aOrbiterB = RotL64((aOrbiterB * 17021415832288477713U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10170682648007918739U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11829089574189398773U;
            aOrbiterE = RotL64((aOrbiterE * 15755874363488568849U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1746524867389196322U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10217423427886742775U;
            aOrbiterJ = RotL64((aOrbiterJ * 9166162099575333519U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1338457710729082656U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1319981417675542556U;
            aOrbiterD = RotL64((aOrbiterD * 9518448254565489715U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3985281993069194761U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 7281264481139915593U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 13498446162967276739U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17394503335338855566U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1430703546991948227U;
            aOrbiterK = RotL64((aOrbiterK * 1623206122475721175U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 472559435062214929U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8065899137826178995U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13287499768933229539U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31396U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29962U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32319U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28613U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + 898812731947995389U) + aNonceWordJ;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 8677347622525527167U;
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 770321564027567654U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 40U)) + RotL64(aCarry, 21U)) + 11020474858081526395U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 3U)) + 17289793580414993470U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 10111912559295118444U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 23U)) + 8083622125544542011U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 35U)) + 7149858558922988240U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 48U)) + 5919683821379905699U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6860902846079238714U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15083517836867542075U;
            aOrbiterH = RotL64((aOrbiterH * 4686657139237578325U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14852868368708376381U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9860233289028878323U;
            aOrbiterC = RotL64((aOrbiterC * 13418143547952204667U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 772406119079116272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8478568022896691911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17199331557841535430U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5468950152869656599U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17138249294921502391U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16236812863923234668U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2925542836624164807U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16941524155859123682U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11240343728857342866U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 7281012444214294659U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15163914964139858328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6673576554415729652U;
            aOrbiterK = RotL64((aOrbiterK * 1558880328574736975U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5399050402101642989U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11806006719060024615U;
            aOrbiterB = RotL64((aOrbiterB * 15782156615926092159U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterK, 48U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
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

void TwistExpander_FootBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD20FACEF442BDA4DULL + 0x9314872593EFFCF1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB2F8E6E679790EC5ULL + 0x87DFB415404E936FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA292A375EDFE2741ULL + 0x971AC9AFAB1C92FFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x989E3F11CF5AFDFFULL + 0xB6467238D364EC3DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD1562325DC1B2A91ULL + 0xC42D92C4E868024CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8D72BC7B552D2B2DULL + 0xFC57CFCD9F53F236ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF54C374F8D4253C1ULL + 0xF46242EEEBF760BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x99896755A1D62609ULL + 0xC577749004E5984AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEBF32CCBD6A1996DULL + 0xE54D8D8F059B57E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9ACC625D1E77BE59ULL + 0xF523121D9365F493ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9FB2E93E6FBF02D7ULL + 0xF6E5A1A5D2A98972ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB71E256DAD38D33ULL + 0xF63BF98A40740FD8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9B6080F15174C7D1ULL + 0xAF939F05514DCE4DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9E285C4FA33220EDULL + 0xC57AB89203FD73AFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE823D29EDC0CF26BULL + 0xA88E28D1AD7B057FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA235DA60DBBA2971ULL + 0xDAD97B0DB88B3251ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3191U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2333U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 106U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2267U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + 4384716820085860551U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 9715780315942116888U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 37U)) + 15963520052789178632U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 14346700690686392938U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 6005518012489966643U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 2506732930310252119U) + aNonceWordL;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 60U)) + 16782163084851775826U) + aNonceWordD;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 823673076571076303U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1634084509064077736U;
            aOrbiterE = RotL64((aOrbiterE * 1128407326773234517U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1288134975466877686U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2998220403162908444U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4321412662318298283U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 220430672180734911U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 10223923547068528867U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11696469696177647608U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 79691451831797107U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8971444023498649419U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7148919880477390009U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5624403902454498793U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9468064161002030997U;
            aOrbiterH = RotL64((aOrbiterH * 8243560528100864595U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4619361544913629805U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12682446273369750704U;
            aOrbiterK = RotL64((aOrbiterK * 10879074713156075641U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 22U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 54U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + aNonceWordI) + aPhaseAWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9573U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((aIndex + 9277U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7454U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6283U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 38U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 7790166497945719700U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 5U)) + 7136208896846119188U;
            aOrbiterK = ((((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 29U)) + 12123156943355100886U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 51U)) + 5095546037880875199U) + aNonceWordA;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 57U)) + 17642705393916765992U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 9918479837334416990U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 19U)) + 4890009823843176466U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17652590786213674124U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 870002527644696135U;
            aOrbiterK = RotL64((aOrbiterK * 915408393979165539U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12545429703552643682U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5310272867406182581U;
            aOrbiterA = RotL64((aOrbiterA * 10420003334833925011U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3264719049050179440U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1967241238180278937U;
            aOrbiterH = RotL64((aOrbiterH * 13004319774269457957U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 773883832927040736U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12766817190261232485U;
            aOrbiterI = RotL64((aOrbiterI * 7448864556802318431U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 260069382395598265U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15462103891287350123U;
            aOrbiterJ = RotL64((aOrbiterJ * 5029268763635635753U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4072032867513289827U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17153061419083897076U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11934532169271718913U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6207264270332656966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18048064697837314947U;
            aOrbiterF = RotL64((aOrbiterF * 13632594619404208489U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 48U)) + aOrbiterJ) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12329U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11576U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13935U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12101U)) & W_KEY1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 47U)) + 14624277139785904404U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + 6966977309498165611U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererE + RotL64(aCross, 39U)) + 205536824352530761U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 16629575265808255692U) + aNonceWordA;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 596881340147972746U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 57U)) + 11944412799107412650U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 13U)) + 4615021315668210206U) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8497630055977606216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11131601107309336885U;
            aOrbiterG = RotL64((aOrbiterG * 18028349768453554935U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 5935883479805510099U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15629346719765798174U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8535523790685945275U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5279128339113651273U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16778365912440331821U;
            aOrbiterD = RotL64((aOrbiterD * 705421028266789241U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16003052937645491524U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6723226158737614764U;
            aOrbiterF = RotL64((aOrbiterF * 16690657664909260573U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9785784358981219543U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10055457337292292710U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17919129940751761111U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11779163108592974175U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1177999477942202687U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13475069421684114643U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9190694445141492214U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15605342360346353457U;
            aOrbiterI = RotL64((aOrbiterI * 14547769706392595647U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 20U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16774U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 20273U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17492U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20546U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 40U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 43U)) + 6771552164800695068U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 12131763371571322040U) + aPhaseAOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 3326182381395522013U) + aNonceWordF;
            aOrbiterE = ((((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 12288775097697156383U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 5195948373449796741U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 11U)) + 14404044002250137144U;
            aOrbiterB = (aWandererE + RotL64(aCross, 35U)) + 11142382920035825426U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2967149520256475485U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1470907369577818097U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9231668148004163910U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13078929163913892386U;
            aOrbiterK = RotL64((aOrbiterK * 7509829068700523627U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9485274692075657877U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12216951187543631673U;
            aOrbiterD = RotL64((aOrbiterD * 6571066246507310805U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6933334652581744234U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17260276102423580920U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7796879893790990605U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 387767848169714392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8597538259308082638U;
            aOrbiterF = RotL64((aOrbiterF * 4888054690557707241U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7996708724489146033U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15357384191688149939U;
            aOrbiterE = RotL64((aOrbiterE * 9827691726832491373U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17739222908739454637U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1614322333281471170U;
            aOrbiterB = RotL64((aOrbiterB * 7063116837752240891U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 18U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + aPhaseAWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aNonceWordB) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26994U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27187U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26155U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23818U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 26U)) + 15383045568644941552U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aScatter, 19U)) + 17452811657750910067U) + aPhaseAOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 15660117718455155603U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 10396441207743665753U) + aNonceWordA;
            aOrbiterD = (aWandererK + RotL64(aScatter, 57U)) + 3708971058200841442U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 7000673057768598750U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 51U)) + 9886354469011131596U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16018065329058043467U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5024756166109352320U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11660932185479046483U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6587818720728886652U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3652672354944162319U;
            aOrbiterK = RotL64((aOrbiterK * 10807121230791716109U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6307315649915348048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16405347331742979258U;
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5427299664054601957U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4983381733483185898U;
            aOrbiterA = RotL64((aOrbiterA * 14646556236306407673U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10182995521328377487U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8694282877540593550U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 14614602561910403893U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6966742100601433005U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9920952446921247521U;
            aOrbiterF = RotL64((aOrbiterF * 1879821050131820933U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aNonceWordP) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + aOrbiterD) + RotL64(aOrbiterB, 56U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31748U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31860U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30978U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 32564U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 51U)) + 12535417189990029950U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 44U)) + RotL64(aCarry, 11U)) + 6204401443676390273U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 869613505613154672U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 15053590879563855802U) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aCross, 29U)) + 13338989605204591428U) + aNonceWordH;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 57U)) + 18306470022403825392U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererF + RotL64(aScatter, 5U)) + 1150696349434090218U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13549541786420596437U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14302878430259588461U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 16813606782134305513U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4660437084477165225U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1653628537860912069U;
            aOrbiterC = RotL64((aOrbiterC * 2624835201155303123U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5594199757006711631U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11008472193138708891U;
            aOrbiterJ = RotL64((aOrbiterJ * 13645764762027798301U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3668516817279364310U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 128159531749679984U;
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6378674346113979108U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11438762460659123362U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2733309638158283953U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 10624263004446482910U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterB = RotL64((aOrbiterB * 11468326687628079347U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8466639576503293921U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5828694979857951504U;
            aOrbiterE = RotL64((aOrbiterE * 7835487310289634515U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterD, 22U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aNonceWordG) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_FootBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA0D3DE99B5E49C4BULL + 0xA9A24851DDE37097ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8C601B69C325BD7DULL + 0xBB759EF222FA8693ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x98826D0ABEDDE9ABULL + 0xC87E7BDF5BAA790BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x86A64276DE50D0EDULL + 0xC822A6D7C4837CE8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC7EFF49A81A7871FULL + 0xDA582A39F0E4D4B6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEA611DFB40782D5BULL + 0xD4AD1D8F96EACC7DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9BDA5ED3F8E31BB7ULL + 0xE0E56B22066E2E3EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDF329B740B9996F1ULL + 0xAA66C7B0A6C246B0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x82A9059D8EEE74F3ULL + 0xE84CAC32B4A06E35ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB1A1EA1F6EDC59AFULL + 0xACF3C9627E2E8B82ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBF9EFEBC188F95F9ULL + 0xD12E523858EA4516ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE2CD7A084D1610F5ULL + 0xD0ACA304E976F02FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE0A03854B38C9625ULL + 0xD8917131911B453EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE40ED98EB4687A1BULL + 0xCA15027C967A2C76ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE10C64D83D4E5191ULL + 0xD9066139A79DAA59ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF7113A09F5DCE943ULL + 0xF1E1548A5382D753ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1080U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5244U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5142U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 2717U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 13915875634607599122U) + aPhaseBOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 1695770381382411673U) + aNonceWordE;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 3709105579778295511U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 42U)) + 7673376335333251804U;
            aOrbiterB = (aWandererK + RotL64(aCross, 13U)) + 8814147709738503518U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13451412605350381172U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6447870234069609538U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4016219229618539433U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13419487997946496825U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5478309847615220345U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12953043149543448765U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3635184969215610049U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12527903812035294828U;
            aOrbiterG = RotL64((aOrbiterG * 12540800512035534967U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1684685110885338814U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12860354576326835090U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12743745087733307255U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9081823570147481835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14369321778210049109U;
            aOrbiterB = RotL64((aOrbiterB * 17865953349448767035U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 40U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + aNonceWordP) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 12U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7945U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8585U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6713U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 6540U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 1457104756581596530U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 6127240317844622874U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 51U)) + 16492290056044189421U) + aNonceWordB;
            aOrbiterK = ((((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 23U)) + 10963676850938416468U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + 4872917367399752405U) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15218882377875616148U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 5934166612122118251U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 10365045124180379919U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14215280930872003003U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11428034799044600979U;
            aOrbiterI = RotL64((aOrbiterI * 12162528943733976177U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5453003654321728726U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14273775120265649389U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5139018128323795309U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 328723770018440271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13032190719588211088U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13363368478932798315U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2386881543033598494U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1649501123340887116U;
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 41U)) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 60U)) + aOrbiterI) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 38U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14226U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13723U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14346U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11119U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 1866656689936219099U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 12U)) + 2312314528139448289U) + aNonceWordC;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 3554037526469185237U) + aPhaseBOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 405707755060974111U) + aNonceWordF;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 27U)) + 1862976326004007697U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12992483065443288263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3793854946371595197U;
            aOrbiterH = RotL64((aOrbiterH * 1819119223110966487U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 4244007978867369382U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10280867500312580308U;
            aOrbiterJ = RotL64((aOrbiterJ * 13729899124177931289U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 472563452959164242U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12041770406895816553U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17811798500132002631U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6118634015704900486U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13637107920449233307U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17712028184714868053U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16673735670669318830U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8602681273646630496U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 6995213887710749241U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 52U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 20U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17566U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16674U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16778U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 20223U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 28U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 11480359716598965890U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 15431182525482873419U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 23U)) + 11360504974812776707U) + aPhaseBOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 9292576416573382769U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + 1549257414531028975U) + aNonceWordO;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5347769463033129317U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17019199177478377234U;
            aOrbiterA = RotL64((aOrbiterA * 4336112198640602307U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16558106007323125094U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3976182233825939422U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4392162052317572289U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2889047161195954395U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2241831345026962605U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5757458560979927857U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12850802412140579294U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13541744735436450160U;
            aOrbiterD = RotL64((aOrbiterD * 906089290000537439U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2085863085516538212U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2969034221711544086U;
            aOrbiterK = RotL64((aOrbiterK * 7768528124408400403U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 56U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23362U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22496U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24472U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 24788U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 13333509828310369865U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 7645352517103840797U) + aNonceWordE;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 5310766306660062655U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 5U)) + 5165635069832352932U) + aNonceWordB;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + 15684141764734281849U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3327963374225061738U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8625811794878848871U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16327750494894125333U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7598657468430485291U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2881171216276746485U;
            aOrbiterI = RotL64((aOrbiterI * 3331350584102843605U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10237691227222918101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6419254255884834497U;
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4238455444646479956U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14936613353493061492U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 3544216916806292273U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15324699725208372627U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordH);
            aWandererH = aWandererH + (((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordF) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + aPhaseBWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 20U)) + RotL64(aCarry, 13U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27979U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 31186U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28482U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30592U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + 9220392006207660113U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 23U)) + 11305018553489132882U) + aNonceWordL;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 11U)) + 5860373868073513684U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 12319586170883987589U) + aNonceWordN;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 14072333614354649021U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9332158529453194608U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3860569321145958686U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 907977527866467591U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8119005668901240093U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13918259792880333239U;
            aOrbiterD = RotL64((aOrbiterD * 5441062406822088853U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 6938856216758228704U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3960905839118710604U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16203746868670689793U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6043879193734253929U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15691425268831319195U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7189195135654636271U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14912209933584715274U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16180183395910618923U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 3942858974766467849U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterK, 22U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
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

void TwistExpander_FootBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA5314F2BF39EC1D1ULL + 0xCDF4D8E9153DAB38ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAA514807754048B5ULL + 0xED5E673A75292585ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC5DE28AF3CC3E09FULL + 0xBD5C6642D40F8878ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xACD64BEDA3F2C3A9ULL + 0xDCD90EA015BCBD9FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAE14791B9B3045C7ULL + 0x9D70B95BA9D2D738ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBBC1A84C9B780927ULL + 0x9C0A54D16022ECCDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x99C8C0D306B0C743ULL + 0xBDAEACB2FA825EB7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6C8D62EC5E42219ULL + 0xA7F72B984F314212ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD1395DF174EC19D1ULL + 0xB95EF956D6B4E9E7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAEA61E1A08EC2AB3ULL + 0xB85E2346DB3E39E8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE561305D31C9EE5DULL + 0xFD6F686AE8E43A7CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8719AD318CC33CE7ULL + 0xC47C2DFB3A13A070ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB1A9B1684EC03AFBULL + 0xEAECE50293EDE9F8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF8F07016A4AAF823ULL + 0xD9E93438F0100B3DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAE61E64C9530C0CBULL + 0xF12ECDA310317077ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAF338484C891EC93ULL + 0xFFD2F78E08A724C7ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1953U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 8038U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5605U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 669U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 44U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 57U)) + 3612110001869385068U) + aPhaseCOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 16340824141280225936U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 15222338965130765231U;
            aOrbiterG = (aWandererF + RotL64(aCross, 13U)) + 6649270508107155041U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 52U)) + 768217258655426384U) + aNonceWordC;
            aOrbiterE = (aWandererJ + RotL64(aCross, 19U)) + 4481855259658861851U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 18318041934562434016U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 39U)) + 4212457153804401807U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererB + RotL64(aCross, 34U)) + 16143621095636987628U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2095664232866642086U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4339527736737366572U;
            aOrbiterA = RotL64((aOrbiterA * 17503569508822244125U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13679353177869884790U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11582168502846418236U;
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10451330452898542191U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12951448817640617841U;
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15389161934419370747U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4754886272708253014U;
            aOrbiterI = RotL64((aOrbiterI * 16638243718191281597U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11746389873929280688U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12042680172517298768U;
            aOrbiterJ = RotL64((aOrbiterJ * 3814780289755857543U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2648103752465009244U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 451594673632597973U;
            aOrbiterG = RotL64((aOrbiterG * 8496763663271072425U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5696534794094099710U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14609435045257077395U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14658408563237468407U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11599395126850950133U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12699598504604446664U;
            aOrbiterH = RotL64((aOrbiterH * 14313494063098111823U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9398465148537154745U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12139736860648011256U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15257503229375247987U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 20U)) + aOrbiterJ) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aPhaseCWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 58U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 26U) + RotL64(aOrbiterB, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10167U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13921U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8204U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14590U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 17668251151213543491U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 58U)) + 16101602509895104517U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 19U)) + 9083915270773304935U;
            aOrbiterD = (aWandererA + RotL64(aCross, 51U)) + 12810720730318214811U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 39U)) + 18113428002071925621U) + aPhaseCOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 35U)) + 1582208899354109878U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 43U)) + 4180688104819188154U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 8954598189262820611U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 51U)) + 15360094153175355879U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8383954114668216260U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15626783326234049197U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15058420415480073793U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10609978564404958066U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17656516608997517984U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4590620354119899777U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 760077259110786536U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3597338735888033063U;
            aOrbiterF = RotL64((aOrbiterF * 6548831472863517621U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4431777844935985157U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10710423172154671296U;
            aOrbiterH = RotL64((aOrbiterH * 16267496318491473315U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10240882795242085185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7826053487019825891U;
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9418883403715727353U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11507423614799075545U;
            aOrbiterA = RotL64((aOrbiterA * 16189463984557044693U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11545217316421066655U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 617921402135485341U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 8182920764965471653U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14456933220749921009U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7990243583564535387U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 5994900368027985469U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14023633125757654751U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11319146808574958827U;
            aOrbiterI = RotL64((aOrbiterI * 13676159969338309307U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 18U)) + aOrbiterH) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterD, 22U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18147U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 22747U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20514U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20165U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 52U)) + 3105313968748067810U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 35U)) + 9977249451119627064U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 17941392803495349366U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 4279533326705471133U) + aNonceWordI;
            aOrbiterH = (aWandererD + RotL64(aIngress, 41U)) + 13983828966811580039U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 57U)) + 3983490984234810378U) + aPhaseCOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 308786542215259956U;
            aOrbiterA = (aWandererC + RotL64(aCross, 26U)) + 8443607695364427037U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 5U)) + 14939626441464340668U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9350693577306121110U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1717071159396961752U;
            aOrbiterF = RotL64((aOrbiterF * 11062480662625054525U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15911765265202100610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14898546272333182767U;
            aOrbiterE = RotL64((aOrbiterE * 2674900543810733067U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3560903518513465868U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5367062725726860234U;
            aOrbiterJ = RotL64((aOrbiterJ * 8521908836601319553U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15233321480618877327U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9288449812290126074U;
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5504840529511585676U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6825598386801620046U;
            aOrbiterH = RotL64((aOrbiterH * 11666542445846250077U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6433024450721339470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 97934156644929458U;
            aOrbiterI = RotL64((aOrbiterI * 8630530773006923215U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3260053604798744515U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16539416623243059076U;
            aOrbiterK = RotL64((aOrbiterK * 12199577351166064503U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9814290051339038920U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13280156404507444041U;
            aOrbiterA = RotL64((aOrbiterA * 15269010043398910061U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11853942590993546833U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13207869904312989977U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15503461937625795969U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 60U)) + aOrbiterC) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 10U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26648U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 30898U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30921U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((aIndex + 30227U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 3U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 3U)) + 15910560457440369082U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererC + RotL64(aScatter, 41U)) + 17953072986407436888U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 15446940721193538669U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 24U)) + 3020785262774422009U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aCross, 19U)) + 7001288645424994404U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 13385250665458462689U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 4841895644623005949U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 51U)) + 13053476783239482065U) + aNonceWordF;
            aOrbiterK = (aWandererI + RotL64(aCross, 28U)) + 641996979335975244U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16211238020928688299U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12715448751323279480U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2116880429675303291U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17784406727699995290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16626339815786580778U;
            aOrbiterG = RotL64((aOrbiterG * 13940754474750138041U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9035070625716345139U) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6085848172494001945U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1177103851507561053U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2281901691017816407U;
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9040984343694325070U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13334258224023902365U;
            aOrbiterD = RotL64((aOrbiterD * 4782523727707164869U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1079824790138592518U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14024082692012948652U;
            aOrbiterE = RotL64((aOrbiterE * 3219489374333737903U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2966776524421278970U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5510281854029308547U;
            aOrbiterH = RotL64((aOrbiterH * 9275402927591867297U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7126632329316720048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1476827035602733472U;
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6470212302133184965U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4172257438373147415U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4449314239630366533U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 18U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + aNonceWordJ) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterC, 44U));
            aWandererF = aWandererF + ((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_FootBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCEAF2566D68BC48DULL + 0xAF6ABC4A64CAC507ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8FB50BFD89217BB5ULL + 0xD4A96742B422E1F8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB10421B0768E73A7ULL + 0xD8C7C23A32FCF512ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9D9BF52AD7D235D7ULL + 0xF9CE3E2DB31704A4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCDD325F777ED37CBULL + 0xEADAECF4C70289A0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE0A3012EB963267FULL + 0xD65F048884ED75B8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA0AEF0C4B394DD3ULL + 0xC451FA58B7F4234BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB7708EE8999CF715ULL + 0x8DFE9C027C186C25ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCE73E797E4D5CDFBULL + 0xB72911787173168EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x97A3AAB14F76F533ULL + 0xE4761AE4754347DEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE0D95C8CAD7D5037ULL + 0xCCDA9ECDFBCF0A33ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFCB16526C7697D29ULL + 0x86C38536A8F99E09ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA8A39F1B6539D87FULL + 0xD955943F26BE2361ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x88D2E73423E5614BULL + 0xA40564E4E80769B1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB896361AA07F981DULL + 0x93B54616047F009AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE7091723C816A649ULL + 0xA08A06D6E4E602AEULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4286U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 2540U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4035U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3335U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 6U)) + 17936518874386450467U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 13722737841589910344U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 11774969167948715796U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 37U)) + 3640101505680493777U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 39U)) + 1369495382725650822U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 11U)) + 11827310354654653345U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 57U)) + 186037671377175394U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 11428829344234627340U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 52U)) + 2275016369870029068U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 13U)) + 15471646673734798328U) + aNonceWordC;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 19U)) + 12172082573115640145U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6626736341348283154U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12220614992483863623U;
            aOrbiterH = RotL64((aOrbiterH * 8137086205714097487U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13157102324253760215U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4143587482368093601U;
            aOrbiterJ = RotL64((aOrbiterJ * 5060677690991506895U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11007575246013796426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11721585930088637162U;
            aOrbiterE = RotL64((aOrbiterE * 15009627907125738519U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5720789204450196217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3094696226821431648U;
            aOrbiterI = RotL64((aOrbiterI * 4412033981712165541U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14675830108100986773U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9444071495289719645U;
            aOrbiterA = RotL64((aOrbiterA * 10983136361953366557U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5106753847015199956U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7585421898593510010U;
            aOrbiterK = RotL64((aOrbiterK * 140996914192351011U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11746948407655524690U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16336323220286344483U;
            aOrbiterC = RotL64((aOrbiterC * 6590417628835864497U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8030445186765781136U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 276034088015165891U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7626025612710225099U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8116955322602209153U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5704503350608834450U;
            aOrbiterF = RotL64((aOrbiterF * 7049558959583832449U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8063875087087055875U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1111816778196345760U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13820440198677609571U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7702895879089714461U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17936518874386450467U;
            aOrbiterG = RotL64((aOrbiterG * 12767279443267850009U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 12U)) + aOrbiterI) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aNonceWordD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 18U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7152U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 8205U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9357U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6573U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 40U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 15813325389431304548U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 47U)) + 2223874171125403602U) + aNonceWordM;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 5510483568496824130U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 34U)) + 15474152493495661876U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 37U)) + 16846339705130829195U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 29U)) + 1289670576865739669U) + aPhaseDOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 21U)) + 18017354919647006944U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 23U)) + 8539685539928984921U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 3333721400836704048U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 26U)) + 2261560416623815491U;
            aOrbiterI = (aWandererB + RotL64(aCross, 19U)) + 4377786131746816567U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 18047393176583722719U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8184724021940434631U;
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10469895939183324807U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14543391765109879223U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5757225781746158178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3539000495894022869U;
            aOrbiterJ = RotL64((aOrbiterJ * 1032298408884695925U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11288971092707065923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2761384065186568294U;
            aOrbiterD = RotL64((aOrbiterD * 3323838837427471051U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7120580145300417101U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6977246291769372866U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 15170353875184253779U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17625434527765525937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3299714663631376190U;
            aOrbiterG = RotL64((aOrbiterG * 6532628892760776767U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10331889953489885250U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8550932256881727932U;
            aOrbiterB = RotL64((aOrbiterB * 13085531621192583719U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11151195711186126257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2552002192824926483U;
            aOrbiterF = RotL64((aOrbiterF * 9754056316698523849U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8038115194286715268U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16594489591573505305U;
            aOrbiterE = RotL64((aOrbiterE * 1241387574663818247U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13476964484361081681U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2136330439951908303U;
            aOrbiterH = RotL64((aOrbiterH * 12728359054660550527U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 231990686776499700U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15813325389431304548U;
            aOrbiterI = RotL64((aOrbiterI * 9155088985405261637U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterB, 26U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterG, 28U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14658U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15498U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14244U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 13601U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 47U)) + 898812731947995389U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 24U)) + 8677347622525527167U) + aNonceWordJ;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 27U)) + 770321564027567654U) + aNonceWordK;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 11020474858081526395U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 17289793580414993470U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 10111912559295118444U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 12U)) + RotL64(aCarry, 43U)) + 8083622125544542011U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 5U)) + 7149858558922988240U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 53U)) + 5919683821379905699U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 37U)) + 6860902846079238714U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 21U)) + 15083517836867542075U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14852868368708376381U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9860233289028878323U;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 772406119079116272U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8478568022896691911U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4027604850785607101U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17199331557841535430U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7515957656979776361U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5468950152869656599U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17138249294921502391U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16236812863923234668U;
            aOrbiterI = RotL64((aOrbiterI * 2925542836624164807U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16941524155859123682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11240343728857342866U;
            aOrbiterK = RotL64((aOrbiterK * 7281012444214294659U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15163914964139858328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6673576554415729652U;
            aOrbiterH = RotL64((aOrbiterH * 1558880328574736975U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5399050402101642989U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11806006719060024615U;
            aOrbiterB = RotL64((aOrbiterB * 15782156615926092159U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9812148913932011655U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4737919734590584193U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2739737604370936959U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3415477403346468057U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5922725868927615919U;
            aOrbiterJ = RotL64((aOrbiterJ * 12390148483052777871U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17435294951520465659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 898812731947995389U;
            aOrbiterC = RotL64((aOrbiterC * 17248379279729365007U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 6U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 24U));
            aWandererC = aWandererC + (((((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 29U)) + aNonceWordI) + aPhaseDWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 26U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20085U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20825U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21385U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20954U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 23U)) + 826930775230515406U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 21U)) + 5137814617363250861U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 14761561947426681616U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 21U)) + 12773023438753662590U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 51U)) + 7331345852207096322U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 5U)) + 3899381212671247460U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 57U)) + 10072004147620068599U;
            aOrbiterB = (aWandererB + RotL64(aCross, 41U)) + 3424585039401897560U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 8246760141625966321U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 48U)) + 3655992860610853290U) + aNonceWordK;
            aOrbiterD = (aWandererE + RotL64(aIngress, 43U)) + 11154618022505863898U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15629361991059709973U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10842068502278489664U;
            aOrbiterJ = RotL64((aOrbiterJ * 17223002513104960799U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5571312349016336686U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 589313823745748879U;
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13633457935771935260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12684602052812183096U;
            aOrbiterG = RotL64((aOrbiterG * 4689206269919806711U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5711307583717354204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7181854170553728211U;
            aOrbiterF = RotL64((aOrbiterF * 9835601115561325911U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 1884620014396115821U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1471516373272364262U;
            aOrbiterB = RotL64((aOrbiterB * 5126319375714848029U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 742739371092077733U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8075893317715227838U;
            aOrbiterC = RotL64((aOrbiterC * 11208274111743259795U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8179547722249281263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15305282712174742323U;
            aOrbiterI = RotL64((aOrbiterI * 7951986906055462929U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1430543231751281079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14585341768267283387U;
            aOrbiterD = RotL64((aOrbiterD * 313213844964269133U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8123889986027932297U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2081696191347150910U;
            aOrbiterH = RotL64((aOrbiterH * 4869653441012615053U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10166788886199265936U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15927074835525735601U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6747650218540675523U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6997764816848988590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 826930775230515406U;
            aOrbiterA = RotL64((aOrbiterA * 9943232461538279601U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 48U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterI, 10U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + aNonceWordB) + aPhaseDWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterI, 30U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25804U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22459U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24860U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23684U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 56U)) + RotL64(aCarry, 13U)) + 7790166497945719700U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 29U)) + 7136208896846119188U) + aNonceWordG;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 53U)) + 12123156943355100886U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 5095546037880875199U) + aNonceWordM;
            aOrbiterK = (aWandererH + RotL64(aIngress, 19U)) + 17642705393916765992U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 4U)) + 9918479837334416990U) + aNonceWordP;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 4890009823843176466U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 21U)) + 17652590786213674124U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 39U)) + 870002527644696135U;
            aOrbiterI = (aWandererB + RotL64(aCross, 47U)) + 12545429703552643682U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 43U)) + 5310272867406182581U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3264719049050179440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1967241238180278937U;
            aOrbiterA = RotL64((aOrbiterA * 13004319774269457957U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 773883832927040736U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12766817190261232485U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7448864556802318431U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 260069382395598265U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15462103891287350123U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5029268763635635753U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4072032867513289827U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17153061419083897076U;
            aOrbiterI = RotL64((aOrbiterI * 11934532169271718913U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6207264270332656966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18048064697837314947U;
            aOrbiterF = RotL64((aOrbiterF * 13632594619404208489U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14484617445340272026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16160443600497652026U;
            aOrbiterD = RotL64((aOrbiterD * 1988599349457831597U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5873314228291583482U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16418290052752166515U;
            aOrbiterH = RotL64((aOrbiterH * 18270363452003213317U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9158414409987627714U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8205937960146492168U;
            aOrbiterB = RotL64((aOrbiterB * 14008398661393344261U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16386126219854809263U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12418021156683187869U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 13897930566207284517U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5427232681451476584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18237670074497382745U;
            aOrbiterC = RotL64((aOrbiterC * 15528665160297906195U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8330262458028468513U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7790166497945719700U;
            aOrbiterK = RotL64((aOrbiterK * 6001280767763971107U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 52U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 12U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31178U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 31447U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31058U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29800U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((((aWandererG + RotL64(aIngress, 40U)) + RotL64(aCarry, 35U)) + 5576732410244514238U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 2833808925935929629U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 5U)) + 3670188682914544792U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aCross, 35U)) + 15759072378887814995U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 13934007231137439994U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 30U)) + 11022225696007690512U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 37U)) + 16989177104453635790U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 3U)) + 9256930045263527091U) + aNonceWordK;
            aOrbiterF = (aWandererA + RotL64(aScatter, 57U)) + 17788596104417068290U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 27U)) + 17044369456673337625U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 1310908395523250343U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12067065689034065422U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15130844248737512262U;
            aOrbiterC = RotL64((aOrbiterC * 9409499577465934107U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14532689204495587494U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8198147292120244178U;
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5485494458627163347U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10830008207150307611U;
            aOrbiterD = RotL64((aOrbiterD * 6526039534042499457U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17770065502486618029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6397859353395335459U;
            aOrbiterH = RotL64((aOrbiterH * 14286997752368893825U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5128700697381508319U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7103394110057060499U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5053680689949149633U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16024401282261796979U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12818445221897253410U;
            aOrbiterF = RotL64((aOrbiterF * 11450004517784155405U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13386978409145916350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16740821954556699503U;
            aOrbiterI = RotL64((aOrbiterI * 5376430209628515105U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 313978038530994953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1355733685461795345U;
            aOrbiterA = RotL64((aOrbiterA * 15955927322082619735U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12590581077253956064U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2298195367575496005U;
            aOrbiterB = RotL64((aOrbiterB * 17512801361187006363U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11847450675712272468U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5914296379577670282U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14574813500616811367U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16901317262621287065U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5576732410244514238U;
            aOrbiterG = RotL64((aOrbiterG * 4514943876091531567U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 46U)) + aOrbiterD) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 43U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterA, 56U));
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aNonceWordP) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_FootBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC655C85A84A05EC5ULL + 0x911B61FF33745BF6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEDCA01698BDAC8FBULL + 0xFCB60EEBAD1C2637ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE72C191BDE54EFFFULL + 0x996C092CCFF4A2CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDCBAC9A637012DEBULL + 0xF37A5DB271B019FDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD053637EB4FCEDB9ULL + 0xBAB7B7F58506FB7AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEDBE7BDC479E2C35ULL + 0xBEA3CC6237D58A7AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCDE5B4C038DC68EFULL + 0xC7D48C970FC15B59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC870B679CA0DF9D1ULL + 0x999926C31457F82FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBAEAE40A52D83C6BULL + 0xAE5B07412CD54926ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB1797D3B89E15D49ULL + 0xD9F76A4BD79FDF4FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD869F65AC6B03A33ULL + 0xE3232D1F5E324FBFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9C9B970D77EE6797ULL + 0x8154CC59ABEA020DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC8AC2AE2D183337BULL + 0x8A0C469123F84A92ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xECE1D7DFFF39BE97ULL + 0xCFA94EBE320E2064ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDF0B04612FBEC029ULL + 0x946E4591FA46A563ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x90C165AE1D9365E5ULL + 0xC82D38959CEB04C0ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 183U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5235U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2459U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 4558U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 58U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + 9751314027302668907U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 21U)) + 12175450995523107056U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 43U)) + 17519694958730119552U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 37U)) + 9093525527925682263U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 3713831321786810138U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 46U)) + RotL64(aCarry, 23U)) + 10108355209191835040U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 12956307447311314768U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 53U)) + 1904298513945877359U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 41U)) + 4658049993308574460U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 23U)) + 9826333658248851902U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 10U)) + 12058666914724365134U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2516574707110528099U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13335308331049750235U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5880227828760598587U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8230749255538495304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16536559486797811486U;
            aOrbiterJ = RotL64((aOrbiterJ * 7097036838156464969U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12387639130570188998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8459259798142872020U;
            aOrbiterA = RotL64((aOrbiterA * 8001346480955847013U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16083784052002800300U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1957284290736468379U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7349538179311335863U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16395170077006105258U;
            aOrbiterF = RotL64((aOrbiterF * 4230485452156662763U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3317652065873784068U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5517155804799120700U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9789270651974719183U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 5568525912112200094U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9334250662962319598U;
            aOrbiterG = RotL64((aOrbiterG * 5034887614541768961U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5641394627075994165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13524971148931512745U;
            aOrbiterE = RotL64((aOrbiterE * 3699457147759854357U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15124425790244392471U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7896294947517723306U;
            aOrbiterD = RotL64((aOrbiterD * 7526632360108129915U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15241686066829586263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12099799118961857495U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10456171163074630861U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17529688916595727188U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9751314027302668907U;
            aOrbiterH = RotL64((aOrbiterH * 521888849578281715U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aNonceWordI) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterJ, 52U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterD, 26U)) + aOrbiterA) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8070U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6105U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10766U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 6738U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 14U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 39U)) + 13481227414590594621U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 50U)) + 17425964381118918026U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + 4792004356135956581U) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 19U)) + 990697329347742142U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 9307721505373076588U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 17605732738841908719U) + aNonceWordH;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 13110764518634187439U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 3U)) + 17970109897810645911U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 13U)) + 10273133817644703654U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 35U)) + 11239046688920468137U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8355821483275763145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15522151127786049345U;
            aOrbiterD = RotL64((aOrbiterD * 4844278537850520413U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5381663179722418112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9551368011768104906U;
            aOrbiterC = RotL64((aOrbiterC * 14202470972121732997U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16264476585232221270U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7721417776432288282U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 339418090653475277U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3247926250495935511U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16824669543765729097U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3390560045236418590U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3894024951542543635U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10599637790900418767U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3878539166189668154U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5617705593218220843U;
            aOrbiterE = RotL64((aOrbiterE * 82771190372750823U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12320861089148474544U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterG = RotL64((aOrbiterG * 13758322022902008313U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18119213517612562775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1413193144229486646U;
            aOrbiterI = RotL64((aOrbiterI * 14562375280658115687U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14810150213456844196U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8468712395797520201U;
            aOrbiterF = RotL64((aOrbiterF * 8167911669632436949U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13501570100536254566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15409772061478100850U;
            aOrbiterB = RotL64((aOrbiterB * 955182899606655851U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8621805947309982779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13481227414590594621U;
            aOrbiterK = RotL64((aOrbiterK * 9591362493722704105U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 58U)) + aOrbiterH) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14125U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 15092U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12934U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 11350U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 44U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 41U)) + 18087125778766689269U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 13710545066503235196U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 35U)) + 1701939704736254645U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 8064093611384019909U) + aNonceWordE;
            aOrbiterI = (aWandererB + RotL64(aScatter, 44U)) + 16623332751533885431U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 29U)) + 15590129153794910109U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 7413312683079107383U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 37U)) + 4186064478651458810U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 5501191643940735954U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 39U)) + 11064645242200570835U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 12U)) + 13825922087298055833U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5944980709887369970U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8181136916070569646U;
            aOrbiterJ = RotL64((aOrbiterJ * 395183021205661827U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15442336949157292482U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11580554435240641337U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 6654637892858767739U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11240018128174598322U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16425887196883725233U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16828683527588834095U;
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9923829146479008804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6669171007279929454U;
            aOrbiterK = RotL64((aOrbiterK * 681823450939955099U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3902430046523165149U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6739998149289590041U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2675037435528416821U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16014401255534234075U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14741857638680634564U;
            aOrbiterB = RotL64((aOrbiterB * 8723611021403369393U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5064807861673260054U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 968747317273200299U;
            aOrbiterA = RotL64((aOrbiterA * 14122304002722582329U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5282686212362051427U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6902253563196129760U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7682808024658992049U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4995580401402368332U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14949762584793646470U;
            aOrbiterG = RotL64((aOrbiterG * 3539183342072953803U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2378815735788107402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18087125778766689269U;
            aOrbiterH = RotL64((aOrbiterH * 16799380528404446281U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 34U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 4U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterA, 20U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16718U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19202U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21035U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17420U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 19U)) + 5510690816044082200U) + aNonceWordA;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + 15967820875033940530U) + aNonceWordM;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + 539348720848176221U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 41U)) + 15779318183635560817U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 14511058534424187469U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 36U)) + 5811130556873428391U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 5U)) + 1085928476499444025U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 6973335316600768130U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 10747243745475009744U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 43U)) + 1072260008981349754U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 54U)) + RotL64(aCarry, 53U)) + 2018772405352495753U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1092091597048996547U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 15103140149542167197U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 621856991658027989U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13194619321108681542U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16749188603268621850U;
            aOrbiterC = RotL64((aOrbiterC * 9575408950550922039U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7427959503086895166U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9895804051379551393U;
            aOrbiterG = RotL64((aOrbiterG * 2701997336201570715U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4526020800679774259U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4484850928870048176U;
            aOrbiterF = RotL64((aOrbiterF * 17556987520625677313U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1837404844299040155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15213208978489570694U;
            aOrbiterJ = RotL64((aOrbiterJ * 7062740584650274133U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9615231781751396800U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15872192167825648096U;
            aOrbiterB = RotL64((aOrbiterB * 2900526493682580729U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12530672039655918903U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10617836782870315804U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 9716778004909794973U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 550750725406860977U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3498554352021622907U;
            aOrbiterI = RotL64((aOrbiterI * 9846933294851238495U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4059346317776216057U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14161853870874499023U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8601560894939097781U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4088411647683253905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9321241420172776158U;
            aOrbiterK = RotL64((aOrbiterK * 4167888281125330225U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8527337525861632945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5510690816044082200U;
            aOrbiterD = RotL64((aOrbiterD * 12464836001483233379U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 30U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 12U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26405U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 24743U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25841U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 24652U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 60U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aCross, 51U)) + 12632404972795375757U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 53U)) + 5351879979055988456U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 21U)) + 3597737727467443413U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 3U)) + 2830846754917852318U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 17311925960294518018U) + aNonceWordC;
            aOrbiterG = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 2083584640523695383U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 10U)) + 15049343611387010158U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 5U)) + 6443050378205811147U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 35U)) + 6021965178697344070U;
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 5080289878758029976U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 576927745306972983U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4728489691382690859U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11220539885798595450U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11091438724966718214U;
            aOrbiterG = RotL64((aOrbiterG * 8225347114759391961U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17184210490020062419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2150997767099116408U;
            aOrbiterB = RotL64((aOrbiterB * 8058553821648892499U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7021953562676903717U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17159676348343312834U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13877284519668483549U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10367891770525239784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11922478487264201233U;
            aOrbiterH = RotL64((aOrbiterH * 9195137452661956029U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17815162358981720634U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9582631251085100284U;
            aOrbiterE = RotL64((aOrbiterE * 11838992994130850483U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 872593750259572264U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17832330100262167302U;
            aOrbiterK = RotL64((aOrbiterK * 1114416841510028467U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16601139856969287418U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14931287111691324985U;
            aOrbiterD = RotL64((aOrbiterD * 16757174577841001179U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11413072442039115924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15253605470589905889U;
            aOrbiterI = RotL64((aOrbiterI * 10832817442285245673U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3653487723581514107U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14891378240114471865U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 1386594204573386051U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15659724464711852035U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12632404972795375757U;
            aOrbiterJ = RotL64((aOrbiterJ * 2407347385127296647U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 20U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31948U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 28795U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28036U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30769U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 54U)) + 5721224134332887360U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 11U)) + 6892749729775049095U) + aNonceWordL;
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 3884839462099556836U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 4365431706830216193U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 13U)) + 15501528746571578773U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 4505911326320650606U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 1865129050927879580U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + 2011737665969640369U) + aNonceWordM;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 611672935827062688U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 3U)) + 663547038310431047U;
            aOrbiterG = (aWandererI + RotL64(aCross, 52U)) + 5468932264754299556U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17920294117231191705U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 486058453837528110U;
            aOrbiterC = RotL64((aOrbiterC * 8851102552244026737U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2789178451938129313U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 420772587981211184U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 17402987842294006667U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16196774774442181825U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16264169656793713547U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 6900221986041638783U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10207659833859860796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8593749091183323678U;
            aOrbiterE = RotL64((aOrbiterE * 10696776033512404927U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7224922076047787384U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15366267474865172373U;
            aOrbiterA = RotL64((aOrbiterA * 10134187073321814217U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4235342515820080294U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5239480080426950612U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12077621553561927079U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10891752830598395582U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7797358829694471108U;
            aOrbiterH = RotL64((aOrbiterH * 7621206775460997431U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3755715857903753416U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3172069024987421726U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16048490837178650865U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8623351347363497301U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5895306804546658158U;
            aOrbiterF = RotL64((aOrbiterF * 1568542219600635919U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5026075347235960113U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3706258841140585921U;
            aOrbiterD = RotL64((aOrbiterD * 4911715089264902109U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6753904207571971217U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5721224134332887360U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4531182106796534951U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 22U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 20U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_FootBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCBFA01491AA28877ULL + 0x8AD14ACA358D1B30ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA23095B4BFC9EFE9ULL + 0xDA9B98A48E6C618AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCCACB6BEDD2075D9ULL + 0x8E5C18A13AD82CDFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE379B96865F3DE5BULL + 0xA36C3E276328A0C6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF03443E89697AE89ULL + 0x805311B54DC08844ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDD4C1F770C4FA3C5ULL + 0x9E4E18293ECA583CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC9D2005C9BE92481ULL + 0xD8D466121299B284ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA0A3F56E43208C77ULL + 0xB1FBA52A0AD57C24ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFD7C2197D69041E3ULL + 0xF1569B92B6A6128BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8CE6B7E69BDE1B79ULL + 0xF5DFC4F01485D278ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC4A89CE3E13D843BULL + 0xABD383A7E6AFD550ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFCF7C9F9F23FDBBDULL + 0xF80E6C020220B20FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF1D66C20CDF8A6EBULL + 0x8F5A6ACDAE0793C6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x80935C530719D90BULL + 0x94EBF95D63FE0B25ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB31498F6B9CC498FULL + 0xD04D300FF01C29ACULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCB71A15F1878ECC3ULL + 0x8FE0A6CE8A092649ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3574U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 2234U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1281U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 1808U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 4U)) + 1393781663398437180U) + aNonceWordM;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 37U)) + 17414594746688585273U) + aNonceWordG;
            aOrbiterD = (aWandererC + RotL64(aIngress, 27U)) + 2823888497053071250U;
            aOrbiterA = (aWandererK + RotL64(aCross, 21U)) + 17032631958617884859U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 57U)) + 15222697630461125019U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 15737414920751551780U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 13U)) + 1357196111055783001U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 5315122321649251691U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 7893744655508595974U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 39U)) + 16721939414324611738U) + aNonceWordP;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 3444375866323610848U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1825716513674511632U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15582066843912467318U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 12765146555943757373U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15673590949193923915U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13887365046280406413U;
            aOrbiterB = RotL64((aOrbiterB * 3169061375011420121U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12730414371734709356U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4819112390640821927U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8782547948627685451U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3089925954422937464U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7180179304678622530U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16118051565147747413U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17030269962085008657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6675917351883004046U;
            aOrbiterC = RotL64((aOrbiterC * 14134335325316949687U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12572022803491077491U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2801421744689267375U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 315045745990934023U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4335148696780313055U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12526298573395110141U;
            aOrbiterK = RotL64((aOrbiterK * 11276803410698178607U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6984239833558496091U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12195433952105336808U;
            aOrbiterH = RotL64((aOrbiterH * 8642600547427664495U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6392683095502982341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18047201953488013325U;
            aOrbiterI = RotL64((aOrbiterI * 16151795290455603489U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15433458942878109208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1700365768743794306U;
            aOrbiterE = RotL64((aOrbiterE * 16151638348775286903U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10951473638533187729U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1393781663398437180U;
            aOrbiterJ = RotL64((aOrbiterJ * 2661447713922232789U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 48U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererB, 12U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6786U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10728U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5602U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7198U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 7722279280863371124U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 11U)) + 11584220561732385598U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 7834679350105534657U;
            aOrbiterH = (aWandererD + RotL64(aCross, 41U)) + 11347994382444180879U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 24U)) + 9449903188047063431U) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 6516243976652795170U;
            aOrbiterG = ((((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 8420815253991184777U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 47U)) + 9081386852515170937U;
            aOrbiterD = (aWandererE + RotL64(aCross, 27U)) + 14375955191735286867U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 19U)) + 880757589768436072U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 60U)) + 3349856625725164229U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7826309957607577207U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8057435761214313635U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4718430712767038607U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9565237500443303103U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterB = RotL64((aOrbiterB * 8457633439171452397U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3276844534476430842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6828644383891274120U;
            aOrbiterJ = RotL64((aOrbiterJ * 979580351653410157U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2815676923011504251U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5030251870850928417U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7075653570570819253U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13464083008377887034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8994560761846897590U;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8398813387154468736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8136429428340910892U;
            aOrbiterA = RotL64((aOrbiterA * 3348811490733577295U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 418587250696862341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4111667833838312094U;
            aOrbiterH = RotL64((aOrbiterH * 860949442143849147U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6075478294190926371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2208124955874142264U;
            aOrbiterF = RotL64((aOrbiterF * 15741988616251072075U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4726538724576443010U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6524078248882840425U;
            aOrbiterK = RotL64((aOrbiterK * 9784875566721689069U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14521003220464811621U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16916247868211621303U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 1911638054294853877U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18207293125461843123U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7722279280863371124U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14303108475807941791U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 54U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 6U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aCross, 28U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + aNonceWordG) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11685U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 15812U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16298U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14182U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 19U)) + (RotL64(aCarry, 38U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 16200278595895089008U;
            aOrbiterB = (aWandererD + RotL64(aCross, 3U)) + 1029614154810465897U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 54U)) + 7129562468705441295U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 27U)) + 14388903902433951274U;
            aOrbiterH = ((((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 1013568949315967455U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 3128823373497815651U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 14525694606889470589U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 39U)) + 14443983602196782887U;
            aOrbiterD = (aWandererI + RotL64(aCross, 57U)) + 12244220415328641190U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 23U)) + 10477159225338766614U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 2842870123078131566U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8621138818955849917U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5038396344400303181U;
            aOrbiterK = RotL64((aOrbiterK * 14636756322207385447U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2768613802894372496U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2027754864051410015U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2461322540050569287U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2848088309172056399U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9079797279596336139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15424866642305110811U;
            aOrbiterH = RotL64((aOrbiterH * 12912331089970158845U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13751764050290602740U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7694557131324740282U;
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3508673897305667669U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3600868397311393233U;
            aOrbiterJ = RotL64((aOrbiterJ * 5165032044164139165U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1222655844979128996U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2257342337168905875U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 6198995971182272119U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6290990717563682725U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15308494772443447109U;
            aOrbiterF = RotL64((aOrbiterF * 1925593111157842325U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4065385272074155855U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17216369169581934516U;
            aOrbiterG = RotL64((aOrbiterG * 16172589962950781777U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15683161334290612079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4197626901960576264U;
            aOrbiterD = RotL64((aOrbiterD * 2822547214684481747U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4400047838649306704U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16200278595895089008U;
            aOrbiterI = RotL64((aOrbiterI * 6603195071605635697U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 36U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 34U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 56U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 30U));
            aWandererA = aWandererA + (((RotL64(aScatter, 50U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17148U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19200U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16415U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 17545U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 56U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + 5480870806135400132U) + aNonceWordD;
            aOrbiterG = (aWandererI + RotL64(aCross, 18U)) + 8034874599430768743U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 4006919843736863767U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + 2988069748674633718U) + aNonceWordL;
            aOrbiterI = (aWandererA + RotL64(aScatter, 43U)) + 12347295651973135786U;
            aOrbiterB = (aWandererD + RotL64(aCross, 37U)) + 14152683894431568192U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 15765143815254196598U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 29U)) + 10473067082331244233U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 1089466925383677249U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 14U)) + 13215039929873682230U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + 3957997712247961479U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10023907397941685546U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14593012591254614353U;
            aOrbiterK = RotL64((aOrbiterK * 17111300092082154687U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13353797968154036726U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9259966668512102858U;
            aOrbiterI = RotL64((aOrbiterI * 8326732574268308221U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10757861831070349321U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10530223113483866178U;
            aOrbiterB = RotL64((aOrbiterB * 11269177745265396583U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7554320926405521865U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6978052067277966996U;
            aOrbiterA = RotL64((aOrbiterA * 18020134738536217801U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1053695861967171420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15980734683539854451U;
            aOrbiterC = RotL64((aOrbiterC * 3208466640010555357U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17041258393808061556U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12846551858751995530U;
            aOrbiterF = RotL64((aOrbiterF * 9303891433380993639U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14617434286683320666U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3999309956180741302U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15037707937050015205U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13452627760403094126U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2633241575260427158U;
            aOrbiterE = RotL64((aOrbiterE * 2638570213290747581U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15575035993965639421U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 7829837426112185905U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 17059814556114938275U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12565466096663867876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4845209979900289818U;
            aOrbiterG = RotL64((aOrbiterG * 14990494169374347835U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13472490162287247012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5480870806135400132U;
            aOrbiterD = RotL64((aOrbiterD * 9150331893094034245U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 60U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterH, 42U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25923U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22066U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23501U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 25524U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aCross, 29U)) + 5131645209694953015U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 40U)) + 12070391048835379854U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 27U)) + 2604295836242338724U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 13U)) + 14042039029284001596U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 8914654543854559327U) + aNonceWordH;
            aOrbiterF = ((aWandererG + RotL64(aCross, 46U)) + RotL64(aCarry, 13U)) + 2185619407969359869U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 5187406295103352574U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 51U)) + 8022832481290871217U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 53U)) + 8783061916740573472U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + 10711028365596196301U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 5U)) + 13387065038269133571U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11187001318931801582U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14191473173276034019U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2491253922434756431U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16207761776716426435U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9677408414452078760U;
            aOrbiterF = RotL64((aOrbiterF * 5487303383095129949U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17812460332794370649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7736423148554132028U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15588733747232852555U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17293203944059014763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13487243633338010243U;
            aOrbiterI = RotL64((aOrbiterI * 9468688858740539095U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15979293016815060755U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17645215484691359547U;
            aOrbiterB = RotL64((aOrbiterB * 1449450767288733995U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11635961468586927692U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 10530136578329059784U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8785021493374398437U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4900370530116992731U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15952900504821599445U;
            aOrbiterA = RotL64((aOrbiterA * 5413316082800365261U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9938000151832814778U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14170277411106520726U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5058343552974910737U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14091010427448547620U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13658560822164111421U;
            aOrbiterK = RotL64((aOrbiterK * 9523184040517290629U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13954269172267844623U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3921811946419945868U;
            aOrbiterH = RotL64((aOrbiterH * 6839440867046147039U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14296483810577739898U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5131645209694953015U;
            aOrbiterE = RotL64((aOrbiterE * 10190969526209064367U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 38U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 18U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 52U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27365U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 31497U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30839U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 27496U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 11700815697312060726U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 11808423452327465441U;
            aOrbiterA = (aWandererC + RotL64(aCross, 44U)) + 8670503858631730886U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 13U)) + 2400061067991988544U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + 16163118178366229686U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 37U)) + 3280178595904941068U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + 3298683600817047727U) + aNonceWordL;
            aOrbiterK = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 16321624053445183574U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 35U)) + 6730229877611375225U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 53U)) + 10162830636713641322U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 15646771327759599256U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14841751262270544102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9545541117228834895U;
            aOrbiterA = RotL64((aOrbiterA * 11529769874752969377U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14676615635857599982U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1231768638470558855U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1945905595345404833U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterJ = RotL64((aOrbiterJ * 4577864352425476233U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1970292335806697198U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12309719390375013297U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5352135521358954576U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15465675376193501658U;
            aOrbiterK = RotL64((aOrbiterK * 16385761112921041387U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2842123638916600369U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3544764287036748668U;
            aOrbiterH = RotL64((aOrbiterH * 3360772950777850115U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6038297172906492282U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10249342332287140970U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16701083081566042277U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1662076777040529446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1949705569959740274U;
            aOrbiterG = RotL64((aOrbiterG * 11340691546658994529U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13934194245417822360U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5720408806425535958U;
            aOrbiterC = RotL64((aOrbiterC * 15237561081637415383U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2209251362417210658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4917447930929521699U;
            aOrbiterI = RotL64((aOrbiterI * 17489570156694692569U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14817115766683623486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11700815697312060726U;
            aOrbiterF = RotL64((aOrbiterF * 16982411053956669181U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterG) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordH);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD3E679464EEEA735ULL + 0x9A2F0245D666F400ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE23539048181EBD3ULL + 0xDEDC9B566952AC8DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x800A71C57F761785ULL + 0xAF35C1A34D0C3A9CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8B619EEA1D9C65EFULL + 0x85AEA68C27527360ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE76D8BBEC8089DD9ULL + 0xFF8D3868BB7BC3AAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA760C6FFBCB86A17ULL + 0xBD683674507FDE9DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCB02F41A90835593ULL + 0xD76BE72D6BED38BAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA102B3A89D2B2897ULL + 0xDBE9B38F6EAD6C64ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8D52C76E3C170F17ULL + 0xF97C0BC17FA66BE7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8953CA98CB955AD9ULL + 0xB354946AFB0FD537ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA4F6255F27AEF3DBULL + 0xC218DC808F9DE1EDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD3D14B0B844FBD03ULL + 0x8D254A9C931B8465ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDEC7B5858538B1A1ULL + 0xE3FADC37FD98C576ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC17E417AB2A537E1ULL + 0xC1264E3774DF5076ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAFB6500849CB8457ULL + 0xF73D7D539C443938ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD85436C70B578AEFULL + 0xEEC079B77C522023ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4319U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 1778U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 296U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1845U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 27U)) + 6771552164800695068U) + aNonceWordF;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 39U)) + 12131763371571322040U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 3326182381395522013U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 6U)) + 12288775097697156383U;
            aOrbiterI = (aWandererI + RotL64(aCross, 23U)) + 5195948373449796741U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 14404044002250137144U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 13U)) + 11142382920035825426U) + aNonceWordC;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 2967149520256475485U;
            aOrbiterF = (aWandererF + RotL64(aCross, 53U)) + 1470907369577818097U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 29U)) + 9231668148004163910U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 48U)) + 13078929163913892386U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9485274692075657877U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12216951187543631673U;
            aOrbiterH = RotL64((aOrbiterH * 6571066246507310805U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6933334652581744234U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17260276102423580920U;
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 387767848169714392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8597538259308082638U;
            aOrbiterE = RotL64((aOrbiterE * 4888054690557707241U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7996708724489146033U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15357384191688149939U;
            aOrbiterJ = RotL64((aOrbiterJ * 9827691726832491373U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17739222908739454637U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1614322333281471170U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7063116837752240891U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4531604274893197209U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3453280714992341288U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8390029711127907805U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 116623650872661533U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6565636510115095988U;
            aOrbiterG = RotL64((aOrbiterG * 9691897067492501177U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10303258439817808058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10917642773040237611U;
            aOrbiterK = RotL64((aOrbiterK * 10232856828372963363U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2087058228468680821U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3691125545393861889U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1768745056298937903U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9240209357066002219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7645250700232422804U;
            aOrbiterB = RotL64((aOrbiterB * 6762116797395687607U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9859862257084218280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6771552164800695068U;
            aOrbiterA = RotL64((aOrbiterA * 11063630807191661109U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 52U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 44U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 44U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 10U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5995U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 5930U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9599U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 7606U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 36U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 8402620908307642697U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 60U)) + 11347672014525086047U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 2816462912503401876U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 13U)) + 6940159795470696093U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 37U)) + 9134692490095883851U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 4999455497008026526U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 5992451460350651332U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 35U)) + 3417087346651371924U) + aNonceWordF;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 53U)) + 3612773820086198270U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 463398077083428570U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 48U)) + 11249391303705089012U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17027535139825739501U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 568131384979596481U;
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4793712537158004047U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10415170179135963622U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13729564030210361415U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2391473979460065630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4240058362680064261U;
            aOrbiterK = RotL64((aOrbiterK * 12375884373396400889U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9963957011090031698U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3325305624067445525U;
            aOrbiterJ = RotL64((aOrbiterJ * 3128542681461806309U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2094945647665114693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10703615640774042674U;
            aOrbiterH = RotL64((aOrbiterH * 12641986098450423751U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3768738815518590289U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15021301790376706827U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14445850924223550339U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10571246886181608316U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 5130325144599151793U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 3185251943547657467U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8617523421720966373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16574597770835250074U;
            aOrbiterG = RotL64((aOrbiterG * 1759209403428937799U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17474733286551120355U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17914672092861237776U;
            aOrbiterF = RotL64((aOrbiterF * 13657291990878792267U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12856557371623447773U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1636296609747335898U;
            aOrbiterC = RotL64((aOrbiterC * 9286345529656087313U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12588848560509679821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8402620908307642697U;
            aOrbiterA = RotL64((aOrbiterA * 2269772223506258147U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterJ, 4U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 30U)) + aOrbiterA) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15234U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12849U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14345U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14233U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 51U) ^ RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 29U)) + 7790166497945719700U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 7136208896846119188U) + aNonceWordF;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 21U)) + 12123156943355100886U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 60U)) + 5095546037880875199U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 51U)) + 17642705393916765992U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 41U)) + 9918479837334416990U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + 4890009823843176466U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 53U)) + 17652590786213674124U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 21U)) + 870002527644696135U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 12545429703552643682U;
            aOrbiterF = (aWandererD + RotL64(aCross, 35U)) + 5310272867406182581U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3264719049050179440U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1967241238180278937U;
            aOrbiterG = RotL64((aOrbiterG * 13004319774269457957U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 773883832927040736U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12766817190261232485U;
            aOrbiterB = RotL64((aOrbiterB * 7448864556802318431U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 260069382395598265U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15462103891287350123U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 5029268763635635753U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4072032867513289827U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17153061419083897076U;
            aOrbiterE = RotL64((aOrbiterE * 11934532169271718913U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6207264270332656966U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18048064697837314947U;
            aOrbiterI = RotL64((aOrbiterI * 13632594619404208489U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14484617445340272026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16160443600497652026U;
            aOrbiterC = RotL64((aOrbiterC * 1988599349457831597U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5873314228291583482U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16418290052752166515U;
            aOrbiterJ = RotL64((aOrbiterJ * 18270363452003213317U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9158414409987627714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8205937960146492168U;
            aOrbiterK = RotL64((aOrbiterK * 14008398661393344261U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16386126219854809263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12418021156683187869U;
            aOrbiterA = RotL64((aOrbiterA * 13897930566207284517U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5427232681451476584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18237670074497382745U;
            aOrbiterD = RotL64((aOrbiterD * 15528665160297906195U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8330262458028468513U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7790166497945719700U;
            aOrbiterF = RotL64((aOrbiterF * 6001280767763971107U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 48U));
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 37U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 20U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20439U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 19014U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16765U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 16643U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 50U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + 5173905450211892891U) + aNonceWordN;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 10U)) + 3555542451908039957U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 11559884700283861559U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 35U)) + 1352524329968738673U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 8914206450420616349U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 42U)) + 2251523378498463946U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 27U)) + 9541575923299247038U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + 1239854507907214595U) + aNonceWordJ;
            aOrbiterE = (aWandererH + RotL64(aCross, 5U)) + 17698101462598498934U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 13U)) + 12305566971683256060U) + aNonceWordG;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 13804545036303215569U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10239749097704329264U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4212214906286320308U;
            aOrbiterI = RotL64((aOrbiterI * 3661436621615751071U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12192418916967430783U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4475514289326450361U;
            aOrbiterK = RotL64((aOrbiterK * 17497164630368757887U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17376102613298827459U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18129393209955439341U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 6404089025014118979U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4014763724300253568U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17325007199676828814U;
            aOrbiterG = RotL64((aOrbiterG * 1420888274815627083U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15480474849292388685U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14357924730184375449U;
            aOrbiterB = RotL64((aOrbiterB * 16723492259068034209U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4335731868597970070U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8296023680394303015U;
            aOrbiterE = RotL64((aOrbiterE * 14027415401430120543U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2807312426993262800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15510369660839648501U;
            aOrbiterA = RotL64((aOrbiterA * 18207954408298333959U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12597844696606519907U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7231012798553551535U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2841306785994479299U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 849663631945232360U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4002310581470781194U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2148877014350721479U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16067735571435654555U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4607980694199923842U;
            aOrbiterF = RotL64((aOrbiterF * 10401780756830017477U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5346879191913449715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5173905450211892891U;
            aOrbiterD = RotL64((aOrbiterD * 15360571827429301833U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 14U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 28U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27255U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22637U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24362U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27144U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 37U)) + 17019646486641172469U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 35U)) + 12276141179299971572U) + aNonceWordA;
            aOrbiterI = (aWandererB + RotL64(aCross, 35U)) + 3617241694029841555U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 6967963401259371737U) + aNonceWordH;
            aOrbiterC = (aWandererK + RotL64(aCross, 51U)) + 6340709284279891017U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 54U)) + 456065368903896482U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 17686765719908116203U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 1322045955429785736U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + 5163772703302372887U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 3U)) + 13268431135020363252U) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 6538789950366849332U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10390344544314544893U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5087084271300584267U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 15149302947570776165U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13423071121590981727U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 18324443012024134729U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15814349432207734533U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4129091815978464507U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17024797553831962245U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3137753479364378175U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6501545108779991661U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11930037791867597447U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4904739567549702851U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4667298703308315851U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6315980380900062127U;
            aOrbiterE = RotL64((aOrbiterE * 12080555704907924637U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12732382340390769888U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7792095326183864547U;
            aOrbiterJ = RotL64((aOrbiterJ * 12645556660611824631U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17428384983571405782U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3193205313177048443U;
            aOrbiterF = RotL64((aOrbiterF * 14488006565106259731U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2813743367131107264U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2742138679703780981U;
            aOrbiterH = RotL64((aOrbiterH * 18356569025783532225U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6270291142961043031U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3490174937775044998U;
            aOrbiterK = RotL64((aOrbiterK * 13879285210885619613U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13182535825771438942U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13047228760732694484U;
            aOrbiterG = RotL64((aOrbiterG * 10365428317468779549U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17926326514553542739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17019646486641172469U;
            aOrbiterC = RotL64((aOrbiterC * 13978838314848228053U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterB, 10U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 26U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 50U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27583U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 31680U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30258U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 28639U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 13U)) + 1457104756581596530U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 23U)) + 6127240317844622874U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 60U)) + 16492290056044189421U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 10963676850938416468U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 27U)) + 4872917367399752405U) + aNonceWordL;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 15218882377875616148U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 5934166612122118251U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 14215280930872003003U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 29U)) + 11428034799044600979U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 51U)) + 5453003654321728726U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 38U)) + RotL64(aCarry, 5U)) + 14273775120265649389U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 328723770018440271U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13032190719588211088U;
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2386881543033598494U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1649501123340887116U;
            aOrbiterG = RotL64((aOrbiterG * 11148976582360499033U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16462401546754210583U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1510579201823042227U;
            aOrbiterC = RotL64((aOrbiterC * 16287912400104043275U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6889066000014251983U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11324594596597724357U;
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12237796033168436537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17306069670330000343U;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14197284538008811658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4754134852883071927U;
            aOrbiterF = RotL64((aOrbiterF * 3484427259538998699U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17201907781639753736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8318419319239859855U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10320390501983802091U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16012488623961565780U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15583721012865354925U;
            aOrbiterI = RotL64((aOrbiterI * 10656414363201743961U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14680351201973315018U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14483973292275372321U;
            aOrbiterK = RotL64((aOrbiterK * 9279222721410811027U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16324317860030681248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7038506963317910910U;
            aOrbiterH = RotL64((aOrbiterH * 2960451734542956767U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12767672960346001218U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1457104756581596530U;
            aOrbiterE = RotL64((aOrbiterE * 1560375242310194691U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 24U) + RotL64(aOrbiterI, 18U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 20U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2425U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 2967U)) & W_KEY1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2414U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3393U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 34U)) + 4622023259121087483U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 10253505250223501352U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 11U)) + 17133877904420462669U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 43U)) + 6162827793741796700U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 57U)) + 9610986424765907615U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 11210747154264753754U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 16554205219580654546U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 39U)) + 10352576357413766388U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 3651845783283479752U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 18145542190463500476U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5415609566767162857U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6474184559323816389U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2033734872464201570U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3507213117125813345U;
            aOrbiterA = RotL64((aOrbiterA * 5453058336688881113U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8716253393049851856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 695984869565941856U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8377921610764044735U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7661578828878284931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 906654265099155956U;
            aOrbiterD = RotL64((aOrbiterD * 8117625377607536949U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6050049984731254612U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17882717590338190821U;
            aOrbiterH = RotL64((aOrbiterH * 10807367411402733215U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4996521991532815957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8700148116452518842U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10039050281847466206U;
            aOrbiterE = RotL64((aOrbiterE * 11884791271239660157U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4513844680425845372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3037563127442815153U;
            aOrbiterF = RotL64((aOrbiterF * 18363509277992292407U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1005237931570968724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1373258132025712065U;
            aOrbiterB = RotL64((aOrbiterB * 10458020799382532395U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 44U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12643U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 15679U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9182U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12181U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 14179205183062705133U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 13U)) + 210032324058740920U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 28U)) + RotL64(aCarry, 35U)) + 7387115089142500152U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 17583362781238061430U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + 4991442849150005943U) + aPhaseCOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 2891376254689854555U;
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 10523274382407446239U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 40U)) + RotL64(aCarry, 51U)) + 3861893764676218667U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 5U)) + 3366674459852093746U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5898492634386601145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7047353571244768721U;
            aOrbiterI = RotL64((aOrbiterI * 2257518291062508467U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14374108805453186316U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8763667021501226510U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7694695426430267863U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18261523829316379575U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 650477532238860965U;
            aOrbiterA = RotL64((aOrbiterA * 8291758490821819851U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2162326554604894042U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5776546692501825278U;
            aOrbiterG = RotL64((aOrbiterG * 14911545784585246537U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3501863793638415049U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14853789267425352958U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10590325397179928739U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15399673014671329743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12253428583438990426U;
            aOrbiterH = RotL64((aOrbiterH * 12052855472196447849U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13202953937621953839U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7547616636832698398U;
            aOrbiterC = RotL64((aOrbiterC * 9533399972562428073U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15709801946594868318U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12458677982746610971U;
            aOrbiterE = RotL64((aOrbiterE * 6662570874316418993U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6957370791367530127U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10511379961344950861U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15551333099264031337U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterF, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH + (((RotL64(aCross, 56U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 4U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21464U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 20688U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18459U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 23308U)) & W_KEY1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aPrevious, 46U)) + 8685374557928800912U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 3482312691892161229U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 5U)) + 6948130297389161165U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 35U)) + 5506385663788942690U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 17859982009307397161U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 19U)) + 9178488809207094043U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 1835479501226057169U;
            aOrbiterE = (aWandererH + RotL64(aCross, 51U)) + 5368101733632614939U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 27U)) + 9050459666576835422U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9042186993119635078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17528342580198295025U;
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6495418332558436882U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8834495762667327342U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10783141541937645995U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4364314196965690905U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6357485231062120459U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3321488322626415347U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10817330671781848737U;
            aOrbiterH = RotL64((aOrbiterH * 15875919466358823335U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17974092279281611763U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2871472057292789157U;
            aOrbiterC = RotL64((aOrbiterC * 16104199340711015181U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15187929795092006849U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13482063681546475923U;
            aOrbiterF = RotL64((aOrbiterF * 14466266308157364963U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6232152545071397380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17488906002621373262U;
            aOrbiterG = RotL64((aOrbiterG * 4719340606442742577U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12444819880507588549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13808941689757772497U;
            aOrbiterE = RotL64((aOrbiterE * 6541360905282412317U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8049361354387692374U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7137831335606542401U;
            aOrbiterB = RotL64((aOrbiterB * 11022231291507235007U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 58U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterE, 18U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30761U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 30185U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28824U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 28890U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 56U)) + 12206125048349568300U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 47U)) + 5843520589343188818U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 12195046124287121687U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 11U)) + 16769779119214020640U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 19U)) + 5257603646260695833U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 8523523946234886745U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 37U)) + 7316024684200084096U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 11996978575084115207U) + aPhaseCOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 52U)) + 15491711479085513628U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6036648530996821484U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 926323222234121863U;
            aOrbiterI = RotL64((aOrbiterI * 6639661141258803779U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2700323841295743492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5852273765810284935U;
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11697397483133538067U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17777142964957007194U;
            aOrbiterE = RotL64((aOrbiterE * 6338967222543284999U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10892176201151170298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11759700374509499684U;
            aOrbiterB = RotL64((aOrbiterB * 14247697264744736081U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11343756773329590643U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15785048929757652350U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17208103574389502597U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7508839228498497238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13088508510402094665U;
            aOrbiterH = RotL64((aOrbiterH * 15730279447009669103U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16259236641717377699U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11228995722951003980U;
            aOrbiterG = RotL64((aOrbiterG * 4870092259515181323U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13775851561528617086U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3023564646900497080U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9936548213275464131U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 154952467284609583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14239675888632174461U;
            aOrbiterF = RotL64((aOrbiterF * 1370550680736926425U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 18U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 22U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7703U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6839U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3201U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5776U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 3U)) + 1888427424966603593U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 57U)) + 5436761445660415091U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 17322876217962143270U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 24U)) + RotL64(aCarry, 57U)) + 9728299982740564979U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 301720335271716921U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8069685428854814396U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1973715500949100991U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7940531594430629427U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 87666408799854155U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12195436904339035245U;
            aOrbiterE = RotL64((aOrbiterE * 15427739165893738105U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4578742069143400295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7828776048774876484U;
            aOrbiterF = RotL64((aOrbiterF * 4047964518501081039U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17203146364542781833U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16913369550858890466U;
            aOrbiterD = RotL64((aOrbiterD * 13534417587921978507U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9632761514552265402U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9106637671877341286U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9073709119482640391U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterD, 42U)) + aPhaseDWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 42U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13305U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 12078U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16200U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 8656U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 12775735908960052604U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 11791373812080296887U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 37U)) + 5537362877706057303U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 2023912048504189380U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 52U)) + 17668828109963766893U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 558908629933941224U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1479633119685446888U;
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15460320397843364063U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterE = RotL64((aOrbiterE * 8671817118586065469U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9987633811929693924U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10087337844580228269U;
            aOrbiterG = RotL64((aOrbiterG * 13817142288940843815U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4446204415503364254U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15106063243302192717U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9430197906134676162U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1226048679997253363U;
            aOrbiterD = RotL64((aOrbiterD * 14247538885252664127U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 40U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 39U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16904U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 17045U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16971U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 19898U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 8020711767807230555U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 15368693777246341570U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 29U)) + 5117523734225562401U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 39U)) + 13155269151097507808U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 9879303753623578272U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1165799257173794826U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 930641942062732091U;
            aOrbiterE = RotL64((aOrbiterE * 17151944851548731159U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11330571332221123153U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2862963158282518899U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13782195862525974199U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6019186399361476659U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1924419843785161958U;
            aOrbiterF = RotL64((aOrbiterF * 9485557122500346869U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12618629043591380461U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9334176504266512405U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16829692481030013551U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5604784396927022709U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2833893610883508353U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25998U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((aIndex + 26226U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28414U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26743U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 77518479758428414U) + aPhaseDOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 4832061802166300011U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 47U)) + 11695291171006574112U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 35U)) + 7467412817843260094U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 35U)) + 17801484124471154757U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5555455638503958639U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5669470540733721606U;
            aOrbiterB = RotL64((aOrbiterB * 17219613748084498879U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3042388456327784163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2236734925228156691U;
            aOrbiterK = RotL64((aOrbiterK * 10076582424701705531U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14459720401528685450U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4814967631216658856U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18288097536171386643U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16950679344449075945U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6262238639302011050U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3522256359074996724U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12524717897707074242U;
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 6U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4864U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 358U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3724U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 2237U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 29U)) + 826930775230515406U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 5U)) + 5137814617363250861U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 37U)) + 14761561947426681616U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 22U)) + RotL64(aCarry, 13U)) + 12773023438753662590U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 7331345852207096322U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 3899381212671247460U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 53U)) + 10072004147620068599U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3424585039401897560U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8246760141625966321U;
            aOrbiterG = RotL64((aOrbiterG * 11478879365443736383U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3655992860610853290U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11154618022505863898U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4791494171286145231U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15629361991059709973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10842068502278489664U;
            aOrbiterF = RotL64((aOrbiterF * 17223002513104960799U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5571312349016336686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 589313823745748879U;
            aOrbiterA = RotL64((aOrbiterA * 1356685926549786027U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13633457935771935260U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12684602052812183096U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4689206269919806711U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5711307583717354204U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7181854170553728211U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9835601115561325911U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1884620014396115821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1471516373272364262U;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 20U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 46U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9954U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((aIndex + 13511U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10635U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11930U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 29U)) + 16651241552253078315U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 4558144676982478003U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 41U)) + 8814884320080367550U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 16011579668555672117U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 21U)) + 4738918668759862438U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 12526083125540985108U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 57U)) + 8048723561746000552U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1082218464034639039U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8432043246965946816U;
            aOrbiterE = RotL64((aOrbiterE * 7801965585991025451U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9982080524048636852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6720069955755215919U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1019035028070247757U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7360619079463870467U;
            aOrbiterJ = RotL64((aOrbiterJ * 6623074813047915863U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10893918488381348474U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1390297670907738019U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11909657437658597735U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12512200589031203480U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14741471280748399540U;
            aOrbiterI = RotL64((aOrbiterI * 3012135242889901095U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8543897248359826770U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8545972622733791272U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11793879362775346821U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7049384618581928664U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14730773807906925408U;
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 60U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18788U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18853U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18839U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20601U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 52U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 57U)) + 5131645209694953015U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 12070391048835379854U;
            aOrbiterF = (aWandererA + RotL64(aCross, 21U)) + 2604295836242338724U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 14042039029284001596U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 41U)) + 8914654543854559327U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 5U)) + 2185619407969359869U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 5187406295103352574U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8022832481290871217U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8783061916740573472U;
            aOrbiterF = RotL64((aOrbiterF * 3309891377744201773U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10711028365596196301U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13387065038269133571U;
            aOrbiterK = RotL64((aOrbiterK * 12444578026365205255U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11187001318931801582U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14191473173276034019U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16207761776716426435U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9677408414452078760U;
            aOrbiterD = RotL64((aOrbiterD * 5487303383095129949U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17812460332794370649U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7736423148554132028U;
            aOrbiterH = RotL64((aOrbiterH * 15588733747232852555U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17293203944059014763U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13487243633338010243U;
            aOrbiterJ = RotL64((aOrbiterJ * 9468688858740539095U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15979293016815060755U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17645215484691359547U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1449450767288733995U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterF, 56U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31793U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 26699U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32640U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 31175U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 14U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 21U)) + 9041099828460168106U;
            aOrbiterB = (aWandererI + RotL64(aCross, 37U)) + 12883711604096848454U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + 17420968786226443079U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 3U)) + 3448213891716125104U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 11866455977445336560U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 4119356835384495905U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 39U)) + 2186212599698637068U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6506144898969301620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12556800923644051626U;
            aOrbiterF = RotL64((aOrbiterF * 15961043406612913121U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4075551535185182945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17877694808492008749U;
            aOrbiterA = RotL64((aOrbiterA * 901315308379887473U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5553428900598223316U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14362304852277160675U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11415103199856419303U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9174200302876075831U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16110739511917638547U;
            aOrbiterI = RotL64((aOrbiterI * 7004356839428657949U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10189881974519849402U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2128076632642616677U;
            aOrbiterK = RotL64((aOrbiterK * 8860453653433114929U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18133523799074400083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9916472958834153766U;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10274457562795569227U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14134814273275356425U;
            aOrbiterC = RotL64((aOrbiterC * 15912501063665343159U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 30U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1821U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 3068U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2575U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 845U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + 8975885703279267062U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 43U)) + 8664844915562660637U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 12281774799736296726U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 15347461352311329726U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 12967500561828907834U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5002833859280402726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11908257536954668983U;
            aOrbiterK = RotL64((aOrbiterK * 4384790916151202785U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17017174811949227162U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16851323125613931180U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12446990992858763577U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13469326957728686706U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5228638551056105241U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13369947664646167255U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11945166198089308564U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16268645041872996022U;
            aOrbiterF = RotL64((aOrbiterF * 5391448793718370911U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14781204627695095701U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5365325354838101092U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8017284997946310807U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 46U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 28U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11145U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 11214U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16353U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12472U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 51U)) + 13714409587461539863U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 14101156723903265839U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 13U)) + 7063754562895369001U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 12320578575245519386U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 19U)) + 11744826789631008424U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8744816505096675597U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10405435520084528645U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13279521344071568023U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1463157688070683543U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12379603577919617703U;
            aOrbiterF = RotL64((aOrbiterF * 14858901470015109311U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1343439118031348146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16118850268070235540U;
            aOrbiterD = RotL64((aOrbiterD * 11184386483735388257U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14116264435819277136U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5251698273012432109U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1495818611622063967U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14806408656041403829U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11569345414052398227U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9913158908301414861U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 36U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23784U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21234U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19733U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 21136U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 42U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + 9041099828460168106U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 12883711604096848454U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 17420968786226443079U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 3448213891716125104U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 11866455977445336560U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4119356835384495905U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2186212599698637068U;
            aOrbiterD = RotL64((aOrbiterD * 6756888950976735707U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6506144898969301620U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12556800923644051626U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15961043406612913121U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4075551535185182945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17877694808492008749U;
            aOrbiterB = RotL64((aOrbiterB * 901315308379887473U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5553428900598223316U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14362304852277160675U;
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9174200302876075831U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16110739511917638547U;
            aOrbiterH = RotL64((aOrbiterH * 7004356839428657949U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 4U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31954U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 24805U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31356U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 31469U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 29U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 3U)) + 14008824488073394623U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 13317978415866411468U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 13209180141897453900U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 11870521586865233578U) + aPhaseFOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 28U)) + 8052156380448047385U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12158131176743680605U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14674467487607719347U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18372548574199176503U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18055496790566231147U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3838105585041578784U;
            aOrbiterF = RotL64((aOrbiterF * 1075709247574580091U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2839568255183054418U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11933612922864258179U;
            aOrbiterK = RotL64((aOrbiterK * 7571964469321160347U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6289849094151630580U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2640344350528492271U;
            aOrbiterC = RotL64((aOrbiterC * 16197726750829369365U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16306175266267657791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3339898380394883600U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 54U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4572U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3298U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5176U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 8037U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 54U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aIngress, 39U)) + 18180797995100240808U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 57U)) + 6585906608223552885U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 3U)) + 14088708930575939855U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 468974153311516044U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 12481951025619894110U) + aPhaseGOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17227987923860711763U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4373962756657477139U;
            aOrbiterI = RotL64((aOrbiterI * 6069068316234356267U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2077576476565420951U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17435011300234663764U;
            aOrbiterE = RotL64((aOrbiterE * 8910133867294004711U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4118039398293246896U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13724716599855216683U;
            aOrbiterF = RotL64((aOrbiterF * 17556333902751079677U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12391461204689596339U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9900605191533799627U;
            aOrbiterK = RotL64((aOrbiterK * 13553565332531046301U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 972946858824366125U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17247681919694541215U;
            aOrbiterB = RotL64((aOrbiterB * 2974639094630445643U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 30U)) + aOrbiterI) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14047U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8307U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16235U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 12773U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 43U)) + 5697928251815176134U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 337587740689259575U;
            aOrbiterC = (aWandererH + RotL64(aCross, 35U)) + 4927686903263973950U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 3742409032569801033U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 11U)) + 1608092659172197650U) + aPhaseGOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15848744267145717509U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15300174177963339253U;
            aOrbiterC = RotL64((aOrbiterC * 5771922862677667319U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14162868453323648628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12020167069983729869U;
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16259538291658723956U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8516686212464112245U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4731296903548893627U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3722184575520553132U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15265344442454471986U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 46U)) + aOrbiterC) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 17530U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24241U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23109U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24437U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + 6469584119078165548U) + aPhaseGOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 14329756366517987910U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 12890831797059772123U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 3164503807500018990U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 54U)) + 177531431387646836U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3167421392893561015U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2813174781844753460U;
            aOrbiterI = RotL64((aOrbiterI * 9760688894575305115U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10953270419153249857U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16911518309710356951U;
            aOrbiterD = RotL64((aOrbiterD * 13162785997686570445U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6616750447844893150U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10276741398025985982U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6824712685896987133U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6206043608461213208U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12021552904553405793U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10023362889960174909U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15283586234744144846U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5923238786775948571U;
            aOrbiterC = RotL64((aOrbiterC * 8200882393521882651U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 24U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28596U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25004U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26949U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 30876U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 58U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 18255347001097480328U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 13679246790311505735U) + aPhaseGOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 47U)) + 10565839529765027116U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 39U)) + 14327172566224769901U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 29U)) + 16239024612038195174U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13800012174212131890U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13900288860157577583U;
            aOrbiterB = RotL64((aOrbiterB * 13177682776510523095U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4144386119777112740U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3154558262670631372U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13236911910092437063U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7456728543137614001U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11709519851158935384U;
            aOrbiterA = RotL64((aOrbiterA * 7016689518570071587U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15607438907832240304U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9276575329661725624U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6459435969129449226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6442382118416542275U;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 38U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererA, 38U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7688U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4845U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 317U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4273U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 12U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 13854738573712660276U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 29U)) + 16835460633412286294U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 6785859293758091931U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 41U)) + 126317283127992659U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 5U)) + 7568963536291415413U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12294016745653004819U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 18269588932920281147U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9031152619272892317U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5872406424994751026U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7764434758831474129U;
            aOrbiterJ = RotL64((aOrbiterJ * 3772146788188420071U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4804168969415573371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 959601763507651280U;
            aOrbiterD = RotL64((aOrbiterD * 4647396592804833217U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9257644462479293048U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14332699366894494579U;
            aOrbiterH = RotL64((aOrbiterH * 8829304078930625541U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10487012596470786004U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 612729229562321440U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11380387280507726003U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 38U) + aOrbiterB) + RotL64(aOrbiterH, 58U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 9164U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 9252U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14989U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 10291U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 5U)) + 6342299552323486695U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 12692748514781367538U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 8202639945493229155U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 37U)) + 4439975701793231639U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 16774235182859553759U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8764155413335405667U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7167848811974967685U;
            aOrbiterH = RotL64((aOrbiterH * 1052856924757654735U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16768278912125334220U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9090838954826296201U;
            aOrbiterG = RotL64((aOrbiterG * 5459329624017272077U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7644075729758006298U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17326182797908071215U;
            aOrbiterE = RotL64((aOrbiterE * 2408330168749256075U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16158809721888137555U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8029938783858263694U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8716553521415553404U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7012599977009208840U;
            aOrbiterA = RotL64((aOrbiterA * 8775355876188948851U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 26U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 19929U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 19644U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21719U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 23129U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 1042610313571524121U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 51U)) + 3505725321008825582U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 22U)) + 12584654563843782991U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 6645399144515770935U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 3608978423753715584U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8089198857670370983U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15207251813516399879U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7596841660069752069U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9579268660105824516U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16055044469473802812U;
            aOrbiterE = RotL64((aOrbiterE * 2269649280637188723U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 583811872609805949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7027491967970873942U;
            aOrbiterI = RotL64((aOrbiterI * 12686754713465826139U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18256061823189677508U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12708429127816136937U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12593886633108075321U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12169216645156306078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12694325407567795065U;
            aOrbiterD = RotL64((aOrbiterD * 3711789483877261899U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 28U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 52U)) + aPhaseHWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30797U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26396U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28342U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 29195U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 13714409587461539863U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 13U)) + 14101156723903265839U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 7063754562895369001U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 41U)) + 12320578575245519386U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 21U)) + 11744826789631008424U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8744816505096675597U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10405435520084528645U;
            aOrbiterK = RotL64((aOrbiterK * 13279521344071568023U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1463157688070683543U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12379603577919617703U;
            aOrbiterI = RotL64((aOrbiterI * 14858901470015109311U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1343439118031348146U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16118850268070235540U;
            aOrbiterD = RotL64((aOrbiterD * 11184386483735388257U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14116264435819277136U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14806408656041403829U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11569345414052398227U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterD, 54U));
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
