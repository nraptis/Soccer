#include "TwistExpander_Rugby_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Rugby_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x84C7309D765686E5ULL + 0xFEC4D536F95A2F53ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDE47ED0B4DF3B2D5ULL + 0x9BCF9364A6E640BAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD152305BC4633125ULL + 0x9A928381B279B69AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBE03255212303D41ULL + 0x8EFADABED946B0F8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xADBC660B2685DE07ULL + 0xCB4CC9A52AD74542ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFAD188318B2DC37DULL + 0x8EFB0646A95A3B5BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCC423A15775772B9ULL + 0xF1063A743B22350AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD60E6C6692B41137ULL + 0x93E33CFE15D4FD27ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEC8612B7A6652EB1ULL + 0xB7054EEB0385CE8EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE6F1460299DA41BFULL + 0xD44FDE285EAB1C94ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF0266EAF8D2D8BEFULL + 0xE70C278E5F2EE9DAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC8B116F262C2F069ULL + 0xD3DA995BA7DC5617ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA6EF42C0A96648A9ULL + 0xF937E721EA063D2DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE4C378DBF85C7F83ULL + 0x8AED35DF13603B61ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x83277C237D7E9C9FULL + 0xA8BC3C83B06CF6E0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCDB92C78FF7D63FDULL + 0xA95678C541DB1F51ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2712U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 2553U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 544U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1550U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 54U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 15316464782468770057U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 50U)) + 6642872057476351588U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 27U)) + 660732654689529192U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 7235418086884000655U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 47U)) + 14784518476694580493U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 39U)) + 12222433977933449375U;
            aOrbiterH = (aWandererD + RotL64(aCross, 5U)) + 8573001207708329927U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 43U)) + 16035256260815013172U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 12U)) + 15767726974121910203U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 53U)) + 17712217935322939971U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 13488963456923357159U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10222949131965611079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1495561412321657209U;
            aOrbiterG = RotL64((aOrbiterG * 9706305581868526265U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16156530750584361434U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7773792489045606309U;
            aOrbiterK = RotL64((aOrbiterK * 10730624207715601393U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11544578291333360613U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3665587867634242865U;
            aOrbiterD = RotL64((aOrbiterD * 4840528190844842595U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15248434984650998090U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15487979645426567581U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6972347795052712690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16074994810010431338U;
            aOrbiterH = RotL64((aOrbiterH * 1262655238856775853U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16851139687900415292U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14630026837021552812U;
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14236330619137368169U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17778707026111136216U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16239561893843454747U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9390961969105999083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1174881758316573228U;
            aOrbiterC = RotL64((aOrbiterC * 6602061268277529311U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3025148570039849574U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2813499258480831171U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12272555492688861861U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15397952138592662354U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10394648143430175275U;
            aOrbiterA = RotL64((aOrbiterA * 18195627209519212303U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3043205345760158739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15316464782468770057U;
            aOrbiterF = RotL64((aOrbiterF * 8162506622688910545U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 40U) + RotL64(aOrbiterK, 50U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 36U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8204U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5597U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6597U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9060U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 29U)) + 10726035965553989335U;
            aOrbiterF = (aWandererD + RotL64(aCross, 43U)) + 967354339530195662U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 43U)) + 10834593005478605624U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 3U)) + 1012888282838656933U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 15283530351725183253U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 35U)) + 11724495956731703750U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 47U)) + 4288330117317505776U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + 10894778070022873473U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 15563886747621617467U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 11182488628562891937U) + aNonceWordP;
            aOrbiterH = (aWandererB + RotL64(aIngress, 23U)) + 10420140066310588580U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11775138062167543111U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16545391898578161683U;
            aOrbiterG = RotL64((aOrbiterG * 14588306527161321535U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1550144656312299266U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14903504853138279883U;
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 309935535526750396U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13991265868040011411U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 2887531132228588441U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1755976294857114222U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2259275858478396846U;
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4838175912944552936U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12307900457200936013U;
            aOrbiterD = RotL64((aOrbiterD * 14719363144850838805U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18025411832912225805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 981375022769564523U;
            aOrbiterI = RotL64((aOrbiterI * 15869361544011831483U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3174014054982742562U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8119692378748963609U;
            aOrbiterB = RotL64((aOrbiterB * 3072354179707448489U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14502863160788675807U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1207582534593709516U;
            aOrbiterK = RotL64((aOrbiterK * 3045412087535529357U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5838011917777875072U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 434594114594643600U;
            aOrbiterA = RotL64((aOrbiterA * 1591023655239709931U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15711060039063734443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8307150522686198490U;
            aOrbiterJ = RotL64((aOrbiterJ * 2082452039297764679U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5805686529930815226U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10726035965553989335U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5563221485243331689U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 40U) + RotL64(aOrbiterG, 34U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 42U) + aOrbiterA) + RotL64(aOrbiterF, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11699U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13378U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 13571U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11670U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aPrevious, 41U)) + 14624277139785904404U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 58U)) + 6966977309498165611U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + 205536824352530761U) + aNonceWordF;
            aOrbiterK = (aWandererE + RotL64(aIngress, 37U)) + 16629575265808255692U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 5U)) + 596881340147972746U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererF + RotL64(aCross, 19U)) + 11944412799107412650U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 4615021315668210206U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 8497630055977606216U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 27U)) + 11131601107309336885U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 29U)) + 5935883479805510099U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 21U)) + 15629346719765798174U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5279128339113651273U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16778365912440331821U;
            aOrbiterA = RotL64((aOrbiterA * 705421028266789241U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16003052937645491524U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6723226158737614764U;
            aOrbiterC = RotL64((aOrbiterC * 16690657664909260573U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9785784358981219543U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10055457337292292710U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17919129940751761111U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11779163108592974175U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1177999477942202687U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13475069421684114643U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9190694445141492214U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15605342360346353457U;
            aOrbiterD = RotL64((aOrbiterD * 14547769706392595647U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14877565450677523492U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1074095623308025684U;
            aOrbiterF = RotL64((aOrbiterF * 7884068939436891093U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12803174154216941583U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8813356463693637033U;
            aOrbiterE = RotL64((aOrbiterE * 4898237214617563167U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6063909634038581414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15112191502834052566U;
            aOrbiterK = RotL64((aOrbiterK * 6780741782103553485U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13926459034757240311U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4324555954703597591U;
            aOrbiterG = RotL64((aOrbiterG * 18068922072149745351U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7183063131331255506U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18072787091203847052U;
            aOrbiterH = RotL64((aOrbiterH * 12530396154012878153U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10143386327707219710U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14624277139785904404U;
            aOrbiterB = RotL64((aOrbiterB * 12100828883424264587U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 50U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF + (((RotL64(aIngress, 14U) + aOrbiterJ) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17220U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 19892U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18431U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 21436U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aPrevious, 57U)) + 13278949403988203974U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 26U)) + 9213599924054673756U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 1255746482932381798U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 21U)) + 11575321997144516122U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 15881587525529432437U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 9846195809864862707U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 5U)) + 12319815691858217670U) + aNonceWordN;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 23U)) + 16322617427294439587U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 41U)) + 16332130810525887437U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 4920951156015336794U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 41U)) + 16767126455124552329U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12553595911087945223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1437522202135436142U;
            aOrbiterA = RotL64((aOrbiterA * 2001992794165550905U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12313100454852227143U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2761983020631055729U;
            aOrbiterF = RotL64((aOrbiterF * 3874839760378039509U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17635303588421554367U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 788212489507463763U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17896475584538528059U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5192552894670654434U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6784748488807738811U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 8077237651953896479U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16113417046719114943U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1096874945215225916U;
            aOrbiterJ = RotL64((aOrbiterJ * 17308604412622879833U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7610274704570171595U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10466070212284342550U;
            aOrbiterI = RotL64((aOrbiterI * 6449728258497920613U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6777845928873855221U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5251515022021984126U;
            aOrbiterG = RotL64((aOrbiterG * 9018277343404261611U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13849343158824111498U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7977711210181714021U;
            aOrbiterB = RotL64((aOrbiterB * 4182053966171053577U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 6494539818728106982U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11314590450226080781U;
            aOrbiterC = RotL64((aOrbiterC * 12455979257225599157U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 552687702594328012U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14961304171192292246U;
            aOrbiterE = RotL64((aOrbiterE * 846375892915484717U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9771874402848476494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13278949403988203974U;
            aOrbiterD = RotL64((aOrbiterD * 2119203863777871233U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 20U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterC, 54U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 43U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22177U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22684U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22509U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22441U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 29U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 29U)) + 15726877954695761686U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 14187652171881943587U) + aNonceWordL;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 21U)) + 8420423151313882782U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aCross, 35U)) + 14942322692433259283U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 26U)) + 7272331475919796255U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 154504365041805840U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 17475491222554948786U) + aNonceWordP;
            aOrbiterH = (aWandererH + RotL64(aIngress, 47U)) + 5759181483165339605U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 52U)) + 5993060214499322845U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + 10901786237875941844U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 23U)) + 17135786595614068473U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5208202073886811165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6821452921018900631U;
            aOrbiterD = RotL64((aOrbiterD * 13119330055184115669U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13348064837402206969U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 8967943922403445136U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 300168481725373093U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8130283784171430891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6351113882502502876U;
            aOrbiterH = RotL64((aOrbiterH * 15960622823993072903U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6894708729226455769U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12065058511247133944U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5432601727436935831U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17138279326229372741U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12987698199066890628U;
            aOrbiterA = RotL64((aOrbiterA * 12665716655177320977U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13688833537574196675U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4211971980434000618U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1374411763361518851U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10376917117582537592U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4807742522197923516U;
            aOrbiterF = RotL64((aOrbiterF * 15257251453302090961U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18038296468177121243U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6879666349379745258U;
            aOrbiterI = RotL64((aOrbiterI * 15819475269715810555U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5193656664432659624U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 680899397323387963U;
            aOrbiterK = RotL64((aOrbiterK * 9857476056194621321U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1851929589073547860U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13093101559415170218U;
            aOrbiterJ = RotL64((aOrbiterJ * 13950928576652143737U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13695333301427028607U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15726877954695761686U;
            aOrbiterG = RotL64((aOrbiterG * 960063676226172027U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterC, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27961U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 28894U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31828U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29310U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 3U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 36U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererH + RotL64(aIngress, 24U)) + 6024062041314952357U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererD + RotL64(aCross, 37U)) + 18340757093658015585U) + aNonceWordI;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 11911120493880346751U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 53U)) + 17428074353884654439U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 58U)) + 12790849760814795936U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 35U)) + 12633397052172117800U;
            aOrbiterH = (aWandererC + RotL64(aCross, 43U)) + 11946150433665237945U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 16842157900909419285U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 14186235783224155962U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 11U)) + 13284904542579767591U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererF + RotL64(aScatter, 13U)) + 11609181965078844357U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9628562297095374984U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7850281529011259759U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 257458718073794527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10693404545773519306U;
            aOrbiterK = RotL64((aOrbiterK * 14821443722828498323U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3430519236533871460U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6183054506953198055U;
            aOrbiterA = RotL64((aOrbiterA * 6121082743789970911U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2905610989884221654U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterH = RotL64((aOrbiterH * 7770678426310856745U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16870142883133769663U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1403692060594816451U;
            aOrbiterJ = RotL64((aOrbiterJ * 9740854430251597879U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16904169913507057108U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4773518591580333357U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5306070307776061267U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6528141733853494275U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11254806909313951442U;
            aOrbiterF = RotL64((aOrbiterF * 6316669786405548827U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6857506858448143407U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2855763534355983644U;
            aOrbiterC = RotL64((aOrbiterC * 16881334940165182415U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12328391751024624740U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16475072086109949522U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15218626930666825883U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15505670341076785424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6972128419331939330U;
            aOrbiterB = RotL64((aOrbiterB * 12206069109180246067U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7151546362283646210U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6024062041314952357U;
            aOrbiterD = RotL64((aOrbiterD * 10243806128059850493U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterK, 38U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
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

void TwistExpander_Rugby_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE0731872626F5095ULL + 0x89A2B6E34AB10F39ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEEE34DF35EF7DF6DULL + 0x87F70C1A80DA3C96ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF556DF8B121DD4CDULL + 0xABBA40898FCAD64FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD907AD17A04B2127ULL + 0xD128737491EB2B7DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBAE754435528DF5FULL + 0xE254C1D7D753DF1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x95E999BF4B60854FULL + 0xB88CDF982AAB20FAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8664A893F46E9809ULL + 0x853AD7BA2AE1B3C9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF1A83116ED437621ULL + 0x80BC599A9230018EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD8F33F27D37444F1ULL + 0xFB9FB06EDFF06EE7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8FD5919C1D2769FDULL + 0xE7453B135D3FF09CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA6A7808F77D1447FULL + 0xEBA5B703074565FCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC4DDE12C345EE995ULL + 0xF0F21D490141C58DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDDF7CEFE0D604BC3ULL + 0xB3EE6E549FFC2989ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEF6623EF25353A39ULL + 0xA81CA5E8C6BA1FACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD5060325CB952EE5ULL + 0xACB1092466C64CF1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD700E146EB464A67ULL + 0xC4EB1EAF96D66689ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6629U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 2805U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4982U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4904U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 56U)) + 8101351470141807662U;
            aOrbiterE = (aWandererC + RotL64(aCross, 5U)) + 6965474099521076705U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 19U)) + 6803828268885684784U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 13454235922950972488U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 11678091885751244777U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 39U)) + 5307134544628507141U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 12U)) + RotL64(aCarry, 37U)) + 4873703518950429353U) + aNonceWordH;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 51U)) + 8542156221858586039U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 3993726182905296513U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12113047622035464386U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1944244448665721151U;
            aOrbiterG = RotL64((aOrbiterG * 7010050836758762003U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12914188029425467576U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2486762763475327024U;
            aOrbiterB = RotL64((aOrbiterB * 12319769994433811617U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14580191602982245481U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12093414832400135066U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12720286833215690663U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13623906997320021065U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9977356009806428696U;
            aOrbiterC = RotL64((aOrbiterC * 2005536391712733499U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3694954095397810851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11453812627797091638U;
            aOrbiterI = RotL64((aOrbiterI * 13730420725113907161U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 542311345544726351U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3024285045990499484U;
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15397664082460849530U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10716856680110815056U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13947203772929252823U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 833342121331428547U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1111339940097269219U;
            aOrbiterE = RotL64((aOrbiterE * 17991642769781175473U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9312963978841402871U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8225496710723213204U;
            aOrbiterF = RotL64((aOrbiterF * 894499195498817065U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterF, 56U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 38U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 42U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8688U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 15085U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8455U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14170U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 36U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 23U)) + 12027839670755583592U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 47U)) + 15380130703509859843U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 3U)) + 4590907433867798074U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 56U)) + 1754574023602519724U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 39U)) + 9832756659564903767U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 5035088494491470403U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 14199170923323644638U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 19U)) + 8325619421264440438U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 51U)) + 969534320779067977U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 270575869402913847U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13344806516599578910U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 10193544126281901579U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15143147951139409101U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14425582489214169238U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16893787086337916355U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13951127523239064584U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14177925225918293579U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 13079514031864998485U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8258920744278218901U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7408161179397242453U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 975737128100519169U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8581481606764773468U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10078416198417433133U;
            aOrbiterK = RotL64((aOrbiterK * 1102721083915858247U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 18299772198826189580U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18304668908084397946U;
            aOrbiterF = RotL64((aOrbiterF * 10589455451200578687U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16729632621573817223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13362300981585573239U;
            aOrbiterC = RotL64((aOrbiterC * 9824473895535518785U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8629682832849915380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6852852009091469641U;
            aOrbiterE = RotL64((aOrbiterE * 11912646687050011915U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7433098156961745198U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10931806208899417308U;
            aOrbiterI = RotL64((aOrbiterI * 14699197041038067483U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 56U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 34U) + RotL64(aOrbiterH, 6U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16706U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 18017U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18292U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24568U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 50U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 7893287783892523139U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 10257331997383491153U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 58U)) + 14562226733652231753U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 14320342577110737851U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 21U)) + 9816717579822880756U) + aNonceWordA;
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 9558926960095881953U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + 9230371862654338324U) + aNonceWordD;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 6U)) + RotL64(aCarry, 39U)) + 6414274291252913420U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 11U)) + 13868546184398350849U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16940736952569949038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2866957764814864371U;
            aOrbiterC = RotL64((aOrbiterC * 3554702178644797003U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7916721976073979724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1602444214978842275U;
            aOrbiterA = RotL64((aOrbiterA * 11072503711308122385U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9529061385251008037U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8402775110887376588U;
            aOrbiterF = RotL64((aOrbiterF * 13980225144628227381U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15003592180290390713U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14195681406520825751U;
            aOrbiterH = RotL64((aOrbiterH * 11455000833788877217U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3263577002367714202U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12019422062655581928U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5002313835338447799U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8508638054582582917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6536618106353552880U;
            aOrbiterD = RotL64((aOrbiterD * 6233964121117511885U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9654542989321430868U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7019594782797863244U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 1234877854354279981U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8256061220727519919U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9232754129467036130U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17556001874302369781U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5608829951337740378U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12632120498473345701U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 6994794653605831925U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 24U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aNonceWordK);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29628U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27731U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26237U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31097U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 37U)) + 13924571355038625040U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 24U)) + RotL64(aCarry, 41U)) + 16328300979357156658U) + aNonceWordO;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 3947771961206012461U;
            aOrbiterH = (aWandererB + RotL64(aCross, 3U)) + 15428284250569311285U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 19U)) + 5777369485254032486U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aWandererH + RotL64(aCross, 53U)) + 16813320300717644673U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 16689933050200758251U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 1856422419049390708U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 48U)) + 18214498743831925517U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18278550878494094923U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 797712062039591797U;
            aOrbiterF = RotL64((aOrbiterF * 7212998747080137625U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15854849439012341347U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 996882939768167773U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3005829974130671692U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8793495343509953906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065479348374612031U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7710453029930631112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9511995836117707047U;
            aOrbiterD = RotL64((aOrbiterD * 7250766204781428201U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 670902975693341744U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9045820304668279777U;
            aOrbiterH = RotL64((aOrbiterH * 18373074917532639027U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12417212387607119470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12816983560669985622U;
            aOrbiterE = RotL64((aOrbiterE * 8406003970221889847U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17245432086377688540U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6806521945548502014U;
            aOrbiterK = RotL64((aOrbiterK * 11335859481858640857U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8947500746292365294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4468060468522895852U;
            aOrbiterG = RotL64((aOrbiterG * 7022481284816599797U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9892975931958803992U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3042599331526937836U;
            aOrbiterI = RotL64((aOrbiterI * 3308512896171443645U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 4U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Rugby_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC043B055B60A6D57ULL + 0xDD5D8CE8670BF665ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE139809AEF63FBE5ULL + 0x82A1BF433076625FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA56D8A5BC8BD6779ULL + 0xEC572B1F66FC0C27ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEAFE76B9081B191DULL + 0xB21FF45A863AE649ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF98CB6FA4108C055ULL + 0x8BE98F4AB6428CC0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9A7EBECF7B7C1AE7ULL + 0xAC81DC244E17E746ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x89C79B3B192B8A13ULL + 0xA1FA131509F6D184ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8CF0EB18840D7A6DULL + 0xB834282DAFA55406ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x800D23F7EB9C5C45ULL + 0xBC6DDE0C80C82BDBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF795D2896F334569ULL + 0xF4FBDA7A257AF191ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9CB9BC75A83D4581ULL + 0xAC5F2DCA3B27BA12ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE690C9A84216DB57ULL + 0xBEAA46A6D883F104ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF096F7A3ED0847B9ULL + 0xCE1164626F00C2E9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF1D499E83AA4CDCBULL + 0x9AC843CB8D891A22ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE508C4269442F093ULL + 0xF9B5925FFF13506AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA3AC913414834451ULL + 0x8B800214F132B832ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3432U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4935U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4707U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 5316U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 29U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 17225673071833726819U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 43U)) + 10301458382103627331U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 3960233050857362414U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 17768665685046605837U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 14471018461213959767U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10730597892721340453U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14863394003122760542U;
            aOrbiterE = RotL64((aOrbiterE * 17731557030589257169U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9948587274816688296U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3573569431435100993U;
            aOrbiterD = RotL64((aOrbiterD * 2303922230056523077U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8153670675740450590U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16438856577722561424U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 4689247488336908827U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15765587867581925041U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1082039522061775213U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4202521649260798876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15877659681260461141U;
            aOrbiterJ = RotL64((aOrbiterJ * 11369910758551088173U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 52U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13194U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((aIndex + 8844U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15699U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9907U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 37U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 29U)) + 5568146815535263910U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 7736084960873834666U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 53U)) + 1336413621817562093U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 5218462026934984692U) + aNonceWordP;
            aOrbiterA = (aWandererC + RotL64(aIngress, 21U)) + 7048890985969555935U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 13415955213864702118U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5657023257021528548U;
            aOrbiterF = RotL64((aOrbiterF * 5200798937081797819U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14338310943137497116U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 12305161641833950473U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 11949964304435964395U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14514226578370459131U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12692904083266024340U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14800805065279908839U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11012959130001327964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3718101961355280891U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13364192077222322664U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1411328915372590283U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 12U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20458U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 19175U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20304U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17207U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 60U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 9446153639709651566U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 10550762260670758167U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 37U)) + 7062634922142578383U;
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 9178499097812764515U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 47U)) + 6887103379773525538U) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6239750312052010257U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17645022614523287959U;
            aOrbiterK = RotL64((aOrbiterK * 14448140327044053545U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3639618183259408272U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 3131737117548745095U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 6585057380704940395U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7253994382396406554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15217993711938379561U;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12594152227603630033U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterG = RotL64((aOrbiterG * 546800378327864723U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12936942656624279424U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10990736056052106149U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 7123916809953459187U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 24U)) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30878U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29026U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24826U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 28022U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 18U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 13204735390996728477U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererD + RotL64(aIngress, 57U)) + 851171359595647173U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 44U)) + 16745304202825290723U) + aNonceWordB;
            aOrbiterJ = ((((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 562392736584913979U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 3244267012529053918U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 17282536111067869133U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14851130066471729068U;
            aOrbiterH = RotL64((aOrbiterH * 6308165353504550619U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5256130407952363129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2904742485828362001U;
            aOrbiterI = RotL64((aOrbiterI * 12941135856735075457U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3723346325449225387U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5344621093694027341U;
            aOrbiterJ = RotL64((aOrbiterJ * 9044881458629673499U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12919263300833603026U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17989801264160996071U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15468293047311883751U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5022175042377172157U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16684822380107847758U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 2834049270263837537U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 36U)) + aNonceWordH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Rugby_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBB8309633ED620B5ULL + 0xFAC29913EECA61C5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEECF074FF0DA10D9ULL + 0xF4845357FAC7E21CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAAC3BB32E785FBAFULL + 0xB3FA3FC161CC0A4EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x87816E5811818835ULL + 0xF4060450EE1691C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB90F37D39A696FCDULL + 0xD5BC8729E44B7DA8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA1B9DB2CCA3E1AE7ULL + 0xB82F8BEFD1F244ACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCED303FECB11282FULL + 0xEAFD7667691D4E9BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF8F9B6953C0E0D3DULL + 0xA2C8786B5490D7B2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD3D91FB9B6999291ULL + 0xCBECFBE1CE0B77F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF744AC51863E4619ULL + 0xAFB9DE700012F35AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8EECD36B909064EDULL + 0xD04C5D4E2A8E2850ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA5207FB76DBD2159ULL + 0xDEB679CC27257D28ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAF937A0D5F349D77ULL + 0x80E6D958ED779565ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x989C2851941DA7F5ULL + 0xFA1CB832F4DFE045ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE3CB9AC4A4CFFF6DULL + 0xF51ACC4DF8C8474AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDD1C8DAC3D5AECADULL + 0xF3685E53F0453932ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6831U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 1383U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7189U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4293U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 15726877954695761686U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 13U)) + 14187652171881943587U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + 8420423151313882782U) + aNonceWordO;
            aOrbiterD = ((aWandererH + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 14942322692433259283U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + 7272331475919796255U) + aNonceWordI;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + 154504365041805840U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 17475491222554948786U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5759181483165339605U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5993060214499322845U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10799489831896153301U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 10901786237875941844U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17135786595614068473U;
            aOrbiterG = RotL64((aOrbiterG * 15923538730142047043U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5208202073886811165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6821452921018900631U;
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13348064837402206969U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterK = RotL64((aOrbiterK * 300168481725373093U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8130283784171430891U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6351113882502502876U;
            aOrbiterJ = RotL64((aOrbiterJ * 15960622823993072903U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6894708729226455769U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17138279326229372741U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12987698199066890628U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12665716655177320977U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 28U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12655U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 13645U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10018U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 15960U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 12122689833405846292U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 13U)) + 9640400270962766788U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 9141937998266739071U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 12899395770434090537U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 28U)) + 13457918115408031842U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + 15134784483576000943U) + aNonceWordO;
            aOrbiterH = (aWandererH + RotL64(aScatter, 37U)) + 12540961268790055438U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6306886773092764230U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13573343491337243121U;
            aOrbiterG = RotL64((aOrbiterG * 15893457012357368707U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8545588657348974413U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10891410570357275120U;
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2877137119767060151U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9178097682386595144U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3524486002084427513U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15528007881855616978U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11368419529245281435U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 12433207037378339309U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5932738914934356645U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5551842263864055419U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16093776759971522681U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3824433359595690603U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17184628855571662441U;
            aOrbiterE = RotL64((aOrbiterE * 691208053136187317U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8724462245014132623U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7481349499528092352U;
            aOrbiterH = RotL64((aOrbiterH * 8212182934509617583U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22246U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18809U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22882U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 20412U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 5U)) + 8793908991006073956U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 2932916283348441943U) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 38U)) + 11069042087940968262U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 14369628676782894441U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 23U)) + 8602903272780978282U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 3827036107178568820U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + 8905245209036772489U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13331387530760017893U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9880107580289737823U;
            aOrbiterD = RotL64((aOrbiterD * 10302652857542703753U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10199619040626900278U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2466307560891374281U;
            aOrbiterC = RotL64((aOrbiterC * 6295342978834217571U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 13973403407981259448U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2851460278409385243U;
            aOrbiterG = RotL64((aOrbiterG * 11226902976321781743U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10365453393815690776U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2382382358987358791U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 481563628980705781U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5058198848163792422U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10500434740387593487U;
            aOrbiterB = RotL64((aOrbiterB * 5946747708776079787U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11289798395177667084U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14327152153231286666U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18155778059595245561U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8065137263811956313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3865153574847924816U;
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 54U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32409U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 31152U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25631U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 32651U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 21U)) + 14624277139785904404U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 48U)) + RotL64(aCarry, 3U)) + 6966977309498165611U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 205536824352530761U;
            aOrbiterH = (aWandererH + RotL64(aCross, 35U)) + 16629575265808255692U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 11U)) + 596881340147972746U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 41U)) + 11944412799107412650U) + aNonceWordD;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 4615021315668210206U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8497630055977606216U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11131601107309336885U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18028349768453554935U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5935883479805510099U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15629346719765798174U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 8535523790685945275U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5279128339113651273U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16778365912440331821U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 705421028266789241U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16003052937645491524U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6723226158737614764U;
            aOrbiterB = RotL64((aOrbiterB * 16690657664909260573U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9785784358981219543U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10055457337292292710U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17919129940751761111U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11779163108592974175U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1177999477942202687U;
            aOrbiterH = RotL64((aOrbiterH * 13475069421684114643U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9190694445141492214U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15605342360346353457U;
            aOrbiterI = RotL64((aOrbiterI * 14547769706392595647U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 3U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererH = aWandererH + (((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 41U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
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

void TwistExpander_Rugby_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCEED1D4FDAC98A43ULL + 0xBC3F847A89D881C2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9A67C3A20CA0E1DBULL + 0xBF68B6A1B0F6DF26ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAE4FEB58F8348379ULL + 0x9E0CE7885B2A5D47ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB29A84942DC649CBULL + 0x9A1F2A33D638A662ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBF5AA8DF6BB62465ULL + 0xD2C32F0980D08136ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB9C61179C45B520BULL + 0xEE21298045D3383BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x81E5F2BA3968F0BBULL + 0xFB52FB092027450DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFBDDF40FF8E40465ULL + 0x8BF80867DDBA3BE2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xABAE53CFD8731D11ULL + 0xAADE2EBB40BF22A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD8ECEE6B8C1234ADULL + 0xE8F7D13C191F41A7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCEADE0C773B2B93DULL + 0xA37F8559B1B6EE9DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9E522C63B173BF81ULL + 0xA1A74922BF81F802ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC1C915FAB3474B99ULL + 0x84C219EE0E933E10ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE686F0FEB6312E4BULL + 0xD42293B620E9393AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFB862D909037170FULL + 0xF793299DEEDCD894ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x801A833C15B138F7ULL + 0x88790EB7AA66646DULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5475U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 5715U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2524U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4384U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 56U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 13714409587461539863U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 14101156723903265839U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 29U)) + 7063754562895369001U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 12320578575245519386U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 54U)) + 11744826789631008424U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 47U)) + 8744816505096675597U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 41U)) + 10405435520084528645U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1463157688070683543U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12379603577919617703U;
            aOrbiterI = RotL64((aOrbiterI * 14858901470015109311U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1343439118031348146U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16118850268070235540U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11184386483735388257U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14116264435819277136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5251698273012432109U;
            aOrbiterD = RotL64((aOrbiterD * 1495818611622063967U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14806408656041403829U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11569345414052398227U;
            aOrbiterA = RotL64((aOrbiterA * 9913158908301414861U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17063874769147888574U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9927420478679581917U;
            aOrbiterK = RotL64((aOrbiterK * 9042782809534196563U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2550285599827162167U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17801534123304996448U;
            aOrbiterB = RotL64((aOrbiterB * 2160836889363614721U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6456685241021762041U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17064208177372969289U;
            aOrbiterG = RotL64((aOrbiterG * 13726627607233302493U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 4U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12021U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8825U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14773U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13945U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aCross, 35U)) + 4179952823252098240U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 3745613452332101749U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 43U)) + 2955689793395307176U) + aNonceWordD;
            aOrbiterG = (aWandererB + RotL64(aScatter, 28U)) + 5639060180251322019U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 7901969163853586463U;
            aOrbiterI = (aWandererK + RotL64(aCross, 3U)) + 2242166787816318119U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 5239936443960750064U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13939136954732185558U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17058884136712717463U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7222348891215482977U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 18148618660054585941U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7022023484530327814U;
            aOrbiterJ = RotL64((aOrbiterJ * 650100011311048589U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7722084537340095637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11764151879690934182U;
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16412785901758144708U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9666718667728274824U;
            aOrbiterE = RotL64((aOrbiterE * 10865799822751771795U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4307127540152109364U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2457646804702647606U;
            aOrbiterA = RotL64((aOrbiterA * 6340030928007058595U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3179394870088602208U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 504977947273774249U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 16190282058883481551U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16182729401018310837U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7110817020445860609U;
            aOrbiterC = RotL64((aOrbiterC * 13371352088428584087U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 58U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18716U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17769U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19882U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18576U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCarry, 19U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 701291026547470433U) + aNonceWordE;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 60U)) + 17283292650462111643U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 37U)) + 9969124091931303406U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 13U)) + 889176772718046988U) + aNonceWordF;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 6054541844643748084U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 14703226235143028132U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 51U)) + 7977975878522921062U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16894322614172266274U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12160451749345900570U;
            aOrbiterD = RotL64((aOrbiterD * 18055355572903901749U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10870847008043897470U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8159920947172520247U;
            aOrbiterJ = RotL64((aOrbiterJ * 4833194641611011805U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2440099120969517932U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2428396147731468007U;
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2213226274394673479U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7079731443427765333U;
            aOrbiterK = RotL64((aOrbiterK * 16918930776877030559U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 958896789550478970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10788682955708075458U;
            aOrbiterB = RotL64((aOrbiterB * 913321215613559729U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2003386579317564870U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8419686358774204999U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6547052526438697621U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 6989167615157578904U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17636634003643824148U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11038576417283732937U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 6U)) + aOrbiterH) + aNonceWordC);
            aWandererK = aWandererK + (((((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 19U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 34U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30901U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 32454U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27133U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26875U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 41U) + RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aScatter, 27U)) + 11039986441331892533U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 21U)) + 6256024955965426119U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 3U)) + 9857443189988995666U) + aNonceWordO;
            aOrbiterC = (((aWandererH + RotL64(aCross, 47U)) + 11900944813380998208U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 8422577734978875541U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 3100835100713928724U) + aNonceWordN;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 11871553509810206993U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17614749493763417027U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3638372131856199916U;
            aOrbiterK = RotL64((aOrbiterK * 480683274898147025U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6582275259281025770U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17016882418498941958U;
            aOrbiterI = RotL64((aOrbiterI * 4269869255230867823U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1747214688658984715U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9356088987044015278U;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4056238112133473456U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16013150119949532998U;
            aOrbiterH = RotL64((aOrbiterH * 12913648646318115315U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16076621211111834889U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9940824359571581765U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11624767861336495331U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15624084004784515753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7630989544834680335U;
            aOrbiterC = RotL64((aOrbiterC * 12261063237156822067U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18003586430673313786U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1654118743290334161U;
            aOrbiterJ = RotL64((aOrbiterJ * 1153250137357176071U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 28U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Rugby_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB1C0A270296AD057ULL + 0xCF64F89A2DCCDE04ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC66CFE33AB26B7DBULL + 0x93FAB451B035B533ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x94AD26B726EF5D8BULL + 0xD94CE63FA32B09AAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA99158258CBCC369ULL + 0x89DA527BBE29CAE4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xADE1CAC83123DC75ULL + 0xA64AC3283E963314ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x804576BF6B35FED5ULL + 0x92A731E1008E602FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF7B5555507F2FE97ULL + 0xD05FDD7E37F0D3B3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA5DCBF6E0A46353BULL + 0xB8B87DC84D01A7E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC4F15B80C1EACFBBULL + 0x91F2CF3DC3C5C1F1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBD3239B4B291AB03ULL + 0xBCD4E73D3BF6F24AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8F72AE4D3B501617ULL + 0xA10739DF6337C249ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAB69DFE1F5856A2DULL + 0x9008E80E137024EBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9F0132DE5B12757BULL + 0xB5BC7C5F3921FE15ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x84AA881D7702BAC7ULL + 0xA361F29335FEA1CFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC7DC84E693EFF547ULL + 0x9BE7C74B05AE1879ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE7EB6A728507633BULL + 0xA3B777BF6702E02EULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2447U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7194U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3636U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 137U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + 8793908991006073956U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 37U)) + 2932916283348441943U) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aCross, 39U)) + 11069042087940968262U) + aNonceWordE;
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 14369628676782894441U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 8602903272780978282U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 20U)) + RotL64(aCarry, 47U)) + 3827036107178568820U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 43U)) + 8905245209036772489U;
            aOrbiterA = (aWandererK + RotL64(aCross, 41U)) + 13331387530760017893U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 27U)) + 9880107580289737823U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 24U)) + 10199619040626900278U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 2466307560891374281U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13973403407981259448U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2851460278409385243U;
            aOrbiterI = RotL64((aOrbiterI * 11226902976321781743U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10365453393815690776U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2382382358987358791U;
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5058198848163792422U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10500434740387593487U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5946747708776079787U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11289798395177667084U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14327152153231286666U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18155778059595245561U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8065137263811956313U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3865153574847924816U;
            aOrbiterD = RotL64((aOrbiterD * 9495741102667755161U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18102279969722473375U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6306428427188742325U;
            aOrbiterG = RotL64((aOrbiterG * 17826782872351406167U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16953348204663693724U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11950791817032898613U;
            aOrbiterF = RotL64((aOrbiterF * 1498946055469611133U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11980823193543752994U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17845490308799454871U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385153013485463791U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5566398755702887071U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10308378271388889968U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 142732084484961281U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6717846700455219260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8297225372883997017U;
            aOrbiterA = RotL64((aOrbiterA * 14102812043481327907U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12249337046267666603U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8793908991006073956U;
            aOrbiterK = RotL64((aOrbiterK * 5851229209188473467U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 56U)) + aOrbiterC) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterB, 60U));
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12137U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 14562U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11917U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11915U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + 4068921616130916949U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 47U)) + 12077715273915151726U) + aNonceWordK;
            aOrbiterB = (aWandererD + RotL64(aScatter, 11U)) + 16047546802670596833U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 44U)) + 9690277462716999763U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + 14484814700447992628U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 17089267243053958210U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 9138746214446211147U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 21U)) + 10181001536979097045U) + aNonceWordF;
            aOrbiterC = (aWandererG + RotL64(aCross, 14U)) + 6657458969093373191U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 7515983477876590988U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 53U)) + 3039935555863947600U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16209389224740851136U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 725253312098083182U;
            aOrbiterB = RotL64((aOrbiterB * 17535989492095522597U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13307041115748941383U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12027236743251643820U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8717826175991286553U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 1175614802543098451U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4769096034227659937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11201226563992939616U;
            aOrbiterG = RotL64((aOrbiterG * 15595355978388159931U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17295978531215563256U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11850923890626719833U;
            aOrbiterC = RotL64((aOrbiterC * 3854851059897397075U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14139441565288097706U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 988684899382304485U;
            aOrbiterK = RotL64((aOrbiterK * 11929090869999700891U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6159251276942253175U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4849529993914550651U;
            aOrbiterE = RotL64((aOrbiterE * 18240712676783671317U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6679745455842119497U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15838404437552215214U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17357853511591350887U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15853153471104458948U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12542164757451566994U;
            aOrbiterA = RotL64((aOrbiterA * 12163611303899312043U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14304233464055838869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4037999346933039765U;
            aOrbiterI = RotL64((aOrbiterI * 564236202758328407U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3582312827630995454U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4068921616130916949U;
            aOrbiterD = RotL64((aOrbiterD * 1527829107415867363U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 60U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 50U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17835U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22112U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24326U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17921U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 9914837590440975587U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 6706125076401958051U;
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 16570817772679258409U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 3U)) + 6843705658115186948U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 37U)) + 16099930446791572351U) + aNonceWordL;
            aOrbiterE = ((aWandererF + RotL64(aCross, 50U)) + 5420550009556030459U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 5U)) + 5729549069420177477U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 15590601126188675834U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 13044027390998620029U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 26U)) + 11068338135659636772U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 21U)) + 6584988841809544332U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8516813219883915404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10647314042912492785U;
            aOrbiterF = RotL64((aOrbiterF * 15559481057047148785U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 201691689889605304U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3883760518944464145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13861805129175491145U;
            aOrbiterA = RotL64((aOrbiterA * 17194438894492581181U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12019138626550801486U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11724200983306280107U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2643807255422544248U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4127143302485631794U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14602951930809633069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4555737199162278494U;
            aOrbiterD = RotL64((aOrbiterD * 12415825635220991865U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6343143902997169834U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10404783711336491985U;
            aOrbiterH = RotL64((aOrbiterH * 6235474458879439079U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7406959231434835393U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6684368109277850196U;
            aOrbiterG = RotL64((aOrbiterG * 8760360417572331159U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4835889355927954728U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7917682889852676712U;
            aOrbiterC = RotL64((aOrbiterC * 9045350756570117327U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10268055422944417055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5563744562922937643U;
            aOrbiterK = RotL64((aOrbiterK * 12442484191329795173U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17244672945880141679U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9914837590440975587U;
            aOrbiterB = RotL64((aOrbiterB * 12269340309792850489U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 30U)) + aOrbiterB) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24880U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28447U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24821U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31611U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 14U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 13U)) + 16183871922837164759U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 5U)) + 7002058258090219055U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 46U)) + 5650868611888303705U) + aNonceWordE;
            aOrbiterA = (aWandererE + RotL64(aScatter, 51U)) + 11899839660943876690U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 15349649504488111111U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 14060149569086744970U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 53U)) + 12920917574225030112U) + aNonceWordC;
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 2831994965175330135U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 13U)) + 18312543585028439192U;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 11657562205118394239U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 3U)) + 10850792819281246052U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17810371216216125323U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7963413941144223128U;
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5498715358793875584U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9256727548911651373U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17246360111302191699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3100998994319502921U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8129301860291235970U;
            aOrbiterK = RotL64((aOrbiterK * 17847033539279176187U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1889641029473279114U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16538494307002917945U;
            aOrbiterB = RotL64((aOrbiterB * 8081488217920885783U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5432230549146849322U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2634437941396090817U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 7612999214758935211U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16940172599174185058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13151669140593952203U;
            aOrbiterD = RotL64((aOrbiterD * 16225319638131723487U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3995064294869931681U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 913081077665768816U;
            aOrbiterE = RotL64((aOrbiterE * 9299514648768060453U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2469001696075411481U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2167390955194185443U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11805065572289005223U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1574066406534010796U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8736976961589874013U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 5980070607180321955U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4233621443153132083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16183871922837164759U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4030569514959370895U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 54U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 24U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Rugby_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDD8EB18404C72BA5ULL + 0xA9F713B87765D535ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC52D1F5B2CD2A79BULL + 0x96C6039E25840E2FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD2E58A6897FBCB8DULL + 0xC0C3FE4AC5787793ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA7C949D2035FFDBFULL + 0xD368B9799E32766AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE866484CD6523EBBULL + 0xF20A26C534F5496DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE5BB01CE1EAD4A67ULL + 0x80E1065E6493BCB3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD53ED80C8DAA4C31ULL + 0xD4B01ADB4DFE7B3FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9E32130862BB4E45ULL + 0x90A71990E4FC72E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x802C3E922D84F8C7ULL + 0xBD136AF41DAD4BEEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCF6082336DCE7767ULL + 0xA2C73542CEC8E5BEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAB1077BD9B3241B1ULL + 0xEE91B783A69B854BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8DB9EA90FE025497ULL + 0x8781F1DFD6525CB7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x85BA4B187CEEE609ULL + 0xD5A99BC2F771BF19ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB60EBFBB3E6FF1FBULL + 0xF4EE7FAC332C0E3BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE47682B99EA44417ULL + 0x85246E4A9F2F200DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB37F664418C10B6BULL + 0xC41006AB8E2B08D5ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4753U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3799U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4517U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 4262U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 12U)) + 4204560462077827182U) + aNonceWordK;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 47U)) + 6572370199668594039U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 35U)) + 15958999876732622825U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 19U)) + 9969349486879280377U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 24U)) + RotL64(aCarry, 41U)) + 15450238998293956181U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 29U)) + 9128619863683138259U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 5691270563628979565U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 5901029710568933106U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 51U)) + 10442738941988588834U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3508116020325721993U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13221917083569767259U;
            aOrbiterF = RotL64((aOrbiterF * 6845108555710135357U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11627915460377128176U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17858261365514253433U;
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4294837988806295989U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11242915481585070249U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 17540688242763829319U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13030663829236027109U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7451948220723185149U;
            aOrbiterA = RotL64((aOrbiterA * 5191778587712222029U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5575508866505031037U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5161096033789876794U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 16843827915802461797U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3980482740649505122U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11188906150207270241U;
            aOrbiterI = RotL64((aOrbiterI * 408550837615188413U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4435504916461645189U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9970252853543702833U;
            aOrbiterD = RotL64((aOrbiterD * 5829143716916091997U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3766347619186305854U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11004616087340082895U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 14469267845747063735U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17600791542296175812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2556224430252009744U;
            aOrbiterB = RotL64((aOrbiterB * 14469426539907112137U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 22U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 6U)) + aOrbiterH) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9361U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 10499U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8547U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7051U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 19U)) + 1042610313571524121U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 3505725321008825582U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 52U)) + 12584654563843782991U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 23U)) + 6645399144515770935U) + aNonceWordM;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 57U)) + 3608978423753715584U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 8089198857670370983U) + aNonceWordJ;
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 15207251813516399879U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 53U)) + 9579268660105824516U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 16055044469473802812U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 583811872609805949U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7027491967970873942U;
            aOrbiterF = RotL64((aOrbiterF * 12686754713465826139U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18256061823189677508U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12708429127816136937U;
            aOrbiterK = RotL64((aOrbiterK * 12593886633108075321U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12169216645156306078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12694325407567795065U;
            aOrbiterG = RotL64((aOrbiterG * 3711789483877261899U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16109994660203297503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4234704064165718913U;
            aOrbiterJ = RotL64((aOrbiterJ * 730085881474787681U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14119541943554602878U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8777769004811352951U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2556957257736134223U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15642663488392549609U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11594468530833278624U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 6639306656361601143U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7365350535791499871U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5965170981970155956U;
            aOrbiterE = RotL64((aOrbiterE * 1898702752753066851U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9115232101451815522U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9433983580038990072U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 1951249217843992179U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8810565477444156140U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12081286530401844859U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 1991383259486140229U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterI, 42U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterG, 36U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15813U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11959U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13127U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 14236U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 60U) ^ RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 4U)) + 4752759164691497960U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 12088872623537639782U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 19U)) + 3734943577379734227U) + aNonceWordI;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 8854778183012444234U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 23U)) + 16948373492893967275U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 35U)) + 7962415690046184385U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 1872682375669714454U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 54U)) + 7776801806943853566U;
            aOrbiterE = (aWandererE + RotL64(aCross, 43U)) + 16665439117257230732U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11088186766134265676U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10850237991780969350U;
            aOrbiterD = RotL64((aOrbiterD * 7547414856143095121U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6464817712131305812U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 244557182884209844U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2394270354887582889U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13261563971157415841U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2323811103717827362U;
            aOrbiterH = RotL64((aOrbiterH * 11483723582415081925U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12338803568475493422U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2811342930111104982U;
            aOrbiterA = RotL64((aOrbiterA * 5020981755203607757U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5554497011738996057U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12712169745460598698U;
            aOrbiterB = RotL64((aOrbiterB * 1985586486150377769U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17415058661427002973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9430421222715343818U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 10321140659099470811U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3926618548181233180U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 6172453297026957838U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 1161551082037835233U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8633288765997226004U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17270881130844274342U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8888559940161770791U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12232950994807835262U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15352600312956742750U;
            aOrbiterE = RotL64((aOrbiterE * 6140396356904933003U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 52U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 18U)) + aOrbiterH) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterK, 24U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18962U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21739U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21229U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17127U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 14008824488073394623U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 39U)) + 13317978415866411468U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 23U)) + 13209180141897453900U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 43U)) + 11870521586865233578U;
            aOrbiterK = (aWandererC + RotL64(aCross, 29U)) + 8052156380448047385U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 43U)) + 12158131176743680605U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 14674467487607719347U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 6U)) + 18055496790566231147U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 3838105585041578784U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2839568255183054418U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11933612922864258179U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7571964469321160347U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6289849094151630580U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2640344350528492271U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16306175266267657791U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3339898380394883600U;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15017076663742800002U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8973064296077602496U;
            aOrbiterB = RotL64((aOrbiterB * 9309462227233615761U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17580319233338139859U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14063208878807603874U;
            aOrbiterG = RotL64((aOrbiterG * 16601475239075164585U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13326130855721009942U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12843186026737544416U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 4975848122837321619U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14102887715772847499U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14495942314329085733U;
            aOrbiterI = RotL64((aOrbiterI * 4236795312917583565U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11564857125101669667U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17435970784822000464U;
            aOrbiterF = RotL64((aOrbiterF * 1472691848852381173U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16561390130356833062U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 9952805588514363872U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 3720874990001086597U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererH = aWandererH + (((((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 58U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterF, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25075U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24641U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24363U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 27028U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 3561491146322798260U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 7075025056181885339U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 14U)) + 9230910887904171613U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 4119781172609908917U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 5U)) + 17155609083870983149U) + aNonceWordK;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 39U)) + 2423018561430181695U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 23U)) + 12957280305617615744U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 27U)) + 2461704174772065813U) + aNonceWordG;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 10U)) + 7907123257849391997U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7257868138318960007U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16425903703085702285U;
            aOrbiterB = RotL64((aOrbiterB * 7996935869077231999U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2990822664594079467U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5654819006718953817U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4465096036756887801U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12183676471235678779U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15026286960542123922U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17199049329995315279U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12169080607071830522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2906296852254787499U;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3029858695410344584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14406410317495954566U;
            aOrbiterD = RotL64((aOrbiterD * 9663780721657983421U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11048818178401163861U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13622063920319445043U;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2642646089141233277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12761571777929273548U;
            aOrbiterK = RotL64((aOrbiterK * 5518252696078700127U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7753802695131502382U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8510425459525030222U;
            aOrbiterA = RotL64((aOrbiterA * 12412361423636026483U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13522645164493316722U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1437430302489702713U;
            aOrbiterH = RotL64((aOrbiterH * 14019316635365783545U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 4U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 34U) + RotL64(aOrbiterI, 41U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29488U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 30109U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30606U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30104U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 10U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 29U)) + 3684295017013759987U) + aNonceWordD;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 6740408842457292881U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 43U)) + 4563975890702399441U) + aNonceWordL;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 23U)) + 797804144825287940U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 2763779540450101303U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 37U)) + 13211846164102089685U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 10U)) + 15214578447281401982U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 19U)) + 13745208628754232427U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 17358621225969190747U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 779739369960480023U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4370963533701407813U;
            aOrbiterI = RotL64((aOrbiterI * 3123135216876641039U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6061333005507739975U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3589705340762734456U;
            aOrbiterH = RotL64((aOrbiterH * 16499293983611196967U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10607697666369230567U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9356757995305239271U;
            aOrbiterD = RotL64((aOrbiterD * 10945513661439954731U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10093033335903048138U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 11037328061699834100U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 11189760551792389605U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 558431161176115540U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17795680919453449358U;
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6096779391116214109U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17594243286880690775U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 12655610181937429915U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15414704802398002423U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 18040588240488602196U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16344249573086571225U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14636298592697156931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9677305688594936561U;
            aOrbiterK = RotL64((aOrbiterK * 8354776999961642997U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16408025751875050713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10018342878801454965U;
            aOrbiterE = RotL64((aOrbiterE * 10349132962708124117U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 60U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 34U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 38U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 52U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Rugby_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x92EBA40A55943C9BULL + 0xFB69B7B42C1FDDC6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBC7BE5A1C29D7149ULL + 0xAF8B0F95C6B17F47ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9A1DF522C51DA6C7ULL + 0x8B5829E1B15F58F5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBFE4A1913441A9B9ULL + 0xB1A6663AE5F7F384ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE8FAF2DA7247388DULL + 0x812CBE22005BBF10ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBB9FF85C82B6FAA1ULL + 0xD95EEBC5B065EC40ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB53FC6439284E4D7ULL + 0xA215A4C07DB954DCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9107A8A69EB2322FULL + 0xD0FD7575320349C4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDF0D0E6F9EB294FDULL + 0xA3FF5C002B4F491EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF740AAC8666072E9ULL + 0xE7234DD62BCE1484ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8EF419013846DF81ULL + 0xBD19B4FEF9A70DB9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAE4897DC6D960C4BULL + 0xCBA5F874FE1AFBD2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE1613B0C2BF7D501ULL + 0xB13EEA9685505EF0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x980449336B51E42BULL + 0xD34F177E8039C3C7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF1EEC1AF6A76945FULL + 0x88DA533F48133B01ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF21ACF19C65567D3ULL + 0xF16E028A336D9F31ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4054U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2734U)) & W_KEY1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4728U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4256U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 16200278595895089008U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 4U)) + 1029614154810465897U) + aNonceWordJ;
            aOrbiterK = ((aWandererB + RotL64(aCross, 53U)) + 7129562468705441295U) + aPhaseAOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 14388903902433951274U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 35U)) + 1013568949315967455U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 3128823373497815651U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 11U)) + 14525694606889470589U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14443983602196782887U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12244220415328641190U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052949098014803181U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10477159225338766614U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2842870123078131566U;
            aOrbiterG = RotL64((aOrbiterG * 11522265477555954071U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8621138818955849917U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5038396344400303181U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14636756322207385447U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2768613802894372496U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2027754864051410015U;
            aOrbiterJ = RotL64((aOrbiterJ * 2461322540050569287U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2848088309172056399U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterD = RotL64((aOrbiterD * 9926904679902843055U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9079797279596336139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15424866642305110811U;
            aOrbiterH = RotL64((aOrbiterH * 12912331089970158845U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13751764050290602740U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7694557131324740282U;
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordH) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 6U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8660U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 9585U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8531U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10486U)) & W_KEY1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererH + RotL64(aIngress, 26U)) + RotL64(aCarry, 57U)) + 7270044678408187242U) + aNonceWordD;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 10192278965379756766U) + aPhaseAOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 5U)) + 17568666746676060748U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 14312927531124963037U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 11U)) + 9825825726152087706U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 9696778570255265896U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 57U)) + 17657841352013417228U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16207815085909628439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1752979206374514227U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14182667540650694199U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10456310689643905854U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16127830548663742550U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4355938404839045417U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2940917376003930842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7353596864777649953U;
            aOrbiterD = RotL64((aOrbiterD * 7499468723171042005U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12725092740446150705U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5791296650856037010U;
            aOrbiterE = RotL64((aOrbiterE * 760379251950502133U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1200130368046206150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16689604428598558547U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13815324235939996623U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 14359561591103730856U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3975025843599045263U;
            aOrbiterB = RotL64((aOrbiterB * 5025047888533298617U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14017901732955607601U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10431526786489555196U;
            aOrbiterJ = RotL64((aOrbiterJ * 10181915874476132407U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12022U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12276U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13735U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12062U)) & W_KEY1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 48U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 2225397913940961213U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 37U)) + 8342544893601343643U) + aPhaseAOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 162922186381417187U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 13U)) + 11660218373710972210U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 14909034764605802354U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 41U)) + 16776955237009701511U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 5834487809188925253U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1498492772767040320U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4161765458781579617U;
            aOrbiterF = RotL64((aOrbiterF * 15535994410289065281U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10511923076962447765U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8575954471692620021U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 12526744988828982731U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6536325446331340573U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1790628986900286346U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5262997114200816715U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2623814807619278590U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11676970995834706612U;
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13836786354224256591U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6293096163612129260U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 8977954126326217153U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4271144764978661248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15938494256992560202U;
            aOrbiterH = RotL64((aOrbiterH * 10004841288382726739U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11038155227307702976U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12408749795071243930U;
            aOrbiterG = RotL64((aOrbiterG * 5527720475032868855U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 22U)) + aNonceWordF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19814U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 21198U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20373U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 19802U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 17454559218352016650U) + aPhaseAOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 8005709669325164803U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 13393741948412816357U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 35U)) + 3665865624348875553U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 60U)) + 8334142570031883436U) + aNonceWordN;
            aOrbiterB = ((aWandererB + RotL64(aCross, 53U)) + 17226066128706139657U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 19U)) + 3319093033121522613U) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6657535603401588798U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5469746182326331147U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11315450342347794329U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17846791786050221418U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15939541003714896288U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1400351482213119809U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12076763190461077406U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3594038213596405284U;
            aOrbiterA = RotL64((aOrbiterA * 10244002692575821495U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8301291631324464622U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8460406137668390582U;
            aOrbiterK = RotL64((aOrbiterK * 9117147929757711595U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7612394867020871200U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8525076134853103975U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5790440201072204659U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11929899088215090379U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7119509166360685726U;
            aOrbiterG = RotL64((aOrbiterG * 1662341427992528823U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5081078459225240607U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17149991983909906705U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 950223374568067343U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 20U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 28U)) + aOrbiterG) + aNonceWordI) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aPhaseAWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23629U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27176U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26537U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 26515U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 60U)) + 12222235191147985484U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 3U)) + 16367317014523328414U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 3511378091284703789U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 15247492830966725949U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 7745995913390407897U) + aNonceWordP;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + 6463593307540108810U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 41U)) + 1101669311005268630U) + aPhaseAOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 12988052764067518580U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17717179747434679772U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10820310705487638793U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11662190906682400416U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6563014073547628748U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 16967910471722117761U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13099094932059419219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16342730862261868847U;
            aOrbiterA = RotL64((aOrbiterA * 10988124108686164829U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16855346813127524624U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6570063128502306944U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11328352033809240501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11640986648833160901U;
            aOrbiterI = RotL64((aOrbiterI * 2895830492089678919U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2675226158571501666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17700531248266458165U;
            aOrbiterC = RotL64((aOrbiterC * 2231403813970188657U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7729597396731910874U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15172374484412053756U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 149009041406406517U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 48U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 28U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28693U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 32380U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27907U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 31368U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 6654158889644956636U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 9045779659363991870U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 29U)) + 3888897662136993491U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 53U)) + 6882016842864459345U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aIngress, 13U)) + 15601891715956172291U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 5U)) + 5176811598629335350U) + aNonceWordA;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 20U)) + RotL64(aCarry, 11U)) + 12519945150889074325U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4552583214397603278U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14225482701804864688U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8526052833180466359U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5485298070606280363U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11237713257388094289U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 11032429223099413011U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14340345895626142788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16275167270553643347U;
            aOrbiterK = RotL64((aOrbiterK * 7308578867128951199U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14041860597556520250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11483155566419547004U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4608508534724289325U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2389196334288832895U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4062682330273866602U;
            aOrbiterH = RotL64((aOrbiterH * 8787682133271101901U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5655656046585592034U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7977947821249746880U;
            aOrbiterF = RotL64((aOrbiterF * 10082104644185964787U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterF, 12U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordL);
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

void TwistExpander_Rugby_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C08869B7DE09253ULL + 0x9A7DCF55025D81B4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x911CF68E59BA745DULL + 0xFFE774B4DBCF385EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF37BA50E6D148D65ULL + 0xBB5AAE6CD0D04971ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x90387A423ED97439ULL + 0xA4E7272D46EEAC88ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCC63C08658662B7FULL + 0xD8B0E292CC6E8A21ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB16B62208E9238EBULL + 0xFF8E761CEBAA2DDCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x85C018BD61433675ULL + 0xA02A529B3349308BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x96413AF735548A83ULL + 0xD40A00077850FFE6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8021189CD385AE99ULL + 0xC86973960EF02E3CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD09BFC9D883ADB81ULL + 0xF96F11CB94EDEFBDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDB28ACBA9EA2CCA7ULL + 0xE2B868C55A61DF1EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE2F058A3F77506C7ULL + 0xB1830B9CDF981756ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB1A488D5B0506B4BULL + 0xD1D7E12DA66974FFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE4275B3189B1AE63ULL + 0xA15680CE280EE809ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF468D154E3E5798FULL + 0x8BDA7E626A6BDAEAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD11CD290B951C461ULL + 0xC9DB01F921E9EBC2ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 399U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4441U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3795U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 516U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 20U)) + RotL64(aCarry, 13U)) + 16651241552253078315U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 11U)) + 4558144676982478003U) + aNonceWordO;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 8814884320080367550U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 16011579668555672117U;
            aOrbiterF = ((((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 4738918668759862438U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12526083125540985108U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8048723561746000552U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11914807994597963481U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1082218464034639039U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 8432043246965946816U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 7801965585991025451U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9982080524048636852U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6720069955755215919U;
            aOrbiterJ = RotL64((aOrbiterJ * 1025046364205332059U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1019035028070247757U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7360619079463870467U;
            aOrbiterB = RotL64((aOrbiterB * 6623074813047915863U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10893918488381348474U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 1390297670907738019U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 11909657437658597735U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 34U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8455U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 8868U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9521U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9815U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 7960325128608297381U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 12773836012104052042U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + 3173972621347773016U) + aPhaseBOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 3708401356314308171U) + aNonceWordF;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 950774285720019449U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4170092315705438265U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17000449130864980747U;
            aOrbiterA = RotL64((aOrbiterA * 7710635557693533263U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8793910540062893860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 520277969543516469U;
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12762214857389827271U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2932451184340207695U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7513337346940091655U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 11062179998786293839U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7919119215271524178U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9053677007180081359U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1774988449597115155U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3799792889466518953U;
            aOrbiterC = RotL64((aOrbiterC * 17512791286490623455U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 18U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 60U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16349U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 11130U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14469U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 11643U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + 13650869943246163567U) + aNonceWordG;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 47U)) + 3435284932011770999U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 12388155658186776579U) + aPhaseBOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 2374345913955712039U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 47U)) + 6095094526980292156U) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4965147025852444174U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3261881216269075298U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4874733445914960785U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4939780217097329222U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 3019862009792676287U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2452316208025448747U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 901910626217143974U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3647055146712366383U;
            aOrbiterD = RotL64((aOrbiterD * 1792602402476450009U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7731765438957392967U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13409819457393479741U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3345078200262410715U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5415832109107794258U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8876738832313114471U;
            aOrbiterA = RotL64((aOrbiterA * 1304277600444504135U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 54U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20064U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16947U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19625U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18112U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 3U)) + 8793908991006073956U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererB + RotL64(aCross, 19U)) + 2932916283348441943U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 11069042087940968262U;
            aOrbiterF = ((((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 14369628676782894441U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 46U)) + RotL64(aCarry, 11U)) + 8602903272780978282U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 3827036107178568820U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8905245209036772489U;
            aOrbiterA = RotL64((aOrbiterA * 5744017326197157667U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13331387530760017893U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9880107580289737823U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10302652857542703753U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10199619040626900278U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2466307560891374281U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6295342978834217571U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13973403407981259448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2851460278409385243U;
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10365453393815690776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2382382358987358791U;
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 56U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 36U)) + aOrbiterA) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 29U)) + aNonceWordF) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25023U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25278U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26701U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 23203U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 34U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 9435962834163239322U) + aPhaseBOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 21U)) + 10524704356081318973U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 7403401305665208680U;
            aOrbiterA = ((((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 7525414805023556493U) + aPhaseBOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 29U)) + 1116686470029070951U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13257612299137802420U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9181543003986598283U;
            aOrbiterD = RotL64((aOrbiterD * 18162011316880411235U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9739384852307501107U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11308402900229016057U;
            aOrbiterG = RotL64((aOrbiterG * 12690186771773188967U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14935167593705272337U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7171824007631943535U;
            aOrbiterI = RotL64((aOrbiterI * 4839974427616194289U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8068411284829563567U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12350207458513447578U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 813973258659041895U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17039236343991574134U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 18291683592714999632U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 7771718817924840713U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aNonceWordP) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aNonceWordI) + aPhaseBWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28070U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27325U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27864U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31039U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 3U)) + 6521330037475130256U) + aPhaseBOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererF + RotL64(aCross, 29U)) + 12611880456055428940U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 12061611078130934708U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 43U)) + 1558112410801116984U) + aNonceWordK;
            aOrbiterD = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 10509115227850160786U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4045915960688792066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1196541286513243082U;
            aOrbiterA = RotL64((aOrbiterA * 5454309408259753479U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15564991032722373702U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4897765238703641798U;
            aOrbiterB = RotL64((aOrbiterB * 9693901276712946763U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12327429514907752733U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6189189797708711636U;
            aOrbiterC = RotL64((aOrbiterC * 9017615866338877651U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6374267075282018852U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 1888758503831341439U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 74387714918264257U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14956857689299491800U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14879361107223331957U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9166712966729591953U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + aPhaseBWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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

void TwistExpander_Rugby_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB603081C3F67CBADULL + 0xF0A24C30D33A0521ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAE57743E3017A9FBULL + 0xD5A94BEAB5705667ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC502047E57B99CABULL + 0xF56F979C6831D4A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAA733D6B3A1F6657ULL + 0xCDB15289CC036D05ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB530A01B127E472FULL + 0xC641AA3FD85DCF4EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE35B1437422D3F29ULL + 0x8E26F08886BC2DD0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEF2A27A0415D420DULL + 0xF3C43DF8BDC8EA7EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFA9CEFCE7B62234FULL + 0xB31CF32851A83D2AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE6D550287648CC47ULL + 0xD9309BF72C7D6660ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8526201E8F20CE01ULL + 0xB7AABA0E268777B4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBEEA984F15D32BADULL + 0xC20CA18EDC72E90DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAA4BA6581AFB30EDULL + 0x96E59AD63E0E3800ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC31427B97E475D69ULL + 0xDE9E57DB48AF96EFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA7F3396519DF421BULL + 0x9F315B66D8286851ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFCD9CE4D022AB29BULL + 0xE6BF818ECFF5B547ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x84F0D6C1F1A1FAF7ULL + 0xFC9D74ED00F05151ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 882U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3756U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6144U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 5860U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 35U)) + 12583180859826261500U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 50U)) + RotL64(aCarry, 53U)) + 9067093488553721468U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 12173106198862881754U) + aPhaseCOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 11333491014394592654U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 3511883526940919554U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 19U)) + 7416810692106273044U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 60U)) + 8341174972619784110U;
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 2220852854836962979U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 39U)) + 8090781422229383825U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2338801236599102223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12484514711848308104U;
            aOrbiterG = RotL64((aOrbiterG * 10364216764253366067U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13684861340589131816U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7634198650894837690U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10240326122201201762U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8758703497719125901U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4162814763739453934U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2766504649149048469U;
            aOrbiterH = RotL64((aOrbiterH * 16731843453895178671U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11051393030148769655U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17687055068651386665U;
            aOrbiterA = RotL64((aOrbiterA * 1042927176246229537U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3353615315436983420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5971640796220306310U;
            aOrbiterJ = RotL64((aOrbiterJ * 15804313508835034807U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12299773092762384765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7435804907797063411U;
            aOrbiterE = RotL64((aOrbiterE * 9848139805288165965U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8735783937125735699U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11903126115475835615U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 16942088822124940265U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4427166023462475475U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6011733469446008137U;
            aOrbiterC = RotL64((aOrbiterC * 17298067225913923517U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 22U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterJ, 30U)) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 24U)) + aOrbiterJ) + aNonceWordO) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15958U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15082U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9484U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 9373U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 13U)) + 1866656689936219099U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererE + RotL64(aScatter, 39U)) + 2312314528139448289U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 3554037526469185237U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 405707755060974111U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 1862976326004007697U) + aNonceWordL;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 12992483065443288263U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 43U)) + 3793854946371595197U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 28U)) + 4244007978867369382U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 51U)) + 10280867500312580308U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 472563452959164242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12041770406895816553U;
            aOrbiterJ = RotL64((aOrbiterJ * 17811798500132002631U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6118634015704900486U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13637107920449233307U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 17712028184714868053U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16673735670669318830U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8602681273646630496U;
            aOrbiterE = RotL64((aOrbiterE * 6995213887710749241U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7683264695930369476U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9146674871199188218U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7403427067419261981U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3012935612827493084U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1259789268731661945U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2372843620327050137U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5623690455471160780U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18355567776031865462U;
            aOrbiterH = RotL64((aOrbiterH * 9553862670107886679U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7705134893833304792U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4435192506444773834U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 5249651218395299501U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6204683785806409075U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17886971535016484255U;
            aOrbiterB = RotL64((aOrbiterB * 6047216474762933535U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4430578901091376829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 607557685798141547U;
            aOrbiterK = RotL64((aOrbiterK * 12342665567201483107U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16480U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 24560U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19927U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22431U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 34U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 4U)) + 12669015908335980355U) + aNonceWordA;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + 5438715179868613192U) + aPhaseCOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 47U)) + 13172104448184536460U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 13421421503244744803U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 18U)) + 13327113302994856582U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererD + RotL64(aScatter, 39U)) + 4671768205922454413U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 5355759962838579929U;
            aOrbiterB = (aWandererE + RotL64(aCross, 23U)) + 6691720614265406851U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 7063906424700911378U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17328616394166672263U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1542940602574207068U;
            aOrbiterA = RotL64((aOrbiterA * 8981679306319627975U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7203866278803132454U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 993485696233139264U;
            aOrbiterK = RotL64((aOrbiterK * 11609009908810366447U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15659679028507488331U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18321361454094675842U;
            aOrbiterG = RotL64((aOrbiterG * 3966860765622641843U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9633319822696783352U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3496559332232402963U;
            aOrbiterD = RotL64((aOrbiterD * 7772060229838162977U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1918349708324205526U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7701088402761359134U;
            aOrbiterE = RotL64((aOrbiterE * 9649485438465644795U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6006824348814439686U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 18088375375347012557U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 12801082943086128385U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12816533373478543584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17951880253818836433U;
            aOrbiterF = RotL64((aOrbiterF * 8935839101517220201U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11311632024372748238U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9891349164779752351U;
            aOrbiterB = RotL64((aOrbiterB * 11405973752233193209U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 711130292000437038U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17818800917771709681U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 10567029732245868263U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 34U)) + aOrbiterE) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29293U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 28545U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29255U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24959U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 16451272412693907816U) + aNonceWordB;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 19U)) + 10099485419723255462U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 28U)) + 17668900099534923192U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 5497093724143181753U) + aNonceWordJ;
            aOrbiterC = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 10354044773550071706U) + aPhaseCOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 23U)) + 12728258851198019099U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 14U)) + 4144050505314242618U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 5U)) + 14133805325480076530U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 37U)) + 308863673210602899U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11741180130160569753U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12926863156769180448U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9726030996091054939U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 211920854786494259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9164711974854618892U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6667377062281954219U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2603737166987437649U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4559040002406721850U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1749875480850675109U;
            aOrbiterH = RotL64((aOrbiterH * 15822640067349481089U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9555365165561936366U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18289733999504213574U;
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8727162691639622461U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 291406782452963706U;
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8294911802626492257U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15853578397277298548U;
            aOrbiterK = RotL64((aOrbiterK * 13256191781365357747U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11535146194939658681U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2177540476748375661U;
            aOrbiterB = RotL64((aOrbiterB * 15791341922007841029U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2705306323728084136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17617871830709148043U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3449981219502809255U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 56U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aIngress, 52U) + aOrbiterK) + RotL64(aOrbiterI, 6U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 36U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Rugby_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA3C8D5848EB4ECB9ULL + 0x98234CCE1274139EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD0BC940D83D85D69ULL + 0xB546C40962EA46BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF8554DB34CCE6763ULL + 0xEA48D405FF22F86BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBFD36FCCA422D60FULL + 0xE5C2286B06962957ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x92DCD7DB07F7C3D9ULL + 0xCA244A398C2A08A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x816D199DF64D9375ULL + 0x941C524CDB618F99ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF360A90D41A67173ULL + 0xFB532CC2B3560DD1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x93EED31FAA68864BULL + 0xD01B3767DC14C75BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9ACB02CA8BD2132FULL + 0xA65481C2873F2947ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x946F7D1E8095D339ULL + 0xAC3C522CEFEF9AFCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE2DC028C87763A23ULL + 0xB0A6B9A60C018CE0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB0E6C000B5E18593ULL + 0x83D55C0935880E6EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF929B21F15EFA3E9ULL + 0xD8A0DFACF37E38A7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE090AEE6745C96D1ULL + 0xBCED5F6696FB8282ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x839AAC434D9D6FE3ULL + 0xC38A0A54629A29F4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x96F29523DA3C051FULL + 0xD3E6767103F74E09ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3597U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1590U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 580U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 5208U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 5U)) + 9446153639709651566U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 10550762260670758167U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 7062634922142578383U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 9178499097812764515U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 19U)) + 6887103379773525538U) + aNonceWordP;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 23U)) + 6239750312052010257U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 27U)) + 17645022614523287959U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 53U)) + 3639618183259408272U) + aNonceWordL;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 37U)) + 3131737117548745095U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 12U)) + 7253994382396406554U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererD + RotL64(aScatter, 51U)) + 15217993711938379561U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12594152227603630033U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11250170200489647869U;
            aOrbiterH = RotL64((aOrbiterH * 546800378327864723U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12936942656624279424U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10990736056052106149U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12787293075893090465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17154990205620778151U;
            aOrbiterC = RotL64((aOrbiterC * 10031369940028159521U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1270827262969060301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17337623431665013136U;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 830330490987911853U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6828309232554560547U;
            aOrbiterF = RotL64((aOrbiterF * 9742464176986145819U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11470087853413986203U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10470148870747884420U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6766079738799967443U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18315536891901859637U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12264670822285914271U;
            aOrbiterB = RotL64((aOrbiterB * 5841574505408674119U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10931842095884524879U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11134871340959676257U;
            aOrbiterJ = RotL64((aOrbiterJ * 11714837622285605745U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11484168476761306078U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5964766416973454097U;
            aOrbiterK = RotL64((aOrbiterK * 14721123403032510803U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10646362765367117994U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8994267196877016381U;
            aOrbiterD = RotL64((aOrbiterD * 17386417559346134797U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16797547458402042464U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9446153639709651566U;
            aOrbiterG = RotL64((aOrbiterG * 567585472220695323U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 37U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + aNonceWordE) + aPhaseDWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 14U)) + aOrbiterI) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 10U)) + aOrbiterD) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8594U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 8630U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8968U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7024U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 38U)) + 18302975933754610273U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 27U)) + 16736972646771456082U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 29U)) + 17389406266488137442U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 5252511566486165539U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 41U)) + 5730715427422747640U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 20U)) + RotL64(aCarry, 13U)) + 6412695646456045825U) + aNonceWordN;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 57U)) + 9539701605708994494U;
            aOrbiterB = (aWandererE + RotL64(aCross, 51U)) + 18355107116412945722U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 43U)) + 11735742491750132942U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 12363819388562658842U) + aNonceWordI;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 5861430292304371543U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15027487084595017708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7012850020745791926U;
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11904871669287886120U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3856004502263742700U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3705931243173921893U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10334871178498711485U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12305785390539209389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 18057980996551978823U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4850564181113470859U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3229431819292153014U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2994716629242460094U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 1029427328395257917U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9796307843453735512U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2957260393651252432U;
            aOrbiterD = RotL64((aOrbiterD * 7261055869794739609U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4060469664218866340U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17462081697889685330U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 7712009170974461225U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13638660073917821172U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15202349592659062565U;
            aOrbiterK = RotL64((aOrbiterK * 4514326257446024301U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12071949111168967041U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11930843273199806728U;
            aOrbiterB = RotL64((aOrbiterB * 16229663295689525137U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11294220104731500296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 440743185210586759U;
            aOrbiterG = RotL64((aOrbiterG * 14810195235168807229U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8514240764798061804U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18302975933754610273U;
            aOrbiterE = RotL64((aOrbiterE * 1972439346780950873U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 36U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 58U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13867U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 15095U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16286U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 15442U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 6U)) + 8793908991006073956U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 47U)) + 2932916283348441943U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 39U)) + 11069042087940968262U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 14369628676782894441U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 8602903272780978282U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 30U)) + 3827036107178568820U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 8905245209036772489U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 53U)) + 13331387530760017893U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 13U)) + 9880107580289737823U) + aNonceWordA;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 27U)) + 10199619040626900278U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 41U)) + 2466307560891374281U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13973403407981259448U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10365453393815690776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2382382358987358791U;
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5058198848163792422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10500434740387593487U;
            aOrbiterA = RotL64((aOrbiterA * 5946747708776079787U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11289798395177667084U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 14327152153231286666U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 18155778059595245561U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8065137263811956313U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3865153574847924816U;
            aOrbiterE = RotL64((aOrbiterE * 9495741102667755161U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18102279969722473375U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6306428427188742325U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 17826782872351406167U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16953348204663693724U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11950791817032898613U;
            aOrbiterB = RotL64((aOrbiterB * 1498946055469611133U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11980823193543752994U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17845490308799454871U;
            aOrbiterK = RotL64((aOrbiterK * 16385153013485463791U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5566398755702887071U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10308378271388889968U;
            aOrbiterG = RotL64((aOrbiterG * 142732084484961281U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6717846700455219260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8297225372883997017U;
            aOrbiterF = RotL64((aOrbiterF * 14102812043481327907U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12249337046267666603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8793908991006073956U;
            aOrbiterJ = RotL64((aOrbiterJ * 5851229209188473467U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 40U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterI, 40U)) + aPhaseDWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 18U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16995U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18684U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17079U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 19923U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 26U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 5480870806135400132U) + aNonceWordM;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 8034874599430768743U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 20U)) + RotL64(aCarry, 29U)) + 4006919843736863767U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 51U)) + 2988069748674633718U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 11U)) + 12347295651973135786U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 43U)) + 14152683894431568192U) + aNonceWordE;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 41U)) + 15765143815254196598U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 35U)) + 10473067082331244233U) + aNonceWordL;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 18U)) + 1089466925383677249U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 13U)) + 13215039929873682230U;
            aOrbiterG = (aWandererG + RotL64(aCross, 57U)) + 3957997712247961479U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10023907397941685546U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14593012591254614353U;
            aOrbiterF = RotL64((aOrbiterF * 17111300092082154687U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13353797968154036726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9259966668512102858U;
            aOrbiterA = RotL64((aOrbiterA * 8326732574268308221U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10757861831070349321U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10530223113483866178U;
            aOrbiterJ = RotL64((aOrbiterJ * 11269177745265396583U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7554320926405521865U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6978052067277966996U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 18020134738536217801U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1053695861967171420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15980734683539854451U;
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17041258393808061556U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12846551858751995530U;
            aOrbiterD = RotL64((aOrbiterD * 9303891433380993639U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14617434286683320666U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3999309956180741302U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15037707937050015205U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13452627760403094126U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2633241575260427158U;
            aOrbiterG = RotL64((aOrbiterG * 2638570213290747581U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15575035993965639421U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7829837426112185905U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17059814556114938275U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12565466096663867876U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4845209979900289818U;
            aOrbiterC = RotL64((aOrbiterC * 14990494169374347835U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13472490162287247012U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5480870806135400132U;
            aOrbiterI = RotL64((aOrbiterI * 9150331893094034245U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 14U)) + aOrbiterE) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + aNonceWordP) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterC, 52U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22417U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24775U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25115U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25378U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 60U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 1142447269198373880U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + 10581460640040336191U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 19U)) + 14703062773878202900U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 46U)) + 15737525756286914746U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 16178774478273186999U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 2514897053906809160U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 13702496607592508464U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 18030885275418337965U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 43U)) + 5241783876161655984U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 2807052676283587925U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 14U)) + 8022804576763271327U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15597099852232205860U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1538435607932096400U;
            aOrbiterK = RotL64((aOrbiterK * 7900752511710516981U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11147868774413615365U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9325213746830411568U;
            aOrbiterH = RotL64((aOrbiterH * 561819005818948769U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13792300423550555634U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3134856508983945719U;
            aOrbiterG = RotL64((aOrbiterG * 4271845067763664863U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8654966018053784882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8937113935476779267U;
            aOrbiterC = RotL64((aOrbiterC * 7386875687217705855U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4135676350355234788U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11407912615743682678U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 2773506587480714695U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10966950663872392059U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6686634993700944582U;
            aOrbiterE = RotL64((aOrbiterE * 2509459942163678241U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14154407529749257990U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18054640398549782388U;
            aOrbiterB = RotL64((aOrbiterB * 7830759861389060149U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14623473030642960240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1857945571104460086U;
            aOrbiterJ = RotL64((aOrbiterJ * 18039903315045620079U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17650774450811065797U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9458168381246672881U;
            aOrbiterA = RotL64((aOrbiterA * 3452665113988737563U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16604923466236483242U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12447748535184711684U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5982708155382249061U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9589720286549780720U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1142447269198373880U;
            aOrbiterI = RotL64((aOrbiterI * 8176719948031280789U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 48U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 6U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 50U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31929U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28275U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30296U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 28669U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 34U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 2617613537256538553U) + aNonceWordJ;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 23U)) + 16642868916835132715U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 20U)) + 10860291124337073254U) + aPhaseDOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 35U)) + 6432511273906902472U;
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 7505375005848241910U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererJ + RotL64(aCross, 57U)) + 11086616004678821329U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 13U)) + 3298830587569881951U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 30U)) + 9775143140064220979U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 37U)) + 4147601326580823120U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 12245920269898100415U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 11U)) + 8391940489176734499U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17876893379544668477U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18301882058180370541U;
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6869225862715140102U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15404118372589259800U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5766851935950389915U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17757381020518233814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17677969146092374455U;
            aOrbiterI = RotL64((aOrbiterI * 3469432916562405063U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15783378556632870114U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5792858258663697864U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12008981883482080427U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11737803388202260296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16001927091970715330U;
            aOrbiterG = RotL64((aOrbiterG * 3062030309852922061U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1749586939123286632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6169421068855905938U;
            aOrbiterB = RotL64((aOrbiterB * 12374789910763348695U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10073586820719728062U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17744171227198661555U;
            aOrbiterA = RotL64((aOrbiterA * 10658375268803957647U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1149819647337612792U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7725598665625892006U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15097586655234391559U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13930096050550704122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3632241034947389647U;
            aOrbiterC = RotL64((aOrbiterC * 8442222389196610427U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17933893495867517142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7888594392078082482U;
            aOrbiterK = RotL64((aOrbiterK * 9809847720610861237U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10805303827043372168U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2617613537256538553U;
            aOrbiterJ = RotL64((aOrbiterJ * 3940471942234248791U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 52U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 26U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 52U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 26U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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

void TwistExpander_Rugby_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9643735B617F46E7ULL + 0x9B48B878DA180187ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD3D4EEE1A1AE7171ULL + 0xAC97F5E31D8D9840ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x95D4A3FFC98DBBDBULL + 0xCA3BD63B7E265AFAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF04D0CD38A5D7851ULL + 0xDAF7E447877B7531ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCE1E637729E17003ULL + 0xA66D47ECD0EED4E3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x98BEDF33A8247A31ULL + 0xC67ED9AF4A6F9973ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8D075C50F19820ABULL + 0x93801A04D96F7604ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC7C4BB2CAF9F3783ULL + 0xAE48029472FD3D09ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDA184B9130632D7DULL + 0xF92D06CE972F94F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9018B00F6E24ED5FULL + 0x9FFE6902F26A3F4EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCFD7349AAEE86EABULL + 0xE41C6F1B48EE5714ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB94E861A18E5B3F5ULL + 0x99E3489A896BA70DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB714670637500BB7ULL + 0xF627A48A5FE7E91CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC576591F6A2B49A1ULL + 0xA3E5D108E89D53C8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE0D250FABEE6C75FULL + 0x89411964D42CE111ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8B1D1F866D13C6FBULL + 0xC03EDFF960DDCD59ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2812U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2487U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 340U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1288U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 40U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 28U)) + 1888427424966603593U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 3U)) + 5436761445660415091U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 17322876217962143270U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 19U)) + 9728299982740564979U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 39U)) + 301720335271716921U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 35U)) + 8069685428854814396U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 21U)) + 1973715500949100991U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 87666408799854155U) + aNonceWordH;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 41U)) + 12195436904339035245U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 11U)) + 4578742069143400295U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 13U)) + 7828776048774876484U) + aNonceWordA;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17203146364542781833U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16913369550858890466U;
            aOrbiterA = RotL64((aOrbiterA * 13534417587921978507U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9632761514552265402U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9106637671877341286U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9073709119482640391U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15423680889126750876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6087310684583331882U;
            aOrbiterH = RotL64((aOrbiterH * 8964465129744898619U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5420955876411796789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14166807419730848032U;
            aOrbiterK = RotL64((aOrbiterK * 442659738632823751U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8118312450347026824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4253043584558403086U;
            aOrbiterB = RotL64((aOrbiterB * 5651748455190536467U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8810774678371762700U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12218479555589447835U;
            aOrbiterG = RotL64((aOrbiterG * 11026364205248516355U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11389930523582876358U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16334420553471379915U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 13830132212033904777U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18201289372553710279U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7196540389657785361U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13058135202554889791U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2601046573550065116U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2243003381737071984U;
            aOrbiterE = RotL64((aOrbiterE * 10518763530499878945U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6058992247656841580U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10083863011670540073U;
            aOrbiterC = RotL64((aOrbiterC * 17908394295613117155U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8505005026063156940U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1888427424966603593U;
            aOrbiterI = RotL64((aOrbiterI * 18298382581929885653U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 10U)) + aOrbiterJ) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterG, 6U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7855U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5918U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5656U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6815U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 42U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 54U)) + RotL64(aCarry, 39U)) + 5576732410244514238U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 13U)) + 2833808925935929629U) + aNonceWordH;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 3670188682914544792U;
            aOrbiterF = (aWandererC + RotL64(aCross, 47U)) + 15759072378887814995U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 41U)) + 13934007231137439994U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 21U)) + 11022225696007690512U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 37U)) + 16989177104453635790U;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 9256930045263527091U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 30U)) + 17788596104417068290U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 51U)) + 17044369456673337625U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 1310908395523250343U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12067065689034065422U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15130844248737512262U;
            aOrbiterC = RotL64((aOrbiterC * 9409499577465934107U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14532689204495587494U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8198147292120244178U;
            aOrbiterG = RotL64((aOrbiterG * 1418356389507740991U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5485494458627163347U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10830008207150307611U;
            aOrbiterE = RotL64((aOrbiterE * 6526039534042499457U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17770065502486618029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6397859353395335459U;
            aOrbiterB = RotL64((aOrbiterB * 14286997752368893825U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5128700697381508319U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7103394110057060499U;
            aOrbiterD = RotL64((aOrbiterD * 5053680689949149633U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16024401282261796979U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12818445221897253410U;
            aOrbiterK = RotL64((aOrbiterK * 11450004517784155405U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13386978409145916350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16740821954556699503U;
            aOrbiterF = RotL64((aOrbiterF * 5376430209628515105U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 313978038530994953U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1355733685461795345U;
            aOrbiterH = RotL64((aOrbiterH * 15955927322082619735U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12590581077253956064U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2298195367575496005U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 17512801361187006363U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11847450675712272468U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5914296379577670282U;
            aOrbiterJ = RotL64((aOrbiterJ * 14574813500616811367U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16901317262621287065U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5576732410244514238U;
            aOrbiterA = RotL64((aOrbiterA * 4514943876091531567U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 26U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + aNonceWordG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterF, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15113U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 15845U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13730U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 16246U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 60U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 21U)) + 5173905450211892891U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 39U)) + 3555542451908039957U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 11559884700283861559U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 1352524329968738673U;
            aOrbiterK = (aWandererE + RotL64(aCross, 19U)) + 8914206450420616349U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 2251523378498463946U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 53U)) + 9541575923299247038U) + aNonceWordC;
            aOrbiterE = (aWandererH + RotL64(aIngress, 5U)) + 1239854507907214595U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 56U)) + 17698101462598498934U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 51U)) + 12305566971683256060U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 43U)) + 13804545036303215569U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10239749097704329264U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4212214906286320308U;
            aOrbiterI = RotL64((aOrbiterI * 3661436621615751071U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12192418916967430783U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4475514289326450361U;
            aOrbiterD = RotL64((aOrbiterD * 17497164630368757887U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17376102613298827459U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18129393209955439341U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 6404089025014118979U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4014763724300253568U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17325007199676828814U;
            aOrbiterK = RotL64((aOrbiterK * 1420888274815627083U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15480474849292388685U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14357924730184375449U;
            aOrbiterE = RotL64((aOrbiterE * 16723492259068034209U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4335731868597970070U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8296023680394303015U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14027415401430120543U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2807312426993262800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15510369660839648501U;
            aOrbiterC = RotL64((aOrbiterC * 18207954408298333959U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12597844696606519907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7231012798553551535U;
            aOrbiterG = RotL64((aOrbiterG * 2841306785994479299U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 849663631945232360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4002310581470781194U;
            aOrbiterA = RotL64((aOrbiterA * 2148877014350721479U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16067735571435654555U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4607980694199923842U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10401780756830017477U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5346879191913449715U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5173905450211892891U;
            aOrbiterH = RotL64((aOrbiterH * 15360571827429301833U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 22U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 40U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterK, 38U)) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterB, 4U)) + aNonceWordA) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + aNonceWordE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16769U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18773U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21282U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19500U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 19U)) + 8402620908307642697U) + aNonceWordM;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 21U)) + 11347672014525086047U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 2816462912503401876U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 43U)) + 6940159795470696093U) + aNonceWordC;
            aOrbiterG = (aWandererB + RotL64(aCross, 58U)) + 9134692490095883851U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + 4999455497008026526U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 5992451460350651332U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 23U)) + 3417087346651371924U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 3612773820086198270U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 463398077083428570U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 37U)) + 11249391303705089012U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17027535139825739501U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 568131384979596481U;
            aOrbiterD = RotL64((aOrbiterD * 5683451044852895957U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4793712537158004047U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10415170179135963622U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13729564030210361415U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2391473979460065630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4240058362680064261U;
            aOrbiterB = RotL64((aOrbiterB * 12375884373396400889U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9963957011090031698U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3325305624067445525U;
            aOrbiterK = RotL64((aOrbiterK * 3128542681461806309U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2094945647665114693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10703615640774042674U;
            aOrbiterC = RotL64((aOrbiterC * 12641986098450423751U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3768738815518590289U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15021301790376706827U;
            aOrbiterJ = RotL64((aOrbiterJ * 14445850924223550339U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10571246886181608316U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5130325144599151793U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3185251943547657467U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8617523421720966373U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16574597770835250074U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 1759209403428937799U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17474733286551120355U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17914672092861237776U;
            aOrbiterI = RotL64((aOrbiterI * 13657291990878792267U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12856557371623447773U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1636296609747335898U;
            aOrbiterE = RotL64((aOrbiterE * 9286345529656087313U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12588848560509679821U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8402620908307642697U;
            aOrbiterF = RotL64((aOrbiterF * 2269772223506258147U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterH, 40U));
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + aNonceWordB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23656U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24562U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26476U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 26329U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 46U)) + RotL64(aCarry, 51U)) + 13204735390996728477U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 851171359595647173U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 13U)) + 16745304202825290723U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 41U)) + 562392736584913979U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 34U)) + 3244267012529053918U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 27U)) + 17282536111067869133U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 3U)) + 14851130066471729068U) + aNonceWordH;
            aOrbiterK = (aWandererG + RotL64(aIngress, 19U)) + 5256130407952363129U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 39U)) + 2904742485828362001U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 3723346325449225387U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 5344621093694027341U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12919263300833603026U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17989801264160996071U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15468293047311883751U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5022175042377172157U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16684822380107847758U;
            aOrbiterD = RotL64((aOrbiterD * 2834049270263837537U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2740326510600876682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13981423865219318820U;
            aOrbiterK = RotL64((aOrbiterK * 14593082145080056441U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 231945878229848395U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14139797734944312580U;
            aOrbiterE = RotL64((aOrbiterE * 6492256080432266407U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16704102101387552373U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8506734780526852552U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4684566118627414659U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2774630043988894695U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12490034334296488127U;
            aOrbiterH = RotL64((aOrbiterH * 16765455396278233145U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 545238171291436006U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1023872898002379590U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 8626333831510136515U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5065187021047872560U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10391809965648089863U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10912471108849550469U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5576919045471579002U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9761904001375034639U;
            aOrbiterG = RotL64((aOrbiterG * 8612901811320541361U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2001472279505185946U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11576457012366242134U;
            aOrbiterC = RotL64((aOrbiterC * 1070815118051466731U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17713147845216099336U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13204735390996728477U;
            aOrbiterF = RotL64((aOrbiterF * 10889281795183444943U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 48U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterE, 54U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28328U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 28627U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31006U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28018U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 51U)) + 1866656689936219099U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 5U)) + 2312314528139448289U;
            aOrbiterB = (aWandererF + RotL64(aCross, 29U)) + 3554037526469185237U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 14U)) + 405707755060974111U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 27U)) + 1862976326004007697U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 12992483065443288263U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 3793854946371595197U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 4244007978867369382U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 11U)) + 10280867500312580308U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 58U)) + 472563452959164242U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 47U)) + 12041770406895816553U) + aNonceWordN;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6118634015704900486U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16673735670669318830U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8602681273646630496U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7683264695930369476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9146674871199188218U;
            aOrbiterD = RotL64((aOrbiterD * 7403427067419261981U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3012935612827493084U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1259789268731661945U;
            aOrbiterK = RotL64((aOrbiterK * 2372843620327050137U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5623690455471160780U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 18355567776031865462U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 9553862670107886679U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7705134893833304792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4435192506444773834U;
            aOrbiterC = RotL64((aOrbiterC * 5249651218395299501U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6204683785806409075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 17886971535016484255U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6047216474762933535U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4430578901091376829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 607557685798141547U;
            aOrbiterE = RotL64((aOrbiterE * 12342665567201483107U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18258994761911545002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 634391404805006992U;
            aOrbiterH = RotL64((aOrbiterH * 5761143438450180463U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8528044138264666860U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3867692060293315964U;
            aOrbiterG = RotL64((aOrbiterG * 8285164562893231087U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8333438209201978886U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1866656689936219099U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3935928308329865425U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 34U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterI, 6U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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

void TwistExpander_Rugby_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC7BC89624230C47ULL + 0xCC502E08202C2275ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF1D1B5A91BEB8D41ULL + 0xA1393D8E55FF98AFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF2EF6FCD5045D9F7ULL + 0xA8A1879D4706AFEFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x93C82F082AE426DFULL + 0x8F2F0E8AF8BC014AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE84626052AEC53BDULL + 0x92FAD94B63A8238BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE1819ABBC53319F1ULL + 0x868CAD0B6744097AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDB28D2620D3EAB05ULL + 0xB33286EA1055BCCDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB6C4B598AFBB8E65ULL + 0xC8139633DFAE98B3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC9CBFA2CB58A6D9FULL + 0xEE549EE6849F2521ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD1BE8397284C57B1ULL + 0xD583FB4E72D79B43ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB959B387F4DDDD79ULL + 0x9B4F2B7538A49D9AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC77F59FD07B380D1ULL + 0xE791BBAF56E1497EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEAA93AD717E196B9ULL + 0xC45078CCE5B616EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x82683C124E5472C1ULL + 0xAC39FD92DFB754A9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAF85B4BF9DA89F13ULL + 0xD396B6BFD9BCE165ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCA6091A2CCE77BA5ULL + 0xE1C47F479B99D207ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 151U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2016U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2386U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3196U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 14U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 4752759164691497960U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + 12088872623537639782U) + aNonceWordB;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 3734943577379734227U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 44U)) + 8854778183012444234U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 16948373492893967275U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 7962415690046184385U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 37U)) + 1872682375669714454U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 57U)) + 7776801806943853566U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 23U)) + 16665439117257230732U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 11U)) + 11088186766134265676U) + aNonceWordL;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 6U)) + 10850237991780969350U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6464817712131305812U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 244557182884209844U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13261563971157415841U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2323811103717827362U;
            aOrbiterH = RotL64((aOrbiterH * 11483723582415081925U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12338803568475493422U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2811342930111104982U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5020981755203607757U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5554497011738996057U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12712169745460598698U;
            aOrbiterJ = RotL64((aOrbiterJ * 1985586486150377769U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17415058661427002973U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9430421222715343818U;
            aOrbiterK = RotL64((aOrbiterK * 10321140659099470811U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3926618548181233180U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6172453297026957838U;
            aOrbiterD = RotL64((aOrbiterD * 1161551082037835233U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8633288765997226004U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17270881130844274342U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 8888559940161770791U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12232950994807835262U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15352600312956742750U;
            aOrbiterC = RotL64((aOrbiterC * 6140396356904933003U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5614120002595447983U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1920822446545182835U;
            aOrbiterA = RotL64((aOrbiterA * 17049182594382482085U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 625576652179261739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2362773059031414585U;
            aOrbiterF = RotL64((aOrbiterF * 17049048587829564949U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16749690978107177915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4752759164691497960U;
            aOrbiterI = RotL64((aOrbiterI * 8442185754037031199U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterC, 10U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 34U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9583U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9640U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10286U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8829U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 30U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 29U)) + 11210042748013785976U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 53U)) + 4584747303233477454U) + aNonceWordM;
            aOrbiterE = (aWandererH + RotL64(aScatter, 19U)) + 8878765929792969517U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 2172232330280041122U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 46U)) + 8378937026022264016U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 57U)) + 8683007464695824208U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 41U)) + 9564352997357118134U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 11713878436769887528U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 8052917623074021077U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 34U)) + 7720597162792145185U) + aNonceWordD;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 3U)) + 2602847785328475621U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17813669222300509724U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8724263063156573013U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3632927017737834359U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6882429835961613492U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13213313479525717359U;
            aOrbiterK = RotL64((aOrbiterK * 2411431247725974895U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2401526093648669573U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3616448566579979749U;
            aOrbiterB = RotL64((aOrbiterB * 13323155103752121393U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18268262471839710401U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5116424918948694752U;
            aOrbiterA = RotL64((aOrbiterA * 7641143782996332069U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11405305689555640431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12427591396711015574U;
            aOrbiterD = RotL64((aOrbiterD * 8112834135715541223U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16960781161508084626U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12382604781005282628U;
            aOrbiterC = RotL64((aOrbiterC * 17196168631120103115U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10054839091354729292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4167641616532985407U;
            aOrbiterJ = RotL64((aOrbiterJ * 919291747187787625U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14383737233143309039U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16258779988369405932U;
            aOrbiterI = RotL64((aOrbiterI * 8348773195366160215U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4777263172049970723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12498046021142146499U;
            aOrbiterF = RotL64((aOrbiterF * 5941015011162130901U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7435001955334177144U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4100235545173125433U;
            aOrbiterH = RotL64((aOrbiterH * 5046572784117638909U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1981704568071298614U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11210042748013785976U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17889749044418386565U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 52U)) + aNonceWordA) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterK, 36U)) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14048U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13710U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13600U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12857U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 50U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 6318740973868639425U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 27U)) + 5487840061430920881U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 54U)) + 10258706763248072672U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 18356875269730338208U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 12883160282903147010U) + aNonceWordI;
            aOrbiterD = (aWandererA + RotL64(aCross, 29U)) + 1010140474942697730U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 23U)) + 17733939421700898293U) + aNonceWordD;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 5U)) + 13693055887924981201U) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 37U)) + 14574732452793385269U;
            aOrbiterA = (aWandererG + RotL64(aCross, 41U)) + 10832873941223609012U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + 8212600587135328040U) + aPhaseFOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5312744319781971178U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6173741211706546923U;
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3693249147883790810U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 18365859989736602556U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10645056678337549771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1175668356822251045U;
            aOrbiterK = RotL64((aOrbiterK * 6579675292775345579U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13556844570541823717U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4790355739411849736U;
            aOrbiterI = RotL64((aOrbiterI * 4083544011788850307U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14905575502272644116U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10161614295718414869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13413914082651612468U;
            aOrbiterA = RotL64((aOrbiterA * 16224039093981079491U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6072693130156927774U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4333656233793103787U;
            aOrbiterJ = RotL64((aOrbiterJ * 9374745547133955709U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17209776289202130250U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11752001118070361543U;
            aOrbiterF = RotL64((aOrbiterF * 4416523594812872339U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15367365111105608277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8650687767097460704U;
            aOrbiterG = RotL64((aOrbiterG * 11430451559660578667U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18074648514448405693U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10857586858462237581U;
            aOrbiterB = RotL64((aOrbiterB * 3722891011080095849U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17219932344278345591U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6318740973868639425U;
            aOrbiterH = RotL64((aOrbiterH * 8846295038878812229U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterC, 37U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 4U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterF, 26U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20386U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 16813U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21804U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 21740U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 30U)) + 13880995121909552664U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 14534942818069300546U) + aNonceWordL;
            aOrbiterA = (aWandererI + RotL64(aIngress, 41U)) + 17745973100886007133U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 53U)) + 2249805580771946872U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 4460116116396439410U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 35U)) + 3378683994078106878U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 10U)) + 3992996501048809123U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 12057768808864451929U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + 4115362079047921130U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 39U)) + 15297384955502206698U;
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 17623548383481905636U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3559213898000162417U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14807313864347885885U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11222085523291581822U;
            aOrbiterC = RotL64((aOrbiterC * 12580941911587215653U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 916681229436292462U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2441350114032314686U;
            aOrbiterI = RotL64((aOrbiterI * 7336079498999018067U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7361470539894653271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12153585147213579808U;
            aOrbiterD = RotL64((aOrbiterD * 3040327545467672961U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13566300726101613579U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14875254144748509128U;
            aOrbiterF = RotL64((aOrbiterF * 13699179902908972403U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9268158535644002904U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14144295981814993491U;
            aOrbiterH = RotL64((aOrbiterH * 12739937231684038161U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13861225650900541642U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12620513474052058164U;
            aOrbiterE = RotL64((aOrbiterE * 18141974182442267181U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14163773386433257965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5725700029399455855U;
            aOrbiterK = RotL64((aOrbiterK * 10446930901088908809U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16644838246877860102U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6611825438224873117U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5336239588054125897U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9408958265247071226U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16980073477599191801U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7985839560318985205U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6513029242607881518U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13880995121909552664U;
            aOrbiterB = RotL64((aOrbiterB * 17463079726765044639U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 60U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterB, 12U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aNonceWordM) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22361U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 26968U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24365U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 22258U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 22U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 11450949896247900941U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 3905542253538116335U;
            aOrbiterG = (aWandererF + RotL64(aCross, 34U)) + 9529740545977785305U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 1856876631533143492U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 37U)) + 84253466320181686U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 12577480918745432444U) + aNonceWordN;
            aOrbiterB = (((aWandererI + RotL64(aCross, 60U)) + 5625703170397704029U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 11U)) + 694608607323629282U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 3993981243536262204U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 3U)) + 4119215953484892051U) + aNonceWordM;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 47U)) + 8785040118556157146U) + aPhaseFOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16234403619456882890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18327987141759096769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 43U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 2859452497983106129U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7196557924940881076U;
            aOrbiterH = RotL64((aOrbiterH * 14415389907490256711U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 930127943984174668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15673596916054795749U;
            aOrbiterI = RotL64((aOrbiterI * 7505660488733199479U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16673140529110941163U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2258448294877833760U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1821550319748977445U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6870209259643931219U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12749790107942194104U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 4871407285968611725U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17131374134617173866U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6426448390733751612U;
            aOrbiterB = RotL64((aOrbiterB * 12490559588384058417U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15592826434339731146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14182944418026376183U;
            aOrbiterE = RotL64((aOrbiterE * 7218860482893476233U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17447476498234456596U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 972861017466618022U;
            aOrbiterF = RotL64((aOrbiterF * 9610670431280153921U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13185309156950240549U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14442284480744008537U;
            aOrbiterC = RotL64((aOrbiterC * 2907844852105175837U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 7816745313858811117U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11450949896247900941U;
            aOrbiterA = RotL64((aOrbiterA * 18317765298694454463U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterB, 4U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29515U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30299U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31018U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 27511U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 60U)) + 14686411261024919129U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 53U)) + 7514582233957632005U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + 6520710480103365552U) + aNonceWordH;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 1983621978676188036U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 23U)) + 9003524602590749672U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 47U)) + 6428568234045228995U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 8656552687136446989U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 41U)) + 16916248288415922490U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 30U)) + 9740237548002535784U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 907561000814618339U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 5U)) + 4751108900841197631U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 167774899400732287U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11907484918310854962U;
            aOrbiterF = RotL64((aOrbiterF * 7213139491146402985U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14910318613649863924U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14882888155751455276U;
            aOrbiterG = RotL64((aOrbiterG * 11394136445442060201U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16175942562693781908U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11022373758481651102U;
            aOrbiterE = RotL64((aOrbiterE * 6836331461393816027U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12548405399045031548U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10850926364556828443U;
            aOrbiterH = RotL64((aOrbiterH * 16231561687709867431U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13391684887911141790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14648937281264822988U;
            aOrbiterB = RotL64((aOrbiterB * 6533299316940026059U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 8298658887198526821U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13822977698661348891U;
            aOrbiterD = RotL64((aOrbiterD * 17769262972278410937U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7505646847564645719U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3238749538197209166U;
            aOrbiterI = RotL64((aOrbiterI * 15394286542600778567U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15853506915123709257U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8426329899401071248U;
            aOrbiterJ = RotL64((aOrbiterJ * 1330397096577715113U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14848635392815613098U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3549927798350175044U;
            aOrbiterA = RotL64((aOrbiterA * 1899044682313056949U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1798973117197750802U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13056711228618953977U;
            aOrbiterK = RotL64((aOrbiterK * 9102877396419306689U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1395893547965799281U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14686411261024919129U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17075377081365066067U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 6U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterK, 46U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aNonceWordD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Rugby_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBBCD54E1C2D95C5BULL + 0xEE0E9E8A881F5177ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFF8B7A2195BD9EC3ULL + 0xD2659A3553586A66ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC2F23AF45B470DB5ULL + 0xFF18C2EE5DC4B4C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDFB8AE8B846ADDDDULL + 0x83777F47F7BD8B45ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x856D9C7ABE037079ULL + 0xB1EA3CD3C8B3F3F2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8A3F905A7738DA8BULL + 0xF831442730D0C37AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC117AD7ED28C678BULL + 0xD16087214D02F4C2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB5670917F6D18469ULL + 0xF67E2BE7133DE5F4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB33852CF88CED955ULL + 0xC3D8407A0CAB58D2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF3B6AFE1B2FA5A19ULL + 0xF5B7B6A2F4399C04ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA787624C85D43D8DULL + 0xECE4E96BB59C1DD8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE3483D83FAAEADDFULL + 0xA541F25EF44885BAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC32628F50D465699ULL + 0x9D9A0CE2B046C32FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD40FEAD7F34E3239ULL + 0xB3F383CB218A0446ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC6AF90FE0242B749ULL + 0xF9FFFF0CD98F5A2DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE6BB87EA9BFD2E0BULL + 0xF101086CA376DAF7ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3835U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 4328U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 941U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3244U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 6469584119078165548U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 14329756366517987910U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 3U)) + 12890831797059772123U) + aNonceWordI;
            aOrbiterC = (aWandererF + RotL64(aCross, 54U)) + 3164503807500018990U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 41U)) + 177531431387646836U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 19U)) + 3167421392893561015U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 5U)) + 2813174781844753460U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 23U)) + 10953270419153249857U) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aIngress, 37U)) + 16911518309710356951U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 52U)) + RotL64(aCarry, 11U)) + 6616750447844893150U) + aNonceWordP;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 11U)) + 10276741398025985982U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6206043608461213208U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12021552904553405793U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10023362889960174909U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15283586234744144846U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterG = RotL64((aOrbiterG * 8200882393521882651U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11044014510971660078U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9351141024085076044U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13316079344614432317U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17703395981862992420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10154548848376027087U;
            aOrbiterC = RotL64((aOrbiterC * 12324478347590509035U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8836420852291617425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10193385413543886344U;
            aOrbiterA = RotL64((aOrbiterA * 824935982418585449U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8248580084535685190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3910083671888152974U;
            aOrbiterH = RotL64((aOrbiterH * 17825311776715895927U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12350341628569930642U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2565977481575002842U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18233446879833776677U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9271041067874027417U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14289254596554201861U;
            aOrbiterI = RotL64((aOrbiterI * 7985522692852251413U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5981802134118235214U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14047813418129636856U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 15961435325216504877U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11808443842149398212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11380858372643695792U;
            aOrbiterJ = RotL64((aOrbiterJ * 100198424024622179U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10385375464069162356U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6469584119078165548U;
            aOrbiterB = RotL64((aOrbiterB * 5263876933019848989U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 42U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8479U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9901U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9959U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7485U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 37U)) + 12775735908960052604U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 11791373812080296887U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 5537362877706057303U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 11U)) + 2023912048504189380U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + 17668828109963766893U) + aNonceWordF;
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 558908629933941224U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 24U)) + 1479633119685446888U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 13U)) + 15460320397843364063U) + aNonceWordJ;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 39U)) + 10059749397555469054U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 9987633811929693924U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 10087337844580228269U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4446204415503364254U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15106063243302192717U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9430197906134676162U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10611580584157624739U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3137391249289641509U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9327201928815412810U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7890659377013147073U;
            aOrbiterD = RotL64((aOrbiterD * 13827717178378062047U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12871947817782057116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11015991745792051390U;
            aOrbiterK = RotL64((aOrbiterK * 17152451500505815031U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6320437975845673731U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterG = RotL64((aOrbiterG * 17491257114676739589U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16629064896250312921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13274874838094190290U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12211422735294360321U;
            aOrbiterF = RotL64((aOrbiterF * 5113738196151089817U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15338616110718583619U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1475787183754511373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10904607643785840003U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15486810401396777742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12775735908960052604U;
            aOrbiterA = RotL64((aOrbiterA * 7478156942468930207U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 24U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 50U)) + aOrbiterB) + aNonceWordH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12549U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11690U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12789U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14959U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 51U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 51U)) + 12122689833405846292U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 24U)) + RotL64(aCarry, 5U)) + 9640400270962766788U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + 9141937998266739071U) + aNonceWordD;
            aOrbiterK = (aWandererF + RotL64(aIngress, 5U)) + 12899395770434090537U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 35U)) + 13457918115408031842U) + aNonceWordN;
            aOrbiterB = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 15134784483576000943U) + aNonceWordH;
            aOrbiterE = (aWandererB + RotL64(aIngress, 39U)) + 12540961268790055438U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 47U)) + 6306886773092764230U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 13573343491337243121U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 43U)) + 8545588657348974413U;
            aOrbiterH = (aWandererA + RotL64(aCross, 19U)) + 10891410570357275120U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2877137119767060151U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9178097682386595144U;
            aOrbiterA = RotL64((aOrbiterA * 3524486002084427513U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15528007881855616978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11368419529245281435U;
            aOrbiterB = RotL64((aOrbiterB * 12433207037378339309U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5932738914934356645U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5551842263864055419U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16093776759971522681U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3824433359595690603U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17184628855571662441U;
            aOrbiterJ = RotL64((aOrbiterJ * 691208053136187317U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8724462245014132623U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7481349499528092352U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 8212182934509617583U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6908362960248294718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5354057969992655314U;
            aOrbiterD = RotL64((aOrbiterD * 16586084885820679343U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11138301629323903147U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14164180536320940750U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9099767681053390287U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 709942920176922902U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6760410778228957309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15333948259759012363U;
            aOrbiterE = RotL64((aOrbiterE * 3685416414008280787U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6929136132517755104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13833415487953533365U;
            aOrbiterI = RotL64((aOrbiterI * 14860437994758579635U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16143046377679975216U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12122689833405846292U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 227699085983424155U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 54U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterK, 24U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterH, 60U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18587U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20438U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19775U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19683U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 23U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 19U)) + 15316464782468770057U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 47U)) + 6642872057476351588U) + aNonceWordB;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 29U)) + 660732654689529192U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 4U)) + 7235418086884000655U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 14784518476694580493U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 41U)) + 12222433977933449375U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 13U)) + 8573001207708329927U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 16035256260815013172U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 43U)) + 15767726974121910203U;
            aOrbiterF = (aWandererA + RotL64(aCross, 6U)) + 17712217935322939971U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 13488963456923357159U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10222949131965611079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1495561412321657209U;
            aOrbiterE = RotL64((aOrbiterE * 9706305581868526265U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16156530750584361434U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7773792489045606309U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10730624207715601393U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11544578291333360613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3665587867634242865U;
            aOrbiterI = RotL64((aOrbiterI * 4840528190844842595U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15248434984650998090U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15487979645426567581U;
            aOrbiterD = RotL64((aOrbiterD * 10868107809356766183U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6972347795052712690U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16074994810010431338U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1262655238856775853U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16851139687900415292U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14630026837021552812U;
            aOrbiterG = RotL64((aOrbiterG * 9577900853521254603U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14236330619137368169U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17778707026111136216U;
            aOrbiterF = RotL64((aOrbiterF * 16239561893843454747U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9390961969105999083U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1174881758316573228U;
            aOrbiterH = RotL64((aOrbiterH * 6602061268277529311U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3025148570039849574U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2813499258480831171U;
            aOrbiterK = RotL64((aOrbiterK * 12272555492688861861U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15397952138592662354U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10394648143430175275U;
            aOrbiterA = RotL64((aOrbiterA * 18195627209519212303U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3043205345760158739U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15316464782468770057U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 8162506622688910545U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 24U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 28U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26371U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22623U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23118U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 25771U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 20U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 16016931609704150191U;
            aOrbiterE = (aWandererD + RotL64(aCross, 23U)) + 14511433515861302636U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 11691237442613269593U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 29U)) + 16383220587320484649U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 14293015313458219868U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 11U)) + 4407695248205526670U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 1158323195324398372U) + aNonceWordK;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 53U)) + 6577683409653864555U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 60U)) + 171080079472863843U;
            aOrbiterG = (aWandererC + RotL64(aCross, 39U)) + 5766333425872228205U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 27U)) + 16173508656917582960U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11781450063402219202U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterH = RotL64((aOrbiterH * 4331137994135472025U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4006310759400926020U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13156817947481574467U;
            aOrbiterD = RotL64((aOrbiterD * 563189239835001483U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12791290558893516411U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 989729955679243234U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8757228712495095017U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 838379839663022790U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2830743864262313606U;
            aOrbiterG = RotL64((aOrbiterG * 10173947177104802797U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2146646527331684652U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4629168181742174906U;
            aOrbiterC = RotL64((aOrbiterC * 9046124907945045131U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1150129989168501777U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 619659995945229440U;
            aOrbiterA = RotL64((aOrbiterA * 13734821008174603409U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8120315647582116952U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13754584116324996165U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12295486140772079747U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6084566798869999580U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5731665119233722504U;
            aOrbiterB = RotL64((aOrbiterB * 5921510209025133639U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16134513471149338456U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9841695976256666234U;
            aOrbiterK = RotL64((aOrbiterK * 7417023101762286049U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2559042046155066240U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14065288635273112125U;
            aOrbiterE = RotL64((aOrbiterE * 10464173719695109147U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18228257734024217020U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16016931609704150191U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2874343578276710555U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + RotL64(aOrbiterE, 6U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterB, 24U)) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30141U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31932U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30034U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28982U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 53U)) + 7651355040951791298U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 19U)) + 13988210277931659312U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 9846849412579537783U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 12746719939495876158U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 37U)) + 11498066185182895284U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 5U)) + 11101058955193080232U) + aNonceWordD;
            aOrbiterF = (aWandererJ + RotL64(aCross, 47U)) + 15513734459555672046U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 44U)) + 15711108675349394643U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 4771231759949468556U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 51U)) + 11449258010811305256U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 23U)) + 17036938391509986723U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6999245666776654250U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2106819066263369528U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12716183358903477216U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16752724547046059889U;
            aOrbiterJ = RotL64((aOrbiterJ * 11475905692393034141U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17623077680983093163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6726003022297274986U;
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2842410225096524740U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9235178377537910514U;
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2619888019860844610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6295481948199619613U;
            aOrbiterC = RotL64((aOrbiterC * 15429161806953951205U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9724921158061115570U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4070976180958458679U;
            aOrbiterE = RotL64((aOrbiterE * 6080566609081811453U), 39U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 5864247978960125554U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7771249710071026757U;
            aOrbiterK = RotL64((aOrbiterK * 4787660062590737657U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15006900854988166845U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2755659268987119046U;
            aOrbiterI = RotL64((aOrbiterI * 8043939381186802359U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1922321482806966418U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13910818219761929659U;
            aOrbiterD = RotL64((aOrbiterD * 8895973123729951173U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7540972911473176026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5419023469522423893U;
            aOrbiterH = RotL64((aOrbiterH * 1380429266266313945U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2349651834739320824U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7651355040951791298U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3713776056028698433U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 53U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterI, 10U));
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 46U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordO);
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

void TwistExpander_Rugby_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1088U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1374U)) & W_KEY1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1995U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 191U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 40U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 9855743441035905047U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 8426286937143990276U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 43U)) + 7146752367170267002U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 12947210066678101726U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 58U)) + 15902163559925328965U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 29U)) + 8506649889346449469U) + aPhaseCOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 23U)) + 8226286036430263052U) + aPhaseCOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 53U)) + 2703047093452420216U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 48U)) + 6769351326360139560U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9857025533281333281U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 238297452132277585U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12974709749856065985U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7203572312072908931U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12497027346166575632U;
            aOrbiterB = RotL64((aOrbiterB * 1703586436725662307U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 473851890609048879U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4635095143004754116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17695676150967345793U;
            aOrbiterD = RotL64((aOrbiterD * 5780416541584439301U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15628965269863402796U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9190117464399730235U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17835918238346011086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4398005402429282682U;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10902589938246551273U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15124274429081385923U;
            aOrbiterG = RotL64((aOrbiterG * 13524180348258805367U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8747233520702236018U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5445611443463112371U;
            aOrbiterA = RotL64((aOrbiterA * 10294109295823410447U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16296005217836151910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6468336224317602364U;
            aOrbiterE = RotL64((aOrbiterE * 7369779919748367133U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + aOrbiterK) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 60U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9430U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((aIndex + 9682U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14695U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15459U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 16424657151168221875U;
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 17150123681886380361U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 48U)) + 16041993588694572757U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 9871185846434828537U) + aPhaseCOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 11227236398354430757U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 43U)) + 5399325217402192631U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 58U)) + 9248828789282890454U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 39U)) + 9041370494203701062U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 14944424084524970764U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5481938174456671041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14783648629543752715U;
            aOrbiterJ = RotL64((aOrbiterJ * 7260164783191886395U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12355573914530445723U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16149688605937250965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8076098639554567792U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11155119311895580013U;
            aOrbiterC = RotL64((aOrbiterC * 1495180896564818647U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6847612160595917702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16094377920388017367U;
            aOrbiterD = RotL64((aOrbiterD * 4875801863643206333U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13584719866672696684U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13446209321646234607U;
            aOrbiterE = RotL64((aOrbiterE * 9945349065094781529U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15829806645369560988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12573767256739062550U;
            aOrbiterK = RotL64((aOrbiterK * 5649504278826069077U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3850030870300393809U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11857593987748189858U;
            aOrbiterH = RotL64((aOrbiterH * 15942863910931814193U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5505918410521728373U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12949653497121247860U;
            aOrbiterI = RotL64((aOrbiterI * 90944913639560027U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 20U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterK, 6U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 42U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aPhaseCWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20663U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20518U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17463U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 22636U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 11U)) + 6469584119078165548U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 18U)) + 14329756366517987910U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 12890831797059772123U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 43U)) + 3164503807500018990U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 177531431387646836U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 23U)) + 3167421392893561015U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + 2813174781844753460U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 43U)) + 10953270419153249857U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 5U)) + 16911518309710356951U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6616750447844893150U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10276741398025985982U;
            aOrbiterB = RotL64((aOrbiterB * 6824712685896987133U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6206043608461213208U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12021552904553405793U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10023362889960174909U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15283586234744144846U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5923238786775948571U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8200882393521882651U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11044014510971660078U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9351141024085076044U;
            aOrbiterI = RotL64((aOrbiterI * 13316079344614432317U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17703395981862992420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10154548848376027087U;
            aOrbiterE = RotL64((aOrbiterE * 12324478347590509035U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8836420852291617425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10193385413543886344U;
            aOrbiterJ = RotL64((aOrbiterJ * 824935982418585449U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8248580084535685190U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3910083671888152974U;
            aOrbiterC = RotL64((aOrbiterC * 17825311776715895927U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12350341628569930642U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2565977481575002842U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18233446879833776677U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9271041067874027417U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14289254596554201861U;
            aOrbiterH = RotL64((aOrbiterH * 7985522692852251413U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 58U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 20U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29708U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 30550U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26204U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 32376U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 40U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 35U)) + 9654059367478508868U;
            aOrbiterF = (aWandererG + RotL64(aCross, 5U)) + 6473006635864677427U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 41U)) + 6944184481315853243U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 19U)) + 4061496421939102306U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 15791809275719085463U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 53U)) + 14050798802646323055U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 12072905924741758266U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 14U)) + 17639076509231343896U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 12195388285571234715U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4325404419499496529U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5910567888204238382U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11503787177122206937U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13092940059929942699U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13381962590820308761U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6345904465930943295U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15622862439323440527U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14027151901132249793U;
            aOrbiterB = RotL64((aOrbiterB * 2273573821630510087U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4584410023907605157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15763755180625487157U;
            aOrbiterG = RotL64((aOrbiterG * 6755736130607297639U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17023059745666559199U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5298529579288492971U;
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2870152867331654736U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12017191100173748848U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9958191466506480519U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15899529176182436062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16482713846343388735U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 719465695044265601U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12943393531812774449U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9881108254540483225U;
            aOrbiterH = RotL64((aOrbiterH * 8011108108007885059U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3532054586199716750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7142230313294797435U;
            aOrbiterF = RotL64((aOrbiterF * 14154176174768868421U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 50U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterC, 22U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterA, 4U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterC, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Rugby_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2933U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 390U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7358U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 8089U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + 7893287783892523139U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 35U)) + 10257331997383491153U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 57U)) + 14562226733652231753U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 14320342577110737851U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 9816717579822880756U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9558926960095881953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9230371862654338324U;
            aOrbiterC = RotL64((aOrbiterC * 8842712825810461561U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6414274291252913420U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13868546184398350849U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1547986864837497409U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16940736952569949038U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2866957764814864371U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3554702178644797003U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7916721976073979724U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1602444214978842275U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11072503711308122385U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9529061385251008037U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8402775110887376588U;
            aOrbiterH = RotL64((aOrbiterH * 13980225144628227381U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 14U)) + aOrbiterD) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16314U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14029U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14831U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13849U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + 12426357877879529292U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 12604900366173639176U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 13511119007338929401U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 9878720081166788060U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 48U)) + 15463195409806395076U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6407922778852833423U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7690427254160734016U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11841396512731990295U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18030974031722143619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17983938038322737041U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12479365337221685413U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16605512170117753884U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 681802273302348322U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14608920184802647123U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15550312921312083819U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17824154101711884508U;
            aOrbiterI = RotL64((aOrbiterI * 7358612830654795357U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1939207786756735430U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3132864634777826569U;
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 43U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22232U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19627U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18570U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21327U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 3U)) + 10881271196314989997U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + 6406461249988567558U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 17255067918280095959U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 16690850682497718411U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 44U)) + RotL64(aCarry, 53U)) + 5576201059361086866U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11991259685693687554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14652535244217836909U;
            aOrbiterE = RotL64((aOrbiterE * 18283959577075524171U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1701789037170782122U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 953429054903473833U;
            aOrbiterI = RotL64((aOrbiterI * 13482379459700651427U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12064513610469714211U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7993881398822002424U;
            aOrbiterC = RotL64((aOrbiterC * 11572884842788918377U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14421313768013320050U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11112386845630998889U;
            aOrbiterD = RotL64((aOrbiterD * 11771526352030371669U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17069630896535699015U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3308240081138623373U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10449509484417835159U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 58U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aPhaseDWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF + (((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28454U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((aIndex + 30863U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26996U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29343U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 16424657151168221875U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 56U)) + 17150123681886380361U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 16041993588694572757U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 9871185846434828537U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 19U)) + 11227236398354430757U) + aPhaseDOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5399325217402192631U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9248828789282890454U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6733832755349139621U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9041370494203701062U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14944424084524970764U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10283363059424655079U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5481938174456671041U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14783648629543752715U;
            aOrbiterC = RotL64((aOrbiterC * 7260164783191886395U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12355573914530445723U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9863991559011968318U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8495251211794343179U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16149688605937250965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 106041828692026825U;
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aCross, 56U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Rugby_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 229U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 3318U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1246U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1580U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 58U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 1708250618750199233U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 51U)) + 12009147777553691142U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 27U)) + 8393982703399156592U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 3247327098356831221U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 3403590155376353737U;
            aOrbiterD = (aWandererI + RotL64(aCross, 36U)) + 18197244558104735044U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 3096253642040701606U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8012692688785412179U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17531946907545680745U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16510602981731506381U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17687695944270225817U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16147773866007628769U;
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 18244641303026196497U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8839160526348897457U;
            aOrbiterD = RotL64((aOrbiterD * 14268021129087663397U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10599266240854068246U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2056723540756216155U;
            aOrbiterG = RotL64((aOrbiterG * 13311591601230386375U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4629354220460621284U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9505955649473204942U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17775391885312236187U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17078153810088721310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9470436761716263000U;
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3305863413630104742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14377172434239576161U;
            aOrbiterK = RotL64((aOrbiterK * 6880176890091033423U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 54U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 5U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13408U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((aIndex + 9232U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16071U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14744U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 41U)) + 6733949564325516029U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 7304098437143918796U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 3U)) + 3923949518391777800U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 57U)) + 14243591003388927124U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 18329498724605410406U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 13118172167747037249U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 34U)) + 5272025143849174212U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16075917179214318424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15263590648674658399U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9918239923411740337U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13730046728289525921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7703141464499623408U;
            aOrbiterI = RotL64((aOrbiterI * 5886009900621521987U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1382279753822135359U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2973369221699098292U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2582783513078999303U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3959762790273529677U;
            aOrbiterE = RotL64((aOrbiterE * 383974377372162751U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 465795011576934604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17880826624185821135U;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10819659185349413173U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17298208553586835030U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1965860510614222093U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterE, 44U));
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20377U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20643U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17835U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 20030U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 35U)) + 16802219662864902427U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 14332033461409490629U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 14U)) + 8781794298640286845U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 8459933908074937264U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 1883580287986004426U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 27U)) + 17500258188004626118U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 21U)) + 7934811305150872870U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6380363892361098905U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12623079132626676910U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12406671746344127399U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10455208121949202703U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8805532707916767629U;
            aOrbiterB = RotL64((aOrbiterB * 666082374369701881U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9161544391400377699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3501434325829663268U;
            aOrbiterE = RotL64((aOrbiterE * 7933545151293799637U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 651783304096081996U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 441505031509930622U;
            aOrbiterD = RotL64((aOrbiterD * 8045355432310956143U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1771159983581326424U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15227946417377695989U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1563141188972797601U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4153717524193279095U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4404521756523902829U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1410342912973206203U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6231945075461813285U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3864780227164426690U;
            aOrbiterH = RotL64((aOrbiterH * 18031353247480673617U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterG, 12U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25372U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 32434U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29644U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 26385U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 13481227414590594621U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 6U)) + RotL64(aCarry, 57U)) + 17425964381118918026U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 27U)) + 4792004356135956581U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 57U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 990697329347742142U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 37U)) + 9307721505373076588U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 17605732738841908719U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13110764518634187439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17970109897810645911U;
            aOrbiterI = RotL64((aOrbiterI * 10395095143998920213U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10273133817644703654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11239046688920468137U;
            aOrbiterA = RotL64((aOrbiterA * 5197802934333553327U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8355821483275763145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15522151127786049345U;
            aOrbiterC = RotL64((aOrbiterC * 4844278537850520413U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5381663179722418112U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9551368011768104906U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16264476585232221270U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7721417776432288282U;
            aOrbiterE = RotL64((aOrbiterE * 10267770327791051869U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 339418090653475277U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3247926250495935511U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16824669543765729097U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3390560045236418590U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3894024951542543635U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10599637790900418767U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 37U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterA, 28U));
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Rugby_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7629U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 222U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2780U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 6384U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 29U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 15036852811491820366U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 305637140752898475U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 48U)) + 11948631574496129610U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 27U)) + 5321623592482991426U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 4075270159062690728U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15111580500356908928U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7244150695504160363U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2445733898697939969U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5131563519577488862U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5881954992088651371U;
            aOrbiterH = RotL64((aOrbiterH * 2424421828597294607U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12780935808751507998U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12599159643925470226U;
            aOrbiterK = RotL64((aOrbiterK * 17690046932587062701U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9466589929741834066U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17461243886150519249U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15456408913739900718U;
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 40U) + RotL64(aOrbiterG, 56U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15429U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 15556U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12943U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 14834U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 1457104756581596530U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 6127240317844622874U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 36U)) + 16492290056044189421U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 10963676850938416468U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 21U)) + 4872917367399752405U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15218882377875616148U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5934166612122118251U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10365045124180379919U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14215280930872003003U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11428034799044600979U;
            aOrbiterF = RotL64((aOrbiterF * 12162528943733976177U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5453003654321728726U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14273775120265649389U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5139018128323795309U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 328723770018440271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13032190719588211088U;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2386881543033598494U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterI = RotL64((aOrbiterI * 11148976582360499033U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterE, 46U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21291U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 18717U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20319U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 18360U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 12380376990224645149U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 27U)) + 18296928500297384014U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 3550626816361145100U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 2667792936946706027U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 43U)) + 12020969779370926953U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 737340727886903447U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1681797651799760502U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11923920414802777451U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2956186342689489064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1876852870402977177U;
            aOrbiterG = RotL64((aOrbiterG * 8875540081346621757U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6433205819353555071U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9065076854974222998U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5459675878087242021U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3254410578766789992U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterB = RotL64((aOrbiterB * 9947701153722014085U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15992999234834560419U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3458344156815120948U;
            aOrbiterF = RotL64((aOrbiterF * 1668460113964608051U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 26U) + aOrbiterB) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27342U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26298U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30384U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27130U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 38U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 4204560462077827182U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 21U)) + 6572370199668594039U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 12U)) + RotL64(aCarry, 27U)) + 15958999876732622825U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 9969349486879280377U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 43U)) + 15450238998293956181U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9128619863683138259U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5691270563628979565U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2170424734274640859U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5901029710568933106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10442738941988588834U;
            aOrbiterD = RotL64((aOrbiterD * 7386621444831603817U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3508116020325721993U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13221917083569767259U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6845108555710135357U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11627915460377128176U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17858261365514253433U;
            aOrbiterG = RotL64((aOrbiterG * 7535577636975884641U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4294837988806295989U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11242915481585070249U;
            aOrbiterC = RotL64((aOrbiterC * 17540688242763829319U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 46U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Rugby_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1779U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2417U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6178U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 6730U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 9435962834163239322U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 10524704356081318973U) + aPhaseGOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 7403401305665208680U;
            aOrbiterF = (aWandererK + RotL64(aCross, 47U)) + 7525414805023556493U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 38U)) + 1116686470029070951U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13257612299137802420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9181543003986598283U;
            aOrbiterH = RotL64((aOrbiterH * 18162011316880411235U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9739384852307501107U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11308402900229016057U;
            aOrbiterJ = RotL64((aOrbiterJ * 12690186771773188967U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14935167593705272337U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7171824007631943535U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4839974427616194289U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8068411284829563567U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12350207458513447578U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 813973258659041895U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17039236343991574134U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18291683592714999632U;
            aOrbiterG = RotL64((aOrbiterG * 7771718817924840713U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10598U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 15509U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13765U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14110U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 28U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 41U)) + 8506388683755208267U) + aPhaseGOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 2179323259055019735U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 3345902531140983016U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 17456139311481306584U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 14587864088462311164U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13178947246650647057U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12866578138946916962U;
            aOrbiterI = RotL64((aOrbiterI * 121991325166969319U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13098524333655118173U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15451329483787541982U;
            aOrbiterB = RotL64((aOrbiterB * 13580376920467431451U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9494299579678389385U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15581954810375490643U;
            aOrbiterF = RotL64((aOrbiterF * 13670002280188424825U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4487042505730624892U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2774455928791636186U;
            aOrbiterC = RotL64((aOrbiterC * 15847933919136777451U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12435319582397755819U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10077180055177766823U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3924363471701748703U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 4U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterA, 51U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 26U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 20U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21080U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 21902U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23090U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17038U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 6467297102954816305U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 13U)) + 7921154109831114952U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 22U)) + RotL64(aCarry, 13U)) + 5701131763215638919U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + 10022999076719002684U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 4367135243038982316U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14445846824810383592U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7683697954545773253U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4832124801510084629U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17517006750428030899U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2052484792684025476U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12463117571122469643U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6279463052085808926U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 679280153651813684U;
            aOrbiterB = RotL64((aOrbiterB * 3047031560593583881U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2939516520188460569U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1960616434964712325U;
            aOrbiterJ = RotL64((aOrbiterJ * 15145998415466343039U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12273819390719947361U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5685033154709449397U;
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 34U)) + aPhaseGWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26173U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27750U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26490U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29732U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 964165145848253292U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 10645976767204934746U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 8241612229349212650U) + aPhaseGOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 29U)) + 4159196033256913347U;
            aOrbiterG = (aWandererF + RotL64(aCross, 13U)) + 7194795864620233507U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7638928444536778384U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11819105916503968109U;
            aOrbiterE = RotL64((aOrbiterE * 9052440449038441625U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18052213302858186237U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8663575313970041570U;
            aOrbiterH = RotL64((aOrbiterH * 14131073322476609161U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16644136720439299786U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16930316530442679864U;
            aOrbiterA = RotL64((aOrbiterA * 2650922074098320859U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16251107616988250593U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7171986193609401665U;
            aOrbiterK = RotL64((aOrbiterK * 3543709971414550087U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17885046834432626644U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7757069274715713557U;
            aOrbiterG = RotL64((aOrbiterG * 15766885299397923879U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 14U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
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

void TwistExpander_Rugby_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 1053U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2862U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 752U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2372U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 8604208734152026945U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 1374329953253889829U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 5779278910548228339U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 17670451230882805140U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 39U)) + 8193848740764866860U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15801168428145650104U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2584718176087499066U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5687189872016780831U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14950366247822737997U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9779293225265670135U;
            aOrbiterE = RotL64((aOrbiterE * 11625969538497982117U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8688968319288372383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13665723186950342601U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 292035540396910837U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9395428688359973510U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2152719218018108418U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15271961483518392671U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1350324137411377992U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8729317951386057921U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6008790836417785083U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterF, 56U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13805U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 13009U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8810U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8788U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aIngress, 57U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererE + RotL64(aScatter, 36U)) + RotL64(aCarry, 21U)) + 12136097566601676613U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 7969431322248040056U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 10530676021510553889U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 8740777303075445264U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 5U)) + 13249434169895564739U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15529577005925628472U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 344627093687331562U;
            aOrbiterF = RotL64((aOrbiterF * 3226087371456521323U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8824277416519988893U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5636276438449709875U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 222817930773618893U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2079413361031851552U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7807998179168655561U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13589392896232029112U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10733011474804473996U;
            aOrbiterH = RotL64((aOrbiterH * 361749145931578805U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15934162328347805968U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7573511217796245232U;
            aOrbiterB = RotL64((aOrbiterB * 10694563909931636155U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterB, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17454U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 20327U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21212U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 19573U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 9774364261626083532U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 18059001521926116420U) + aPhaseHOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 10615626210406381148U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 10536484278007898620U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 42U)) + 13320663045139972700U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17127001787268166583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16742574590844166551U;
            aOrbiterA = RotL64((aOrbiterA * 17828964140627204983U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8347719720758228053U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13502468705946051986U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13822952083584784695U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3512687886188904904U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 495660316165795934U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6724596801190194913U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5092722552034477356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15641128019608284015U;
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15421873776811085458U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17978775513204574125U;
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterE, 14U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 27550U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 28027U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27536U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31432U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 13U)) + 16651241552253078315U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 4558144676982478003U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 8814884320080367550U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 16011579668555672117U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 51U)) + 4738918668759862438U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12526083125540985108U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8048723561746000552U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11914807994597963481U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1082218464034639039U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8432043246965946816U;
            aOrbiterB = RotL64((aOrbiterB * 7801965585991025451U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9982080524048636852U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6720069955755215919U;
            aOrbiterH = RotL64((aOrbiterH * 1025046364205332059U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1019035028070247757U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7360619079463870467U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10893918488381348474U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1390297670907738019U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11909657437658597735U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
